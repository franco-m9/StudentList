/*
Name: Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework 6
Purpose: This is a main file which loops a menu of various options a user can do in relation to student information.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "studentlist.h"
using namespace std;

void Menu();

int main()
{
	StudentList a;	// creates studentlist object
	char menuoption;
	char userenterfile[30];


	Menu();
	do // loop that runs until user quits
	{
		cout << ">";
		cin >> menuoption;

		if (menuoption == 'I' || menuoption == 'i')
		{
			cout << "Enter a filename: ";
			cin >> userenterfile;
			if(!a.ImportFile(userenterfile))
			{
			cout << "Invalid file. No data imported" << endl;
			}
			cout << endl;
		}
		else if (menuoption == 'S' || menuoption == 's')
		{
			a.ShowList();
			cout << endl;
		}
		else if (menuoption == 'E' || menuoption == 'e')
		{
			cout << "Enter a filename: ";
			cin >> userenterfile;
			if(a.CreateReportFile(userenterfile)==false)
				cout << "Invalid file. No data exported" << endl;
			cout << endl;
		}
		else if (menuoption == 'M' || menuoption == 'm')
		{
			Menu();
			cout << endl;
		}
		else if (menuoption == 'Q' || menuoption == 'q')
		{
			cout << endl;
			cout << "Goodbye!" << endl;
		}
		else
			cout << "Invalid menu option, try again" << endl;
	} 
	while (menuoption != 'Q' && menuoption != 'q');




}
void Menu() // function for menu
{
	cout << "		***Student List menu***" << endl;
	cout << "	I	Import students form file" << endl;
	cout << "	S	Show student list (brief)" << endl;
	cout << "	E	Export a grade report (to file)" << endl;
	cout << "	M	Show this Menu" << endl;
	cout << "	Q	Quit Program" << endl;
}
