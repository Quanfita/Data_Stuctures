#include<iostream>
using namespace std;
const int StackSize = 10;

template<class DataType>
class SeqStack
{
public:
    SeqStack(){top = -1;}
    ~SeqStack(){}
    void Push(DataType x);
    DataType Pop();
    DataType GetTop(){if(top != -1) return data[top];}
    int Empty(){if(top == -1) return 1;else return 0;}
private:
    DataType data[StackSize];
    int top;
};

template <class DataType>
void SeqStack<DataType>::Push(DataType x)
{
    if(top == StackSize-1) throw "Overflow";
    data[++top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop()
{
    if(top == -1) throw "Underflow";
    DataType x = data[top--];
    return x;
}

int main()
{
    SeqStack<int> s;
    s.Push(12);
    s.Push(6);
    cout<<s.Empty()<<endl;
    cout<<s.GetTop()<<endl;
    s.Pop();
    s.Pop();
    cout<<s.Empty()<<endl;
    return 0;
}
