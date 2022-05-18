// ConsoleApplication1.29.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 26. Задача 3. Реализация программы управления окном рабочего стола.

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class MonitorControl;

class Window {
	friend class MonitorControl;
	int anchСoordinateX, anchCoordinateY, widthDisplay, heightDisplay;
public:
	 void set_anchСoordinate(int x, int y) {
		 anchСoordinateX = x;
		 anchCoordinateY = y;
	}

	void set_widthDisplay(int widthD) {
		widthDisplay = widthD;
	}

	void set_heightDisplay(int heightD) {
		heightDisplay = heightD;
	}

	int get_coordinateX() {
		return anchСoordinateX;
	}

	int get_coordinateY() {
		return anchCoordinateY;
	}

	 int get_widthDisplay() {
		return  widthDisplay;
	}

	 int get_heightDisplay() {
		return heightDisplay;
    }
};

class MonitorControl {
	int abs = 0, ord = 0, wWidth = 0, wHeight = 0;
	public:
		void resize() {
			Window window;
			vector<Window>windows;
			int w = 0, h = 0;
			do {
				cout << "\nУкажите ширину окна.";
				cin >> w;
				cout << "\nУкажите высоту окна.";
				cin >> h;
				if (w < 0 || h < 0) {
					cout << "\nУкажите правильно размеры окна.";
				}
			} while (w < 0 || h < 0);
			window.set_widthDisplay(w);
			window.set_heightDisplay(h);
			wWidth = window.get_widthDisplay();
			wHeight = window.get_heightDisplay();
			cout << "\nРазмер окна: " << window.get_widthDisplay() << "X" << window.get_heightDisplay();
		}

		void move() {
		Window window;
		int X = 0, Y = 0;		
		do {
			cout << "\nУкажите абсциссу точки привязки.";
			cin >> X;
			cout << "\nУкажите ординату точки привязки.";
			cin >> Y;
			window.set_anchСoordinate(X, Y);
			if (X < 1 || X + wWidth > 79 || Y < 1 || Y + wHeight > 49) {
				cout << "\nЗадайте правильно координаты.";
			}
		} while (X < 0 || X + wWidth  > 79 || Y < 0 || Y + wHeight>49);
		abs= window.get_coordinateX();
		ord= window.get_coordinateY();
	}
	
	void showDisplay() {
				int numberRow = 50, numberCol = 80;
				for (int row = 0; row < numberRow; row++) {
					for (int col = 0; col < numberCol; col++) {
						if (row == 0 || row == numberRow - 1) {
							cout << "-";
						}
						else if (col == 0 || col == numberCol - 1) {
							cout << "|";
						}
						else if (row >= ord && row < ord + wHeight && col >= abs && col < abs + wWidth) {
							cout << "1";
						}
						else {
							cout << "0";
						}
						if (col == numberCol - 1) {
							cout << "\n";
						}
					}
				}
			}

 void close() {
		cout << "\nВыключение монитора.";
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\nКоманды программы:";
	cout << "\n                   move - перемещение вектора на заданные координаты;";
	cout << "\n                   resize - ввод размера окна;";
	cout << "\n                   display - вывод текущего изображения монитора;";
	cout << "\n                   close - выход из программы;\n";
MonitorControl control;
string command = "";
	cout<<"\nСоздание окна.\n";
	control.showDisplay();  
	while(command!="close"){
		cout << "\nВведите коменду.";
		cin >> command;
		if (command == "display") {
			control.showDisplay(); 
		}
		else if (command == "move") {
			control.move();
		}
		else if (command == "resize") {
			control.resize();
		}
		else if (command == "close") {
			control.close();
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
