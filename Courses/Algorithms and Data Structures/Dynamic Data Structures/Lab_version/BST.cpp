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
        printt(bst->right);
        printt(bst->left);
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

bstNode *searcht(bstNode *bst, int index) //searches an element
{
    while(bst && bst->index != index)
    {
        if(index < bst->index){
            bst = bst->left;
        }else{
            bst = bst->right;
        }
    }
    if(!bst)
    {
        cout<<"There is no student with id "<<index<<endl;
    }else
        //cout<<bst->name<<" "<<bst->surname<<" "<<bst->index<<endl;
    return bst;
}

void deletet(bstNode **bst, int index) //deletes an element
{
    bstNode *curr = *bst;
    //bstNode *root = *bst;
    bstNode *temp = NULL;
    bstNode *prev = NULL;
    while(curr && curr->index != index){
        prev = curr;
        if(index < curr->index)
        {
            curr = curr->left;
        }else{
            curr = curr->right;
        }
        //cout<<1<<endl;
    }
    //cout<<2<<endl;
    if(curr == NULL){
        cout<<index<<" doesn't exist"<<endl;
        return;
    }
    //cout<<3<<endl;
    if(!curr->left && !curr->right) //no child
    {
        //cout<<"no child"<<endl;
        if(!prev){
            *bst = NULL;
            return;
        }
        if(index < prev->index)
            prev->left = NULL;
        else{
            prev->right = NULL;
        }
    }else if(!curr->left){ //one child
        //cout<<"one child"<<endl;
        temp = curr->right;
        if(!prev)
        {
            *bst = temp;
            return;
        }
        if(index < prev->index){
            prev->left = temp;
        }else{
            prev->right = temp;
        }
    }else if(!curr->right){ //one child
        //cout<<"one child"<<endl;
        temp = curr->left;
        if(!prev)
        {
            *bst= temp;
            return;
        }
        if(index < prev->index){
            prev->left = temp;
        }else{
            prev->right = temp;
        }
        return;
    }else{ //two children
        //cout<<"two children"<<endl;
        bstNode* small = curr->right;
        bstNode* smallParent = curr;
        while(small->left){
            smallParent = small;
            small = small->left;
        }
        if(smallParent!=curr)
            smallParent->left = small->right; //remove reference
        else
            smallParent->right = small->right;

        small->left = curr->left;
        small->right = curr->right;
        if(!prev)
        {
            *bst = small;
            return;
        }
        if(index < prev->index)//usuwamy lewy child
            prev->left = small; //
        else{ //usuwamy prawy child
            prev->right = small;
        }
        return;
    }
}

int main()
{
    fstream plik, wyn, sea, del;
    clock_t start, endu;
    plik.open("data.txt");
    wyn.open("bst.txt");
    del.open("delete.txt");
    sea.open("search.txt");
    if(!plik.good() || !del.good() || !sea.good() || !wyn.good())
    {
       cout<<"Wrong file"<<endl;
       return 0;
    }

    int N,n; //number of instances, number of the elements
    string name, surname;
    int index;
    bstNode *bst = NULL; //initializing list
    plik>>N;
    for(int k=0;k<N;++k)
    {
        plik>>n;
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
        endu = clock();
        wyn<<"BST,"<<n<<","<<"append,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

        cout<<"search"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            sea>>index;
            searcht(bst, index);
        }
        endu = clock();
        wyn<<"BST,"<<n<<","<<"search,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

        cout<<"delete"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            del>>index;
            deletet(&bst, index);
        }
        endu = clock();
        wyn<<"BST,"<<n<<","<<"delete,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        printt(bst);
    }

    plik.close();
    wyn.close();
    del.close();
    sea.close();
    return 0;
}
