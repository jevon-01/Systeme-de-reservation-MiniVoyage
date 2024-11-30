#pragma once
#include "Reservation.hpp"

class BDP {
public:
	BDP();
	void afficherReservations();
	void ajouterReservation(const shared_ptr<Reservation>& reservation);
	void supprimerReservation(const string& nom);
	void supprimerTousReservations();
	vector<shared_ptr<Reservation>>& obtenirReservations();
	
private:
	vector<shared_ptr<Reservation>> reservations;

};
