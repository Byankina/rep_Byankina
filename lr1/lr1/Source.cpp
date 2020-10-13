#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct truba {     //Создаем структуру труба со свойствами (как в примере задания)
	int id;
	double l;
	int d;
	bool remont;
};

truba tr[10] = {};

struct ks {        //Создаем структуру КС со свойствами (как в примере задания) 
	int id;
	string Name;
	int kol_ceh;
	int kol_ceh_inwork;
	double effect;
};

bool check_value(int x) {
	return x > 0 ? true : false;
}
bool check_value(double x) {
	return x > 0 ? true : false;
}

truba create_truba() {                  //Создание нового объекта в структуре
	truba new_truba;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "ID= " << endl;
		cin >> new_truba.id;
	} while (!check_value(new_truba.id) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Diameter= " << endl;
		cin >> new_truba.d;
	} while (!check_value(new_truba.d) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Dlina= " << endl;
		cin >> new_truba.l;
	} while (!check_value(new_truba.l) || cin.fail());
	new_truba.remont = false;
	return new_truba;
}
ks create_ks() {     //Создание нового объекта в структуре КС
	ks new_ks;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "ID= " << endl;
		cin >> new_ks.id;
	} while (!check_value(new_ks.id) || cin.fail());
	cout << "Name: " << endl;
	cin >> new_ks.Name;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Kol-vo cehov= " << endl;
		cin >> new_ks.kol_ceh;
	} while (!check_value(new_ks.kol_ceh) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Kol-vo cehov inwork= " << endl;
		cin >> new_ks.kol_ceh_inwork;
	} while (!(check_value(new_ks.kol_ceh_inwork) && (new_ks.kol_ceh_inwork <= new_ks.kol_ceh)) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Effect =" << endl;
		cin >> new_ks.effect;
	} while (!check_value(new_ks.effect) || cin.fail());
	return new_ks;
}

void write_truba_info(const truba& p, ks& comp) {     //Просмотр информации о трубе
	cout << "TRUBA";
	cout << "id: " << p.id << endl;
	cout << "Diameter= " << p.d << endl;
	cout << "Dlina= " << p.l << endl;
	cout << (p.remont ? "V remonte" : "Ne v remonte") << endl;
	cout << "KS";
	cout << "ID: " << comp.id << endl;
	cout << "Name: " << comp.Name << endl;
	cout <<"in work "<< comp.kol_ceh-comp.kol_ceh_inwork  <<"/"<<comp.kol_ceh<< endl;
	cout << "Effect= " << comp.effect << endl;
}

void change_status(bool& status) {    //Изменить статус трубы
	status = !status;
}

void change_kol(ks& name) {       //
	cout << "Kol-vo cehov inwork= " << endl;
	cin >> name.kol_ceh_inwork;
}


void save_to_file(truba p,ks c) {
	ofstream fout;
	fout.open("lab.txt", ios::out);
	if (fout.is_open()) {
		fout << p.id << endl << p.d << endl << p.l << endl << p.remont <<endl << c.id << endl << c.Name << endl << c.kol_ceh << endl << c.kol_ceh_inwork << endl << c.effect;
		fout.close();
	}
}

truba load_from_file(truba& p,ks& comp) {
	ifstream fin;
	fin.open("lab.txt", ios::in);
	if (fin.is_open()) {
		fin >> p.id;
		fin >> p.d;
		fin >> p.l;
		fin >> p.remont;
		fin >> comp.Name;
		fin >> comp.id;
		fin >> comp.kol_ceh;
		fin >> comp.kol_ceh_inwork;
		fin >> comp.effect;
		fin.close();
		return p;
	}
}


void PrintMenu() {
	cout << "1. Dobavit' trubu" << endl;
	cout << "2. Dobavit' KS" << endl;
	cout << "3. Prosmotr truba+ks" << endl;
	cout << "4. Redaktirovat' trubu(remont/ne remont)" << endl;
	cout << "5. Redaktirovat' KS" << endl;
	cout << "6. Sohranit' truba+ks" << endl;
	cout << "7. Zagruzit' dannie trubi+ks iz faila" << endl;
	cout << "0. Exit" << endl;
}

int main()
{
	ks comp;
	truba p;
	int i;
	while (1) {
		cout << "Select action:" << endl;
		PrintMenu();
		cin >> i;
			switch (i)
			{
			case 1:
				p = create_truba();
				break;
			case 2:
				comp = create_ks();
				break;
			case 3:
				write_truba_info(p, comp);
				break;
			case 4:
				change_status(p.remont);
				break;
			case 5:
				change_kol(comp);
				break;
			case 6:
				save_to_file(p, comp);
				break;
			case 7:
				load_from_file(p, comp);
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "Vybor deystviya: " << endl;
				break;
			}
		

	}

}