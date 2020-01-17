#pragma once
#include "stdafx.h"
#include "TT_SList.h"

template <typename T>
class TT_CircularList
{
	//꼬리 노드
	SingleNode<T> * tail_;
	//머리 노드
	SingleNode<T> * head_;
	//길이
	int length_;
public:
	TT_CircularList();
	TT_CircularList(const TT_CircularList & temp);
	~TT_CircularList();

	//새 노드 삽입. 꼬리에
	void Insert(SingleNode<T> * newNode);
	void Insert(T data);
	void Insert(SingleNode<T> * newNode, int index);
	void Insert(T data, int index);


	//검색후 삭제
	bool Delete(int index);


	//검색 위치로
	SingleNode<T> & SearchIndex(int index);
	//데이터로 찾기.
	SingleNode<T> & Search(T data);

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

template<typename T>//default index : 1 에 넣는것.
void TT_CircularList<T>::Insert(SingleNode<T>* newNode)
{
	if (head_ == nullptr)  //꼬리 비었으면
	{
		this->head_ = newNode;
		this->tail_ = newNode;
		newNode->next_ = this->tail_;  //꼬리에 추가 후 원으로 연결.
	}
	else//아니면 꼬리에 추가 하고
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
	if (head_ == nullptr)  //꼬리 비었으면
	{
		this->head_ = newNode;
		this->tail_ = newNode;
		newNode->next_ = this->tail_;  //꼬리에 추가 후 원으로 연결.
	}
	else//아니면 꼬리에 추가 하고
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
	if (index >= length_ && index <= 1)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
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

	if (index >= length_ && index <= 1)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
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
	//인덱스까지 탐색.
	SingleNode<T> * temp = this->head_;
	for (int i = 0; i < index; i++) //인덱스 위치까지 옮겨가서
	{
		temp = temp->next_;
		cout << "index : " << i+1 << endl;
	}

	return *temp;
}

template<typename T>
SingleNode<T>& TT_CircularList<T>::Search(T data)
{
	//전체 순환하며 데이터 검색.
	SingleNode<T> * temp = this->head_;
	// TODO: 여기에 반환 구문을 삽입합니다.
	for (int i = 0; i < length_; i++) //인덱스 위치까지 옮겨가서
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
	while (i < length_) //노드가 존재하지 않을때 까지
	{
		temp = temp->next_;//다음노드다음노드로
		cout << "index : " << i+1 << "   data : " << temp->data_ << endl;//출력.
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
