/*
Timmins, Chase		(The_Spanish_Inquisition)
CS A250
September 15, 2016

Project 1A: MemberType.h
*/
#ifndef MEMBER_TYPE_H
#define MEMBER_TYPE_H

#include <iostream>
#include  <string>
using namespace std;

class MemberType
{
public:
	MemberType();

	MemberType(const string&, const string&, int);

	void setMembershipInfo(const string&, const string&, int);

	string getFirstName() const;

	string getLastName() const;

	int getMembershipNo() const;

	void printName() const;

	void printMemberInfo() const;

	~MemberType();

private:
	string firstName;
	string lastName;
	int membershipNo;
};

#endif

