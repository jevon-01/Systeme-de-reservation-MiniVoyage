#pragma once
#include "Reservation.hpp"

class ReservationComposite : public Reservation {
public:
	void afficher() const;
	void afficherDate() const;
	void afficherId() const;
	void afficherNom() const;
	void ajouterReservation(Reservation r);
	string obtenirDate() const;
	vector<string> obtenirDetails() const;
	void supprimerReservation(Reservation r);
private:
	vector<shared_ptr<Reservation>> reservations;
};

