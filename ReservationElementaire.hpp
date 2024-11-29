#pragma once
#include "Reservation.hpp"
#include "OffreProxy.hpp"

class ReservationElementaire : public Reservation {
public:
	//override maybe

	//inherited methods
	/*
	void afficher() const;
	void afficherDate() const;
	void afficherId() const;
	void afficherNom() const;
	void ajouterReservation(Reservation r);
	string obtenirDate() const;
	vector<string> obtenirDetails() const;
	void supprimerReservation(Reservation r);
	*/

	//new
	string obtenirContactVendeur() const;
	string obtenirDateAchat() const;
	string obtenirNomVendeur() const;

private:
	string contactVendeur; // email, telephone?
	string dateAchat;
	string nomVendeur;
	OffreProxy offre; //sinon shared_ptr<Offre>
};

