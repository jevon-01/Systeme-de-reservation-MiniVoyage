#pragma once
#include "Offre.hpp"
#include "string"

using namespace std;

class Excursion : public Offre {
public:
	Excursion(const string& categorie, vector<string> details, const string& nom, double p, const string& ville, int nbEtoiles) : Offre(categorie, details, nom, p), ville(ville), nbEtoiles(nbEtoiles) {};
	
	vector<string> obtenirDetails() const override;
	string obtenirVille() const;
	int obtenirNbEtoiles() const;

	void reserver(const string& nom) override;
private:
	string ville;
	int nbEtoiles;
};

