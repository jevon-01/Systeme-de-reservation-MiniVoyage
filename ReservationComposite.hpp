#pragma once
#include "Reservation.hpp"
#include "iostream"

class ReservationComposite : public Reservation {
public:

	//void afficher() const;
	/*void afficherDate() const;
	void afficherId() const;
	void afficherNom() const;*/
	//const string& obtenirDate() const;
	ReservationComposite(const string& nom, const string& date) : Reservation(nom, date) {}
	virtual ~ReservationComposite() = default;

	void ajouterReservation(shared_ptr<Reservation> r) override;
	void supprimerReservation(shared_ptr<Reservation> r) override;
	void afficherTout() const;
private:
	vector<shared_ptr<Reservation>> reservations;
};
