#include <string.h>
#include <stdlib.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char* nameToFind);
PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char* phoneToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

int main(){
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");

    if(matchPtr != NULL){
        printf("Employee Phone # 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee Phone # 909-555-2134 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "408-231-2345");

    if(matchPtr != NULL){
        printf("Employee Phone # 408-231-2345 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee Phone # 408-231-2345 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);

    if(matchPtr != NULL){
        printf("Employee salary 7.80 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee salary 7.80 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 1.22);

    if(matchPtr != NULL){
        printf("Employee salary 1.22 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee salary 1.22 is NOT found in the record\n");
    }


    return EXIT_SUCCESS;
}