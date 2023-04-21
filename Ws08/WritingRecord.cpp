// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 20-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        temp->rangeValidator();

                        if (activeEmp.luhnAlgorithm(emp[i].id)) {
                           
                            activeEmp.operator+=(temp);
                            delete temp;
                        }
                        else {
                            throw std::string("error");
                        }
                    }
                    catch (const std::string msg) {
                        delete temp;
                        throw;
                    }
                }
            }
        }
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    unique_ptr<EmployeeWage> smartTemp(new EmployeeWage(emp[i].name, sal[j].salary));
                    try {
                        smartTemp->rangeValidator();
                        if (activeEmp.luhnAlgorithm(emp[i].id)) {
                            activeEmp.operator+=(std::move(smartTemp));
                        }
                        else {
                            throw std::string("error");
                        }
                    }
                    catch (const std::string msg) {
                        throw;

                    }
                }
            }
        }
		return activeEmp;
	}
}