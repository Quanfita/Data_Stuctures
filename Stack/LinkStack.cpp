#include<iostream>
using namespace std;

template<class DataType>
class LinkStack
{
public:
    typedef struct node
    {
        DataType data;
        node *next;
    }Node;
    LinkStack(){top = NULL;}
    ~LinkStack();
    void Push(DataType x);
    DataType Pop();
    DataType GetTop(){if(top != NULL ) return top->data;}
    int Empty(){if(top == NULL) return 1;else return 0;}
private:
    Node *top;
};

template<class DataType>
LinkStack<DataType>::~LinkStack()
{
    while(top!=NULL){
        Node* p = top;
        top = top->next;
        delete p;
    }
}

template<class DataType>
void LinkStack<DataType>::Push(DataType x)
{
    Node *s = new Node;
    s->next = top;
    s->data = x;
    top = s;
}

template<class DataType>
DataType LinkStack<DataType>::Pop()
{
    if(top == NULL) throw "Underflow";
    DataType x = top->data;
    Node *p = top;
    top = top->next;
    delete p;
    return x;
}

int main()
{
    LinkStack<int> s;
    cout<<s.Empty()<<endl;
    s.Push(3);
    s.Push(8);
    cout<<s.GetTop()<<endl;
    s.Pop();
    cout<<s.GetTop()<<endl;
    return 0;
}
