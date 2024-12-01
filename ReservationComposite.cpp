#include "ReservationComposite.hpp"

//TODO
void ReservationComposite::ajouterReservation(shared_ptr<Reservation> r) {
	reservations.push_back(r);
}

void ReservationComposite::supprimerReservation(shared_ptr<Reservation> r) {
	for (auto it = reservations.begin(); it != reservations.end(); ++it) {
		if ((*it)->obtenirNom() == r->obtenirNom()) {
			reservations.erase(it);
			return;
		}
	}
	
}

void ReservationComposite::afficherTout() const {
	for (const auto& r : reservations) {
		r->afficherInfo();
	}
}