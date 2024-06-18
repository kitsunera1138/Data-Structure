#include <iostream>
#define SIZE 5
using namespace std;

template <typename T>
class LinearQueue { //선형 큐
private:
	int rear;
	int front;
	int size;

	T container[SIZE];

public:
	LinearQueue() {
		size = 0;
		rear = 0;
		front = 0;

		for (int i = 0;i < SIZE;i++) {
			container[i] = NULL;
		}
	}

	void Push(T data) {
		if (rear >= SIZE) {
			cout << "Queue Overflow" << endl;
		}
		else {
			container[rear++] = data; //후위 증가
			size++;
		}

		//if (rear != SIZE) {
		//	container[rear] = data;
		//	rear++;
		//	size++;
		//}
		//else {
		//	cout << "Queue Overflow" << endl;
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
		if (Empty()) { //비어있으면
			cout << "Linear Queue is Empty" << endl;
		}
		else {
			container[front++] = NULL;
			size--;
		}
		//if (front != SIZE) {
		//	container[front] = NULL;
		//	front++;
		//	size--;
		//}
	}

	T& Front() { //가장 앞의 값 반환
		if (Empty()) { //비어있다면
			exit(1);//강제 종료
		}
		else {
			return container[front];
		}
	}

	T& Back() {
		if (Empty()) { //비어있다면
			exit(1);//강제 종료
		}
		else {
			return container[rear - 1];
		}
	}

	int& Size() {
		return size;
	}
	void Show() {
		for (int i = 0;i < SIZE;i++) {
			cout << container[i] << endl;
		}
	}
};


int main()
{
	//선형 큐
	LinearQueue<int> linearQueue;
	linearQueue.Push(10);
	linearQueue.Push(20);
	linearQueue.Push(30);
	linearQueue.Push(40);
	linearQueue.Push(50);

	cout << "linearQueue.Back: " << linearQueue.Back() << endl;

	while (linearQueue.Empty() == false) {
		cout << linearQueue.Front() << endl;
		linearQueue.Pop();
	}

	linearQueue.Push(99);


	return 0;
}