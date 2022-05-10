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
};                                                   
	                                               
class Player {
            public: 
            vector<Track> load() {
			    Track  melody; 
				vector<Track> melodyPlay;
			int countMelody = 0;
				ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
				if (file.is_open()) {
					cout << "\nЗагрузка мелодий.\n";
				}
				else {
					cerr << "\nThe file is not found. ";
				}
				while (!file.eof()) {
                    string str = "", str1 = "";
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
					countMelody++; 
				}
				
				file.close();
				for (int i = 0; i < countMelody; i++) {
					cout << " " << melodyPlay[i].title << " " << melodyPlay[i].duration << " " << melodyPlay[i].dateCreation << "\n";
				}			
				return  melodyPlay;
		}

             vector<Track> PlayList= load();

	 int TrackSize() {
		int count = 0;
	ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
		string str = "";
		if (!file.is_open()) {
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

	 int  record() {
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

 int next(int numberMelody){
			int numM = 0;
			cout << numberMelody;
			srand(time(nullptr));
			numM = rand() % numberMelody + 1;
			return numM;
		}

	    void play(int num){
			cout << "\nСейчас звучит: ";		
			cout<< PlayList[num].title<<" "<< PlayList[num].duration<<" "<< PlayList[num].dateCreation << "\n";
}

		void pause() {
			cout << "\nПауза.";
		}

		 void stop() {
					cout << "\nВоспроизведение остановлено.";
	 }

         void exit() {
			cout << "\nВыключение плеера.";
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	string   strAct = "";
	int numMelody = 0, anotherMelody = 0;
	bool bPlay=true, bStop=false, bNext=false, bPause=false;
	cout << "\n                               АУДИОПЛЕЕР.";
	cout << "\nНастройки аудиоплеера: ";
	cout << "\n                       play - воспроизведение звукозаписи;";
	cout << "\n                       pause - пауза;";
	cout << "\n                       next - переход к следующей записи;";
	cout << "\n                       stop - прекращение воспроизведения;";
	cout << "\n                       record - запись;";
	cout << "\n                       exit - выключение плеера.";
	Player Song;
	numMelody =Song.TrackSize()-1;
	while (strAct != "exit") {
		cin >> strAct;		
		if ((strAct == "play") && (bPlay == true)) {
			if (bPause == true) {
				anotherMelody = Song.next(numMelody);
				Song.play(anotherMelody);
				bPlay = false;
			}
			else if (bPause ==false) {
				Song.play(anotherMelody);	
				bPlay = false;
			}
			bPause = true;
		}
		else if ((strAct == "next") && (bNext == true)) {
			anotherMelody = Song.next(numMelody);
			Song.play(anotherMelody);
		}
		else if ((strAct == "pause")&&(bPause==true)) {
			Song.pause();
			bPause=false;
		}
		else if (strAct == "record") {
			Song.record();
			numMelody = Song.TrackSize();
		}
		else if ((strAct == "stop")&&(bStop==true)) {
			Song.stop();
			bNext = false;
		}
		else if (strAct == "exit") {
			Song.exit();
		}
if ((strAct == "play")||(strAct == "next")) {
			bStop = true;
			bPause = true;
			bNext = true;
		}
		if ((strAct=="stop")||(strAct=="pause")) {
			bPlay = true;
			bStop = false;
		}
if (strAct == "pause") {
			bPlay = true;
			bPause = false;
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
