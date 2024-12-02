#pragma once
#include "ReservationDecorateur.hpp"

class CommentaireReservationDecorateur : public ReservationDecorateur {

public:
    CommentaireReservationDecorateur(shared_ptr<Reservation>& reservation, const string& commentaire)
        : ReservationDecorateur(reservation), commentaire(commentaire) {}
    virtual ~CommentaireReservationDecorateur() = default;

    void changerCommentaire(const string& com);
    void supprimerCommentaire();
    const string& obtenirCommentaire();
    void afficherInfo();
private:
    string commentaire;
};
