#include "Devise.hpp"

using namespace std;

void Devise::changerDevise(const string& d) {
	devise = d;
}

void Devise::changerTauxConversion(const double taux) {
	tauxConversion = taux;
}

const string& Devise::obtenirDevise() const {
	return devise;
}

double Devise::obtenirTauxConversion() const {
	return tauxConversion;
}

const double Devise::convertir(double& prix, const string& d) {
	if (d == "EURO") {
		return prix / 1.5;
	}
	else {
		return prix * 1.5;
	}

}