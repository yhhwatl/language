//HashTable.h ����ַ����ϣ���ࣨHashTable�ࣩ
#ifndef _HAXI_H_
#define _HAXI_H_
const int SUCCESS=1;
const int UNSUCCESS=0;
const int DUPLICATE=-1;
const int N=4;
int hashsize[N]={11, 19, 37, 73};
//��ϣ������������һ�����ʵ��������У����أ�����ϣ���õ�
template<typename D>class HashTable
{
private:
	D *elem;
	int count, length;
	int sizeindex;
	int	*rando;
	int Hash(KeyType Key)
	{
		return Key%length;
	}
	int Hash2(KeyType Key)
	{
		return Key%(length-2);
	}
	void Random()
	{
		bool *ra=new bool[length];
		rando=new int[length];
		int i;
		for(i=1; i<length; i++)
			ra[i]=false;
//		srand(time(0));//�������������
		for(i=1; i<length; i++)
		{
			do
			{
				rando[i]=rand()%(length-1)+1;
				if(!ra[rando[i]])
					ra[rando[i]]=true;
				else
					rando[i]=0;
			}while(rando[i]==0);
			cout<<"rando["<<i<<"]="<<rando[i]<<endl;
		}
		delete[]ra;
	}
	int d(int i, KeyType Key)
	{
		switch(type)
		{
		case 0: return i;
		case 1: return ((i+1)/2)*((i+1)/2)*(int)pow(-1, i-1);
				
		case 2: return i*Hash2(Key);
		case 3: return rando[i];
		default:return i;
		}
	}
	void collision(KeyType Key, int &p, int i)
	{
		p=(Hash(Key)+d(i, Key))%length;
		if(p<0)
			p=p+length;
	}
	void RecreateHashTable()
	{
		int i, len=length;
		D *p=elem;
		sizeindex++;
		if(sizeindex<N)
		{
			length=hashsize[sizeindex];
			elem=new D[length];
			assert(elem!=NULL);
			for(i=0; i<length; i++)
				elem[i].key=EMPTY;
			for(i=0; i<len; i++)
				if(p[i].key!=EMPTY && p[i].key!=TOMB)
					InsertHash(p[i]);
			delete[]p;
			if(type==3)
				Random();
		}
	}
public:
	int type;
	HashTable()
	{
		count=0;
		sizeindex=0;
		length=hashsize[sizeindex];
		elem=new D[length];
		assert(elem!=NULL);
		for(int i=0; i<length; i++)
			elem[i].key=EMPTY;
		cout<<"������̽�鷨�����ͣ�0�����ԣ�1�����Σ�2��˫ɢ�У�3���������";
		cin>>type;
		if(type==3)
			Random();
		else
			rando=NULL;
	}
	~HashTable()
	{
		if(elem!=NULL)
			delete[]elem;
		if(type==3)
			delete[]rando;
	}
	bool SearchHash(KeyType Key, int &p, int &c)
	{
	 
	 
		int c1, tomb=-1;
		p=Hash(Key);
		while(elem[p].key==TOMB || elem[p].key!=EMPTY && !EQ(Key, elem[p].key))
		{
			if(elem[p].key==TOMB && tomb==-1)
			{
				tomb=p;
				c1=c;
			}
			c++;
			if(c<=hashsize[sizeindex]/2)
				collision(Key, p, c);
			else
				break;
		}
		if EQ(Key, elem[p].key)
			return true;
		else
		{
			if(tomb!=-1)
			{
				p=tomb;
				c=c1;
			}
			return false;
		}
	}
	int InsertHash(D e)
	{
	 
		int p, c=0;
		if(SearchHash(e.key, p, c))
			return DUPLICATE;
		else if(c<hashsize[sizeindex]/2)
		{
			elem[p]=e;
			++count;
			return SUCCESS;
		}
		else
		{
			cout<<"����ϣ��ַ��˳������ؽ�ǰ�Ĺ�ϣ��"<<endl;
			TraverseHash(Visit);
			cout<<"�ؽ���ϣ��"<<endl;
			RecreateHashTable();
			return UNSUCCESS;
		}
	}
	bool DeleteHash(KeyType Key, D &e)
	{
	 
		int p, c;
		if(SearchHash(Key, p, c))
		{
			e=elem[p];
			elem[p].key=TOMB;
			--count;
			return true;
		}
		else
			return false;
	}
	D GetElem(int i)const
	{
		return elem[i];
	}
	void TraverseHash(void(*visit)(int, D*))const
	{
		int i;
		cout<<"��ϣ��ַ0��"<<length-1<<endl;
		for(i=0; i<length; i++)
			if(elem[i].key!=EMPTY && elem[i].key!=TOMB)
				visit(i, &elem[i]);
	}
};
#endif

