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
	
public:
		string title, duration, dateCreation;

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
		vector<Track> melodyPlay; //добавил
};                                                   
	                                               
class Player {
public:
static vector<Track> load(vector<Track> melodyPlay) {
			    Track  melody;          
           // vector<Track> melodyPlay;
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

	static int  record() {
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
		return 0;
	}

	static void exit() {
		cout << "\nВыключение плеера.";
	}

	static void pause(int count) {
		if (count == 0) {
			cout << "\nПауза.";
		}
	}
	static void play(int count, vector<Track>PlayList, int num) {
		if (count == 0){
			cout << "\nСейчас звучит: ";
			cout<< PlayList[num].title<<" "<< PlayList[num].duration<<" "<< PlayList[num].dateCreation << "\n";
	}
}

		static int next(int countMel) {
			int numM = 0;
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
	string   strAct = "", strP = "";
	int countPause = 0, countMel = 0, numMelody = 0, countStop = 0, countPlay = 0, countStr = 0, countRecord = 0, numberMelody=0;
	cout << "\n                               АУДИОПЛЕЕР.";
	cout << "\nНастройки аудиоплеера: ";	
	cout << "\n                       play - воспроизведение звукозаписи;";
	cout << "\n                       pause - пауза;";
	cout << "\n                       next - переход к следующей записи;";
	cout << "\n                       stop - прекращение воспроизведения;";
	cout << "\n                       record - запись;";
	cout << "\n                       exit - выключение плеера.";
	Track  melody;
	 vector <Track> melodyPlay;
	vector<Track>PlayList = Player::load(melodyPlay);
	numMelody = Player::TrackSize();
	while (strAct != "exit") {
		cin >> strAct;
		if (strAct != "pause") {
			countPause = 0;
		}
		if (strAct != "play"&&strAct!="pause") {
			countPlay = 0; 
		}
		if (strAct != "play") {
			countStr = 0;
		}	
			if (countRecord != 0) {				    
				vector<Track>PlayList = Player:: load(melodyPlay);
             numMelody = Player::TrackSize();
				countRecord=0;			
		}
		if (strAct == "record") {
			Player::record();
			countRecord++;
		}
		else if (strAct == "play" || strAct == "next") {
			if (countPlay == 0) {
                numberMelody = Player::next(numMelody); 
				}
				if (countStr == 0) {			
					Player::play( countPause, PlayList, numberMelody);
					countStop = 0; countPlay++;
					countStr++;
				}
			}
		else if (strAct == "pause") {
			Player::pause(countPause);
			countPause++;		
		}
		else if (strAct == "stop") {
			Player::stop (countStop);
			countStop++;
		}
		else if (strAct == "exit") {
			Player::exit();
			break;
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
