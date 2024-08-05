#include <iostream>
#define SIZE 26
using namespace std;

template <typename T>

class Trie {
private:
	bool final;

	Trie* alphabet[SIZE];

public:
	Trie() {
		for (int i = 0;i < SIZE;i++) {
			alphabet[i] = nullptr;
		}

		final = false;
	}

	void Insert(const char* content) {

		if (*content == '\0') { //null이라면
			final = true;
		}
		else {
			int index = 0;

			if ('A' <= *content && 'Z' >= *content) {
				index = *content - 'A';
			}
			else if ('a' <= *content && 'z' >= *content) {
				index = *content - 'a';
			}


			if (alphabet[index] == nullptr)
			{
				alphabet[index] = new Trie();
			}

			alphabet[index]->Insert(content + 1);
		}


	}

	bool Find(const char* content) {

		if(*content == NULL) {
			if (final == true) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			int index = 0;

			if ('A' <= *content && 'Z' >= *content) {
				index = *content - 'A';
			}
			else if ('a' <= *content && 'z' >= *content) {
				index = *content - 'a';
			}

			if (alphabet[index] == nullptr) {
				return false;
			}
			else {
				return alphabet[index]->Find(content + 1);
			}
		}
	}

	~Trie() {
		for (int i = 0; i < SIZE;i++) {
			if (alphabet[i] != nullptr) {
				delete alphabet[i];
			}
		}
	}
};
int main()
{
	Trie <char> trie;

	trie.Insert("Hello");
	trie.Insert("Apple");
	trie.Insert("Health");
	trie.Insert("Game");

	cout << trie.Find("Hello");
	cout << trie.Find("League");
	cout << trie.Find("Apple");
	cout << trie.Find("Health"); //

	return 0;
}

