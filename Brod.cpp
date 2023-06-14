//Metode i podaci vezani za rad sa Brod klasom
#include "Brod.h"

void Brod::insert_transport()
{

	Brod b;
	int id;
	string naziv;
	string registracija;
	string tip;
	string model;
	string prekookeanski;
	string line;
	string c = "y";

	ofstream write;

	write.open("brod.txt", ios::app);


	if (write.is_open()) { //Unos novog broda

		while (c == "y")
		{
			cout << "___________________________________\n";
			cout << "----- Unesite nov brod -----\n";
			cout << "ID                 :"; cin >> id;
			cout << "Naziv                :"; cin >> naziv;
			cout << "Registracija        :"; cin >> registracija;
			cout << "Tip                :"; cin >> tip;
			cout << "Model        :"; cin >> model;
			cout << "Prekookeanski :"; cin >> prekookeanski;
			cout << "___________________________________\n";


			b.setId(id);
			b.setNaziv(naziv);
			b.setRegistracija(registracija);
			b.setTip(tip);
			b.setModel(model);
			b.setPrekookeanski(prekookeanski);
		


			write << b.getId() << " " << b.getNaziv() << " " << b.getRegistracija() << " " << b.getTip() << " " << b.getModel() << " " << b.getPrekookeanski() <<  endl;

			cout << "Unesi y za nastavak!!!" << endl;
			cin >> c;
		}

		cout << "Uspesno dodat nov brod!!!" << endl;
	}
	else {
		cout << "Fajl nije otvoren" << endl;
	}

	write.close();

}

void Brod::display_all() //Prikaz brodova
{


	vector<string>b;

	ifstream read;
	read.open("brod.txt", ios::in);
	string line;


	if (read.is_open()) {
		while (getline(read, line))
		{
			if (line.find("1") != string::npos) {
				b.push_back(line);
			}
		}
		sort(b.begin(), b.end());

		for (auto b : b) {

			cout << b << endl;
		}
	}
	read.close();

}

void Brod::update_transport() //Izmena postojeceg broda
{

	Brod b;
	fstream stud;
	fstream temp;

	stud.open("brod.txt", ios::in);
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

		stud.open("brod.txt", ios::out);
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
	string model;
	string prekookeanski;

	string c = "y";


	stud.open("brod.txt", ios::app);
	temp.open("brod.txt", ios::in);

	cout << "___________________________________\n";
	cout << "----- Unesite nove podatke -----\n";
	cout << "ID                 :"; cin >> id;
	cout << "Naziv                :"; cin >> naziv;
	cout << "Registracija       :"; cin >> registracija;
	cout << "Tip                :"; cin >> tip;
	cout << "Model           :"; cin >> model;
	cout << "Prekookeanski    :"; cin >> prekookeanski;

	cout << "___________________________________\n";

	b.setId(id);
	b.setNaziv(naziv);
	b.setRegistracija(registracija);
	b.setTip(tip);
	b.setModel(model);
	b.setPrekookeanski(prekookeanski);


	if (stud.is_open()) {
		stud << b.getId() << " " << b.getNaziv() << " " << b.getRegistracija() << " " << b.getTip() << " " << b.getModel() << " " << b.getPrekookeanski() <<  endl;

		while (getline(temp, line))
		{
			if (line.find("1") != string::npos) {
				cout << line << endl;
			}
		}
	}
	stud.close();
	temp.close();


	cout << "\n Uspesno ste izmenili podatke o brodu!!! \n";
}