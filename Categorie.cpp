#include "Categorie.hpp"
#include "memory"
#include "iostream"
#include "fstream"
#include "Vol.hpp"
#include "Hebergement.hpp"
#include "Excursion.hpp"

using namespace std;

//3 type de categorie, Vol, Hebergement et Excursions
Categorie::Categorie(const string& nom) : nom(nom) {
	if (nom == "Vols")
		definirVols();
	else if (nom == "Hebergement")
		definirHebergement();
	else if (nom == "Excursions")
		definirExcursions();
}
void Categorie::definirVols() {
	string filePath = "MV_offres_de_reservation_Vols.csv";
	ifstream file(filePath);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filePath << std::endl;
		return;
	}

	string line;
	getline(file, line);
	while (getline(file, line)) {
		size_t start = 0;
		size_t end;
		vector<string> v;
		while ((end = line.find(',', start)) != std::string::npos) {
			v.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		v.push_back(line.substr(start));
		shared_ptr<Vol> vol = make_shared<Vol>("Transport", v[0], stod(v[12]), v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[13]);
		ajouterOffre(vol);
	}
}

void Categorie::definirHebergement() {
	string filePath = "MV_offres_de_reservation_Hebergement.csv";
	ifstream file(filePath);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filePath << std::endl;
		return;
	}

	string line;
	getline(file, line);
	while (getline(file, line)) {
		size_t start = 0;
		size_t end;
		vector<string> v;
		while ((end = line.find(',', start)) != std::string::npos) {
			v.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		v.push_back(line.substr(start));
		shared_ptr<Hebergement> heb = make_shared<Hebergement>("Hebergement", v[0], stod(v[4]), v[1], v[2], stod(v[3]), v[5]);
		ajouterOffre(heb);
	}
}

void Categorie::definirExcursions() {
	string filePath = "MV_offres_de_reservation_Excursions.csv";
	ifstream file(filePath);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filePath << std::endl;
		return;
	}

	string line;
	getline(file, line);
	while (getline(file, line)) {
		size_t start = 0;
		size_t end;
		vector<string> v;
		while ((end = line.find(',', start)) != std::string::npos) {
			v.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		v.push_back(line.substr(start));
		shared_ptr<Excursion> exc = make_shared<Excursion>("Excursion", v[0], stod(v[3]), v[1], stoi(v[2]), v[4]);
		ajouterOffre(exc);
	}
}

void Categorie::ajouterOffre(shared_ptr<Offre> offre) {
	offres.push_back(offre);
}

void Categorie::afficherCategorie() const {
	cout << nom << endl;
}

void Categorie::afficherOffres() const {
	for (const auto& offre : offres) {
		cout << offre->obtenirNom() << endl;
	}
}

const vector<shared_ptr<Offre>>& Categorie::obtenirOffres() const {
	return offres;
}


vector<shared_ptr<Offre>>& Categorie::obtenirOffresNonConst() {
	return offres;
}

const string& Categorie::obtenirNomCategorie() const {
	return nom;
}

shared_ptr<Offre> Categorie::obtenirOffreSpecifique(const string& nom) const {
	for (const auto& ptrOffre : offres) {
		if (ptrOffre->obtenirNom() == nom)
			return ptrOffre;
	}
}