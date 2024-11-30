#include "BDOR.hpp"
#include "iostream"

using namespace std;

BDOR::BDOR() {
	cout << "Objet BDOR cree!" << endl;
	
	Categorie vol = Categorie("Vol");
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
	for (const auto& c : categories) {
		c.afficherOffres();
	}
}