#ifndef company_h
#define company_h

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

struct Company {

int id;
std::string name;
std::vector<std::pair<char, char> > employees;

public:
Company();

Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

int getId() const;

std::string getName() const;

std::vector<std::pair<char, char> > getEmployees() const;

std::string getInfo() const;

friend std::ostream& operator<<(std::ostream& stream, const Company& c);

friend std::istream& operator>>(std::istream& stream, Company& c);

 virtual bool isSuper(void) const {return true;};

 virtual ~Company()=default;

};


#endif