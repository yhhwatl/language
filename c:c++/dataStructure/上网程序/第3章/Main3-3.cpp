//Main3-3.cpp ��֤ϡ�����RLSMatrix��ĳ�Ա����
#include "C.h"
#include "RLSMatrix.h"
void main()
{
	bool f;
	RLSMatrix<int> A("F3-2.txt"), B, C;
	
	cout<<"����A="<<endl;
	A.PrintSMatrix();
	f=B.CreateSMatrixFromFile();
	if(f)
	{
		cout<<"����B="<<endl;
		B.PrintSMatrix();
	}
	C.CopySMatrix(A);
	cout<<"�ɾ���A���Ƶľ���C="<<endl;
	C.PrintSMatrix();
	f=C.CreateSMatrixFromFile("F3-3.txt");
	if(f)
	{
		cout<<"���ļ�F3-3.txt��������C="<<endl;
		C.PrintSMatrix();
	}
	f=B.AddSMatrix(A, C);
	if(f)
	{
		cout<<"����B1=A+C="<<endl;
		B.PrintSMatrix();
	}
	f=C.SubtSMatrix(B, A);
	if(f)
	{
		cout<<"����C1=B-A="<<endl;
		C.PrintSMatrix();
	}
	A.TransposeSMatrix(C);
	cout<<"����A1=C��ת��"<<endl;
	A.PrintSMatrix();
	f=B.MultSMatrix(C, A);
	if(f)
	{
		cout<<"����B2=C��A="<<endl;
		B.PrintSMatrix();
	}
}

