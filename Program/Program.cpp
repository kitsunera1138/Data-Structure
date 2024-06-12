#include <iostream>
using namespace std;
template <typename T>


class DoublyLinkedList { //DoublyLinkedList 양방향 리스트
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;

public:
	DoublyLinkedList() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushBack(T data) {
		Node* newNode = new Node; //동적할당

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr) {
			tail = newNode;
			head = tail;
		}
		else {

			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;
		}
		size++;
	}

	void PushFront(T data) {
		
		Node* newNode = new Node; //동적할당

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}


	void PopBack() {

		if (tail == nullptr) { //노드가 하나도 없는 경우
			cout << "Linked List is empty" << endl;
		}
		else {
			Node* deleteNode = tail; //포인터 변수가 tail를 가리킴

			if (head == tail) { //노드가 하나인 경우
				head = nullptr;
				tail = nullptr;

				delete deleteNode;
			}
			else {//노드가 둘 이상일 경우
				tail->previous->next = nullptr;
				tail = tail->previous;

				delete deleteNode;
			}
			size--;
		}

		//ㅁㅁㅁ
		//if (head != nullptr) {

		//	if (head == tail) { //노드가 하나인 경우
		//		Node* deleteNode = head; //포인터 변수 헤드 가리킴
		//		delete deleteNode;

		//		head = nullptr;
		//		tail = nullptr;
		//	}
		//	else { //노드가 둘 이상일 경우
		//		Node* deleteNode = tail; //포인터 변수가 tail를 가리킴

		//		tail = deleteNode->previous;
		//		//tail = tail->previous;
		//		tail->next = nullptr;
		//		delete deleteNode;
		//	}


		//}
		//else { //노드가 하나도 없는 경우
		//	cout << "Linked List is empty" << endl;
		//}

	}

	int& Size() {//복사 비용 방지
		return size;
	}

	void Show() {
		Node* currentNode = head; //노드 포인터 //= head로 시작주소를 바로 가리킴

		while (currentNode != nullptr) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}
};


int main()
{
	DoublyLinkedList<int> DoublyLinkedList;
	DoublyLinkedList.PushBack(10);
	DoublyLinkedList.PushBack(20);
	DoublyLinkedList.PushBack(30);

	DoublyLinkedList.PopBack();

	DoublyLinkedList.PushFront(50);
	DoublyLinkedList.PushFront(60);

	DoublyLinkedList.Show();

	cout << "DoublyLinkedList의 Size: "<< DoublyLinkedList.Size() << endl;


	return 0;
}

