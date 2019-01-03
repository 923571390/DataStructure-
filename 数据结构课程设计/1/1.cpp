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
        cout<<"查无此人，请重新输入："<<endl;
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
            cout<<"请输入你要插入的考生的位置:"<<endl;
            cin>>op;
            while((op>j.ListLength()+1)||op<1){
                cout<<"插入位置无效，请重新输入:"<<endl;
                cin>>op;
            }
            cout<<"请依次输入要插入考生的考号、姓名、性别、年龄以及报考类别）:"<<endl;
            Stu s;
            cin>>s.num>>s.name>>s.gender>>s.age>>s.type;
            j.LinkInsert(s, op);
            j.GetElem(op,x);
            cout<<"你插入的考生的信息是:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 2:
            cout<<"请输入你要删除的考生的考号:"<<endl;
            findnum(j,x,op);
            j.LinkDelete(x,op);
            cout<<"你删除的考生的信息是:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 3:
            cout<<"请输入你要搜索的考生的考号:"<<endl;
            findnum(j,x,op);
            cout<<"你搜索的考生的信息是:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 4:
            cout<<"请输入你要修改的考生的考号:"<<endl;
            findnum(j,x,op);
            cout<<"考生目前的信息是:"<<endl;
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            cout<<"请依次输入修改后考生的考号、姓名、性别、年龄以及报考类别:"<<endl;
            Stu t;
            cin>>t.num>>t.name>>t.gender>>t.age>>t.type;
            findpos(j,op);
            j.SetElem(op,t);
            cout<<"经过修改后该考生的信息是:"<<endl;
            j.GetElem(op,x);
            cout<<x.num<<" "<<x.name<<" "<<x.gender<<" "<<x.age<<" "<<x.type<<endl;
            break;
        case 5:
            cout<<"目前，考试报名系统中共有"<<j.ListLength()<<"位考生的信息"<<endl;
            cout<<"统计结果如下:"<<endl;
            print(j.ListLength(),j);
            break;
        case 6:
            cout<<"操作已经取消！"<<endl;
            break;
        default:
            cout<<"您输入的编码有误！"<<endl;
    }
}
int main(){
    int menu;
    int people;
    int i;
    cout<<"首先请建立考生信息系统:"<<endl;
    cout<<"请输入考生人数:"<<endl;
    cin>>people;
    while(people<=0){
        cout<<"至少要有一名考生，请重新输入考生人数:"<<endl;
        cin>>people;
    }
    List<Stu> Student;
    cout<<"请依次输入考生的考号、姓名、性别、年龄以及报考类别:"<<endl;
    for(i=1;i<=people;i++){
        Stu s;
        cin>>s.num>>s.name>>s.gender>>s.age>>s.type;
        Student.LinkInsert(s, i);
    }
    print(people,Student);
operate:
    cout<<"请输入您要操作的选项(1为插入，2为删除，3为查找，4为修改，5为统计，6为取消操作）:"<<endl;
    cin>>menu;
    operate(menu,Student);
    goto operate;
}

