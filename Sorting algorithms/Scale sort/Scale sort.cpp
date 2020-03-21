#include<bits/stdc++.h>
using namespace std;
#define N 10000
int tab[N];

vector<int> temp;

void scale(int first,int middle, int last)
{
    int counter1=0,counter2=0;          //counters mark which element we are currently checking from each part
    for(int i=first;i<=last;i++)
    {
        if(middle+1+counter2>last)      //check if we have no more elements from second half to compare
        {
            temp.push_back(tab[first+counter1]);
            counter1++;
            continue;
        }
        if(first+counter1>middle)        //check if we have no more elements from first half to compare
        {
            temp.push_back(tab[middle+1+counter2]);
            counter2++;
            continue;
        }

        if(tab[first+counter1]>tab[middle+1+counter2])  //compare elements from two parts
        {
            temp.push_back(tab[middle+1+counter2]);
            counter2++;
        }
        else
        {
            temp.push_back(tab[first+counter1]);
            counter1++;
        }
    }

    for(int i=first;i<=last;i++)    //move sorted elements from a vector to the array
    {
        tab[i]=temp[i-first];
    }
    while(!temp.empty())temp.pop_back();       //clear temporary vector (where we stored sorted elements)
}


void scaleSort(int first, int last)
{
    if(first == last)return;

    int middle = (first + last)/2;

    scaleSort(first,middle);
    scaleSort(middle+1,last);
    scale(first, middle,last);

}

int main()
{
    int n;
    cin>>n; //number of elements

    for(int i=0; i<n;i++) cin>>tab[i];

    scaleSort(0,n-1);

    cout<<"\n";

    for(int i=0;i<n;i++) cout<<tab[i]<<" ";

    return 0;
}
