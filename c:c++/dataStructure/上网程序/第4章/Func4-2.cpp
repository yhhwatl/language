//Func4-2.cpp ��������Ԫ�����ͺ͹ؼ������ͼ������ǵ�I/O����
typedef int KeyType;
struct T
{
	KeyType key;
	int others;
};
void Visit(BiTNode<T> *c)
{
	cout<<'('<<c->data.key<<", "<<c->data.others<<')';
}
void InputFromFile(ifstream &f, T &c)
{
	f>>c.key>>c.others;
}
void InputKey(KeyType &k)
{
	cin>>k;
}

