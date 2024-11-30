#pragma once
#include "Devise.hpp"
#include "string"
#include "vector"

using namespace std;

class Offre {
public:
	Offre(const string& categorie, vector<string> details, const string& nom, const double p);
	void afficherDetails() const;
	double calculerPrixTotal() const;
	virtual vector<string> obtenirDetails() const = 0;
	string obtenirCategorie() const;
	string obtenirNom() const;
	Devise obtenirDevise() const;
	//void definirDevise();
	virtual void reserver(const string& nom) = 0;
protected:
	string categorie;
	vector<string> details;
	Devise devise = Devise();
	string nom;
	double prix;
private:
	void messageDeCreation() const;
};

//ici on utilise le patron methode ou wtv, celui qui reutilise le squelette