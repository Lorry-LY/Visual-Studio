#include "LexicalAnalyzer.h"
#include "ParserAnalyzer.h"

int main(int argc,char* args[])
{
	string input = argc > 1 ? args[1] : "SAMPLE.TNY";
	LexicalAnalyzer* lexical = new LexicalAnalyzer(input);
	ParserAnalyzer* parser = new ParserAnalyzer(input);
	lexical->getTokenList();
	lexical->printToken(true);
	parser->printTree(parser->analyze(lexical->getTokenList()),0);

	return 0;
}