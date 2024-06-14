#include <iostream>
using namespace std;

template <typename T>

class CircleLinkedList { //원형 연결 리스트 //CircularLinkedList
private:
	int size;

	struct Node {
		T data;
		Node* next;
	};

	Node* head;

public:

	CircleLinkedList() {
		size = 0;
		head = nullptr;
	}

	void PushBack(T data) {
		Node* newNode = new Node; //동적할당
		newNode->data = data;

		if (head == nullptr) { //노드가 하나도 없을 경우

			head = newNode;

			head->next = newNode;
		}
		else {
			newNode->next = head->next;
			head->next = newNode;

			head = newNode;
		}

		size++;
	}

	void PushFront(T data) {
		Node* newNode = new Node; //동적할당
		newNode->data = data;

		if (head == nullptr) { //노드가 하나도 없을 경우
			head = newNode;
			head->next = newNode;
		}
		else { //노드가 하나이상 있음
			newNode->next = head->next;
			head->next = newNode;
		}

		size++;

	}

	void PopFront() {

		if (head == nullptr) {
			cout << "Linked List is Empty" << endl;
		}
		else {
			Node* deleteNode = head->next;

			if (head == head->next) {
				head = nullptr;
			}
			else {
				head->next = deleteNode->next;
			}
			delete deleteNode;

			size--;
		}

	}
	void PopBack() {

		if (head == nullptr) {
			cout << "Linked List is Empty" << endl;
		}
		else {

		Node* deleteNode = head;
		Node* currentNode = head;

		if (head == head->next) {
			head = nullptr;
		}
		else {
				//while (currentNode->next != head) {
				//	currentNode = currentNode->next;
				//}
			for (int i = 0;i < size - 1;i++) {
				currentNode = currentNode->next;
			}
			currentNode->next = head-> next;
			head = currentNode;

			delete deleteNode;
		}


		size--;
		}

	}


	void Show() {
		if (head != nullptr) {
			Node* currentNode = head->next; //노드 포인터 //= head로 시작주소를 바로 가리킴

			for (int i = 0;i < size;i++) {
				cout << currentNode->data << endl;
				currentNode = currentNode->next;
			}
		}
	}
};



int main()
{
	CircleLinkedList<int> CircularLinkedList;

	CircularLinkedList.PushBack(10);
	CircularLinkedList.PushBack(20);
	CircularLinkedList.PushBack(30);

	CircularLinkedList.PushFront(40);
	CircularLinkedList.PopFront(); //10 20 30

	CircularLinkedList.PopBack();

	CircularLinkedList.Show();





	return 0;
}

