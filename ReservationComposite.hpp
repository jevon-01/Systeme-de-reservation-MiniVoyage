#pragma once
#include "Reservation.hpp"
#include "iostream"

class ReservationComposite : public Reservation {
public:

	ReservationComposite(const string& nom, const string& date) : Reservation(nom, date) {}
	ReservationComposite(const string& nom, const ReservationComposite& other);
	virtual ~ReservationComposite() = default;

	void ajouterReservation(shared_ptr<Reservation> r) override;
	void supprimerReservation(shared_ptr<Reservation> r) override;
	void afficherTout() const;
	const double calculerPrixTotal() override;
private:
	vector<shared_ptr<Reservation>> reservations;

};
