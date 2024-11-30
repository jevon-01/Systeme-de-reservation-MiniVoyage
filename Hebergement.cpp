#include "Hebergement.hpp"

using namespace std;

string Hebergement::obtenirVille() const {
	return ville;
}

string Hebergement::obtenirSecteur() const {
	return secteur;
}

double Hebergement::obtenirCote() const {
	return cote;
}

vector<string> Hebergement::obtenirDetails() const {
    return {
        nom, ville, secteur, to_string(cote)
    };
}