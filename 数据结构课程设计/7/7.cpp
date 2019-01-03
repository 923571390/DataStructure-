#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > wood;
    int N,a;
    cout<<"请输入要将木头锯成的段数："<<endl;
operate1:
    cin >>N;
    if(N<=0){
        cout<<"输入有误，请重新输入："<<endl;
        goto operate1;
    }
    cout<<"请依次输入每一段的长度："<<endl;
    for (int i = 0;i < N;i ++){
operate2:
        cin >> a;
        if(a <=0){
            cout<<"输入有误，请重新输入："<<endl;
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
    cout << "将木头锯成" <<N<< "段的最小花费是" << price << endl;
}

