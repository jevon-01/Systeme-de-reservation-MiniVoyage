#pragma once
#include "Offre.hpp"
#include "string"

using namespace std;

class Excursion : public Offre {
public:
	Excursion(const string& categorie, vector<string> details, const Devise dev, const string& nom, double p, const string& ville, int nbEtoiles) : Offre(categorie, details, dev, nom, p), ville(ville), nbEtoiles(nbEtoiles) {};
	void afficherDetails() const override;

	string obtenirVille() const;
	int obtenirNbEtoiles() const;

	//void reserver(string);
private:
	string ville;
	int nbEtoiles;
};

