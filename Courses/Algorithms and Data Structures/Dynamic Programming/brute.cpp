#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    fstream wyn, plik, sol;
    clock_t start, endu;
    plik.open("items_br.txt");
    wyn.open("brute.txt",ios::in|ios::app);
    sol.open("solutions_BF.txt",ios::in|ios::app);

    if(!plik.good()){
        cout<<"Wrong file"<<endl;
        return 0;
    }

    if(!wyn.good()){
        cout<<"Wrong file2"<<endl;
        return 0;
    }

    if(!sol.good()){
        cout<<"Wrong file2"<<endl;
        return 0;
    }

    char bin; // : ;
    int n, N; //number of rows, Number of items
    plik>>n;

    wyn<<"n,"<<" capacity,"<<" method,"<<" time"<<endl;
    for(int i=0;i<n;++i)
    {
        plik>>N;
        plik>>bin;
        int tab[N][2]; // weight, value
        for(int j=0;j<N;++j)
        {
            plik>>tab[j][0]; //weight
            plik>>tab[j][1]; //value
            plik>>bin;
        }
        string ciag = "";
        for(int j=0;j<N;++j)
            ciag+='0';

        //wyn<<N<<" : ";
        cout<<N<<endl;
        //sol<<N<<" items: "<<endl;


        for(int c=15;c<=15;c+=1) //dla ró¿nych obci¹¿eñ plecaka
        {
            start = clock();
            int maxv=0; //max value
            bool add=0;
            int pos=0;
            while(!add || pos<N) //sprzwdzamy wszystkie mo¿liwe scenariusze brania itemków
            {
                add=1;
                pos=0;
                while(add && pos<N)//tworzymy ci¹gi 0-1, 0: zostawiamy itemek, 1: bierzemy itemek
                {
                    if(ciag[pos]=='1')
                    {
                        ciag[pos]='0';
                    }else{
                        ciag[pos]='1';
                        add=0;
                    }
                    pos+=1;
                }

                int temv=0; //temporary value
                int temw=0; //temporary weight
                for(int b=0;b<ciag.size();++b)//zliczamy wartoœæ spakowanych przedmiotów dla danego ci¹gu i podanego max obci¹¿enia plecaka
                {
                    if(ciag[b]=='1')
                    {
                        if(temw+tab[b][0]>c)
                            break;
                        else
                        {
                            temw+=tab[b][0];
                            temv+=tab[b][1];
                        }
                    }
                }
                if(temv>maxv)
                    maxv=temv;
            }
            //cout<<maxv<<" ";
            sol<<maxv<<endl;
            endu=clock();
            wyn<<N<<" ,"<<c<<" ,"<<" BF, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        }
        //sol<<endl;
        //wyn<<endl;
        //cout<<endl;
    }
    sol.close();
    wyn.close();
    plik.close();
    return 0;
}
