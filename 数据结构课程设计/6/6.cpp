#include <iostream>
#include <string>
#include"Family.h"
using namespace std;
int main()
{
    Family L;
    cout<<"**          ���׹���ϵͳ          **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**        ��ѡ��Ҫִ�еĲ���       **"<<endl;
    cout<<"**         A-----���Ƽ���        **"<<endl;
    cout<<"**         B-----��Ӽ�ͥ��Ա     **"<<endl;
    cout<<"**         C-----��ɢ�ֲ���ͥ     **"<<endl;
    cout<<"**         D-----���ļ�ͥ��Ա����  **"<<endl;
    cout<<"**         E-----�˳�����        **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"���Ƚ���һ�����ף�"<<endl;
    L.Creat(L);
operate:
    cout<<"��ѡ��Ҫִ�еĲ�����"<<endl;
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
        default: cout << "��������ȷ�Ĳ�����" <<endl;
    }
goto operate;
}

