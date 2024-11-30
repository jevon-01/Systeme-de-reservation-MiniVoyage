#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, vector<string> details, const Devise dev, const string& nom, const double p) : categorie(categorie), details(details), devise(dev), nom(nom), prix(p) { messageDeCreation(); };
	virtual void afficherDetails() const;
	double calculerPrixTotal() const;
	vector<string> obtenirDetails() const;
	string obtenirCategorie() const;
	string obtenirNom() const;
	void reserver(string nom);
protected:
	string categorie;
	vector<string> details;
	Devise devise;
	string nom;
	double prix;
private:
	void messageDeCreation() const;
};

