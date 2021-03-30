#include <iostream>
using namespace std;

//В Trie-дереве найти все слова, содержащие символы заданного множества

const int d = 26;
struct TrieNode {
	TrieNode* child[d + 1];
};

class Trie {
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode[d + 1];
		for (int i = 0; i < d + 1; i++)
			root->child[i] = NULL;
	};
	void insert(string s);
	void retrieve(string s, TrieNode*& p);
	bool check(string s, string _search);
	void Print();
	void Search(string _search);
private:
	void insertNode(TrieNode* p, int i);
	bool isLeaf(TrieNode* p);
	void deleteLeaf(TrieNode*& p, int i);
	void print(string s, TrieNode* p);
	void search(TrieNode* p, string _search, string _print);
};
