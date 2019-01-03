#ifndef List_h
#define List_h
using namespace std;
template<class T>
struct LinkNode{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL){link = ptr;}
    LinkNode(const T& item,LinkNode<T> *ptr = NULL)
    {data = item; link = ptr;}
};
template<class T>
class List{
public:
    List(){Head = new LinkNode<T>;}
    List(const List &copy);
    ~List(){makeEmpty();}
    void makeEmpty();
    bool ListEmpty() const;
    int ListLength() const;
    bool GetElem(int pos, T &item);
    bool SetElem(int pos, T &item);
    LinkNode<T>* Locate(int pos);
    bool LinkInsert(T item, int pos);
    bool LinkDelete(T &item,int pos);
private:
    LinkNode<T> *Head;
};
template <class T>
List<T>::List(const List &copy)
{
    LinkNode<T> *p = copy.Head->link;
    Head = new LinkNode<T>;
    LinkNode<T> *h = Head;
    while (p != NULL)
    {
        LinkNode<T> *t = new LinkNode<T>;
        h->link = t;
        t->data = p->data;
        p = p->link;
        h = h->link;
    }
}
template <class T>
void List<T>::makeEmpty()
{
    LinkNode<T> *p = Head;
    LinkNode<T> *t;
    while (p)
    {
        t = p->link;
        delete p;
        p = t;
    }
}
template <class T>
bool List<T>::ListEmpty() const
{
    LinkNode<T> *p = Head->link;
    
    while (p)
    {
        if (p->data == NULL)
        {
            return true;
        }
        p = p->link;
    }
    return false;
}
template <class T>
int List<T>::ListLength() const
{
    LinkNode<T> *p = Head->link;
    int nLink = 0;
    while (p)
    {
        nLink++;
        p = p->link;
    }
    return nLink;
}
template <class T>
bool List<T>::GetElem(int pos, T &item)
{
    LinkNode<T> *p = Locate(pos);
    if (p == NULL)
    {
        return false;
    }
    item = p->data;
    return true;
}
template <class T>
bool List<T>::SetElem(int pos, T &item)
{
    if(pos<=0) return false;
    LinkNode<T> *p = Locate(pos);
    if (p == NULL) return false;
    p->data=item;
    return true;
}
template <class T>
LinkNode<T>* List<T>::Locate(int pos)
{
    LinkNode<T> *p = Head;
    while (pos--)
    {
        p = p->link;
    }
    return p;
}
template <class T>
bool List<T>::LinkInsert(T item, int pos)
{
    using std::cerr;
    using std::endl;
    LinkNode<T> *p = Locate(pos - 1);
    
    if (p == NULL)
    {
        return false;
    }

    LinkNode<T> *node = new LinkNode<T>(item);
    node->link = p->link;
    p->link = node;
    return true;
}
template <class T>
bool List<T>::LinkDelete(T &item, int pos)
{
    LinkNode<T> *p = Locate(pos - 1);
    if (NULL == p || NULL == p->link)
        return false;
    LinkNode<T> *del = p->link;
    p->link = del->link;
    item = del->data;
    delete del;
    return true;
}

#endif
