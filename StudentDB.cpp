#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

class college
{
	char snm[20], stnm[20], std[20], admdate[10], dec;
	int rn, age, f;
	fstream fs;

	public:
	void putread();
	void display();
	void rollnumberwise();
	void studentsearch();
	void deletestudent();
};


void college::putread()
{
	fs.open("college.txt", ios::out | ios::app);
	do {
		cout << "\nEnter Name, age, class, rollnumber, admission date: \n";
		cin >> stnm >> age >> std >> rn >> admdate;

		fs << stnm << "\t" << age << "\t" << std << "\t" << rn << "\t" << admdate << endl;
		cout << "\nWant to repeat (y/n)? : ";
		cin >> dec;
	} while (dec == 'y' || dec == 'Y');
	fs.close();
}


void college::display()
{
	fs.open("college.txt", ios::out | ios::in);
	while (fs) {
		fs >> stnm >> age >> std >> rn >> admdate;
		if (fs.eof() == 0)
			cout << stnm << "\t" << age << "\t" << std << "\t" << rn << "\t" << admdate << endl;
	}
	fs.close();
}


void college::studentsearch()
{
	fs.open("college.txt", ios::out | ios::in);
	f = 0;
	cout << "\nEnter student name to search : ";
	cin >> snm;

	while (fs) {
		fs >> stnm >> age >> std >> rn >> admdate;
		if (fs.eof() == 0)
			if (strcmp(stnm, snm) == 0) {
				f = 1;
				cout << stnm << "\t" << age << "\t" << std << "\t" << rn << "\t" << admdate << endl;
			}
	}
	fs.close();
	if (f == 0)
		cout << "\nRecord not found in database...\n";
}


void college::rollnumberwise()
{
	int rn1;
	fs.open("college.txt", ios::in);
	f = 0;
	cout << "\nEnter student roll number to search : ";
	cin >> rn1;

	while (fs) {
		fs >> stnm >> age >> std >> rn >> admdate;
		if (fs.eof() == 0)
			if (rn == rn1) {
				f = 1;
				cout << stnm << "\t" << age << "\t" << std << "\t" << rn << "\t" << admdate << endl;
			}
	}
	fs.close();
	if (f == 0)
		cout << "\nRecord not found in database...\n";
}


void college::deletestudent()
{
	int flag = 0;
	fstream temp;
	fs.open("college.txt", ios::in);
	temp.open("temp.dat", ios::out);

	cout << "Enter name to delete from database : ";
	cin >> snm;
	while (fs) {
		fs >> stnm >> age >> std >> rn >> admdate;
		if (fs.eof() == 0) {
			if (strcmp(snm, stnm) != 0)
				temp << stnm << "\t" << age << "\t" << std << "\t" << rn << "\t" << admdate << endl;
			else
				flag = 1;
		}
	}
	fs.close();
	temp.close();
	remove("college.txt");
	rename("temp.dat", "college.txt");
	if (flag == 0)
		cout << "\nRecord not found in database...\n";
	else
		cout << "Record deleted...\n";
}


int main()
{
	college ct;
	int ch;
	
	while (1) {
		cout << "\n\n\t\t*** Welcome To College Information System ***\n\n";
		cout << "1. Add Student.\n2. Student List.\n3. Student Search using Name.\n";
		cout << "4. Student search using Roll number.\n5. Delete Student Record.\n";
		cout << "6. Exit from Database.\n\n";

		cout << "Enter your choice : ";
		cin >> ch;

		switch (ch) {
			case 1:
				ct.putread();
				break;
			case 2:
				ct.display();
				break;
			case 3:
				ct.studentsearch();
				break;
			case 4:
				ct.rollnumberwise();
				break;
			case 5:
				ct.deletestudent();
				break;
			case 6:
				return 0;
			default:
				cout << "Enter valid choice...\n";
		}
	}
}
