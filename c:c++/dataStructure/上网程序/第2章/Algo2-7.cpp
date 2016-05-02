//Algo2-7.cpp �õݹ麯���ͷǵݹ麯�������̤��������
#include "C.h"
#include "SqStack.h"
#include "PosType.h"
#include "PosDirect.h"
class HORSE
{
private:
	int N;
	int **Chessboard;
	int number;
	ofstream fout;
	static PosType HTry[8];
	void HorseByRecursion(PosType Now, int count)
	{
		PosType Next;
		for(int m=0; m<8; m++)
		{
			Next=Now+HTry[m];
			if(Chessboard[Next.x][Next.y]==0)
			{
				Chessboard[Next.x][Next.y]=++count;
				if(count<N*N)
					HorseByRecursion(Next, count);
				else
				{
					++number;
					print();
				}
				Chessboard[Next.x][Next.y]=0;
				count--;
			}
		}
	}
	bool HorseByStack(PosDirect &start)
	{
		int count=1;
		bool flag;
		PosDirect next, now;
		SqStack<PosDirect> S(8);
		S.Push(start);
		Chessboard[start.pos.x][start.pos.y]=1;
		while(!S.StackEmpty())
		{
			S.Pop(now);
			flag=false;
			while(++now.direct<8)
			{
				next.pos=now.pos+HTry[now.direct];
				if(Chessboard[next.pos.x][next.pos.y]==0)
				{
					Chessboard[next.pos.x][next.pos.y]=++count;
					flag=true;
					S.Push(now);
					next.direct=-1;
					S.Push(next);
					if(count==N*N)
					{
						++number;
						print();
						return true;
					}
					break;
				}
			}
			if(!flag)
			{
				--count;
				Chessboard[now.pos.x][now.pos.y]=0;
			}
		}
		return false;
	}
	void print()
	{
		fout<<"��"<<number<<endl;
		for(int k=0; k<N; k++)
		{
			for(int n=0; n<N; n++)
				fout<<setw(3)<<Chessboard[k+2][n+2];
			fout<<endl;
		}
		fout<<endl;
	}
	void print1()
	{
		for(int k=0; k<N+4; k++)
		{
			for(int n=0; n<N+4; n++)
				cout<<setw(3)<<Chessboard[k][n];
			cout<<endl;
		}
	}
public:
	HORSE(int n, PosType Init, int j, char f[])
	{
		N=n;
		number=0;
		Chessboard=new int*[N+4];
		for(int i=0; i<N+4; i++)
		{
			Chessboard[i]=new int[N+4];
			for(int j=0; j<N+4; j++)
				if(i>=2 && i<=N+1 && j>=2 && j<=N+1)
					Chessboard[i][j]=0;
				else
					Chessboard[i][j]=-1;
		}
		cout<<"Chessboard���飺"<<endl;
		print1();
		PosType p={1, 1};
		Init=Init+p;
		fout.open(f, ios::out);
		if(j==0)
		{
			PosDirect First;
			First.direct=-1;
			First.pos=Init;
			fout<<"����ջ����̤���̵�һ���⣺"<<endl;
			HorseByStack(First);
		}
		if(j==1)
		{
			clock_t tstart=clock();
			Chessboard[Init.x][Init.y]=1;
			fout<<"�õݹ鷽������̤���̵����н⣺"<<endl;
			HorseByRecursion(Init, 1);
			double t=(clock()-tstart);
			cout<<"����"<<number<<"���⣬��ʱ"<<t<<"���롣";
		}
		cout<<"�����"<<f<<"��"<<endl;
	}
	~HORSE()
	{
		for(int i=0; i<N+4; i++)
			delete[]Chessboard[i];
		delete[]Chessboard;
		fout.close();
	}
};
PosType HORSE::HTry[8]={{2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, 
{-1, -2}, {1, -2}};
void main()
{
	char FileName[13]="��̤����.txt";
	int i, n=5;
	PosType Init;
	cout<<"�õݹ鷽������̤���̵����н�������1����ջ����̤���̵�һ����������0��";
	cin>>i;
	cout<<"����"<<n<<"��"<<n<<"�����������������ڵ��У�1��"<<n<<"���У�1��"<<n<<"����";
	cin>>Init.x>>Init.y;
	HORSE h(n, Init, i, FileName);
	
}

