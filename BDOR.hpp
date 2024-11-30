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
	/*void ajouterOffre(const Offre& offre, const string& nomCategorie);*/
	const vector<Categorie>& obtenirCategories() const;
	const shared_ptr<Offre>& obtenirOffre(const string& nomOffre, const string& nomCategorie) const;
	const vector<shared_ptr<Offre>>& obtenirTousOffres() const;
	/*void supprimerOffre(const Offre& offre, const string& nom);*/
private:
	vector<Categorie> categories;
};

