#include<iostream>

#include<Windows.h>
#include<string>
using namespace std;
int main() {
	char pwd[4];
	char dict[9];
	char tmp[32];
	int index = 0;
	for (int i = 0; i < 10; i++) {
		dict[index++] = '0' + i;
	}
	int n = 10;
	for (int p1 = 0; p1 < n; p1++) {
		for (int p2 = 0; p2 < n; p2++) {
			for (int p3 = 0; p3 < n; p3++) {
				for (int p4 = 0; p4 < n; p4++) {
					tmp[0] = dict[p1];
					tmp[1] = dict[p2];
					tmp[2] = dict[p3];
					tmp[3] = dict[p4];
					tmp[4] = '\0';
					cout << tmp << endl;
					
				}
			}
		}
	}
	system("pause");
	return 0;
}