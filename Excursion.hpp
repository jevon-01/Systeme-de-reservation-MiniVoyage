#pragma once
#include "Offre.hpp"
#include "string"

using namespace std;

class Excursion : public Offre {
public:
	Excursion();
	void afficherDetails() const override;

private:
	string lieu;
};

