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
using namespace std;

class Phone;

class Contacts {
	friend class Phone;

string subscriber="", phoneNumber="";
int serialNumber=0;
public:
void set_serialNumber(int number) {
	serialNumber = number;
}

	void set_subscriber(string name) {
		subscriber = name;
	}

	void set_phoneNumber(string number) {
		phoneNumber = number;
	}

	int get_serialNumber() {
		return serialNumber;
	}
	string get_subscriber() {
		return subscriber;
	}

	string get_phoneNumber() {
		return phoneNumber;
	}
};


class Phone {
public:
	static vector<Contacts> load(vector <Contacts> subscriberList) {
		Contacts telephone;
		string str = "", str1 = "";
		int j = 0, strNumber = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
		if (file.is_open()) {
			cout << "\nЗагрузка телефона.\n";
		}
		else {
			cerr << "\nThe file is not found. ";
		}
		while (!file.eof()) {
			file >> strNumber >> str >> str1;
			telephone.set_serialNumber(strNumber);
			telephone.set_phoneNumber(str);
			telephone.set_subscriber(str1);
			subscriberList.push_back(telephone);
			j++;
		}
		file.close();
		for (int i = 0; i < j - 1; i++) {
			cout << " " << subscriberList[i].serialNumber << " " << subscriberList[i].phoneNumber << " " << subscriberList[i].subscriber << "\n";
		}
		return subscriberList;
	}

	static int PhoneSize() {
		static int countLoad = 0;
		vector<Contacts>phoneBook;
		countLoad = phoneBook.size();
		return countLoad;
	}
	
	 int add(string strAdd) {
		 static int countSubscr = Phone::PhoneSize();
		 if (strAdd == "add") {
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
			 file << countSubscr << " " << strNumber << " " << strName << "\n";
			 strNumber = ""; strName = "";
		 }
		return 0;
	}

	 void call(string strNumber, vector<Contacts>phoneBook) {
		 if (strNumber == "call") {
			 static int number = Phone::PhoneSize();
			 int telNumber = 0;
			 int interval = 0;
			 cout << "\nВведите номер абонента.";
			 cout << "\nДля вызова абонента из телефонного справочника введите порядковый номер ";
			 cin >> telNumber;
			 if (telNumber <= number) {
				 cout << "\nВызов абонента: " << phoneBook[telNumber - 1].phoneNumber << " " << phoneBook[telNumber - 1].subscriber << "\n";
			 }
			 time_t  start = time(nullptr);
			 time_t t = 3 + start;
			 do {
				 time_t st = time(nullptr);
				 cout << '\a';
				 if (st > t) {
					 cout << "\nВам обязательно ответят!";
					 break;
				 }
			 } while (true);
		 }
	}

	 void sms(string strSms, vector<Contacts>phoneBook) {
		 if (strSms == "sms") {
			 static int number = Phone::PhoneSize();
			 string message = "";
			 int telNumber = 0;
			 cout << "\nВведите номер телефона.";
			 cout << "\nДля отправки сообщения абоненту из телефонного справочника введите порядковый номер ";
			 cin >> telNumber;
			 cout << "\nВведите сообщение.";
			 cin >> message;
			 if (telNumber <= number) {
				 cout << "\n Абонент " << phoneBook[telNumber - 1].phoneNumber << " " << phoneBook[telNumber - 1].subscriber << "\n";
			 }
			 time_t  start = time(nullptr);
			 time_t t = 3 + start;
			 cout << "\nотправка сообщения...";
			 do {
				 time_t st = time(nullptr);
				 cout << '\a';
				 if (st > t) {
					 cout << "\nВаше сообщение отправлено.";
					 break;
				 }
			 } while (true);
		 }
	 }

	 void exit(string strEx) {
		 if (strEx == "exit") {
			 cout << "\nВыключение телефона.";
		 }
	 }
};

int main() {
	setlocale(LC_ALL, "rus");
	cout << "                               Телефон.\n";
	cout << "Настройки телефона: \n";
	cout << "                      add -  добавить в телефон абонента;\n";
	cout << "                      call - вызов абонента;\n";
	cout << "                      sms - отпавка sms-сообщений;\n";
	cout << "                      exit - выходиз программы;\n";
	string strAct = "";
	Contacts contact;
	Phone telephone;
	vector<Contacts>subscriberList;
	vector<Contacts>phoneBook =Phone:: load(subscriberList);
	while (strAct != "exit") {
    cin >> strAct;
	        telephone.add(strAct);
			telephone.call(strAct, phoneBook);
			telephone.sms(strAct, phoneBook);
			telephone.exit(strAct);
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
