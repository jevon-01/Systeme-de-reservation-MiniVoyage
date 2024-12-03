#include "Offre.hpp"
#include "iostream"

using namespace std;

Offre::Offre(const string& categorie, const string& nom, const double p, const Devise& d, bool nouvelleOffre) : categorie(categorie), nom(nom), prix(p), devise(d) {
    if (nouvelleOffre) {
        messageDeCreation();
    }
};

const double Offre::calculerPrixTotal() {

    if (devise.obtenirDevise() == "EURO") {
        return devise.convertir(prix, "CAD");
    }

    return prix;
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

const double& Offre::obtenirPrix() const {
    return prix;
}

void Offre::changerPrix(double newPrix) {
    prix = newPrix;
}