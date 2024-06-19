#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	int size;
	int capacity;

	T* container; //크기가 변함
public:
	Vector() {
		size = 0;
		capacity = 0;
		container = nullptr;
	}

	void Resize(int newSize) {
		//1.capacity에 새로운 size 값을 저장합니다.
		capacity = newSize;

		//2.새로운 포인터 변수를 생성해서  새롭게 
		// 만들어진 메모리 공간을 가리키도록 합니다.
		T* newcontainer = new T[capacity]; //T* potiner = new T[capacity];

		//3. 새로운 메모리 공간의 값을 초기호 합니다.
		for (int i = 0;i < capacity;i++) {
			newcontainer[i] = NULL;
		}

		//4.기존 배열에 있는 값을 복사해서 새로운 배열에 넣어 줍니다.
		for (int i = 0;i < size;i++) {
			newcontainer[i] = container[i];
		}

		//5. 기존 배열의 메모리 해제합니다.
		//주의할 점 사이즈가 아예없을 때 배열이 할당안되었을때 할당 해제하면 안됨 - 조건
		if (container != nullptr) {
			delete[] container;
		}

		//6. 기존에 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킵니다.
		container = newcontainer;
	}

	void PushBack(T data) {
		if (capacity <= 0) {
			Resize(1);
		}
		else if (size >= capacity) {
			Resize(capacity * 2);
		}
		//크기 할당 후 데이터 삽입
		container[size++] = data;
	}

	T& operator[] (const int& index) {//값 변경 X도록 const
		return container[index];
	}

	int& Size() {
		return size;
	}

	~Vector() {
		if (container != nullptr) {
			delete[] container;
		}
	}

};

int main()
{
	Vector<int> vector;
	vector.PushBack(10);
	vector.PushBack(20);
	vector.PushBack(30);

	for (int i = 0; i < vector.Size();i++) {
		cout << vector[i] << endl;
	}

	return 0;
}

