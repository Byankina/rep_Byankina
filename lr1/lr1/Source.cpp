#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct truba {     //Создаем структуру труба со свойствами (как в примере задания)
	int id;
	double l;
	double d;
	bool remont;
};

struct ks {        //Создаем структуру КС со свойствами (как в примере задания) 
	int id;
	string Name;
	int kol_ceh;
	int kol_ceh_inwork;
	double effect;
};

template <typename T>
T GetCorrectNumber(T max)
{
	T x;
	while ((cin >> x).fail() || x < 0 || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Type number (" << 0 << "-" << max << "):";
	}
	return x;
}


truba create_truba() {                  //Создание нового объекта в структуре
	truba new_truba;
	cout << "id=" << endl;
	new_truba.id = GetCorrectNumber(1000);
	cout << "diametr=" << endl;
	new_truba.d = GetCorrectNumber(2000);
	cout << "dlina=" << endl;
	new_truba.l = GetCorrectNumber(1000);
	new_truba.remont = false;
	return new_truba;
}
ks create_ks() {     //Создание нового объекта в структуре КС
	ks new_ks;
	cout << "Name: " << endl;
	cin.ignore(10000, '\n');
	getline(cin, new_ks.Name);
	//cin.getline (new_ks.Name);
	cout << "id=" << endl;
	new_ks.id = GetCorrectNumber(1000);
	cout << "kol ceh=" << endl;
	new_ks.kol_ceh = GetCorrectNumber(10);
	cout << "kol ceh inwork=" << endl;
	new_ks.kol_ceh_inwork = GetCorrectNumber(new_ks.kol_ceh);
	cout << "effect=" << endl;
	new_ks.effect = GetCorrectNumber(1000);
	return new_ks;
}

void write_truba_info(const truba& t) {     //Просмотр информации о трубе
	if (t.id > 0) { 
		cout << "TRUBA" << endl;
		cout << "id: " << t.id << endl;
		cout << "Diameter= " << t.d << endl;
		cout << "Dlina= " << t.l << endl;
		cout << (t.remont ? "V remonte" : "Ne v remonte") << endl; 
	}
	else cout << "We have not the pipe"<< endl;
}

void write_ks_info(const ks& k) {     //Просмотр информации о КС
	if (k.id > 0) {
		cout << "KS" << endl;
		cout << "ID: " << k.id << endl;
		cout << "Name: " << k.Name << endl;
		cout << "in work " << k.kol_ceh_inwork << "/" << k.kol_ceh << endl;
		cout << "Effect= " << k.effect << endl;
	}
	else cout << "We have not the KS" << endl;

}

void change_status(bool& status) {    //Изменить статус трубы
	status = !status;
}

void change_kol(ks& name) {           //Изменить количество цехов в работе
	cout << "Kol-vo cehov inwork= " << endl;
	name.kol_ceh_inwork = GetCorrectNumber(name.kol_ceh);
}


void save_to_file_pipe(const truba& p) {
	ofstream fout;
	fout.open("Pipe.txt", ios::out);
	if (fout.is_open()) {
		fout << p.id << endl << p.d << endl << p.l << endl << p.remont <<endl;
		fout.close();
	}
}

void save_to_file_ks(const ks& c) {
	ofstream fout;
	fout.open("KS.txt", ios::out);
	if (fout.is_open()) {
		fout <<  c.id << endl << c.Name << endl << c.kol_ceh << endl << c.kol_ceh_inwork << endl << c.effect;
		fout.close();
	}
}


void load_from_file_pipe(truba& t) 
{
	ifstream fin;
	fin.open("Pipe.txt", ios::in);
	if (fin.is_open()) {
		fin >> t.id>> t.d>> t.l>> t.remont;
		fin.close();
	}
}

void load_from_file_ks(ks& k) 
{
	ifstream fin;
	fin.open("KS.txt", ios::in);
	if (fin.is_open()) {
		fin >> k.Name>> k.id >> k.kol_ceh >> k.kol_ceh_inwork>> k.effect;
		fin.close();
	}
}


void PrintMenu() {
	cout << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Add KS" << endl;
	cout << "3. Show the pipe" << endl;
	cout << "4. Show the KS" << endl;
	cout << "5. Change the pipe(remont/ne remont)" << endl;
	cout << "6. Change the KS" << endl;
	cout << "7. Save the pipe" << endl;
	cout << "8. Save the KS" << endl;
	cout << "9. Load from file the pipe" << endl;
	cout << "10. Load from file the KS" << endl;
	cout << "0. Exit" << endl;
}

int main()
{
	ks k;
	truba t;
	int i;
	while (1) {
		cout << "Select action:" << endl;
		PrintMenu();
		i = GetCorrectNumber(10);
			switch (i)
			{
			case 1:
				t = create_truba();
				break;
			case 2:
				k = create_ks();
				break;
			case 3:
				write_truba_info(t);
				break;
			case 4:
				write_ks_info(k);
			case 5:				
				change_status(t.remont);
				break;
			case 6:
				change_kol(k);
				break;
			case 7:
				save_to_file_pipe(t);
				break;
			case 8:
				save_to_file_ks(k);
			case 9:
				load_from_file_pipe(t);
				break;
			case 10: 
				load_from_file_ks(k);
				break;
			case 0:
				return 0;
				break;
			/*default:
			{cout << endl;
			cout << "Vybor deystviya: " << endl;}
			break;*/
			}

			cout << endl;

		

	}

}