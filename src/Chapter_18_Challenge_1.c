/*
 ============================================================================
 Name        : Chapter_18_Challenge_1.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description : Challenge
               Tasks:
             • Create structure employee with members name, salary and id. Member name is character array with 30 elements,
               salary and id is integer.
             • Create employee array of 5 elements.
             • Write function print_employee_array() which first parameter is a pointer to employee array,
               and second parameter is count of employees.
             • Write function update_salary() which first parameter is a pointer to employee array, second parameter is count of employees,
               third is id of employee that needs to be updated and fourth is amount of new salary.
               Example usage: update_salary(&employees, count, id, 150);
             • Write function find_employee() which first parameter is a pointer to employee array, second parameter is count of employees,
               third is id of employee. Function returns pointer to found employee, or NULL if there is no such id.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 5

typedef struct
{
	char name[30];
	int salary;
	int ID;

}Employee;

Employee arrey[ELEMENTS];


void print_employee_array(Employee* arrey, int count)
{
	for(int i = 0; i < ELEMENTS; i++)
	{
		printf("%d.Employee is %s with ID number %d and have a salary %d EUR.\n", i+1, arrey[i].name, arrey[i].ID, arrey[i].salary);
	}
}

void update_salary(Employee* arrey, int count, int ID, int amount)
{
	for(int i = 0; i < ELEMENTS; i++)
	{
		if(arrey[i].ID == ID)
		{
			arrey[i].salary += amount;
			printf("\n%d.Employee's %s salary has been updated for %d EUR.\n", i+1, arrey[i].name, amount);
			printf("%d.Employee's %s has a salary now %d EUR!\n", i+1, arrey[i].name, arrey[i].salary);
		}
	}
}

Employee* find_employee(Employee* arrey, int count, int ID)
{
	for(int i = 0; i < ELEMENTS; i++)
	{
		if(arrey[i].ID == ID)
		{
			return &arrey[i];
		}
	}
	return NULL;
}

int main(void)
{
	int count = sizeof(arrey)/sizeof(Employee);

	Employee arrey[] =
	{
			{"Jon Jons", 1200, 0000},
			{"Mike Rogan", 1400, 0001},
			{"Steve Mugan", 1450, 0025},
			{"Boby Smoke", 1700, 0032},
			{"James Bond", 2500, 0045}

	};

	print_employee_array(arrey, count);
	update_salary(arrey, count, 0032, 550);

	Employee* foundEmployee = find_employee(arrey, count, 0045);
	if(foundEmployee != NULL)
	{
		printf("\nEmployee found with ID %d: %s\n", foundEmployee->ID, foundEmployee->name);
	}
	else
        {
		printf("\nEmployee with specified ID not found.\n");
	}

}
