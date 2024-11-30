#pragma once
#include "Reservation.hpp"

class BDP {
public:
	BDP();
	void afficherReservations();
	void ajouterReservation(const Reservation& reservation);
	void supprimerReservation(const string& nom);
	void supprimerTousReservations();
	vector<Reservation>& obtenirReservations();
	
private:
	vector<shared_ptr<Reservation>> reservations;

};