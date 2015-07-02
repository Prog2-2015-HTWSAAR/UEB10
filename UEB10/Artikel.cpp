/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb06 *.o
* @file Artikel.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 16.05.2015
*
* Artikel-Klasse
*
*/
#include "Artikel.h"

#include <sstream>
#include <cmath>
const char* Artikel::ARTIKELNUMMER = "ArtikelNr: ";
const char* Artikel::BEZEICHNUNG = "Bez.: ";
const char* Artikel::ARTIKELPREIS = "Preis: ";
const char* Artikel::BESTAND = "Bestand: ";
const char* Artikel::meldungArtikelNr = "Die Artikelnummer muss eine 4-stellige positive Zahl sein!";
const char* Artikel::meldungArtikelBez = "Die Bezeichnung eines Artikels darf nicht leer sein!";
const char* Artikel::meldungBestand = "Der Bestand darf nie negativ sein!";
const char* Artikel::meldungPreis = "Der Preis muss immer positiv sein!";
const char* Artikel::meldungBuchungsmenge = "Es duerfen nur positive Mengen gebucht werden!";
const char* Artikel::meldungZuHoheAbbuchung = "Es koennen nicht mehr Artikel abgebucht werden als vorhanden!";
const char* Artikel::meldungTooHighChange = "This change is too damn High!";
const char* Artikel::meldungNullNaN = "0 or NaN Forbidden";
/**
* @brief Konstruktor
* @details Konstruktor zur Erzeugung eines Artikel Obj; Bestandsangabe optional
* @param artikelNr muss vierstellig sein!
* @param bezeichnung darf kein leerer String sein!
* @param artikelPreis darf nicht negativ sein!
* @param bestand (optional) darf nicht negativ sein!
*/
Artikel::Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand) throw(ArtikelException){
	if (artikelNr < MINARTKIKELNR || artikelNr > MAXARTIKELNR) {
		throw ArtikelException(meldungArtikelNr);
	}
	if (bezeichnung.empty()){
		throw ArtikelException(meldungArtikelBez);
	}
	if (bestand < 0){
		throw ArtikelException(meldungBestand);
	}
	if(artikelPreis <= 0){
		throw ArtikelException(meldungPreis);
	}
	this->artikelNr = artikelNr;
	this->bezeichnung = bezeichnung;
	this->bestand = bestand;
	this->artikelPreis = artikelPreis;
}

/**
* @brief bucheZugang
* @details Funktion zum erhoehen des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheZugang(int menge) throw(ArtikelException){
	if(menge <= 0){
		throw ArtikelException(meldungBuchungsmenge);
	}

	bestand += menge;
}
/**
* @brief bucheAbgang
* @details Funktion zum verringern des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheAbgang(int menge)  throw(ArtikelException){
	if(menge <= 0){
		throw ArtikelException(meldungBuchungsmenge);
	}
	if (bestand - menge < 0){
		throw ArtikelException(meldungZuHoheAbbuchung);
	}
	bestand -= menge;
}
/**
* @brief setBestand bei Inventur
* @details Funktion zum setzen des Bestands
* @param neuBestand darf nicht negativ sein!
*/
void Artikel::setBestand(int neuBestand)  throw(ArtikelException){
	if (neuBestand < 0){
		throw ArtikelException(meldungBestand);
	}
	bestand = neuBestand;

}
/**
* @brief setBezeichnung
* @details Funktion zum setzen der Bezeichnung
* @param neuBezeichnung darf nicht leer sein!
*/
void Artikel::setBezeichnung(string neuBezeichnung)  throw(ArtikelException){
	if (neuBezeichnung.empty()){
		throw ArtikelException(meldungArtikelBez);
	}
	bezeichnung = neuBezeichnung;
}
/**
* @brief Set neuer Preis
* @param neuPreis darf nicht negativ sein!
*/
void Artikel::setPreis(double neuPreis) throw(ArtikelException){
	if(neuPreis < 0){
		throw ArtikelException(meldungPreis);
	}
	artikelPreis=round(neuPreis*100)/100.0; // auf zwei stellen runden
}
/**
 * @brief Preisaenderung
 * @param preisaenderung in Prozent (max. 99%)
 */
void Artikel::aenderePreis(double preisaenderung) throw(ArtikelException){
	if (abs(preisaenderung) > 100 ){
		throw ArtikelException(meldungTooHighChange);
	}	if (abs(preisaenderung) == 0){
		throw ArtikelException(meldungNullNaN);
	}
	artikelPreis*=(1+(preisaenderung/100));
	artikelPreis=round(artikelPreis*100)/100;
}
/**
 * @brief toString gibt den Inhalt des Artikels als String zurueck
 * @returns Stringrepresentation des Artikel-Objekts
 */
string Artikel::toString() const {
	ostringstream o;
	o << ARTIKELNUMMER << artikelNr << "\t"
	  << BEZEICHNUNG << bezeichnung << "\t "
	  << ARTIKELPREIS << artikelPreis << "\t"
	  << BESTAND << bestand;
	return o.str();
}
/**
 * @brief <<Operator zur ausgabe in einen stream
 * @param o Streamreferenz
 * @param artikel Artikelreferenz
 * @returns Referenz auf Stream mit angehaengtem ArtikelString
 */
ostream& operator<<(ostream& o, const Artikel& artikel) {
	return o << artikel.toString();
}
