//Func5-1.cpp ����AGraph���ж���ṹģ��<VerT>��ʵ��V�������I/O����
struct V
{
	string name;
};
void Visit(V ver)
{
	cout<<ver.name<<' ';
}
void InputVertex(V &ver)
{
	cin>>ver.name;
}
void InputVertexFromFile(ifstream &f, V &ver)
{
	f>>ver.name;
}
void InputVertexNameFromFile(ifstream &f, V &ver)
{
	f>>ver.name;
}

