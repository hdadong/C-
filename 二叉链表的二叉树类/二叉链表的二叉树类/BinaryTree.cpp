#include"BinaryTree.h"
#include<stack>

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current)
{
	//˽�к������ӽ��subTree��ʼ�������ڵ�current�ĸ��ڵ�,���ҵ��ڵ�current�ĸ��ڵ�
	//�򷵻ظ��ڵ�ĵ�ַ������������NULL
	if (subTree == NULL)return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;//�ҵ������ظ��ڵ�subTree
	BinTreeNode<T>*p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)return p;//�ݹ�������������Ѱ
	else return Parent(subTree->rightChild, current);//�ݹ�������������Ѱ

}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>*subTree, ostream&out)
{
	//˽�к����������������Ϊsubtree�Ķ�����
	if (subTree != NULL)
	{
		out << subTree->data << " ";//���subTree������ֵ
		Traverse(subTree->leftChild, out);//�ݹ����������subTree��������
		Traverse(subTree->rightChild, out);//�ݹ����������subTree��������

	}

}

#if 0
template<class U>
ostream&operator << (ostream &out, BinaryTree<U>&Tree)
{
	//���ز��������һ�ö�����Tree,out�����������
	out << "��������ǰ�����\n";
	Tree.Traverse(Tree.root, out);
	out << endl;
	return out;
}
#endif

//�ù�������������
#if 1
template<class U>
ostream& operator<<(ostream &out, BinaryTree<U>&Tree)//���ز������
{
	cout << "cout guangyi table:";
	PrintBTree(Tree.root);
	return out;
}

#endif
//gettop��ʲô��������



#if 1   //�����������
template<class U>
istream&operator>>(istream &in, BinaryTree<U>&Tree)
{
	cout << "����һ������";
	Tree.CreateBinTree(in, Tree.root);
	 
	return in;
}//���ز�������
#endif

//�ù�������������
#if 0 
template<class T>
void BinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T>*&BT)
{
	cout << "������һ�������";
	//��������IN����������Ĺ�����ʾ������Ӧ�Ķ�������,BT�ᱻ��Ϊ���ڵ�
	stack<BinTreeNode<T>*>s;
	BT = NULL;//�ÿն�����
	BinTreeNode<T>*p, *t; int k=0;//��K��Ϊ�������������ı��
	char ch;
	in >> ch;//��In˳�����һ���ַ�
	while (ch != RefValue)//����ַ�����
	{
		switch (ch)
		{
			case '(':s.push(p); k = 1; break;//��������
			case')':t = s.top(); s.pop(); break;//�˳�����
			case',':k = 2; break;
			default:p = new BinTreeNode<T>(ch);
				if (BT == NULL)BT = p;//��P��Ϊ���ڵ�
				else if (k == 1)
				{
					t=s.top(); t->leftChild = p;//����*t������Ů
				}
				else
				{
					t=s.top(); t->rightChild = p;//����*t������Ů
				}

		}
		in >> ch;

		
	}
}
#endif 
/////////////Ӧ��ǰ������������������㷨//////////////////
#if 1
template<class T>
void BinaryTree<T>::CreateBinTree(istream&in, BinTreeNode<T>*&subTree)
{
//˽�к������Եݹ鷽ʽ����������
	
	T item;
	if (!in.eof())
	{
		in >> item;
		if (item != RefValue)
		{
			subTree = new BinTreeNode<T>(item);
			if (subTree == NULL)
			{
				cerr << "�洢�������" << endl; exit(1);
			}
			CreateBinTree(in, subTree->leftChild);//�ݹ齨��������
			CreateBinTree(in, subTree->rightChild);//�ݹ齨��������
		}
		else subTree = NULL;//���ָ���������ָ��
	}
}

#endif

//�������
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	//�ݹ麯�������㷨����������������subTreeΪ��������
	if (subTree != NULL)//=NULL����ֹ����
	{
		InOrder(subTree->leftChild, visit);//�����������������
		visit(subTree);//���ʸ��ڵ�
		InOrder(subTree->rightChild, visit);//�������������
	}
}


//ǰ�����
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL)//�ݹ��������
	{
		visit(subTree);//���ʸ��ڵ�
		preOrder(subTree->leftChild, visit);
		preOrder(subTree->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	//�ݹ麯�������㷨�������
	if (subTree != NULL)//�ݹ����
	{
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}

}

/////////////���������������ʵ��///////////////////////

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>*subTree)const
{
	//˽�к�����������subTreeΪ���Ķ������Ľڵ���
	if (subTree == NULL)return 0;
	else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>*subTree)const
{
	//˽�к�����������*subtreeΪ���Ķ������ĸ߶Ȼ����
	if (subTree == NULL)return 0;
	else
	{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

//////////////////////������ǰ�������Ӧ��/////////////////////
//Copy��δʵ��
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>&s)
{
	//�������������ƹ��캯��
	root = Copy(s.root);
}

template<class T>
BinTreeNode<T>*BinaryTree<T>::Copy(BinTreeNode<T>*orignode)
{
	//˽�к����������������һ��ָ�룬������һ����orignodeΪ���Ķ���������
	if (orignode == NULL)return NULL;//��Ϊ�շ��ؿ�ָ��
	BinTreeNode<T>*temp = new BinTreeNode<T>;//�������ڵ�
	temp->data = orignode->data;//��������
	temp->leftChild = Copy(orignode->leftChild);//����������
	temp->rightChild = Copy(orignode->rightChild);//����������
	return temp;//���ظ�ָ��
}


template<class T>
void PrintBTree(BinTreeNode<T>*BT)
{
	//cout << "����";
	if (BT != NULL)
	{
		cout << BT->data;
		if (BT->leftChild != NULL || BT->rightChild != NULL)
		{
			cout << "(";
			PrintBTree(BT->leftChild);
			cout << ",";
			if (BT->rightChild != NULL)
				PrintBTree(BT->rightChild);
			cout << ")";

		}
	}
}
