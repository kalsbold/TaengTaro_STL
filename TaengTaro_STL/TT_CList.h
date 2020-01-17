#pragma once
#include "stdafx.h"
#include "TT_SList.h"

template <typename T>
class TT_CircularList
{
	//���� ���
	SingleNode<T> * tail_;
	//�Ӹ� ���
	SingleNode<T> * head_;
	//����
	int length_;
public:
	TT_CircularList();
	TT_CircularList(const TT_CircularList & temp);
	~TT_CircularList();

	//�� ��� ����. ������
	void Insert(SingleNode<T> * newNode);
	void Insert(T data);
	void Insert(SingleNode<T> * newNode, int index);
	void Insert(T data, int index);


	//�˻��� ����
	bool Delete(int index);


	//�˻� ��ġ��
	SingleNode<T> & SearchIndex(int index);
	//�����ͷ� ã��.
	SingleNode<T> & Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//����Ʈ ����.
	void ClearList();

	//����Ʈ ����.
	int ListLength();
};

template<typename T>
TT_CircularList<T>::TT_CircularList()
{
	tail_ = nullptr;
	head_ = nullptr;
	length_ = 0;
}

template<typename T>
TT_CircularList<T>::TT_CircularList(const TT_CircularList & temp)
{
}

template<typename T>
TT_CircularList<T>::~TT_CircularList()
{
	if (head_ == nullptr)
	{
		return;
	}

	else 
		ClearList();
	length_ = 0;

	cout << "destroy list" << endl;
}

template<typename T>//default index : 1 �� �ִ°�.
void TT_CircularList<T>::Insert(SingleNode<T>* newNode)
{
	if (head_ == nullptr)  //���� �������
	{
		this->head_ = newNode;
		this->tail_ = newNode;
		newNode->next_ = this->tail_;  //������ �߰� �� ������ ����.
	}
	else//�ƴϸ� ������ �߰� �ϰ�
	{
		newNode->next_ = this->head_;
		this->head_ = newNode;
		this->tail_->next_ = this->head_;
	}
	length_++;
}

template<typename T>
void TT_CircularList<T>::Insert(T data)
{
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data_ = data;
	if (head_ == nullptr)  //���� �������
	{
		this->head_ = newNode;
		this->tail_ = newNode;
		newNode->next_ = this->tail_;  //������ �߰� �� ������ ����.
	}
	else//�ƴϸ� ������ �߰� �ϰ�
	{
		newNode->next_ = this->head_;
		this->head_ = newNode;
		this->tail_->next_ = this->head_;
	}
	length_++;
}

template<typename T>
void TT_CircularList<T>::Insert(SingleNode<T>* newNode, int index)
{
	if (index >= length_ && index <= 1)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}

	SingleNode* current = this->head_;

	for (int i = 1; i < index - 1; i++)
	{
		current = current->next_;
	}

	newNode->next_ = current->next_;
	current->next_ = newNode;

}

template<typename T>
void TT_CircularList<T>::Insert(T data, int index)
{
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data_ = data;

	if (index >= length_ && index <= 1)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	SingleNode* current = this->head_;

	for (int i = 1; i < index - 1; i++)
	{
		current = current->next_;
	}

	newNode->next_ = current->next_;
	current->next_ = newNode;
}

template<typename T>
bool TT_CircularList<T>::Delete(int index)
{
	if (this->IsEmpty())
		return false;

	SingleNode<T> * Temp = nullptr;
	SingleNode<T> * current = this->head_;

	for (int i = 0; i < index; i++)
	{
		if (current->next_ == nullptr)
		{
			cout << "no data... link destroy.,.." << endl;
			return false;
		}
		if (i == index-1)
			Temp = current;
		current = current->next_;
	}

	Temp->next_ = current->next_;
	delete current;
	this->length_--;
	return true;
}


template<typename T>
SingleNode<T>& TT_CircularList<T>::SearchIndex(int index)
{
	//�ε������� Ž��.
	SingleNode<T> * temp = this->head_;
	for (int i = 0; i < index; i++) //�ε��� ��ġ���� �Űܰ���
	{
		temp = temp->next_;
		cout << "index : " << i+1 << endl;
	}

	return *temp;
}

template<typename T>
SingleNode<T>& TT_CircularList<T>::Search(T data)
{
	//��ü ��ȯ�ϸ� ������ �˻�.
	SingleNode<T> * temp = this->head_;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	for (int i = 0; i < length_; i++) //�ε��� ��ġ���� �Űܰ���
	{
		temp = temp->next_;
		cout << "index : " << i+1 << endl;
		if (temp->data_ == data)
		{
			return *temp;
		}
	}

	return nullptr;
}

template<typename T>
void TT_CircularList<T>::PrintAll()
{
	SingleNode<T> * temp = this->head_;
	int i = 0;
	while (i < length_) //��尡 �������� ������ ����
	{
		temp = temp->next_;//��������������
		cout << "index : " << i+1 << "   data : " << temp->data_ << endl;//���.
		i++;
	}
}

template<typename T>
bool TT_CircularList<T>::IsEmpty()
{
	if (head_ == tail_ && length_ == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
void TT_CircularList<T>::ClearList()
{
	while (head_ != tail_)
	{
		Delete();
	}
}

template<typename T>
int TT_CircularList<T>::ListLength()
{
	return length_;
}
