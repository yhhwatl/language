//Func5-7.cpp ����AGraph���ж���ṹģ��<VerT>��ʵ��V�������I/O����
struct V
{
	string name;
	int ve, vl;
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
void Visitel(V ver)
{
	cout<<setw(5)<<ver.name<<setw(4)<<ver.ve<<setw(4)<<ver.vl;
}

