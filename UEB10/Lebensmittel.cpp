#include "Lebensmittel.h"

namespace artikel {
	const char* Lebensmittel::meldungMHD = "Das Mindesthaltbarkeitsdatum ist bereits abgelaufen!";

	Lebensmittel::Lebensmittel(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, Datum& bestBeforeDate) throw (ArtikelException)
		: Artikel(artikelNr, bezeichnung, artikelPreis, bestand), bestBeforeDate(bestBeforeDate) {}

	void Lebensmittel::ausgeben(std::ostream& o) const {
		Artikel::ausgeben(o);
		o << "\tHaltbar bis: " << bestBeforeDate;
	}
	void Lebensmittel::eingeben(std::istream& in) {
		Artikel::eingeben(in);
		in >> bestBeforeDate;
	}

	void Lebensmittel::setBestBeforeDate(Datum bbd) { bestBeforeDate = bbd; }
	Datum Lebensmittel::getBestBeforeDate() const   { return bestBeforeDate; }

}
