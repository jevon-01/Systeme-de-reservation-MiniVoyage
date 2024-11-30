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

const vector<string>& Reservation::obtenirDetails() const {
	return details;
}