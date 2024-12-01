#pragma once
#include "Offre.hpp"
#include "string"

class Hebergement : public Offre {
public:
	Hebergement(const string& categorie, const string& nom, const double p, const string& v, const string& s, const double cote, const Devise& d = Devise()) : Offre(categorie, nom, p, d), ville(v), secteur(s), cote(cote){};
	~Hebergement() override = default;
	const string& obtenirVille() const;
	const string& obtenirSecteur() const;
	double obtenirCote() const;

private:
	string ville;
	string secteur;
	double cote;
	vector<string> disponibilites;
};

