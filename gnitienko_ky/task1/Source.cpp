#include <stdio.h>
#include <math.h>
#include <io.h>
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

class Time {
	time_t hours, UserHours, buffHours;
	time_t minutes, UserMinutes, buffMinutes;
	time_t seconds, UserSeconds, buffSeconds;
public:
	Time() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hours = ltm->tm_hour;
		minutes = ltm->tm_min;
		seconds = ltm->tm_sec;
	}
	void EnterTime(int a, int b, int c) {
		UserHours = a;
		UserMinutes = b;
		UserSeconds = c;
	}
	void Print1() {
		cout << "������� �����: " << hours << ":" << minutes << ":" << seconds << endl;
	}
	void Print2() {
		cout << "���������������� �����: " << UserHours << ":" << UserMinutes << ":" << UserSeconds << endl;
	}
	void Enter() {
		cout << "������� �����, �� ������� ����� �������� �������" << endl;
		cout << "����: ";
		cin >> buffHours;
		cout << "������: ";
		cin >> buffMinutes;
		cout << "�������: ";
		cin >> buffSeconds;
	}
	void Difference() {
		cout << "������� ����� ������� � ���������������� ��������: " << abs(hours - UserHours) << ":" << abs(minutes - UserMinutes) << ":" << abs(seconds - UserSeconds) << endl;
	}
	void PlusTime() {
		int hour, minute, sec;
		int buffHours1 = buffHours, buffMinutes1 = buffMinutes, buffSeconds1 = buffSeconds;
		if (buffSeconds1 / 60 > 0)  buffMinutes1 += (buffSeconds1 / 60);
		if ((buffSeconds1 % 60) + seconds > 60) buffMinutes1++;
		if (buffMinutes1 / 60 > 0)  buffHours1 += (buffMinutes1 / 60);
		if ((buffMinutes1 % 60) + minutes > 60) buffHours1++;
		while (((hours + buffHours1) % 24 <= 24) && ((hours + buffHours1) % 24 >= 0)) { hour = hours + buffHours1; buffHours1 -= 24; }
		while (((minutes + buffMinutes1) % 60 <= 60) && ((minutes + buffMinutes1) % 60 >= 0)) { minute = minutes + buffMinutes1; buffMinutes1 -= 60; }
		while (((seconds + buffSeconds1) % 60 <= 60) && ((seconds + buffSeconds1) % 60 >= 0)) { sec = seconds + buffSeconds1; buffSeconds1 -= 60; }
		cout << "����� �� ������� � ������� �������: " << hour << ":" << minute << ":" << sec << endl;
	}
	void MinusTime() {
		int hour, minute, sec;
		int buffHours2 = buffHours, buffMinutes2 = buffMinutes, buffSeconds2 = buffSeconds;
		if (buffSeconds2 / 60 > 0) { buffMinutes2 += (buffSeconds2 / 60); buffSeconds2 = buffSeconds % 60; }
		if (buffMinutes2 / 60 > 0) { buffHours2 += (buffMinutes2 / 60); buffMinutes2 = buffMinutes2 % 60; }
		buffHours2 = buffHours2 % 24;
		if (hours - buffHours2 < 0) {
			hour = (hours + 24) - buffHours2;
		}
		else hour = hours - buffHours2;
		//******************************************//
		if (minutes - buffMinutes2 < 0) {
			minute = (minutes + 60) - buffMinutes2;
		}
		else minute = minutes - buffMinutes2;
		//******************************************//
		if (seconds - buffSeconds2 < 0) {
			sec = (seconds + 60) - buffSeconds2;
		}
		else sec = seconds - buffSeconds2;
		cout << "����� �� ������� � ������� �������: " << hour << ":" << minute << ":" << sec << endl;
	}
};

void main() {
	int a, b, c;
	setlocale(LC_CTYPE, "Rus");
	Time t;
	t.Print1();
	//*********************************************//
	cout << "������� ����� �����: " << endl;
	cout << "����: ";
	cin >> a;
	while (a < 0 || a > 23) {
		cout << "������� ���������� ���-�� �����: ";
		cin >> a;
	}
	cout << "������: ";
	cin >> b;
	while (b < 0 || b > 59) {
		cout << "������� ���������� ���-�� �����: ";
		cin >> b;
	}
	cout << "�������: ";
	cin >> c;
	while (c < 0 || c > 59) {
		cout << "������� ���������� ���-�� ������: ";
		cin >> c;
	}
	t.EnterTime(a, b, c);
	t.Print2();
	t.Difference();
	system("pause");
	system("cls");
	//*********************************************//
	t.Print1();
	t.Enter();
	t.PlusTime();
	t.MinusTime();
	system("pause");
}