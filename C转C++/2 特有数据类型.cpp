#include <iostream>
using namespace std;
int main () {
	bool flag = 1;//������true 
	cout << flag << endl;
	flag = -2; //������false 
	cout << flag << endl;
	const int a = 114514;
	string s1 = "C++̫��������";//Java��String 
	string s2 = ",���ù�û��";
	string s3;
	cin >> s3;
	cout << s1+s3+s2+"\n"; 
	cout << (s1+s3+s2).length() <<endl;
	cin.ignore();
	/*��ִ��cin >> s3��
	���뻺�����л����һ�����з�\n�������û�����s3�󰴻س������ģ�
	��ʱ����getline(cin, s1)
	����ֱ�Ӷ�ȡ���������\n
	����s1����ֵΪ���ַ�����""��*/ 
	getline(cin,s1);
	cout << s1.substr(0,3) <<endl;
	return 0;
}
 
