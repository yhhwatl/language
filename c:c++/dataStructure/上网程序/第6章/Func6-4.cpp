//Func6-4.cpp ����ģ��<D>��ʵ��Ot����Ӧ��I/O����
struct Ot
{
	int order;
};
void Visit(Record<Ot> c)
{
	cout<<'('<<c.key<<", "<<c.others.order<<')';
}
void InputFromFile(ifstream &f, Record<Ot> &c)
{
	f>>c.key>>c.others.order;
}
void InputKey(KeyType &k)
{
	cin>>k;
}

