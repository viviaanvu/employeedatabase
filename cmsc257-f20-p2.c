// Project 2
// Project Description - Create a small menu-driven
//                       employee database that sorts, 
//                       searches, and deletes records. 
//
// Author Name         - Vivian Vu
// Last Edit Date      - 10/27/20
//
// ****************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"

int main ()
{
	struct DataBase* db;
	db = (struct DataBase*) malloc(sizeof(struct DataBase));
	initialize (db);
	displayMenu (db);
	return 0;
}
