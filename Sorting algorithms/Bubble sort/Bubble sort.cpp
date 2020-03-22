#include<bits/stdc++.h>
#include <windows.h>
#define N 10000
using namespace std;

int tab[N], n,k=7;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void showArray(int colorIndex, bool change)
{
    cout<<"\n"<<" ";
    for(int i=0;i<n;i++)
    {
        if(i==colorIndex || i==colorIndex+1)
        {
            k= 12;
            SetConsoleTextAttribute(hConsole, k);
            cout<<tab[i]<<" ";
            k=7;
            SetConsoleTextAttribute(hConsole, k);
        }
        else cout<<tab[i]<<" ";
    }
    if(change)
    {
        k= 14;
        SetConsoleTextAttribute(hConsole, k);
        cout<<"   "<<"swap";
        k=7;
        SetConsoleTextAttribute(hConsole, k);
    }
}

int main()
{
    bool change=false;

    cout<<" ";
    cin>>n;
    cout<<" ";
    for(int i=0;i<n;i++)cin>>tab[i];



    for(int j=1;j<=n-1;j++)
    {
        for(int i=0;i<n-j;i++)
        {

            if(tab[i]>tab[i+1])  //>
            {
                swap(tab[i],tab[i+1]);
                change=true;
            }
            showArray(i,change);
        }
        if(!change)break;
        else change =false;
    }

    cout<<endl<<" Sorted Array: ";
    showArray(-10,false);
    cout<<endl;

}
