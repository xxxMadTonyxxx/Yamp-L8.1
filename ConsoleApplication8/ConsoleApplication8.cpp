#include <iostream>
#include <iomanip>
#include "Student.h"
#include <Windows.h>
using namespace std;
bool StringEqual(char b[30], char b1[30]);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	student students[30];
	int counter = 0, score = 0, counter1 = 0, counter2 = 0, records = 0;
	char search[30];
	char flag = 'y';
	do {
		cout << "Студент " << records + 1 << endl;
		cout << "Введите имя студента" << endl;
		cin >> students[records].name;
		cout << "Введите фамилию студента" << endl;
		cin >> students[records].fam;
		cout << "Введите баллы по математике" << endl;
		cin >> students[records].math;
		cout << "Введите баллы по физике" << endl;
		cin >> students[records].phys;
		cout << "Введите баллы по русскому" << endl;
		cin >> students[records].rus;
		students[records].sum = (students[records].math + students[records].phys + students[records].rus);
		cout << "Продолжить ввод? (y/n)";
		cin >> flag;
		records++;
	} while (flag == 'y');

	for (counter = 0; records > counter; counter++) {
		if (score < students[counter].sum) {
			score = students[counter].sum;
		}
	}
	for (counter1 = 0; records > counter1; counter1++) {
		if (score == students[counter1].sum) {
			cout << setw(16) << "Фамилия" << setw(10) <<
				"Имя" << setw(10) << "Сумма баллов" << endl;
			cout << setw(16) << students[counter1].fam << setw(10) <<
				students[counter1].name << setw(10) <<
				students[counter1].sum << endl;
		}
	}
	cout << "Хотите ли вы выполнить поиск по фамилии? (y/n)" << endl;
	cin >> flag;
	if (flag == 'y') {
		cout << "Введите фамилию студента, которого хотите найти" << endl;
		cin >> search;
		for (counter2 = 0; records > counter2; counter2++) {
			if (StringEqual(search, students[counter2].fam)) {
				cout << setw(16) << "Фамилия" << setw(10) <<
					"Имя" << setw(10) << "Сумма баллов" << endl;
				cout << setw(16) << students[counter2].fam << setw(10) <<
					students[counter2].name << setw(10) <<
					students[counter2].sum << endl;
			}
		}

	}
}
bool StringEqual(char b[30], char b1[30]) {
	for (int i = 0; i < 30; i++) {
		if (b[i] != b1[i])
			return false;
	}
	return true;
}