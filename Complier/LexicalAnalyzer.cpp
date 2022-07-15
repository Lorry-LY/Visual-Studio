#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer()
{
	LexicalAnalyzer("");
}

LexicalAnalyzer::LexicalAnalyzer(string input)
{
	this->m_inputFile = fstream(input, ios::in);
	this->m_outputFile = fstream("output.txt", ios::out);
	if (!m_inputFile.is_open() || !m_outputFile.is_open())
	{
		cout << "文件打开失败。" << endl;
		return;
	}
	string temp;
	while (getline(m_inputFile, temp))this->m_sourceCode.push_back(temp);
	this->m_currentLine = 0;
	this->m_commitState = 0;
}

vector<LexicalAnalyzer::Token> LexicalAnalyzer::getTokenList()
{
	vector<Token> tokens;
	this->m_commitState = 0;
	for (m_currentLine = 0; m_currentLine < this->m_sourceCode.size(); m_currentLine++)
	{
		int start = 0, end;
		while (start != m_sourceCode[m_currentLine].size())
		{
			while (this->m_sourceCode[m_currentLine][start] == ' ' || this->m_sourceCode[m_currentLine][start] == '\t')start++;
			end = start;
			Token toke = getToken(start, end);
			if (toke != Token())tokens.push_back(toke);
			start = end;
		}
	}
	Token token(Token::ENDFILE, "", m_currentLine);
	tokens.push_back(token);
	m_tokens = tokens;
	return tokens;
}

void LexicalAnalyzer::printToken(bool target)
{
	int tokenNumber = 0;
	for (m_currentLine = 0; m_currentLine < m_sourceCode.size(); m_currentLine++)
	{
		if (target)cout << m_currentLine + 1 << ":" << m_sourceCode[m_currentLine] << endl;
		while (tokenNumber < m_tokens.size() && m_tokens[tokenNumber].lineNumber == m_currentLine)
		{
			cout << "	" << m_currentLine + 1 << ":" << "	TokenType:" << TokenTypeToString(m_tokens[tokenNumber]) << "    value:" << m_tokens[tokenNumber].value << endl;
			tokenNumber++;
		}
	}
	cout << "	" << m_currentLine + 1 << ":" << "	TokenType:" << TokenTypeToString(m_tokens[tokenNumber]) << "    value:" << m_tokens[tokenNumber].value << "\n\n\n\n";
}

LexicalAnalyzer::Token LexicalAnalyzer::getToken(int start, int& end)
{
	if (!m_commitState)
	{
		Token token;
		int len = -2;
		if ((m_commitState = startAnnotation(start, end)) != 0) {
			return Token();
		}
		if ((len = isReservedWords(start)) != -1) {
			end = start + len;
			return getReservedWordsToken(start, len);
		}
		if ((len = isSymbols(start)) != -1) {
			end = start + len;
			return getSymbolsToken(start, len);
		}
		if ((len = isFloat(start)) != -1) {
			end = start + len;
			return getFloatToken(start, len);
		}
		if ((len = isInteger(start)) != -1) {
			end = start + len;
			return getIntegerToken(start, len);
		}
		if ((len = isID(start)) != -1) {
			end = start + len;
			return getIDToken(start, len);
		}
		return Token();
	}
	else
	{
		if (m_commitState == 1)m_commitState = endAnnotation(start, end, "}");
		if (m_commitState == 2)m_commitState = endAnnotation(start, end, "*/");
		return Token();
	}

}

LexicalAnalyzer::Token LexicalAnalyzer::getReservedWordsToken(int off, int size)
{
	switch (size)
	{
	case 2: {
		return Token(Token::TokenType::IF, "if", m_currentLine);
		break;
	}
	case 3: {
		if ("end" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::END, "end", m_currentLine);
		if ("int" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::INT, "int", m_currentLine);
		if ("def" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::DEF, "def", m_currentLine);
		break;
	}
	case 4: {
		if ("then" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::THEN, "then", m_currentLine);
		if ("else" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::ELSE, "else", m_currentLine);
		if ("read" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::READ, "read", m_currentLine);
		break;
	}
	case 5: {
		if ("float" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::FLT, "float", m_currentLine);
		if ("while" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::WHILE, "while", m_currentLine);
		if ("write" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::WRITE, "write", m_currentLine);
		if ("until" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::UNTIL, "until", m_currentLine);
		break;
	}
	case 6: {
		return Token(Token::TokenType::REPEAT, "repeat", m_currentLine);
		break;
	}
	default:
		return Token();
		break;
	}
	return Token();
}

LexicalAnalyzer::Token LexicalAnalyzer::getSymbolsToken(int off, int size)
{
	switch (size)
	{
	case 1: {
		if ("=" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::EQ, "=", m_currentLine);
		if ("<" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::LT, "<", m_currentLine);
		if ("+" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::PLUS, "+", m_currentLine);
		if ("-" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::MINUS, "-", m_currentLine);
		if ("*" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::TIMES, "*", m_currentLine);
		if ("/" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::OVER, "/", m_currentLine);
		if ("(" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::LPAREN, "(", m_currentLine);
		if (")" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::RPAREN, ")", m_currentLine);
		if (";" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::SEMI, ";", m_currentLine);
		if ("," == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::COMMA, ",", m_currentLine);
		if ("[" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::LEFTPAR, "[", m_currentLine);
		if ("]" == this->m_sourceCode[m_currentLine].substr(off, size))return Token(Token::TokenType::RIGHTPAR, "]", m_currentLine);
		break;
	}
	case 2: {
		return Token(Token::TokenType::ASSIGN, ":=", m_currentLine);
		break;
	}
	default:
		return Token();
		break;
	}
	return Token();
}

LexicalAnalyzer::Token LexicalAnalyzer::getIntegerToken(int off, int size)
{
	return Token(Token::TokenType::NUM, m_sourceCode[m_currentLine].substr(off, size), m_currentLine);
}

LexicalAnalyzer::Token LexicalAnalyzer::getFloatToken(int off, int size)
{
	return Token(Token::TokenType::FLOAT, m_sourceCode[m_currentLine].substr(off, size), m_currentLine);
}

LexicalAnalyzer::Token LexicalAnalyzer::getIDToken(int off, int size)
{
	return Token(Token::TokenType::ID, m_sourceCode[m_currentLine].substr(off, size), m_currentLine);
}

int LexicalAnalyzer::startAnnotation(int start, int& end)
{
	if ("{" == this->m_sourceCode[m_currentLine].substr(start, 1)) {
		end = start + 1;
		return 1;
	}
	if ("/*" == this->m_sourceCode[m_currentLine].substr(start, 2)) {
		end = start + 2;
		return 2;
	}
	if ("//" == this->m_sourceCode[m_currentLine].substr(start, 2)) {
		end = m_sourceCode[m_currentLine].size();
		return 3;
	}
	return 0;
}

int LexicalAnalyzer::endAnnotation(int start, int& end, string endLetter)
{
	for (m_currentLine; m_currentLine < m_sourceCode.size(); m_currentLine++)
	{
		while (start < m_sourceCode[m_currentLine].size() - endLetter.size() + 1)
		{
			if (endLetter == this->m_sourceCode[m_currentLine].substr(start, endLetter.size()))
			{
				end = start + endLetter.size();
				return 0;
			}
			start++;
		}
		start = 0;
	}
	return 3;
}

string LexicalAnalyzer::TokenTypeToString(Token token)
{
	vector<string> names = { "ENDFILE", "ERROR", "NONE",
		"IF", "THEN", "ELSE", "END", "REPEAT", "UNTIL", "READ", "WRITE","INT","FLT","DEF","WHILE",
		"ID", "NUM", "FLOAT",
		"ASSIGN", "EQ", "LT", "PLUS", "MINUS", "TIMES", "OVER", "LPAREN", "RPAREN", "SEMI","COMMA","LEFTPAR","RIGHTPAR"};
	return names[token.type];
}

int LexicalAnalyzer::isReservedWords(int index)
{
	string str = this->m_sourceCode[m_currentLine].substr(index, 2);
	if ("if" == str)return 2;
	str = this->m_sourceCode[m_currentLine].substr(index, 3);
	if ("end" == str)return 3;
	if ("def" == str)return 3;
	if ("int" == str)return 3;
	str = this->m_sourceCode[m_currentLine].substr(index, 4);
	if ("then" == str)return 4;
	if ("else" == str)return 4;
	if ("read" == str)return 4;
	str = this->m_sourceCode[m_currentLine].substr(index, 5);
	if ("write" == str)return 5;
	if ("while" == str)return 5;
	if ("until" == str)return 5;
	if ("float" == str)return 5;
	str = this->m_sourceCode[m_currentLine].substr(index, 6);
	if ("repeat" == str)return 6;
	return -1;
}

int LexicalAnalyzer::isSymbols(int index)
{
	string str = this->m_sourceCode[m_currentLine].substr(index, 2);
	if (":=" == str)return 2;
	char ch = this->m_sourceCode[m_currentLine].substr(index, 1)[0];
	switch (ch)
	{
	case '=':case '<':case '+':case '-':case '*':case '/':case '(':case ')':case ';':case ',':case '[':case ']':return 1;
	default:return -1;
	}
	return -1;
}

int LexicalAnalyzer::isInteger(int index)
{
	int end = index;
	while ('0' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= '9')end++;
	if (end == index)return -1;
	else return end - index;
}

int LexicalAnalyzer::isFloat(int index)
{
	int end = index;
	while ('0' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= '9')end++;
	if (end == index || m_sourceCode[m_currentLine][end++] != '.')return -1;
	while ('0' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= '9')end++;
	if (m_sourceCode[m_currentLine][end] != 'E')return end - index;
	if (m_sourceCode[m_currentLine][++end] == '+' || m_sourceCode[m_currentLine][++end] == '-')end++;
	while ('0' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= '9')end++;
	return end - index;
}

int LexicalAnalyzer::isID(int index)
{
	int end = index;
	if (('A' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= 'Z')
		|| ('a' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= 'z')
		|| (this->m_sourceCode[m_currentLine][end] == '_'))end++;
	else return -1;
	while (('A' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= 'Z')
		|| ('a' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= 'z')
		|| ('0' <= this->m_sourceCode[m_currentLine][end] && this->m_sourceCode[m_currentLine][end] <= '9')
		|| (this->m_sourceCode[m_currentLine][end] == '_'))end++;
	return end - index;
}

