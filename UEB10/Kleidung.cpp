#include "Kleidung.h"

namespace artikel {
	Kleidung::Kleidung(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double size, std::string colour)
		: Artikel(artikelNr, bezeichnung, artikelPreis, bestand), size(size), colour(colour){}

	void Kleidung::ausgeben(std::ostream& o) const {
		Artikel::ausgeben(o);
		o << "\tGroesse: " << size << "\tFarbe: " << colour;
	}
	void Kleidung::eingeben(std::istream& in) {
		Artikel::eingeben(in);
		in >> size >> colour;
	}
	void Kleidung::setSize(double newSize) { size = newSize; }
	double Kleidung::getSize() const   { return size; }

	void Kleidung::setColour(std::string newColour) { colour = newColour; }
	std::string Kleidung::getColour() const   { return colour; }
}
