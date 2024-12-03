#include "OffreProxy.hpp"

const double OffreProxy::calculerPrixTotal()  {
	return ptrOffre->calculerPrixTotal();
}

const string& OffreProxy::obtenirCategorie() const {
	return ptrOffre->obtenirCategorie();
}

const string& OffreProxy::obtenirNom() const {
	return ptrOffre->obtenirNom();
}
shared_ptr<Offre>& OffreProxy::obtenirOffre() {
	return ptrOffre;
}