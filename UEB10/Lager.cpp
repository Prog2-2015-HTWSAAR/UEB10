/*
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb06 *.o
 * @file Lager.cpp
 *
 * @date 23.05.2015
 * @author Andreas Schreiber & Simon Bastian
 *
 * Lager-Klasees Implementation
 */

#include "Lager.h"

#include <sstream>
#include <cmath>
const char* Lager::defaultName = "Musterlager";
const char* Lager::meldungGroesse = "Lagergroesse muss positiv sein!";
const char* Lager::meldungNameLeer = "Lagername darf nicht leer sein!";
const char* Lager::meldungArtNrVorhanden = "Artikelnummer bereits vorhanden!";
const char* Lager::meldungLagerVoll = "Lager ist voll!";
/**
* @brief Konstruktor
* @param maxAnzArtikel (optional) muss positiv sein!
* @param name (optional) Name des Lagers darf nicht leer sein!
*/
Lager::Lager(int maxAnzArtikel, string name){
	if(maxAnzArtikel < 1){
		throw LagerException(meldungGroesse);
	}
	if(name.empty()){
		throw LagerException(meldungNameLeer);
	}
	anzArtikel = defaultArtikelAnzahl;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = name;
	this->artikelTab = new Artikel*[maxAnzArtikel];
}
/**
 * Expliziter Kopierkonstruktor
 * @param lager Referenz auf zu kopierendes Objekt
 */
Lager::Lager(const Lager& lager){
	// Attribute uebertragen
	this->name = lager.name;
	this->maxAnzArtikel = lager.maxAnzArtikel;
	artikelTab = new Artikel*[maxAnzArtikel];
	anzArtikel = lager.anzArtikel;
	//vorhandene Artikel kopieren
	for(int i = 0; i > anzArtikel; i++){
		Artikel* tmp = lager.artikelTab[i];
		artikelTab[i] = new Artikel(*tmp);
	}
}

/**
* @brief Destructor loescht alle Artikel
*/
Lager::~Lager() {
	loescheAlleArtikel();
	delete[] artikelTab;
}
/**
 * Expliziter Zuweisungsoperator
 *
 * @param lager Referenz auf das zugewiesene Objekt
 * @return Referenz auf das aktuelle Objekt
 */
Lager& Lager::operator=(const Lager& lager){
	// Zuweisung auf mich selbst?
	if (this == &lager)
		return *this;

	// bisherige Konto-Objekte destruieren
	loescheAlleArtikel();
	delete[] artikelTab;
	// Attribute uebertragen und das Array anlegen
	this->name = lager.name;
	this->maxAnzArtikel = lager.maxAnzArtikel;
	artikelTab = new Artikel*[maxAnzArtikel];
	anzArtikel = lager.anzArtikel;

	// vorhandene Konten kopieren
	for (int i = 0; i < anzArtikel; i++) {
		Artikel* tmp = lager.artikelTab[i];
		artikelTab[i] = new Artikel(*tmp);
	}
	return *this;
}

/**
* @brief Eintragen eines neuen Artikels ohne Bestandsangabe
* @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
* @param artikelNr
* @param bezeichnung
* @param artikelPreis
*/
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis){
	if(anzArtikel == maxAnzArtikel){
		throw LagerException(meldungLagerVoll);
	}
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}else{
		throw LagerException(meldungArtNrVorhanden);
	}
}
/**
* @brief Eintragen eines neuen Artikels mit Bestandsangabe
* @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
* @param artikelNr
* @param bezeichnung
* @param artikelPreis
* @param bestand
*/
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	if(anzArtikel == maxAnzArtikel){
		throw LagerException(meldungLagerVoll);
	}
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis, bestand);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}else{
		throw LagerException(meldungArtNrVorhanden);
	}
}
/**
* @brief deleteArtikel Entfernen eines Artikels aus dem Lager
* @param artikelNr
*/
void Lager::deleteArtikel(int artikelNr){
	int i = findeArtikel(artikelNr);
	if(i >= 0){
		delete artikelTab[i];
		// letztes Konto an die Stelle i setzen
		if(i != anzArtikel-1){
			artikelTab[i] = artikelTab[anzArtikel-1];
		}
		artikelTab[anzArtikel-1] = 0;
		anzArtikel--;
	}
}
/**
* @brief bucheZugang erhoeht den bestand
* @param artikelNr
* @param menge
*/
void Lager::bucheAbgang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i >= 0 ){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheAbgang(menge);
	}
}
/**
* @brief bucheAbgang verringert den bestand
* @param artikelNr
* @param menge
*/
void Lager::bucheZugang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i >= 0 ){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheZugang(menge);
	}
}
/**
* @brief preiseAendern aendert alle preise prozentual
* @param preisAenderung
*/
void Lager::preiseAendern(double preisAenderung){
	for (int i = 0; i < anzArtikel; i++){
		artikelTab[i]->aenderePreis(preisAenderung);
	}

}
/**
* @brief findeArtikel Findet einen Artikel
* @param artikelNr
* @returns index, falls Artikel gefunden, sonst -1
*/
int Lager::findeArtikel(int artikelNr){
	for(int i = 0; i < anzArtikel; i++){
	if (artikelNr == artikelTab[i]->getArtikelNr()){
			return i;
		}
	}
	return -1;
}
/**
* @brief loescheAlleArtikel loesche alle artikel
*/
void Lager::loescheAlleArtikel(){
	for(int i = 0; i < anzArtikel; i++){
		delete artikelTab[i];
	}
	anzArtikel = 0;
}
/**
 * @brief toString gibt den Inhalt des Lagers als String zurueck
 * @returns Stringrepresentation des Lager-Objekts
 */
string Lager::toString() const {
	ostringstream o;
	o << "Lager: " << name << '\n';
	for (int i = 0; i < anzArtikel; i++) {
		o << artikelTab[i]->toString() << '\n';
	}
	o << endl;
	return o.str();
}
/**
 * @brief <<Operator zur ausgabe in einen stream
 * @param o Streamreferenz
 * @param lager Lagerreferenz
 * @returns referenz auf stream mit angehaengtem LagerString
 */
ostream& operator<<(ostream& o, const Lager& lager) {
	o << "Lager: " << lager.name << " ";
	o << lager.anzArtikel << "/" << lager.maxAnzArtikel <<'\n';
	for (int i = 0; i < lager.anzArtikel; i++) {
		o << *lager.artikelTab[i] << endl;
	}
	return o;
}
