#pragma once
#include "string"

using namespace std;

class Devise {
public:
	Devise() {};
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);
	//void convertir(const double, Devise);
	string obtenirDevise() const;
	double obtenirTauxConversion() const;
private:
	string devise = "CAD";
	double tauxConversion = 1.0;
};

