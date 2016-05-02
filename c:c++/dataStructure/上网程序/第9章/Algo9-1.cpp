//Algo9-1.cpp �߽��ʶ����
#include "C.h"
#include "DLinkListNH.h"
#define FootLoc(p) p+p->data.size-1
//�������ĺ궨�壬ָ��p��ָ���ĵײ������һ����㣩
const int e=10;
#define uplink prior
class BoundaryLogo
{
private:
	struct T
	{
		bool tag;
		int size;
	};
	DLNode<T> *t;
	int MAX;
	DLinkListNH<T> pav;
	list<DLNode<T>*> occ;
	void Distribute(DLNode<T>* p)
	{
		pav.ListDelete(p);
		p->data.tag=(FootLoc(p))->data.tag=true;
	}
	void DistributePart(DLNode<T>* p, int n)
	{
		DLNode<T> *f=FootLoc(p);
		f->data.tag=true;
		p->data.size-=n;
		f=FootLoc(p);
		f->data.tag=false;
		f->uplink=p;
		f=f+1;
		f->data.tag=true;
		f->data.size=n;
	}
	void InsertByAscend(DLNode<T>* p)
	{
		DLNode<T> *s=pav.Head;
		int i=1;
		while(i<=pav.ListLength() && s->data.size<p->data.size)
		{
			i++;
			s=s->next;
		}
		pav.ListInsert(i, p);
	}
	void AmendDomain(DLNode<T>* p)
	{
		p->data.tag=false;
		(FootLoc(p))->uplink=p;
		(FootLoc(p))->data.tag=false;
	}
	void MergeLeft(DLNode<T>* p, DLNode<T>* &s)
	{
		s=(p-1)->uplink;
		s->data.size+=p->data.size;
		DLNode<T> *f=FootLoc(p);
		f->uplink=s;
		f->data.tag=false;
	}
public:
	BoundaryLogo(int m)
	{
		MAX=m;
		DLNode<T> *p;
		t=new DLNode<T>[MAX+2];
		
		assert(t!=NULL);
		t->data.tag=true;
		
		p=t+1;
		p->data.tag=false;
		p->data.size=MAX;
		pav.ListInsert(1, p);
		p=FootLoc(p);
		p->uplink=pav.Head;
		p->data.tag=false;
		(p+1)->data.tag=true;
		cout<<"˫ѭ��������DLNode<T>Ϊ"<<sizeof(DLNode<T>)<<"���ֽ�"<<endl;
		Print();
	}
	~BoundaryLogo()
	{
		delete[]t;
		pav.Head=NULL;
	}
	bool AllocBoundTag(int i, int n)
	{
	 
		DLNode<T> *p;
		switch(i)
		{
		case 1: 
				for(p=pav.Head; p!=NULL&&p->data.size<n&&p->next!=pav.Head; p=p->next);
				
				if(p==NULL || p->data.size<n)
					p=NULL;
				else
				{
					pav.Head=p->next;
					if(p->data.size-n<e)
						Distribute(p);
					else
					{
						DistributePart(p, n);
						p=p+p->data.size;
					}
				}
				break;
		case 2: 
				for(p=pav.Head; p!=NULL&&p->data.size<n&&p->next!=pav.Head; p=p->next);
				
				if(p==NULL || p->data.size<n)
					p=NULL;
				else
				{
					if(p->data.size-n<e)
						Distribute(p);
					else
					{
						DistributePart(p, n);
						if(p->data.size<p->prior->data.size)
						{
							pav.ListDelete(p);
							InsertByAscend(p);
						}
						p=p+p->data.size;
					}
				}
				break;
		case 3: 
				if(pav.Head==NULL)
					p=NULL;
				else
					p=pav.Head->prior;
				if(p->data.size<n)
					p=NULL;
				else
				{
					if(p->data.size-n<e)
						Distribute(p);
					else
					{
						DistributePart(p, n);
						if(p->data.size<p->prior->data.size)
						{
							pav.ListDelete(p);
							InsertByAscend(p);
						}
						p=p+p->data.size;
					}
				}
				break;
		default:p=NULL;
		}
		if(p!=NULL)
		{
			occ.push_back(p);
			return true;
		}
		else
			return false;
	}
	void Reclaim(int i, int k)
	{
	 
		list<DLNode<T>*>::iterator ip=occ.begin();
		advance(ip, k-1);
		DLNode<T> *p, *s, *f;
		p=*ip;
		occ.erase(ip);
		f=p+p->data.size;
		bool lft=(p-1)->data.tag, r=(p+p->data.size)->data.tag;
		
		switch(i)
		{
		case 1: 
				if(lft && r)
				{
					pav.ListInsert(1, p);
					AmendDomain(p);
				}
				else if(!lft && r)
					MergeLeft(p, s);
					
				else if(lft && !r)
				{
					p->data.tag=false;
					p->prior=f->prior;
					p->prior->next=p;
					p->next=f->next;
					p->next->prior=p;
					p->data.size+=f->data.size;
					(FootLoc(f))->uplink=p;
					if(pav.Head==f)
						pav.Head=p;
				}
				else
				{
					pav.ListDelete(f);
					s=(p-1)->uplink;
					s->data.size+=p->data.size+f->data.size;
					(FootLoc(f))->uplink=s;
				}
				break;
		case 2: 
		case 3: 
				if(lft && r)
				{
					InsertByAscend(p);
					AmendDomain(p);
				}
				else if(!lft && r)
				{
					MergeLeft(p, s);
					
					if(s->data.size>s->next->data.size)
					{
						pav.ListDelete(s);
						InsertByAscend(s);
					}
				}
				else if(lft && !r)
				{
					pav.ListDelete(f);
					p->data.tag=false;
					p->data.size+=f->data.size;
					(FootLoc(f))->uplink=p;
					InsertByAscend(p);
				}
				else
				{
					pav.ListDelete(f);
					s=(p-1)->uplink;
					s->data.size+=p->data.size+f->data.size;
					(FootLoc(f))->uplink=s;
					if(s->data.size>s->next->data.size)
					{
						pav.ListDelete(s);
						InsertByAscend(s);
					}
				}
		}
	}
	void Print()
	{
		DLNode<T> *h, *f;
		list<DLNode<T>*>::iterator ip;
		int i;
		if(pav.Head!=NULL)
		{
			h=pav.Head;
			f=FootLoc(h);
			do
			{
				cout<<"���п�Ĵ�С="<<h->data.size<<" ����׵�ַ="<<f->uplink
				<<" ���־="<<boolalpha<<h->data.tag<<" �ڿ��׵�ַ="<<f+1<<endl;
				h=h->next;
				f=FootLoc(h);
			}while(h!=pav.Head);
		}
		for(i=1, ip=occ.begin(); ip!=occ.end(); ip++, i++)
		{
			cout<<"��"<<i<<"��ռ�ÿ���׵�ַ="<<*ip<<" ��Ĵ�С=";
			cout<<(*ip)->data.size<<" ���־="<<(*ip)->data.tag<<endl;
		}
	}
};
void main()
{
	BoundaryLogo bl(100);
	int n, i, j, k;
	bool dis, flag=true;
	cout<<"��ѡ�������ԣ�1. �״���Ϸ���2. �����Ϸ���3. �����Ϸ�����";
	cin>>i;
	while(flag)
	{
		cout<<"��ѡ��������1. ����ռ䣻2. �����ͷſ飻0. �˳�����";
		cin>>j;
		switch(j)
		{
		case 0: flag=false;
				break;
		case 1: cout<<"�����������ռ��Сn����DLNode<T>Ϊ��λ����";
				cin>>n;
				dis=bl.AllocBoundTag(i, n);
				if(dis)
				{
					cout<<"����"<<n<<"���ռ�󣬴洢�ռ�״��Ϊ"<<endl;
					bl.Print();
				}
				else
					cout<<"����ʧ��"<<endl;
				break;
		case 2: cout<<"������Ҫ���յĿ�k��";
				cin>>k;
				bl.Reclaim(i,k);
				cout<<"���յ�"<<k<<"��ռ�ÿ�󣬴洢�ռ�״��Ϊ"<<endl;
				bl.Print();
		}
	}
}

