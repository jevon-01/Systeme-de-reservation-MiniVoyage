#include "Offre.hpp"
#include "iostream"

using namespace std;


Offre::Offre(const string& categorie, const string& nom, const double p, const Devise& d) : categorie(categorie), nom(nom), prix(p), devise(d) {
    messageDeCreation();
};


//void Offre::afficherDetails() const {
//    const vector<string>& listDetails = obtenirDetails();
//    for (const string& elem : listDetails) {
//        cout << elem << " hi";
//    }
//    cout << endl;
//}

//TODO
const double Offre::calculerPrixTotal() const {
    return 0.0;
}

void Offre::messageDeCreation() const {
	cout << "Entree " << obtenirNom() << " rattachee a la categorie " << obtenirCategorie() << " creee!" << endl;
}

void Offre::changerDevise(const string& d) {
    devise.Devise::changerDevise(d);
}

void Offre::changerTauxConversion(const double taux) {
    devise.Devise::changerTauxConversion(taux);
}

const string& Offre::obtenirCategorie() const {
    return categorie;
}

const string& Offre::obtenirNom() const {
    return nom;
}

const Devise& Offre::obtenirDevise() const {
    return devise;
}