#include<bits/stdc++.h>
using namespace std;
#define N 10000      //array size

int n;

void quickSort(int first, int last,int* tab)  //first - first index, last - last index
{
    //cout<<first<<" "<<last<<"\n";
    if(first == last) return;

    int middle = (last+first)/2;
    int* j = tab + first;
    for(int* i = (tab + first) ;i<=(tab + last);i++)  //search array
    {
        if(tab[middle]>*i)
        {
            swap(*i,*j);
            j++;
        }
    }

    quickSort(first,(last+first)/2,tab);
    quickSort((last+first)/2+1,last,tab);
}

int main()
{
    int tab[N];
    cin>>n;
    for(int i=0;i<n;i++)cin>>tab[i];
    cout<<"\n";
    quickSort(0,n-1,tab);

    cout<<"\n";
    for(int i=0;i<n;i++)cout<<tab[i]<<" ";

    return 0;
}
