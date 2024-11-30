#include "iostream"
#include "BDOR.hpp"

using namespace std;

int main() {
	cout << "Hello" << endl;
	BDOR a;
	a.afficherOffres();
	cout << "\n==============================" << endl;
	Categorie c = Categorie("Vols");
	//c.afficherOffres();
	//c.afficherCategorie();
	return 0;
}