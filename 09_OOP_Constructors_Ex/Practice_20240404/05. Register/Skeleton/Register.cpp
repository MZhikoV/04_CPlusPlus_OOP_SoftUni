#include "Register.h"
#include "Company.h"

	Register::Register(size_t numCompanies):numAdded(0), companiesArray(new Company[numCompanies]) {};

	void Register::add(const Company& c) {
		companiesArray[numAdded++]=c;
	};

	Company Register::get(int companyId) const {
		for (size_t idx=0; idx<numAdded;idx++) {
			if (companiesArray[idx].getId()==companyId) {
				return companiesArray[idx];
			}
		};
		return Company();
	};

	Register::	~Register() {
    delete[] companiesArray;
}




