#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, vector<string> details, const Devise dev, const string& nom, const double p);
	void afficherDetails() const;
	double calculerPrixTotal() const;
	virtual vector<string> obtenirDetails() const = 0;
	string obtenirCategorie() const;
	string obtenirNom() const;
	virtual void reserver(string nom) = 0;
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