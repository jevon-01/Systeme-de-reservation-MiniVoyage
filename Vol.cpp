#include "Vol.hpp"

using namespace std;

const string& Vol::obtenirTransporteur() const {
    return transporteur;
}

const string& Vol::obtenirNumeroVol() const {
    return noVol;
}

const string& Vol::obtenirLieuDepart() const {
    return lieuDepart;
}

const string& Vol::obtenirLieuArrivee() const {
    return lieuArrivee;
}

const string& Vol::obtenirJourDepart() const {
    return jourDepart;
}

const string& Vol::obtenirHeureDepart() const {
    return heureDepart;
}

const string& Vol::obtenirJourArrivee() const {
    return jourArrivee;
}

const string& Vol::obtenirHeureArrivee() const {
    return heureArrivee;
}

const string& Vol::obtenirNomAvion() const {
    return nomAvion;
}

const string& Vol::obtenirClasse() const {
    return classe;
}

const string& Vol::obtenirWifi() const {
    return wifi;
}
