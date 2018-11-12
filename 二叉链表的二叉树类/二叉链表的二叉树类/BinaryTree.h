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
	friend ostream& operator<< (ostream &out, BinaryTree<U>&Tree);//���ز������
public:
	BinaryTree() :root(NULL) {};//���캯��
	BinaryTree(T value) :RefValue(value), root(NULL) {};//���캯��
	BinaryTree(const BinaryTree<T>&s);//���ƹ��캯��
	~BinaryTree() { destroy(root); }//��������
	bool IsEmpty() { return (root == NULL) ? true : false; }//�ж϶������շ�
	BinTreeNode<T>* Parent(BinTreeNode<T>*current)  //���ظ��ڵ�
	{
		return(root == NULL || root == current) ? NULL : Parent(root, current);
	}
	BinTreeNode<T>*LeftChild(BinTreeNode<T>*current)//��������Ů
	{
		return(current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T>*RightChild(BinTreeNode<T>*current)
	{
		return(current != NULL) ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }//�������ĸ߶�

	int Size() { return Size(root); }//���ؽڵ���

	BinTreeNode<T>*getRoot()const { return root; }//ȡ��

	void preOrder(void(*visit)(BinTreeNode<T>*p)) { preOrder(root, visit); }//ǰ�����

	void inOrder(void(*visit)(BinTreeNode<T>*p)) { inOrder(root, visit); }//�������

	void postOrder(void(*visit)(BinTreeNode<T>*p)) { postOrder(root, visit); }//�������

	void levelOrder(void(*visit)(BinTreeNode<T>*p));//��������

	int Insert(const T&item);//������Ԫ��

	BinTreeNode<T>*Find(T&item)const;//����

	void returnRefvalue() { cout << "�����������ʶ��"; cin >> RefValue; };

protected:
	BinTreeNode<T> *root;
	T RefValue; //��������ֹͣ��־
	void CreateBinTree(istream&in, BinTreeNode<T>*&subTree);//���ļ����뽨��
//	bool Insert(BinTreeNode<T>*&subTree, const T&x);//����
	void destroy(BinTreeNode<T>*subTree);//ɾ��
//	bool Find(BinTreeNode<T>*subTree, const T&x)const;//����
	BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);//����
	int Height(BinTreeNode<T>*subTree)const;//�������ĸ߶�
	int Size(BinTreeNode<T>*subTree)const;//���ؽ����
	BinTreeNode<T>*  Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current);//���ظ��ڵ�
//	BinTreeNode<T>Find(BinTreeNode<T>*subTree, const T&x)const;//��Ѱx
	void Traverse(BinTreeNode<T>*subTree, ostream&out);//ǰ��������
	void preOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p));
	void inOrder(BinTreeNode<T>*subTree, void(*visit)(BinTreeNode<T>*p));
	void postOrder(BinTreeNode<T>*Tree, void(*visit)(BinTreeNode<T>*p));
	template<class U>
	friend istream&operator>>(istream &in, BinaryTree<U>&Tree);//���ز�������
};


template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*subTree) {
	//˽�к�������ָ��subtree��Ϊ�գ���ɾ����Ϊsubtree������
	if (subTree != NULL)
	{
		destroy(subTree->leftChild);//�ݹ�ɾ��subtree��������
		destroy(subTree->rightChild);
		delete subTree;
	}
}






#endif