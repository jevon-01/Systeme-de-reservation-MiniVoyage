#pragma once
#include "string"

using namespace std;

class Devise {
public:
	Devise(const string& d = "CAD", const double t = 1.00) : devise(d), tauxConversion(t) {}
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);
	const double convertir(double& prix, const string& d) const;
	const string& obtenirDevise() const;
	double obtenirTauxConversion() const;
private:
	string devise;
	double tauxConversion;
};

