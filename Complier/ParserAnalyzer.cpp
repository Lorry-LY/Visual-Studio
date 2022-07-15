#include "ParserAnalyzer.h"

ParserAnalyzer::ParserAnalyzer(string input)
{
	this->m_outputFile = fstream("output.txt", ios::out);
	if (!m_outputFile.is_open())
	{
		cout << "文件打开失败。" << endl;
		return;
	}
}

ParserAnalyzer::TreeNode* ParserAnalyzer::analyze(vector<LexicalAnalyzer::Token> tokens)
{
	m_tokens = tokens;
	m_cursor = 0;
	isError = false;
	TreeNode* t = stmt_sequence();
	return t;
}

void ParserAnalyzer::printTree(TreeNode* tree, int level)
{
	int i;
	while (tree != NULL) {
		for (int j = 0; j < level; j++)cout << "\t";
		if (tree->nodekind == StmtK)
		{
			switch (tree->kind.stmt) {
			case IfK:
				cout<<"If\n";
				break;
			case RepeatK:
				cout << "Repeat\n";
				break;
			case AssignK:
				printf("Assign to: %s\n",tree->attr.name);
				break;
			case ReadK:
				printf("Read: %s\n", tree->attr.name);
				break;
			case WriteK:
				cout <<"Write\n";
				break;
			case IdentK:
				cout << "Ident\n";
				break;
			case DefK:
				printf("Def %s:\n", tree->attr.name);
				break;
			case WhileK:
				cout << "While\n";
				break;
			default:
				cout << "Unknown ExpNode kind\n";
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp) {
			case OpK:
				cout <<"Op: \n";
				//printToken(tree->attr.op);
				break;
			case ConstK:
				if(tree->type== Float)
					printf("Const: %f\n", tree->attr.valf);
				else printf("Const: %d\n", tree->attr.val);
				break;
			case IdK:
				printf("Id: %s\n", tree->attr.name);
				break;
			case ArrayK:
				cout << "Array:\n";
				break;
			case funcK:
				printf("func: %s\n", tree->attr.name);
				break;
			default:
				cout << "Unknown ExpNode kind\n";
				break;
			}
		}
		else cout << "Unknown node kind\n";
		for (i = 0; i < MAXCHILDREN; i++)
			printTree(tree->child[i],level+1);
		tree = tree->sibling;
	}
}

void ParserAnalyzer::match(LexicalAnalyzer::Token::TokenType expected)
{
	if (m_tokens[m_cursor].type == expected)m_cursor++;
	else
	{
		syntaxError("unexpected token -> ");
		printToken(m_tokens[m_cursor]);
	}
}

ParserAnalyzer::TreeNode* ParserAnalyzer::stmt_sequence()
{
	TreeNode* t = statement();
	TreeNode* p = t;
	while ((m_tokens[m_cursor].type != LexicalAnalyzer::Token::ENDFILE)
		&& (m_tokens[m_cursor].type != LexicalAnalyzer::Token::END)
		&& (m_tokens[m_cursor].type != LexicalAnalyzer::Token::ELSE)
		&& (m_tokens[m_cursor].type != LexicalAnalyzer::Token::UNTIL))
	{
		match(LexicalAnalyzer::Token::SEMI);
		TreeNode* q = statement();
		if (q != NULL) {
			if (t == NULL) t = p = q;
			else /* now p cannot be NULL either */
			{
				p->sibling = q;
				p = q;
			}
		}
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::statement()
{
	TreeNode* t = NULL;
	switch (m_tokens[m_cursor].type) {
	case LexicalAnalyzer::Token::IF: t = if_stmt(); break;
	case LexicalAnalyzer::Token::REPEAT: t = repeat_stmt(); break;
	case LexicalAnalyzer::Token::ID: t = assign_stmt(); break;
	case LexicalAnalyzer::Token::READ: t = read_stmt(); break;
	case LexicalAnalyzer::Token::WRITE: t = write_stmt(); break;
	case LexicalAnalyzer::Token::WHILE: t = while_stmt(); break;
	case LexicalAnalyzer::Token::INT:
	case LexicalAnalyzer::Token::FLT:t = ident_stmt(); break;
	case LexicalAnalyzer::Token::DEF:t = def_stmt(); break;
	default: 
		syntaxError("unexpected token -> ");
		printToken(m_tokens[m_cursor]);
		m_cursor++;
		break;
	} /* end case */
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::if_stmt()
{
	TreeNode* t = newStmtNode(IfK);
	match(LexicalAnalyzer::Token::IF);
	if (t != NULL) t->child[0] = exp();
	match(LexicalAnalyzer::Token::THEN);
	if (t != NULL) t->child[1] = stmt_sequence();
	if (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ELSE) {
		match(LexicalAnalyzer::Token::ELSE);
		if (t != NULL) t->child[2] = stmt_sequence();
	}
	match(LexicalAnalyzer::Token::END);
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::while_stmt()
{
	TreeNode* t = newStmtNode(WhileK);
	match(LexicalAnalyzer::Token::WHILE);
	if (t != NULL) t->child[0] = exp();
	match(LexicalAnalyzer::Token::THEN);
	if (t != NULL) t->child[1] = stmt_sequence();
	match(LexicalAnalyzer::Token::END);
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::repeat_stmt()
{
	TreeNode* t = newStmtNode(RepeatK);
	match(LexicalAnalyzer::Token::REPEAT);
	if (t != NULL) t->child[0] = stmt_sequence();
	match(LexicalAnalyzer::Token::UNTIL);
	if (t != NULL) t->child[1] = exp();
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::assign_stmt()
{
	TreeNode* t = newStmtNode(AssignK);
	if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
		t->attr.name = (char*)m_tokens[m_cursor].value.data();
	match(LexicalAnalyzer::Token::ID);
	match(LexicalAnalyzer::Token::ASSIGN);
	if (t != NULL) t->child[0] = exp();
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::read_stmt()
{
	TreeNode* t = newStmtNode(ReadK);
	match(LexicalAnalyzer::Token::READ);
	if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
		t->attr.name = (char*)m_tokens[m_cursor].value.data();
	match(LexicalAnalyzer::Token::ID);
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::write_stmt()
{
	TreeNode* t = newStmtNode(WriteK);
	match(LexicalAnalyzer::Token::WRITE);
	if (t != NULL) t->child[0] = exp();
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::ident_stmt()
{
	TreeNode* t = newStmtNode(IdentK);
	LexicalAnalyzer::Token::TokenType _type = m_tokens[m_cursor].type;
	switch (_type)
	{
	case LexicalAnalyzer::Token::INT:
		t->type = ExpType::Integer;
		match(LexicalAnalyzer::Token::INT);
		break;
	case LexicalAnalyzer::Token::FLT:
		t->type = ExpType::Float;
		match(LexicalAnalyzer::Token::FLT);
		break;
	default:
		syntaxError("unexpected token -> ");
		printToken(m_tokens[m_cursor]);
		m_cursor++;
		break;
	}
	int childNumber = 0;
	if (t != NULL)t->child[childNumber++] = element();
	while (m_tokens[m_cursor].type == LexicalAnalyzer::Token::COMMA)
	{
		match(LexicalAnalyzer::Token::COMMA);
		if (t != NULL)t->child[childNumber++] = element();
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::def_stmt()
{
	TreeNode* t = newStmtNode(DefK);
	match(LexicalAnalyzer::Token::DEF);
	if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
		t->attr.name = (char*)m_tokens[m_cursor].value.data();
	match(LexicalAnalyzer::Token::ID);
	match(LexicalAnalyzer::Token::LPAREN);
	if(m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID)
	{
		int childNumber = 0;
		if (t != NULL) t->child[++childNumber] = element();
		while (m_tokens[m_cursor].type == LexicalAnalyzer::Token::COMMA)
		{
			match(LexicalAnalyzer::Token::COMMA);
			if (t != NULL) t->child[++childNumber] = element();
		}
	}
	match(LexicalAnalyzer::Token::RPAREN);
	match(LexicalAnalyzer::Token::THEN);
	if (t != NULL) t->child[0] = stmt_sequence();
	match(LexicalAnalyzer::Token::END);
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::exp()
{
	TreeNode* t = simple_exp();
	if ((m_tokens[m_cursor].type == LexicalAnalyzer::Token::LT)
		|| (m_tokens[m_cursor].type == LexicalAnalyzer::Token::EQ)) {
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = m_tokens[m_cursor].type;
			t = p;
		}
		match(m_tokens[m_cursor].type);
		if (t != NULL)
			t->child[1] = simple_exp();
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::simple_exp()
{
	TreeNode* t = term();
	while ((m_tokens[m_cursor].type == LexicalAnalyzer::Token::PLUS) 
		|| (m_tokens[m_cursor].type == LexicalAnalyzer::Token::MINUS))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = m_tokens[m_cursor].type;
			t = p;
			match(m_tokens[m_cursor].type);
			t->child[1] = term();
		}
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::term()
{
	TreeNode* t = factor();
	while ((m_tokens[m_cursor].type == LexicalAnalyzer::Token::TIMES)
		|| (m_tokens[m_cursor].type == LexicalAnalyzer::Token::OVER))
	{
		TreeNode* p = newExpNode(OpK);
		if (p != NULL) {
			p->child[0] = t;
			p->attr.op = m_tokens[m_cursor].type;
			t = p;
			match(m_tokens[m_cursor].type);
			p->child[1] = factor();
		}
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::factor()
{
	TreeNode* t = NULL;
	switch (m_tokens[m_cursor].type) {
	case LexicalAnalyzer::Token::NUM:
		t = newExpNode(ConstK);
		if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::NUM))
			t->attr.val = atoi(m_tokens[m_cursor].value.c_str());
		match(LexicalAnalyzer::Token::NUM);
		break;
	case LexicalAnalyzer::Token::ID:
		if (m_tokens[m_cursor + 1].type == LexicalAnalyzer::Token::LEFTPAR)
		{
			t = newExpNode(ArrayK);
			if(t!=NULL)t->child[0] = newExpNode(IdK);
			if ((t != NULL)&&(t->child[0] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
				t->child[0]->attr.name = (char*)m_tokens[m_cursor].value.data();
			match(LexicalAnalyzer::Token::ID);
			match(LexicalAnalyzer::Token::LEFTPAR);
			if (t != NULL)t->child[1] = newExpNode(ConstK);
			if ((t != NULL) && (t->child[1] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::NUM))
				t->child[1]->attr.val = atoi((char*)m_tokens[m_cursor].value.data());
			match(LexicalAnalyzer::Token::NUM);
			match(LexicalAnalyzer::Token::RIGHTPAR);
		}
		else if (m_tokens[m_cursor + 1].type == LexicalAnalyzer::Token::LPAREN)
		{
			t = newExpNode(funcK);
			if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
				t->attr.name = (char*)m_tokens[m_cursor].value.data();
			match(LexicalAnalyzer::Token::ID);
			match(LexicalAnalyzer::Token::LPAREN);
			if (m_tokens[m_cursor].type != LexicalAnalyzer::Token::RPAREN)
			{
				int childNumber = 0;
				if (t != NULL) t->child[childNumber++] = exp();
				while (m_tokens[m_cursor].type == LexicalAnalyzer::Token::COMMA)
				{
					match(LexicalAnalyzer::Token::COMMA);
					if (t != NULL) t->child[childNumber++] = exp();
				}
			}
			match(LexicalAnalyzer::Token::RPAREN);
		}
		else
		{
			t = newExpNode(IdK);
			if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
				t->attr.name = (char*)m_tokens[m_cursor].value.data();
			match(LexicalAnalyzer::Token::ID);
		}
		break;
	case LexicalAnalyzer::Token::LPAREN:
		match(LexicalAnalyzer::Token::LPAREN);
		t = exp();
		match(LexicalAnalyzer::Token::RPAREN);
		break;
	default:
		syntaxError("unexpected token -> ");
		printToken(m_tokens[m_cursor]);
		m_cursor++;
		break;
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::element()
{
	TreeNode* t = NULL;
	if (m_tokens[m_cursor + 1].type == LexicalAnalyzer::Token::LEFTPAR)
	{
		t = newExpNode(ArrayK);
		if(t!=NULL)t->child[0] = newExpNode(IdK);
		if ((t != NULL)&&(t->child[0] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
			t->child[0]->attr.name = (char*)m_tokens[m_cursor].value.data();
		match(LexicalAnalyzer::Token::ID);
		match(LexicalAnalyzer::Token::LEFTPAR);
		if (t != NULL)t->child[1] = newExpNode(ConstK);
		if ((t != NULL) && (t->child[1] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::NUM))
			t->child[1]->attr.val = atoi((char*)m_tokens[m_cursor].value.data());
		match(LexicalAnalyzer::Token::NUM);
		match(LexicalAnalyzer::Token::RIGHTPAR);
		if (m_tokens[m_cursor].type == LexicalAnalyzer::Token::EQ)
		{
			match(LexicalAnalyzer::Token::EQ);
			switch (m_tokens[m_cursor].type)
			{
			case LexicalAnalyzer::Token::NUM:
				if (t != NULL)t->child[2] = newExpNode(ConstK);
				if ((t != NULL) && (t->child[2] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::NUM))
					t->child[2]->attr.val = atoi(m_tokens[m_cursor].value.c_str());
				match(LexicalAnalyzer::Token::NUM);
				break;
			case LexicalAnalyzer::Token::FLOAT:
				if (t != NULL)t->child[2] = newExpNode(ConstK);
				if ((t != NULL) && (t->child[2] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::FLOAT))
					t->child[2]->attr.valf = atof(m_tokens[m_cursor].value.c_str());
				match(LexicalAnalyzer::Token::FLOAT);
				break;
			default:
				syntaxError("unexpected token -> ");
				printToken(m_tokens[m_cursor]);
				m_cursor++;
				break;
			}
		}
	}
	else if (m_tokens[m_cursor + 1].type == LexicalAnalyzer::Token::EQ)
	{
		t = newExpNode(IdK);
		if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
			t->attr.name = (char*)m_tokens[m_cursor].value.data();
		match(LexicalAnalyzer::Token::ID);
		match(LexicalAnalyzer::Token::EQ);
		switch (m_tokens[m_cursor].type)
		{
		case LexicalAnalyzer::Token::NUM:
			if (t != NULL)t->child[0] = newExpNode(ConstK);
			if ((t != NULL) &&(t->child[0] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::NUM))
				t->child[0]->attr.val = atoi(m_tokens[m_cursor].value.c_str());
			match(LexicalAnalyzer::Token::NUM);
			break;
		case LexicalAnalyzer::Token::FLOAT:
			if (t != NULL)t->child[0] = newExpNode(ConstK);
			if ((t != NULL) &&(t->child[0] != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::FLOAT))
				t->child[0]->attr.valf = atof(m_tokens[m_cursor].value.c_str());
			match(LexicalAnalyzer::Token::FLOAT);
			break;
		default:
			syntaxError("unexpected token -> ");
			printToken(m_tokens[m_cursor]);
			m_cursor++;
			break;
		}

	}
	else
	{
		t = newExpNode(IdK);
		if ((t != NULL) && (m_tokens[m_cursor].type == LexicalAnalyzer::Token::ID))
			t->attr.name = (char*)m_tokens[m_cursor].value.data();
		match(LexicalAnalyzer::Token::ID);
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::newStmtNode(StmtKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	if (t == NULL)
		m_outputFile<< "Out of memory error at line %d\n", m_tokens[m_cursor].lineNumber;
	else {
		for (int i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->lineno = m_tokens[m_cursor].lineNumber;
	}
	return t;
}

ParserAnalyzer::TreeNode* ParserAnalyzer::newExpNode(ExpKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		m_outputFile<< "Out of memory error at line %d\n", m_tokens[m_cursor].lineNumber;
	else {
		for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = kind;
		t->lineno = m_tokens[m_cursor].lineNumber;
		t->type = Void;
	}
	return t;
}

void ParserAnalyzer::syntaxError(string message)
{
	m_outputFile<< "\n>>> ";
	m_outputFile << "Syntax error at line %d: %s", m_tokens[m_cursor].lineNumber, message;
	isError = true;
}

void ParserAnalyzer::printToken(LexicalAnalyzer::Token token)
{
	switch (token.type)
	{
	case LexicalAnalyzer::Token::IF:
	case LexicalAnalyzer::Token::THEN:
	case LexicalAnalyzer::Token::ELSE:
	case LexicalAnalyzer::Token::END:
	case LexicalAnalyzer::Token::REPEAT:
	case LexicalAnalyzer::Token::UNTIL:
	case LexicalAnalyzer::Token::READ:
	case LexicalAnalyzer::Token::WRITE:
		m_outputFile <<"reserved word: %s\n", token.value;
		break;
	case LexicalAnalyzer::Token::ASSIGN: m_outputFile<< ":=\n"; break;
	case LexicalAnalyzer::Token::LT: m_outputFile<< "<\n"; break;
	case LexicalAnalyzer::Token::EQ: m_outputFile<< "=\n"; break;
	case LexicalAnalyzer::Token::LPAREN: m_outputFile<< "(\n"; break;
	case LexicalAnalyzer::Token::RPAREN: m_outputFile<< ")\n"; break;
	case LexicalAnalyzer::Token::SEMI: m_outputFile<< ";\n"; break;
	case LexicalAnalyzer::Token::PLUS: m_outputFile<< "+\n"; break;
	case LexicalAnalyzer::Token::MINUS: m_outputFile<< "-\n"; break;
	case LexicalAnalyzer::Token::TIMES: m_outputFile<< "*\n"; break;
	case LexicalAnalyzer::Token::OVER: m_outputFile<< "/\n"; break;
	case LexicalAnalyzer::Token::ENDFILE: m_outputFile<< "EOF\n"; break;
	case LexicalAnalyzer::Token::NUM:
		m_outputFile<<"NUM, val= %s\n", token.value;
		break;
	case LexicalAnalyzer::Token::FLOAT:
		m_outputFile<<"FLOAT, val= %s\n", token.value;
		break;
	case LexicalAnalyzer::Token::ID:
		m_outputFile<<"ID, name= %s\n", token.value;
		break;
	case LexicalAnalyzer::Token::ERROR:
		m_outputFile<<"ERROR: %s\n", token.value;
		break;
	default: /* should never happen */
		m_outputFile<< "Unknown token: %d\n", token.value;
	}
}

