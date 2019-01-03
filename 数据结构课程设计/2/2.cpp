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
        cout<<"第"<<i+1<<"个死者的位置为:  "<<p->data<<endl;
        pre->link=p->link;
        p=pre->link;
    }
    cout<<"最后剩下"<<n-d<<"人"<<endl;
    cout<<"剩余生者的位置为: ";
    for(i=0;i<n;i++){
        if(alive[i]!=0) cout<<alive[i]<<"  ";
    }
};
int main(){
    int n,m,s,k;
    cout<<"现有N人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一人开始报数，如此循环，直到剩下K个人为止。"<<endl;
operate:
    cout<<endl<<"请输入生死游戏的总人数N： ";
    cin>>n;
    cout<<endl<<"请输入游戏开始的位置S： ";
    cin>>s;
    cout<<endl<<"请输入死亡数字M： ";
    cin>>m;
    cout<<endl<<"请输入剩余的生者人数K： ";
    cin>>k;
    if((s>n)||(s<=0)||(k>n)||(k<0)){
        cout<<"您的输入不符合要求，请重新输入！"<<endl;
        goto operate;
    }
    CircList<int> circle(1);
    Joseloop(circle,n);
    Josephus(circle,n-k,m,s,n);
};

