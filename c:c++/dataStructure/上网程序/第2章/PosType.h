//PosType.h ��ά����λ�����ͽṹ�弰���ص������
#ifndef _POSTYPE_H_
#define _POSTYPE_H_
struct PosType
{
	int x, y;
};
PosType operator+(const PosType p1, const PosType p2)
{
	PosType p;
	p.x=p1.x+p2.x;
	p.y=p1.y+p2.y;
	return p;
}
bool operator==(const PosType p1, const PosType p2)
{
	return p1.x==p2.x && p1.y==p2.y;
}
#endif

