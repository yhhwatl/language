//Func7-1.cpp ����ģ��<D>��ʵ��ID����Ӧ��I/O����
struct ID
{
	KeyType key;
	int order;
};
void Visit(ID* c)
{
	cout<<'('<<c->key<<", "<<c->order<<')';
}
void InputFromFile(ifstream &f, ID &c)
{
	f>>c.key>>c.order;
}

