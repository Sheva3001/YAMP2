#include <iostream>
#include "TrieTree.h"
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream input("data.txt");
	
	if (!input.is_open())
		cout << "Ошибка открытия файла" << endl;
	else {
		Trie a;
		string data;
		while (!input.eof()) {
			input >> data;
			a.insert(data);
		}
		string _search = "abc";
		a.Search(_search);
	}
	return 0;
}
