//Algo2-5.cpp �õݹ麯���ͷǵݹ麯������Թ�����
#include "C.h"
#include "SqStack.h"
#include "PosType.h"
#include "PosDirect.h"
const int MAXLENGTH=10;
class MAZE
{
private:
	int maze[MAXLENGTH][MAXLENGTH];
	int row, col;
	int count;
	PosType begin, end;
	static PosType direc[4];
	void Try(PosType curpos, int curstep)
	{
		PosType nextpos;
		for(int i=0; i<=3; i++)
		{
			nextpos=curpos+direc[i];
			if(maze[nextpos.x][nextpos.y]==-1)
			{
				maze[nextpos.x][nextpos.y]=++curstep;
				if(nextpos==end)
				{
					cout<<"��"<<++count<<endl;
					Print();
				}
				else
					Try(nextpos, curstep);
				maze[nextpos.x][nextpos.y]=-1;
				
				curstep--;
			}
		}
	}
	void Print()const
	{
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
				cout<<setw(3)<<maze[i][j];
			cout<<endl;
		}
	}
public:
	MAZE(char* FileName)
	{
		ifstream fin(FileName);
		fin>>row>>col;
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				fin>>maze[i][j];
		cout<<"�Թ��ṹ���£�"<<endl;
		Print();
		fin>>begin.x>>begin.y;
		fin>>end.x>>end.y;
		cout<<"�Թ�����㣺("<<begin.x<<", "<<begin.y<<')'<<endl;
		cout<<"�Թ����յ㣺("<<end.x<<", "<<end.y<<')'<<endl;
		fin.close();
	}
	bool MazePathByStack()
	{
		SqStack<PosDirect> S(8);
		PosDirect e;
		PosType curpos=begin;
		int curstep=1;
		do
		{
			if(maze[curpos.x][curpos.y]==-1)
			{
				maze[curpos.x][curpos.y]=curstep;
				e.pos=curpos;
				e.direct=0;
				S.Push(e);
				curstep++;
				if(curpos==end)
				{
					cout<<"���Թ�����ڵ����ڵ�һ��·�����£�"<<endl;
					Print();
					return true;
				}
				else
					curpos=curpos+direc[e.direct];
					
			}
			else
				if(!S.StackEmpty())
				{
					S.Pop(e);
					curstep--;
					while(e.direct==3 && !S.StackEmpty())
					{
						maze[e.pos.x][e.pos.y]=-2;
						
						S.Pop(e);
						curstep--;
					}
					if(e.direct<3)
					{
						e.direct++;
						S.Push(e);
						curstep++;
						curpos=e.pos+direc[e.direct];
						
					}
				}
		}while(!S.StackEmpty());
		cout<<"���Թ�û�д���ڵ����ڵ�·��"<<endl;
		return false;
	}
	void MazePathByRecursion()
	{
		maze[begin.x][begin.y]=1;
		count=0;
		Try(begin, 1);
	}
};
PosType MAZE::direc[4]={{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
//�����������ռ�ͳ�ʼ����{������, ������}���ƶ���������Ϊ�϶�����
void main()
{
	int i;
	MAZE M("F2-1.txt");
	cout<<"�õݹ鷽�����Թ������н�������1����ջ���Թ���һ����������0��";
	cin>>i;
	if(i==0)
		M.MazePathByStack();
	else
		M.MazePathByRecursion();
}

