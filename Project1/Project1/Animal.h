#ifndef ANIMAL_H
#define ANIMAL_H

//#include <string>

using namespace std;

class Animal
{
private:
	string name;
	int age;
public:
	void setName(string);
	void setAge(int);
	string getName() const;
	int getAge() const;
};

#endif
