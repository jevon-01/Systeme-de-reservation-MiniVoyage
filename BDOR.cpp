#include "BDOR.hpp"
#include "iostream"

using namespace std;

BDOR::BDOR() {
	cout << "Objet BDOR cree!" << endl;
	cout << "Categorie Transport creee!" << endl
		<< "Categorie Hebergement creee!" << endl
		<< "Categorie Excursion creee!" << endl;
	for (const auto& type : { "Vols", "Hebergement", "Excursions" }) {
		Categorie c = Categorie(type);
		ajouterCategorie(c);
	}
	for (const auto& c : categories) {
		for (const auto& o : c.obtenirOffres()) {
			offres.push_back(o);
		}
	}
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

const vector<Categorie>& BDOR::obtenirCategories() const {
	return categories;
}

const shared_ptr<Offre>& BDOR::obtenirOffre(const string& nomOffre) const {
	for (const auto& c : categories) {
		for (const auto& o : c.obtenirOffres()) {
			if (o->obtenirNom() == nomOffre) {
				return o;
			}
		}
	}
}

const vector<shared_ptr<Offre>>& BDOR::obtenirTousOffres() const {
	return offres;
}

shared_ptr<Offre> BDOR::remplacerOffre(const string& offreNom, shared_ptr<Offre> nouvelOffre) {
	
	for (auto& categorie : categories) {
	
		for (auto& offre : categorie.obtenirOffresNonConst()) {
			
			if (offre->obtenirNom() == offreNom) {
				
				offre = nouvelOffre; 
				return offre; 
			}
		}
	}
	
	return nullptr;
}