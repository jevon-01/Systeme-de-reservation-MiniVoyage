#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, const string& nom, const double p, const Devise& d = Devise(), bool nouvelleOffre = true);
	virtual ~Offre() = default;
	virtual const double calculerPrixTotal();
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);
	virtual const string& obtenirCategorie() const;
	virtual const string& obtenirNom() const;
	const Devise& obtenirDevise() const;
	const double& obtenirPrix() const;

protected:
	string categorie;
	Devise devise;
	string nom;
	double prix;
private:
	void messageDeCreation() const;
};