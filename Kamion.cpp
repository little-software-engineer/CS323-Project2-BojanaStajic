//Metode i podaci vezani za rad sa Kamion klasom
#include "Kamion.h"

void Kamion::insert_transport()
{

	Kamion k;
	int id;
	string naziv;
	string registracija;
	string tip;
	string serija;
	string marka;
	double predjeniKm;
	string line;
	string c = "y";

	ofstream write;

	write.open("kamion.txt", ios::app);


	if (write.is_open()) {//Unos novog kamiona

		while (c == "y")
		{
			cout << "___________________________________\n";
			cout << "----- Unesite nov kamion -----\n";
			cout << "ID                 :"; cin >> id;
			cout << "Naziv                :"; cin >> naziv;
			cout << "Registracija        :"; cin >> registracija;
			cout << "Tip                :"; cin >> tip;
			cout << "Serija        :"; cin >> serija;
			cout << "Marka :"; cin >> marka;
			cout << "Predjeni km :"; cin >> predjeniKm;
			cout << "___________________________________\n";


			k.setId(id);
			k.setNaziv(naziv);
			k.setRegistracija(registracija);
			k.setTip(tip);
			k.setSerija(serija);
			k.setMarka(marka);
			k.setPredjeniKm(predjeniKm);


			write << k.getId() << " " << k.getNaziv() << " " << k.getRegistracija() << " " << k.getTip() << " " << k.getSerija() << " " << k.getMarka() << " " << k.getPredjeniKm() << endl;

			cout << "Unesi y za nastavak!!!" << endl;
			cin >> c;
		}

		cout << "Uspesno dodat nov kamion!!!" << endl;
	}
	else {
		cout << "Fajl nije otvoren" << endl;
	}

	write.close();

}

void Kamion::display_all()//Prikaz kamiona
{


	vector<string>v;

	ifstream read;
	read.open("kamion.txt", ios::in);
	string line;


	if (read.is_open()) {
		while (getline(read, line))
		{
			if (line.find("1") != string::npos) {
				v.push_back(line);
			}
		}
		sort(v.begin(), v.end());

		for (auto k : v) {

			cout << k << endl;
		}
	}
	read.close();

}

void Kamion::update_transport() //Izmena postojeceg kamiona
{

	Kamion k;
	fstream stud;
	fstream temp;

	stud.open("kamion.txt", ios::in);
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

		stud.open("kamion.txt", ios::out);
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
	string serija;
	string marka;
	double predjeniKm;
	string c = "y";


	stud.open("kamion.txt", ios::app);
	temp.open("kamion.txt", ios::in);

	cout << "___________________________________\n";
	cout << "----- Unesite nove podatke -----\n";
	cout << "ID                 :"; cin >> id;
	cout << "Naziv                :"; cin >> naziv;
	cout << "Registracija       :"; cin >> registracija;
	cout << "Tip                :"; cin >> tip;
	cout << "Serija        :"; cin >> serija;
	cout << "Marka    :"; cin >> marka;
	cout << "Predjeni km    :"; cin >> predjeniKm;
	cout << "___________________________________\n";

	k.setId(id);
	k.setNaziv(naziv);
	k.setRegistracija(registracija);
	k.setTip(tip);
	k.setSerija(serija);
	k.setMarka(marka);
	k.setPredjeniKm(predjeniKm);

	if (stud.is_open()) {
		stud << k.getId() << " " << k.getNaziv() << " " << k.getRegistracija() << " " << k.getTip() << " " << k.getSerija() << " " << k.getMarka() << " " << k.getPredjeniKm() << endl;

		while (getline(temp, line))
		{
			if (line.find("1") != string::npos) {
				cout << line << endl;
			}
		}
	}
	stud.close();
	temp.close();


	cout << "\n Uspesno ste izmenili podatke o kamionu!!! \n";
}
