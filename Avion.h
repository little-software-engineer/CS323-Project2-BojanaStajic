//Header fajl koji sadrzi deklaraciju klase Avion kao vidu transporta
#pragma once
#include "Transport.h"
class Avion :
	public Transport
{
private:
	string avioKompanija;
	string serijskiBroj;
	int godinaProizvodnje;

public:
	Avion() {};
	Avion(string naziv, string tip, string registracija, int id, string avioKompanija, string serijskiBroj, int godinaProizvodnje)
		: Transport(naziv, tip, registracija, id), avioKompanija(avioKompanija),serijskiBroj(serijskiBroj),godinaProizvodnje(godinaProizvodnje) {};
	~Avion() {};

	void setAvioKompanija(string avioKompanija) { this->avioKompanija = avioKompanija; };
	void setSerijskiBroj(string serijskiBroj) { this->serijskiBroj = serijskiBroj; };
	void setGodinaProizvodnje(int godinaProizvodnje) { this->godinaProizvodnje = godinaProizvodnje; };


	string getAvioKompanija() const { return avioKompanija; };
	string getSerijskiBroj() const { return serijskiBroj; };
	int getGodinaProizvodnje() const { return godinaProizvodnje; };

	void  insert_transport();
	void display_all();
	void update_transport();


};