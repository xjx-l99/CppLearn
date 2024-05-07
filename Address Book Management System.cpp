#include <iostream>
using namespace std;
#define MAX 1000

// 菜单页面
void showMenu() {
	cout << "---------------------------" << endl;
	cout << "|      1、添加联系人      |" << endl;
	cout << "|      2、显示联系人      |" << endl;
	cout << "|      3、删除联系人      |" << endl;
	cout << "|      4、查找联系人      |" << endl;
	cout << "|      5、修改联系人      |" << endl;
	cout << "|      6、清空联系人      |" << endl;
	cout << "|      0、退出通讯录      |" << endl;
	cout << "---------------------------" << endl;
}

// 添加联系人
// 联系人结构体
struct person {
	string name;
	int sex;
	int age;
	string phone;
	string Addr;
};
// 通讯录结构体
struct addressBooks {
	struct person personArr[MAX];
	int person_num;
};

void addPerson(addressBooks* abs) {
	if (abs->person_num == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArr[abs->person_num].name = name;

		int sex;
		cout << "请输入性别" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		while (true) {
			cin.clear();
			cin.ignore(1024, '\n');
			cin >> sex;
			if (sex == 1 || sex == 2) {
				// 指针内部的结构体可以用.来访问
				abs->personArr[abs->person_num].sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArr[abs->person_num].age = age;

		string phone;
		cout << "请输入手机号码" << endl;
		cin >> phone;
		abs->personArr[abs->person_num].phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArr[abs->person_num].Addr = address;

		abs->person_num++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(addressBooks* abs) {
	if (abs->person_num == 0) {
		cout << "无通讯人" << endl;
	}
	else {
		for (int i = 0; i < abs->person_num; i++) {
			cout << "姓名：" << abs->personArr[i].name << "\t";
			if (abs->personArr[i].sex == 1) {
				cout << "性别：男" << "\t";
			}
			else {
				cout << "性别：女" << "\t";
			}
			cout << "年龄：" << abs->personArr[i].age << "\t";
			cout << "手机号码：" << abs->personArr[i].phone << "\t";
			cout << "地址：" << abs->personArr[i].Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int searchPeson(addressBooks* abs, string name) {
	for (int i = 0; i < abs->person_num; i++) {
		if (abs->personArr[i].name == name) {
			return i;
		}
	}
	//cout << "无此联系人" << endl;
	return -1;
	system("pause");
	system("cls");
}

void delPerson(addressBooks* abs) {
	cout << "请输入要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->person_num; i++) {
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->person_num--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(addressBooks* abs) {
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArr[ret].name << "\t";
		if (abs->personArr[ret].sex == 1) {
			cout << "性别：男" << "\t";
		}
		else {
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->personArr[ret].age << "\t";
		cout << "手机号码：" << abs->personArr[ret].phone << "\t";
		cout << "地址：" << abs->personArr[ret].Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(addressBooks* abs) {
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArr[ret].name = name;

		int sex;
		cout << "请输入性别" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				// 指针内部的结构体可以用.来访问
				abs->personArr[ret].sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArr[ret].age = age;

		string phone;
		cout << "请输入手机号码" << endl;
		cin >> phone;
		abs->personArr[ret].phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArr[ret].Addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void QingkongPerson(addressBooks* abs) {
	int y;
	cout << "请确认是否清空？（确认请输入1） " << endl;
	cin >> y;
	if (y == 1) {
		abs->person_num = 0;
		cout << "清空成功" << endl;
	}
	else {
		return;
	}

	system("pause");
	system("cls");
}

int main() {
	addressBooks abs;
	abs.person_num = 0;
	int select = 0;

	while (true) {

		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			delPerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			changePerson(&abs);
			break;
		case 6:
			QingkongPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}