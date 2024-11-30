#include "BDOR.hpp"
#include "iostream"

using namespace std;

BDOR::BDOR() {
	cout << "Objet BDOR cree!" << endl;
	
	Categorie vol = new Categorie("Vol");

	ajouterCategorie();
}