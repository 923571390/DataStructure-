#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > wood;
    int N,a;
    cout<<"������Ҫ��ľͷ��ɵĶ�����"<<endl;
operate1:
    cin >>N;
    if(N<=0){
        cout<<"�����������������룺"<<endl;
        goto operate1;
    }
    cout<<"����������ÿһ�εĳ��ȣ�"<<endl;
    for (int i = 0;i < N;i ++){
operate2:
        cin >> a;
        if(a <=0){
            cout<<"�����������������룺"<<endl;
            goto operate2;
        }
        else wood.push(a);
    }
    int price=0;
    while(wood.size()!=1){
        int x=wood.top();
        wood.pop();
        int y=wood.top();
        wood.pop();
        price+=x+y;
        wood.push(x+y);
    }
    cout << "��ľͷ���" <<N<< "�ε���С������" << price << endl;
}

