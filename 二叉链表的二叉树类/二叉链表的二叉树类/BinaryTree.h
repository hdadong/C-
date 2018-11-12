#pragma once
#ifndef BinaryTree1
#define BinaryTree1
#include<iostream>
using namespace std;
template<class T>
struct BinTreeNode {
	T data;
	BinTreeNode<T>*leftChild, *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T>*l = NULL, BinTreeNode<T>*r = NULL) :data(x), leftChild(l), rightChild(r) {};

};

template<class T>
class BinaryTree
{
	
	template<class U>
	friend ostream& operator<< (ostream &out, BinaryTree<U>&Tree);//重载操作输出
public:
	BinaryTree() :root(NULL) {};//构造函数
	BinaryTree(T value) :RefValue(value), root(NULL) {};//构造函数
	BinaryTree(const BinaryTree<T>&s);//复制构造函数
	~BinaryTree() { destroy(root); }//析构函数
	bool IsEmpty() { return (root == NULL) ? true : false; }//判断二叉树空否
	BinTreeNode<T>* Parent(BinTreeNode<T>*current)  //返回父节点
	{
		return(root == NULL || root == current) ? NULL : Parent(root, current);
	}
	BinTreeNode<T>*LeftChild(BinTreeNode<T>*current)//返回左子女
	{
		return(current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T>*RightChild(BinTreeNode<T>*current)
	{
		return(current != NULL) ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }//返回树的高度

	int Size() { return Size(root); }//返回节点数

	BinTreeNode<T>*getRoot()const { return root; }//取根

	void preOrder(void(*visit)(BinTreeNode<T>*p)) { preOrder(root, visit); }//前序遍历

	void inOrder(void(*visit)(BinTreeNode<T>*p)) { inOrder(root, visit); }//中序便利

	void postOrder(void(*visit)(BinTreeNode<T>*p)) { postOrder(root, visit); }//后序遍历

	void levelOrder(void(*visit)(BinTreeNode<T>*p));//层次序遍历

	int Insert(const T&item);//插入新元素

	BinTreeNode<T>*Find(T&item)const;//搜索

	void returnRefvalue() { cout << "请输入结束标识符"; cin >> RefValue; };

protected:
	BinTreeNode<T> *root;
	T RefValue; //数据输入停止标志
	void CreateBinTree(istream&in, BinTreeNode<T>*&subTree);//从文件读入建树
//	bool Insert(BinTreeNode<T>*&subTree, const T&x);//插入
	void destroy(BinTreeNode<T>*subTree);//删除
//	bool Find(BinTreeNode<T>*subTree, const T&x)const;//查找
	BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);//复制
	int Height(BinTreeNode<T>*subTree)const;//返回树的高度
	int Size(BinTreeNode<T>*subTree)const;//返回结点数
	BinTreeNode<T>*  Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current);//返回父节点
//	BinTreeNode<T>Find(BinTreeNode<T>*subTree, const T&x)const;//搜寻x
	void Traverse(BinTreeNode<T>*subTree, ostream&out);//前序遍历输出
	void preOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p));
	void inOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p));
	void postOrder(BinTreeNode<T>*Tree, void(*visit)(BinTreeNode<T>*p));
	template<class U>
	friend istream&operator>>(istream &in, BinaryTree<U>&Tree);//重载操作输入
};


template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*subTree) {
	//私有函数：若指针subtree不为空，则删除根为subtree的子树
	if (subTree != NULL)
	{
		destroy(subTree->leftChild);//递归删除subtree的左子树
		destroy(subTree->rightChild);
		delete subTree;
	}
}






#endif