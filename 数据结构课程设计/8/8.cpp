#include <iostream>
#include "graph.h"
using namespace std;
int main()
{
    graph g;
    cout<<"**          电网造价模拟系统       **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**         请选择要执行的操作      **"<<endl;
    cout<<"**         A-----创建电网顶点     **"<<endl;
    cout<<"**         B-----添加电网的边     **"<<endl;
    cout<<"**         C-----构造最小生成树   **"<<endl;
    cout<<"**         E-----退出程序        **"<<endl;
    cout<<"=================================="<<endl;
operate:
    cout<<"请选择要执行的操作："<<endl;
    char ch;
    cin>>ch;
    switch(ch) {
        case 'A':
            int i,j;
            printf("请输入城市的个数，城市间道路的条数:");
            cin>>i>>j;
            g.vertex=i;
            g.edge=j;
            cout<<"请依次输入各顶点的名称："<<endl;
            for(int i=0;i<g.vertex;i++){cin >> g.name[i];};
            break;
        case 'B':
            int k;
            char s,t;
            for(k=0;k<g.edge;k++){
                cout<<"请输入两个顶点及边："<<endl;
                cin>>s>>t>>g.weight[k];
                for(int i=0;i<g.edge;i++){
                    if(g.name[i] == s) g.Initial[k]=i;
                }
                for(int i=0;i<g.edge;i++){
                    if(g.name[i] == t) g.end[k]=i;
                }
            }
            break;
        case 'C':
            char start;
            cout<<"最小生成树的顶点及边为："<<endl;
            g.matrix();
            g.prim();
            break;
        case 'E':
            break;
        default: cout << "请输入正确的操作！" <<endl;
    }
    goto operate;
}

