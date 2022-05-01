// ConsoleApplication1.29.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 26. Задача 3. Реализация программы управления окном рабочего стола.


#include <iostream>
#include <locale.h>
#include <string>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Display {
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

	static void resize(int *ww, int *wh) {
		Display monitor;
		int w=0, h=0;
		do {
			cout << "\nУкажите ширину окна.";
			cin >> w;
			cout << "\nУкажите высоту окна.";
			cin >> h;
			if (w < 0 || h < 0) {
				cout << "\nУкажите правильно размеры окна.";
			}
		} 		while (w < 0 || h < 0);	
		monitor.set_widthDisplay(w);
		monitor.set_heightDisplay(h);
		(*ww)= monitor.get_widthDisplay();
		(*wh)= monitor.get_heightDisplay();
		cout << "\nРазмер окна: " << monitor.get_widthDisplay() << "X" <<monitor.get_heightDisplay() ;
	}

	static void move(int* wx, int* wy, int& W, int& H) {
		Display monitor;
		int X = 0, Y = 0;
		do {
			cout << "\nУкажите абсциссу точки привязки.";
			cin >> X;
			cout << "\nУкажите ординату точки привязки.";
			cin >> Y;
			monitor.set_anchСoordinate(X, Y);				
			if (X < 1 || X + W > 79 || Y < 1 || Y + H > 49) {
				cout << "\nЗадайте правильно координаты.";
			}
		} while (X < 0 || X + W > 79 || Y < 0 || Y + H>49);
		(*wx) = monitor.get_coordinateX();
		(*wy) = monitor.get_coordinateY();
	}

		static void showDisplay(int &wX, int &wY, int &wW, int &wH){
		for(int row=0;row<50;row++){
		for (int col = 0; col < 80; col++) {
 if (row==0||row==49){
				cout << "-";
		}
 else if (col == 0 || col == 79) {
				cout << "|";
			}
else if (row >= wY && row < wY+wH && col>=wX && col < wX+wW) {
		cout << "1";
}
else  {
	cout << "0";
}
if (col == 79) {
				cout << "\n";
			}
		  }
       }
	}

	static void close() {
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
	string command = "";
	int abs = 0, ord = 0, wWidth=0, wHeight=0;	
     Display::resize(&wWidth, &wHeight);
     Display::move(&abs, &ord, wWidth, wHeight);	
	while(command!="close"){
		cout << "\nВведите коменду.";
		cin >> command;
		if (command == "display") {
			Display:: showDisplay(abs, ord, wWidth, wHeight);
		}
		else if (command == "move") {
			Display::move(&abs, &ord, wWidth, wHeight);
		}
		else if (command == "resize") {
			Display::resize(&wWidth, &wHeight);
		}
		else if (command == "close") {
			Display::close();
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
