#include "DonorType.h"
using namespace std;

DonorType::DonorType()
{
	donation = 0.0;
}

DonorType::DonorType(const string &fName, const string &lName, int membershipNo,
	double donationAmount) : MemberType(fName, lName, membershipNo)
{
	donation = donationAmount;
}

double DonorType::getAmountDonated() const
{
	return donation;
}

void DonorType::setAmountDonated(double amountDonated)
{
	donation = amountDonated;
}

void DonorType::setDonorInfo(const string &fName, const string &lName, int newMemberNum,
	double newDonation)
{
	setMembershipInfo(fName, lName, newMemberNum);
	donation = newDonation;
}
void DonorType::printDonor() const
{
	printMemberInfo();
}

void DonorType::printDonation() const
{
	printName();
	cout << "    Donation Amount: $" << fixed << setprecision(2) << donation << endl;
}

DonorType::~DonorType() {}