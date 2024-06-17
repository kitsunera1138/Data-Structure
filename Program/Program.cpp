#include <iostream>
using namespace std;

#define SIZE 10

template <typename T>
class Stack {
private:
	int top;
	T container[SIZE];

public:
	Stack() {
		top = -1;

		//container = {0, }//X //container를 저렇게 초기화 하면 오류뜸//저 방법은 선언할때만 사용가능
		for (int i = 0; i < SIZE; i++) {
			container[i] = 0;
		}
	}

	void Push(T data) {
		if (top >= SIZE -1) {
			cout << "Stack OverFlow" << endl;
		}
		else {
			container[++top] = data;
		}
	}

	void Pop() {
		if (Empty()) {
			cout << "Stack is Empty" << endl;
		}
		else {
			top--;
		}
	}

	bool Empty() {
		if (top <= -1) {
			return true;
		}
		else {
			return false;
		}
	}

	int& Size() {
		return top;
	}

	T& Top() {
		return container[top];
	}
	
	void Show() {
		//for (int i = 0; i < SIZE; i++) {
		//	cout << "Stack[" << i << "] : " << container[i] << endl;
		//}

		for (int i = top;i >= 0;i--) {
			cout << container[i] << " ";
		}
	}

};

bool CheckBracket(string content) { //괄호검사
	if (content.length() <= 0){
		return false;
	}
}

int main()
{
	/*
	Stack<int> stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	stack.Pop();

	//stack.Show();

	//데이터 출력
	while (stack.Empty() == false) {//비어있지않을 경우
		cout << stack.Top() << endl;
		stack.Pop();
	}
	*/

	//Stack<char> stack;
	//stack.CheckBracket("asd");

	return 0;
}

