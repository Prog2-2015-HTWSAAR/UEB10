/*
 * Date.h
 *
 *  Created on: 04.07.2015
 *      Author: Simon
 */

#ifndef DATUM_H_
#define DATUM_H_
#include <string>
#include <sstream>
namespace artikel {
class Datum {
public:
	Datum(int tag, int monat, int jahr);
	virtual ~Datum();
	int getTag()const {return tag;}
	void setTag(int tag){this->tag = tag;}
	int getMonat()const {return monat;}
	void setMonat(int monat){this->monat = monat;}
	int getJahr()const {return jahr;}
	void setJahr(int jahr){this->jahr = jahr;}
	bool operator>(Datum& datum);
	friend std::istream& operator>> (std::istream& i, Datum& datum);
	friend std::ostream& operator<< (std::ostream& o, Datum& datum);
	std::string toString() const;
private:
	int tag;
	int monat;
	int jahr;
};

} /* namespace artikel */

#endif /* DATUM_H_ */
