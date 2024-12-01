#include "iostream"
#include "BDOR.hpp"
#include "OffreProxy.hpp"
#include "Reservation.hpp"
#include "ReservationComposite.hpp"
#include "ReservationElementaire.hpp"
#include "BDP.hpp"

using namespace std;

void creationVoyageDora(const BDOR& bDOR, BDP& bDP) {
	vector<pair<string, vector<pair<string, vector<string>>>>> segmentsEtJours = {
	{"Segment France 1ère partie", {
		{"2024-10-26", {"Air Canada AC 870 2024-10-26"}},
		{"2024-10-27", {"Hotel Stella"}},
		{"2024-10-28", {"Paris Diner-croisiere sur la Seine by Bateaux Mouches", "Hotel Stella"}}
	}},
	{"Segment Portugal", {
		{"2024-10-29", {"TAP Air Portugal TP 441 2024-10-29", "Hotel Roma"}},
		{"2024-10-30", {"Visite du Musee Calouste-Gulbenkian", "Hotel Roma"}},
		{"2024-10-31", {"easyJet 4592 2024-10-31"}}
	}},
	{"Segment France 2e partie", {
		{"2024-10-31", {"Hotel Stella"}},
		{"2024-11-01", {"Visite guidee pour voir les chefs-d'œuvre du musee du Louvre", "Hotel Stella"}},
		{"2024-11-02", {"Visite guidee a Versailles et acces prioritaire avec transfert depuis l'hotel au depart de Paris", "Hotel Stella"}},
		{"2024-11-03", {"Air Transat 111 2024-11-03"}}
	}}
	};

	shared_ptr<ReservationComposite> groupe = make_shared<ReservationComposite>("Voyage de Dora", "2024");
	cout << groupe->obtenirNom() << " cree!\n";
	bDP.ajouterReservation(groupe);

	for (const auto& seg : segmentsEtJours) {

		shared_ptr<ReservationComposite> segment = make_shared<ReservationComposite>(seg.first, "2024");
		cout << "  ";
		cout << segment->obtenirNom() << " cree dans le " << groupe->obtenirNom() << "!\n";
		groupe->ajouterReservation(segment);

		for (const auto& jour : seg.second) {

			shared_ptr<ReservationComposite> jourSeg = make_shared<ReservationComposite>(jour.first, jour.first);
			segment->ajouterReservation(jourSeg);
			cout << "    ";
			cout << "Journee " << jourSeg->obtenirNom() << " creee dans le " << seg.first << "!\n";

			for (const auto& reservation : jour.second) {
				shared_ptr<Offre> ptrOffreReservation = bDOR.obtenirOffre(reservation); //Fix les accents et enlever commentaire et effacer la ligne suivante. 
				//shared_ptr<Offre> ptrOffreReservation = bDOR.obtenirOffre("Hotel Stella"); 
				shared_ptr<ReservationElementaire> res = make_shared<ReservationElementaire>(ptrOffreReservation->obtenirNom(), jourSeg->obtenirNom(), "514", jourSeg->obtenirDate(), "2024", ptrOffreReservation);
				jourSeg->ajouterReservation(res);
				cout << "      ";
				cout << "Reservation creee : " << groupe->obtenirNom() << "/" << jourSeg->obtenirDate() << "/" << ptrOffreReservation->obtenirNom() << "!\n";
			}

		}

	}
}

int main() {

	BDOR bDOR;
	BDP bDP;

	cout << "\n==============================" << endl;
	//test
	shared_ptr<Offre> ptrOffre = bDOR.obtenirOffre("Hotel Stella");
	cout << ptrOffre->obtenirNom() << " " 
		 << ptrOffre->obtenirCategorie() << endl;

	//Creer reservation avec le ptrOffre


	//Création voyage Dora
	creationVoyageDora(bDOR,bDP);

	//bDOR.afficherOffres(); //affiche les noms de toutes les offres
	
	return 0;
}

