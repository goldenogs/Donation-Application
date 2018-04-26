/*
The_Spanish_Inquisition
Boone, Damon
Hsu, Golden
Kobel, Connor
Timmins, Chase
CS A250
September 22, 2016

Project 1: DonorType Class
*/
#ifndef DONOR_TYPE_H
#define DONOR_TYPE_H

#include "MemberType.h"
#include <iomanip>

class DonorType : public MemberType
{
public:
	//Constructors
	DonorType();
	DonorType(const string&, const string&, int, double);

	//Getter
	double getAmountDonated() const;

	//Setter
	void setAmountDonated(double);
	void setDonorInfo(const string&, const string&, int, double);

	//Member Functions
	void printDonor() const;
	void printDonation() const;

	//Destructor
	~DonorType();
private:
	double donation;
};

#endif