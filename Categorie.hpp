#pragma once
#include "Offre.hpp"
#include "string"
#include "vector"
#include "memory"

using namespace std;

class Categorie {
public:
	Categorie(const string& nom);
	~Categorie() = default;
	void definirVols();
	void definirHebergement();
	void definirExcursions();
	void afficherCategorie() const;
	void afficherOffres() const;
	void ajouterOffre(shared_ptr<Offre> offre);
	const string& obtenirNomCategorie() const;
	const vector<shared_ptr<Offre>>& obtenirOffres() const;
	shared_ptr<Offre> obtenirOffreSpecifique(const string& nom) const;

private:
	string nom;
	vector<shared_ptr<Offre>> offres;
};