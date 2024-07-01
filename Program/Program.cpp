#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {//이진 탐색 트리

private:

	struct Node
	{
		T data;

		Node* left;
		Node* right;

	}; 
	
	Node* root;

public:
	BinarySearchTree() {
		root = nullptr;
	}

};

int main()
{




	return 0;
}
