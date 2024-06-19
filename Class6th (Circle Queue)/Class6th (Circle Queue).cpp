#include <iostream>
using namespace std;

#define SIZE 5

template <typename T>
class CircleQueue {
private:
	int front;
	int rear;
	int size;

	T container[SIZE];
public:

	CircleQueue() {
		size = 0;
		front = SIZE - 1;
		rear = SIZE - 1;

		for (int i = 0;i < SIZE;i++) {
			container[i] = NULL;
		}
	}

	void Push(T data) {

		if (front == (rear + 1) % SIZE) { //공간X
			cout << "CircleQueue Overflow" << endl;
		}
		else {
			rear = (rear + 1) % SIZE;//0번째 인덱스 들어감
			container[rear] = data;

			size++;
		}

		//ㅁㅁX
		//if (front == rear) { //데이터 0개

		//	if (rear >= SIZE - 1) {
		//		rear = 0;
		//		container[0] = data;
		//	}
		//}
		//else {
		//	if (rear >= SIZE - 1) {
		//		rear = 0;
		//		container[0] = data;
		//	}
		//	else {
		//		container[rear++] = data;
		//	}
		//}
	}

	bool Empty() {

		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}

	void Pop() {

		if (Empty()) {
			cout << "CircleQueue is Empty" << endl;
		}
		else { //비어있지 않다면
			front = (front + 1) % SIZE;
			container[front] = NULL;

			size--;
		}

		//ㅁㅁㅁ
		//if (front >= SIZE -1) {
		//	front = 0;
		//	container[front] = NULL;
		//}
		//else {
		//	container[++front] = NULL;
		//}
	}

	int& Size() {
		return size;
	}
	T& Front() {
		return container[(front + 1) % SIZE];
	}

	void Show() {
		for (int i = 0;i < SIZE - 1;i++) {
			cout << container[i] << endl;
		}
	}
};

int main()
{
	/*
	CircleQueue<int> circleQueue;
	circleQueue.Push(10);
	circleQueue.Push(20);
	circleQueue.Push(30);
	circleQueue.Push(40);

	circleQueue.Pop();
	circleQueue.Pop();

	circleQueue.Show();
	*/
	CircleQueue<char> circleQueue; //size 5로 잡아서 4개만 Push 가능 
	//원형 큐는 한칸은 비워놓음
	circleQueue.Push('A');
	circleQueue.Push('B');
	circleQueue.Push('C');
	circleQueue.Push('D');

	while (circleQueue.Empty() == false) {
		cout << circleQueue.Front() << endl;
		circleQueue.Pop();
	}

	circleQueue.Push('E');
	circleQueue.Push('F');

	cout << endl;
	while (circleQueue.Empty() == false) {
		cout << circleQueue.Front() << endl;
		circleQueue.Pop();
	}

	return 0;
}