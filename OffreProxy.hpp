#pragma once
#include "Offre.hpp"
#include "memory"

class OffreProxy : public Offre {
public:
	OffreProxy();
	virtual void afficherDetails() const;
	double calculerPrixTotal() const;
	string obtenirCategorie() const;
	vector<string> obtenirDetails() const;
	string obtenirNom() const;
private:
	shared_ptr<Offre> ptrOffre;
};

