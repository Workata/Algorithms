#include<bits/stdc++.h>
using namespace std;
#define N 1000      //maximum number of vertexes

bool visited[N]; //check if vertex was visited
bool tab[N][N]; //Adjacency matrix
int n, m;       // n - number of vertexes, m - number of edges

void DFS(int vertexNumber)
{
    if(visited[vertexNumber] == true) return;

    visited[vertexNumber] = true;   cout<<vertexNumber<<"\n";

    for(int i=0;i<=n;i++)
    {
        if(tab[vertexNumber][i] == true) DFS(i);
    }
}

int main()
{
    int a,b;

    for(int i=0;i<N;i++)
    {
        visited[i] = false;

        for(int j=0;j<N;j++)
        {
            tab[i][j]=false;
        }
    }

    /*-------------INPUT DATA-------------*/

    cout<<"Enter number of vertexes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    cout<<"Enter connections of vertexes: \n";

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        tab[a][b] = true;
    }

    /*------------------------------------*/

    DFS(0); //if vertexes are numbered from 0
    //DFS(1); //if vertex are numbered from 1

    return 0;
}
