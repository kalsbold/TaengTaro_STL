#pragma once

#include "TT_DList.h"

template<typename T>
class TT_Stack
{
	TT_DoubleList * stack_;
	int size_;
public:
	TT_Stack(int size);
	TT_Stack(const TT_Stack & temp);
	~TT_Stack();

	void Push(T data);
	T Pop();

	bool Is_Empty();

	int StackLength();
};

template<typename T>
TT_Stack<T>::TT_Stack(int size)
{
	//����Ʈ ����
	this->stack_ = new TT_DoubleList<T>();
	//���� ������ ����.
	this->size_ = size;
}

template<typename T>
TT_Stack<T>::TT_Stack(const TT_Stack & temp)
{
}

template<typename T>
TT_Stack<T>::~TT_Stack()
{
	//���� ����Ʈ ����.
	if (this->stack_ != nullptr)
	{
		delete this->stack_;
	}
}

template<typename T>
void TT_Stack<T>::Push(T data)
{
	//LIFO
	//����Ʈ �� ���� �Է�.
	if (this->stack_->ListLength() >= this->size_)
	{
		cout << "stack is full..." << endl;
	}
	else
	{
		this->stack_->Insert(data, this->stack_->ListLength());

		cout << "push stack top.." << endl;
	}
}

template<typename T>
T TT_Stack<T>::Pop()
{
	//����Ʈ �ǳ� ���.
	//��ġ�س���
	//����
	//��ȯ.
	T re;

	if (this->stack_->IsEmpty() == true)
	{
		cout << "stack is empty..." << endl;
		return 0;
	}
	else
	{
		DoubleNode<T> data = this->stack_->SearchIndex(this->stack_->ListLength());
		re = data.data_;

		this->stack_->DeleteIndex(this->stack_->ListLength());

		cout << "pop up stack top..." << endl;
		return re;
	}
}

template<typename T>
bool TT_Stack<T>::Is_Empty()
{
	//����Ʈ ������� ��.
	//�������� ����.
	if (this->stack_->IsEmpty() == true)
		return true;
	else
		return false;
}

template<typename T>
int TT_Stack<T>::StackLength()
{
	//���ÿ� ���ִ� ��ŭ ���� ��ȯ.
	return this->stack_->ListLength();
}
