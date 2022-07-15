/*
 * TODO: add a file header here.
 */
#include "BST.h"
#include <vector>

BST::BST() {
    /* YOUR CODE HERE */
    root = nullptr;
    numElements = 0;
}

BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return this->numElements;
}

BST::Node* BST::getRoot()
{
    return this->root;
}

void BST::clear() {
    /* YOUR CODE HERE */
    if (!root)return;
    Node* temp = root;
    vector<Node*> nodes;
    nodes.push_back(temp);
    while (nodes.size())
    {
        temp = nodes.back();
        nodes.pop_back();
        if (temp->leftChild)nodes.push_back(temp->leftChild);
        if (temp->rightChild)nodes.push_back(temp->rightChild);
        delete temp;
        temp = nullptr;
    }
    this->root = nullptr;
    numElements = 0;
}

bool BST::insert(int element) {
    /* YOUR CODE HERE */
    if (root == nullptr)
    {
        root = new Node(element);
        numElements++;
        return true;
    }
    Node* temp = root;
    while (temp)
    {
        if (element > temp->data)
        {
            if (temp->rightChild)
            {
                temp = temp->rightChild;
                continue;
            }
            else
            {
                Node* newNode = new Node(element);
                temp->rightChild = newNode;
                newNode->parent = temp;
                numElements++;
                return true;
            }
        }
        else if (element < temp->data)
        {
            if (temp->leftChild)
            {
                temp = temp->leftChild;
                continue;
            }
            else
            {
                Node* newNode = new Node(element);
                temp->leftChild = newNode;
                newNode->parent = temp;
                numElements++;
                return true;
            }
        }
        else return false;
    }
    return false;
}

bool BST::find(const int& query) const {
    /* YOUR CODE HERE */
    if (root == nullptr)return false;
    Node* temp = root;
    while (temp)
    {
        if (query > temp->data)
        {
            if (temp->rightChild)temp = temp->rightChild;
            else return false;
        }
        else if (query < temp->data)
        {
            if (temp->leftChild)temp = temp->leftChild;
            else return false;
        }
        else return true;

    }
    return false;
}

BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    if (!root)return nullptr;
    Node* temp = this->root;
    while (temp->leftChild)temp = temp->leftChild;
    return temp;
}

BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    if (this->rightChild) {
        Node* temp = this->rightChild;
        while (temp->leftChild)temp = temp->leftChild;
        return temp;
    }
    Node* child = this;
    Node* parent = this->parent;
    while (parent && parent->rightChild == child)
    {
         child = parent;
         parent = parent->parent;
    }
    return parent;
}