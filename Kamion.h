//Header fajl koji sadrzi deklaraciju klase Kamion kao vidu transporta
#pragma once
#include "Transport.h"
class Kamion :
	public Transport
{
private:
	string serija;
	string marka;
	double predjeniKm;

public:
	Kamion() {};
	Kamion(string naziv, string tip, string registracija, int id, string serija, string marka, double predjeniKm)
		: Transport(naziv, tip, registracija, id), serija(serija), marka(marka), predjeniKm(predjeniKm) {};
	~Kamion() {};

	void setSerija(string serija) { this->serija = serija; };
	void setMarka(string marka) { this->marka = marka; };
	void setPredjeniKm(double predjeniKm) { this->predjeniKm = predjeniKm; };


	string getSerija() const { return serija; };
	string getMarka() const { return marka; };
	double getPredjeniKm() const { return predjeniKm; };

	void  insert_transport();
	void display_all();
	void update_transport();


};