#ifndef ELEKTROGERAETE_H
#define ELEKTROGERAETE_H
#include "Artikel.h"
namespace artikel {
	class Elektrogeraete : public Artikel
	{
	public:
		static const char* meldungLeistung;
		/**
		* @brief std konstruktor
		*/
		Elektrogeraete();
		/**
		* @brief konstruktor
		* @param artikelNr Artikelnummer
		* @param bezeichnung Bezeichnung
		* @param artikelPreis Preis
		* @param bestand Bestand
		* @param leistung Kwh
		*/
		Elektrogeraete(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double leistung)
			throw (ArtikelException);
	//	~Elektrogeraete();
		/**
		* @brief eingeben Eingabefunktion
		* @param istream& istream Referenz
		*/
		void eingeben(std::istream&);
		/**
		* @brief ausgeben Ausgabefunkion
		* @param ostream& ostream Referenz
		*/
		void ausgeben(std::ostream&) const;
		/**
		* @brief getLeistung get Leistung
		*/
		double getLeistung() const;
		/**
		* @brief setLeistung set Leistung
		* @param leist neue Leistung
		*/
		void setLeistung(long leist);
	private:
		double leistung;
	};
}
#endif
