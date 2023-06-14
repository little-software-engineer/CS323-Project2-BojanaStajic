//CS323 Main Klasa 2. projektnog zadataka pisanog u C++ na temu Aplikacija za upravljanje sredstvima transporta FedEx-a.

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<Windows.h>
#include"Avion.h"
#include"Voz.h"
#include"Kamion.h"
#include"Brod.h"



using namespace std;

int main() {



	try {
		Avion a;
		Voz v;
		Kamion k;
		Brod b;
	

		Transport* aa = &a;
		Transport* ba1 = &v;
		Transport* aa4 = &k;
		Transport* aa3 = &b;

		string us = "y";

		while (us == "y") //Korisnicki meni
		{

			cout << "------ IZABERITE VRSTU TRANSPORTA ----- \n\n";

			cout << " 1 za Avion  \n 2 za Voz \n 3 za Kamion  \n 4 za Brod \n ";

			cout << " \n _________________________________________ ";
			cout << " \n Izaberite jednu od ponudjenih opcija: ";
			int c;
			cin >> c;
			if (c == 1) {
				cout << "----- Izabrali ste avione -----" << endl;
				cout << " 1: Unesi  \n 2: Pretrazi  \n 3: Editovanje \n 4: Brisanje \n 5: Prikazi fajl  \n ";
				int k;
				cin >> k;
				switch (k)
				{

				case 1:
					aa->insert_transport();
					break;
				case 2:
					aa->search_transport();
					break;
				
				case 3:
					aa->update_transport();

					break;
				case 4:
					aa->delete_transport();
					break;
				case 5:
					aa->display_all();
					break;


				default:
					cout << " \n Izaberite jednu od ponudjenih opcija: \n";
				}
				system("pause");
				system("cls");
			}
			else if (c == 2) {
				cout << "----- Izabrali ste vozove -----" << endl;
				cout << " 1: Unesi  \n 2: Pretrazi  \n 3: Editovanje \n 4: Brisanje \n 5: Prikazi fajl \n ";
				int z;
				cin >> z;
				switch (z)
				{
				case 1:
					ba1->insert_transport();
					break;
				case 2:
					ba1->search_transport();
					break;
				
				case 3:
					ba1->update_transport();

					break;
				case 4:
					ba1->delete_transport();
					break;
				case 5:
					ba1->display_all();
					break;

				default:
					cout << " \n Izaberite jednu od ponudjenih opcija: \n";
				}
				system("pause");
				system("cls");
			}
			else if (c == 3) {
				cout << "----- Izabrali ste vrstu kamione -----" << endl;
				cout << " 1: Unesi  \n 2: Pretrazi   \n 3: Editovanje \n 4: Brisanje \n 5: Prikazi fajl \n ";
				int b;
				cin >> b;
				switch (b)
				{

				case 1:
					aa4->insert_transport();
					break;
				case 2:
					aa4->search_transport();
					break;
			
				case 3:
					aa4->update_transport();

					break;
				case 4:
					aa4->delete_transport();
					break;
				case 5:
					aa4->display_all();
					break;

				default:
					cout << " \n Izaberite jednu od ponudjenih opcija: \n";
				}
				system("pause");
				system("cls");
			}
			else if (c == 4) {
				cout << "----- Izabrali ste brodove -----" << endl;
				cout << " 1: Unesi  \n 2: Pretrazi  \n 3: Editovanje \n 4: Brisanje \n 5: Prikazi fajl \n ";
				int a;
				cin >> a;
				switch (a)
				{

				case 1:
					aa3->insert_transport();
					break;
				case 2:
					aa3->search_transport();
					break;
				
				case 3:
					aa3->update_transport();

					break;
				case 4:
					aa3->delete_transport();
					break;
				case 5:
					aa3->display_all();
					break;

				default:
					cout << " \n Izaberite jednu od ponudjenih opcija: \n";
				}
				system("pause");
				system("cls");
			}
			
			else {

				cout << "Izaberite odgovarajuci broj" << endl;
			}

			cout << "Upisite y za nastavak" << endl;
			cin >> us;

		}

	}
	catch (IDNijeValidan& e) { //Obrada izuzetaka
		cout << e.what() << endl;
	}
	catch (NazivNijeValidan& e) { //Obrada izuzetaka
		cout << e.what() << endl;
	}


	return 0;
}


