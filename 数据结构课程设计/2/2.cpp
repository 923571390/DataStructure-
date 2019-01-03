#include <iostream>
#include "CircList.h"
using namespace std;
void Joseloop(CircList<int> &Js,int &n)
{
    int i;
    for(i=2;i<=n;i++)
    Js.LinkInsert(i);
}
void Josephus(CircList<int> &Js,int d,int m,int s,int n){
    LinkNode<int> *p=Js.Find(s), *pre = NULL;
    int i,j;
    int alive[n];
    for(i=0;i<n;i++){alive[i]=i+1;}
    for(i=0;i<d;i++){
        for(j=0;j<m-1;j++){
            pre=p;
            p=p->link;
        }
        alive[p->data-1]=0;
        cout<<"��"<<i+1<<"�����ߵ�λ��Ϊ:  "<<p->data<<endl;
        pre->link=p->link;
        p=pre->link;
    }
    cout<<"���ʣ��"<<n-d<<"��"<<endl;
    cout<<"ʣ�����ߵ�λ��Ϊ: ";
    for(i=0;i<n;i++){
        if(alive[i]!=0) cout<<alive[i]<<"  ";
    }
};
int main(){
    int n,m,s,k;
    cout<<"����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ�˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ��"<<endl;
operate:
    cout<<endl<<"������������Ϸ��������N�� ";
    cin>>n;
    cout<<endl<<"��������Ϸ��ʼ��λ��S�� ";
    cin>>s;
    cout<<endl<<"��������������M�� ";
    cin>>m;
    cout<<endl<<"������ʣ�����������K�� ";
    cin>>k;
    if((s>n)||(s<=0)||(k>n)||(k<0)){
        cout<<"�������벻����Ҫ�����������룡"<<endl;
        goto operate;
    }
    CircList<int> circle(1);
    Joseloop(circle,n);
    Josephus(circle,n-k,m,s,n);
};

