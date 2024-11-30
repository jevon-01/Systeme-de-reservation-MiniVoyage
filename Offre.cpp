#include "Offre.hpp"
#include "iostream"

using namespace std;

void Offre::messageDeCreation() const {
	cout << "Entree " << obtenirNom() << " rattachee a la categorie " << obtenirCategorie() << " creee!" << endl;
}
