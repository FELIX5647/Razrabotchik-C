#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<thread>
#include<conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	HINSTANCE load;
	int Prior = 1;
	load = LoadLibrary(L"InitMessage.dll");
	typedef int (*Log)(string, int);
	Log IntMessage = (Log)GetProcAddress(load, "Message");

	string NameLog = "Log.txt", TextPrioritet, YesOrNot;
	bool exitPril = true;
	while (exitPril == true) { 
		IntMessage(NameLog, Prior); 
		int p = Prior, enter = 0; 
		Prior = -1;
		while (Prior == -1) {
			cout << endl << "Введите важность сообщения по умолчанию: Спам - Обычное - Важное - Ничего не вводить(нажать enter): ";
			enter = _getch();
			cin >> TextPrioritet;
			if (TextPrioritet == "Спам") {
				Prior = 0;
			}
			else if (TextPrioritet == "Обычное") {
				Prior = 1;
			}
			else if (TextPrioritet == "Важное") {
				Prior = 2;
			}
			else if (enter == 13)
				Prior = p;
			else
				cout << "Не корректный ввод важности.\n";
		}
		YesOrNot = "";
		while (YesOrNot == "") {
			cout << "Закончить ввод сообщений(Да - Нет): ";
			cin >> YesOrNot;
			if (YesOrNot == "Да")
				exitPril = false;
			else if (YesOrNot == "Нет") {
				exitPril = true;
			}
			else {
				YesOrNot = "";
				cout << "Не корректный ввод" << endl;
			}
		}
	}
	FreeLibrary(load);
	return 0;
}