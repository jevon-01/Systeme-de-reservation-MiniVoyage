#pragma once
#include "Offre.hpp"

class Hebergement : public Offre {
public:
	Hebergement();
	void afficherDetails() const override;
};

