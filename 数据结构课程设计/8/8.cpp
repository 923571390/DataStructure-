#include <iostream>
#include "graph.h"
using namespace std;
int main()
{
    graph g;
    cout<<"**          �������ģ��ϵͳ       **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**         ��ѡ��Ҫִ�еĲ���      **"<<endl;
    cout<<"**         A-----������������     **"<<endl;
    cout<<"**         B-----��ӵ����ı�     **"<<endl;
    cout<<"**         C-----������С������   **"<<endl;
    cout<<"**         E-----�˳�����        **"<<endl;
    cout<<"=================================="<<endl;
operate:
    cout<<"��ѡ��Ҫִ�еĲ�����"<<endl;
    char ch;
    cin>>ch;
    switch(ch) {
        case 'A':
            int i,j;
            printf("��������еĸ��������м��·������:");
            cin>>i>>j;
            g.vertex=i;
            g.edge=j;
            cout<<"�������������������ƣ�"<<endl;
            for(int i=0;i<g.vertex;i++){cin >> g.name[i];};
            break;
        case 'B':
            int k;
            char s,t;
            for(k=0;k<g.edge;k++){
                cout<<"�������������㼰�ߣ�"<<endl;
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
            cout<<"��С�������Ķ��㼰��Ϊ��"<<endl;
            g.matrix();
            g.prim();
            break;
        case 'E':
            break;
        default: cout << "��������ȷ�Ĳ�����" <<endl;
    }
    goto operate;
}

