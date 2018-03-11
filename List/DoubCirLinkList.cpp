#include<iostream>
using namespace std;

template<class DataType>
struct DulNode
{
	DataType data;
	DulNode<DataType> *prior,*next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();                     //
	LinkList(DataType a[], int n);  //
	~LinkList();                    //
	int Length();                   //
	DataType Get(int i);            //
	int Locate(DataType x);         //
	void Insert(int i, DataType x); //
	DataType Delete(int i);         //
	void PrintList();               //
private:
	DulNode<DataType> *first;          //
};

template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new DulNode<DataType>;
	first->next = first;
	first->prior = first;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new DulNode<DataType>;
	first->next = NULL;
	for (int i = 0; i < n; i++)
	{
		DulNode<DataType> *s = new DulNode<DataType>;
		s->data = a[i];
		s->prior = first;
		s->next = first->next;
		first->next->prior = s;
		first->next = s;
	}
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
	while (first->next != first)
	{
		DulNode<DataType>* q = first;
		first->prior->next = first->next;
		first = first->next;
		delete q;
	}
	delete first;
}

template<class DataType>
int LinkList<DataType>::Length()
{
	DulNode<DataType>* p = first->next;
	int count = 0;
	while (p != first)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	DulNode<DataType>* p = first->next;
	int count = 1;
	while (p != first && count<i)
	{
		p = p->next;
		count++;
	}
	if (p == first && count!=1) throw "Location";
	else return p->data;
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	DulNode<DataType> *p = first->next;
	int count = 1;
	while (p != first)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	DulNode<DataType> *p = first;
	int count = 0;
	while (p->next != first && count<i - 1)
	{
		p = p->next;
		count++;
	}
	if (count!=0 && p == first) throw "Location";
	else {
		DulNode<DataType> *s = new DulNode<DataType>;
		s->data = x;
		s->prior = p;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
	}
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	DulNode<DataType> *p = first;
	int count = 0;
	while (p->next != first && count<i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == first && count!=0) throw "Location";
	else {
		DulNode<DataType> *q = p->next;
		int x = q->data;
		q->next->prior = q->prior;
		q->prior->next = q->next;
		return x;
	}
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	DulNode<DataType> *p = first->next;
	while (p != first)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{
	LinkList<int> p;
	p.Insert(1, 6);
	p.Insert(2, 9);
	p.PrintList();
	p.Insert(2, 3);
	p.PrintList();
	cout << p.Get(2) << endl;
	cout << p.Locate(9) << endl;
	cout << p.Length() << endl;
	p.Delete(1);
	p.PrintList();
	return 0;
}

