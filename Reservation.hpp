#pragma once
#include "string"
#include "vector"
#include "memory"

using namespace std;

class Reservation {
public:
	//maybe virtual
	Reservation(const string& nom, const string& date) : nom(nom), date(date) {}
	~Reservation() = default;
	void afficherInfo() const;
	const string& obtenirDate() const;
	const string& obtenirNom() const;
	virtual void ajouterReservation(shared_ptr<Reservation> r) = 0;
	virtual void supprimerReservation(shared_ptr<Reservation> r) = 0;
	virtual const double calculerPrixTotal() = 0;
private:
	string nom;
	string date;
};
