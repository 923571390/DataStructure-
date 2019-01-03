#ifndef graph_h
#define graph_h
#include<iostream>
#include<stdlib.h>
using namespace std;
class graph
{
public:
    int  Initial[20],end[20],weight[20];
    char name[20];
    int  vertex,edge;
    void matrix();
    void prim();
private:
    int elem[20][20];
    int cost[20];
    int node[20];
};
void graph::matrix()
{
    int i,j,k;
    for(i=0;i<vertex;i++)
        for(j=0;j<vertex;j++)
            elem[i][j]=900;
    for(k=0;k<edge;k++)
    {
        elem[Initial[k]][end[k]]= weight[k];
        elem[end[k]][Initial[k]]= weight[k];
    }
}
void graph::prim()
{
    int i,j,k,min;
    for(i=1;i<vertex;i++)
    {
        cost[i]=elem[0][i];
        node[i]=1;
    }
    node[1]=0;
    j=1;
    for(i=1;i< vertex;i++)
    {
        min=cost[j];
        k=i;
        for(j=1;j< vertex;j++)
            if(cost[j]<min&&node[j]!=0)
            {
                min=cost[j];
                k=j;
            }
        cout<< name[node[k]]<<"-><"<<elem[node[k]][k]<<">->"<< name[k]<<endl;
        node[k]=0;
        for(j=1;j<vertex;j++)
            if( elem[k][j]<cost[j]&&node[j]!=0)
            {
                cost[j]= elem[k][j];
                node[j]=k;
            }
    }
}
#endif
