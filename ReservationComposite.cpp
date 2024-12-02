#include "ReservationComposite.hpp"
#include "CommentaireReservationDecorateur.hpp"
#include "AjoutReservationDecorateur.hpp"

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
		else if (auto dec = dynamic_cast<CommentaireReservationDecorateur*>(reserv.get())) {
			dec->afficherInfo();
		}
		else if (auto dec = dynamic_cast<AjoutReservationDecorateur*>(reserv.get())) {
			dec->afficherInfo();
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

shared_ptr<Reservation> ReservationComposite::obtenirReservationSpecifique(const string& r, const string& date) {
	for (const auto& reserv : reservations) {
		
		if (auto composite = dynamic_cast<ReservationComposite*>(reserv.get())) {
	
			auto result = composite->obtenirReservationSpecifique(r, date);
			if (result) {
				return result; 
			}
		}

		if (reserv->obtenirNom() == r && reserv->obtenirDate() == date) {
			
			return reserv;
		}
	}
	
	return nullptr;
}

shared_ptr<Reservation> ReservationComposite::remplacerReservation(const string& r, const string& date, shared_ptr<Reservation> res) {
	for (auto& reserv : reservations) {

		if (auto composite = dynamic_cast<ReservationComposite*>(reserv.get())) {

			auto result = composite->remplacerReservation(r, date, res);
			if (result) {
				return result; 
			}
		}

		if (reserv->obtenirNom() == r && reserv->obtenirDate() == date) {
			reserv = res; 
			return reserv; 
		}
	}
	
	return nullptr;
}

void ReservationComposite::afficherVoyage(int indentLevel) const {

	string indent(indentLevel * 2, ' ');
	if (obtenirDate() == obtenirNom()) {
		cout << indent << "Journee " << obtenirNom() << ":\n";
	}
	else {
		string nom = obtenirNom();
		if (nom.find("Segment")) {
			cout << indent << obtenirNom() << ":\n";
			indentLevel = indentLevel - 1;
		}
	}
	
	for (const auto& s : reservations) {
		if (auto composite = dynamic_cast<const ReservationComposite*>(s.get())) {
			
			composite->afficherVoyage(indentLevel + 1);
		}
		else if (auto commentaire = dynamic_cast<CommentaireReservationDecorateur*>(s.get())) {
	
			cout << indent << "  " << "Reservation " << commentaire->obtenirNom() << ", prix total ($ CA): " << commentaire->calculerPrixTotal() << ".\n";

			cout << indent << indent << "  " << "Commentaire: " << commentaire->obtenirCommentaire() << endl;
		}
		else if (auto ajout = dynamic_cast<AjoutReservationDecorateur*>(s.get())) {
	
			cout << indent << "  " << "Reservation " << ajout->obtenirNom() << ", prix total ($ CA): " << ajout->calculerPrixTotal() << ".\n";

			cout << indent << indent << "Reservation " << ajout->obtenirNomSousReservation() << endl;
		}
		else {
			cout << indent << "  " << "Reservation " << s->obtenirNom() << ", prix total ($ CA): " << s->calculerPrixTotal() << ".\n";
		}
	}
}