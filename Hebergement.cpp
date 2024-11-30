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

//const vector<string>& Hebergement::obtenirDetails() const {
//    return {
//        nom, ville, secteur, to_string(cote)
//    };
//}

//TODO
void Hebergement::reserver(const string& nom) {

}