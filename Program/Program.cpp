#include <iostream>
using namespace std;

template <typename T>

class SingleLinkedList { //단일 연결 리스트
private:
	int size;

	struct Node {
		T data;
		Node* next;

	};
	Node* head;
public:
	SingleLinkedList() {
		size = 0;
		head = nullptr;
	}

	void PushFront(T data) {
		if (head == nullptr) {
			head = new Node; //new 노드의 시작 주소를 가리킴

			head->data = data;
			head->next = nullptr;
		}
		else { //node가 하나라도 있을 경우
			//지역변수로 하면 소멸되어서 동적할당으로 해줘야 한다
			Node* newNode = new Node; //동적할당

			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void Show() {
		Node* currenNode = head; //노드 포인터 //= head로 시작주소를 바로 가리킴

		while(currentNode !=nullptr) {
			cout << currenNode->data << endl;

			currenNode= currenNode.next;
		}

	}

};

int main()
{
	SingleLinkedList<int> a;

}
