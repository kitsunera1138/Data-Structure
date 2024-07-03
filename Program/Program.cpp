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

	void Remove(T data) {
		if (root == nullptr) {
			cout << "Binary Search Tree is Empty" << endl;
		}
		else {
			Node* currentNode = root;
			Node* parentNode = root;


			while (currentNode != nullptr && currentNode->data != data) {//And // while (currentNode->data != data && currentNode != nullptr)를 쓰면 쇼트서킷	일어남

				if (currentNode->data > data) {
					parentNode = currentNode;
					currentNode = currentNode->left;
				}
				else {
					parentNode = currentNode;
					currentNode = currentNode->right;
				}
			}

			if (currentNode == nullptr) { //데이터가 없는 경우
				cout << "Data Not found in the Binary Search Tree" << endl;
			}
			else if (currentNode->left == nullptr && currentNode->right == nullptr) {

				if (parentNode != nullptr) {
					if (parentNode->left == currentNode) {
						parentNode->left = nullptr;
					}
					else {
						parentNode->right = nullptr;
					}
				}
				else {
					root = nullptr;
				}
			}
			else if (currentNode->left == nullptr || currentNode->right == nullptr) {
				//둘 중 하나가 값 존재 //자식 노드가 1개 있는 노드를 삭제하는 경우 // 참고로 둘 다 비어있는 경우는 위에서 걸러짐
				Node* childNode = root;

				if (currentNode->left != nullptr) {
					childNode = currentNode->left;
				}
				else {
					childNode = currentNode->right;
				}

				if (parentNode != nullptr) {
					if (parentNode->left == currentNode) {
						parentNode->left = childNode;
					}
					else {
						parentNode->right = childNode;
					}
				}
			}
			else {
				//자식이 두명 있을 경우
				Node* childNode = currentNode->right;
				Node* traceNode = childNode;

				while (childNode->left != nullptr) {
					traceNode = childNode;
					childNode = childNode->left;
				}


				currentNode->data = childNode->data;

				traceNode->left = childNode->right;

				delete childNode;

				return;
			}
			//ㅁㅁ 자식 하나
			//else if(currentNode->left !=nullptr ){
			//	Node* childNode = root;

			//	childNode = currentNode->left;
			//	parentNode->left = childNode;
			//}
			//else if (currentNode->right != nullptr) {
			//	Node* childNode = root;

			//	childNode = currentNode->right;
			//	parentNode->right = childNode;
			//}




			delete currentNode;
		}


	}

	//ㅁㅁ
	void Remove2(T data) { //값을 넣어 그 값을 찾으면 삭제

		if (root != nullptr && root->data == data) {
			root = nullptr;
			return;
		}

		Node* currentNode = root;

		while (currentNode != nullptr) {

			if (currentNode->data != data) {
				if (currentNode->data > data) {

					if (currentNode->left==nullptr) {
						cout << "Data Not Find" << endl;
						break;
					}

					if (currentNode->left-> data == data) {
						delete currentNode->left;
						currentNode->left = nullptr;

						break;
					}
					else {
						currentNode = currentNode->left;
					}
				}
				else {
					if (currentNode->right == nullptr) {
						cout << "Data Not Find" << endl;
						break;
					}

					if (currentNode->right->data == data) {
						delete currentNode->right;
						currentNode->right = nullptr;

						break;
					}
					else {
						currentNode = currentNode->right;
					}
				}
			}
			else {
				return;
			}
		}

		if (currentNode == nullptr) {
			cout << "BinarySearchTree Empty";
		}

	}


	void Destroy(Node* root) { //동적할당된 노드를 삭제 //소멸자에서 쓰이는 함수

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
	binarySearchTree.Insert(3);
	binarySearchTree.Insert(9);
	binarySearchTree.Insert(8);

	binarySearchTree.Remove(5);
	binarySearchTree.Remove(7);
	//binarySearchTree.Remove(1);

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
