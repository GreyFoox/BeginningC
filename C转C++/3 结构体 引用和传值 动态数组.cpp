#include <iostream>
#include <string>   
#include <vector> 
using namespace std;

struct stu {
		string name;
		int age;
		vector<int> v; 
		
	};

void f(int &a) { 
	a = 18;
}
int main() {
	int n = 0; 
	f(n);
	stu s = {"miku", n, {3,9}};//�Ⱥſ���ʡ
	s.v = {3, 9, 3, 9}; 
	cout << s.v.size() << endl;
	vector<int> v0(10,9);
	v0.resize(8);
	v0.push_back(10);
	//ע�⣺��ҪԽ�磡 
	cout << v0[8] << endl; 
	for (auto i = v0.begin(); i != v0.end(); i++) {
		cout << *i << " ";
	}//���������� 
	return 0; 
}

