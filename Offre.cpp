#include "Offre.hpp"
#include "iostream"

using namespace std;


Offre::Offre(const string& categorie, vector<string> details, const Devise dev, const string& nom, const double p) : categorie(categorie), details(details), devise(dev), nom(nom), prix(p) {
    messageDeCreation(); 
};


void Offre::afficherDetails() const {
    vector<string> listDetails = obtenirDetails();
    for (const string& elem : listDetails) {
        cout << elem << " ";
    }
    cout << endl;
}

void Offre::messageDeCreation() const {
	cout << "Entree " << obtenirNom() << " rattachee a la categorie " << obtenirCategorie() << " creee!" << endl;
}
