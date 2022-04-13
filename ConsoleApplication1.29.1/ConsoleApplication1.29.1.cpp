// ConsoleApplication1.29.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 26. Задача 1. Реализация имитации аудиоплеера.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Player;

class Track {
	friend int record(Track melody[1000]);
public:
		static int load() {
			ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
			string str = "", str1 = "";
			int j = 0, count = 0;		
			if (file.is_open()) {
				cout << "\nЗагрузка мелодий.\n";
			}
			else {
				cerr << "\nThe file is not found. ";
				return -1;
			}
			while (!file.eof()) {				
				file >> melody[j].title >> melody[j].duration;
				str1 = "";
				for (int l = 0; l < 6; l++) {
					str1 = "";
					file >> str1;
					str.append(str1);
					str.append(" ");
				}
				melody[j].dateCreation = str;
				str = "";
				str1 = "";
				cout << melody[j].title << " " << melody[j].duration << " " << melody[j].dateCreation << "\n";
				j++; 
			}
	file.close();	
		}
string title, dateCreation, duration;
}
melody[1000];

class Player {
static int TrackSize() {
		int count = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt"); 
	    string str = "";
		if (file.is_open()) {
			cout << "\nСейчас звучит:";
		}
		else {
			cerr << "\nThe file is not found. ";

			return -1;
		}
		while (!file.eof()) {
			file >> str;
			if (str == ":") {
				count++;
			}		
			str = "";
		}
		file.close();
	return count;
	}
public:
	static int  record(Track melody[1000]) {
ofstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt", ios::app);	
int count = 0;
			string str = "";
			if (file.is_open()) {
				cout << "\nФайл открыт для записи.";
			}
			else {
				cerr << "\nФайл не найден.";
				return 1;
			}
		string strTitle="", strDur="", strR="";
		while (strR != "end") {
			cout << "\nВведите название мелодии.";
			cin >> strTitle;
			cout << "\nВведите продолжительность мелодии.";
			cin >> strDur;
			melody[count].title = strTitle;
			melody[count].duration = strDur;
			time_t t = time(0);
			char* loc = ctime(&t);
			melody[count].dateCreation = loc;
file << strTitle << " " << strDur << " " << loc << ":" << "\n";
			count++;
			cout << "\nДля продолжения записи нажмите любую клавишу, для прекращения - введите end.";
			strR = "";
			cin >> strR;
			if (strR == "end") {
				break;
			}
			strTitle = ""; strDur = "";
		}		
return 0;
};

	static void exit() {
	cout << "\nВыключение плеера.";
}

static void pause (int count) {
	if (count == 0) {
		cout << "\nПауза.";
	}
}

	static void play(int count, string strP, int counter) {
		if (strP != "pause") {
			if (count == 0) {
				int numMelody = 0;
				cout << "\n" << melody[counter - 1].title << " " << melody[counter - 1].duration << " " << melody[counter - 1].dateCreation;
			}
			else if (count != 0) {
				cout << "\n" << melody[counter - 1].title << " " << melody[counter - 1].duration << " " << melody[counter - 1].dateCreation;
			}
		}
	}

   static int next() {
		int countMel = 0, numM = 0;
		countMel = TrackSize();
		srand(time(nullptr));
		numM = rand() % countMel + 1;
		return numM;
    }

   static void stop(int count) {
		if (count == 0) {
			cout << "\nВоспроизведение остановлено.";
		}
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
	string str4 = "", str5="", strAct="", strP="";
	int countPause=0, countMel=0, numMelody = 0, countS=0;
	cout << "\n                               АУДИОПЛЕЕР.";
	cout << "\nНастройки аудиоплеера: ";
	cout << "\n                       on   - включение аудиоплеера;";
	cout << "\n                       play - воспроизведение звукозаписи;";
	cout << "\n                       pause - пауза;";
	cout << "\n                       next - переход к следующей записи;";
	cout << "\n                       stop - прекращение воспроизведения;";
	cout << "\n                       record - запись;";
	cout << "\n                       exit - выключение плеера.";
	while (strAct != "exit") {
		cin >> strAct;
		if (strAct == "on") {
			Track::load();
		}
		if (strAct == "record") {
			Player::record(melody);
		}
		else if (strAct == "play"|| strAct == "next") {
			if (countPause == 0) {
				numMelody = Player::next();
			}
			Player::play(countPause, strAct, numMelody);
			countS = 0;
		}
		else if (strAct == "pause") {
			Player::pause(countPause);
			countPause++;		
		}
		else if (strAct == "stop") {
			Player::stop (countS);
			countS++;
		}
		else if (strAct == "exit") {
			Player::exit();
			break;
		}
       if (strAct != "pause" && countPause > 0) {
			countPause = 0;
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
