#pragma once
#include "Reservation.hpp"
#include "ReservationElementaire.hpp"
#include "iostream"

class ReservationDecorateur : public Reservation { 
public:

    ReservationDecorateur(shared_ptr<Reservation>& p) : Reservation(p->obtenirNom(), p->obtenirDate()), reservationBase(p) {}
    virtual ~ReservationDecorateur() = default;

    const double calculerPrixTotal() override;
    
protected:
    shared_ptr<Reservation> reservationBase;
};