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

		cout << "cc" << hashIndex << endl;
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
		if (bucket[hashIndex].count== 0) {
			//bucket[hashIndex]의 head 포인터를 newNode를 가리키도록 함
			bucket[hashIndex].head = newNode;
		}
		else { //하나라도 존재한다면
			newNode->next= bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}
		//bucket[hashIndex]의 count를 증가합니다.
		bucket[hashIndex].count++;


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
	hashTable.Insert("Sword",100);

	return 0;
}

