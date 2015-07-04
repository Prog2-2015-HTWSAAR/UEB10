#include "Lebensmittel.h"

namespace artikel {

	Lebensmittel::Lebensmittel(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, std::string bestBeforeDate)
		: Artikel(artikelNr, bezeichnung, artikelPreis, bestand), bestBeforeDate(bestBeforeDate) {}

	void Lebensmittel::ausgeben(std::ostream& o) const {
		Artikel::ausgeben(o);
		o << "\tHaltbar bis: " << bestBeforeDate;
	}
	void Lebensmittel::eingeben(std::istream& in) {
		Artikel::eingeben(in);
		in >> bestBeforeDate;
	}

	void Lebensmittel::setBestBeforeDate(std::string bbd) { bestBeforeDate = bbd; }
	std::string Lebensmittel::getBestBeforeDate() const   { return bestBeforeDate; }

}
