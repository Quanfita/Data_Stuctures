#include<iostream>
using namespace std;

template<class DataType>
class LinkQueue
{
public:
    typedef struct node
    {
        DataType data;
        node *next;
    }Node;
    LinkQueue();
    ~LinkQueue();
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetQueue();
    int Empty(){if(front == rear) return 1;else return 0; }
private:
    Node *front,*rear;
};

template<class DataType>
LinkQueue<DataType>::LinkQueue()
{
    Node *s = new Node;
    s->next = NULL;
    front = rear = s;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue()
{
    while(front->next != NULL)
    {
        Node *s = front->next;
        front->next = s->next;
        delete s;
    }
}

template<class DataType>
void LinkQueue<DataType>::EnQueue(DataType x)
{
    Node *s = new Node;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
    if(rear == front) throw "Underflow";
    Node *p = front->next;
    DataType x = p->data;
    front->next = p->next;
    if(p->next = NULL) rear = front;
    delete p;
    return x;
}

template<class DataType>
DataType LinkQueue<DataType>::GetQueue()
{
    DataType x = front->next->data;
    return x;
}

int main()
{
    LinkQueue<int> q;
    cout<<q.Empty()<<endl;
    q.EnQueue(2);
    q.EnQueue(4);
    q.EnQueue(9);
    cout<<q.GetQueue()<<endl;
    cout<<q.DeQueue()<<endl;
    cout<<q.DeQueue()<<endl;
    return 0;
}
