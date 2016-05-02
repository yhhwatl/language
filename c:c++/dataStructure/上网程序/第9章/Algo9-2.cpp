//Algo9-2.cpp ���ϵͳ��
#include "C.h"
#include "DLinkListNH.h"
const int m=5;
const int N=16;
class BuddySystem
{
private:
	struct T
	{
		bool tag;
		int kval;
	};
	struct HeadNode
	{
		int size;
		DLinkListNH<T> first;
	};
	HeadNode FreeList[m+1];
	DLNode<T> *t;
	list<DLNode<T>*> occ;
	DLNode<T>* buddy(DLNode<T>* p)
	{
		if((p-t)%(int)pow(2, p->data.kval+1)==0)
			return p+(int)pow(2, p->data.kval);
		else
			return p-(int)pow(2, p->data.kval);
	}
public:
	BuddySystem()
	{
		int i;
		t=new DLNode<T>[(int)pow(2, m)];
		
		assert(t!=NULL);
		t->data.tag=false;
		t->data.kval=m;
		for(i=0; i<=m; i++)
		{
			FreeList[i].size=(int)pow(2, i);
			FreeList[i].first.Head=NULL;
		}
		FreeList[m].first.ListInsert(1,t);
		cout<<"˫ѭ��������DLNode<T>Ϊ"<<sizeof(DLNode<T>)<<"���ֽ�"<<endl;
		cout<<"m="<<m<<" �洢����ռ�="<<(int)pow(2, m);
		cout<<" ռ�ÿ���������ֵN="<<N<<endl;
		Print();
	}
	~BuddySystem()
	{
		int i;
		delete[]t;
		for(i=0; i<=m; i++)
			FreeList[i].first.Head=NULL;
	}
	bool AllocBuddy(int n)
	{
		int i, k;
		DLNode<T> *pa, *pi;
		for(k=0; k<=m && (FreeList[k].size<n||FreeList[k].first.Head==NULL); ++k);
		
		if(k>m)
			pa=NULL;
		else
		{
			pa=FreeList[k].first.Head;
			FreeList[k].first.ListDelete(pa);
			
			for(i=1; FreeList[k-i].size>=n; ++i)
			{
				pi=pa+(int)pow(2, k-i);
				FreeList[k-i].first.ListInsert(1, pi);
				
				pi->data.tag=false;
				pi->data.kval=k-i;
			}
			pa->data.tag=true;
			pa->data.kval=k-(--i);
		}
		if(pa!=NULL)
		{
			occ.push_back(pa);
			return true;
		}
		else
			return false;
	}
	void Reclaim(int i)
	{
		list<DLNode<T>*>::iterator ip=occ.begin();
		advance(ip, i-1);
		DLNode<T> *s, *p;
		p=*ip;
		occ.erase(ip);
		s=buddy(p);
		while(s>=t && s<t+FreeList[m].size && !s->data.tag && 
		s->data.kval==p->data.kval)
		{
			FreeList[s->data.kval].first.ListDelete(s);
			if((p-t)%(int)pow(2, p->data.kval+1)==0)
				p->data.kval++;
			else
			{
				s->data.kval=p->data.kval+1;
				p=s;
			}
			s=buddy(p);
		}
		p->data.tag=false;
		FreeList[p->data.kval].first.ListInsert(1, p);
		
	}
	void Print()
	{
		int i;
		DLNode<T> *h;
		list<DLNode<T>*>::iterator ip;
		for(i=0; i<=m; i++)
			if(FreeList[i].first.Head!=NULL)
			{
				h=FreeList[i].first.Head;
				do
				{
					cout<<"���п�Ĵ�С="<<(int)pow(2, h->data.kval)<<" ����׵�ַ="<<h;
					cout<<" ���־="<<boolalpha<<h->data.tag<<endl;
					h=h->next;
				}while(h!=FreeList[i].first.Head);
			}
		for(i=1, ip=occ.begin(); ip!=occ.end(); ip++, i++)
		{
			cout<<"��"<<i<<"��ռ�ÿ���׵�ַ="<<*ip<<" ��Ĵ�С=";
			cout<<(int)pow(2, (*ip)->data.kval)<<" ���־="<<(*ip)->data.tag<<endl;
		}
	}
};
void main()
{
	BuddySystem bs;
	int i, j, n;
	bool dis, flag=true;
	while(flag)
	{
		cout<<"��ѡ��������1. ����ռ䣻2. �����ͷſ飻0. �˳�����";
		cin>>j;
		switch(j)
		{
		case 0: 
				flag=false;
				break;
		case 1: 
				cout<<"�����������ռ��Сn����DLNode<T>Ϊ��λ����";
				cin>>n;
				dis=bs.AllocBuddy(n);
				if(dis)
				{
					cout<<"�������"<<n<<"���ռ�󣬴洢�ռ�״��Ϊ"<<endl;
					bs.Print();
				}
				break;
		case 2: 
				cout<<"������Ҫ���յĿ�i��";
				cin>>i;
				bs.Reclaim(i);
				cout<<"���յ�"<<i<<"��ռ�ÿ�󣬴洢�ռ�״��Ϊ"<<endl;
				bs.Print();
		}
	}
}

