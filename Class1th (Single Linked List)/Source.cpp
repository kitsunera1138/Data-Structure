//게임프로그래밍4 자료구조 6월10일~7월3일
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

	void PushBack(T data) {

		if (head == nullptr) { //데이터가 하나라도 없는경우
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else {
			Node* currentNode = head; //노드 포인터 //= head로 시작주소를 바로 가리킴

			while (currentNode->next != nullptr) {
				currentNode = currentNode->next;
			}
			//currentNode next가 nullptr이라면 //마지막까지 왔다면

			Node* newNode = new Node;
			currentNode->next = newNode;

			newNode->data = data;
			newNode->next = nullptr; //
		}
		size++;
	}

	void PopFront() {
		if (head == nullptr) {
			cout << "Linked List is empty" << endl;
		}
		else {
			Node* deleteNode = head; //포인터 변수 헤드 가리킴
			head = deleteNode->next; //다음 노드 가리킴
			delete deleteNode;

			size--;
		}

	}

	void PopBack() {

		if (head == nullptr) {
			cout << "Linked List is empty" << endl;
		}
		else {
			Node* deleteNode = head;
			Node* previousNode = nullptr;

			if (size == 1) { //노드가 하나일 경우
				head = deleteNode->next;

				delete deleteNode;
			}
			else { //둘 이상일 경우
				while (deleteNode->next != nullptr) {

					previousNode = deleteNode; //previousNode에 deleteNode의 주소를 넣는다
					deleteNode = deleteNode->next;
				}
				previousNode->next = deleteNode->next;
				delete deleteNode;
			}

			size--;
		}
	}

	void Show() {
		Node* currentNode = head; //노드 포인터 //= head로 시작주소를 바로 가리킴

		while (currentNode != nullptr) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	~SingleLinkedList() {//노드를 동적할당으로 만들었기 때문에 소멸자에서 삭제
		//ㅁㅁㅁ
		//while (head != nullptr) {
		//	Node* deleteNode = head; //포인터 변수 헤드 가리킴
		//	head = deleteNode->next; //다음 노드 가리킴
		//	delete deleteNode;

		//	cout << "delete" << endl;
		//}

		if (head != nullptr) {
			while (head != nullptr) {
				PopBack();
			}
		}
	}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;
	singleLinkedList.PushFront(30); //앞부터 데이터 삽입
	singleLinkedList.PushFront(20);
	singleLinkedList.PushFront(10);

	singleLinkedList.PopFront(); //20 30

	singleLinkedList.PushBack(10); //20 30 10
	singleLinkedList.PushBack(50);

	singleLinkedList.PopBack();

	singleLinkedList.Show();
}

