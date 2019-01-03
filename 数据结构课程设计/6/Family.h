#ifndef Family_h
#define Family_h
#include <iostream>
using namespace std;
class Person {
    friend class Family;
public:
    Person() { name = '?'; lchild = NULL; rchild = NULL; }
private:
    string name;
    Person *lchild;
    Person *rchild;
};
class Family {
public:
    Family() { root = NULL; }
    void Creat(Family &L);
    void Complate(Family &L);
    void Add(Family &L);
    void Dissolve(Family &L);
    void Rename(Family &L);
private:
    Person *root;
    void Print(Person *p);
    Person * Find(Person *p, string name);
};
void Family::Creat(Family &L) {
    string ancestor;
    cout << "请输入祖先的姓名：";
    cin >> ancestor;
    Person *p = new Person;
    p->name = ancestor;
    L.root = p;
    cout << "此家谱的祖先是：" << p->name << endl;
}
void Family::Complate(Family &L) {
    string name;
    cout << "请输入要建立家庭的人的姓名：";
    cin>> name;
    Person *s = Family::Find(L.root, name);
    if (s==NULL)  {
        cout << "查无此人，请重新输入！" << endl;
        Family::Complate(L);
    }
    else{
        int n,m;
        string name;
        cout << "请输入" << s->name << "的儿女人数：";
        cin >> n;
        m = n;
        cout << "请依次输入" << s->name << "的儿女的姓名：";
        Person *p = s;
        while (m>0) {
            Person *q = new Person;
            cin >> name;
            q->name = name;
            if (m == n) {
                s->lchild = q;
                s = s->lchild;
            }
            else {
                s->rchild = q;
                s = s->rchild;
            }
            m--;
        }
        Family::Print(p);
    }
}
void Family::Add(Family &L) {
    string rootname;
    cout << "请输入要添加儿子（或女儿）的人的姓名：";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "查无此人，请重新输入！" << endl;
        Family::Add(L);
    }
    else {
        string name;
        Person *p = s;
        Person *q = new Person;
        cout << "请输入" << s->name << "新添加的儿子（或女儿）的姓名：" ;
        cin >> name;
        q->name = name;
        if (s->lchild==NULL) { s->lchild = q; }
        else {
            s = s->lchild;
            while (s->rchild!=NULL) { s = s->rchild; }
            s->rchild = q;
        }
        Family::Print(p);
    }
}
void Family::Dissolve(Family &L) {
    string rootname;
    cout << "请输入要解散家庭的人的姓名：";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "查无此人，请重新输入！" << endl;
        Family::Dissolve(L);
    }
    else {
        if (s->lchild==NULL){
            cout << s->name << "尚未组成家庭！";
        }
        else {
            cout << "要解散家庭的人是：" << s->name <<endl;
            Family::Print(s);
            s->lchild = NULL;
        }
    }
}
void Family::Rename(Family &L) {
    string rootname;
    cout << "请输入要更改姓名的人的目前姓名：";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "查无此人，请重新输入！" << endl;
        Family::Rename(L);
    }
    else {
        string name;
        cout << "请输入更改后的姓名：";
        cin >> name;
        s->name = name;
        cout << rootname << "现已更名为" << s->name <<endl;
    }
}
Person * Family::Find(Person *p, string name) {
    Person *q = NULL;
    Person *s[100];
    int top = 0;
    while (p !=NULL|| top > 0) {
        while (p !=NULL) {
            if (p->name == name) { q = p; }
            s[++ top] = p;
            p = p->lchild;
        }
        p = s[top --];
        p = p->rchild;
    }
    return q;
}
void Family::Print(Person *p) {
    cout << p->name << "的第一代子孙是：" << p->lchild->name <<endl;
    p = p->lchild;
    while (p->rchild) {
        cout << p->rchild->name << endl;
        p = p->rchild;
    }
    cout <<endl;
}
#endif
