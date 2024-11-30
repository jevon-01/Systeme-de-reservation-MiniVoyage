#include "Excursion.hpp"

using namespace std;

string Excursion::obtenirVille() const {
	return ville;
}

int Excursion::obtenirNbEtoiles() const {
	return nbEtoiles;
}

vector<string> Excursion::obtenirDetails() const {
    return {
        nom, ville, to_string(nbEtoiles)
    };
}