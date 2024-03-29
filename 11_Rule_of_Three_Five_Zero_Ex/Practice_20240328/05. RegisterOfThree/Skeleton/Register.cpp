#include "Register.h"
#include <algorithm>
//class Register


//	size_t numAdded;
//	Company* companiesArray;


	Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company [numCompanies]) {};

	void Register::add(const Company& c) {
		companiesArray[numAdded]=c;
		numAdded++;
	}

	Company Register::get( int companyId) const {
		for (size_t cur=0; cur<numAdded;cur++) {
			if (companiesArray[cur].getId()==companyId){
				return companiesArray[cur];
			};
		};
		return Company (-1, "Invalid");
	};

	Register::~Register() {
		delete [] companiesArray;
	};

	Register& Register::operator=(const Register& other) {
		Company * newArray=new Company[other.numAdded];
		std::copy(other.companiesArray, other.companiesArray+other.numAdded, newArray);
		
		if (this->companiesArray) {
			delete[] this->companiesArray;
		};
		this->companiesArray=newArray;
		this->numAdded=other.numAdded;

		return *this;
	};

	Register::Register(const Register& other) : numAdded(0),companiesArray(nullptr) {
		*this=other;
	};



/*Lecturer(const Lecturer& other)
		: rating(other.rating), name(other.name) {
		std::cout << "Lecturer COPY ctor BODY" << std::endl;
	}

	Lecturer& operator=(const Lecturer& other) {
		this->rating = other.rating;
		this->name = other.name;

		std::cout << "Lecturer COPY-ASSIGN operator BODY" << std::endl;

		return *this;
	}*/
