#pragma once

#include<iostream>
#include<vector>

using namespace std;

class Gragh
{
public:
	void addSide(pair<char, char> side);
	void addNode(char A);

public:
	vector<char> nodes;
	vector<pair<char, char>> sides;
};

