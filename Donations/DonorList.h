/*
The_Spanish_Inquisition
Boone, Damon
Hsu, Golden
Kobel, Connor
Timmins, Chase
CS A250
December 9, 2016

Project 2: DonorList Class
*/

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include<iostream>
#include <string>		
#include <iomanip>
#include <list>

using namespace std;

class DonorList
{
public:
	//default constructor
	DonorList();

	//addDonor
	void addDonor(const string&, const string&, int, double) const;

	//getNumberOfDonors
	int getNumberOfDonors() const;

	//searchID
	bool searchID(int) const;

	//getTotalDonations
	double getTotalDonations() const;

	//deleteDonor
	void deleteDonor(int) const;

	//searchDonorByMemberNo
	bool searchDonorByMemberNo(string& name, double& newDonation, int searchID) const;

	//searchDonorLocation
	bool searchDonorLocation(int memberNo, list<DonorType>::iterator& iter) const;

	//highestDonation
	double highestDonation(string& fname, string& lname, int& memberID) const;

	//printAllDonors
	void printAllDonors(string& allDonors) const;

	//destroyList
	void destroyList();

	//destructor
	~DonorList();

private:

	list<DonorType> *donors;
};

#endif
