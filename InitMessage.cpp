#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
extern "C" __declspec(dllexport) void Message(string NameLog, int Prioritet) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout;
	fout.open(NameLog, ios::app);

	if (!fout.is_open())
		cout << "Не удалость открыть журнал";
	else {
		char TextMessage[200];
		string TextPrioritet;
		int p = Prioritet, PrioritetVvod = -1, enter = 0;
		cout << "Введите сообщение: ";
		cin.getline(TextMessage, 200);
		while(PrioritetVvod == -1){
			cout << endl << "Введите важность сообщения: Спам - Обычное - Важное - Ничего не вводить(нажать enter): ";
			enter = _getch();
			if (enter != 13) {
				cin >> TextPrioritet;
			}
			if (TextPrioritet == "Спам") {
				PrioritetVvod = 0;
			}
			else if (TextPrioritet == "Обычное") {
				PrioritetVvod = 1;
			}
			else if (TextPrioritet == "Важное") {
				PrioritetVvod = 2;
			}
			else if (enter == 13)
				PrioritetVvod = Prioritet;
			else
				cout << "Не корректный ввод важности.\n";
		}
		SYSTEMTIME now;
		GetLocalTime(&now);
		int minute = now.wMinute, hour = now.wHour;

		if (Prioritet <= PrioritetVvod && minute > 9) {
			fout << TextMessage << "\nВажность: " << TextPrioritet << ". Время: " << hour << ":" << minute << endl;
		}
		else if(Prioritet <= PrioritetVvod && now.wMinute <= 9){
			fout << TextMessage << "\nВажность: " << TextPrioritet << ". Время: " << hour << ":0" << minute << endl;
		}
		else {
			cout << "Ошибка отправки сообщения в журнал";
		}
	}

	fout.close();

	return;
}