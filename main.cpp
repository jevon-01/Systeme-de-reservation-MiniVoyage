#include "iostream"
#include "BDOR.hpp"
#include "BDP.hpp"

using namespace std;

int main() {
	// Étape 1 – Création de la base de données des offres de réservation
	BDOR bDOR;

	cout << "\n==============================" << endl;
	//test
	shared_ptr<Offre> ptrOffre = bDOR.obtenirOffre("Hotel Stella", "Hebergement");
	cout << ptrOffre->obtenirNom() << " " 
		 << ptrOffre->obtenirCategorie() << endl;

	cout << "\n==============================" << endl;

	BDP bDP;
	// Étape 2 – Création d’un premier voyage
	// 2.1 – Voyage de Dora
	// 2.1 Creer reservation avec le ptrOffre
	string nom = "Voyage de Dora";
	


	//bDOR.afficherOffres(); //affiche les noms de toutes les offres
	
	return 0;
}