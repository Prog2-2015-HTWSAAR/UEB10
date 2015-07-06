/*
 * Date.h
 *
 *  Created on: 04.07.2015
 *      Author: Simon
 */

#ifndef DATUM_H_
#define DATUM_H_
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
namespace artikel {

class DatumException : public std::logic_error {
public:
	DatumException(const std::string& msg = "") : logic_error(msg) {}
};

class Datum {
public:
	static const char* meldungTag;
	static const char* meldungMonat;
	static const char* meldungJahr;
	/**
	 * @brief Konstruktor
	 * @param tag
	 * @param monat
	 * @param jahr
	 */
	Datum(int tag, int monat, int jahr)throw (DatumException);
	/**
	 * @brief Dekonstruktor
	 */
	virtual ~Datum();
	/**
	 * @brief Tag-getter
	 * @returns tag
	 */
	int getTag()const {return tag;}
	/**
	 * @brief Tag-Setter
	 * @param tag
	 */
	void setTag(int tag);
	/**
	 * @brief Monat-Getter
	 * @returns monat
	 */
	int getMonat()const {return monat;}
	/**
	 * @brief Monat-Setter
	 * @param monat
	 */
	void setMonat(int monat);
	/**
	 * @brief Jahr-Getter
	 * @returns jahr
	 */
	int getJahr()const {return jahr;}
	/**
	 * @brief Jahr-Setter
	 * @param jahr
	 */
	void setJahr(int jahr);
	/**
	 * @brief Vergleichsfunktion fuer Daten
	 * @param datumA
	 * @param datumB
	 * @returns 0, wenn Daten gleich
	 * 			>0, wenn datumA nach datumB
	 * 			<0, wenn datumA vor datumB
	 */
	friend int dateCMP(Datum& datumA, Datum& datumB);
	/**
	 * @brief Einleseoperator fur Datum
	 * @param i istream-Referenz
	 * @param datum Datums-Referenz
	 * @returns i Ausgelesene istream-Referenz
	 */
	friend std::istream& operator>> (std::istream& i, Datum& datum)
		throw (DatumException);
	/**
	 * @brief Ausgabeeoperator fur Datum
	 * @param o ostream-Referenz
	 * @param datum Datums-Referenz
	 * @returns o ostream-Referenz mit angehaengtem Datum-String
	 */
	friend std::ostream& operator<< (std::ostream& o, Datum& datum);
	/**
	 * @brief ermittelt das aktuelle Datum
	 * @return datum pointer auf ein neues Datum-Objekt
	 */
	static Datum* calcCurrentDate();
	/**
	 * @brief Liefert eine Stringrepraesentation des Datums
	 * @returns Datum-String
	 */
	std::string toString() const;
private:
	/**
	 * @brief Prueft ob das Angegebene Datum existiert
	 * @param tag
	 * @param monat
	 * @param jahr
	 * @throws DatumException
	 */
	void checkDate(int tag, int monat, int jahr) throw (DatumException);
	/**
	 * @brief Prueft ob der Tag des Datums existiert
	 * @param tag
	 * @param monat
	 * @param jahr
	 * @returns true, wenn der Tag existert
	 * 			false, sonst
	 */
	bool checkDay(int tag, int monat, int jahr);
	/**
	 * @brief Prueft ob der Monat des Datums existiert
	 * @param monat
	 * @returns true, wenn der Monat existiert
	 * 			false, sonst
	 */
	bool checkMonth(int monat);
	/**
	 * @brief Prueft ob das Jahr des Datums gueltig ist
	 * @details nur Jahre >= 1900 sind gueltig
	 * @param jahr
	 * @returns true, wenn das Jahr gueltig ist
	 * 			false, sonst
	 */
	bool checkYear(int jahr);
	/**
	 * @brief Prueft ob das Jahr ein Schaltjahr ist
	 * @param jahr
	 * @returns true, wenn das Jahr ein Schaltjahr ist
	 * 			false, sonst
	 */
	bool leapYear(int jahr);
	int tag;
	int monat;
	int jahr;
};

} /* namespace artikel */

#endif /* DATUM_H_ */
