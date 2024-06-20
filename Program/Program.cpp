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
		int arraySize = strlen(content);

		if (strlen(container) == arraySize) {
			
			for (int i = 0; i < arraySize + 1;i++) {
				if (container[i] != content[i]) {
					return -1;
				}
			}
			return 1;
		}
		else {
			cout << "string length X";
			return -1;
		}

	}

	char &operator[] (int index){
		return container[index];
	}

	int& Size() {

		return size;
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
	//string.Compare("Alistar");

	if (string.Compare("Alistar") == 1) {
		cout << "same";
	}
	else {
		cout << "X";
	}
	return 0;
}

