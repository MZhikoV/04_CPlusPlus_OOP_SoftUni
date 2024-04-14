#include "Register.h"

// class Register {
// 	size_t numAdded;
// 	Company* companiesArray;
// public:
	//Register::Register() : numAdded(0), companiesArray(nullptr) {}

	Register::Register(size_t numCompanies): numAdded(0), companiesArray(new Company [numCompanies]) {};

	void Register::add(const Company& c) {
		companiesArray[numAdded++]=c;
	};

	Company Register::get(int companyId) const {
		for (size_t idx=0;idx<numAdded;idx++) {
			if (companiesArray[idx].getId()==companyId) {
				return companiesArray[idx];
			};
		};
		return Company();
	};

	Register::~Register() {
		delete[] companiesArray;
	};

	Register& Register::operator=(const Register& other) {
		this->numAdded=other.numAdded;
		this->companiesArray=new Company [numAdded-1];
		this->companiesArray=other.companiesArray;
		return *this;
	};


	Register::Register(const Register& other) {
		*this=other;
	};

