//Register::
	// size_t numAdded;
	// Company* companiesArray;

	#include "Register.h"
	#include <algorithm>


	Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company [numCompanies]) {};

	void Register::add(const Company& c) {
		companiesArray[numAdded]=c;
		numAdded++;
	};



	Company Register::get(int companyId) const {
		for (size_t idx=0; idx<numAdded;idx++) {
			if (companiesArray[idx].getId()==companyId) {
				return companiesArray[idx];
			};
		};
		return Company(-1, "Invalid");
	};

	Register::~Register() {
			delete[] companiesArray;
	}

	Register& Register::operator=(const Register& other) {
		Company * newArr=new Company[other.numAdded];

		std::copy(other.companiesArray,other.companiesArray+other.numAdded,newArr);

		if (this->companiesArray) {
			delete [] this->companiesArray;
		};

		this->numAdded=other.numAdded;
		this->companiesArray=newArr;

		return *this;
	};


	Register::Register(const Register& other) :numAdded(0), companiesArray(nullptr) {
		*this=other;
	};

