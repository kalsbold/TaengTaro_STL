#pragma once

//https://lx5475.github.io/2017/07/24/algorithm/algorithm-bianry-search-tree/

//�⺻ ����Ʈ���� ����.
template <typename T>
class TreeNode {
public:
	T data_;
	TreeNode<T> * right_;
	TreeNode<T> * left_;

public:
	TreeNode()
	{
		this->right_ = nullptr;
		this->left_ = nullptr;
	}
	TreeNode(T data_ = 0, TreeNode<T> * right_ = nullptr, TreeNode<T> * left_ = nullptr)
	{
		this->data_ = data_;
		this->right_ = right_;
		this->left_ = left_;
	}
	TreeNode(const TreeNode &temp) //���� ������
	{
		this->data_ = temp.data_;
		this->right_ = temp.right_;
		this->left_ = temp.left_;
	}
	~TreeNode() {}
	TreeNode & operator =(const TreeNode &temp)  //���� ������.
	{
		this->data_ = temp.data_;
		this->right_ = temp.right_;
		this->left_ = temp.left_;

		return *this;
	}
};
//Ʈ�� ���
/*
���� : ���� �θ� �ִ� ����� ����� ��.
��� : Ʈ���� �������. �ڽİ� ����� �����Ϳ� �����͸� ������ ������ ����.
���� : ��Ʈ���� �ش� �������� ���� ������ 
��Ʈ : Ʈ���� �ֻ��� ���. 
���� : Ʈ���� ������ ���.
���� : �θ��ڽĳ����̸� �����ϴ� ��.
���� ��� : �θ� ���� ����.
���� : ��Ʈ�� �������� 1���� ���̿� ���� �������.

����Ʈ�� : ����� �ڽ��� 2���� Ʈ��.

��ȭ ����Ʈ�� : ��� ������ ��尡 ���� ����Ʈ����. ���̰� h �϶� 2^(h+1)-1 ���� ������ ������ ���� Ʈ��.
���� ����Ʈ�� : ��� ���� n �� �϶�, �߰� ������� ��� 1������ n������ ��ȭ ����Ʈ���� ���� ��ġ�� ������ Ʈ��.
��, ����, ������ ���� �� �������� ���������� ������� ä���� Ʈ��. 

���� ����Ʈ�� : �¿� ���� ������ �ڽ����θ� ��尡 ä������ Ʈ��.

*/

//�˻� ����.
//������ �� ��带 ���� üũ�ϴ���.
	//���� ��ȸ  : �� ��� -> ���� ����Ʈ�� -> ������ ����Ʈ��
	//���� ��ȸ  : ���� ����Ʈ�� -> �� ��� -> ������ ����Ʈ��
	//���� ��ȸ. : ���� ����Ʈ�� -> ������ ����Ʈ�� -> �� ���
//
//���� ����
// ������ ���� �ߺ� �ƴϸ�.
// �θ��带 �������� 
// ������ ����, ũ�� ���������� �̵�.
// �̵��� ���� ������� ����!

//���� ����
//������ ������ �̵�.
//������ ��尡 �ڽ��� ���� ���� ���� ����.
//�θ����� �����͸� nullptr
//�ڽ��� �ϳ��� �θ����� �����Ϳ� �ٲ��� ����!
//�ڽ��� ���̸� �������� �ִ밪�� �ű�ų�, �������� �ּҰ��� �Ű��ش�.

template <typename T>
class TT_Tree
{
private:
	TreeNode<T> * root_; //��Ʈ ���.
	int length_; //��� ��.
	int max_Level_; //�ִ� ����
public:
	//������
	TT_Tree();
	//�Ҹ���
	~TT_Tree();
	//��Ʈ��� ãã.
	TreeNode<T>* FindRoot();

	//���� �⺻ ������ ���� ��忡 ����.
	void InsertNode(T data);
	void InsertNode(TreeNode<T> * newNode);

	//���� 
	bool DeleteNode();
	bool DeleteNode(T data);
	bool DeleteNodeIndex(int index);
	//�˻�
	TreeNode<T> & SearchIndex(int index);
	TreeNode<T> & Search(T data);

	//�� ���. �Է��� ������ ���� ����, ����, ����, ���� �� ���.
	void PrintAll();

	bool IsEmpty();

	//Ʈ�� ����. 
	void ClearTree();

	int TreeSize();
	
	//��, ��, ��, ����
	void PreOrder(TreeNode<T> * root);
	void InOrder(TreeNode<T> * root);
	void PostOrder(TreeNode<T> * root);
	void LevelOrder(TreeNode<T> * root);
};

template<typename T>
TT_Tree<T>::TT_Tree()
{
	root_ = nullptr;
	length_ = 0;
	max_Level_ = 0;
}

template<typename T>
TT_Tree<T>::~TT_Tree()
{
	while (root_ == nullptr)
	{
		//��������
	}
}

template<typename T>
TreeNode<T> * TT_Tree<T>::FindRoot()
{
	return root_;
}

template<typename T>
void TT_Tree<T>::InsertNode(T data)  //�� �� �� �� ������ �⺻. 
{
	TreeNode<T> * newNode = new TreeNode<T>(data);

	//�ϴ� ��Ʈ ������� ��Ʈ�� �ְ�.
	if (this->root_ == nullptr)
	{
		root_ = newNode;
	}

	//�ϴ� �˻��˻� �ִ��� Ȯ��.������ ��
	//�ӽ� ���� �θ� ��� 
	//�˻��� ������. �ʱ� ������ ��Ʈ���.
	//������ �� nullptr �� �ɶ�����. = �������� ������������
	//���縦 �θ�� �ű��, 
	//�Է¹��� ���� �θ𺸴� ������ ����
	//                       ũ�� ���������� ������ �̵�.
	//�̵��� ������ 
	//�Է¹��� ���� �θ𺸴� ������ ����
	//                       ũ�� ���������� ����.
}

template<typename T>
void TT_Tree<T>::InsertNode(TreeNode<T>* newNode)
{
	//�ϴ� ��Ʈ ������� ��Ʈ�� �ְ�.
	if (this->root_ == nullptr)
	{
		root_ = newNode;
	}

	//�ϴ� �˻��˻� �ִ��� Ȯ��.������ ��
	//�ӽ� ���� �θ� ��� 
	//�˻��� ������. �ʱ� ������ ��Ʈ���.
	//������ �� nullptr �� �ɶ�����. = �������� ������������
	//���縦 �θ�� �ű��, 
	//�Է¹��� ���� �θ𺸴� ������ ����
	//                       ũ�� ���������� ������ �̵�.
	//�̵��� ������ 
	//�Է¹��� ���� �θ𺸴� ������ ����
	//                       ũ�� ���������� ����.
}

template<typename T>
bool TT_Tree<T>::DeleteNode()  //�⺻ �� �Ʒ� ������ �̵��� ����
{
	//�ϴ� ��Ʈ ������� ������
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
bool TT_Tree<T>::DeleteNode(T data) //������ �񱳷� �ش� ������ �̵� �� ����.  //search�Լ� �̿�.
{
	//�ϴ� ��Ʈ ������� ������
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
bool TT_Tree<T>::DeleteNodeIndex(int index)  //�ش� �ε��� ���� �ִ� �̵��� ����. //search�Լ� �̿�.
{
	//�ϴ� ��Ʈ ������� ������
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
TreeNode<T>& TT_Tree<T>::SearchIndex(int index)
{
	//�ϴ� ��Ʈ ������� ������
	if (this->root_ == nullptr)
	{
		return false;
	}
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

template<typename T>
TreeNode<T>& TT_Tree<T>::Search(T data)
{
	//�ϴ� ��Ʈ ������� ������
	if (this->root_ == nullptr)
	{
		return false;
	}
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

template<typename T>
void TT_Tree<T>::PrintAll()
{
}

template<typename T>
bool TT_Tree<T>::IsEmpty()
{
	return false;
}

template<typename T>
void TT_Tree<T>::ClearTree()
{
}

template<typename T>
int TT_Tree<T>::TreeSize()
{
	return length_;
}

template<typename T>
void TT_Tree<T>::PreOrder(TreeNode<T>* root)
{
	//�־��� ��� ���
	//���� ���� ������. //������ ���� �ƴϸ�
	//������ ���� ������. //�������� ���� �ƴϸ�
}

template<typename T>
void TT_Tree<T>::InOrder(TreeNode<T>* root)
{
	//���� ���� ������. //������ ���� �ƴϸ�
	//��� ���
	//������ ���� ������. //�������� ���� �ƴϸ�
}

template<typename T>
void TT_Tree<T>::PostOrder(TreeNode<T>* root)
{
	//���ʳ��� ������ //������ ���� �ƴϸ�
	//������ ���� ������ //�������� ���� �ƴϸ�
	//��� ���.
}

template<typename T>
void TT_Tree<T>::LevelOrder(TreeNode<T>* root)
{  
	//ť �� �����ϰ� 
	//ť�� ��Ʈ�� ����.
	//ť�� ��� ������ 
		//ť���� ����
		//�湮ǥ��.
		//���� ��带 ť�� �ְ�
		//������ ��带 ť�� �ְ�
}
