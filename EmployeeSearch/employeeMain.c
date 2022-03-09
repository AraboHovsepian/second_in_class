// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Example found (Phone number)
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");

    if (matchPtr != NULL)
        printf("Phone number 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 714-555-2749 is NOT found in the record\n");

    // Example not found (Phone number)
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "777-555-2749");

    if (matchPtr != NULL)
        printf("Phone number 777-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 777-555-2749 is NOT found in the record\n");

    // Example found (Salary)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);

    if (matchPtr != NULL)
        printf("Salary 6.34 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Salary 6.34 is NOT found in the record\n");

    // Example not found (Salary)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.90);

    if (matchPtr != NULL)
        printf("Salary 8.78 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Salary 8.78 is NOT found in the record\n");    

    return EXIT_SUCCESS;
}