#pragma once
#include "Categorie.hpp"
#include "Offre.hpp"
#include "string"
#include "vector"

using namespace std;

class BDOR {
public:
	BDOR();
	void afficherCategories() const;
	void afficherOffres() const;
	void ajouterCategorie(Categorie c);
	void ajouterOffre(Offre offre, string nom);
	vector<Categorie> obtenirCategorie() const;
	vector<Offre> obtenirOffreCategorie(string nom) const;
	vector<Offre> obtenirTousOffres() const;
	void supprimerOffre(Offre offre, string nom);
private:
	vector<Categorie> categories;
};

