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
	bool bStop = false, bPlay=true, bPause=false, bNext=true, bNextMelody=false;
            public: 
            vector<Track> load() {
			    Track  melody; 
				vector<Track> melodyPlay;
			int countMelody = 0;
				ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
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
private:
 int numberMelody = TrackSize()-1, numM = 0, num = 0; 
public:
	 int next() {	
			 srand(time(nullptr));
			 numM = rand() % numberMelody + 1;
			 return numM;
		}

	 void nextMelody() {
		 if (bNextMelody == true) {
			 num = next();
			 cout << "\nСейчас звучит: ";
			 cout << PlayList[num].title << " " << PlayList[num].duration << " " << PlayList[num].dateCreation << "\n";
			 bStop = true;
			 bPause = true;
		 }
	 }

	 void play() {
		 if ((bPlay == true)&&(bNext==true)){
			 num = next();
			 cout << "\nСейчас звучит: ";
			 cout << PlayList[num].title << " " << PlayList[num].duration << " " << PlayList[num].dateCreation << "\n";
			 bPlay = false;
			 bStop = true;
			 bPause = true;
			 bNextMelody = true;
		 }
		 else if (bPlay == true) {
			 cout << "\nСейчас звучит: ";
			 cout << PlayList[num].title << " " << PlayList[num].duration << " " << PlayList[num].dateCreation << "\n";
			 bPlay = false;
			 bStop = true;
			 bPause = true;
			 bNextMelody = true;
		 }
}

		void pause() {
			if (bPause == true) {
				cout << "\nПауза.";
				bPause = false;
				bPlay = true;
				bNext = false;
				bNextMelody = false;
			}
		}

		 void stop() {
			 if (bStop == true) {
				 cout << "\nВоспроизведение остановлено.";
				 bStop = false;
				 bPlay = true;
				 bNext = true;
				 bNextMelody = false;
				 bPause = false;
			 } 
	 }

         void exit() {
			cout << "\nВыключение плеера.";
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
		ifstream file("C:\\Users\\Александр\\Documents\\text for program\\playerM.txt");
		if (file.is_open()) {
			cout << "\nЗагрузка мелодий.\n";
		}
		else {
			cerr << "\nThe file is not found. ";
			return 1;
		}	
		file.close();
	Player Song;
	while (strAct != "exit") {
		cin >> strAct;		
		if (strAct == "play") {
				Song.play();				
			}
		else if (strAct == "next"){
			Song.nextMelody();
		}
		else if (strAct == "pause") {
			Song.pause();
		}
		else if (strAct == "record") {
			Song.record();
		}
		else if (strAct == "stop"){
			Song.stop();			
		}
		else if (strAct == "exit") {
			Song.exit();
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
