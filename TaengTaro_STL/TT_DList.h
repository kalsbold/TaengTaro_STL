#pragma once
#include "stdafx.h"

template <typename T>
class DoubleNode {
public:
	T data_;
	DoubleNode<T> * prev_;
	DoubleNode<T> * next_;

public:
	DoubleNode() 
	{ 
		this->prev_ = nullptr; 
		this->next_ = nullptr;
	}
	DoubleNode(const DoubleNode &temp) //���� ������
	{
		this->data_ = temp.data_;
		this->prev_ = temp.prev_;
		this->next_ = temp.next_;
	}
	~DoubleNode() {}
	DoubleNode & operator =(const DoubleNode &temp)  //���� ������.
	{
		this->data_ = temp.data_;
		this->prev_ = temp.prev_;
		this->next_ = temp.next_;

		return *this;
	}
};


template<typename T>
class TT_DoubleList
{
	DoubleNode<T> * head_;
	DoubleNode<T> * tail_;

	int length_;

public:
	TT_DoubleList();
	TT_DoubleList(const TT_DoubleList & temp);
	~TT_DoubleList();

	//�� ��� ����. ����
	void Insert(DoubleNode<T> * newNode);
	void Insert(DoubleNode<T> * newNode, int index);
	void Insert(T data, int index);

	//���� ��ġ, ������.
	bool DeleteIndex(int index);
	bool Delete(T data);

	//�˻�
	DoubleNode<T> * SearchIndex(int index);
	DoubleNode<T> * Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//����Ʈ ����.
	void ClearList();

	//����Ʈ ����.
	int ListLength();

	//��尣 ������ ��ȯ
	void SwapNodeData(int index1, int index2);
};

template<typename T>
TT_DoubleList<T>::TT_DoubleList()
{
	head_ = new DoubleNode<T>();
	tail_ = new DoubleNode<T>();

	head_->next_ = tail_;
	tail_->prev_ = head_;

	length_ = 0;
}

template<typename T>
TT_DoubleList<T>::TT_DoubleList(const TT_DoubleList & temp)
{
}

template<typename T>
TT_DoubleList<T>::~TT_DoubleList()
{
	if (head_ == nullptr)
	{
		return;
	}

	else if (head_->next_ != tail_)
		ClearList();
	length_ = 0;

	cout << "destroy dlist" << endl;
}

template<typename T>
void TT_DoubleList<T>::Insert(DoubleNode<T>* newNode)
{
	//tail�� �տ��ٰ� ��������� ��.
	tail_->prev_->next_ = newNode;
	newNode->prev_ = tail_->prev_;
	tail_->prev_ = newNode;
	newNode->next_ = tail_;
	length_++;
}

template<typename T>
void TT_DoubleList<T>::Insert(DoubleNode<T>* newNode, int index)
{
	if (index >= length_ && index <= 0)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else
	{
		if (index > (length_ / 2))  //����Ʈ ���� ���ݺ��� ū��ȣ
		{
			DoubleNode<T> *temp = tail_;

			for (int i = length_; i > index; --i)
			{
				//���Ͽ��� ����.
				temp = temp->prev_;
			}
			//������ �������� �����
			//������� �������� �������
			//��������� �������� �����.
			//������� �������� �������
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		else //�۰ų� ������ȣ
		{
			//��忡�� ����
			DoubleNode<T> *temp = head_;

			for (int i = 0; i < index; i++)
			{
				//���Ͽ��� ����.
				temp = temp->next_;
			}
			//������ �������� �����
			//������� �������� �������
			//��������� �������� �����.
			//������� �������� �������
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		length_++;
	}
}

template<typename T>
void TT_DoubleList<T>::Insert(T data, int index)
{
	DoubleNode<T> *newNode = new DoubleNode<T>();
	newNode->data_ = data;
	if (index >= length_ && index <= 0)  //�ε��� ������ ����� �ϴ� �������� �־�a.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else
	{
		if (index > (length_ / 2))  //����Ʈ ���� ���ݺ��� ū��ȣ
		{
			DoubleNode<T> *temp = tail_;

			for (int i = length_; i > index; --i)
			{
				//���Ͽ��� ����.
				temp = temp->prev_;
			}
			//������ �������� �����
			//������� �������� �������
			//��������� �������� �����.
			//������� �������� �������
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		else //�۰ų� ������ȣ
		{
			//��忡�� ����
			DoubleNode<T> *temp = head_;

			for (int i = 0; i < index; i++)
			{
				//���Ͽ��� ����.
				temp = temp->next_;
			}
			//������ �������� �����
			//������� �������� �������
			//��������� �������� �����.
			//������� �������� �������
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		length_++;
	}
}

template<typename T>
bool TT_DoubleList<T>::DeleteIndex(int index)
{
	if (index >= length_ && index <= 0)  //�ε��� ������ ����� 
	{
		return false;   //���� �ź�
	}
	else
	{
		if (index > (length_ / 2))  //����Ʈ ���� ���ݺ��� ū��ȣ
		{
			DoubleNode<T> *temp = tail_;
			DoubleNode<T> *deletetemp = nullptr;

			for (int i = length_; i > index; --i)
			{
				//���Ͽ��� ����.
				temp = temp->prev_;
				cout << "index : " << i << endl;
			}
			//�����۾�.
			if (index == length_)
			{
				deletetemp = tail_->prev_;
			}
			else 
			{
				deletetemp = temp;
			}
			deletetemp->prev_->next_ = deletetemp->next_;
			deletetemp->next_->prev_ = deletetemp->prev_;

			delete deletetemp;

			length_--;
		}
		else //�۰ų� ������ȣ
		{
			//��忡�� ����
			DoubleNode<T> *temp = head_;
			DoubleNode<T> *deletetemp = nullptr;
			for (int i = 0; i < index; i++)
			{
				//���Ͽ��� ����.
				temp = temp->next_;
				cout << "index : " << i << endl;
			}
			//�����۾�.
			//�����۾�.
			deletetemp = temp;
			deletetemp->prev_->next_ = deletetemp->next_;
			deletetemp->next_->prev_ = deletetemp->prev_;

			delete deletetemp;

			length_--;
		}
		return true;
	}
}

template<typename T>
bool TT_DoubleList<T>::Delete(T data)
{
	//��忡�� ����
	DoubleNode<T> *temp = head_;
	DoubleNode<T> *deletetemp = nullptr;
	for (int i = 0; i < length_; i++)
	{
		//���Ͽ��� ����.
		temp = temp->next_;
		cout << "index : " << i+1 << endl;
		if (temp->data_ == data)
		{
			deletetemp = temp;
			break;
		}
	}
	if (deletetemp != nullptr)   //�����Ұ� ã����. 
	{ 
		//�����۾�.
		deletetemp = temp;
		deletetemp->prev_->next_ = deletetemp->next_;
		deletetemp->next_->prev_ = deletetemp->prev_;

		delete deletetemp;

		length_--;
	}
	else {   //��ã���� �Ѿ.
		return false;
	}
	return true;
}

template<typename T>
DoubleNode<T>* TT_DoubleList<T>::SearchIndex(int index)
{
	//�ε������� Ž��.
	if (index > (length_ / 2))  //����Ʈ ���� ���ݺ��� ū��ȣ
	{
		DoubleNode<T> *temp = tail_;

		for (int i = length_; i >= index; --i)
		{
			//���Ͽ��� ����.
			temp = temp->prev_;
			//cout << "index : " << i+1 << endl;
		}

		return temp;
	}
	else //�۰ų� ������ȣ
	{
		//��忡�� ����
		DoubleNode<T> *temp = head_;

		for (int i = 0; i <= index; i++)
		{
			//���Ͽ��� ����.
			temp = temp->next_;
			//cout << "index : " << i + 1 << "  data :" << temp->data_ << endl;
		}

		return temp;
	}
}

template<typename T>
DoubleNode<T>* TT_DoubleList<T>::Search(T data)
{
	//��ü ��ȯ�ϸ� ������ �˻�.
	DoubleNode<T> * temp = head_;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	for (int i = 0; i < length_; i++) //�ε��� ��ġ���� �Űܰ���
	{
		temp = temp->next_;
		cout << "index : " << i << endl;
		if (temp->data_ == data)
		{
			return temp;
		}
	}

	return nullptr;
}

template<typename T>
void TT_DoubleList<T>::PrintAll()
{
	DoubleNode<T> * temp = head_;
	int i = 0;
	while (temp->next_ != tail_) //��尡 �������� ������ ����
	{
		temp = temp->next_;//��������������
		cout << "index : " << i + 1 << "   data : " << temp->data_ << "  ";//���.
		i++;
	}
	cout << endl;
}

template<typename T>
bool TT_DoubleList<T>::IsEmpty()
{
	if (head_->next_ == tail_ && length_ == 0)  //��� ������ ù����ε� �̰� ����, ���̰� 0�̸�
		return true; //���� �����.
	else
		return false; // �Ⱥ����.
}

template<typename T>
void TT_DoubleList<T>::ClearList()
{
	while (head_->next_ != tail_) //ù��°��尡 ������������
	{
		DeleteIndex(length_);  //�������� ���� ������.
	}
}

template<typename T>
int TT_DoubleList<T>::ListLength()
{
	return length_;
}

template<typename T>
void TT_DoubleList<T>::SwapNodeData(int index1, int index2)
{
	DoubleNode<T>* swap1 = this->SearchIndex(index1);
	DoubleNode<T>* swap2 = this->SearchIndex(index2);

	T temp;

	//cout << "swap 1 : " << swap1->data_ << "  swap2 : " << swap2->data_ << endl;

	temp = swap1->data_;
	swap1->data_ = swap2->data_;
	swap2->data_ = temp;

	//cout << "after swap ::: swap 1 : " << swap1->data_ << "  swap2 : " << swap2->data_ << endl;
}
