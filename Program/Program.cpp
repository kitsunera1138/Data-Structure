#include <iostream>
using namespace std;

#define SIZE 8

template <typename T>
class Heap {
private:
	int index;
	T container[SIZE]; //정적배열

public:
	Heap() {
		index = 0;

		for (int i = 0; i < SIZE;i++) {
			container[i] = NULL;
		}
	}

	void Insert(T data) {
		if (index >= SIZE) {
			cout << "Heap Overflow" << endl;
		}
		else {
			container[++index] = data; //전위 증가 //1부터 데이터 삽입

			int child = index;
			int parent = child / 2;

			while (child > 1) { //자식이 있을 경우 (1은 자식X)

				if (container[parent] < container[child]) {
					std::swap(container[parent], container[child]);
				}

				child = parent; //갱신 
				parent = child / 2;
			}
		}

	}

	void Order() { //정렬

		int child = index;
		int parent = child / 2;

		while (child > 1) { //자식이 있을 경우 (1은 자식X)

			if (container[parent] < container[child]) {
				Swap(&container[parent], &container[child]);
				//std::swap(container[parent], container[child]);
			}

			child = parent; //갱신 
			parent = child / 2;
		}
	}

	T Remove() {

		if (index <= 0) {//없을 때
			cout << "Heap is Empty" << endl;
			exit(1); //강제 종료
		}

		T result = container[1];

		container[1] = container[index];
		container[index] = NULL;
		//Order();
		index--;

		int parent = 1;
		int leftchild = parent * 2;
		int rightchild = parent * 2 +1;

		if (container[leftchild] < container[rightchild]) {
			
			std::swap(container[parent], container[rightchild]);
		}
		else {
			std::swap(container[parent], container[leftchild]);
		}

	}

	void Swap(int* A, int* B) {
		int temp = *A;
		*A = *B;
		*B = temp;
	}

	void Show() {
		for (int i = 1; i <= index; i++) {
			cout << container[i] << " ";
		}
		//for (int i = 0; i < SIZE; i++) {
		//	cout << container[i] << " ";
		//}
	}

};

int main()
{
	Heap<int> heap;
	heap.Insert(6);
	heap.Insert(7);
	heap.Insert(2);
	heap.Insert(10);

	heap.Insert(30);
	heap.Insert(40);
	heap.Insert(50);


	heap.Remove();
	heap.Show();

	return 0;
}

