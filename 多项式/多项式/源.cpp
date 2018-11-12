#include<iostream>
using namespace std;

struct Term
{
	float coef;//多项式的系数

	int exp;//指数
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
	//多项式类
public:
	Polynomial()
{
	first = new Term(0, -1);
}
	Polynomial(Polynomial& R);//复制构造函数
	int maxOrder();//计算最大阶数
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
	//Term的友元函数，输出一个X的内容到输出流Out中
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
	//复制构造函数
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
	//计算最大阶数，当多项式按升序排序时，最后一项中是指数最大者
	Term *current = first;
	while (current->link != NULL) current = current->link;
	return current->exp;
}

istream &operator>> (istream &in, Polynomial& x)
{
	//用尾插法建立一个多项式指针
	Term *rear = x.getHead(); int c, e;
	//rear是尾指针
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
	//输出带附加头节点的多项式链表X
	Term *current = x.getHead()->link;
	cout << "The polynomal is:" << endl;
	bool h = true;
	while (current != NULL)
	{
		if (h = false && current->coef > 0.0)cout << "+";
		h = false;
		out << *current;//调用Term 的重载运算符
		current = current->link;


	}
	out << endl;
	return out;

}

Polynomial operator +(Polynomial& A, Polynomial&B)
{
	Term *pa, *pb, *pc, *p; float temp;
	Polynomial C; pc = C.first;
	//pc为结果多项式创建过程的尾指针
	pa = A.getHead()->link; pb = B.getHead()->link;
	//两链的检测指针
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp == pb->exp)
		{
			//对应指数相等
			temp = pa->coef + pb->coef;
			//对应系数相加


			//相加后系数不为0
			if (fabs(temp) > 0.001) pc = pc->InsertAfter(temp, pa->exp);
			pa = pa->link; pb = pb->link;
		}

		else if (pa->exp < pb->exp)//pa指数小
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
	if (pa != NULL)p = pa;//P指示剩余链的指针
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
	//乘积用附加头节点的单链表存储，返回值指向存储乘积多项式的单链表的头指针
	Term *pa, *pb, *pc; int AL, BL, i, k, maxExp;
	Polynomial C;
	pc = C.getHead();
	AL = A.maxOrder(); BL = B.maxOrder();
	if ((AL != -1) || (BL != -1))//没有0多项式
	{
		maxExp = AL + BL;//结果多项式的最高阶数
		float *result = new float[maxExp + 1];
		for (i = 0; i <= maxExp; i++) result[i] = 0.0;
		pa = A.getHead()->link;
		while (pa != NULL)
		{
			pb = B.getHead()->link;
			while (pb != NULL)
			{
				k = pa->exp + pb->exp;//乘积的指数
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