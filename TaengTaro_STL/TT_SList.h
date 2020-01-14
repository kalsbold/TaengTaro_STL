#pragma once

#include "stdafx.h"
//node class
//operator = 오버라이딩.
//복사생성자 
//템플릿 클래스

template <typename T>
class SingleNode {
public:
	T data_;
	SingleNode<T> * next_;

public:
	SingleNode() { this->next_ = nullptr; }
	SingleNode(const SingleNode &temp) //복사 생성자
	{
		this->data_ = temp.data_;
		this->next_ = temp.next_;
	}
	~SingleNode() {}
	SingleNode & operator =(const SingleNode &temp)  //대입 연산자.
	{
		this->data_ = temp.data_;
		this->next_ = temp.next_;

		return *this;
	}
};

//복사생성자.
//operator += - 리스트 이어주기.
//검색
//삽입
//삭제
//all print
//리스트 길이
//전체 삭제
//비었는지 확인.
template <typename T>
class TT_SingleList
{
	//머리노드
	SingleNode<T> * head_;
	//길이
	int length_;
public:
	TT_SingleList();
	TT_SingleList(const TT_SingleList & temp);
	~TT_SingleList();

	//새 노드 삽입. 끝에
	void Insert(SingleNode<T> * newNode);
	void Insert(SingleNode<T> * newNode, int index);
	void Insert(T data, int index);

	//삭제 위치, 데이터.
	bool DeleteIndex(int index);
	bool Delete(T data);

	//검색
	SingleNode<T> & SearchIndex(int index);
	SingleNode<T> & Search(T data);

	//all print
	void PrintAll();

	//empty
	bool IsEmpty();

	//리스트 비우기.
	void ClearList();

	//리스트 길이.
	int ListLength();

	//TT_SingleList & operator+=(const TT_SingleList & temp); //이어주기. 
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
	if (head_->next_ == nullptr)  //첫노드 null이면
	{
		head_->next_ = newNode;  //거기에 추가.
		length_++;
	}
	else
	{
		SingleNode<T> * temp = head_;  //헤드를 기준으로
		while (temp->next_ != nullptr) //노드가 존재하지 않을때 까지
		{
			temp = temp->next_; //다음노드다음노드로
		}
		temp->next_ = newNode; //끝에다가 추가.
		length_++;
	}
}

template<typename T>
void TT_SingleList<T>::Insert(SingleNode<T> * newNode, int index)
{
	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else  //범위 내면
	{
		SingleNode<T> * temp = head_;
		for (int i = 0; i < index; i++) //인덱스 위치까지 옮겨가서
		{
			temp = temp->next_;
		}
		newNode->next_ = temp->next_; //사이에 
		temp->next_ = newNode;        //쏙.

		length_++;
	}
}

template<typename T>
void TT_SingleList<T>::Insert(T data, int index)
{
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data_ = data;

	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 일단 마지막에 넣어줭.
	{
		cout << "wrong index... insert last node" << endl;
		Insert(newNode);
	}
	else  //범위 내면
	{
		SingleNode<T> * temp = head_;
		for (int i = 0; i < index; i++) //인덱스 위치까지 옮겨가서
		{
			temp = temp->next_;
		}
		newNode->next_ = temp->next_;
		temp->next_ = newNode;
		length_++;
	}
}

template<typename T>
bool TT_SingleList<T>::DeleteIndex(int index)  //위치가서 삭제
{
	//index 범위 확인 후 넘치면 false
	if (index >= length_ && index <= 0)  //인덱스 범위를 벗어나면 
	{
		return false;   //삭제 거부
	}
	else
	{	//위치 한칸 전까지 이동. 
		//다음노드의 다음을 
		SingleNode<T>* deleteTemp = nullptr;  //검색해서 삭제 노드 찾찾.
		SingleNode<T> * temp = head_;
		SingleNode<T> *prevTemp = nullptr;
		for (int i = 0; i < index; i++) //인덱스 직전 위치까지 옮겨가서
		{
			prevTemp = temp;
			temp = temp->next_;
		}
		deleteTemp = temp;
		prevTemp->next_ = deleteTemp->next_;//노드연결 이어주고
		delete deleteTemp;
		length_--;

		return true;
	}
}

template<typename T>
bool TT_SingleList<T>::Delete(T data)   //데이터 찾아서 삭제.
{
	SingleNode<T>* deleteTemp = nullptr;  //검색해서 삭제 노드 찾찾.
	SingleNode<T> *Temp = head_;
	SingleNode<T> *prevTemp = Temp;
	// TODO: 여기에 반환 구문을 삽입합니다.
	for (int i = 0; i < length_; i++) //전체중에
	{
		prevTemp = Temp;
		Temp = Temp->next_;
		cout << "index : " << i << endl;
		if (Temp->data_ == data)  //일치하는 데이터 있으면
		{
			deleteTemp = Temp;  //삭제할거에 대입
			//찾았다는 로그
			cout << "find delete data..." << endl;
			break;
		}
	}
	if (deleteTemp != nullptr)  //있으면 지우고
	{
		prevTemp->next_ = deleteTemp->next_;
		delete deleteTemp;
		length_--;
	}
	else {  //없으면 넘어가
		return false;
	}
	return true;
}

template<typename T>
SingleNode<T> & TT_SingleList<T>::SearchIndex(int index)
{
	//인덱스까지 탐색.
	SingleNode<T> * temp = head_;
	for (int i = 0; i < index; i++) //인덱스 위치까지 옮겨가서
	{
		temp = temp->next_;
		cout << "index : " << i << endl;
	}

	return *temp;
}

template<typename T>
SingleNode<T> & TT_SingleList<T>::Search(T data)
{
	//전체 순환하며 데이터 검색.
	SingleNode<T> * temp = head_;
	// TODO: 여기에 반환 구문을 삽입합니다.
	for (int i = 0; i < length_; i++) //인덱스 위치까지 옮겨가서
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
	while (temp->next_ != nullptr) //노드가 존재하지 않을때 까지
	{
		temp = temp->next_;//다음노드다음노드로
		cout << "index : " << i + 1 << "   data : " << temp->data_ << endl;//출력.
		i++;
	}
}

template<typename T>
bool TT_SingleList<T>::IsEmpty()
{
	if (head_->next_ == nullptr && length_ == 0)  //헤드 다음이 첫노드인데 이게 없고, 길이가 0이면
		return true; //ㅇㅇ 비었음.
	else
		return false; // 안비었음.
}

template<typename T>
void TT_SingleList<T>::ClearList()
{
	while (head_->next_ != nullptr) //첫번째노드가 없어질때까지
	{
		DeleteIndex(length_);  //마지막꺼 지워 스끼야.
	}
}

template<typename T>
int TT_SingleList<T>::ListLength()  //길이 반환.
{
	return length_;
}

//template<typename T>
//TT_SingleList<T> & TT_SingleList<T>::operator+=(const TT_SingleList & temp)
//{
//	// TODO: 여기에 반환 구문을 삽입합니다.
//}
