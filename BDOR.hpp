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
	void ajouterCategorie(const Categorie& c);
	void ajouterOffre(const Offre& offre, const string& nom);
	const vector<Categorie>& obtenirCategories() const;
	vector<shared_ptr<Offre>> obtenirOffreCategorie(const string& nom) const;
	vector<shared_ptr<Offre>> obtenirTousOffres() const;
	void supprimerOffre(const Offre& offre, const string& nom);
private:
	vector<Categorie> categories;
};

