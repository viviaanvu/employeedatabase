#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 22
#define emailSIZE 21

struct Employee {
	char ID[idSIZE];
	char first[nameSIZE];
	char last[nameSIZE];
	char email[emailSIZE];
	double salary;
};

struct DataBase {
	struct Employee** emp;
	int total;
};

// Function          : initialize
// Description       : initializes the database by manually entering records using createRecord function
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void initialize (struct DataBase *db);

// Function          : createRecord
// Description       : creates an employee record in the database
// Inputs            : char ID           - char array of employee ID
//                     char first        - char array of employee first name
//                     char last         - char array of employee last name
//                     char email        - char array of employee email
//                     double salary     - double of employee salary
//                     struct DataBase * - pointer to the database
// Outputs           : void
void createRecord (char ID[idSIZE], char first[nameSIZE], char last[nameSIZE], char email[emailSIZE], double salary, struct DataBase *db);

// Function          : displayMenu
// Description       : displays menu options and allows user input for each menu option 
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void displayMenu (struct DataBase *db);

// Function          : sortID
// Description       : sorts each employee's ID in ascending order
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void sortID (struct DataBase *db);

// Function          : displayEmployees
// Description       : displays the employees in the database in the order they were called in
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void displayEmployees (struct DataBase *db);

// Function          : searchEmployeeID
// Description       : searches for employee in the database by ID
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void searchEmployeeID (struct DataBase *db);

// Function          : searchEmployeeLastName
// Description       : searches for every employee in the database by their last name
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void searchEmployeeLastName (struct DataBase *db);

// Function          : deleteEmployeeID 
// Description       : deletes the employee from the database by their ID
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void deleteEmployeeID (struct DataBase *db);

// Function          : deleteEmployeeLastName
// Description       : deletes the first occurence of the employee from the database by their last name
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void deleteEmployeeLastName (struct DataBase *db);

// Function          : menu
// Description       : displays the menu options 1-7 and running total of the employees
// Inputs            : int total         - updated total amount of employees in the database
// Outputs           : void
void menu (int total);

// Function          : labels
// Description       : label headers for the printing of the database
// Inputs            : N/A
// Outputs           : void
void labels ();

// Function          : quit
// Description       : frees and deallocates all mallocated memory then exits the program
// Inputs            : struct DataBase * - pointer to the database
// Outputs           : void
void quit (struct DataBase *db);
