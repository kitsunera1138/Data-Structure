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
};
int main()
{

	return 0;
}

