//Metode i podaci vezani za rad sa Avion klasom
#include "Avion.h"

void Avion::insert_transport()
{

	Avion a;
	int id;
	string naziv;
	string registracija;
	string tip;
	string avioKompanija;
	string serijskiBroj;
	int godinaProizvodnje;
	string line;
	string c = "y";

	ofstream write;

	write.open("avion.txt", ios::app);
	


	if (write.is_open()) { //Unos novog aviona

		while (c == "y")
		{
			cout << "___________________________________\n";
			cout << "----- Unesite nov avion -----\n";
			cout << "ID                 :"; cin >> id;
			cout << "Naziv                :"; cin >> naziv;
			cout << "Registracija        :"; cin >> registracija;
			cout << "Tip                :"; cin >> tip;
			cout << "Avio Kompanija        :"; cin >> avioKompanija;
			cout << "Serijski broj :"; cin >> serijskiBroj;
			cout << "Godina proizvodnje :"; cin >> godinaProizvodnje;
			cout << "___________________________________\n";


			a.setId(id);
			a.setNaziv(naziv);
			a.setRegistracija(registracija);
			a.setTip(tip);
			a.setAvioKompanija(avioKompanija);
			a.setSerijskiBroj(serijskiBroj);
			a.setGodinaProizvodnje(godinaProizvodnje);


			write << a.getId() << " " << a.getNaziv() << " " << a.getRegistracija() << " " << a.getTip() << " " << a.getAvioKompanija() << " " << a.getSerijskiBroj() << " " << a.getGodinaProizvodnje() << endl;

			cout << "Unesi y za nastavak!!!" << endl;
			cin >> c;
		}

		cout << "Uspesno dodat nov avion!!!" << endl;
	}
	else {
		cout << "Fajl nije otvoren" << endl;
	}

	write.close();

}

void Avion::display_all() //Prikaz aviona
{


	vector<string>v;

	ifstream read;
	read.open("avion.txt", ios::in);
	string line;


	if (read.is_open()) {
		while (getline(read, line))
		{
			if (line.find("1") != string::npos) {
				v.push_back(line);
			}
		}
		sort(v.begin(), v.end());

		for (auto a : v) {

			cout << a << endl;
		}
	}
	read.close();

}

void Avion::update_transport() //Izmena postojeceg aviona
{

	Avion a;
	fstream stud;
	fstream temp;

	stud.open("avion.txt", ios::in);
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

		stud.open("avion.txt", ios::out);
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
	string avioKompanija;
	string serijskiBroj;
	int godinaProizvodnje;
	string c = "y";


	stud.open("avion.txt", ios::app);
	temp.open("avion.txt", ios::in);

	cout << "___________________________________\n";
	cout << "----- Unesite nove podatke -----\n";
	cout << "ID                 :"; cin >> id;
	cout << "Naziv                :"; cin >> naziv;
	cout << "Registracija       :"; cin >> registracija;
	cout << "Tip                :"; cin >> tip;
	cout << "Avio Kompanija        :"; cin >> avioKompanija;
	cout << "Serisjki broj    :"; cin >> serijskiBroj; 
	cout << "Godina proizvodnje    :"; cin >> godinaProizvodnje;
	cout << "___________________________________\n";

	a.setId(id);
	a.setNaziv(naziv);
	a.setRegistracija(registracija);
	a.setTip(tip);
	a.setAvioKompanija(avioKompanija);
	a.setSerijskiBroj(serijskiBroj);
	a.setGodinaProizvodnje(godinaProizvodnje);

	if (stud.is_open()) {
		stud << a.getId() << " " << a.getNaziv() << " " << a.getRegistracija() << " " << a.getTip() << " " << a.getAvioKompanija() << " " << a.getSerijskiBroj() << " " << a.getGodinaProizvodnje() << endl;

		while (getline(temp, line))
		{
			if (line.find("1") != string::npos) {
				cout << line << endl;
			}
		}
	}
	stud.close();
	temp.close();


	cout << "\n Uspesno ste izmenili podatke o avionu!!! \n";
}
