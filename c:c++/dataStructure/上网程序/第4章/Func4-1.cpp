//Func4-1.cpp ����Ԫ������Ϊ�������͵�I/O����
void Visit(BiTNode<T> *c)
{
	cout<<c->data<<' ';
}
void InputFromFile(ifstream &f, T &c)
{
	f>>c;
}
void Input(T &c)
{
	cin>>c;
}

