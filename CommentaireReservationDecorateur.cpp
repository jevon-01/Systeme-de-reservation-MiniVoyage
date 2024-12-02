#include "CommentaireReservationDecorateur.hpp"
#include "iostream"

void CommentaireReservationDecorateur::changerCommentaire(const string& com) {
	commentaire = com;
}

void CommentaireReservationDecorateur::supprimerCommentaire() {
	commentaire = "";
}

const string& CommentaireReservationDecorateur::obtenirCommentaire() {
	return commentaire;
}

void CommentaireReservationDecorateur::afficherInfo() {
	reservationBase->afficherInfo();
	cout << "   Commentaire: " << commentaire << endl;
}
