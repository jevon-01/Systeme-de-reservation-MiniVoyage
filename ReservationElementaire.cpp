#include "ReservationElementaire.hpp"
#include "ReservationComposite.hpp"
#include "Devise.hpp"

const string& ReservationElementaire::obtenirContactVendeur() const {
	return contactVendeur;
}

const string& ReservationElementaire::obtenirDateAchat() const {
	return dateAchat;
}
const string& ReservationElementaire::obtenirNomVendeur() const {
	return nomVendeur;
}

OffreProxy& ReservationElementaire::obtenirOffre() {
	return offre;
}

const double ReservationElementaire::calculerPrixTotal() {
	return offre.calculerPrixTotal();
}

void ReservationElementaire::changerOffre(shared_ptr<Offre> ptr) {
	offre.changerOffre(ptr);
}
