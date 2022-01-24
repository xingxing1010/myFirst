#include<iostream>
#include<string>
#include<ctype.h>
#include<fstream>
using namespace std;
#define MAX 1000
struct Person {
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
struct AddressBooks {
	struct Person personArray[MAX];
	int size = 0;
};
void save(AddressBooks* p) {
	fstream ofs;
	ofs.open("电话薄.txt ",  ios::out);
	
	for (int i = 0; i < p->size; i++) {
		
		ofs  << p->personArray[i].name <<" ";
		ofs << (p->personArray[i].sex == 1 ? "男" : "女") << " ";
		ofs  << p->personArray[i].age <<" ";
		ofs  << p->personArray[i].phone <<" ";
		ofs  << p->personArray[i].address << endl;
	}

	ofs.close();


	
}
void menuShow() {
	cout << "************************" << endl;
	cout << "***** 1-添加联系人 *****" << endl;
	cout << "***** 2-显示联系人 *****" << endl;
	cout << "***** 3-删除联系人 *****" << endl;
	cout << "***** 4-查找联系人 *****" << endl;
	cout << "***** 5-修改联系人 *****" << endl;
	cout << "***** 6-清空联系人 *****" << endl;
	cout << "***** 0-退      出 *****" << endl;

	cout << "************************" << endl;


}
void addPerson(AddressBooks* p) {

	if (p->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
	
		int count = 0;
		string name;
		cout << "请输入姓名：" << endl;
		//cout << len;
		cin >> name;
		p->personArray[p->size].name = name;

		cout << "请输入性别：" << "\n" << "1-男" << "2-女" << endl;

		while (1) {
			cin.clear();
			int sex = 0;
			cin >> sex;
			char b = getchar();
			if (isalpha(b)) {
				cout << "请输入数字！！！！\a\a\a" << endl;
				while (getchar() != '\n') {

				}
				
			}
			if (sex == 1 || sex == 2) {
				p->personArray[p->size].sex = sex;
				break;

			}
			else {
				cout << "输入有误，请重新输入" << endl;
				

			}

		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		p->personArray[p->size].age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		p->personArray[p->size].phone = phone;


		cout << "请输入家庭地址：" << endl;
		string add;
		cin >> add;
		p->personArray[p->size].address = add;

		p->size++;
		
		cout << "添加成功";
		
		
		system("pause");

		system("cls");
	
	}


}



void display(AddressBooks* p) {
	
	if (p->size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout  << p->personArray[i].name << " ";
			cout  <<( p->personArray[i].sex ==1?"男":"女") << " ";
			cout  << p->personArray[i].age << " ";
			cout  << p->personArray[i].phone << " ";
			cout  << p->personArray[i].address << endl;
		}
		
	}
	system("pause");
	system("cls");

}
int isExist(AddressBooks* p, string name) {
	for (int n = 0; n < p->size; n++) {
		if (p->personArray[n].name == name) {
			return n;
		}

	}
	return -1;
}
void deletePerson(AddressBooks* p) {
	cout << "请输入您要删除的人员：\n";
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1) {
		for (int i = ret; i < p->size; i++) {
			p->personArray[i] = p->personArray[i + 1];
		}
		p->size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人？？？";
	}
	system("pause");
	system("cls");
}
void findPerson(AddressBooks* p)
{
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		cout << "姓名:" << p->personArray[ret].name << "\t";
		cout << "性别:" << p->personArray[ret].sex << "\t";
		cout << "年龄:" << p->personArray[ret].age << "\t";
		cout << "电话:" << p->personArray[ret].phone << "\t";
		cout << "家庭住址:" << p->personArray[ret].address << endl;


	}
	else {
		cout << "查无此人？？？";
	}

	system("pause");
	system("cls");

}
void modify(AddressBooks* p) {
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personArray[ret].name = name;
		cout << "请输入性别：" << "\n" << "1-男" << "2-女" << endl;
		int sex = 0;
		while (true) {
			cin.clear();

			cin >> sex;
			char b = getchar();
			
			if (isalpha(b)) {
				cout << "请输入数字！！！！\a\a\a" << endl;
				while (getchar() != '\n') {

				}
				system("pause");
				system("cls");
			}else
			if (sex == 1 || sex == 2) {
				p->personArray[ret].sex = sex;
				break;

			}
			//else {
				cout << "输入有误，请重新输入" << endl;
			//}

		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		p->personArray[ret].age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		p->personArray[ret].phone = phone;


		cout << "请输入家庭地址：" << endl;
		string add;
		cin >> add;
		p->personArray[ret].address = add;
		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人？？？";
	}

	system("pause");
	system("cls");


}
void cleanPerson(AddressBooks* p) {
	int ret = 0;
	cin >> ret;
	while (true) {
		if (ret == 1) {
			p->size = 0;
			cout << "通讯录已经清空" << endl;
			ofstream ofs("电话薄.txt", ios::trunc);
			ofs.close();
			break;
		}
		else if (ret == 2) {
			cout << "您已放弃清空操作" << endl;
			break;
		}
		else {
			cout << "输入有误！请输入";
		}
	}
	system("pause");
	system("cls");


	

	

	
}


int get() {
	ifstream ifs("电话薄.txt", ios::in);
	string na;
	string se;
	int ag;
	string phon;
	string addr;
	int num = 0;
	while(ifs >> na && ifs >> se && ifs >> ag && ifs >> phon && ifs >> addr) {
		//cout << na << se << ag << phon << addr;
		num++;
	
	}
		
	

	
		ifs.close();
	
	return num;
	}
	
void init(AddressBooks* p) {
	ifstream ifs("电话薄.txt", ios::in);
	string na;
	string se;
	int ag;
	string phon;
	string addr;
	int index = 0;
	while (ifs >> na && ifs >> se && ifs >> ag && ifs >> phon && ifs >> addr) {
		p->personArray[index].name = na;
		if (se == "男") {
			p->personArray[index].sex = 1;
		}
		else if (se == "女") {
			p->personArray[index].sex = 2;
		}
		p->personArray[index].age = ag;
		p->personArray[index].phone= phon;
		p->personArray[index].address= addr;
		index++;
	}
	
ifs.close();

 }


int main(void)
{
	struct AddressBooks abs;
	
	
	int Num = get();


	cout << "通讯录人数是" << Num << "人" << endl;


	init(&abs);
	abs.size = Num;
	//abs.size = NewNum;
	for (int i = 0; i < Num; i++) {
		cout << abs.personArray[i].name << " ";
		cout << (abs.personArray[i].sex == 1 ? "男" : "女") << " ";
		cout << abs.personArray[i].age << " ";
		cout << abs.personArray[i].phone << " ";
		cout << abs.personArray[i].address << endl;
	}

	

	//bool fileIsEmpty;
	
	while (1) {
		menuShow();
		cin.clear();
		cout << "请输入选项：" << endl;
		int select = 0;
		cin >> select;
		char c = getchar();
		if (isalpha(c)) {
			cout << "请输入数字！！！！\a\a\a" << endl;
			/*while (getchar() != '\n') {

			}*/
			cin.clear();
			cin.ignore(1024, '\n');
			system("pause");
			system("cls");
		}
		else {

			switch (select) {

			case 1:
				cout << "请输入您要添加的人员：\n";

				 addPerson(&abs);
				
				save(&abs);
				
			//	fileIsEmpty = false;
				break;

			case 2:
				cout << "联系人信息如下：\n";
				display(&abs);
				save(&abs);
				break;
			case 3:
				deletePerson(&abs);
				save(&abs);
				break;
			case 4:
				cout << "请输入您要查找的人员：\n";
				findPerson(&abs);

				break;
			case 5:
				cout << "请输入您要修改的人员：\n";
				modify(&abs);
				save(&abs);
				break;
			case 6:
				cout << "你确定要清空通讯录吗：1：yes/2:no\n";
				cleanPerson(&abs);

				break;
		
			case 0:  cout << "欢迎下次使用！" << endl;
				
				system("pause");
				return 0;
			default:
				cout << "输入有误！！！";
				system("pause");
				system("cls");
				break;
			}


		}


	}
	system("pause");
	return 0;
}