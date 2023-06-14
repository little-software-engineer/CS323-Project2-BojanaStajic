//Header fajl koji sadrzi deklaraciju klase Voz kao vidu transporta
#pragma once
#include "Transport.h"
class Voz :
	public Transport
{
private:
	string prevoznik;
	string sistemSina;
	string pogon;

public:
	Voz() {};
	Voz(string naziv, string tip, string registracija, int id, string prevoznik, string sistemSina, string pogon)
		: Transport(naziv, tip, registracija, id), prevoznik(prevoznik), sistemSina(sistemSina), pogon(pogon) {};
	~Voz() {};

	void setPrevoznik(string prevoznik) { this->prevoznik = prevoznik; };
	void setSistemSina(string sistemSina) { this->sistemSina = sistemSina; };
	void setPogon(string pogon) { this->pogon = pogon; };


	string getPrevoznik() const { return prevoznik; };
	string getSistemSina() const { return sistemSina; };
	string getPogon() const { return pogon; };

	void  insert_transport();
	void display_all();
	void update_transport();


};