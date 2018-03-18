#include<iostream>
using namespace std;

const int QueueSize = 100;
template<class DataType>
class CirQueue
{
public:
    CirQueue(){front = rear = QueueSize-1;}
    ~CirQueue(){}
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetQueue();
    int Empty(){if(front = rear) return 1;else return 0; }
private:
    DataType data[QueueSize];
    int front,rear;
};

template<class DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
    if((rear+1)%QueueSize == front) throw "Overflow";
    rear = (rear+1)%QueueSize;
    data[rear] = x;
}

template<class DataType>
DataType CirQueue<DataType>::DeQueue()
{
    if(rear == front) throw "Underflow";
    front = (front + 1) % QueueSize;
    return data[front];
}

template<class DataType>
DataType CirQueue<DataType>::GetQueue()
{
    if(rear == front) throw "Underflow";
    int i = (front+1)%QueueSize;
    return data[i];
}

int main()
{
    CirQueue<int> q;
    cout<<q.Empty()<<endl;
    q.EnQueue(3);
    q.EnQueue(9);
    cout<<q.GetQueue()<<endl;
    cout<<q.DeQueue()<<endl;
    cout<<q.DeQueue()<<endl;
    return 0;
}
