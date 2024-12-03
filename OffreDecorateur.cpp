#include "OffreDecorateur.hpp"

void OffreDecorateur::appliquerRabais(double rabais) {
	offreBase->changerPrix(offreBase->obtenirPrix() - rabais);
}

const string& OffreDecorateur::obtenirCommentaire() const {
	return commentaire;
}
void OffreDecorateur::modifierCommentaire(const string& newCom) {
	commentaire = newCom;
}

void OffreDecorateur::appliquerRabaisPourcentage(double pourcentage) {
	offreBase->changerPrix(offreBase->obtenirPrix() * (1.00 + (pourcentage/100)));
}
