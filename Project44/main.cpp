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
        cout << "���һ������ҽ���������..." << endl;
        BinTreeNode<string>* p = pDTree->GetRoot();
        string strElem = p->data;
        while (IsQuestion(strElem))
        {
            cout << strElem;
            cout << "��ش�";
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
        cout << "����Ķ�����" << strElem << "����ش�";
        if (UserSaysYes())
        {
            cout << "����һ̨��������������..." << endl;
        }
        else
        {
            cout << "�������˵�..." << endl;
            cout << "�����ʲô�����أ�" << endl;
            string  strNewAnimal, strOldAnimal = strElem;
            cin >> strNewAnimal;
            cout << "������һ�����ʾ䣬�϶��ش�Ϊ" << strNewAnimal << ",�񶨻ش�Ϊ" << strOldAnimal << endl;
            cin >> strElem;
            p->data = strElem;
            p->leftChild = new BinTreeNode<string>(strNewAnimal);
            p->rightChild = new BinTreeNode<string>(strOldAnimal);
        }
        cout << "������һ������ش�";
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