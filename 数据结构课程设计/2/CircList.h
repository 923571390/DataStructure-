#ifndef CircList_h
#define CircList_h
using namespace std;
template<class T>
struct LinkNode{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL):link(ptr){}
    LinkNode(T item,LinkNode<T> *ptr = NULL):data(item),link(ptr){}
};
template<class T>
class CircList{
public:
    CircList(const T& x){Head = new LinkNode<T>(x);Tail = Head;Tail->link = Head;}
    CircList(const CircList &copy);
    ~CircList(){makeEmpty();}
    void makeEmpty();
    bool CircListEmpty() const;
    LinkNode<T>* Find(T &item);
    LinkNode<T>* Locate(int pos);
    bool LinkInsert(T item);
private:
    LinkNode<T> *Head,*Tail;
};
template <class T>
void CircList<T>::makeEmpty()
{
    LinkNode<T> *p;
    while (Head->link!=Tail)
    {
        p = Head->link;
        Head->link=p->link;
    }
}
template <class T>
LinkNode<T>* CircList<T>::Find(T &item)
{
    LinkNode<T> *p = Head->link;
    while (p!=Head)
    {
        if (p->data == item)
        {
            break;
        }
        p = p->link;
    }
    return p;
}

template <class T>
LinkNode<T>* CircList<T>::Locate(int pos)
{
    LinkNode<T> *p = Head;

    while (pos>1)
    {
        p = p->link;
        pos--;
    }

    return p;
}
template <class T>
bool CircList<T>::LinkInsert(T item)
{
    LinkNode<T> *node = new LinkNode<T>(item);
    node->link = Head;
    Tail->link = node;
    Tail= node;
    return true;
}

#endif
