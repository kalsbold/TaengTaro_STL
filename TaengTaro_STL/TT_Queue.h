#pragma once

#include "TT_DList.h"

template <typename T>
class TT_Queue 
{
	TT_DoubleList * queue_;
	int size_;
public:
	TT_Queue(int size);
	TT_Queue(const TT_Queue & temp);
	~TT_Queue();

	void Push(T data);
	T Pop();

	bool Is_Empty();

	int QueueLength();
};

template<typename T>
TT_Queue<T>::TT_Queue(int size)
{
	//ť ����Ʈ ����.
	//ť ������ ����.
	this->queue_ = new TT_DoubleList<T>();
	this->queue_ = size;
}

template<typename T>
TT_Queue<T>::TT_Queue(const TT_Queue & temp)
{
}

template<typename T>
TT_Queue<T>::~TT_Queue()
{
	//ť ����Ʈ ����
	if (this->queue_ != nullptr)
	{
		this->queue_->ClearList();
		delete this->queue_;
	}
}

template<typename T>
void TT_Queue<T>::Push(T data)
{
	if (this->queue_->ListLength() >= this->size_)
	{
		cout << "stack is full..." << endl;
	}
	else
	{
		this->queue_->Insert(data, this->queue_->ListLength());

		cout << "push stack top.." << endl;
	}
	//����Ʈ ���� Ǫ��.
}

template<typename T>
T TT_Queue<T>::Pop()
{
	//����Ʈ �տ��� ���.
	T re;

	if (this->queue_->IsEmpty() == true)
	{
		cout << "stack is empty..." << endl;
		return 0;
	}
	else
	{
		DoubleNode<T> data = this->queue_->SearchIndex(0);
		re = data.data_;

		this->queue_->DeleteIndex(0);

		cout << "pop up stack top..." << endl;
		return re;
	}
}

template<typename T>
bool TT_Queue<T>::Is_Empty()
{
	//����Ʈ ������� ��.
		//�������� ����.
	if (this->queue_->IsEmpty() == true)
		return true;
	else
		return false;
}

template<typename T>
int TT_Queue<T>::QueueLength()
{
	return this->queue_->ListLength();
}
