#include<bits/stdc++.h>
using namespace std;
#define N 1000      //maximum number of vertexes
vector<int> tab[N];
stack<int>stackOfVertexes;
int n, m;       // n - number of vertexes, m - number of edges

void DFS()
{
    int a = stackOfVertexes.top();
    cout<<a<<"\n";

    stackOfVertexes.pop();

    for(int i=0;i<tab[a].size();i++)
    {
        stackOfVertexes.push(tab[a][i]);
    }
    if(!stackOfVertexes.empty())DFS();

}

int main()
{
    int a,b;

    /*-------------INPUT DATA-------------*/

    cout<<"Enter number of vertexes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    cout<<"Enter connections of vertexes: \n";

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        tab[a].push_back(b);
    }

    /*------------------------------------*/

    stackOfVertexes.push(0);
    DFS();


    return 0;
}
