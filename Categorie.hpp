#pragma once
#include "Offre.hpp"
#include "string"
#include "vector"
#include "memory"

using namespace std;

class Categorie {
public:
	Categorie(const string& nom);
	void afficherCategorie() const;
	void afficherOffres() const;
	void ajouterOffre(Offre offre);
	void changerCategorie(string nom);
	string obtenirNomCategorie() const;
	vector<shared_ptr<Offre>> obtenirOffres() const;
	shared_ptr<Offre> obtenirOffreSpecifique(shared_ptr<Offre> offre) const;
	void supprimerOffre(shared_ptr<Offre> offre);
private:
	string nom;
	vector<shared_ptr<Offre>> offres;
};