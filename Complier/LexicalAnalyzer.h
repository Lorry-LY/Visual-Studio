#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class LexicalAnalyzer
{
public:
	LexicalAnalyzer();
	LexicalAnalyzer(string input);

	friend class ParserAnalyzer;
private:
	fstream m_inputFile;
	fstream m_outputFile;
	vector<string> m_sourceCode;
	int m_currentLine;
	int m_commitState;

	/* book-keeping tokens */
	typedef struct Token {
		string value;
		int lineNumber;
		enum TokenType
		{
			ENDFILE, ERROR, NONE,
			/* reserved words */
			IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, INT, FLT, DEF,WHILE,
			/* multicharacter tokens */
			ID, NUM, FLOAT,
			/* special symbols */
			ASSIGN, EQ, LT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI, COMMA, LEFTPAR, RIGHTPAR
		}type;
		Token(TokenType type = TokenType::NONE, string value = "", int line = -1) :type(type), value(value), lineNumber(line) {};
		bool operator ==(const Token t)const { return this->type == t.type && value == t.value && lineNumber == t.lineNumber; };
		bool operator !=(const Token t)const { return this->type != t.type || value != t.value || lineNumber != t.lineNumber; };
	};

	vector<Token> m_tokens;

public:
	vector<Token> getTokenList();
	void printToken(bool target);

private:
	int isReservedWords(int index);
	int isSymbols(int index);
	int isInteger(int index);
	int isFloat(int index);
	int isID(int index);

	Token getToken(int start, int& end);
	Token getReservedWordsToken(int off, int size);
	Token getSymbolsToken(int off, int size);
	Token getIntegerToken(int off, int size);
	Token getFloatToken(int off, int size);
	Token getIDToken(int off, int size);
	int startAnnotation(int start, int& end);
	int endAnnotation(int start, int& end, string endLetter);

	string TokenTypeToString(Token token);
};

