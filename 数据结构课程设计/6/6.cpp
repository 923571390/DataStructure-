#include <iostream>
#include <string>
#include"Family.h"
using namespace std;
int main()
{
    Family L;
    cout<<"**          家谱管理系统          **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**        请选择要执行的操作       **"<<endl;
    cout<<"**         A-----完善家谱        **"<<endl;
    cout<<"**         B-----添加家庭成员     **"<<endl;
    cout<<"**         C-----解散局部家庭     **"<<endl;
    cout<<"**         D-----更改家庭成员姓名  **"<<endl;
    cout<<"**         E-----退出程序        **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"首先建立一个家谱！"<<endl;
    L.Creat(L);
operate:
    cout<<"请选择要执行的操作："<<endl;
    char ch;
    cin>>ch;
    switch(ch) {
        case 'A':
            L.Complate(L);
            break;
        case 'B':
            L.Add(L);
            break;
        case 'C':
            L.Dissolve(L);
            break;
        case 'D':
            L.Rename(L);
            break;
        case 'E':
            break;
        default: cout << "请输入正确的操作！" <<endl;
    }
goto operate;
}

