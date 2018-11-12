#include<iostream>
using namespace std;

struct Term
{
	float coef;//����ʽ��ϵ��

	int exp;//ָ��
	Term *link;
		Term(float c, int e, Term *next = NULL)
	{
			coef = c; exp = e; link = next;
	}
		Term *InsertAfter(float c, int e);
		friend ostream &operator <<(ostream &, const Term &);
};

class Polynomial
{
	//����ʽ��
public:
	Polynomial()
{
	first = new Term(0, -1);
}
	Polynomial(Polynomial& R);//���ƹ��캯��
	int maxOrder();//����������
	Term *getHead()const { return first; }
private:
	Term *first;
	friend ostream & operator <<(ostream &, const Polynomial &);
	friend istream& operator >>(istream &, Polynomial&);
	friend Polynomial operator +(Polynomial&, Polynomial &);
	friend Polynomial operator *(Polynomial&, Polynomial &);



};

Term *Term::InsertAfter (float c, int e)
{
	link = new Term(c, e, link);
	return link;
}

ostream & operator <<(ostream &out, const Term&x)
{
	//Term����Ԫ���������һ��X�����ݵ������Out��
	if (x.coef == 0.0)return out;
	out << x.coef;
	switch (x.exp)
	{
	case 0:break;
	case 1:out << "X"; break;
	default:out << "X^" << x.exp; break;

	}
	return out;
}


Polynomial::Polynomial(Polynomial&R)
{
	//���ƹ��캯��
	first = new Term(0, -1);
	Term *destptr = first, *srcptr = R.getHead()->link;
	while (srcptr != NULL)
	{
		destptr->InsertAfter(srcptr->coef, srcptr->exp);
		srcptr = srcptr->link;
		destptr = destptr->link;

	}

}

int Polynomial::maxOrder()
{
	//������������������ʽ����������ʱ�����һ������ָ�������
	Term *current = first;
	while (current->link != NULL) current = current->link;
	return current->exp;
}

istream &operator>> (istream &in, Polynomial& x)
{
	//��β�巨����һ������ʽָ��
	Term *rear = x.getHead(); int c, e;
	//rear��βָ��
	while (1)
	{
		cout << "Input a term(coef,exp):" << endl;
		in >> c >> e;
		if (e < 0)break;
		rear = rear->InsertAfter(c, e);
	}
	return in;
}

ostream & operator <<(ostream & out, const Polynomial &x)
{
	//���������ͷ�ڵ�Ķ���ʽ����X
	Term *current = x.getHead()->link;
	cout << "The polynomal is:" << endl;
	bool h = true;
	while (current != NULL)
	{
		if (h = false && current->coef > 0.0)cout << "+";
		h = false;
		out << *current;//����Term �����������
		current = current->link;


	}
	out << endl;
	return out;

}

Polynomial operator +(Polynomial& A, Polynomial&B)
{
	Term *pa, *pb, *pc, *p; float temp;
	Polynomial C; pc = C.first;
	//pcΪ�������ʽ�������̵�βָ��
	pa = A.getHead()->link; pb = B.getHead()->link;
	//�����ļ��ָ��
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp == pb->exp)
		{
			//��Ӧָ�����
			temp = pa->coef + pb->coef;
			//��Ӧϵ�����


			//��Ӻ�ϵ����Ϊ0
			if (fabs(temp) > 0.001) pc = pc->InsertAfter(temp, pa->exp);
			pa = pa->link; pb = pb->link;
		}

		else if (pa->exp < pb->exp)//paָ��С
		{
			pc = pc->InsertAfter(pa->coef, pa->exp);
				pa = pa->link;
		}
		else
		{
			pc = pc->InsertAfter(pb->coef, pb->exp);
			pb = pb->link;

		}
	}
	if (pa != NULL)p = pa;//Pָʾʣ������ָ��
	else p = pb;
	while (p != NULL)
	{
		pc = pc->InsertAfter(p->coef, p->exp);
		p = p->link;
	}
	return C;
}


Polynomial operator *(Polynomial&A, Polynomial&B)
{
	//�˻��ø���ͷ�ڵ�ĵ�����洢������ֵָ��洢�˻�����ʽ�ĵ������ͷָ��
	Term *pa, *pb, *pc; int AL, BL, i, k, maxExp;
	Polynomial C;
	pc = C.getHead();
	AL = A.maxOrder(); BL = B.maxOrder();
	if ((AL != -1) || (BL != -1))//û��0����ʽ
	{
		maxExp = AL + BL;//�������ʽ����߽���
		float *result = new float[maxExp + 1];
		for (i = 0; i <= maxExp; i++) result[i] = 0.0;
		pa = A.getHead()->link;
		while (pa != NULL)
		{
			pb = B.getHead()->link;
			while (pb != NULL)
			{
				k = pa->exp + pb->exp;//�˻���ָ��
				result[k] = result[k] + pa->coef*pb->coef;
				pb = pb->link;
			}
			pa = pa->link;

		}
		for (i = 0; i <= maxExp; i++)
		{
			if (fabs(result[i] > 0.001))
				pc = pc->InsertAfter(result[i], i);
		}
		delete[]result;
	}
	pc->link = NULL;
	return C;

}
int main()
{
	Polynomial A;
	cin >> A;
	Polynomial B;
	cin >> B;
	Polynomial C;
		C= A + B;
	cout << C;
	C = A * B;
	cout << C;

	getchar();
	getchar();
	getchar();
	return 0;

}