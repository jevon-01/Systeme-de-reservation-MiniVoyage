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

	//si erreur
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filePath << std::endl;
		return;
	}

	string line;
	getline(file, line); //skip la 1ere row
	while (getline(file, line)) {
		size_t start = 0;
		size_t end;
		vector<string> v;
		while ((end = line.find(',', start)) != std::string::npos) {
			v.push_back(line.substr(start, end - start)); // Extract the field
			start = end + 1; // Move to the next character after the comma
		}
		
		/*for (const auto& e : v) {
			cout << e << endl;
		}*/

		/*const string& categorie,
		vector<string> details,
				const Devise dev, removed
		const string& nom,
		const double prix,
		const string& transporteur,
		const string& noVol,
		const string& lieuDepart,
		const string& lieuArrivee,
		const string& jourDepart,
		const string& heureDepart,
		const string& jourArrivee, 
		const string& heureArrivee, 
		const string& nomAvion, 
		const string& classe,
		bool wifi*/

		//index 0 a 13
		shared_ptr<Vol> vol = make_shared<Vol>("Vols", vector<string>{ "pas de details" }, v[0], stod(v[12]), v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11]);
		ajouterOffre(vol);
	}
}

void Categorie::ajouterOffre(shared_ptr<Offre> offre) {
	offres.push_back(offre);
}

void Categorie::definirHebergement() {

}
void Categorie::definirExcursions() {

}

void Categorie::afficherCategorie() const {
	cout << nom << endl;
}

void Categorie::afficherOffres() const {
	for (auto offre : offres) {
		offre->afficherDetails();
	}
}
