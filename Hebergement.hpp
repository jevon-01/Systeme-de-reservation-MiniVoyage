#pragma once
#include "Offre.hpp"
#include "string"

class Hebergement : public Offre {
public:
	Hebergement(const string& categorie, vector<string> details, const Devise dev, const string& nom, const double p, const string& v, const string& s, const double cote) : Offre(categorie, details, dev, nom, p), ville(v), secteur(s), cote(cote) {};
	void afficherDetails() const override;
	
	string obtenirVille() const;
	string obtenirSecteur() const;
	double obtenirCote() const;
private:
	string ville;
	string secteur;
	double cote;
};

