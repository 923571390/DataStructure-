#include <iostream>
#include"Bsorttree.h"
using namespace std;
int main()
{
    Bsorttree B;
    cout<<"**          ����������            **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**         ��ѡ��Ҫִ�еĲ���      **"<<endl;
    cout<<"**         1-----��������������   **"<<endl;
    cout<<"**         2-----����Ԫ��        **"<<endl;
    cout<<"**         3-----��ѯԪ��        **"<<endl;
    cout<<"**         4-----�˳�����        **"<<endl;
    cout<<"=================================="<<endl;
operate:
    cout<<"Please select��"<<endl;
    char ch;
    int b;
    cin>>ch;
    switch(ch) {
        case '1':
            int N;
            cout << "Please input the number of your keys:" <<endl;
            cin>>N;
            int a[20];
            cout << "Please input key to create Bsort_tree:" <<endl;
            for(int i=0; i<N; i++){
                cin>>a[i];
            }
            B.create(a,N);
            B.print();
            break;
        case '2':
            cout << "Please input key which inserted:" <<endl;
            cin >> b;
            B.insert(b);
            B.print();
            break;
        case '3':
            cout << "Please input key which searched:" <<endl;
            cin >> b;
            B.search(b);
            break;
        case '4':
            break;
        default:
            cout << "Please select a right operation!" <<endl;
    }
    goto operate;
}

