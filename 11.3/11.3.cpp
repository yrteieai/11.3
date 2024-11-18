#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

bool isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 28 + isLeap) return false;
    }
    return true;
}

void CreateTXT(char* fname) {
    ofstream fout(fname); 
    char ch;
    string surname, name, phone;
    int day, month, year;

    do {
        cout << "������ �������: ";
        cin >> surname;
        cout << "������ ��'�: ";
        cin >> name;
        cout << "������ �������: ";
        cin >> phone;
        do {
            cout << "������ ���� ���������� (����, �����, ��): ";
            cin >> day >> month >> year;
            if (!isValidDate(day, month, year)) {
                cout << "���������� ����! ��������� �� ���.\n";
            }
        } while (!isValidDate(day, month, year));
        fout << surname << " " << name << " " << phone << " "
            << day << " " << month << " " << year << endl;
        cout << "������ �� ���� �����? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

void PrintTXT(char* fname) {
    ifstream fin(fname);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void AppendTXT(char* fname) {
    ofstream fout(fname, ios::app);
    char ch;
    string surname, name, phone;
    int day, month, year;

    do {
        cout << "������ �������: ";
        cin >> surname;
        cout << "������ ��'�: ";
        cin >> name;
        cout << "������ �������: ";
        cin >> phone;
        do {
            cout << "������ ���� ���������� (����, �����, ��): ";
            cin >> day >> month >> year;
            if (!isValidDate(day, month, year)) {
                cout << "���������� ����! ��������� �� ���.\n";
            }
        } while (!isValidDate(day, month, year));
        fout << surname << " " << name << " " << phone << " "
            << day << " " << month << " " << year << endl;
        cout << "������ �� ���� �����? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

void searchBySurname(char* fname, const string& surname) {
    ifstream fin(fname);
    string line, fileSurname, name, phone;
    int day, month, year;
    bool found = false;

    while (fin >> fileSurname >> name >> phone >> day >> month >> year) {
        if (fileSurname == surname) {
            cout << "��������: " << fileSurname << " " << name
                << ", �������: " << phone
                << ", ���� ����������: " << day << "/" << month << "/" << year << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "����� �� �������� " << surname << " �� ��������.\n";
    }
    fin.close();
}

void menu() {
    int choice;
    char filename[100];
    do {
        cout << "\n����:\n";
        cout << "1. �������� ����� ����\n";
        cout << "2. ����������� ���� �����\n";
        cout << "3. ������ ������ � ����\n";
        cout << "4. ����� �� ��������\n";
        cout << "0. �����\n";
        cout << "������� �����: ";

        while (!(cin >> choice) || choice < 0 || choice > 4) {
            cout << "������� ����. ��������� �� ���: ";
            cin.clear();
            cin.get();
            cin.sync();
        }

        switch (choice) {
        case 1:
            cout << "������ ��'� �����: ";
            cin >> filename;
            CreateTXT(filename);
            break;
        case 2:
            cout << "������ ��'� �����: ";
            cin >> filename;
            PrintTXT(filename);
            break;
        case 3:
            cout << "������ ��'� �����: ";
            cin >> filename;
            AppendTXT(filename);
            break;
        case 4: {
            cout << "������ ��'� �����: ";
            cin >> filename;
            string surname;
            cout << "������ �������: ";
            cin >> surname;
            searchBySurname(filename, surname);
            break;
        }
        case 0:
            cout << "���������� ��������.\n";
            break;
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}
