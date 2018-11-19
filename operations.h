#ifndef STUDENTDATABASE_STUDENTDATABASE_OPERATIONS_H_
#define STUDENTDATABASE_STUDENTDATABASE_OPERATIONS_H_
#include <fstream>
#include "student.h"


void create() {
	fstream file;
	file.open("StudentsGrades.db", ios::app);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Student st;
	cin >> st;
	file << st;
	cout << "Record saved!\n";
	file.close();

}

void sequentialSearch() {
	fstream file;
	file.open("StudentsGrades.db", ios::in);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Student st;
	unsigned long long fn;
	do { cin >> fn; } while (fn<0 || fn>pow(2, 50));
	bool found = false;
	file.seekg(0, ios::beg);
	while (file >> st) {
		if (st.getFacNum() == fn) { cout << st; found = true; break; }

	}
	if (!found) { cout << "Record not found!\n"; }
	file.close();

}
void operationParser() {
	string input;
	cin >> input;
	while (input != "exit") {

		if (input == "create") {
			create();
		}
		else if (input == "sequentialSearch") {
			sequentialSearch();
		}
		else { cout << "Invalid operation!\n"; }
		cin >> input;
	}
}

#endif