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
    cout<<"��"<<sum+1<<"�ַ���"<<endl;
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
    cout <<"����NXN�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��л�ͬһб���ϣ�"<<endl;
    cout <<"������ʺ�ĸ�����"<<endl;
    cin>>num;
    cout <<"�ʺ�ڷ�:"<<endl;
    Queen();
    cout <<"����"<<sum<<"�ֽⷨ��"<<endl;
}

