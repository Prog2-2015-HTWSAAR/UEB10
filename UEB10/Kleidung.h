#ifndef KLEIDUNG_H
#define KLEIDUNG_H
#include "Artikel.h"
namespace artikel {
	class Kleidung : public Artikel
	{
	public:
		static const char* meldungSize;

		/**
		* @brief std konstruktor
		*/
		Kleidung();
		/**
		* @brief konstruktor
		* @param artikelNr Artikelnummer
		* @param bezeichnung Bezeichnung
		* @param artikelPreis Preis
		* @param bestand Bestand
		* @param size Kleidungsgroesse
		* @param colour Kleidungsfarbe
		*/
		Kleidung(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double size, std::string colour)
			throw (ArtikelException);
	//	~Kleidung();
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
		* @brief setSize set Groesse
		* @param newSize neue groessse
		*/
		void setSize(double newSize);
		/**
		* @brief getSize get Groesse
		*/
		double getSize() const;
		/**
		* @brief setColour set Farbe
		* @param newColour neue groessse
		*/
		void setColour(std::string newColour);
		/**
		* @brief getColour get Farbe
		*/
		std::string getColour() const;
	private:
		double size;
		std::string colour;
	};
}
#endif
