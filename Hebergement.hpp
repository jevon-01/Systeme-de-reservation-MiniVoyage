#pragma once
#include "Offre.hpp"
#include "string"

class Hebergement : public Offre {
public:
	Hebergement(const string& categorie, vector<string> details, const string& nom, const double p, const string& v, const string& s, const double cote) : Offre(categorie, details, nom, p), ville(v), secteur(s), cote(cote){};
	
	vector<string> obtenirDetails() const override;
	string obtenirVille() const;
	string obtenirSecteur() const;
	double obtenirCote() const;
	void definirDisponibilites();
	void reserver(const string& nom) override;
private:
	string ville;
	string secteur;
	double cote;
	vector<string> disponibilites;
};

