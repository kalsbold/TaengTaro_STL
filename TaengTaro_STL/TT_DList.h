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
	DoubleNode(const DoubleNode &temp) //복사 생성자
	{
		this->data_ = temp.data_;
		this->prev_ = temp.prev_;
		this->next_ = temp.next_;
	}
	~DoubleNode() {}
	DoubleNode & operator =(const DoubleNode &temp)  //대입 연산자.
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

	//새 노드 삽입. 끝에
	void Insert(DoubleNode<T> * newNode);
	void Insert(DoubleNode<T> * newNode, int index);
	void Insert(T data, int index);

	//삭제 위치, 데이터.
	bool DeleteIndex(int index);
	bool Delete(T data);

	//검색
	DoubleNode<T> & SearchIndex(int index);
	DoubleNode<T> & Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//리스트 비우기.
	void ClearList();

	//리스트 길이.
	int ListLength();
};

template<typename T>
TT_DoubleList<T>::TT_DoubleList()
{
	head_ = new DoubleNode<T>();
	tail_ = new DoubleNode<T>();

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

	else if (head_->next_ != nullptr)
		ClearList();
	length_ = 0;
}

template<typename T>
void TT_DoubleList<T>::Insert(DoubleNode<T>* newNode)
{
}

template<typename T>
void TT_DoubleList<T>::Insert(DoubleNode<T>* newNode, int index)
{
}

template<typename T>
void TT_DoubleList<T>::Insert(T data, int index)
{
}

template<typename T>
bool TT_DoubleList<T>::DeleteIndex(int index)
{
	return false;
}

template<typename T>
bool TT_DoubleList<T>::Delete(T data)
{
	return false;
}

template<typename T>
DoubleNode<T>& TT_DoubleList<T>::SearchIndex(int index)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
DoubleNode<T>& TT_DoubleList<T>::Search(T data)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
void TT_DoubleList<T>::PrintAll()
{
}

template<typename T>
bool TT_DoubleList<T>::IsEmpty()
{
	return false;
}

template<typename T>
void TT_DoubleList<T>::ClearList()
{
}

template<typename T>
int TT_DoubleList<T>::ListLength()
{
	return 0;
}
