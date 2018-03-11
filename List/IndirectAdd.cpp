#include<iostream>
using namespace std;

const int MaxSize = 100;

template <class DataType>
class SeqList
{
public:
    typedef struct
    {
        DataType data;
    }Node;
    SeqList(){length=0;}            //
    SeqList(DataType a[],int n);    //
    ~SeqList();                   //
    int Length(){return length;}    //
    DataType Get(int i);            //
    int Locate(DataType x);         //
    void Insert(int i,DataType x);  //
    DataType Delete(int i);         //
    void PrintList();               //
private:
    Node *IndAdd[MaxSize];         //
    int length;                     //
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        Node *p = new Node;
        p->data = a[i];
        IndAdd[i] = p;
    }
    length = n;
}

template <class DataType>
SeqList<DataType>::~SeqList()
{
    for(int i = 0;i<length;i++)
    {
        delete IndAdd[i];
    }
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
    if(i<1 || i>length) throw "Location";
    else{
        return IndAdd[i-1]->data;
    }
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
    for(int i = 0;i<length;i++)
    {
        if(IndAdd[i]->data = x) return i;
    }
    return 0;
}

template <class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
    if(length>=MaxSize) throw "FULL";
    else if(i>length+1 || i<1) throw "Location";
    else{
        for(int j = length;j>=i-1;j--)
        {
            IndAdd[j] = IndAdd[j-1];
        }
        Node *p = new Node;
        p->data = x;
        IndAdd[i-1] = p;
        length++;
    }
}

template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
    Node *p = IndAdd[i-1];
    DataType x = p->data;
    delete p;
    for(int j = i-1;j<length;j++)
    {
        IndAdd[j] = IndAdd[j+1];
    }
    length--;
    return x;
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
    for(int i = 0;i<length;i++)
    {
        Node *p = IndAdd[i];
        cout<<p->data<<" ";
    }
    cout<<endl;
}

int main()
{
    SeqList<int> p;
    p.Insert(1,5);
    p.Insert(2,9);
    p.PrintList();
    p.Insert(2,3);
    cout<<p.Length()<<endl;
    p.PrintList();
    cout<<p.Get(3)<<endl;
    p.Delete(2);
    p.PrintList();
    return 0;
}
