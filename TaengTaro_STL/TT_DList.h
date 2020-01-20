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
	DoubleNode<T> * SearchIndex(int index);
	DoubleNode<T> * Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//리스트 비우기.
	void ClearList();

	//리스트 길이.
	int ListLength();

	//노드간 데이터 교환
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
	//tail의 앞에다가 집어넣으면 됨.
	tail_->prev_->next_ = newNode;
	newNode->prev_ = tail_->prev_;
	tail_->prev_ = newNode;
	newNode->next_ = tail_;
	length_++;
}

template<typename T>
void TT_DoubleList<T>::Insert(DoubleNode<T>* newNode, int index)
{
	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else
	{
		if (index > (length_ / 2))  //리스트 길이 절반보다 큰번호
		{
			DoubleNode<T> *temp = tail_;

			for (int i = length_; i > index; --i)
			{
				//테일에서 접근.
				temp = temp->prev_;
			}
			//이전의 다음노드로 새노드
			//새노드의 이전노드로 이전노드
			//다음노드의 이전으로 새노드.
			//새노드의 다음노드로 다음노드
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		else //작거나 같은번호
		{
			//헤드에서 접근
			DoubleNode<T> *temp = head_;

			for (int i = 0; i < index; i++)
			{
				//테일에서 접근.
				temp = temp->next_;
			}
			//이전의 다음노드로 새노드
			//새노드의 이전노드로 이전노드
			//다음노드의 이전으로 새노드.
			//새노드의 다음노드로 다음노드
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
	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else
	{
		if (index > (length_ / 2))  //리스트 길이 절반보다 큰번호
		{
			DoubleNode<T> *temp = tail_;

			for (int i = length_; i > index; --i)
			{
				//테일에서 접근.
				temp = temp->prev_;
			}
			//이전의 다음노드로 새노드
			//새노드의 이전노드로 이전노드
			//다음노드의 이전으로 새노드.
			//새노드의 다음노드로 다음노드
			temp->prev_->next_ = newNode;
			newNode->prev_ = temp->prev_;
			temp->prev_ = newNode;
			newNode->next_ = temp;
		}
		else //작거나 같은번호
		{
			//헤드에서 접근
			DoubleNode<T> *temp = head_;

			for (int i = 0; i < index; i++)
			{
				//테일에서 접근.
				temp = temp->next_;
			}
			//이전의 다음노드로 새노드
			//새노드의 이전노드로 이전노드
			//다음노드의 이전으로 새노드.
			//새노드의 다음노드로 다음노드
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
	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 
	{
		return false;   //삭제 거부
	}
	else
	{
		if (index > (length_ / 2))  //리스트 길이 절반보다 큰번호
		{
			DoubleNode<T> *temp = tail_;
			DoubleNode<T> *deletetemp = nullptr;

			for (int i = length_; i > index; --i)
			{
				//테일에서 접근.
				temp = temp->prev_;
				cout << "index : " << i << endl;
			}
			//삭제작업.
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
		else //작거나 같은번호
		{
			//헤드에서 접근
			DoubleNode<T> *temp = head_;
			DoubleNode<T> *deletetemp = nullptr;
			for (int i = 0; i < index; i++)
			{
				//테일에서 접근.
				temp = temp->next_;
				cout << "index : " << i << endl;
			}
			//삭제작업.
			//삭제작업.
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
	//헤드에서 접근
	DoubleNode<T> *temp = head_;
	DoubleNode<T> *deletetemp = nullptr;
	for (int i = 0; i < length_; i++)
	{
		//테일에서 접근.
		temp = temp->next_;
		cout << "index : " << i+1 << endl;
		if (temp->data_ == data)
		{
			deletetemp = temp;
			break;
		}
	}
	if (deletetemp != nullptr)   //삭제할거 찾으면. 
	{ 
		//삭제작업.
		deletetemp = temp;
		deletetemp->prev_->next_ = deletetemp->next_;
		deletetemp->next_->prev_ = deletetemp->prev_;

		delete deletetemp;

		length_--;
	}
	else {   //못찾으면 넘어가.
		return false;
	}
	return true;
}

template<typename T>
DoubleNode<T>* TT_DoubleList<T>::SearchIndex(int index)
{
	//인덱스까지 탐색.
	if (index > (length_ / 2))  //리스트 길이 절반보다 큰번호
	{
		DoubleNode<T> *temp = tail_;

		for (int i = length_; i >= index; --i)
		{
			//테일에서 접근.
			temp = temp->prev_;
			//cout << "index : " << i+1 << endl;
		}

		return temp;
	}
	else //작거나 같은번호
	{
		//헤드에서 접근
		DoubleNode<T> *temp = head_;

		for (int i = 0; i <= index; i++)
		{
			//테일에서 접근.
			temp = temp->next_;
			//cout << "index : " << i + 1 << "  data :" << temp->data_ << endl;
		}

		return temp;
	}
}

template<typename T>
DoubleNode<T>* TT_DoubleList<T>::Search(T data)
{
	//전체 순환하며 데이터 검색.
	DoubleNode<T> * temp = head_;
	// TODO: 여기에 반환 구문을 삽입합니다.
	for (int i = 0; i < length_; i++) //인덱스 위치까지 옮겨가서
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
	while (temp->next_ != tail_) //노드가 존재하지 않을때 까지
	{
		temp = temp->next_;//다음노드다음노드로
		cout << "index : " << i + 1 << "   data : " << temp->data_ << "  ";//출력.
		i++;
	}
	cout << endl;
}

template<typename T>
bool TT_DoubleList<T>::IsEmpty()
{
	if (head_->next_ == tail_ && length_ == 0)  //헤드 다음이 첫노드인데 이게 없고, 길이가 0이면
		return true; //ㅇㅇ 비었음.
	else
		return false; // 안비었음.
}

template<typename T>
void TT_DoubleList<T>::ClearList()
{
	while (head_->next_ != tail_) //첫번째노드가 없어질때까지
	{
		DeleteIndex(length_);  //마지막꺼 지워 스끼야.
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
