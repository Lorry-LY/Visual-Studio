#pragma once

#include "LexicalAnalyzer.h"

#define MAXCHILDREN 8

class ParserAnalyzer
{
private:
	vector<LexicalAnalyzer::Token> m_tokens;
	int m_cursor;
	fstream m_outputFile;
	bool isError;


	typedef enum { StmtK, ExpK } NodeKind;
	typedef enum { IfK, RepeatK, AssignK, ReadK, WriteK,IdentK,DefK,WhileK } StmtKind;
	typedef enum { OpK, ConstK, IdK ,ArrayK,funcK} ExpKind;
	/* ExpType is used for type checking */
	typedef enum { Void, Integer, Boolean,Float } ExpType;

	typedef struct treeNode
	{
		struct treeNode* child[MAXCHILDREN];
		struct treeNode* sibling;
		int lineno;
		NodeKind nodekind;
		union { StmtKind stmt; ExpKind exp; } kind;
		union _attr{
			LexicalAnalyzer::Token::TokenType op;
			int val;
			float valf;
			char* name;
		} attr;
		ExpType type; /* for type checking of exps */
	} TreeNode;

public:
	ParserAnalyzer() {};
	ParserAnalyzer(string input);
	TreeNode* analyze(vector<LexicalAnalyzer::Token> tokens);
	void printTree(TreeNode* t,int level);
	void match(LexicalAnalyzer::Token::TokenType expected);

private:
	TreeNode* stmt_sequence();
	TreeNode* statement();
	TreeNode* if_stmt();
	TreeNode* while_stmt();
	TreeNode* repeat_stmt();
	TreeNode* assign_stmt();
	TreeNode* read_stmt();
	TreeNode* write_stmt();
	TreeNode* ident_stmt();
	TreeNode* def_stmt();
	TreeNode* exp();
	TreeNode* simple_exp();
	TreeNode* term();
	TreeNode* factor();
	TreeNode* element();

	TreeNode* newStmtNode(StmtKind kind);
	TreeNode* newExpNode(ExpKind kind);

	void syntaxError(string message);
	void printToken(LexicalAnalyzer::Token token);
};

