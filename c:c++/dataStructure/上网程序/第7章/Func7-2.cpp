//Func7-2.cpp ����ģ��<D>��ʵ��SL����Ӧ��I/O����
struct SL
{
	struct
	{
		int key;
		int order;
	}rc;
	int next;
};
void Visit(SL* c)
{
	cout<<'('<<c->rc.key<<", "<<c->rc.order<<')';
}
void Visitn(SL* c)
{
	cout<<'('<<c->rc.key<<", "<<c->rc.order<<", "<<c->next<<')';
}
void InputFromFile(ifstream &f, SL &c)
{
	f>>c.rc.key>>c.rc.order;
}

