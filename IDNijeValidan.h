//Header fajl koji definise izuzetak ukoliko je unesen neispravan ID
#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

class IDNijeValidan : public exception {
public:

	const char* what() const throw ()
	{
		return "ID ne moze biti negativan broj!";
	}


};