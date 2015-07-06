#ifndef LEBENSMITTEL_H
#define LEBENSMITTEL_H
#include "Artikel.h"
#include "Datum.h"
namespace artikel {
	class Lebensmittel : public Artikel
	{
	public:
		static const char* meldungMHD;
		/**
		* @brief std Konstruktor
		*/
		Lebensmittel();
		/**
		* @brief konstruktor
		* @param artikelNr Artikelnummer
		* @param bezeichnung Bezeichnung
		* @param artikelPreis Preis
		* @param bestand Bestand
		* @param bestBeforeDate MHD
		*/
		Lebensmittel(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, Datum& bestBeforeDate, Datum& aktuellesDatum)
			throw (ArtikelException);
	//	virtual ~Lebensmittel();
		/**
		* @brief eingeben Eingabefunktion
		* @param istream& istream Referenz
		*/
		void eingeben(std::istream&);
		/**
		* @brief ausgeben Ausgabefunktion
		* @param ostream& ostream Referenz
		*/
		void ausgeben(std::ostream&) const;
		/**
		* @brief setBestBeforeDate set fkt bbd
		* @param bbd Datum obj
		*/
		void setBestBeforeDate(Datum bbd);
		/**
		* @brief getBestBeforeDate get fkt bbd
		*/
		Datum getBestBeforeDate()    const;
		Datum updateDatum();
	private:
		/**
		* @brief bestBeforeDate Datumsobj 
		*/
		Datum& bestBeforeDate;
	};
}
#endif
