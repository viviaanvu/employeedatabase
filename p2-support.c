// Project 2
// Project Description - Create a small employee menu-driven
//                       database that implements sorting,
//                       searching, and deleting records. 
//
// Author Name         - Vivian Vu
// Last Edit Date      - 10/27/20
//
// **********************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"

void initialize (struct DataBase *db)
{
	db->emp = (struct Employee*) malloc(sizeof(struct Employee)*dbSIZE);
	//allocate memory for 100 employees
	db->total = 0;
	//there are 0 employees at the beginning
	createRecord ("00306", "Wei", "Martin", "wm@aol.com", 98999.99, db);
	createRecord ("00307", "Mitch", "Martinez", "mitch@aol.com", 78999.88, db);
	createRecord ("00408", "David", "Boyle", "db@aol.com", 100000.01, db);
	createRecord ("00204", "Christine", "Bluer", "cb@aol.com", 40009.99, db);
	createRecord ("00305", "Stephen", "Black", "sb@aol.com", 8500.01, db);
	createRecord ("00409", "Chris", "Boyle", "cb@aol.com", 200000.01, db);
	createRecord ("00101", "Paula", "Brown", "pb@aol.com", 1000.37, db);
	createRecord ("00102", "Paul", "Green", "pg@aol.com", 2700.45, db);
	createRecord ("00203", "Chris", "Reddy", "cr@aol.com", 2304.67, db);
}

void createRecord (char ID[idSIZE], char first[nameSIZE], char last[nameSIZE], char email[emailSIZE], double salary, struct DataBase *db) {
	struct Employee* employee = (struct Employee*) malloc(sizeof(struct Employee));
	strncat(employee->ID, ID, 5);
	strncat(employee->first, first, 10);
	strncat(employee->last, last, 10);
	strncat(employee->email, email, 20);
	employee->salary = salary;
	db->emp[db->total] = employee;
	db->total++;
}


void displayMenu (struct DataBase *db) {	
	while (1) { 
		menu(db->total);
		int choice;
		scanf("%d", &choice);
		if (choice == 1) {
			sortID(db);
		}
		else if (choice == 2) {
			displayEmployees(db);			
		}
		else if (choice == 3) {
			searchEmployeeID(db);	
		}
		else if (choice == 4) {
			searchEmployeeLastName(db);
		}
		else if (choice == 5) {
			deleteEmployeeID(db);	
		}
		else if (choice == 6) {
			deleteEmployeeLastName(db);
		}
		else {
			quit(db);
		}
	}	
}

void sortID (struct DataBase *db) {
	struct Employee *temp;
	int i,k;
	for (i = 1; i < db->total; i++) {
		for (k = 0; k < db->total - i; k++) {
			if (strcmp(db->emp[k]->ID, db->emp[k+1]->ID) > 0) {
				temp = db->emp[k];
				db->emp[k] = db->emp[k+1];
				db->emp[k+1] = temp;
			}
		}
	}
	printf("\n");
}

void displayEmployees (struct DataBase *db) {
	int i;
	labels();
	for (i = 0; i < db->total; i++) {
		char name[20] = {'\0'};
		strncat(name, db->emp[i]->first, 11);
		strcat(name, " ");
		strncat(name, db->emp[i]->last, 11);
		printf("%-3d %5s ", i, db->emp[i]->ID);
		printf("%-20s ", name);	
		printf("%-20s  $%10.2f\n", db->emp[i]->email, db->emp[i]->salary);	
	}
	printf("\n");
}

void searchEmployeeID (struct DataBase *db) {
	char searchID[6];
	int i;
	printf("Enter the ID you are searching for\n");
	scanf("%s", searchID);
	labels();
	for (i = 0; i < db->total; i++) {
		if (strcmp(db->emp[i]->ID, searchID) == 0) {
			char name[20] = {'\0'};
			strncat(name, db->emp[i]->first, 11);
			strcat(name, " ");
			strncat(name, db->emp[i]->last, 11);
			printf("%-3d %5s ", i, db->emp[i]->ID);
			printf("%-20s ", name);	
			printf("%-20s  $%10.2f\n", db->emp[i]->email, db->emp[i]->salary);		
		}
	}
	printf("\n");
}

void searchEmployeeLastName (struct DataBase *db) {
	char lastName[10];
	int i;
	printf("Enter the last name  you are searching for\n");
	scanf("%s", lastName);
	labels();
	for (i = 0; i < db->total; i++) {
		if (strcmp(db->emp[i]->last, lastName) == 0) {
			char name[20] = {'\0'};
			strncat(name, db->emp[i]->first, 11);
			strcat(name, " ");
			strncat(name, db->emp[i]->last, 11);
			printf("%-3d %5s ", i, db->emp[i]->ID);
			printf("%-20s ", name);	
			printf("%-20s  $%10.2f\n", db->emp[i]->email, db->emp[i]->salary);		
		}
	}
	printf("\n");
}

void deleteEmployeeID (struct DataBase *db) {
	char searchID[6];
	int i,k;
	printf("Enter the ID you are searching for\n");
	scanf("%s", searchID);	
	labels();
	for (i = 0; i < db->total; i++) {
		if (strcmp(db->emp[i]->ID, searchID) == 0) {
			char name[20] = {'\0'};
			strncat(name, db->emp[i]->first, 11);
			strcat(name, " ");
			strncat(name, db->emp[i]->last, 11);
			printf("%-3d %5s ", i, db->emp[i]->ID);
			printf("%-20s ", name);	
			printf("%-20s  $%10.2f\n", db->emp[i]->email, db->emp[i]->salary);
			free(db->emp[i]);
			for (k = i; k < db->total-1; k++) {
				db->emp[i] = db->emp[k+1];
			}
			db->total--;
		}
	}
	printf("\n");
}

void deleteEmployeeLastName (struct DataBase *db) {
	char lastName[10] = {'\0'};
	int i;
	int k;
	printf("Enter the Last Name you are searching for\n");
	scanf("%s", lastName);
	labels(); 
	for (i = 0; i < db->total; i++) {
		if (strcmp(db->emp[i]->last, lastName) == 0) {
			char name[20] = {'\0'};
			strncat(name, db->emp[i]->first, 11);
			strcat(name, " ");
			strncat(name, db->emp[i]->last, 11);
			printf("%-3d %5s ", i, db->emp[i]->ID);
			printf("%-20s ", name);	
			printf("%-20s  $%10.2f\n", db->emp[i]->email, db->emp[i]->salary);
			free(db->emp[i]);
			for (k = i; k < db->total-1; k++) {
				db->emp[i] = db->emp[k+1];
			}	
			db->total--;
			break;
		}
	}
	printf("\n");
}

void quit (struct DataBase *db) {
	int i;
	for (i = 0; i < db->total; i++) {
		free(db->emp[i]);
		db->emp[i] = NULL;
	}
	free(db->emp);
	db->emp = NULL;
	free(db);
	printf("Bye!\n");
	exit(0);
}

void labels () {
	printf("No. EmpID Employee Name        Email                 Salary\n");
	printf("--- ----- -------------------- --------------------- -----------\n");	
}

void menu (int total) {
	printf("****************************************************************\n");
	printf("********  VUV2 Employee Database - Total Employees:  %d  ********\n", total);
	printf("****************************************************************\n");
	printf("\nChoose one of the menu options:");
	printf("\n1. Sort with ID");
	printf("\n2. Display all employees");
	printf("\n3. Search employee by ID");
	printf("\n4. Search employee by Last Name");
	printf("\n5. Delete employee by ID");
	printf("\n6. Delete employee by Last Name");
	printf("\n7. Exit\n");
}
