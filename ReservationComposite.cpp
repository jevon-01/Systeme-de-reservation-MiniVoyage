#include "ReservationComposite.hpp"
#include "CommentaireReservationDecorateur.hpp"
#include "AjoutReservationDecorateur.hpp"
#include "OffreDecorateur.hpp"
#include "fstream"
#include "filesystem"

using namespace std;

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

void ReservationComposite::afficherVoyage(int indentLevel, string& journeePrec) const {

	string indent(indentLevel * 2, ' ');
	if (obtenirDate() == obtenirNom()) {
		if (journeePrec != obtenirNom()) {
			cout << indent << "Journee " << obtenirNom() << ":\n";
			journeePrec = obtenirNom();
		}
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

			composite->afficherVoyage(indentLevel + 1, journeePrec);
		}
		else if (auto commentaire = dynamic_cast<CommentaireReservationDecorateur*>(s.get())) {

			cout << indent << "  " << "Reservation " << commentaire->obtenirNom() << ", prix total ($ CA): " <<  round(commentaire->calculerPrixTotal()) << ".\n";

			cout << indent << indent << "  " << "Commentaire: " << commentaire->obtenirCommentaire() << endl;
		}
		else if (auto ajout = dynamic_cast<AjoutReservationDecorateur*>(s.get())) {

			cout << indent << "  " << "Reservation " << ajout->obtenirNom() << ", prix total ($ CA): " <<  round(ajout->calculerPrixTotal()) << ".\n";

			cout << indent << indent << "  " << "Reservation " << ajout->obtenirNomSousReservation() << endl;
		}
		else if (auto elem = dynamic_cast<ReservationElementaire*>(s.get())) {
			cout << indent << "  " << "Reservation " << s->obtenirNom() << ", prix total ($ CA): " << round(s->calculerPrixTotal()) << ".\n";
		
			const auto& offreProxy = elem->obtenirOffre();
	
			auto* internalOffre = const_cast<OffreProxy&>(offreProxy).obtenirOffre().get();

			if (auto offreDec = dynamic_cast<OffreDecorateur*>(internalOffre)) {
				cout << indent << indent << "  Commentaire: " << offreDec->obtenirCommentaire() << endl;
			
			}

		}
	}
}

void ReservationComposite::creerJournalisation(const string& nomJournal, string& journeePrec, int indentLevel) const {
	string fileName = "log" + nomJournal + ".txt";
	ofstream outFile;

	string indent(indentLevel * 2, ' ');
	auto writeIndented = [&](const string& message, int level) {
		string indent(level * 2, ' ');
		outFile << indent << message << endl;
		};
	if (indentLevel != 0) {
		outFile.open(fileName, ios::app);
	}
	else {
		outFile.open(fileName);
		writeIndented(obtenirNom() + ":", indentLevel);
	}

	if (obtenirDate() == obtenirNom()) {

		if (journeePrec != obtenirNom()) {
			writeIndented("Journee " + obtenirNom() + ":", indentLevel);
			journeePrec = obtenirNom();
		}

	}
	else {
		string nom = obtenirNom();
		if (nom.find("Segment") != string::npos) {
			indentLevel = indentLevel - 1;
		}
	}
	for (const auto& s : reservations) {
		if (auto composite = dynamic_cast<const ReservationComposite*>(s.get())) {
			composite->creerJournalisation(nomJournal, journeePrec, indentLevel + 1);
		}
		else if (auto commentaire = dynamic_cast<CommentaireReservationDecorateur*>(s.get())) {
			writeIndented(indent + "Reservation " + commentaire->obtenirNom() +
				", prix total ($ CA): " + to_string((int)round(commentaire->calculerPrixTotal())) + ".",
				indentLevel);
			writeIndented(indent + "Commentaire: " + commentaire->obtenirCommentaire(), indentLevel + 1);
		}
		else if (auto ajout = dynamic_cast<AjoutReservationDecorateur*>(s.get())) {
			writeIndented(indent + "Reservation " + ajout->obtenirNom() +
				", prix total ($ CA): " + to_string((int) round(ajout->calculerPrixTotal())) + ".",
				indentLevel);
			writeIndented("Reservation " + ajout->obtenirNomSousReservation(), indentLevel + 1);
		}
		else if (auto elem = dynamic_cast<ReservationElementaire*>(s.get())) {
			writeIndented(indent + "Reservation " + s->obtenirNom() +
				", prix total ($ CA): " + to_string((int)round(s->calculerPrixTotal())) + ".",
				indentLevel); 
			const auto& offreProxy = elem->obtenirOffre();

			auto* internalOffre = const_cast<OffreProxy&>(offreProxy).obtenirOffre().get();

			if (auto offreDec = dynamic_cast<OffreDecorateur*>(internalOffre)) {
				writeIndented(indent + "  Commentaire: " + offreDec->obtenirCommentaire(), indentLevel);

			}
		}
	}
	outFile.close();
}

vector<shared_ptr<Reservation>>& ReservationComposite::obtenirReservations() {
	return reservations;
}

shared_ptr<Reservation> ReservationComposite::changerOffre(shared_ptr<Offre> ptr) {
	for (auto& reserv : reservations) {

		if (auto composite = dynamic_cast<ReservationComposite*>(reserv.get())) {
			composite->changerOffre(ptr);  
		}
	
		else if (auto elem = dynamic_cast<ReservationElementaire*>(reserv.get())) {
			if (elem->obtenirOffre().obtenirNom() == ptr->obtenirNom()) {
				
				elem->obtenirOffre().changerOffre(ptr);
			}
		}
	}
	return nullptr;  
}

shared_ptr<Reservation> ReservationComposite::inflationAnnuelle() {
	for (auto& reserv : reservations) {

		if (auto composite = dynamic_cast<ReservationComposite*>(reserv.get())) {
			composite->inflationAnnuelle();
		}

		else if (auto elem = dynamic_cast<ReservationElementaire*>(reserv.get())) {

			if (elem->obtenirOffre().obtenirCategorie() == "Hebergement") {
				elem->obtenirOffre().changerPrix(elem->obtenirOffre().obtenirPrix() * 1.03);
			}
			else {
				elem->obtenirOffre().changerPrix(elem->obtenirOffre().obtenirPrix() * 1.02);
			}
		}
	}
	return nullptr;
}