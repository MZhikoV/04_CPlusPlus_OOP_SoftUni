#ifndef companyy_h
#define companyy_h

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class HasInfo {
    public:
        virtual std::string getInfo() const=0;

        virtual ~HasInfo()=default;    
};

class HasId {

    public:
        virtual int getId() const=0;

         virtual ~HasId()=default; 
};

class Company:public HasInfo, public HasId {

    int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;

    public:
        Company();
        Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

        virtual int getId() const override;

        std::string getName() const;

        std::vector<std::pair<char, char> > getEmployees() const;

        virtual std::string getInfo() const override;

        friend std::ostream& operator<<(std::ostream& stream, const Company& c);

        friend std::istream& operator>>(std::istream& stream, Company& c);
};


#endif
