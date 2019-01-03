#include<iostream>
#include<cmath>
using namespace std;
int board[100];
int *p=board;
int num,sum=0;
bool available(int s)
{
    for(int i=0;i<s;i++){
        if(p[s]==p[i]||abs(s-i)==abs(p[s]-p[i])) return false;
    }
    return true;
}
void print(void)
{
    cout<<"第"<<sum+1<<"种方案"<<endl;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(j==p[i]) cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
    }
}
void traceBack(int s)
{
    int i;
    if(s>=num){
        print();
        sum++;
    }
    else{
        for(i=0;i<num;i++){
            p[s]=i;
            if(available(s)) traceBack(s+1);
        }
    }
}
void Queen(void)
{
    traceBack(0);
}
int main()
{
    cout <<"现有NXN的棋盘，放入N个皇后，要求所有皇后不在同一行、列或同一斜线上！"<<endl;
    cout <<"请输入皇后的个数："<<endl;
    cin>>num;
    cout <<"皇后摆法:"<<endl;
    Queen();
    cout <<"共有"<<sum<<"种解法！"<<endl;
}

