#include "Elektrogeraete.h"
namespace artikel {
	Elektrogeraete::Elektrogeraete(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double leistung)
		: Artikel(artikelNr, bezeichnung, artikelPreis, bestand), leistung(leistung) {}


	void Elektrogeraete::ausgeben(std::ostream& o) const {
		Artikel::ausgeben(o);
		o << "\tKwh: " << leistung;
	}
	void Elektrogeraete::eingeben(std::istream& in) {
		Artikel::eingeben(in);
		in >> leistung;
	}
	void Elektrogeraete::setLeistung(long leist) { leistung = leist; }
	double Elektrogeraete::getLeistung() const   { return leistung; }

}
