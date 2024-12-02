#include "Reservation.hpp"
#include "iostream"

using namespace std;

void Reservation::afficherInfo() const {
	cout << nom << " " << date << endl;
}

const string& Reservation::obtenirNom() const {
	return nom;
}

const string& Reservation::obtenirDate() const {
	return date;
}

void Reservation::ajouterReservation(shared_ptr<Reservation> r) {
	return;
}
void Reservation::supprimerReservation(shared_ptr<Reservation> r) {
	return;
}