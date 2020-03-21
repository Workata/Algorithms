#include<bits/stdc++.h>
using namespace std;
#define N 10000      //array size

int tab[N];

int main()
{
    int n,a,k;
    vector <int> sortedTab;

    cout<<"Enter number of elements: \n";
    cin>>n;
    cout<<"Enter elements: \n";

    for(int i=0; i<n;i++)
    {
        cin>>a;
        tab[i] = a;
        if(i==0)
        {
            sortedTab.push_back(tab[i]);
            continue;
        }

        k =i-1;
        while(1)
        {
            if(k==-1)
            {
                sortedTab.insert(sortedTab.begin(),a);
                break;
            }
            else if(sortedTab[k]<a)
            {
                sortedTab.insert(sortedTab.begin()+k+1,a);
                break;
            }
            else k--;
        }
    }

    cout<<"Sorted elements: \n";
    for(int i=0 ; i<n;i++)
    {
        cout<<sortedTab[i]<<" ";

    }
    return 0;

}
