#ifndef Stack_h
#define Stack_h
#include <iostream>
using namespace std;
struct Point
{
    int x;
    int y;
    bool acessible;
    int tab;
    Point *next;
    Point(int rx = 0, int ry = 0, bool racessible = false,int rtab=0)
    {
        x = rx;
        y = ry;
        acessible = racessible;
        tab = rtab;
        next = NULL;
    }
};
class Stack
{
public:
    Stack();
    int push(Point point);
    Point pop();
    int getLength(){
        return length;
    }
    Point getTop(){
        return *top;
    }
    void printStack();
private:
    Point *base;
    Point *top;
    int length;
};
Stack::Stack()
{
    length = 0;
    base = NULL;
    top = NULL;
}
int Stack::push(Point point)
{
    Point *p = new Point();
    *p = point;
    if (length == 0)
        top = base = p;
    else
    {
        top->next = p;
        top = p;
    }
    return ++length;
}
Point Stack::pop()
{
    if (length <= 0)
        return NULL;
    Point retPoint = *top;
    top = base;
    while (top->next != NULL)
    {
        if (top->next->next == NULL)
        {
            delete(top->next);
            top->next = NULL;
            break;
        }
        top = top->next;
    }
    if (length == 1)
    {
        delete(base);
        base = top = NULL;
    }
    length--;
    return retPoint;
}
void Stack::printStack()
{
    Point *p = base;
    while (p != top)
    {
        cout << "(" << p->x << "," << p->y << ")" << "--->";
        p = p->next;
    }
    cout << "(" << p->x << "," << p->y << ")" << endl;
}
#endif
