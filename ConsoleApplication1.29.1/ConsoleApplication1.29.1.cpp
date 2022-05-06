// ConsoleApplication1.29.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 26. Задача 1. Реализация имитации аудиоплеера.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Player;

class Track {
	friend class Player;
		string title, duration, dateCreation;
public:
		void set_title(string strTitle) {
			title = strTitle;
		}

		void set_duration(string strDur) {
			duration = strDur;
		}

		void set_dateCreation(string strDate) {
			dateCreation = strDate;
		}

		string get_title() {
			return title;
		}

		string get_duration() {
			return duration;
		}

		string get_dateCreation() {
			return dateCreation;
		}
	//	vector<Track> melodyPlay; 
};                                                   
	                                               
class Player {
            public:
           static vector<Track> load(vector<Track> melodyPlay) {
			    Track  melody;          
			string str = "", str1 = "";
					int j = 0, count = 0;
				ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
					if (file.is_open()) {
						cout << "\nЗагрузка мелодий.\n";
					}
					else {
						cerr << "\nThe file is not found. ";
					}
				while (!file.eof()) {
					file >> str >> str1;           // строки str и str1 собирают
					melody.set_title(str);         //строку данных о мелодии
					melody.set_duration(str1);
					str = "";
					for (int l = 0; l < 6; l++) {
						str1 = "";
						file >> str1;
						str.append(str1);
						str.append(" ");
					}
					melody.set_dateCreation(str);
					str = ""; str1 = "";
					melodyPlay.push_back( melody);
					j++; 
				}
				file.close();
				for (int i = 0; i < j; i++) {
					cout << " " << melodyPlay[i].title << " " << melodyPlay[i].duration << " " << melodyPlay[i].dateCreation << "\n";
				}			
				return  melodyPlay;
		}

	static int TrackSize() {
		int count = 0;
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
		string str = "";
		if (file.is_open()) {

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

	 int  record(string commandRec) {
		if (commandRec == "record") {
			ofstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt", ios::app);
			if (file.is_open()) {
				cout << "\nФайл открыт для записи.";
			}
			else {
				cerr << "\nФайл не найден.";
				return 1;
			}
			string strTitle = "", strDur = "", strR = "";
			while (strR != "end") {
				cout << "\nВведите название мелодии.";
				cin >> strTitle;
				cout << "\nВведите продолжительность мелодии.";
				cin >> strDur;
				time_t t = time(0);
				char* loc = ctime(&t);
				file << strTitle << " " << strDur << " " << loc << ":" << "\n";
				cout << "\nДля продолжения записи нажмите любую клавишу, для прекращения - введите end.";
				strR = "";
				cin >> strR;
				if (strR == "end") {
					break;
				}
				strTitle = ""; strDur = "";
			}
		}
		return 0;
	}

	 void pause(string commandPaus) {
		static int countComPaus = 0;
		if (commandPaus == "pause") {
			if (countComPaus == 0) {
				cout << "\nПауза.";
				countComPaus++;
			}
		}
		else countComPaus = 0;
	}

         int next(){
static int numberMelody = Player::TrackSize();
			int numM = 0;
			srand(time(nullptr));
			numM = rand() % numberMelody + 1;
			return numM;
		}

	    void play(string commandPlay, vector<Track> PlayList){
		static int countPlay = 0, num=0;
		if((commandPlay=="next")||((commandPlay == "play")&&( countPlay == 0))){
			num = Player:: next();
			cout << "\nСейчас звучит: ";
			countPlay++;
			cout<< PlayList[num].title<<" "<< PlayList[num].duration<<" "<< PlayList[num].dateCreation << "\n";
	}
		if (commandPlay != "play") {
			countPlay = 0;
		}
}

		 void stop(string commandS) {
			static	int countComS = 0;
			if (commandS == "stop") {
				if (countComS == 0) {
					cout << "\nВоспроизведение остановлено.";
					countComS++;
				}
			}
				else countComS = 0;
	 }

         void exit(string commandEx) {
		     if (commandEx == "exit") {
			cout << "\nВыключение плеера.";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	string   strAct = "";
	cout << "\n                               АУДИОПЛЕЕР.";
	cout << "\nНастройки аудиоплеера: ";
	cout << "\n                       play - воспроизведение звукозаписи;";
	cout << "\n                       pause - пауза;";
	cout << "\n                       next - переход к следующей записи;";
	cout << "\n                       stop - прекращение воспроизведения;";
	cout << "\n                       record - запись;";
	cout << "\n                       exit - выключение плеера.";
	Player Song;
	 vector <Track> melodyPlay;
	vector<Track>PlayList = Player::load(melodyPlay);
	while (strAct != "exit") {
		cin >> strAct;
	Song.play(strAct, PlayList);
	Song.record(strAct);
	Song.pause(strAct);
    Song.stop(strAct);
	Song.exit(strAct);
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
