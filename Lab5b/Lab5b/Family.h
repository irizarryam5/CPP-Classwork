#ifndef FAMILY_H
#define FAMILY_H

using namespace std;

struct person
{
	string firstName;
	int age;	
};

class Family
{
private:
	string familyName;
	person parents[2];
	person children[10];
public:
	void setFamilyName(string);
	void setParents(string[2], int[2]);
	void setChildren(string n[10], int a[10]);
	string getFamilyName() const;
	string getParentsNames(int) const;
	int getParentsAges(int) const;
	string getChildrensNames(int) const;
	int getChildrensAges(int) const;
};
#endif