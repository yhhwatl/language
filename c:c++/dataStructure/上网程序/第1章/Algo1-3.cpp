//Algo1-3.cpp ��STL��ʹ���Զ�����������
#include "C.h"
struct Student
{
	string name;
	int score;
};
bool cmp(Student a, Student b)
{
	return a.score<=b.score;
}
void main()
{
	vector<Student> a;
	vector<Student>::iterator ip;
	ifstream fin("F1-1.txt");
	Student e;
	while(!fin.eof())
	{
		fin>>e.name>>e.score;
		a.push_back(e);
	}
	fin.close();
	for(ip=a.begin(); ip!=a.end(); ip++)
		cout<<ip->name<<' '<<ip->score<<endl;
	ip=a.begin()+2;
	e.name="��Ӣ��";
	e.score=93;
	a.insert(ip, e);
	a.erase(a.begin()+4);
	cout<<"����ɾ����"<<endl;
	for(ip=a.begin(); ip!=a.end(); ip++)
		cout<<ip->name<<' '<<ip->score<<endl;
	cout<<"a.front()="<<a.front().name<<' '<<a.front().score<<endl;
	sort(a.begin(), a.end(), cmp);
	cout<<"���������������"<<endl;
	for(ip=a.begin(); ip!=a.end(); ip++)
		cout<<ip->name<<' '<<ip->score<<endl;
}

