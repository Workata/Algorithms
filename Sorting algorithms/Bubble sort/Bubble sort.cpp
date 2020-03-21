#include<bits/stdc++.h>
#define N 10000
using namespace std;

int tab[N];

int main()
{
    int n;
    bool change=false;
    cin>>n;

    for(int i=0;i<n;i++)cin>>tab[i];

    while(1)
    {
        for(int i=0;i<n-1;i++)
        {
            if(tab[i]>tab[i+1])
            {
                swap(tab[i],tab[i+1]);
                change=true;
            }
        }
        if(!change)break;
        else change =false;
    }

    cout<<"\n";
    for(int i=0;i<n;i++)cout<<tab[i]<<" ";

}
