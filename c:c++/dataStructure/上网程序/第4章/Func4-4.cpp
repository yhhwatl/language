//Func4-4.cpp ���ӵ�I/O����
void VisitRB(RBTNode<T> *c)
{
	cout<<'('<<c->data.key<<", ";
	if(c->RB==Red)
		cout<<"Red"<<')';
	else
		cout<<"Black"<<')';
}

