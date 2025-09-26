#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> split(string str) {
	const char* delimiters = " ";
	char *p = strtok(&str[0], delimiters);
	vector<string> result;
	while (p != nullptr) {
		result.push_back(p);
		p = strtok(nullptr, delimiters);
	}
	return result;
}

int main() {
	string str;
	getline(cin, str);
	vector<string> result = split(str);
	for (auto r : result) {
		cout << r << endl;
	}
	return 0;
}
