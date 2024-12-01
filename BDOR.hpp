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
	const vector<Categorie>& obtenirCategories() const;
	const shared_ptr<Offre>& obtenirOffre(const string& nomOffre) const;
	const vector<shared_ptr<Offre>>& obtenirTousOffres() const;

private:
	vector<Categorie> categories;
	vector<shared_ptr<Offre>> offres;
};

