//Register::
	// size_t numAdded;
	// Company* companiesArray;

	#include "Register.h"
	#include "RemoveInvalid.h"


	Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company* companiesArray [numCompanies]) {};

	void Register::add(const Company& c) {
		if (!removeInvalid) {
		companiesArray[numAdded]<<c.getId()<<c.getName();
		numAdded++;
		};
	};



	Company Register::get(int companyId) const {
		//Company * newCompany;
		for (size_t idx=0; idx<numAdded;idx++) {
			if (companiesArray[idx].getId()==companyId) {
				return companiesArray[idx];
			};
		};
	}

	Register::~Register() {
		for (size_t idx=0; idx<numAdded;idx++) {
			delete companiesArray[idx];
		};
	}

	Register& Register::operator=(const Register& other) {
		this->numAdded=other.numAdded;
		this->companiesArray=other.companiesArray;

		return *this;
	};


	Register::Register(const Register& other) :numAdded(other.numAdded), companiesArray(other.companiesArray) {};

