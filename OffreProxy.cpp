#include "OffreProxy.hpp"

const double OffreProxy::calculerPrixTotal() const {
	return ptrOffre->calculerPrixTotal();
}

const string& OffreProxy::obtenirCategorie() const {
	return ptrOffre->obtenirCategorie();
}

const string& OffreProxy::obtenirNom() const {
	return ptrOffre->obtenirNom();
}

void OffreProxy::reserver(const string& nom) {
	ptrOffre->reserver(nom);
}