﻿#include <iostream>
using namespace std;
//트리

struct Node {
	int data;

	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* left, Node* right) {
	Node* newNode = new Node;

	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

void Preorder(Node* root) { //전위 순회 //재귀함수

	if (root != nullptr) {
		cout << root->data << " ";

		Preorder(root->left); //재귀함수 사용
		Preorder(root->right);
	}
}

void Inorder(Node* root) { //중위 탐색

	if (root != nullptr) {
		Inorder(root->left);

		cout << root->data << " ";

		Inorder(root->right);
	}
}


void Postorder(Node* root) { //후위 탐색

	if (root != nullptr) {
		Postorder(root->left);
		Postorder(root->right);

		cout << root->data << " ";
	}
}


int main()
{
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);

	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	//전위 순회
	//Preorder(node1);

	//중위 순회
	//Inorder(node1);

	//후위 순회
	Postorder(node1);


	return 0;
}
