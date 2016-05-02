//Algo3-2.cpp ����ʵ��BM�㷨�ĳ���
#include "C.h"
#include "HString.h"
const int N=256;
class BMMatching
{
private:
	HString Main, Sub;
	bitset<N> bit;
	void MakeBitSet()
	{
		int i;
		for(i=0; i<Sub.length; i++)
			bit[(unsigned char)Sub.ch[i]]=1;
	}
	int last(char c)
	{
		if(bit[(unsigned char)c]==0)
			return -1;
		else
			for(int i=Sub.length-1; i>=0; i--)
				if(c==Sub.ch[i])
					return i;
	}
public:
	BMMatching(const char* strM="", const char* strS="")
	{
		Main.StrAssign(strM);
		Sub.StrAssign(strS);
		MakeBitSet();
	}
	int BMMatch()
	{
		int m, n, i, j;
		cout<<"����Ϊ";
		Main.StrPrint();
		cout<<"ģʽ��Ϊ";
		Sub.StrPrint();
		m=Sub.length;
		n=Main.length;
		j=m-1;
		i=m-1;
		do
		{
			if(Sub.ch[j]==Main.ch[i])
				if(j==0)
					return i+1;
				else
					i--, j--;
			else
			{
				i=i+m-__min(j, 1+last(Main.ch[i]));
				j=m-1;
			}
		}while(i<n);
		return 0;
	}
};
void main()
{
	BMMatching M1("The atom bomb is in this room.", "room");
	BMMatching M2("�㷨�����ݽṹ", "����");
	int i;
	i=M1.BMMatch();
	if(i)
		cout<<"������ģʽ���ڵ�"<<i<<"���ַ����״�ƥ��"<<endl;
	else
		cout<<"������ģʽ��ƥ�䲻�ɹ�"<<endl;
	i=M2.BMMatch();
	if(i)
		cout<<"������ģʽ���ڵ�"<<i<<"���ַ����״�ƥ��"<<endl;
	else
		cout<<"������ģʽ��ƥ�䲻�ɹ�"<<endl;
}

