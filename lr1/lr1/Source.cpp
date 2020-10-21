#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct truba {     //Создаем структуру труба со свойствами (как в примере задания)
	int id;
	int l;
	int d;
	bool remont;
};

struct ks {        //Создаем структуру КС со свойствами (как в примере задания) 
	int id;
	string Name;
	int kol_ceh;
	int kol_ceh_inwork;
	int effect;
};

int check_int(int a) {             //функция проверки значения
	int i;
	cin >> i;
	while (i > a || i < 0 || cin.fail()) {
		cout << "povtor " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> i;
	}
	cin.ignore(10000, '\n');
	return i;
}


truba create_truba() {                  //Создание нового объекта в структуре
	truba new_truba;
	cout << "id=" << endl;
	new_truba.id = check_int(1000);
	cout << "diametr=" << endl;
	new_truba.d = check_int(1000);
	cout << "dlina=" << endl;
	new_truba.l = check_int(1000);
	new_truba.remont = false;
	return new_truba;
}
ks create_ks() {     //Создание нового объекта в структуре КС
	ks new_ks;
	cout << "Name: " << endl;
	cin >> new_ks.Name;
	cout << "id=" << endl;
	new_ks.id = check_int(1000);
	cout << "kol ceh=" << endl;
	new_ks.kol_ceh = check_int(1000);
	cout << "kol ceh inwork=" << endl;
	new_ks.kol_ceh_inwork = check_int(new_ks.kol_ceh);
	cout << "effect=" << endl;
	new_ks.effect = check_int(1000);
	return new_ks;
}

void write_truba_ks_info(const truba& t, const ks& k) {     //Просмотр информации о трубе
	cout << "TRUBA"<<endl;
	cout << "id: " << t.id << endl;
	cout << "Diameter= " << t.d << endl;
	cout << "Dlina= " << t.l << endl;
	cout << (t.remont ? "V remonte" : "Ne v remonte") << endl;
	cout << "KS"<<endl;
	cout << "ID: " << k.id << endl;
	cout << "Name: " << k.Name << endl;
	cout <<"in work "<< k.kol_ceh_inwork  <<"/"<<k.kol_ceh<< endl;
	cout << "Effect= " << k.effect << endl;
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

void load_from_file(truba& t,ks& k) {
	ifstream fin;
	fin.open("lab.txt", ios::in);
	if (fin.is_open()) {
		fin >> t.id;
		fin >> t.d;
		fin >> t.l;
		fin >> t.remont;
		fin >> k.Name;
		fin >> k.id;
		fin >> k.kol_ceh;
		fin >> k.kol_ceh_inwork;
		fin >> k.effect;
		fin.close();
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
	ks k;
	truba t;
	int i;
	while (1) {
		cout << "Select action:" << endl;
		PrintMenu();
		cin >> i;
			switch (i)
			{
			case 1:
				t = create_truba();
				break;
			case 2:
				k = create_ks();
				break;
			case 3:
				write_truba_ks_info(t,k);
				break;
			case 4:
				change_status(t.remont);
				break;
			case 5:
				change_kol(k);
				break;
			case 6:
				save_to_file(t,k);
				break;
			case 7:
				load_from_file(t,k);
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