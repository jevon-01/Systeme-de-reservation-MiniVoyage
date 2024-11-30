#pragma once
#include "Offre.hpp"
#include "string"

class Vol : public Offre {
public:
	Vol(const string& categorie, vector<string> details, const Devise dev, const string& nom, const double p, const string& transporteur, const string& noVol, const string& lieuDepart, const string& lieuArrivee, const string& jourDepart, const string& heureDepart, const string& jourArrivee, const string& heureArrivee, const string& nomAvion, const string& classe,
	bool wifi ) : Offre(categorie, details,dev, nom, p), transporteur(transporteur), noVol(noVol), lieuDepart(lieuDepart), lieuArrivee(lieuArrivee), jourDepart(jourDepart), heureDepart(heureDepart), jourArrivee(jourArrivee), heureArrivee(heureArrivee), nomAvion(nomAvion), classe(classe), wifi(wifi) {};

	vector<string> obtenirDetails() const override;
	string obtenirTransporteur() const;
	string obtenirNumeroVol() const;
	string obtenirLieuDepart() const;
	string obtenirLieuArrivee() const;
	string obtenirJourDepart() const;
	string obtenirHeureDepart() const;
	string obtenirJourArrivee() const;
	string obtenirHeureArrivee() const;
	string obtenirNomAvion() const;
	string obtenirClasse() const;
	bool obtenirWifi() const;
	
	//void reserver(string);

private:
	string transporteur;
	string noVol;
	string lieuDepart;
	string lieuArrivee;
	string jourDepart;
	string heureDepart;
	string jourArrivee;
	string heureArrivee;
	string nomAvion;
	string classe;
	bool wifi;
};

