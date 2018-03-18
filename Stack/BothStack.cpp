#include<iostream>
using namespace std;
const int StackSize = 100;
template<class DataType>
class BothStack
{
public:
    BothStack(){top1 = -1;top2 = StackSize;}
    ~BothStack(){}
    void Push(int i,DataType x);
    DataType Pop(int i);
    DataType GetTop(int i);
    int Empty(int i);
private:
    DataType data[StackSize];
    int top1,top2;
};

template<class DataType>
void BothStack<DataType>::Push(int i,DataType x)
{
    if(top1 == top2-1) throw "Overflow";
    if(i == 1) data[++top1] = x;
    if(i == 2) data[--top2] = x;
}

template<class DataType>
DataType BothStack<DataType>::Pop(int i)
{
    if(i == 1){
        if(top1 == -1) throw "Underflow";
        return data[top1--];
    }
    if(i == 2){
        if(top2 == StackSize) throw "Underflow";
        return data[top2++];
    }
}

template<class DataType>
DataType BothStack<DataType>::GetTop(int i)
{
    if(i == 1) return data[top1];
    if(i == 2) return data[top2];
}

template<class DataType>
int BothStack<DataType>::Empty(int i)
{
    if((i == 1 && top1 == -1) || (i == 2 && top2 == StackSize)) return 1;
    else return 0;
}

int main()
{
    BothStack<int> s;
    cout<<s.Empty(1)<<endl;
    s.Push(1,2);
    s.Push(2,4);
    s.Push(1,5);
    s.Push(2,9);
    cout<<s.GetTop(2)<<endl;
    cout<<s.Pop(1)<<endl;
    return 0;
}
