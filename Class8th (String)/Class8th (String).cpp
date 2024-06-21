#include <iostream>
using namespace std;

#pragma warnings(disable : 4996) //strlen 사용
//#define _CRT_SECURE_NO_WARNINGS //strlen사용 

class String {
private:
	char* container;
	int size;

public:
	String() {
		size = 0;
		container = nullptr;
	}

	void operator = (const char* content) {
		int arraySize = strlen(content) + 1;
		size = strlen(content);

		if (container == nullptr) {
			container = new char[arraySize];

			for (int i = 0; i < arraySize; i++) {
				container[i] = content[i];//읽기라 문제 X
			}
		}
		else { //새로것이 들어왔을 때
			char* newContainer = new char[arraySize];//메모리 확보

			for (int i = 0; i < arraySize; i++) {
				newContainer[i] = content[i];
			}
			delete container;
			container = newContainer;//container을 newContainer에 참조
		}
	}

	int Compare(const char* content) {
		int count = 0;

		for (int i = 0; i < strlen(content);i++) { //길이가 다르면
			if (container[i] != content[i]) {
				break;
			}
			else {
				count++; //같으면 증가
			}
		}
		if (strlen(content) == count) {
			return 0;
		}

		int classString = 0;//나의 클래스 문자열
		int otherString = 0;

		for (int i = 0;i < strlen(container);i++) {
			classString += container[i];
		}
		for (int i = 0;i < strlen(content);i++) {
			otherString += content[i];
		}

		if (classString > otherString) {
			return 1;
		}
		else {
			return -1;
		}


	}

	//ㅁㅁㅁ
	//int Compare2(const char* content) {
	//	int arraySize = strlen(content);

	//	if (strlen(container) == arraySize) {
	//		
	//		for (int i = 0; i < arraySize + 1;i++) {
	//			if (container[i] != content[i]) {
	//				return -1;
	//			}
	//		}
	//		return 1;
	//	}
	//	else {
	//		cout << "string length X";
	//		return -1;
	//	}

	//}
	//ㅁㅁㅁ

	char& operator[] (int index) {
		return container[index];
	}

	int& Size() {

		return size;
	}
	void Append(const char* content) {
		int newSize = strlen(container) + strlen(content); //기본적으로 +1상태

		char* newContainer = new char[newSize];

		for (int i = 0; i < strlen(container);i++) {
			newContainer[i] = container[i];
		}

		for (int i = 0; i < strlen(content);i++) {
			newContainer[strlen(container) + i] = content[i];
		}

		size = newSize;
		delete[] container;
		container = newContainer;
	}

	void Append2(const char* content) {
		int newSize = strlen(container) + strlen(content); //기본적으로 +1상태

		int contents = 0;
		int arraySize = strlen(container);

		if (container != nullptr) {
			char* newContainer = new char[strlen(container) + strlen(content)];

			for (int i = 0; i < strlen(container);i++) {
				newContainer[i] = container[i];
			}

			for (int i = 0; i < strlen(content);i++) {
				newContainer[strlen(container) + i] = content[i];
			}

			size = newSize; //size를 newSize로 초기화 해줘야함!!

			delete[] container;
			container = newContainer;
		}

	}

	~String() {
		if (container != nullptr) {
			delete[] container;
		}
	}
};


int main()
{

	String string;

	string = "Janna";
	//cout << "string의 크기 : " << string.Size() << endl;

	string = "Alistar";
	//for (int i=0;i < string.Size();i++) {
	//	cout << string[i]; //char &operator[] (int index)
	//}

	//if (string.Compare2("Alistar") == 1) {
	//	cout << "same";
	//}
	//else {
	//	cout << "X";
	//}

	cout << string.Compare("Alistar") << endl;;

	string.Append("ABCAA");

	for (int i = 0;i < string.Size();i++) {
		cout << string[i]; //char &operator[] (int index)
	}
	return 0;
}