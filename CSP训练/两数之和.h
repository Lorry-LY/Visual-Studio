#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int value;
    int key;
    Node* nextNode;
};

vector<int> twoSum(vector<int>& nums, int target) {
    const int hashLength = 20000;
    Node* hash[hashLength + 1] = { NULL };
    for (int i = 0; i < nums.size(); i++)
    {
        int mul = nums[i] % (hashLength / 2);
        Node* currentNode = hash[mul + hashLength / 2];
        if (currentNode == NULL)
        {
            hash[mul + hashLength / 2] = new Node{ nums[i],i,NULL };
        }
        else
        {
            while (currentNode->nextNode != NULL)currentNode = currentNode->nextNode;
            Node* newNode = new Node{ nums[i],i,NULL };
            currentNode->nextNode = newNode;
        }
    }
    int mul = target % (hashLength / 2);
    for (int i = 0; i < hashLength; i++)
    {
        int j = mul - (i - hashLength / 2) + hashLength / 2;
        if (hash[i] != NULL && hash[j] != NULL)
        {
            Node* first = hash[i];
            Node* second = hash[j];
            while (first != NULL)
            {
                while (second != NULL)
                {
                    if (first->key != second->key && first->value + second->value == target)
                    {
                        return { first->key,second->key };
                    }
                    second = second->nextNode;
                }
                first = first->nextNode;
            }
        }
    }
    return { -1,-1 };
}

int main()
{
    vector<int>nums = { 2,2,2,7,11,15,90 };
    int target = 9;
    vector<int> result = twoSum(nums, target);

    return 0;
}