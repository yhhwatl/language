//Main3-1.cpp ��֤��HString��ĳ�Ա����
#include "C.h"
#include "HString.h"
void main()
{
	int i;
	char c, *p="God bye!", *q="God luck!";
	HString t, s(p),r("Good luck!");
	cout<<"��sΪ";
	s.StrPrint();
	cout<<"��rΪ";
	r.StrPrint();
	HString u(r);
	cout<<"��uΪ";
	u.StrPrint();
	t.StrAssign(p);
	cout<<"��tΪ";
	t.StrPrint();
	cout<<"t�Ĵ���Ϊ"<<t.StrLength()<<"�����շ�";
	cout<<boolalpha<<t.StrEmpty()<<endl;
	s.StrAssign(q);
	cout<<"��sΪ";
	s.StrPrint();
	i=s.StrCompare(t);
	if(i<0)
		c='<';
	else if(i==0)
		c='=';
	else
		c='>';
	cout<<"��s"<<c<<"��t"<<endl;
	r.Concat(t, s);
	cout<<"��t���Ӵ�s�����Ĵ�rΪ";
	r.StrPrint();
	s.StrAssign("oo");
	cout<<"��sΪ";
	s.StrPrint();
	t.StrAssign("o");
	cout<<"��tΪ";
	t.StrPrint();
	r.Replace(t, s);
	cout<<"�Ѵ�r�кʹ�t��ͬ���Ӵ��ô�s����󣬴�rΪ";
	r.StrPrint();
	s.ClearString();
	cout<<"��s��պ󣬴���Ϊ"<<s.StrLength()<<"�����շ�";
	cout<<boolalpha<<s.StrEmpty()<<endl;
	r.SubString(s, 6, 4);
	cout<<"��sΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ"<<s.StrLength()<<"����sΪ";
	s.StrPrint();
	t.StrCopy(r);
	cout<<"�ɴ�r���Ƶô�t����tΪ";
	t.StrPrint();
	t.StrInsert(6, s);
	cout<<"�ڴ�t�ĵ�6���ַ�ǰ���봮s�󣬴�tΪ";
	t.StrPrint();
	t.StrDelete(1, 5);
	cout<<"�Ӵ�t�ĵ�1���ַ���ɾ��5���ַ��󣬴�tΪ";
	t.StrPrint();
	cout<<t.Index(s, 1)<<"�ǴӴ�t�ĵ�1���ַ��𣬺ʹ�s��ͬ�ĵ�һ���Ӵ���λ��"<<endl;
	cout<<t.Index(s, 2)<<"�ǴӴ�t�ĵ�2���ַ��𣬺ʹ�s��ͬ�ĵ�һ���Ӵ���λ��"<<endl;
}

