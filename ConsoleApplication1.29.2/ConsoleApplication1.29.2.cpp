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
	 vector<Contacts> load() {
		Contacts telephone;	
		vector <Contacts> subscriberList;
		int subscrNumber = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
		while (!file.eof()) {
            string strPhone = "", strSubscr = "", str="";           
			int strNumber = 0;
			file >> strNumber >> strPhone >> strSubscr>>str;
			telephone.set_serialNumber(strNumber);
			telephone.set_phoneNumber(strPhone);
			telephone.set_subscriber(strSubscr);
			subscriberList.push_back(telephone);
			subscrNumber++;
		}
		file.close();
		for (int i = 0; i < subscrNumber - 1; i++) {
			cout << " " << subscriberList[i].serialNumber << " " << subscriberList[i].phoneNumber << " " << subscriberList[i].subscriber << "\n";
		}
		return subscriberList;
	}

	 vector<Contacts>phoneBook =load();

	 int PhoneSize() {
		 int countLoad = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");		
		if (!file.is_open()) {
			cerr << "\nThe file is not found. ";
			return -1;
		}
		while (!file.eof()) {
            string str = "";
			file >> str;
			if (str == ";") {
				countLoad++;
			}
			str = "";
		}	
		file.close();
		return countLoad;
	}
	
	 int add() {
		  int countSubscr = Phone::PhoneSize();
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
			 file << countSubscr << " " << strNumber << " " << strName <<" "<<";"<< "\n";
			 strNumber = ""; strName = "";
		return 0;
	}

	 void call( int number) {	
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

	 void sms(int number) {
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

	 void exit() {		
			 cout << "\nВыключение телефона.";
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
	ifstream file("C:\\Users\\Александр\\Documents\\text for program\\phonebook.txt");
	if (file.is_open()) {
		cout << "\nЗагрузка телефона.\n";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
    file.close();
	string strAct = "";
	int numberSubscribers = 0;
	Phone telephone;
	numberSubscribers = telephone.PhoneSize();
	while (strAct != "exit") {
    cin >> strAct;
	if (strAct == "add") {
		telephone.add();
	}
	else if (strAct == "call") {
		telephone.call(numberSubscribers);
	}
	else if (strAct == "sms") {
		telephone.sms(numberSubscribers);
	}
	else if (strAct == "exit") {
		telephone.exit();
	}
  }	
	return 0;
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
