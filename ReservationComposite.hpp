#pragma once
#include "Reservation.hpp"
#include "Offre.hpp"
#include "iostream"

class ReservationComposite : public Reservation {
public:
	ReservationComposite(const string& nom, const string& date) : Reservation(nom, date) {}
	ReservationComposite(const string& nom, const ReservationComposite& other);
	virtual ~ReservationComposite() = default;

	void ajouterReservation(shared_ptr<Reservation> r) override;
	void supprimerReservation(shared_ptr<Reservation> r) override;
	void afficherTout() const;
	void afficherVoyage(int i, string& prec) const;
	const double calculerPrixTotal() override;
	vector<shared_ptr<Reservation>>& obtenirReservations();
	shared_ptr<Reservation> obtenirReservationSpecifique(const string& r, const string& date);
	shared_ptr<Reservation> remplacerReservation(const string& r, const string& date, shared_ptr<Reservation> res);
	void creerJournalisation(const string& nomJournal, string& journeePrec, int indentlevel = 0) const;
	shared_ptr<Reservation> changerOffre(shared_ptr<Offre> ptr);
	shared_ptr<Reservation> inflationAnnuelle();
private:
	vector<shared_ptr<Reservation>> reservations;

};
