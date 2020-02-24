#pragma once

//https://lx5475.github.io/2017/07/24/algorithm/algorithm-bianry-search-tree/

//기본 이진트리로 구현.
template <typename T>
class TreeNode {
public:
	T data_;
	TreeNode<T> * right_;
	TreeNode<T> * left_;

public:
	TreeNode()
	{
		this->right_ = nullptr;
		this->left_ = nullptr;
	}
	TreeNode(T data_ = 0, TreeNode<T> * right_ = nullptr, TreeNode<T> * left_ = nullptr)
	{
		this->data_ = data_;
		this->right_ = right_;
		this->left_ = left_;
	}
	TreeNode(const TreeNode &temp) //복사 생성자
	{
		this->data_ = temp.data_;
		this->right_ = temp.right_;
		this->left_ = temp.left_;
	}
	~TreeNode() {}
	TreeNode & operator =(const TreeNode &temp)  //대입 연산자.
	{
		this->data_ = temp.data_;
		this->right_ = temp.right_;
		this->left_ = temp.left_;

		return *this;
	}
};
//트리 용어
/*
차수 : 같은 부모에 최다 연결된 노드의 수.
노드 : 트리의 구성요소. 자식과 연결될 포인터와 데이터를 저장할 공간을 가짐.
깊이 : 루트에서 해당 노드까지의 직선 간선수 
루트 : 트리의 최상위 노드. 
리프 : 트리의 최하위 노드.
엣지 : 부모자식노드사이를 연결하는 선.
형제 노드 : 부모가 같은 노드들.
레벨 : 루트를 기준으로 1부터 깊이에 따른 노드집합.

이진트리 : 노드의 자식이 2개인 트리.

포화 이진트리 : 모든 레벨에 노드가 꽉찬 이진트리로. 높이가 h 일때 2^(h+1)-1 개의 노드수를 가지는 이진 트리.
완전 이진트리 : 노드 수가 n 개 일때, 중간 공백없이 노드 1번부터 n번까지 포화 이진트리와 같은 위치를 가지는 트리.
즉, 왼쪽, 오른쪽 둘중 한 방향으로 순차적으로 공백없이 채워진 트리. 

편향 이진트리 : 좌우 한쪽 방향의 자식으로만 노드가 채워지는 트리.

*/

//검색 순서.
//쟁점은 현 노드를 언제 체크하느냐.
	//전위 순회  : 현 노드 -> 왼쪽 서브트리 -> 오른쪽 서브트리
	//중위 순회  : 왼쪽 서브트리 -> 현 노드 -> 오른쪽 서브트리
	//후위 순회. : 왼쪽 서브트리 -> 오른쪽 서브트리 -> 현 노드
//
//삽입 연산
// 삽입할 값이 중복 아니면.
// 부모노드를 기준으로 
// 작으면 왼쪽, 크면 오른쪽으로 이동.
// 이동한 쪽이 비었으면 삽입!

//삭제 연산
//삭제할 노드까지 이동.
//삭제할 노드가 자식이 없는 리프 노드면 삭제.
//부모노드의 포인터를 nullptr
//자식이 하나면 부모노드의 포인터와 바꾼후 삭제!
//자식이 둘이면 좌측에서 최대값을 옮기거나, 우측에서 최소값을 옮겨준다.

template <typename T>
class TT_Tree
{
private:
	TreeNode<T> * root_; //루트 노드.
	int length_; //노드 수.
	int max_Level_; //최대 레벨
public:
	//생성자
	TT_Tree();
	//소멸자
	~TT_Tree();
	//루트노드 찾찾.
	TreeNode<T>* FindRoot();

	//삽입 기본 최하위 리프 노드에 삽입.
	void InsertNode(T data);
	void InsertNode(TreeNode<T> * newNode);

	//삭제 
	bool DeleteNode();
	bool DeleteNode(T data);
	bool DeleteNodeIndex(int index);
	//검색
	TreeNode<T> & SearchIndex(int index);
	TreeNode<T> & Search(T data);

	//전 출력. 입력한 변수에 따라 전위, 중위, 후위, 레벨 로 출력.
	void PrintAll();

	bool IsEmpty();

	//트리 비우기. 
	void ClearTree();

	int TreeSize();
	
	//전, 중, 후, 레벨
	void PreOrder(TreeNode<T> * root);
	void InOrder(TreeNode<T> * root);
	void PostOrder(TreeNode<T> * root);
	void LevelOrder(TreeNode<T> * root);
};

template<typename T>
TT_Tree<T>::TT_Tree()
{
	root_ = nullptr;
	length_ = 0;
	max_Level_ = 0;
}

template<typename T>
TT_Tree<T>::~TT_Tree()
{
	while (root_ == nullptr)
	{
		//삭제삭제
	}
}

template<typename T>
TreeNode<T> * TT_Tree<T>::FindRoot()
{
	return root_;
}

template<typename T>
void TT_Tree<T>::InsertNode(T data)  //왼 오 왼 오 순서가 기본. 
{
	TreeNode<T> * newNode = new TreeNode<T>(data);

	//일단 루트 비었으면 루트에 넣고.
	if (this->root_ == nullptr)
	{
		root_ = newNode;
	}

	//일단 검색검색 있는지 확인.없으면 고
	//임시 저장 부모 노드 
	//검색중 현재노드. 초기 시작은 루트노드.
	//현재노드 가 nullptr 이 될때까지. = 끝노드까지 내려갈때까지
	//현재를 부모로 옮기고, 
	//입력받은 값이 부모보다 작으면 왼쪽
	//                       크면 오른쪽으로 현재노드 이동.
	//이동이 끝나면 
	//입력받은 값이 부모보다 작으면 왼쪽
	//                       크면 오른쪽으로 저장.
}

template<typename T>
void TT_Tree<T>::InsertNode(TreeNode<T>* newNode)
{
	//일단 루트 비었으면 루트에 넣고.
	if (this->root_ == nullptr)
	{
		root_ = newNode;
	}

	//일단 검색검색 있는지 확인.없으면 고
	//임시 저장 부모 노드 
	//검색중 현재노드. 초기 시작은 루트노드.
	//현재노드 가 nullptr 이 될때까지. = 끝노드까지 내려갈때까지
	//현재를 부모로 옮기고, 
	//입력받은 값이 부모보다 작으면 왼쪽
	//                       크면 오른쪽으로 현재노드 이동.
	//이동이 끝나면 
	//입력받은 값이 부모보다 작으면 왼쪽
	//                       크면 오른쪽으로 저장.
}

template<typename T>
bool TT_Tree<T>::DeleteNode()  //기본 맨 아래 노드까지 이동후 삭제
{
	//일단 루트 비었으면 에바임
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
bool TT_Tree<T>::DeleteNode(T data) //데이터 비교로 해당 노드까지 이동 후 삭제.  //search함수 이용.
{
	//일단 루트 비었으면 에바임
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
bool TT_Tree<T>::DeleteNodeIndex(int index)  //해당 인덱스 까지 최단 이동후 삭제. //search함수 이용.
{
	//일단 루트 비었으면 에바임
	if (this->root_ == nullptr)
	{
		return false;
	}
	return false;
}

template<typename T>
TreeNode<T>& TT_Tree<T>::SearchIndex(int index)
{
	//일단 루트 비었으면 에바임
	if (this->root_ == nullptr)
	{
		return false;
	}
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
TreeNode<T>& TT_Tree<T>::Search(T data)
{
	//일단 루트 비었으면 에바임
	if (this->root_ == nullptr)
	{
		return false;
	}
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
void TT_Tree<T>::PrintAll()
{
}

template<typename T>
bool TT_Tree<T>::IsEmpty()
{
	return false;
}

template<typename T>
void TT_Tree<T>::ClearTree()
{
}

template<typename T>
int TT_Tree<T>::TreeSize()
{
	return length_;
}

template<typename T>
void TT_Tree<T>::PreOrder(TreeNode<T>* root)
{
	//주어진 노드 출력
	//왼쪽 노드로 내려감. //왼쪽이 널이 아니면
	//오른쪽 노드로 내려감. //오른쪽이 널이 아니면
}

template<typename T>
void TT_Tree<T>::InOrder(TreeNode<T>* root)
{
	//왼쪽 노드로 내려감. //왼쪽이 널이 아니면
	//노드 출력
	//오른쪽 노드로 내려감. //오른쪽이 널이 아니면
}

template<typename T>
void TT_Tree<T>::PostOrder(TreeNode<T>* root)
{
	//왼쪽노드로 내려감 //왼쪽이 널이 아니면
	//오른쪽 노드로 내려감 //오른쪽이 널이 아니면
	//노드 출력.
}

template<typename T>
void TT_Tree<T>::LevelOrder(TreeNode<T>* root)
{  
	//큐 를 생성하고 
	//큐에 루트를 넣음.
	//큐가 비기 전까지 
		//큐에서 빼고
		//방문표시.
		//왼쪽 노드를 큐에 넣고
		//오른쪽 노드를 큐에 넣고
}
