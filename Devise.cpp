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