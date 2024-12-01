#include "ReservationElementaire.hpp"

const string& ReservationElementaire::obtenirContactVendeur() const {
	return contactVendeur;
}

const string& ReservationElementaire::obtenirDateAchat() const {
	return dateAchat;
}
const string& ReservationElementaire::obtenirNomVendeur() const {
	return nomVendeur;
}

const OffreProxy& ReservationElementaire::obtenirOffre() const {
	return offre;
}

//TODO
void  ReservationElementaire::ajouterReservation(shared_ptr<Reservation> r) {

}

void  ReservationElementaire::supprimerReservation(shared_ptr<Reservation> r) {

}