#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre();
	virtual void afficherDetails() const;
	double calculerPrixTotal() const;
	vector<string> obtenirDetails() const;
	string obtenirCategorie() const;
	string obtenirNom() const;
	void reserver(string nom);
private:
	string categorie;
	vector<string> details;
	Devise devise;
	string nom;
	double prix;
};

