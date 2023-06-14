//Header fajl koji sadrzi deklaraciju klase Transport
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<exception>
#include <cctype>
#include"IDNijeValidan.h"
#include"NazivNijeValidan.h"
#include<map>
#include<sstream>


using namespace std;

class Transport {
private:
	string naziv;
	string tip; //kopneni, vodeni ili vazdusni
	string registracija;
	int id;
protected:
	Transport() {};
	Transport(string naziv, string tip, string registracija, int id) :
		naziv(naziv),  tip(tip), id(id) {};
	virtual ~Transport() {};
public:

	void setNaziv(string naziv);

	void setTip(string tip);
	void setRegistracija(string registracija) { this->registracija = registracija; };
	void setId(int id);

	string getNaziv() const { return naziv; };
	
	string getTip() const { return tip; };
	string getRegistracija() const { return registracija; };
	int getId() const { return id; };


	virtual void insert_transport() = 0;
	virtual void search_transport();
	virtual void display_all() = 0;
	virtual void update_transport() = 0;
	virtual void delete_transport();
	virtual void display_all_list();







};