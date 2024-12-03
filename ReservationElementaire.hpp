#pragma once
#include "Reservation.hpp"
#include "OffreProxy.hpp"

class ReservationElementaire : public Reservation {
public:
	ReservationElementaire(const string& nom, const string& date, const string& contact, const string& dateAchat, const string& nomVendeur, shared_ptr<Offre>& ptrOffre) : Reservation(nom, date), contactVendeur(contact), dateAchat(dateAchat), nomVendeur(nomVendeur), offre(OffreProxy(ptrOffre)) {}
	virtual ~ReservationElementaire() = default;
	const string& obtenirContactVendeur() const;
	const string& obtenirDateAchat() const;
	const string& obtenirNomVendeur() const;
	OffreProxy& obtenirOffre();
	const double calculerPrixTotal() override;

	void changerOffre(shared_ptr<Offre> ptr);

private:
	string contactVendeur;
	string dateAchat;
	string nomVendeur;
	OffreProxy offre;
};
