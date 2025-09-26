#include <iostream>
using namespace std;
int main () {
	bool flag = 1;//正数是true 
	cout << flag << endl;
	flag = -2; //负数是false 
	cout << flag << endl;
	const int a = 114514;
	string s1 = "C++太好用啦！";//Java：String 
	string s2 = ",你用过没？";
	string s3;
	cin >> s3;
	cout << s1+s3+s2+"\n"; 
	cout << (s1+s3+s2).length() <<endl;
	cin.ignore();
	/*当执行cin >> s3后
	输入缓冲区中会残留一个换行符\n（比如用户输入s3后按回车产生的）
	此时调用getline(cin, s1)
	它会直接读取这个残留的\n
	导致s1被赋值为空字符串（""）*/ 
	getline(cin,s1);
	cout << s1.substr(0,3) <<endl;
	return 0;
}
 
