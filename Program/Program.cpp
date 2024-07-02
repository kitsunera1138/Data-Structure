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
	//Node* root; //중위 순회를 위해 public으로 설정 했던것.. 프로퍼티를 사용하는 방법으로 변경

	BinarySearchTree() {
		root = nullptr;
	}

	Node* Root() { //private의 root에 접근하기 위한 방법으로 프로퍼티 사용
		return root; //프로퍼티
	}

	Node* CreateNode(T data) {
		// 1.새로운 노드를 생성합니다.
		Node* newNode = new Node();

		// 2. 새로운 노드에 data 값을 초기화합니다.
		newNode->data = data;

		// 3. 새로운 노드에 left값을 초기화합니다.
		newNode->left = nullptr;

		// 4. 새로운 노드에 right값을 초기화 합니다.
		newNode->right = nullptr;

		// 5. 새로운 노드르 반환합니다.
		return newNode;
	}

	void Insert(T data) {
		if (root == nullptr) {
			root = CreateNode(data);
		}
		else {
			Node* currrentNode = root;

			while (currrentNode != nullptr) {
				if (currrentNode->data == data) { //동일한 데이터가 들어왔을 시 
					return;
				}
				else if (currrentNode->data > data) { //들어온 데이터가 현재 데이터보다 작을때 왼쪽노드

					if (currrentNode->left == nullptr) {
						currrentNode->left = CreateNode(data);
						break;
					}
					else {
						currrentNode = currrentNode->left;
					}
				}
				else {
					if (currrentNode->right == nullptr) {
						currrentNode->right = CreateNode(data);
						break;
					}
					else {
						currrentNode = currrentNode->right;
					}
				}
			}
		}
	}

	bool Find(T data) {

		Node* currentNode = root;

		if (currentNode == nullptr) {
			return false;
		}
		else {
			while (currentNode != nullptr) {

				if (currentNode->data == data) {
					return true;
				}
				else {

					if (currentNode->data > data) {
						currentNode = currentNode->left;
					}
					else {
						currentNode = currentNode->right;
					}
				}
			}
			return false;
		}
	}

	//ㅁㅁㅁ
	//bool Find(T data) {

	//	Node* currentNode = root;

	//	while (currentNode != nullptr) {

	//		if (currentNode->data > data) {//왼

	//			if (currentNode->data == data) {
	//				return true;
	//			}

	//			if (currentNode->left == nullptr) {
	//				return false;
	//			}
	//			else {
	//				currentNode = currentNode->left;
	//			}

	//		}
	//		else {
	//			if (currentNode->data == data) {
	//				return true;
	//			}

	//			if (currentNode->right == nullptr) {
	//				return false;
	//			}
	//			else {
	//				currentNode = currentNode->right;
	//			}
	//		}

	//	}

	//	return false;

	//}

	void Inorder(Node* root) { //중위 탐색

		if (root != nullptr) {
			Inorder(root->left);

			cout << root->data << " ";

			Inorder(root->right);
		}

	}

	void Destroy(Node* root) {

		if (root != nullptr) {
			Destroy(root->left);
			Destroy(root->right);
			delete root; //매개변수로 들어온 root
		}

	}

	~BinarySearchTree() { //소멸자에서 delete
		Destroy(root);
	}
};

int main()
{
	BinarySearchTree<int> binarySearchTree;
	binarySearchTree.Insert(10);
	binarySearchTree.Insert(7);
	binarySearchTree.Insert(15);
	binarySearchTree.Insert(5);

	binarySearchTree.Inorder(binarySearchTree.Root());

	cout << endl;
	cout << binarySearchTree.Find(10) << " ";
	cout << binarySearchTree.Find(7) << " ";
	cout << binarySearchTree.Find(5) << " ";
	cout << binarySearchTree.Find(99) << " ";
	cout << binarySearchTree.Find(0) << " ";
	cout << endl;

	return 0;
}
