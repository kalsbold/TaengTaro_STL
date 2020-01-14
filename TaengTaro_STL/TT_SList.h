#pragma once

#include "stdafx.h"
//node class
//operator = �������̵�.
//��������� 
//���ø� Ŭ����

template <typename T>
class SingleNode {
public:
	T data_;
	SingleNode<T> * next_;

public:
	SingleNode() { this->next_ = nullptr; }
	SingleNode(const SingleNode &temp) //���� ������
	{
		this->data_ = temp.data_;
		this->next_ = temp.next_;
	}
	~SingleNode() {}
	SingleNode & operator =(const SingleNode &temp)  //���� ������.
	{
		this->data_ = temp.data_;
		this->next_ = temp.next_;

		return *this;
	}
};

//���������.
//operator += - ����Ʈ �̾��ֱ�.
//�˻�
//����
//����
//all print
//����Ʈ ����
//��ü ����
//������� Ȯ��.
template <typename T>
class TT_SingleList
{
	//�Ӹ����
	SingleNode<T> * head_;
	//����
	int length_;
public:
	TT_SingleList();
	TT_SingleList(const TT_SingleList & temp);
	~TT_SingleList();

	//�� ��� ����. ����
	void Insert(SingleNode<T> * newNode);
	void Insert(SingleNode<T> * newNode, int index);
	void Insert(T data, int index);

	//���� ��ġ, ������.
	bool DeleteIndex(int index);
	bool Delete(T data);

	//�˻�
	SingleNode<T> & SearchIndex(int index);
	SingleNode<T> & Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//����Ʈ ����.
	void ClearList();

	//����Ʈ ����.
	int ListLength();

	//TT_SingleList & operator+=(const TT_SingleList & temp); //�̾��ֱ�. 
};


template <typename T>
TT_SingleList<T>::TT_SingleList()
{
	head_ = new SingleNode<T>();
	length_ = 0;
}

template<typename T>
TT_SingleList<T>::TT_SingleList(const TT_SingleList & temp)
{
	//this->head_ = temp.head_;
	//this->length_ = temp.ListLength();
}

template <typename T>
TT_SingleList<T>::~TT_SingleList()
{
	if (head_ == nullptr)
	{
		return;
	}

	else if (head_->next_ != nullptr)
		ClearList();
	length_ = 0;

	cout << "destroy list" << endl;

}

template<typename T>
void TT_SingleList<T>::Insert(SingleNode<T> * newNode)
{
	if (head_->next_ == nullptr)  //ù��� null�̸�
	{
		head_->next_ = newNode;  //�ű⿡ �߰�.
		length_++;
	}
	else
	{
		SingleNode<T> * temp = head_;  //��带 ��������
		while (temp->next_ != nullptr) //��尡 �������� ������ ����
		{
			temp = temp->next_; //��������������
		}
		temp->next_ = newNode; //�����ٰ� �߰�.
		length_++;
	}
}

template<typename T>
void TT_SingleList<T>::Insert(SingleNode<T> * newNode, int index)
{
	if (index >= length_ && index <= 0)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else  //���� ����
	{
		SingleNode<T> * temp = head_;
		for (int i = 0; i < index; i++) //�ε��� ��ġ���� �Űܰ���
		{
			temp = temp->next_;
		}
		newNode->next_ = temp->next_; //���̿� 
		temp->next_ = newNode;        //��.

		length_++;
	}
}

template<typename T>
void TT_SingleList<T>::Insert(T data, int index)
{
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data_ = data;

	if (index >= length_ && index <= 0)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else  //���� ����
	{
		SingleNode<T> * temp = head_;
		for (int i = 0; i < index; i++) //�ε��� ��ġ���� �Űܰ���
		{
			temp = temp->next_;
		}
		newNode->next_ = temp->next_;
		temp->next_ = newNode;
		length_++;
	}
}

template<typename T>
bool TT_SingleList<T>::DeleteIndex(int index)  //��ġ���� ����
{
	//index ���� Ȯ�� �� ��ġ�� false
	if (index >= length_ && index <= 0)  //�ε��� ������ ����� 
	{
		return false;   //���� �ź�
	}
	else
	{	//��ġ ��ĭ ������ �̵�. 
		//��������� ������ 
		SingleNode<T>* deleteTemp = nullptr;  //�˻��ؼ� ���� ��� ãã.
		SingleNode<T> * temp = head_;
		SingleNode<T> *prevTemp = nullptr;
		for (int i = 0; i < index; i++) //�ε��� ���� ��ġ���� �Űܰ���
		{
			prevTemp = temp;
			temp = temp->next_;
		}
		deleteTemp = temp;
		prevTemp->next_ = deleteTemp->next_;//��忬�� �̾��ְ�
		delete deleteTemp;
		length_--;

		return true;
	}
}

template<typename T>
bool TT_SingleList<T>::Delete(T data)   //������ ã�Ƽ� ����.
{
	SingleNode<T>* deleteTemp = nullptr;  //�˻��ؼ� ���� ��� ãã.
	SingleNode<T> *Temp = head_;
	SingleNode<T> *prevTemp = Temp;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	for (int i = 0; i < length_; i++) //��ü�߿�
	{
		prevTemp = Temp;
		Temp = Temp->next_;
		cout << "index : " << i << endl;
		if (Temp->data_ == data)  //��ġ�ϴ� ������ ������
		{
			deleteTemp = Temp;  //�����Ұſ� ����
			//ã�Ҵٴ� �α�
			cout << "find delete data..." << endl;
			break;
		}
	}
	if (deleteTemp != nullptr)  //������ �����
	{
		prevTemp->next_ = deleteTemp->next_;
		delete deleteTemp;
		length_--;
	}
	else {  //������ �Ѿ
		return false;
	}
	return true;
}

template<typename T>
SingleNode<T> & TT_SingleList<T>::SearchIndex(int index)
{
	//�ε������� Ž��.
	SingleNode<T> * temp = head_;
	for (int i = 0; i < index; i++) //�ε��� ��ġ���� �Űܰ���
	{
		temp = temp->next_;
		cout << "index : " << i << endl;
	}

	return *temp;
}

template<typename T>
SingleNode<T> & TT_SingleList<T>::Search(T data)
{
	//��ü ��ȯ�ϸ� ������ �˻�.
	SingleNode<T> * temp = head_;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	for (int i = 0; i < length_; i++) //�ε��� ��ġ���� �Űܰ���
	{
		temp = temp->next_;
		cout << "index : " << i << endl;
		if (temp->data_ == data)
		{
			return *temp;
		}
	}

	return nullptr;

}

template<typename T>
void TT_SingleList<T>::PrintAll()
{
	SingleNode<T> * temp = head_;
	int i = 0;
	while (temp->next_ != nullptr) //��尡 �������� ������ ����
	{
		temp = temp->next_;//��������������
		cout << "index : " << i + 1 << "   data : " << temp->data_ << endl;//���.
		i++;
	}
}

template<typename T>
bool TT_SingleList<T>::IsEmpty()
{
	if (head_->next_ == nullptr && length_ == 0)  //��� ������ ù����ε� �̰� ����, ���̰� 0�̸�
		return true; //���� �����.
	else
		return false; // �Ⱥ����.
}

template<typename T>
void TT_SingleList<T>::ClearList()
{
	while (head_->next_ != nullptr) //ù��°��尡 ������������
	{
		DeleteIndex(length_);  //�������� ���� ������.
	}
}

template<typename T>
int TT_SingleList<T>::ListLength()  //���� ��ȯ.
{
	return length_;
}

//template<typename T>
//TT_SingleList<T> & TT_SingleList<T>::operator+=(const TT_SingleList & temp)
//{
//	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
//}
