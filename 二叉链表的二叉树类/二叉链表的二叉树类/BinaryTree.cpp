#include"BinaryTree.h"
#include<stack>

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current)
{
	//私有函数：从结点subTree开始，搜索节点current的父节点,若找到节点current的父节点
	//则返回父节点的地址，否则函数返回NULL
	if (subTree == NULL)return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;//找到，返回父节点subTree
	BinTreeNode<T>*p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)return p;//递归在左子树中搜寻
	else return Parent(subTree->rightChild, current);//递归在右子树中搜寻

}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>*subTree, ostream&out)
{
	//私有函数：搜索并输出根为subtree的二叉树
	if (subTree != NULL)
	{
		out << subTree->data << " ";//输出subTree的数据值
		Traverse(subTree->leftChild, out);//递归搜索并输出subTree的左子树
		Traverse(subTree->rightChild, out);//递归搜索并输出subTree的右子树

	}

}

#if 0
template<class U>
ostream&operator << (ostream &out, BinaryTree<U>&Tree)
{
	//重载操作：输出一棵二叉树Tree,out是输出流对象
	out << "二叉树的前序遍历\n";
	Tree.Traverse(Tree.root, out);
	out << endl;
	return out;
}
#endif

//用广义表输出二叉树
#if 1
template<class U>
ostream& operator<<(ostream &out, BinaryTree<U>&Tree)//重载操作输出
{
	cout << "cout guangyi table:";
	PrintBTree(Tree.root);
	return out;
}

#endif
//gettop是什么？？？？



#if 1   //用输入二叉树
template<class U>
istream&operator>>(istream &in, BinaryTree<U>&Tree)
{
	cout << "输入一个棵树";
	Tree.CreateBinTree(in, Tree.root);
	 
	return in;
}//重载操作输入
#endif

//用广义表输入二叉树
#if 0 
template<class T>
void BinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T>*&BT)
{
	cout << "请输入一个广义表：";
	//从输入流IN输入二叉树的广义表表示建立对应的二叉链表,BT会被置为根节点
	stack<BinTreeNode<T>*>s;
	BT = NULL;//置空二叉树
	BinTreeNode<T>*p, *t; int k=0;//用K作为处理左右子树的标记
	char ch;
	in >> ch;//从In顺序读入一个字符
	while (ch != RefValue)//逐个字符处理
	{
		switch (ch)
		{
			case '(':s.push(p); k = 1; break;//进入子树
			case')':t = s.top(); s.pop(); break;//退出子树
			case',':k = 2; break;
			default:p = new BinTreeNode<T>(ch);
				if (BT == NULL)BT = p;//把P设为根节点
				else if (k == 1)
				{
					t=s.top(); t->leftChild = p;//链入*t的左子女
				}
				else
				{
					t=s.top(); t->rightChild = p;//链入*t的右子女
				}

		}
		in >> ch;

		
	}
}
#endif 
/////////////应用前序遍历建立二叉树的算法//////////////////
#if 1
template<class T>
void BinaryTree<T>::CreateBinTree(istream&in, BinTreeNode<T>*&subTree)
{
//私有函数：以递归方式建立二叉树
	
	T item;
	if (!in.eof())
	{
		in >> item;
		if (item != RefValue)
		{
			subTree = new BinTreeNode<T>(item);
			if (subTree == NULL)
			{
				cerr << "存储分配错误" << endl; exit(1);
			}
			CreateBinTree(in, subTree->leftChild);//递归建立左子树
			CreateBinTree(in, subTree->rightChild);//递归建立右子树
		}
		else subTree = NULL;//封闭指向空子树的指针
	}
}

#endif

//中序遍历
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	//递归函数：此算法按照中序次序遍历已subTree为根的子树
	if (subTree != NULL)//=NULL是终止调节
	{
		InOrder(subTree->leftChild, visit);//中序遍历根的左子树
		visit(subTree);//访问根节点
		InOrder(subTree->rightChild, visit);//中序遍历右子树
	}
}


//前序遍历
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL)//递归结束条件
	{
		visit(subTree);//访问根节点
		preOrder(subTree->leftChild, visit);
		preOrder(subTree->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p))
{
	//递归函数：此算法后序遍历
	if (subTree != NULL)//递归结束
	{
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}

}

/////////////二叉树后序遍历的实例///////////////////////

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>*subTree)const
{
	//私有函数：计算以subTree为根的二叉树的节点数
	if (subTree == NULL)return 0;
	else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>*subTree)const
{
	//私有函数：计算以*subtree为根的二叉树的高度或深度
	if (subTree == NULL)return 0;
	else
	{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

//////////////////////二叉树前序遍历的应用/////////////////////
//Copy还未实现
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>&s)
{
	//公共函数：复制构造函数
	root = Copy(s.root);
}

template<class T>
BinTreeNode<T>*BinaryTree<T>::Copy(BinTreeNode<T>*orignode)
{
	//私有函数：这个函数返回一个指针，它给出一个以orignode为根的二叉树副本
	if (orignode == NULL)return NULL;//根为空返回空指针
	BinTreeNode<T>*temp = new BinTreeNode<T>;//创建根节点
	temp->data = orignode->data;//传送数据
	temp->leftChild = Copy(orignode->leftChild);//复制左子树
	temp->rightChild = Copy(orignode->rightChild);//复制右子树
	return temp;//返回跟指针
}


template<class T>
void PrintBTree(BinTreeNode<T>*BT)
{
	//cout << "啊啊";
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
