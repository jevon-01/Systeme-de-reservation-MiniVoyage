#include "Offre.hpp"
#include "iostream"

using namespace std;


Offre::Offre(const string& categorie, vector<string> details, const string& nom, const double p) : categorie(categorie), details(details), nom(nom), prix(p) {
    messageDeCreation();
};


void Offre::afficherDetails() const {
    vector<string> listDetails = obtenirDetails();
    for (const string& elem : listDetails) {
        cout << elem << " ";
    }
    cout << endl;
}

//TODO
double Offre::calculerPrixTotal() const {
    return 0.0;
}

void Offre::messageDeCreation() const {
	cout << "Entree " << obtenirNom() << " rattachee a la categorie " << obtenirCategorie() << " creee!" << endl;
}

string Offre::obtenirCategorie() const {
    return categorie;
}

string Offre::obtenirNom() const {
    return nom;
}

Devise Offre::obtenirDevise() const {
    return devise;
}