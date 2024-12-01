#pragma once
#include "Reservation.hpp"

class ReservationComposite : public Reservation {
public:

	//void afficher() const;
	/*void afficherDate() const;
	void afficherId() const;
	void afficherNom() const;*/

	void ajouterReservation(Reservation r);
	const string& obtenirDate() const;
	const vector<string>& obtenirDetails() const;

	void ajouterReservation(shared_ptr<Reservation> r) override;
	virtual void supprimerReservation(shared_ptr<Reservation> r) override;
private:
	vector<shared_ptr<Reservation>> reservations;
};

