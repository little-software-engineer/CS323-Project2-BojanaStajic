//Metode i podaci vezani za rad sa Voz klasom
#include "Voz.h"

void Voz::insert_transport()
{

	Voz v;
	int id;
	string naziv;
	string registracija;
	string tip;
	string prevoznik;
	string sistemSina;
	string pogon;
	string line;
	string c = "y";

	ofstream write;

	write.open("voz.txt", ios::app);


	if (write.is_open()) {//Unos novog voza

		while (c == "y")
		{
			cout << "___________________________________\n";
			cout << "----- Unesite nov voz -----\n";
			cout << "ID                 :"; cin >> id;
			cout << "Naziv                :"; cin >> naziv;
			cout << "Registracija        :"; cin >> registracija;
			cout << "Tip                :"; cin >> tip;
			cout << "Prevoznik        :"; cin >> prevoznik;
			cout << "Sistem sina :"; cin >> sistemSina;
			cout << "Pogon :"; cin >> pogon;
			cout << "___________________________________\n";


			v.setId(id);
			v.setNaziv(naziv);
			v.setRegistracija(registracija);
			v.setTip(tip);
			v.setPrevoznik(prevoznik);
			v.setSistemSina(sistemSina);
			v.setPogon(pogon);


			write << v.getId() << " " << v.getNaziv() << " " << v.getRegistracija() << " " << v.getTip() << " " << v.getPrevoznik() << " " << v.getSistemSina() << " " << v.getPogon() << endl;

			cout << "Unesi y za nastavak!!!" << endl;
			cin >> c;
		}

		cout << "Uspesno dodat nov voz!!!" << endl;
	}
	else {
		cout << "Fajl nije otvoren" << endl;
	}

	write.close();

}

void Voz::display_all()//Prikaz vozova
{


	vector<string>v;

	ifstream read;
	read.open("voz.txt", ios::in);
	string line;


	if (read.is_open()) {
		while (getline(read, line))
		{
			if (line.find("1") != string::npos) {
				v.push_back(line);
			}
		}
		sort(v.begin(), v.end());

		for (auto v : v) {

			cout << v << endl;
		}
	}
	read.close();

}

void Voz::update_transport()//Izmena postojeceg voza
{

	Voz v;
	fstream stud;
	fstream temp;

	stud.open("voz.txt", ios::in);
	temp.open("temp.txt", ios::out);

	string line;
	string search;

	cin.ignore();
	cout << "Unesi naziv za transport koji se edituje: ";
	getline(cin, search);

	if (stud.is_open()) {
		while (getline(stud, line))
		{

			if (line.find(search) != string::npos)
			{

				continue;
			}
			else
			{
				temp << line << endl;

			}

		}
		temp.close();
		stud.close();

		stud.open("voz.txt", ios::out);
		temp.open("temp.txt", ios::in);
		while (getline(temp, line))
		{

			stud << line << endl;

		}
	}
	temp.close();
	stud.close();
	remove("temp.txt");


	int id;
	string naziv;
	string registracija;
	string tip;
	string prevoznik;
	string sistemSina;
	string pogon;
	string c = "y";


	stud.open("voz.txt", ios::app);
	temp.open("voz.txt", ios::in);

	cout << "___________________________________\n";
	cout << "----- Unesite nove podatke -----\n";
	cout << "ID                 :"; cin >> id;
	cout << "Naziv                :"; cin >> naziv;
	cout << "Registracija       :"; cin >> registracija;
	cout << "Tip                :"; cin >> tip;
	cout << "Ptevoznik       :"; cin >> prevoznik;
	cout << "Sistem sina    :"; cin >> sistemSina;
	cout << "Pogon    :"; cin >> pogon;
	cout << "___________________________________\n";

	v.setId(id);
	v.setNaziv(naziv);
	v.setRegistracija(registracija);
	v.setTip(tip);
	v.setPrevoznik(prevoznik);
	v.setSistemSina(sistemSina);
	v.setPogon(pogon);

	if (stud.is_open()) {
		stud << v.getId() << " " << v.getNaziv() << " " << v.getRegistracija() << " " << v.getTip() << " " << v.getPrevoznik() << " " << v.getSistemSina() << " " << v.getPogon() << endl;

		while (getline(temp, line))
		{
			if (line.find("1") != string::npos) {
				cout << line << endl;
			}
		}
	}
	stud.close();
	temp.close();


	cout << "\n Uspesno ste izmenili podatke o vozu!!! \n";
}