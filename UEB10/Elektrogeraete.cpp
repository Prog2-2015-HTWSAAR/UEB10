#include "Elektrogeraete.h"
namespace artikel {
	const char* Elektrogeraete::meldungLeistung = "Die Leistungseingabe war Fehlerhaft";

	Elektrogeraete::Elektrogeraete(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double leistung) throw (ArtikelException)
		: Artikel(artikelNr, bezeichnung, artikelPreis, bestand), leistung(leistung) {
		if (leistung < 0){
			throw ArtikelException(meldungLeistung);
		}
	}


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
