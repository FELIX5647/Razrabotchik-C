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
			cout << endl << "������� �������� ��������� �� ���������: ���� - ������� - ������ - ������ �� �������(������ enter): ";
			enter = _getch();
			cin >> TextPrioritet;
			if (TextPrioritet == "����") {
				Prior = 0;
			}
			else if (TextPrioritet == "�������") {
				Prior = 1;
			}
			else if (TextPrioritet == "������") {
				Prior = 2;
			}
			else if (enter == 13)
				Prior = p;
			else
				cout << "�� ���������� ���� ��������.\n";
		}
		YesOrNot = "";
		while (YesOrNot == "") {
			cout << "��������� ���� ���������(�� - ���): ";
			cin >> YesOrNot;
			if (YesOrNot == "��")
				exitPril = false;
			else if (YesOrNot == "���") {
				exitPril = true;
			}
			else {
				YesOrNot = "";
				cout << "�� ���������� ����" << endl;
			}
		}
	}
	FreeLibrary(load);
	return 0;
}