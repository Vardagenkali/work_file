#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Simvol() {
	char sim;
	string f;
	int kolvo = 0;
	fstream file("file.txt");
	cout << "������� ������ �� �������� ���� �������� �����: ";
	cin >> sim;
	if (!file) cout << "������" << endl;
	while (file >> f) {
		if (!f.empty()&& tolower(f[0])==tolower(sim)) kolvo++;
	}
	cout << "���� ������� ���������� �� ��� �����: " << kolvo << endl;
	file.close();
}

void Replace() {
	string f;
	int vib;
	string search = "0", search2="1";
	
	ifstream file("file.txt");
	ofstream file2("file2.txt");
	if (!file)cout << "Error";
	cout << "��������:\n1)0 �������� �� 1\n2)1 �������� �� 0\n��� �����:";
	cin >> vib;
	cout << "\n";
	while (getline(file, f)) {
		if (vib == 1) {
			size_t pos = f.find("0");
			if (pos != string::npos) {
				f.replace(pos, search.length(), search2);
			}
			file2 << f << endl;
		}
		if (vib == 2) {
			size_t pos = f.find("1");
			if (pos != string::npos) {
				f.replace(pos, search2.length(), search);
			}
			file2 << f << endl;
		}
	}
	file.close();
	file2.close();
	remove("file.txt"); 
	rename("file2.txt", "file.txt");
}

void Save() {
	string line;
	ofstream file("file.txt");
	if (!file) cout << "Erroor";
	cout << "������� �������: ";
	cin.ignore();
	while (true) {
		getline(cin, line);
		if (line.empty()) {
			cout << endl;
			cout << "����� �������!" << endl;
			break;
		}
		file << line<<"\n";
	}
	file.close();
}

void Kol() {
	char f;
	int kol = 0;
	ifstream file("file.txt");
	if (!file) cout << "Eroor";
	while (file >> f) {
		kol++;
	}
	cout << "���������� ��������: " << kol << endl;
	file.close();
}

void Kol_strok() {
	string f;
	int a = 0;
	ifstream file("file.txt");
	if (!file) cout << "Error!" << endl;
	while (getline(file, f)) {
		a++;
	}
	cout << "���������� �����: " << a << endl;

	file.close();
}

void Censored() {
	ifstream file_cen("cen.txt");
	ifstream file("file.txt");
	ofstream file2("file2.txt");

	if (!file_cen || !file || !file2) {
		cout << "������ ��� �������� ������." << endl;
		return;
	}

	string censore;
	vector<string> censores;
	while (file_cen >> censore) {
		censores.push_back(censore);
	}

	string word;
	while (file >> word) {
		bool isCensored = false;
		for (const string& censored : censores) {
			if (word == censored) {
				isCensored = true;
				break;
			}
		}
		if (!isCensored) {
			file2 << word << " ";
		}
	}

	file_cen.close();
	file.close();
	file2.close();

	remove("file.txt");
	rename("file2.txt", "file.txt");

	cout << "������������ ����� ������� �� �����." << endl;
}

int main(){
	setlocale(LC_ALL, "");
	int choice;
	cout << "\t\t�����\n1)���������� ���������� ������������ � ������������� �������\n2)������ 0 �� 1 ��� ��������\n3)���������� ������� ����� � ������ ������� � ����\n4)���������� ���������� �������� � ���\n5)���������� ���������� ����� � ���\n6)������ ������������ �����\n\n" << endl;
	cin >> choice;
	if (choice < 1 || choice>6) cout << "������"<<endl;
	if (choice == 1) {
		Simvol();
	}
	if (choice == 2) {
		Replace();
	}
	if (choice == 3) {
		Save();
	}
	if (choice == 4) {
		Kol();
	}
	if (choice == 5) {
		Kol_strok();
	}
	if (choice == 6) {
		Censored();
	}
}