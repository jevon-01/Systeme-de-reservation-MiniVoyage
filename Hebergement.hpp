#pragma once
#include "Offre.hpp"
#include "string"

class Hebergement : public Offre {
public:
	Hebergement(const string& categorie, const string& nom, const double p, const string& v, const string& s, const double cote, const Devise& d = Devise()) : Offre(categorie, nom, p, d), ville(v), secteur(s), cote(cote){};
	~Hebergement() = default;
	/*const vector<string>& obtenirDetails() const override;*/
	const string& obtenirVille() const;
	const string& obtenirSecteur() const;
	double obtenirCote() const;
	void definirDisponibilites();
	void reserver(const string& nom) override;
private:
	string ville;
	string secteur;
	double cote;
	vector<string> disponibilites;
};

