/*
Timmins, Chase
CS A250
September 15, 2016

Project 1a: MemberType.cpp
*/
#include "MemberType.h"
using namespace std;

MemberType::MemberType()
{
	membershipNo = 0;
}

MemberType::MemberType(const string &fName, const string &lName, int newMembershipNo)
{
	firstName = fName;
	lastName = lName;
	membershipNo = newMembershipNo;
}

void MemberType::setMembershipInfo(const string &fName, const string &lName, int newMemberNum)
{
	firstName = fName;
	lastName = lName;
	membershipNo = newMemberNum;
}

string MemberType::getFirstName() const
{
	return firstName;
}

string MemberType::getLastName() const
{
	return lastName;
}

int MemberType::getMembershipNo() const
{
	return membershipNo;
}

void MemberType::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

void MemberType::printMemberInfo() const
{
	cout << membershipNo << " - " << firstName << " " << lastName << endl;
}

MemberType::~MemberType() {}
