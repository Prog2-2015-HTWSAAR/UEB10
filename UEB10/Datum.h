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
	Datum(int tag, int monat, int jahr)throw (DatumException);
	virtual ~Datum();
	int getTag()const {return tag;}
	void setTag(int tag);
	int getMonat()const {return monat;}
	void setMonat(int monat);
	int getJahr()const {return jahr;}
	void setJahr(int jahr);
	friend int dateCMP(Datum& datumA, Datum& datumB);
	friend std::istream& operator>> (std::istream& i, Datum& datum)
		throw (DatumException);
	friend std::ostream& operator<< (std::ostream& o, Datum& datum);
	static Datum* calcCurrentDate();
	std::string toString() const;
private:
	void checkDate(int tag, int monat, int jahr) throw (DatumException);
	bool checkDay(int tag, int monat, int jahr);
	bool checkMonth(int monat);
	bool checkYear(int jahr);
	bool leapYear(int jahr);
	int tag;
	int monat;
	int jahr;
};

} /* namespace artikel */

#endif /* DATUM_H_ */
