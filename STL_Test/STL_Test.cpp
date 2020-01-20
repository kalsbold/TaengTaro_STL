// STL_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
template <typename T1, typename T2>
void printAll(T1 a, T2 b)
{
	cout << "T1 : " << a << endl;
	cout << "T2 : " << b << endl;
}

//
template <typename T>
void BubbleSort(TT_DoubleList<T>* sortList, SORTMODE sortmode)
{
	
	//리스트 요소 n개에 대해
	//n-1번을 순회한다.
	//비교는 n-지난 노드수만큼 진행.
	//정렬 방식에 따라
	//오름차순이면 앞이 크면 변경. 작으면 유지
	//내림차순이면 앞이 크면 유지, 작으면 변경.
	int length = sortList->ListLength();
	int count = 0;
	for (int pass = length; pass >= 0; pass--)
	{
		for (int i = 1; i <= pass; i++)
		{
			DoubleNode<T>* swap1 = sortList->SearchIndex(i - 1);
			DoubleNode<T>* swap2 = sortList->SearchIndex(i);
			//cout << "firts one :" << swap1->data_<< endl;
			//cout << "second one : " << swap2->data_ << endl;
			if (sortmode == SORTMODE::ASCENDING)
			{
				//오름차순
				if (swap1->data_ > swap2->data_)
				{
					//cout << "swap them" << endl;
					sortList->SwapNodeData(i-1,i);
				}
			}
			if(sortmode == SORTMODE::DESCENDING)
			{
				//내림차순.
				if (swap1->data_ < swap2->data_)
				{
					sortList->SwapNodeData(i - 1, i);
				}
			}
		}
		count++;
		cout << "step - " << count << "  ";
		sortList->PrintAll();
	}

}

int main()
{
    //cout << "Hello World!\n"; 

	//printAll("string", 10);

	//TT_SingleList<int> *listtest = new TT_SingleList<int>();

	//cout << "list length : " << listtest->ListLength() << endl;


	//SingleNode<int> *Node = new SingleNode<int>();
	//Node->data_ = 10;
	//SingleNode<int> *Node2 = new SingleNode<int>();
	//Node2->data_ = 20;
	//SingleNode<int> *Node3 = new SingleNode<int>();
	//Node3->data_ = 30;
	//SingleNode<int> *Node4 = new SingleNode<int>();
	//Node4->data_ = 40;
	//listtest->Insert(Node);
	//cout << "list length : " << listtest->ListLength() << endl;
	//listtest->Insert(Node2);
	//cout << "list length : " << listtest->ListLength() << endl;
	//listtest->Insert(Node3);
	//cout << "list length : " << listtest->ListLength() << endl;
	//listtest->Insert(Node4);
	//cout << "list length : " << listtest->ListLength() << endl;

	//listtest->PrintAll();

	//listtest->DeleteIndex(3);

	//listtest->PrintAll();

	//listtest->Delete(10);

	//listtest->PrintAll();
	////node를 삭제할때 문제가 발생 했는데.
	////node 삽입시 일반 객체일때는 에러발생
	////            포인터 일때는 에러가 사라졌다.
	//cout << "list length : " << listtest->ListLength() << endl;

	//delete listtest;

	TT_DoubleList<int> *dlisttest = new TT_DoubleList<int>();

	cout << "dlist length : " << dlisttest->ListLength() << endl;


	DoubleNode<int> *dNode = new DoubleNode<int>();
	dNode->data_ = 50;
	DoubleNode<int> *dNode2 = new DoubleNode<int>();
	dNode2->data_ = 40;
	DoubleNode<int> *dNode3 = new DoubleNode<int>();
	dNode3->data_ = 10;
	DoubleNode<int> *dNode4 = new DoubleNode<int>();
	dNode4->data_ = 30;
	DoubleNode<int> *dNode5 = new DoubleNode<int>();
	dNode5->data_ = 20;
	dlisttest->Insert(dNode);
	//cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode2);
	//cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode3);
	//cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode4);
	dlisttest->Insert(dNode5);
	cout << "dlist length : " << dlisttest->ListLength() << endl;

	dlisttest->PrintAll();

	BubbleSort(dlisttest,SORTMODE::ASCENDING);

	dlisttest->PrintAll();

	//dlisttest->DeleteIndex(3);

	//dlisttest->PrintAll();

	//dlisttest->Delete(10);
	
	//dlisttest->PrintAll();
	cout << "dlist length : " << dlisttest->ListLength() << endl;
	
	delete dlisttest;


	/*TT_CircularList<int> *clisttest = new TT_CircularList<int>();

	cout << "clist length : " << clisttest->ListLength() << endl;

	SingleNode<int> *Node5 = new SingleNode<int>();
	Node5->data_ = 10;
	SingleNode<int> *Node6 = new SingleNode<int>();
	Node6->data_ = 20;
	SingleNode<int> *Node7 = new SingleNode<int>();
	Node7->data_ = 30;
	SingleNode<int> *Node8 = new SingleNode<int>();
	Node8->data_ = 40;
	clisttest->Insert(Node5);
	cout << "list length : " << clisttest->ListLength() << endl;
	clisttest->Insert(Node6);
	cout << "list length : " << clisttest->ListLength() << endl;
	clisttest->Insert(Node7);
	cout << "list length : " << clisttest->ListLength() << endl;
	clisttest->Insert(Node8);
	cout << "list length : " << clisttest->ListLength() << endl;

	clisttest->PrintAll();

	cout << "delete node" << endl;
	clisttest->Delete(3);

	clisttest->PrintAll();

	cout << "delete node" << endl;
	clisttest->Delete(1);

	clisttest->PrintAll();*/

	return 0;
}
