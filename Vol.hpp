#pragma once
#include "Offre.hpp"
#include "string"

class Vol : public Offre {
public:
	Vol(const string& categorie, const vector<string>& details, const string& nom, const double p, const string& transporteur, const string& noVol, const string& lieuDepart, const string& lieuArrivee, const string& jourDepart, const string& heureDepart, const string& jourArrivee, const string& heureArrivee, const string& nomAvion, const string& classe,
	const string& wifi, const Devise& d) : Offre(categorie, details, nom, p, d), transporteur(transporteur), noVol(noVol), lieuDepart(lieuDepart), lieuArrivee(lieuArrivee), jourDepart(jourDepart), heureDepart(heureDepart), jourArrivee(jourArrivee), heureArrivee(heureArrivee), nomAvion(nomAvion), classe(classe), wifi(wifi) {};

	/*const vector<string>& obtenirDetails() const override;*/
	const string& obtenirTransporteur() const;
	const string& obtenirNumeroVol() const;
	const string& obtenirLieuDepart() const;
	const string& obtenirLieuArrivee() const;
	const string& obtenirJourDepart() const;
	const string& obtenirHeureDepart() const;
	const string& obtenirJourArrivee() const;
	const string& obtenirHeureArrivee() const;
	const string& obtenirNomAvion() const;
	const string& obtenirClasse() const;
	const string& obtenirWifi() const;
	
	void reserver(const string& nom) override;

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
	string wifi;
};

