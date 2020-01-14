// STL_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
template <typename T1, typename T2>
void printAll(T1 a, T2 b)
{
	cout << "T1 : " << a << endl;
	cout << "T2 : " << b << endl;
}

int main()
{
    cout << "Hello World!\n"; 

	//printAll("string", 10);

	TT_SingleList<int> *listtest = new TT_SingleList<int>();

	cout << "list length : " << listtest->ListLength() << endl;


	SingleNode<int> *Node = new SingleNode<int>();
	Node->data_ = 10;
	SingleNode<int> *Node2 = new SingleNode<int>();
	Node2->data_ = 20;
	SingleNode<int> *Node3 = new SingleNode<int>();
	Node3->data_ = 30;
	SingleNode<int> *Node4 = new SingleNode<int>();
	Node4->data_ = 40;
	listtest->Insert(Node);
	cout << "list length : " << listtest->ListLength() << endl;
	listtest->Insert(Node2);
	cout << "list length : " << listtest->ListLength() << endl;
	listtest->Insert(Node3);
	cout << "list length : " << listtest->ListLength() << endl;
	listtest->Insert(Node4);
	cout << "list length : " << listtest->ListLength() << endl;

	listtest->PrintAll();

	listtest->DeleteIndex(3);

	listtest->PrintAll();

	listtest->Delete(10);

	listtest->PrintAll();
	//node를 삭제할때 문제가 발생 했는데.
	//node 삽입시 일반 객체일때는 에러발생
	//            포인터 일때는 에러가 사라졌다.
	cout << "list length : " << listtest->ListLength() << endl;

	delete listtest;

	TT_DoubleList<int> *dlisttest = new TT_DoubleList<int>();

	cout << "dlist length : " << dlisttest->ListLength() << endl;


	DoubleNode<int> *dNode = new DoubleNode<int>();
	dNode->data_ = 10;
	DoubleNode<int> *dNode2 = new DoubleNode<int>();
	dNode2->data_ = 20;
	DoubleNode<int> *dNode3 = new DoubleNode<int>();
	dNode3->data_ = 30;
	DoubleNode<int> *dNode4 = new DoubleNode<int>();
	dNode4->data_ = 40;
	dlisttest->Insert(dNode);
	cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode2);
	cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode3);
	cout << "dlist length : " << dlisttest->ListLength() << endl;
	dlisttest->Insert(dNode4);
	cout << "dlist length : " << dlisttest->ListLength() << endl;

	dlisttest->PrintAll();

	dlisttest->DeleteIndex(3);

	dlisttest->PrintAll();

	dlisttest->Delete(10);
	
	dlisttest->PrintAll();
	cout << "dlist length : " << dlisttest->ListLength() << endl;
	
	delete dlisttest;

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
