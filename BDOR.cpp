#include "BDOR.hpp"
#include "iostream"

using namespace std;

BDOR::BDOR() {
	cout << "Objet BDOR cree!" << endl;
	cout << "Categorie Transport creee!" << endl;
	cout << "Categorie Hebergement creee!" << endl;
	cout << "Categorie Excursion creee!" << endl;
	Categorie vol = Categorie("Vols");
	ajouterCategorie(vol);
}

void BDOR::ajouterCategorie(const Categorie& c) {
	categories.push_back(c);
}

void BDOR::afficherCategories() const {
	for (const auto& c : categories) {
		c.afficherCategorie();
	}
}
void BDOR::afficherOffres() const {
	cout << "dans afficherOffres" << endl;
	for (const auto& c : categories) {
		c.afficherOffres();
	}
}

vector<Categorie> BDOR::obtenirCategories() const {
	return categories;
}