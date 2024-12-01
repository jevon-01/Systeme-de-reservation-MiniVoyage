#pragma once
#include "Offre.hpp"
#include "memory"

class OffreProxy : public Offre {
public:
	OffreProxy(shared_ptr<Offre>& offre)
		: Offre(offre->obtenirCategorie(), offre->obtenirNom(), offre->calculerPrixTotal(), offre->obtenirDevise(), false),
		ptrOffre(offre) {}
	~OffreProxy() override = default;
	const double calculerPrixTotal() override;
	const string& obtenirCategorie() const override;
	const string& obtenirNom() const override;

private:
	shared_ptr<Offre> ptrOffre;
};
