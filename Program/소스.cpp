//#include <iostream>
//using namespace std;
//
//#define SIZE 6
//
//template<typename KEY, typename VALUE>
//class HashTable
//{
//private:
//    struct Node
//    {
//        KEY key;
//        VALUE value;
//
//        Node* next;
//    };
//
//    struct Bucket
//    {
//        int count;
//        Node* head;
//    };
//
//    Bucket bucket[SIZE];
//
//public:
//    HashTable()
//    {
//        for (int i = 0; i < SIZE; i++)
//        {
//            bucket[i].count = 0;
//            bucket[i].head = nullptr;
//        }
//    }
//
//    template <typename T>
//    unsigned int HashFunction(T key)
//    {
//        unsigned int hashIndex = (int)key % SIZE;
//        cout << "aa" << hashIndex << endl;
//
//        return hashIndex;
//    }
//
//    /*template<>
//    int HashFunction(std::string key)
//    {
//        int result = 0;
//
//        for (const char& element : key)
//        {
//            result += element;
//        }
//
//        int hashIndex = result % SIZE;
//        cout << "bb" << hashIndex << endl;
//
//        return hashIndex;
//    }*/
//
//};
//
//int main()
//{
//    HashTable<std::string, int>    hashTable;
//
//    cout << hashTable.HashFunction("Kim");
//
//
//    return 0;
//}