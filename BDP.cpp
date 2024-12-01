#include "BDP.hpp"
#include "iostream"

BDP::BDP() {}

void BDP::afficherReservations() {
	for (const auto& r : reservations) {
		r->afficherInfo();
	}
}

void BDP::ajouterReservation(const string& nom, const string& date, const vector<string>& details) {
	/*const auto& r = make_shared<Reservation>(nom, date, details);
	reservations.push_back(r);*/
}


void BDP::ajouterReservation(const shared_ptr<Reservation>& reservation) {
	reservations.push_back(reservation);
}

vector<shared_ptr<Reservation>>& BDP::obtenirReservations() {
	return reservations;
}

void BDP::supprimerReservation(const string& nom) {
	for (auto it = reservations.begin(); it != reservations.end(); ++it) {
		if ((*it)->obtenirNom() == nom) {
			reservations.erase(it);
			return; 
		}
	}
}

void BDP::supprimerTousReservations() {
	reservations.clear();
}
