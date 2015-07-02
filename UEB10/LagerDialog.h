/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb06 *.o
* @file LagerDialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* LagerDialog-Header
*
*/
#ifndef LAGERDIALOG_H_
#define LAGERDIALOG_H_
#include "BasisDialog.h"
#include "Lager.h"

enum CreateLagerOption{EXITCL, SIZENAME, NAME, STANDARD, LAGERAUTOTST};
enum ManageLagerOption{EXITML, CREATEARTIKEL, CREATEARTIKELOHNEBESTAND, EDITARTIKEL, DELETEARTIKEL, ABORT };
enum ManageArtikelOption{EXITMA, ZUGANGL, ABGANGL, CHANGEPRICES};
/**
 * @brief Klasse zum Testen der Lager-Klasse
 */
class LagerDialog {
public:
	static const char* TESTARTIKELBEZEICHNUNGONE;
	static const char* TESTARTIKELBEZEICHNUNGTWO;
	static const char* TESTARTIKELBEZEICHNUNGTHREE;
	static const char* TESTLAGERNAME;
	static const char* AUTOTESTERZEUGEARTIKEL;
	static const char* AUTOTESTLOESCHEARTIKEL;
	static const char* AUTOTESTZUBUCHEN;
	static const char* AUTOTESTABBUCHEN;
	static const char* AUTOTESTPREISAENDERN;
	static const int TESTARTIKELNUMMERONE;
	static const int TESTARTIKELNUMMERTWO;
	static const int TESTARTIKELNUMMERTHREE;
	static const int TESTARTIKELNUMMERFOUR;
	static const int TESTARTIKELNUMMERWRONG;
	static const int TESTARTIKELBESTANDONE;
	static const int TESTARTIKELBESTANDTWO;
	static const int TESTARTIKELBESTANDTHREE;
	static const int TESTARTIKELBESTANDNEGATIVE;
	static const int TESTARTIKELBESTANDAENDERUNGONE;
	static const int TESTARTIKELBESTANDAENDERUNGTWO;
	static const int TESTLAGERSIZEFUERAUTO;
	static const double TESTARTIKELPREISONE;
	static const double TESTARTIKELPREISTWO;
	static const double TESTARTIKELPREISTHREE;
	static const double TESTARTIKELPREISNEGATIVE;
	static const double TESTARTIKELPREISAENDERUNGONE;
	static const double TESTARTIKELPREISAENDERUNGTWO;
	static const char* LAGERWIRKLICHLOESCHEN;
	static const char* ARTIKELWIRKLICHLOESCHEN;
	static const char* ARTIKELNUMMER;
	static const char* BEZEICHNUNG;
	static const char* ARTIKELPREIS;
	static const char* BESTAND;
	static const char* ZUGANG;
	static const char* ABGANG;
	static const char* PRICECHANGEPHRASE;
	static const char* EDITDIALOGOPTIONONE;
	static const char* EDITDIALOGOPTIONTWO;
	static const char* EDITDIALOGOPTIONTHREE;
	static const char* SEPERATOR;
	static const char* SEPERATORCREATELAGER;
	static const char* SEPERATORDELETELAGER;
	static const char* SEPERATORBUCHEZUGANG;
	static const char* SEPERATORBUCHEABGANG;
	static const char* SEPERATORAENDEREPREIS;
	static const char* SEPERATORDELETEARTIKEL;
	static const char* SEPERATORCREATEARTIKEL;
	static const char* DIALOGOPTIONONE;
	static const char* DIALOGOPTIONTWO;
	static const char* DIALOGOPTIONTHREE;
	static const char* DIALOGOPTIONFOUR;
	static const char* STANDARDEXITOPTION;
	static const char* STANDARDBACKOPTION;
	static const char* LAGERDIALOGOPTIONONE;
	static const char* LAGERDIALOGOPTIONTWO;
	static const char* LAGERDIALOGOPTIONTHREE;
	static const char* LAGERDIALOGOPTIONFOUR;
	static const char* LAGERDIALOGOPTIONEXIT;
	static const char* STANDARDCHOICEPHRASE;
	static const char* INPUTERRORPHRASE;
	static const char* ERRORPHRASE;
	static const char* STANDARDLAGERNAME;
	static const char* ENTERNAMEPHRASE;
	static const char* ENTERSIZEPHRASE;
	/**
	* @brief Konstructor
	*/
	LagerDialog();
	/**
	* @brief Destructor 
	*/
	virtual ~LagerDialog();
	/**
	* @brief Dialog zur Erstellung des Lagers
	*/
	void createLagerDialog();
	/**
	* @brief Eingabeleerung
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void leereEingabe();
	/**
	* @brief startLagerDialog Dialog Lagermanagementdialog
	* @param lager
	*/
	void startLagerDialog(Lager* lager);
	/**
	* @brief artikelEditDialog Dialog zum Aendern von Artikeln
	* @param lager
	*/
	void artikelEditDialog(Lager* lager);
	
	void automatischerLagerTest();
};

#endif
