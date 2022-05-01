// ConsoleApplication1.29.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 26. Задача 2. Реализация программы симуляции мобильного телефона.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h> 
using namespace std;

class Phone {
	string subscriber, phoneNumber;
public:;
	void set_subscriber(string name) {
		subscriber = name;
	}

	void set_phoneNumber(string number) {
		phoneNumber = number;
	}

	string get_subscriber() {
		return subscriber;
	}

	string get_phoneNumber() {
		return phoneNumber;
	}

	static vector<Phone> load() {
		Phone  telephone;
		vector <Phone> subscriberList;
		string str = "", str1 = "";
		int j = 0, count = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");

		if (file.is_open()) {
			cout << "\nЗагрузка телефона.\n";
		}
		else {
			cerr << "\nThe file is not found. ";
		}
		while (!file.eof()) {
			file >> str >> str1;
			telephone.set_phoneNumber(str);
			telephone.set_subscriber(str1);
			subscriberList.push_back(telephone);
			j++;
		}
		file.close();
		for (int i = 0; i < j - 1; i++) {
			cout << " " << subscriberList[i].phoneNumber << " " << subscriberList[i].subscriber << "\n";
		}
		return subscriberList;
	}
	static int add() {
		ofstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt", ios::app);
		if (file.is_open()) {
			cout << "\nФайл открыт для записи.";
		}
		else {
			cerr << "\nФайл не найден.";
			return 1;
		}
		string strNumber = "", strName = "";
			cout << "\nТелефон абонента: ";
			cin >> strNumber;
			cout << "\nИмя абонента: ";
			cin >> strName;
			file << strNumber << " " << strName << "\n";
            strNumber = ""; strName = "";
		return 0;
	}

	static void call() {
		string telNumber = "";
		int interval = 0;
		cout << "\nВведите номер абонента ";
		cin >> telNumber;
		time_t  start = time(nullptr);
		time_t t = 15 + start;
		do {
			time_t start= time(nullptr);
			Beep(750, 2250);
			Sleep(1500);
			if (start > t) {
				cout << "\nВам обязательно ответят!";
				break;
			}
		} while (t > start);
	}

	static void sms() {
		string telNumber = "", message = "";
		cout << "\nВведите номер телефона.";
		cin >> telNumber;
		cout << "\nВведите сообщение.";
		cin >> message;
		cout << "\nотправка сообщения...";
		Sleep(3000);
		cout << "\nВаше сообщение отправлено.";
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	cout << "                               Телефон.\n";
	cout << "Настройки телефона: \n";
	cout << "                      on - включить телефон;\n";
	cout << "                      add -  добавить в телефон абонента;\n";
	cout << "                      call - вызов абонента;\n";
	cout << "                      sms - отпавка sms-сообщений;\n";
	cout << "                      exit - выходиз программы;\n";
	string strAct = "";
	int countLoad = 0;
	while (strAct != "exit") {
cin >> strAct;
		if (strAct == "on") {
			if (countLoad == 0) {
				Phone::load();
				countLoad++;
			}
		}
		else if (strAct == "add") {
			Phone::add();
		}
		else if (strAct == "call") {
			Phone::call();
		}
		else if (strAct == "sms") {
			Phone::sms();
		}
		else if (strAct == "exit") {
			break;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
