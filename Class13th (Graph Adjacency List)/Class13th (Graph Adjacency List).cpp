#include <iostream>
using namespace std;

#define SIZE 10

template <typename T>
class Adjacencylist { //인접 리스트
private:

	struct Node {
		T data;
		Node* next;

		Node(T data, Node* link = nullptr) {
			this->data = data;
			next = link;
		}
	};

	int size; // 정점의 개수
	T vertex[SIZE]; //정점의 집합
	Node* list[SIZE]; //인접 리스트

public:

	Adjacencylist() {
		size = 0;

		for (int i = 0; i < SIZE; i++) {
			vertex[i] = NULL;
			list[i] = NULL;
		}
	}

	void Insert(T data) {
		if (size >= SIZE) {
			cout << "Adjacency List Overflow";
		}
		else {
			vertex[size++] = data;
		}
	}

	void Connect(int u, int v) {

		if (size <= 0) {
			cout << "Adjacency List is Empty" << endl;
		}
		else if (u >= size || v >= size) {
			cout << "Index Out of Range" << endl;
		}
		else {
			list[u] = new Node(vertex[v], list[u]);
			list[v] = new Node(vertex[u], list[v]); //그래프 연결 
		}

	}

	void Show() {

		for (int i = 0; i < size; i++) {
			cout << vertex[i] << " : ";

			Node* currentNode = list[i];

			while (currentNode != nullptr) {

				cout << currentNode->data << " ";

				currentNode = currentNode->next;

			}

			cout << endl;
		}

	}

	~Adjacencylist() {//new로 생성했기에 delete해줘야함

		for (int i = 0; i < SIZE;i++) {
			if (list[i] != nullptr) {
				delete[] list[i]; //[] 연결된 애들까지 delete
			}
		}

		//ㅁㅁ
		//for (int i = 0; i < size;i++) {
		//	Node* currentNode = list[i];
		//	Node* deleteNode = currentNode;


		//	while (deleteNode != nullptr) {
		//		cout << "delete" << endl;
		//		currentNode = currentNode->next;

		//		delete deleteNode;
		//		deleteNode = currentNode;

		//	}
		//}
	}

};
int main()
{
#pragma region 인접리스트
	//그래프의 각 정점에 인접한 정점들을 연결 리스트로 표현하는 방법입니다.

	//장점
	// 그래프의 모든 간선의 수를 O(V + E)로 표현할 수 있습니다.

	// 단점
	// 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서
	// 정점의 인접 리스트를 모두 탐색해야 하므로, 정점의 차수 만큼의 시간이 필요합니다.

	Adjacencylist<char> adjacencylist;
	adjacencylist.Insert('A');
	adjacencylist.Insert('B');
	adjacencylist.Insert('C');
	adjacencylist.Insert('D');

	adjacencylist.Connect(0, 1);
	adjacencylist.Connect(0, 2);
	adjacencylist.Connect(2, 3);

	adjacencylist.Show();

#pragma endregion

	return 0;
}
