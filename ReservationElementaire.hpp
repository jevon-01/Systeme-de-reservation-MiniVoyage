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
	ReservationElementaire(const string& nom, const string& date, const vector<string>& details, const string& contact, const string& dateAchat, const string& nomVendeur, shared_ptr<Offre> ptrOffre) : Reservation(nom, date, details), contactVendeur(contact), dateAchat(dateAchat), nomVendeur(nomVendeur), offre(OffreProxy(ptrOffre)) {}
	virtual ~ReservationElementaire() = default;
	const string& obtenirContactVendeur() const;
	const string& obtenirDateAchat() const;
	const string& obtenirNomVendeur() const;
	const OffreProxy& obtenirOffre() const;
	void ajouterReservation(shared_ptr<Reservation> r) override;
	void supprimerReservation(shared_ptr<Reservation> r) override;
private:
	string contactVendeur; // email
	string dateAchat;
	string nomVendeur;
	OffreProxy offre;
};

