#include<iostream>
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
int tab[100000],n;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void showArray(int startIndex, int endIndex)
{
    cout<<endl<<" ";
    for(int i=startIndex;i<=endIndex;i++)cout<<tab[i]<<" ";
}

void showArrayPiwot(int startIndex, int endIndex, int piwotIndex)
{
    cout<<endl<<" ";
    for(int i=startIndex;i<=endIndex;i++)
    {
        if(i==piwotIndex)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout<<tab[i]<<" ";
            SetConsoleTextAttribute(hConsole, 7);

        }
        else  cout<<tab[i]<<" ";
    }
}

void showArrayBorder(int startIndex, int endIndex, int borderIndex)
{
    cout<<endl<<" ";
    for(int i=startIndex;i<=endIndex;i++)
    {
        if(i==borderIndex)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout<<tab[i]<<" ";
            SetConsoleTextAttribute(hConsole, 7);

        }
        else  cout<<tab[i]<<" ";
    }
}

int Partition(int p, int r)
{
    int x = tab[p]; //wybor piwota
    showArrayPiwot(p,r,p);
    cout<<"    <---- przed partycja";
    int i = p-1;
    int j = r+1;

    while(true)
    {
        do {j--; }while(tab[j]>x);  //>         warunek przeciwny do until
        do {i++; }while(tab[i]<x); //<
        if(i<j) swap(tab[i],tab[j]);
        else break;
    }
    return j;
}

void QuickSort(int p,int r)
{
    if(p<r)
    {

        int q = Partition(p,r);
        showArrayBorder(p,r,q);
        cout<<"    <---- po partycji";
        QuickSort(p,q);
        QuickSort(q+1,r);
    }
}

int main()
{
    cout<< " ";
    cin>>n;
    cout<<" ";
    for(int i=0;i<n;i++)cin>>tab[i];
    QuickSort(0,n-1);

    cout<<endl<<endl<<" Sorted array:";
    showArray(0,n-1);
}
