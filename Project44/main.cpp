//
// Created by Administrator on 2021/11/20.
//

#include <mqoai.h>
#include "iostream"
#include "binary_tree.h"
#include "bin_tree_node.h"
#include <fstream>

using namespace std;

class GameOfAnimal {
private:
    BinaryTree<string>* pDTree;
    void WriteHlep(BinTreeNode<string>* root, ofstream& outFile);
    bool IsQuestion(string strSentence);

public:
    GameOfAnimal();
    virtual ~GameOfAnimal();
    void Run();
};


Boolean UserSaysYes(void)
{
    int c;
    printf("(y/n)?");
    do {
        while ((c = getchar()) == '\n')
            ;
        if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
            return(c == 'y' || c == 'Y');
        printf("Please respond by typing one of the letter y or Y.\n");
    } while (1);
}



void GameOfAnimal::Run() {
    do {
        cout << "想出一个动物，我将尽力猜它..." << endl;
        BinTreeNode<string>* p = pDTree->GetRoot();
        string strElem = p->data;
        while (IsQuestion(strElem))
        {
            cout << strElem;
            cout << "请回答";
            if (UserSaysYes())
            {
                p = p->leftChild;
            }
            else
            {
                p = p->rightChild;
                strElem = p->data;
            }
        }
        cout << "你想的动物是" << strElem << "吗？请回答";
        if (UserSaysYes())
        {
            cout << "哈！一台计算机都打败了你..." << endl;
        }
        else
        {
            cout << "你是幸运的..." << endl;
            cout << "你想的什么动物呢？" << endl;
            string  strNewAnimal, strOldAnimal = strElem;
            cin >> strNewAnimal;
            cout << "请输入一个疑问句，肯定回答为" << strNewAnimal << ",否定回答为" << strOldAnimal << endl;
            cin >> strElem;
            p->data = strElem;
            p->leftChild = new BinTreeNode<string>(strNewAnimal);
            p->rightChild = new BinTreeNode<string>(strOldAnimal);
        }
        cout << "想再玩一次吗？请回答";
    } while (UserSaysYes());
}
void GameOfAnimal::WriteHlep(BinTreeNode<string>* root, ofstream& outFile) {
    if (root != NULL)
    {
        WriteHlep(root->leftChild, outFile);
        WriteHlep(root->rightChild, outFile);
        outFile << root->data << endl;
    }
}