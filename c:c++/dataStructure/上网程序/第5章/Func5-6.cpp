//Func5-6.cpp ����һ��AdjListGraph���л��ṹģ��<ArcT>��ʵ��A�������I/O����
struct A
{
	VRType weight;
	string message;
};
void InputArc(bool direct, bool weight, V ver1, V ver2, A &arc)
{
	string s="��";
	if(direct)
		s="��";
	if(weight)
	{
		cout<<"������"<<ver1.name<<s<<ver2.name<<"��Ȩֵ��";
		cin>>arc.weight;
	}
	cout<<"������˻���������Ϣ��";
	getline(cin, arc.message);
	getline(cin, arc.message);
}
void OutputArc(bool direct, bool weight, V ver1, V ver2, A arc)
{
	string s="��";
	if(direct)
		s="��";
	cout<<ver1.name<<s<<ver2.name<<"��(";
	if(weight)
		cout<<arc.weight<<", ";
	cout<<arc.message<<") ";
}
void InputArcFromFile(ifstream &f, A &arc)
{
	getline(f, arc.message, ' ');
	getline(f, arc.message);
}

