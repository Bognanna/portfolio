#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct bstNode
{
    bstNode *left, *right;
    string name, surname;
    int index;
};

void printt(bstNode *bst)
{
    //cout<<1<<endl;
    if(bst)
    {
        cout<<bst->name<<" "<<bst->surname<<" "<<bst->index<<endl;
        printt(bst->left);
        printt(bst->right);
    }

}

void append( bstNode **bst, string name, string surname, int index) //appends an element
{
    bstNode *new_el = new bstNode; //creates new element
    bstNode *head = *bst;

    new_el->name = name;
    new_el->surname = surname;
    new_el->index = index;
    new_el->left = NULL;
    new_el->right = NULL;

    if(*bst == NULL){
        *bst = new_el;
        return;
    }
        while(true)
        {
            if(new_el->index < head->index)
            {
                if(head->left == NULL)
                    break;
                head = head->left;
                //cout<<1;
            }else if (new_el->index > head->index) {
                if(head->right == NULL)
                    break;
                head = head->right;
            }
        }
    if(new_el->index < head->index)
    {
        head->left = new_el;
    }
    else
    {
        head->right = new_el;
    }
    return;
}


int main()
{
    fstream plik;
    clock_t start, endu;
    plik.open("data_10.txt");

    if(!plik.good())
    {
       cout<<"Wrong file"<<endl;
       return 0;
    }

    int N,n; //number of instances, number of the elements
    string name, surname;
    int index;
    bstNode *bst = NULL; //initializing list
    N = 1;
    for(int k=0;k<N;++k)
    {
        n = 10;
        cout<<"n: "<<n<<endl;
        cout<<"append"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            plik>>name;
            plik>>surname;
            plik>>index;
            append(&bst, name, surname, index);
        }

        //endu = clock();
        //wyn<<"BST,"<<n<<","<<"append,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        cout<<"Pre order"<<endl;
        printt(bst);
    }

    plik.close();

    return 0;
}

