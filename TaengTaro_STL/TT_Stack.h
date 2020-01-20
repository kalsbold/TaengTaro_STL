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
	//리스트 생성
	this->stack_ = new TT_DoubleList<T>();
	//스택 사이즈 지정.
	this->size_ = size;
}

template<typename T>
TT_Stack<T>::TT_Stack(const TT_Stack & temp)
{
}

template<typename T>
TT_Stack<T>::~TT_Stack()
{
	//보유 리스트 삭제.
	if (this->stack_ != nullptr)
	{
		delete this->stack_;
	}
}

template<typename T>
void TT_Stack<T>::Push(T data)
{
	//LIFO
	//리스트 맨 끝에 입력.
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
	//리스트 맨끝 출력.
	//서치해놓고
	//삭제
	//반환.
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
	//리스트 비었으면 참.
	//차있으면 거짓.
	if (this->stack_->IsEmpty() == true)
		return true;
	else
		return false;
}

template<typename T>
int TT_Stack<T>::StackLength()
{
	//스택에 차있는 만큼 길이 반환.
	return this->stack_->ListLength();
}
