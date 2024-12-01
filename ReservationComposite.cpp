#include "ReservationComposite.hpp"

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

ReservationComposite::ReservationComposite(const string& nom, const ReservationComposite& other)
	: Reservation(nom, other.obtenirDate()) {
	for (const auto& r : other.reservations) {
		if (auto composite = dynamic_cast<ReservationComposite*>(r.get())) {
			reservations.push_back(make_shared<ReservationComposite>(*composite));
		}
		else {
			reservations.push_back(r); 
		}
	}
}

void ReservationComposite::afficherTout() const {
	for (const auto& reserv : reservations) {
	
		if (auto composite = dynamic_cast<const ReservationComposite*>(reserv.get())) {
		
			composite->afficherTout();
		}
		else {
			reserv->afficherInfo();
		}
	}
}

const double ReservationComposite::calculerPrixTotal() {
	
	double prixTotal = 0.0;

	for (const auto& reserv : reservations) {

		if (auto composite = dynamic_cast<ReservationComposite*>(reserv.get())) {
			prixTotal += composite->calculerPrixTotal();
		}
		else {
			prixTotal += reserv->calculerPrixTotal();
		}
	}

	return prixTotal;
}