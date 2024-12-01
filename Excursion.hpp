#pragma once
#include "Offre.hpp"
#include "string"

using namespace std;

class Excursion : public Offre {
public:
	Excursion(const string& categorie, const string& nom, double p, const string& ville, const int nbEtoiles, const Devise& d = Devise()) : Offre(categorie, nom, p, d), ville(ville), nbEtoiles(nbEtoiles) {};
	~Excursion() override = default;
	const string& obtenirVille() const;
	const int obtenirNbEtoiles() const;

private:
	string ville;
	int nbEtoiles;
};

