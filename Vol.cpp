#include "Vol.hpp"

using namespace std;

string Vol::obtenirTransporteur() const {
    return transporteur;
}

string Vol::obtenirNumeroVol() const {
    return noVol;
}

string Vol::obtenirLieuDepart() const {
    return lieuDepart;
}

string Vol::obtenirLieuArrivee() const {
    return lieuArrivee;
}

string Vol::obtenirJourDepart() const {
    return jourDepart;
}

string Vol::obtenirHeureDepart() const {
    return heureDepart;
}

string Vol::obtenirJourArrivee() const {
    return jourArrivee;
}

string Vol::obtenirHeureArrivee() const {
    return heureArrivee;
}

string Vol::obtenirNomAvion() const {
    return nomAvion;
}

string Vol::obtenirClasse() const {
    return classe;
}

string Vol::obtenirWifi() const {
    return wifi;
}

vector<string> Vol::obtenirDetails() const {
    return {
        transporteur,
        noVol,
        lieuDepart,
        lieuArrivee,
        jourDepart,
        heureDepart,
        jourArrivee,
        heureArrivee,
        nomAvion,
        classe,
        wifi
    };
}

//TODO
void Vol::reserver(const string& nom) {
    
}