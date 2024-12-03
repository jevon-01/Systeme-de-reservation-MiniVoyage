#pragma once
#include "Offre.hpp"

class OffreDecorateur : public Offre {

public:

    OffreDecorateur(shared_ptr<Offre> ptr, const string& commentaire, const string& categorie, const string& nom, const double p) :
        Offre(ptr->obtenirCategorie(), ptr->obtenirNom(), ptr->obtenirPrix(), ptr->obtenirDevise(), false), offreBase(ptr), commentaire(commentaire) {}
    virtual ~OffreDecorateur() = default;

    void appliquerRabais(double rabais);
    void appliquerRabaisPourcentage(double pourcentage);
    const string& obtenirCommentaire() const;
    void modifierCommentaire(const string& newCom);

private:
    shared_ptr<Offre> offreBase;
    string commentaire;
};