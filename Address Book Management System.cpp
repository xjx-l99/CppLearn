#include <iostream>
using namespace std;
#define MAX 1000

// �˵�ҳ��
void showMenu() {
	cout << "---------------------------" << endl;
	cout << "|      1�������ϵ��      |" << endl;
	cout << "|      2����ʾ��ϵ��      |" << endl;
	cout << "|      3��ɾ����ϵ��      |" << endl;
	cout << "|      4��������ϵ��      |" << endl;
	cout << "|      5���޸���ϵ��      |" << endl;
	cout << "|      6�������ϵ��      |" << endl;
	cout << "|      0���˳�ͨѶ¼      |" << endl;
	cout << "---------------------------" << endl;
}

// �����ϵ��
// ��ϵ�˽ṹ��
struct person {
	string name;
	int sex;
	int age;
	string phone;
	string Addr;
};
// ͨѶ¼�ṹ��
struct addressBooks {
	struct person personArr[MAX];
	int person_num;
};

void addPerson(addressBooks* abs) {
	if (abs->person_num == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArr[abs->person_num].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		while (true) {
			cin.clear();
			cin.ignore(1024, '\n');
			cin >> sex;
			if (sex == 1 || sex == 2) {
				// ָ���ڲ��Ľṹ�������.������
				abs->personArr[abs->person_num].sex = sex;
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArr[abs->person_num].age = age;

		string phone;
		cout << "�������ֻ�����" << endl;
		cin >> phone;
		abs->personArr[abs->person_num].phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArr[abs->person_num].Addr = address;

		abs->person_num++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(addressBooks* abs) {
	if (abs->person_num == 0) {
		cout << "��ͨѶ��" << endl;
	}
	else {
		for (int i = 0; i < abs->person_num; i++) {
			cout << "������" << abs->personArr[i].name << "\t";
			if (abs->personArr[i].sex == 1) {
				cout << "�Ա���" << "\t";
			}
			else {
				cout << "�Ա�Ů" << "\t";
			}
			cout << "���䣺" << abs->personArr[i].age << "\t";
			cout << "�ֻ����룺" << abs->personArr[i].phone << "\t";
			cout << "��ַ��" << abs->personArr[i].Addr << endl;
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
	//cout << "�޴���ϵ��" << endl;
	return -1;
	system("pause");
	system("cls");
}

void delPerson(addressBooks* abs) {
	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->person_num; i++) {
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->person_num--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(addressBooks* abs) {
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArr[ret].name << "\t";
		if (abs->personArr[ret].sex == 1) {
			cout << "�Ա���" << "\t";
		}
		else {
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->personArr[ret].age << "\t";
		cout << "�ֻ����룺" << abs->personArr[ret].phone << "\t";
		cout << "��ַ��" << abs->personArr[ret].Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(addressBooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = searchPeson(abs, name);
	if (ret != -1) {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArr[ret].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				// ָ���ڲ��Ľṹ�������.������
				abs->personArr[ret].sex = sex;
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArr[ret].age = age;

		string phone;
		cout << "�������ֻ�����" << endl;
		cin >> phone;
		abs->personArr[ret].phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArr[ret].Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void QingkongPerson(addressBooks* abs) {
	int y;
	cout << "��ȷ���Ƿ���գ���ȷ��������1�� " << endl;
	cin >> y;
	if (y == 1) {
		abs->person_num = 0;
		cout << "��ճɹ�" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}