#include "Gragh.h"

void Gragh::addSide(pair<char, char> side)
{
	sides.push_back(side);
}

void Gragh::addNode(char A)
{
	nodes.push_back(A);
}