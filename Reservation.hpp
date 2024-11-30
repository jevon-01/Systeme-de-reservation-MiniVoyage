#pragma once
#include "string"
#include "vector"
#include "memory"

using namespace std;

class Reservation {
public:
	//maybe virtual
	void afficher() const;
	void afficherDate() const;
	void afficherNom() const;
	void ajouterReservation(Reservation r); //might be shared_ptr<Reservation>
	string obtenirDate() const;
	string obtenirNom() const;
	vector<string> obtenirDetails() const;
	void supprimerReservation(Reservation r); //might be shared_ptr<Reservation>
private:
	string nom;
	string date;
	vector<string> details;
};

