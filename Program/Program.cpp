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
		if (front == rear) { //데이터 0개

			if (rear >= SIZE - 1) {
				rear = 0;
				container[0] = data;
			}
		}
		else {

		}
	}

	void Pop() {
		if (front >= SIZE -1) {
			front = 0;
			container[front] = NULL;
		}
		else {
			container[++front] = NULL;
		}
	}


	void Show() {
		for (int i = 0;i < SIZE;i++) {
			cout << container[i] << endl;
		}
	}
};

int main()
{
	CircleQueue<int> circleQueue;
	circleQueue.Push(10);
	circleQueue.Pop();
	circleQueue.Pop();

	circleQueue.Show();

	return 0;
}

