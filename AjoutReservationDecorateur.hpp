#pragma once
#include "ReservationDecorateur.hpp"

class AjoutReservationDecorateur : public ReservationDecorateur {

public:
    AjoutReservationDecorateur(shared_ptr<Reservation> reservationBase, shared_ptr<Reservation> sousReserv) : ReservationDecorateur(reservationBase), sousReservation(sousReserv) {}
    virtual ~AjoutReservationDecorateur() = default;
    void annulerReservation();
    void afficherInfo();
    const string& obtenirNomSousReservation();

private:
    shared_ptr<Reservation> sousReservation;
};
