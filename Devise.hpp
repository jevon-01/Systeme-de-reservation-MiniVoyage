#pragma once
#include "string"

using namespace std;

class Devise {
public:
	void changerDevise(string montant);
	void changerTauxConversion(double taux);
	void convertir(double, Devise);
	string obtenirDevise() const;
	double obtenirtauxConversion() const;
private:
	string devise;
	double tauxConvsersion;
};

