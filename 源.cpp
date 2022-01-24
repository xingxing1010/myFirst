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
	ofs.open("�绰��.txt ",  ios::out);
	
	for (int i = 0; i < p->size; i++) {
		
		ofs  << p->personArray[i].name <<" ";
		ofs << (p->personArray[i].sex == 1 ? "��" : "Ů") << " ";
		ofs  << p->personArray[i].age <<" ";
		ofs  << p->personArray[i].phone <<" ";
		ofs  << p->personArray[i].address << endl;
	}

	ofs.close();


	
}
void menuShow() {
	cout << "************************" << endl;
	cout << "***** 1-�����ϵ�� *****" << endl;
	cout << "***** 2-��ʾ��ϵ�� *****" << endl;
	cout << "***** 3-ɾ����ϵ�� *****" << endl;
	cout << "***** 4-������ϵ�� *****" << endl;
	cout << "***** 5-�޸���ϵ�� *****" << endl;
	cout << "***** 6-�����ϵ�� *****" << endl;
	cout << "***** 0-��      �� *****" << endl;

	cout << "************************" << endl;


}
void addPerson(AddressBooks* p) {

	if (p->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
	
		int count = 0;
		string name;
		cout << "������������" << endl;
		//cout << len;
		cin >> name;
		p->personArray[p->size].name = name;

		cout << "�������Ա�" << "\n" << "1-��" << "2-Ů" << endl;

		while (1) {
			cin.clear();
			int sex = 0;
			cin >> sex;
			char b = getchar();
			if (isalpha(b)) {
				cout << "���������֣�������\a\a\a" << endl;
				while (getchar() != '\n') {

				}
				
			}
			if (sex == 1 || sex == 2) {
				p->personArray[p->size].sex = sex;
				break;

			}
			else {
				cout << "������������������" << endl;
				

			}

		}

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		p->personArray[p->size].age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		p->personArray[p->size].phone = phone;


		cout << "�������ͥ��ַ��" << endl;
		string add;
		cin >> add;
		p->personArray[p->size].address = add;

		p->size++;
		
		cout << "��ӳɹ�";
		
		
		system("pause");

		system("cls");
	
	}


}



void display(AddressBooks* p) {
	
	if (p->size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout  << p->personArray[i].name << " ";
			cout  <<( p->personArray[i].sex ==1?"��":"Ů") << " ";
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
	cout << "��������Ҫɾ������Ա��\n";
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1) {
		for (int i = ret; i < p->size; i++) {
			p->personArray[i] = p->personArray[i + 1];
		}
		p->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�����";
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
		cout << "����:" << p->personArray[ret].name << "\t";
		cout << "�Ա�:" << p->personArray[ret].sex << "\t";
		cout << "����:" << p->personArray[ret].age << "\t";
		cout << "�绰:" << p->personArray[ret].phone << "\t";
		cout << "��ͥסַ:" << p->personArray[ret].address << endl;


	}
	else {
		cout << "���޴��ˣ�����";
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
		cout << "������������" << endl;
		cin >> name;
		p->personArray[ret].name = name;
		cout << "�������Ա�" << "\n" << "1-��" << "2-Ů" << endl;
		int sex = 0;
		while (true) {
			cin.clear();

			cin >> sex;
			char b = getchar();
			
			if (isalpha(b)) {
				cout << "���������֣�������\a\a\a" << endl;
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
				cout << "������������������" << endl;
			//}

		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		p->personArray[ret].age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		p->personArray[ret].phone = phone;


		cout << "�������ͥ��ַ��" << endl;
		string add;
		cin >> add;
		p->personArray[ret].address = add;
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴��ˣ�����";
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
			cout << "ͨѶ¼�Ѿ����" << endl;
			ofstream ofs("�绰��.txt", ios::trunc);
			ofs.close();
			break;
		}
		else if (ret == 2) {
			cout << "���ѷ�����ղ���" << endl;
			break;
		}
		else {
			cout << "��������������";
		}
	}
	system("pause");
	system("cls");


	

	

	
}


int get() {
	ifstream ifs("�绰��.txt", ios::in);
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
	ifstream ifs("�绰��.txt", ios::in);
	string na;
	string se;
	int ag;
	string phon;
	string addr;
	int index = 0;
	while (ifs >> na && ifs >> se && ifs >> ag && ifs >> phon && ifs >> addr) {
		p->personArray[index].name = na;
		if (se == "��") {
			p->personArray[index].sex = 1;
		}
		else if (se == "Ů") {
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


	cout << "ͨѶ¼������" << Num << "��" << endl;


	init(&abs);
	abs.size = Num;
	//abs.size = NewNum;
	for (int i = 0; i < Num; i++) {
		cout << abs.personArray[i].name << " ";
		cout << (abs.personArray[i].sex == 1 ? "��" : "Ů") << " ";
		cout << abs.personArray[i].age << " ";
		cout << abs.personArray[i].phone << " ";
		cout << abs.personArray[i].address << endl;
	}

	

	//bool fileIsEmpty;
	
	while (1) {
		menuShow();
		cin.clear();
		cout << "������ѡ�" << endl;
		int select = 0;
		cin >> select;
		char c = getchar();
		if (isalpha(c)) {
			cout << "���������֣�������\a\a\a" << endl;
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
				cout << "��������Ҫ��ӵ���Ա��\n";

				 addPerson(&abs);
				
				save(&abs);
				
			//	fileIsEmpty = false;
				break;

			case 2:
				cout << "��ϵ����Ϣ���£�\n";
				display(&abs);
				save(&abs);
				break;
			case 3:
				deletePerson(&abs);
				save(&abs);
				break;
			case 4:
				cout << "��������Ҫ���ҵ���Ա��\n";
				findPerson(&abs);

				break;
			case 5:
				cout << "��������Ҫ�޸ĵ���Ա��\n";
				modify(&abs);
				save(&abs);
				break;
			case 6:
				cout << "��ȷ��Ҫ���ͨѶ¼��1��yes/2:no\n";
				cleanPerson(&abs);

				break;
		
			case 0:  cout << "��ӭ�´�ʹ�ã�" << endl;
				
				system("pause");
				return 0;
			default:
				cout << "�������󣡣���";
				system("pause");
				system("cls");
				break;
			}


		}


	}
	system("pause");
	return 0;
}