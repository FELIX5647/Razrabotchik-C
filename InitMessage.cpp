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
		cout << "�� �������� ������� ������";
	else {
		char TextMessage[200];
		string TextPrioritet;
		int p = Prioritet, PrioritetVvod = -1, enter = 0;
		cout << "������� ���������: ";
		cin.getline(TextMessage, 200);
		while(PrioritetVvod == -1){
			cout << endl << "������� �������� ���������: ���� - ������� - ������ - ������ �� �������(������ enter): ";
			enter = _getch();
			if (enter != 13) {
				cin >> TextPrioritet;
			}
			if (TextPrioritet == "����") {
				PrioritetVvod = 0;
			}
			else if (TextPrioritet == "�������") {
				PrioritetVvod = 1;
			}
			else if (TextPrioritet == "������") {
				PrioritetVvod = 2;
			}
			else if (enter == 13)
				PrioritetVvod = Prioritet;
			else
				cout << "�� ���������� ���� ��������.\n";
		}
		SYSTEMTIME now;
		GetLocalTime(&now);
		int minute = now.wMinute, hour = now.wHour;

		if (Prioritet <= PrioritetVvod && minute > 9) {
			fout << TextMessage << "\n��������: " << TextPrioritet << ". �����: " << hour << ":" << minute << endl;
		}
		else if(Prioritet <= PrioritetVvod && now.wMinute <= 9){
			fout << TextMessage << "\n��������: " << TextPrioritet << ". �����: " << hour << ":0" << minute << endl;
		}
		else {
			cout << "������ �������� ��������� � ������";
		}
	}

	fout.close();

	return;
}