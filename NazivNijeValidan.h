//Header fajl koji definise izuzetak ukoliko naziv transporta nema korektan format
#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

class NazivNijeValidan : public exception {
public:

	const char* what() const throw ()
	{
		return "Naziv vrste transporta treba da sadrzi samo slova!!!";
	}


};
