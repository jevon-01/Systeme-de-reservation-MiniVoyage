#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, const string& nom, const double p, const Devise& d = Devise());
	//void afficherDetails() const;
	double calculerPrixTotal() const;
	void changerDevise(const string& d);
	void changerTauxConversion(const double taux);
	~Offre() = default;
	const string& obtenirCategorie() const;
	const string& obtenirNom() const;
	const Devise& obtenirDevise() const;
	//virtual const vector<string>& obtenirDetails() const = 0;
	virtual void reserver(const string& nom) = 0;
	//void definirDevise();
protected:
	string categorie;
	Devise devise;
	string nom;
	double prix;
private:
	void messageDeCreation() const;
};

//ici on utilise le patron methode ou wtv, celui qui reutilise le squelette