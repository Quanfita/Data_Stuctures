#include<iostream>
using namespace std;

const int MaxSize = 100;

template <class DataType>
class StaticList
{
public:
    typedef struct
    {
        DataType data;
        int next;
    }Node;
    StaticList();                      //
    StaticList(DataType a[],int n);    //
    ~StaticList(){}                    //
    int Length(){return length;}    //
    DataType Get(int i);            //
    int Locate(DataType x);         //
    void Insert(int i,DataType x);  //
    DataType Delete(int i);         //
    void PrintList();               //
private:
    Node SList[MaxSize];         //
    int length;                    //
    int avail;
};

template<class DataType>
StaticList<DataType>::StaticList()
{
    length = 0;
    for(int i = 1;i<MaxSize-1;i++)
    {
        SList[i].next = i+1;
    }
    SList[0].next = -1;
    SList[MaxSize-1].next = -1;
    avail = 1;
}

template<class DataType>
StaticList<DataType>::StaticList(DataType a[],int n)
{
    length = 0;
    avail = 1;
    for(int i = 0;i<MaxSize-1;i++)
    {
        SList[i].next = i+1;
    }
    SList[MaxSize-1].next = -1;
    SList[0].next = avail;
    for(int j = avail;j<=n;j++)
    {
        SList[j].data = a[j-1];
        SList[j].next = j+1;
    }
}

template<class DataType>
DataType StaticList<DataType>::Get(int i)
{
    int m = 0;
    if(i>length || i<1) throw "Location";
    else{
        for(int j = 0;j<i;j++)
        {
            m = SList[m].next;
        }
        return SList[m].data;
    }
}

template<class DataType>
int StaticList<DataType>::Locate(DataType x)
{
    int m = 0;
    for(int i = 0;i<length;i++)
    {
        m = SList[m].next;
        if(SList[m].data == x) return i;
    }
    return 0;
}

template<class DataType>
void StaticList<DataType>::Insert(int i,DataType x)
{
    if(length == MaxSize - 2) throw "Full";
    else if(i<1 || i>length+1) throw "Location";
    else{
        int m = 0;
        for(int j = 0;j<i-1;j++)
        {
            m = SList[m].next;
        }
        int t = avail;
        avail = SList[avail].next;
        int s = SList[m].next;
        SList[m].next = t;
        SList[t].data = x;
        SList[t].next = s;
        length++;
    }
}

template<class DataType>
DataType StaticList<DataType>::Delete(int i)
{
    if(i<1 || i>length) throw "Location";
    else{
        int m = 0;
        for(int j = 0;j<i-1;j++)
        {
            m = SList[m].next;
        }
        DataType temp = SList[SList[m].next].data;
        int t = SList[m].next;
        SList[m].next = SList[SList[m].next].next;
        SList[t].next = avail;
        avail = t;
        length--;
        return temp;
    }
}

template<class DataType>
void StaticList<DataType>::PrintList()
{
    int m = 0;
    for(int i = 0;i<length;i++)
    {
        m = SList[m].next;
        cout<<m<<":";
        cout<<SList[m].data<<" ";
    }
    cout<<endl;
}

int main()
{
    StaticList<int> p;
    p.Insert(1,3);
    p.Insert(2,6);
    p.PrintList();
    p.Insert(2,9);
    p.PrintList();
    cout<<p.Get(2)<<endl;
    cout<<p.Length()<<endl;
    cout<<p.Locate(6)<<endl;
    p.Delete(1);
    p.PrintList();
    return 0;
}
