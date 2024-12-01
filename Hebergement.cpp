#include "Hebergement.hpp"

using namespace std;

const string& Hebergement::obtenirVille() const {
	return ville;
}

const string& Hebergement::obtenirSecteur() const {
	return secteur;
}

double Hebergement::obtenirCote() const {
	return cote;
}
