#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct bbstNode
{
    bbstNode *left, *right;
    string name, surname;
    int index;
};

void heapify(int tab1[], char *tab2[], char *tab3[] ,int id,int tab_size)
{
    int l=2*id+1;
    int r=l+1;
    int maxi=id;
    if(l < tab_size && tab1[l] > tab1[maxi])
        maxi=l;
    if(r < tab_size && tab1[r] > tab1[maxi])
        maxi=r;

    if(maxi!=id)
    {
        swap(tab1[id], tab1[maxi]);
        swap(tab2[id], tab2[maxi]);
        swap(tab3[id], tab3[maxi]);

        heapify(tab1,tab2,tab3,maxi,tab_size);
    }
}

void HS(int tab1[], char *tab2[], char *tab3[] ,int tab_size)
{
    for(int i=(tab_size/2)-1;i>=0;i--)
    {
        heapify(tab1,tab2, tab3, i,tab_size);
    }
    for(int i=tab_size-1;i>0;i--)
    {
        swap(tab1[0], tab1[i]);
        swap(tab2[0], tab2[i]);
        swap(tab3[0], tab3[i]);
        heapify(tab1,tab2,tab3,0,i);
    }
}

bbstNode* add(int id, string name, string surname)
{
    bbstNode* new_el = new bbstNode();
    new_el->index = id;
    new_el->name = name;
    new_el->surname = surname;
    new_el->left = NULL;
    new_el->right = NULL;

    return new_el;
}

bbstNode* convert(int tab1[], char *tab2[], char *tab3[], int l, int r)
{
    if (l > r)
    return NULL;

    int mid = (l + r)/2;
    bbstNode* root = add(tab1[mid], tab2[mid], tab3[mid]);

    root->left = convert(tab1, tab2, tab3, l, mid - 1);
    root->right = convert(tab1, tab2, tab3, mid + 1, r);

    return root;
}

void printt(bbstNode *bbst)
{
    if(bbst)
    {
        cout<<bbst->name<<" "<<bbst->surname<<" "<<bbst->index<<endl;
        printt(bbst->right);
        printt(bbst->left);
    }
}

bbstNode *searcht(bbstNode *bbst, int id) //searches an element
{
    while(bbst && bbst->index != id)
    {
        if(id < bbst->index){
            bbst = bbst->left;
        }else{
            bbst = bbst->right;
        }
    }
    if(!bbst)
    {
        cout<<"There is no student with id "<<id<<endl;
    }else
        //cout<<bbst->name<<" "<<bbst->surname<<" "<<bbst->index<<endl;
    return bbst;
}

void deletet(bbstNode **bbst, int index) //deletes an element
{
    bbstNode *curr = *bbst;
    bbstNode *temp = NULL;
    bbstNode *prev = NULL;
    while(curr && curr->index != index){
        prev = curr;
        if(index < curr->index){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }

    if(curr == NULL){
        cout<<index<<" doesn't exist"<<endl;
        return;
    }

    if(!curr->left && !curr->right) //no child
    {
        if(!prev){
            *bbst = NULL;
            return;
        }else if(index < prev->index)
            prev->left = NULL;
        else{
            prev->right = NULL;
        }

    }else if(!curr->left){ //one child
        temp = curr->right;
        if(!prev){
            *bbst = temp;
            return;
        }
        if(index < prev->index){
            prev->left = temp;
        }else{
            prev->right = temp;
        }

    }else if(!curr->right){ //one child
        temp = curr->left;
        if(!prev){
            *bbst= temp;
            return;
        } else if(index < prev->index){
            prev->left = temp;
        }else{
            prev->right = temp;
        }
        return;

    }else{ //two children
        bbstNode* small = curr->right;
        bbstNode* smallParent = curr;
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
        if(!prev){
            *bbst = small;
            return;
        }
        if(index < prev->index)//usuwamy lewy child
            prev->left = small;
        else{ //usuwamy prawy child
            prev->right = small;
        }
        return;
    }
}

int main()
{
    fstream plik, wyn, sea, del;
    clock_t start, start2, endu;
    plik.open("data.txt");
    wyn.open("bbst.txt");
    del.open("delete.txt");
    sea.open("search.txt");
    if(!plik.good())
    {
       cout<<"Wrong file"<<endl;
       return 0;
    }

    int N,n; //number of instances, number of the elements
    int id;
    bbstNode *bbst = NULL; //initializing list
    plik>>N;
    for(int k=0;k<N;++k)
    {

        plik>>n;
        int* index = new int[n];
        char** name = (char**)malloc(n *sizeof(char*));
        char** surname = (char**)malloc(n *sizeof(char*));
        for(int i=0; i<n;++i){
            name[i] = (char*)malloc(12 * sizeof(char));
            surname[i] = (char*)malloc(12 * sizeof(char));
        }

        cout<<"n: "<<n<<endl;
        cout<<"append"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            plik>>name[i];
            plik>>surname[i];
            plik>>index[i];
        }
        HS(index, name, surname, n);

        start2 = clock();
        bbst = convert(index, name, surname, 0, n-1);
        endu = clock();
        wyn<<"BBST,"<<n<<","<<"append,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;


        cout<<"search"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            sea>>id;
            searcht(bbst, id);
        }
        endu = clock();
        wyn<<"BBST,"<<n<<","<<"search,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

        cout<<"delete"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            del>>id;
            deletet(&bbst, id);
        }

        endu = clock();
        wyn<<"BBST,"<<n<<","<<"delete,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        printt(bbst);

        for(int i = 0; i<n; ++i){
           free(name[i]);
           free(surname[i]);
        }
        free(name);
        free(surname);
        free(index);
    }

    plik.close();
    wyn.close();
    del.close();
    sea.close();
    return 0;
}
