#include "iostream"
#include "BDOR.hpp"

using namespace std;

int main() {
	BDOR bDOR;

	cout << "\n==============================" << endl;
	//test
	shared_ptr<Offre> ptrOffre = bDOR.obtenirOffre("Hotel Stella", "Hebergement");
	cout << ptrOffre->obtenirNom() << " " 
		 << ptrOffre->obtenirCategorie() << endl;

	//Creer reservation avec le ptrOffre

	//bDOR.afficherOffres(); //affiche les noms de toutes les offres
	
	return 0;
}