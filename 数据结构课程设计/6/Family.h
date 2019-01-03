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
    cout << "���������ȵ�������";
    cin >> ancestor;
    Person *p = new Person;
    p->name = ancestor;
    L.root = p;
    cout << "�˼��׵������ǣ�" << p->name << endl;
}
void Family::Complate(Family &L) {
    string name;
    cout << "������Ҫ������ͥ���˵�������";
    cin>> name;
    Person *s = Family::Find(L.root, name);
    if (s==NULL)  {
        cout << "���޴��ˣ����������룡" << endl;
        Family::Complate(L);
    }
    else{
        int n,m;
        string name;
        cout << "������" << s->name << "�Ķ�Ů������";
        cin >> n;
        m = n;
        cout << "����������" << s->name << "�Ķ�Ů��������";
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
    cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "���޴��ˣ����������룡" << endl;
        Family::Add(L);
    }
    else {
        string name;
        Person *p = s;
        Person *q = new Person;
        cout << "������" << s->name << "����ӵĶ��ӣ���Ů������������" ;
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
    cout << "������Ҫ��ɢ��ͥ���˵�������";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "���޴��ˣ����������룡" << endl;
        Family::Dissolve(L);
    }
    else {
        if (s->lchild==NULL){
            cout << s->name << "��δ��ɼ�ͥ��";
        }
        else {
            cout << "Ҫ��ɢ��ͥ�����ǣ�" << s->name <<endl;
            Family::Print(s);
            s->lchild = NULL;
        }
    }
}
void Family::Rename(Family &L) {
    string rootname;
    cout << "������Ҫ�����������˵�Ŀǰ������";
    cin >> rootname;
    Person *s = Family::Find(L.root, rootname);
    if (s==NULL)  {
        cout << "���޴��ˣ����������룡" << endl;
        Family::Rename(L);
    }
    else {
        string name;
        cout << "��������ĺ��������";
        cin >> name;
        s->name = name;
        cout << rootname << "���Ѹ���Ϊ" << s->name <<endl;
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
    cout << p->name << "�ĵ�һ�������ǣ�" << p->lchild->name <<endl;
    p = p->lchild;
    while (p->rchild) {
        cout << p->rchild->name << endl;
        p = p->rchild;
    }
    cout <<endl;
}
#endif
