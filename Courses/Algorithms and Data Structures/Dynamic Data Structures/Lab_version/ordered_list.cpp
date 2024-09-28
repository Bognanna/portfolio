#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct olNode {
    olNode *next;
    string name, surname;
    int index;
};

void printl(olNode *ol){ //recursive function that prints all elements of the list
    if(ol)
    {
        cout<<ol->name<<" "<<ol->surname<<" "<<ol->index<<endl;
        printl(ol->next);
    }
}

olNode *pointer(olNode *ol){ //returns pointer to the last element
    if(ol)
    {
        while(ol->next)
            ol=ol->next;
    }
    return ol;
}

void append(olNode *&ol, string name, string surname, int index){ //appends an element to the end of the list
    olNode *new_el = new olNode; //creates new element of the list
    new_el->name = name;
    new_el->surname = surname;
    new_el->index = index;
    new_el->next = NULL;

    if(ol) // appends new element to the end
        pointer(ol)->next = new_el;
    else
        ol = new_el;
}

olNode *searchl(olNode *ol, int id){ //searches for an element
    if(ol)
    {
        while(ol->next && ol->index != id)
            ol = ol->next;
        if(ol->next == NULL)
        {
            if(ol->index == id)
            {
                //cout<<ol->name<<" "<<ol->surname<<" "<<ol->index<<endl;
                return ol;
            }
            cout<<"There is no student with id "<<id<<endl;
            return NULL;
        }
    }
    //cout<<ol->name<<" "<<ol->surname<<" "<<ol->index<<endl;
    return ol;
}

void clearl(olNode *&ol) //destroys the list
{
    while(ol)
    {
        olNode *temp = ol;
        ol = ol->next;
        delete temp;
    }
    ol = NULL;
}

void deletel(olNode **ol, int id) //deletes an element
{
    olNode *pom = *ol;
    olNode *prev = NULL;
    if (pom->next && pom->index == id) // If head node itself holds the key to be deleted
    {
        *ol = pom->next;
        delete pom;
        return;
    }else if (pom->index == id){
        clearl(*ol);
        return;
    }else{
        while(pom->next && pom->index != id)
        {
            prev = pom;
            pom = pom->next;
        }
        if(pom->next == NULL) // If key was not present in linked list
        {
            if(pom->index == id)
            {
                prev->next = NULL;
                delete pom;
                return;
            }
            cout<<"There is no student with id "<<id<<endl;
            return;
        }
    }
    prev->next = pom->next;
    delete pom;
}

int main() //ordered list == linked list == unidirectional list
{
    fstream plik, wyn, sea, del;
    clock_t start, endu;
    plik.open("data.txt");
    wyn.open("ol.txt");
    del.open("delete.txt");
    sea.open("search.txt");

    if(!plik.good() || !del.good() || !sea.good() || !wyn.good())
    {
       cout<<"Wrong file"<<endl;
       return 0;
    }


    int N, n; //number of the elements, number of instances
    string name, surname;
    int index;
    olNode *ol = NULL; //initializing list

    plik>>N;
    cout<<"N: "<<N<<endl;

    wyn<<"data_structure,"<<"no_elements,"<<"operation,"<<"time"<<endl;
    for(int k=0;k<N;++k)
    {
        plik>>n;
        cout<<"n: "<<n<<endl;
        //wyn<<n<<" ";

        cout<<"append"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            plik>>name;
            plik>>surname;
            plik>>index;
            append(ol, name, surname, index);
        }
        endu = clock();
        wyn<<"OL,"<<n<<","<<"append,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

        cout<<"search"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            sea>>index;
            searchl(ol, index);
        }
        endu = clock();
        wyn<<"OL,"<<n<<","<<"search,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

        cout<<"delete"<<endl;
        start = clock();
        for(int i=0;i<n;++i)
        {
            del>>index;
            deletel(&ol, index);
        }
        endu = clock();
        wyn<<"OL,"<<n<<","<<"delete,"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        printl(ol);
        clearl(ol);

    }

    plik.close();
    wyn.close();
    del.close();
    sea.close();
    return 0;
}
