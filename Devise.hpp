#pragma once
#include "string"

using namespace std;

class Devise {
public:
	Devise(const string& d = "CAD", const double t = 1.0) : devise(d), tauxConversion(t) {}
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);
	//void convertir(const double, Devise);
	const string& obtenirDevise() const;
	double obtenirTauxConversion() const;
private:
	string devise;
	double tauxConversion;
};

