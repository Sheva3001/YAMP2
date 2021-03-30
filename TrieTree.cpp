#include "TrieTree.h"
using namespace std;

void Trie::insert(string s) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); i++) {
		if (p->child[s[i] - 'a'] != NULL)
			p = p->child[s[i] - 'a'];
		else if (p->child[s[i] - 'a'] == NULL) {
			insertNode(p, s[i] - 'a');
			p = p->child[s[i] - 'a'];
		}
	}
	insertNode(p, d);
}

void Trie::insertNode(TrieNode* p, int i) {
	p->child[i] = new TrieNode;
	for (int j = 0; j < d + 1; j++)
		p->child[i]->child[j] = NULL;
}

bool Trie::isLeaf(TrieNode* p) {
	bool result = true;
	int i = 0;
	while (i <= d && result) {
		if (p->child[i])
			result = false;
		i++;
	}
	return result;
}

void Trie::deleteLeaf(TrieNode*& p, int i) {
	TrieNode* q = p->child[i];
	p->child[i] = 0;
	delete q;
}

void Trie::retrieve(string s, TrieNode*& p) {
	if (s == "") {
		if (p->child[d])
			deleteLeaf(p, d);
	}
	else {
		retrieve(s.erase(0, 1), p->child[s[0] - 'a']);
	}
}

void Trie::print(string s, TrieNode* p) {
	for (int i = 0; i <= d; i++) {
		if (p->child[i] != NULL) {
			s += (char)(i + 'a');
			print(s, p->child[i]);
			if (s[s.size() - 1] == d+'a') {
				s.erase(s.size() - 1, 1);
				cout << s << endl;
			}
			if (s != "")
				s.erase(s.size() - 1, 1);
		}
	}
}

bool Trie::check(string s, string _search) {
	bool _check = false;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < _search.size(); j++) {
			if (s[i] == _search[j])
				_check = true;
		}
	}
	return _check;
}

void Trie::Print() {
	string temp;
	print(temp, root);
}

void Trie::Search(string _search) {
	string _print;
	search(root, _search, _print);
}

void Trie::search(TrieNode* p, string _search, string _print) {
	string temp;
	for (int i = 0; i <= d; i++) {
		if (!p->child[i] == NULL) {
			temp = (char)(i + 'a');
			_print += temp;
			if (check(temp, _search)) {
				print(_print, p->child[i]);
				if (p == root)
					_print = "";
			}
			else {
				search(p->child[i], _search, _print);
				if (p == root)
					_print = "";
			}
		}
	}
}