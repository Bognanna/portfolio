#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    fstream plik;
    plik.open("items.txt");
    //plik.open("items_br.txt"); //brute

    if(!plik.good()){
        cout<<"Wrong file"<<endl;
        return 0;
    }

    srand(time(NULL));
    int maxw=50; //weight
    int maxv=100; //value
    int maxn=50000;//number of items
    int space=1000; // step
    //int maxn = 33; //brute
    //int space = 1; //brute

    plik<<((maxn/space))<<endl;

    for(int i=space;i<=maxn;i+=space)
    {
        plik<<i<<" : ";
        for(int j=0;j<i;++j)
        {
            plik<<rand()%(maxw-1)+1<<" "<<rand()%(maxv-1)+1<<" ; ";
        }
        plik<<endl;
    }

    plik.close();
    return 0;
}
