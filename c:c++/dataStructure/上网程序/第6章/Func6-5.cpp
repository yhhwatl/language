//Func6-5.cpp ����ģ��<D>��ʵ��Ot����Ӧ��I/O����
struct Ot
{
	int order;
};
void Out(Record<Ot> c)
{
	cout<<'('<<c.key.ch<<", "<<c.others.order<<')';
}
void InputFromFile(ifstream &f, Record<Ot> &c)
{
	f>>c.key.ch>>c.others.order;
	c.key.num=strlen(c.key.ch);
}
int j=0;

