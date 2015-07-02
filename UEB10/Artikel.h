/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb06 *.o
 * @file Artikel.h
 * @author Andreas Schreiner & Simon Bastian
 * @date 16.05.2015
 *
 * Artikel Klasse und zugehoerige Ausnahmen
 */
#ifndef ARTIKEL_H_
#define ARTIKEL_H_
#include <string>
#include <iostream>
#include <stdexcept>


using namespace std;


/**
 * Standardausnahme fuer logische Fehler in der Artikelklasse
 */
class ArtikelException : public logic_error {
public:
    ArtikelException(const string& msg = "") : logic_error(msg) {}
};

/**
 * @brief Artikel Klasse
 */
class Artikel {
public:
	static const int MINARTKIKELNR = 1000;
	static const int MAXARTIKELNR = 9999;
	static const char* ARTIKELNUMMER;
	static const char* BEZEICHNUNG;
	static const char* ARTIKELPREIS;
	static const char* BESTAND;
	static const char* meldungArtikelNr;
	static const char* meldungArtikelBez;
	static const char* meldungBestand;
	static const char* meldungPreis;
	static const char* meldungBuchungsmenge;
	static const char* meldungZuHoheAbbuchung;
	static const char* meldungTooHighChange;
	static const char* meldungNullNaN;

	/**
	 * @brief Konstruktor
	 * @details Konstruktor zur Erzeugung eines Artikel Obj mit Bestandsangabe
	 * @param artikelNr muss vierstellig sein!
	 * @param bezeichnung darf kein leerer String sein!
	 * @param artikelPreis darf nicht negativ sein!
	 * @param bestand (optional) darf nicht negativ sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand = 0)
			throw (ArtikelException);
	/**
	 * @brief Dekonstruktor
	 * @details Dekonstruktor
	 */
	virtual ~Artikel(){}
	/**
 	 * @brief bucheZugang
	 * @details Funktion zum erhoehen des Bestands
	 * @param menge muss positiv sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void bucheZugang(int menge) throw (ArtikelException);
	/**
	 * @brief bucheAbgang
	 * @details Funktion zum verringern des Bestands
	 * @param menge muss positiv sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void bucheAbgang(int menge) throw (ArtikelException);
	/**
	 * @brief setBezeichnung
	 * @details Funktion zum setzen der Bezeichnung
	 * @param neuBezeichnung darf nicht leer sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void setBezeichnung(string neuBezeichnung) throw (ArtikelException);
	/**
	 * @brief setBestand bei Inventur
	 * @details Funktion zum setzen des Bestands
	 * @param neuBestand darf nicht negativ sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void setBestand(int neuBestand) throw (ArtikelException);
	/**
	 * @brief Set neuer Preis
	 * @param neuPreis darf nicht negativ sein!
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void setPreis(double neuPreis) throw (ArtikelException);
	/**
	 * @brief Preisaenderung
	 * @param preisaenderung in Prozent (0% < preisaenderung < 100%)
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void aenderePreis(double preisaenderung) throw (ArtikelException);
	/**
	 * @brief get Artikelnummer
	 * @return artikelNr
	 */
	int getArtikelNr() const {
		return artikelNr;
	}
	/**
	 * @brief get Bezeichnung
	 * @return bezeichnung
	 */
	string getBezeichnung() const {
		return bezeichnung;
	}
	/**
	 * @brief get Bestand
	 * @return bestand
	 */
	int getBestand() const {
		return bestand;
	}
	/**
	 * @brief get ArtikelPreis
	 * @return artikelPreis
	 */
	double getArtikelPreis() const{
		return artikelPreis;
	}
	/**
	 * @brief toString gibt den Inhalt des Artikels als String zurueck
	 * @returns Stringrepresentation des Artikel-Objekts
	 */
	virtual string toString() const;
	/**
	 * @brief <<Operator zur ausgabe in einen stream
	 * @param o Streamreferenz
	 * @param artikel Artikelreferenz
	 * @returns stream mit angehaengtem ArtikelString
	 */
	friend ostream& operator<<(ostream&, const Artikel&);
private:
	int artikelNr; ///< Artikel Nummer
	string bezeichnung; ///< Artikel Bezeichnung
	int bestand; ///< Artikel Bestand
	double artikelPreis; ///< Artikel Preis
};


#endif 

