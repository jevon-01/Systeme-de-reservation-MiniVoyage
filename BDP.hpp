#pragma once
#include "Reservation.hpp"

class BDP {
public:
	BDP();
	~BDP() = default;
	void afficherReservations();
	void supprimerTousReservations();
	void ajouterReservation(const shared_ptr<Reservation>& reservation);
	void supprimerReservation(const string& nom);
	vector<shared_ptr<Reservation>>& obtenirReservations();
	
private:
	vector<shared_ptr<Reservation>> reservations;
};
