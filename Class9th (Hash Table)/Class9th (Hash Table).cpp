#include <iostream>
using namespace std;
#define SIZE 6

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node {
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket {
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public:
	HashTable()
	{
		for (int i = 0;i < SIZE;i++) {
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	//해시 함수(Hash Function)란, 주어진 데이터(Key)를 고유한 숫자 값인 해시 값(Hash Value)으로 표현해주는 함수이다.
	template<typename T>
	int HashFunction(T key) {
		int hashIndex = (int)key % SIZE;//float로 들어왔을 경우 문제 자동(int)사용
		return hashIndex;
	}

	template<>
	int HashFunction(std::string key) {
		int result = 0; //임시 변수

		for (const char& element : key) {//0번째 ~ end까지만
			result += element;
		}
		int hashIndex = (int)result % SIZE; //	int hashIndex = result % SIZE;

		//cout << "cc" << hashIndex << endl;
		return hashIndex;
	}

	Node* CreatNode(KEY key, VALUE value) {
		Node* newNode = new Node();
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value) {
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		//새로운 노드를 생성 합니다.
		Node* newNode = CreatNode(key, value);

		//노드가 1개라도 존재하지 않는다면
		if (bucket[hashIndex].count == 0) {
			//bucket[hashIndex]의 head 포인터를 newNode를 가리키도록 함
			bucket[hashIndex].head = newNode;
		}
		else { //하나라도 존재한다면
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}
		//bucket[hashIndex]의 count를 증가합니다.
		bucket[hashIndex].count++;
	}

	void Show() {

		for (int i = 0; i < SIZE; i++) {
			Node* currentNode = bucket[i].head;

			while (currentNode != nullptr) {
				cout << "[" << i << "]" << " KEY : " << currentNode->key << " VALUE : " << currentNode->value << " ";
				currentNode = currentNode->next;
			}
			cout << endl;
		}
	}

	void Remove(KEY key) {
		//1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		//2. Node를 탐색할 수 있는 포인터 변수 선언
		Node* currentNode = bucket[hashIndex].head;

		//3. 이전 Node를 저장할 수 있는 포인터 변수 선언
		Node* previousNode = nullptr;

		//4. currentNode가 nullptr과 같다면 함수를 종료합니다.
		if (currentNode == nullptr) {
			cout << "Not Key Found" << endl;
			return;
		}
		else {
			//5. currentNode를 이용해서 내가 찾고자 하는 Key 값을 찾습니다.
			while (currentNode != nullptr) {
				if (currentNode->key == key) {

					if (currentNode == bucket[hashIndex].head) //head일때
					{
						bucket[hashIndex].head = currentNode->next;

					}
					else {
						previousNode->next = currentNode->next;
					}
					bucket[hashIndex].count--;
					delete currentNode;
					return;
				}
				else {
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
			//다 돌았는데 못 찾은 경우 //없음을 출력
			cout << "Not Key Found" << endl;

		}

	}

	~HashTable() {
		for (int i = 0; i < SIZE; i++) {
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr) {
				continue;
			}
			else { //하나라도 존재
				while (nextNode != nullptr) {
					nextNode = deleteNode->next;

					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}

		//ㅁㅁㅁ
		//for (int i = 0; i < SIZE; i++) {
		//	Node* deleteNode = bucket[i].head;
		//	Node* nextNode = deleteNode;

		//	while (deleteNode != nullptr) {
		//		nextNode = deleteNode->next;
		//		cout << "delete" << deleteNode->key;
		//		delete deleteNode;
		//		deleteNode = nextNode;
		//	}
		//}
	}

};

int main()
{
	//HashTable <int, std::string> hashTable;
	//cout << hashTable.HashFunction(10) << endl;;
	//cout<<hashTable.HashFunction(10.5f)<<endl;
	//cout << hashTable.HashFunction('A')<<endl;

	//HashTable < std::string, int> hashTable2;
	//cout << hashTable2.HashFunction("Kim");

	HashTable <std::string, int> hashTable;
	hashTable.Insert("Sword", 100);
	hashTable.Insert("Diamond", 909);
	hashTable.Insert("Potion", 50);
	hashTable.Insert("Ruby", 1455);

	hashTable.Remove("Ruby");
	hashTable.Remove("Diamond");
	hashTable.Remove("branch");
	hashTable.Show();

	return 0;
}