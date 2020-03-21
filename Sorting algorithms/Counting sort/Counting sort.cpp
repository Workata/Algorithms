#include<bits/stdc++.h>
using namespace std;
#define N 10000

int tab[N], counter[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
        counter[tab[i]]++;
    }

    cout<<"\n";

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<counter[i];j++) cout<<i<<" ";
    }
}
