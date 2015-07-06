/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb10 *.o
* @file Artikeldialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* BasisDialog Implementation
*
*/
#ifndef BASISDIALOG_H_
#define BASISDIALOG_H_
#include <sstream>
#include <cmath>

#include "Artikel.h"
#include "Artikeldialog.h"
#include "Lager.h"
#include "LagerDialog.h"
namespace artikel {
	enum BasisOption{ EXITB, ARTIKELDIALOG, LAGERDIALOG };
	class BasisDialog
	{
	public:
		static const char* SEPERATOR;
		static const char* DIALOGOPTIONONE;
		static const char* DIALOGOPTIONTWO;
		static const char* STANDARDEXITOPTION;
		static const char* STANDARDCHOICEPHRASE;
		static const char* INPUTERRORPHRASE;
		static const char* ERRORPHRASE;

		/**
		 * @brief Konstruktor
		 */
		BasisDialog();
		/**
		 * @brief Dekonstruktor
		 */
		~BasisDialog();
		int readIntegerInput();
		/**
		* @brief readDoubleInput Einlese fkt fuer double
		*/
		double readDoubleInput();
		/**
		* @brief clearInput Eingabeleerung
		* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
		*/
		void clearInput();
		/**
		* @brief readStringInput Einlese fkt fuer string
		*/
		std::string readStringInput();
		/**
		 * @brief Initiiert den ArtikelDialog
		 */
		void enterArtikelDialog();
		/**
		 * @brief Initiiert den LagerDialog
		 */
		void enterLagerDialog();
		/**
		 * @brief Initiiert den StartDialog
		 * @details Auswahl zwischen Artikel- und Lagerdialog
		 */
		void startDialog();

	};
}
#endif 
