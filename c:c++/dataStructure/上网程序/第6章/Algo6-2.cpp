//Algo6-2.cpp ����STL���������ݽ��в��ҵ��㷨
#include "C.h"
#include "Func6-1.cpp"
static long c;
bool cmp(Sc e)
{
	return e.number==c;
}
void main()
{
	int length;
	vector<Sc> a;
	vector<Sc>::iterator ip;
	Sc e;
	ifstream fin("F6-1.txt");
	fin>>length;
	for(int i=0; i<length; i++)
	{
		InputFromFile(fin, e);
		a.push_back(e);
	}
	fin.close();
	cout<<"׼��֤��  ����  ���� ���� ��ѧ ���� �ܷ�"<<endl;
	for(ip=a.begin(); ip!=a.end(); ip++)
	{
		Total(ip);
		Visit(ip);
	}
	cout<<"������������˵Ŀ��ţ�";
	InputKey(c);
	ip=find_if(a.begin(), a.end(), cmp);
	if(ip!=a.end())
		Visit(ip);
}

