#include <iostream>
#include<stdlib.h>
#include"List.h"
using namespace std;
struct Stu
{
    int num;
    char name[20];
    char gender[20];
    int age;
    char type[20];
};
void print(int num,List<Stu> j){
    int i;
    for(i=1;i<=num;i++){
        Stu x;
        j.GetElem(i,x);
        cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
    }
}
void findnum(List<Stu>&j,Stu &s,int &num){
    cin>>num;
    int i;
    Stu t;
    for(i=0;i<=j.ListLength();){
        j.GetElem(i,t);
        if(t.num==num){
            s=t;
            break;
        }
        i++;
    }
    if(i==(j.ListLength()+1)){
        cout<<"���޴��ˣ����������룺"<<endl;
        findnum(j,s,num);
    }
}
void findpos(List<Stu>j,int &num){
    int i;
    Stu t;
    int pos;
    for(i=0;i<=j.ListLength();){
        j.GetElem(i,t);
        if(t.num==num){
            pos=i;
            break;
        }
        i++;
    }
    num=pos;
}
void operate(int &i,List<Stu> &j){
    int op;
    Stu x;
    switch (i) {
        case 1:
            cout<<"��������Ҫ����Ŀ�����λ��:"<<endl;
            cin>>op;
            while((op>j.ListLength()+1)||op<1){
                cout<<"����λ����Ч������������:"<<endl;
                cin>>op;
            }
            cout<<"����������Ҫ���뿼���Ŀ��š��������Ա������Լ��������:"<<endl;
            Stu s;
            cin>>s.num>>s.name>>s.gender>>s.age>>s.type;
            j.LinkInsert(s, op);
            j.GetElem(op,x);
            cout<<"�����Ŀ�������Ϣ��:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 2:
            cout<<"��������Ҫɾ���Ŀ����Ŀ���:"<<endl;
            findnum(j,x,op);
            j.LinkDelete(x,op);
            cout<<"��ɾ���Ŀ�������Ϣ��:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 3:
            cout<<"��������Ҫ�����Ŀ����Ŀ���:"<<endl;
            findnum(j,x,op);
            cout<<"�������Ŀ�������Ϣ��:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 4:
            cout<<"��������Ҫ�޸ĵĿ����Ŀ���:"<<endl;
            findnum(j,x,op);
            cout<<"����Ŀǰ����Ϣ��:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            cout<<"�����������޸ĺ����Ŀ��š��������Ա������Լ��������:"<<endl;
            Stu t;
            cin>>t.num>>t.name>>t.gender>>t.age>>t.type;
            findpos(j,op);
            j.SetElem(op,t);
            cout<<"�����޸ĺ�ÿ�������Ϣ��:"<<endl;
            j.GetElem(op,x);
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 5:
            cout<<"Ŀǰ�����Ա���ϵͳ�й���"<<j.ListLength()<<"λ��������Ϣ"<<endl;
            cout<<"ͳ�ƽ������:"<<endl;
            print(j.ListLength(),j);
            break;
        case 6:
            cout<<"�����Ѿ�ȡ����"<<endl;
            break;
        default:
            cout<<"������ı�������"<<endl;
    }
}
int main(){
    int menu;
    int people;
    int i;
    cout<<"�����뽨��������Ϣϵͳ:"<<endl;
    cout<<"�����뿼������:"<<endl;
    cin>>people;
    while(people<=0){
        cout<<"����Ҫ��һ�����������������뿼������:"<<endl;
        cin>>people;
    }
    List<Stu> Student;
    cout<<"���������뿼���Ŀ��š��������Ա������Լ��������:"<<endl;
    for(i=1;i<=people;i++){
        Stu s;
        cin>>s.num>>s.name>>s.gender>>s.age>>s.type;
        Student.LinkInsert(s, i);
    }
    print(people,Student);
operate:
    cout<<"��������Ҫ������ѡ��(1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�6Ϊȡ��������:"<<endl;
    cin>>menu;
    operate(menu,Student);
    goto operate;
}

