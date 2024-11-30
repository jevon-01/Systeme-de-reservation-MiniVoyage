#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, const vector<string>& details, const string& nom, const double p, const Devise& d = Devise());
	void afficherDetails() const;
	double calculerPrixTotal() const;
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);

	const string& obtenirCategorie() const;
	const string& obtenirNom() const;
	const Devise& obtenirDevise() const;
	const vector<string>& obtenirDetails() const;
	virtual void reserver(const string& nom) = 0;
	//void definirDevise();
protected:
	string categorie;
	vector<string> details;
	Devise devise;
	string nom;
	double prix;
private:
	void messageDeCreation() const;
};

//ici on utilise le patron methode ou wtv, celui qui reutilise le squelette