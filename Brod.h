//Header fajl koji sadrzi deklaraciju klase Brod kao vidu transporta
#pragma once
#include "Transport.h"
class Brod :
	public Transport
{
private:
	string model;
	string prekookeanski;


public:
	Brod() {};
	Brod(string naziv, string tip, string registracija, int id, string model, string prekookeanski, string pogon)
		: Transport(naziv, tip, registracija, id), model(model), prekookeanski(prekookeanski) {};
	~Brod() {};

	void setModel(string model) { this->model = model; };
	void setPrekookeanski(string prekookeanski) { this->prekookeanski = prekookeanski; };
	


	string getModel() const { return model; };
	string getPrekookeanski() const { return prekookeanski; };


	void  insert_transport();
	void display_all();
	void update_transport();


};