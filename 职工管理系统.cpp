#include<iostream>
#include "workManager.h"
#include  "boss.h"
#include "manager.h"
#include "employee.h"
//#include "worker.h"
using namespace std;
int main() {
	//WORKER* worker = NULL;
	//worker = new employee(1, "����", 1);
	//worker->showINfor();
	//delete worker;
	//worker = new manager(2, "����", 2);
	//worker->showINfor();
	//delete worker;
	//worker = new boss(3, "�ϻ�", 3);
	//worker->showINfor();
	//delete worker;
	workManager vm;
	int choice = 0;
	while (true) {
		vm.MenuShow();
		cout << "������ѡ�" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			vm.ExitSystem();
			break;

		case 2:
		vm.Add_Emp();

			break;
		case 3:
			vm.show_Emp();
			break;
		case 4:
			vm.del_Emp();


			break;
		case 5:
			vm.modify();

			break;
		case 6:
			vm.findEmp();

			break;


		default:
			system("pause");
			system("cls");

		}
	}
	
		system("pause");
		return 0;
	
}