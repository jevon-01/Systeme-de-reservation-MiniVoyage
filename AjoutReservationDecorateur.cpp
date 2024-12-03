#include "AjoutReservationDecorateur.hpp"
#include "iostream"

void AjoutReservationDecorateur::annulerReservation() {
	sousReservation = nullptr;
}

void AjoutReservationDecorateur::afficherInfo() {
	reservationBase->afficherInfo();
	if (sousReservation) {
		cout << "  " << sousReservation->obtenirNom() << endl;
	}
}

const string& AjoutReservationDecorateur::obtenirNomSousReservation() {
	return sousReservation->obtenirNom();
}
