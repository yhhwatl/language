//Func6-3.cpp ����ģ��<D>��ʵ��HD����Ӧ��I/O����
struct HD
{
	KeyType key;
	int order;
};
void Visit(int i, HD* c)
{
	cout<<'['<<i<<"]: "<<'('<<c->key<<", "<<c->order<<')'<<endl;
}
void Visit(HD c)
{
	cout<<'('<<c.key<<", "<<c.order<<')';
}
void InputFromFile(ifstream &f, HD &c)
{
	f>>c.key>>c.order;
}
void InputKey(int &k)
{
	cin>>k;
}

