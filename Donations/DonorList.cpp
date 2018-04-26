#include "DonorList.h"

//default constructor
DonorList::DonorList()
{
	donors = new list<DonorType>;
}

//addDonor
void DonorList::addDonor(const string &fName, const string& lName, int memberNum,
	double donatedAmnt) const
{
	donors->push_back(DonorType(fName, lName, memberNum, donatedAmnt));
}

//getNumberOfDonors
int DonorList::getNumberOfDonors() const
{
	return (static_cast<int>(donors->size()));
}

//searchID
bool DonorList::searchID(int memberNum) const
{
	list<DonorType>::iterator iter;

	return searchDonorLocation(memberNum, iter);
}

//getTotalDonations
double DonorList::getTotalDonations() const
{
	double total = 0.0;
	list<DonorType>::const_iterator cIter = donors->cbegin(),
		cend = donors->cend();
	while (cIter != cend)
	{
		total += cIter->getAmountDonated();
		cIter++;
	}
	return total;
}

//deleteDonor
void DonorList::deleteDonor(int searchID) const
{
	list<DonorType>::iterator iter;
	if (searchDonorLocation(searchID, iter))
	{
		donors->erase(iter);
	}
}

//searchDonorByMemberNo
bool DonorList::searchDonorByMemberNo(string& name, double& newDonation, int searchID) const
{
	list<DonorType>::iterator iter = donors->begin();
	if (searchDonorLocation(searchID, iter))
	{
		name = iter->getLastName() + ", " + iter->getFirstName();
		newDonation = iter->getAmountDonated();
		return true;
	}
	return false;
}

//searchDonorLocation
bool DonorList::searchDonorLocation(int searchID, list<DonorType>::iterator& iter) const
{
	list<DonorType>::iterator end = donors->end();
	for (iter = donors->begin(); iter != end; iter++)
	{
		if (iter->getMembershipNo() == searchID)
			return true;
	}
	return false;
}

//highestDonation
double DonorList::highestDonation(string& fname, string& lname, int& memberID) const
{
	list<DonorType>::const_iterator iter = donors->cbegin(),
		end = donors->cend();
	double donation = iter->getAmountDonated();
	fname = iter->getFirstName();
	lname = iter->getLastName();
	memberID = iter->getMembershipNo();
	iter++;

	while (iter != end)
	{
		if (iter->getAmountDonated() > donation)
		{
			donation = iter->getAmountDonated();
			fname = iter->getFirstName();
			lname = iter->getLastName();
			memberID = iter->getMembershipNo();
		}
		iter++;
	}

	return donation;
}

//printAllDonors
void DonorList::printAllDonors(string& allDonors) const
{
	list<DonorType>::const_iterator iter = donors->cbegin(),
		end = donors->cend();

	while (iter != end)
	{
		allDonors += to_string(iter->getMembershipNo());
		allDonors += "-" + iter->getLastName() + ", " + iter->getFirstName();
		iter++;
		if (iter != end)
			allDonors += "\n";
	}
}

//destroyList
void DonorList::destroyList()
{
	donors->clear();
}

//destructor
DonorList::~DonorList()
{
	destroyList();
	delete donors;
	donors = nullptr;
}