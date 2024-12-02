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
	const OffreProxy& obtenirOffre() const;
	const double calculerPrixTotal() override;
private:
	string contactVendeur;
	string dateAchat;
	string nomVendeur;
	OffreProxy offre;
};

