/*
Name: Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework 6
Purpose: This cpp file contains all function definitions from the header file to successfully store students and their info into the student list
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "studentlist.h"
using namespace std;

StudentList::StudentList() // initializes to null and 0 size
{
	list = 0;
	studentsize = 0;
}
StudentList::~StudentList() // destructor for every index of pointer array
{
	if(list!=0)
	{
	for (int i = 0; i < studentsize; i++)
		delete list[i];
	delete [] list;
	list = 0;
	}
}

bool StudentList::ImportFile(const char * filename)
{
	ifstream f;
	string sfirstname, slastname, scourse; // restating variables
	double eattendance, eproject, emidterm, efinalexam;
	double htermpaper, hmidterm, hfinalexam;
	double mquiz1, mquiz2, mquiz3, mquiz4, mquiz5, mtest1, mtest2, mfinalexam;


	f.open(filename);
	if (!f.is_open())
	{
		return false; // fails if file doesn't exist
	}
	else
	{
		int oldsize = studentsize; // for resizing the dynamic array to appropriate size and if appending, start from the last part
		f >> studentsize;
		studentsize += oldsize;
		Student**temp= new Student*[studentsize];
		for(int i=0; i<oldsize; i++)
		temp[i]=list[i];
		delete [] list;
		list = temp;
		
		f.ignore(100, '\n');
		for (int i = oldsize; i < studentsize; i++)
		{
			getline(f, slastname, ',');
			f.ignore();
			getline(f, sfirstname, '\n');
			getline(f, scourse, ' ');
			if (scourse[0] == 'E')
			{
				f >> eattendance;
				f >> eproject;
				f >> emidterm;
				f >> efinalexam;
				f.ignore(100, '\n');
				list[i] = new English (sfirstname, slastname, scourse, eattendance, eproject, emidterm, efinalexam); // creates appropirate course student to list
			}
			else if (scourse[0] == 'H')
			{
				f >> htermpaper;
				f >> hmidterm;
				f >> hfinalexam;
				f.ignore(100, '\n');
				list[i] = new History (sfirstname, slastname, scourse, htermpaper, hmidterm, hfinalexam);
			}
			else if (scourse[0] == 'M')
			{
				f >> mquiz1;
				f >> mquiz2;
				f >> mquiz3;
				f >> mquiz4;
				f >> mquiz5;
				f >> mtest1;
				f >> mtest2;
				f >> mfinalexam;
				f.ignore(100,'\n');
				list[i] = new Mathematics (sfirstname, slastname, scourse, mquiz1, mquiz2, mquiz3, mquiz4, mquiz5, mtest1, mtest2, mfinalexam);
			}
		}
	}
	f.close();
	return true;
}

bool StudentList::CreateReportFile(const char * filename)
{
	int Acount, Bcount, Ccount, Dcount, Fcount; // counter variables to track overall grades
	Acount = 0;
	Bcount = 0;
	Ccount = 0;
	Dcount = 0;
	Fcount = 0;
	ofstream g;
	g.open(filename, ios::app); // appends if already written
	if (!g)
		return false;
	else
	{
		g << "Student Grade Summary" << endl;
		g << "---------------------" << endl << endl;
		g << "ENGLISH CLASS" << endl << endl;
		g.setf(ios::left); // setw() and set precision to format the export file
		g << setw(41) << "Student" << setw(8) << "Final" << setw(8) << "Final" << setw(8) <<  "Letter" << endl;
		g << setw(41) << "Name" << setw(8) << "Exam" << setw(8) <<  "Avg" << setw(8) << "Grade" << endl;
		g.unsetf(ios::left);
		g << "----------------------------------------------------------------------" << endl;
		for (int i = 0; i < studentsize; i++)
		{
			if (list[i]->GetCourse() == "English")
			{
			g.setf(ios::left);
			g << setw(41) << list[i]->GetFirst() + " " + list[i]->GetLast() << setw(8) << fixed << setprecision(0) << list[i]->GetFinal() << setw(8) <<
			setprecision(2) << list[i]->GetPerc() << setw(8) << list[i]->GetLetter() << endl;
			g.unsetf(ios::left);
			}
		}
		g << endl << endl;
		g << "HISTORY CLASS" << endl << endl;
		g.setf(ios::left);
		g << setw(41) << "Student" << setw(8) << "Final" << setw(8) << "Final" << setw(8) << "Letter" << endl;
		g << setw(41) << "Name" << setw(8) << "Exam" << setw(8) << "Avg" << setw(8) << "Grade" << endl;
		g.unsetf(ios::left);
		g << "----------------------------------------------------------------------" << endl;
		for (int i = 0; i < studentsize; i++)
		{
			if (list[i]->GetCourse() == "History")
			{
			g.setf(ios::left);
			g << setw(41) << list[i]->GetFirst() + " " + list[i]->GetLast() << setw(8) << fixed << setprecision(0) << list[i]->GetFinal() << setw(8) <<
			setprecision(2) <<  list[i]->GetPerc() << setw(8) << list[i]->GetLetter() << endl;
			g.unsetf(ios::left);
			}
		}
		g << endl << endl;
		g << "MATH CLASS" << endl << endl;
		g.setf(ios::left);
		g << setw(41) << "Student" << setw(8) <<  "Final" << setw(8) << "Final" << setw(8) << "Letter" << endl;
		g << setw(41) << "Name" << setw(8) << "Exam" << setw(8) << "Avg" << setw(8) << "Grade" << endl;
		g.unsetf(ios::left);
		g << "----------------------------------------------------------------------" << endl;
		for (int i = 0; i < studentsize; i++)
		{
			if (list[i]->GetCourse() == "Math")
			{
			g.setf(ios::left);
			g << setw(41) << list[i]->GetFirst() + " " + list[i]->GetLast() << setw(8) << fixed << setprecision(0) << list[i]->GetFinal() << setw(8) << 
			setprecision(2) << list[i]->GetPerc() << setw(8) << list[i]->GetLetter() << endl;
			g.unsetf(ios::left);
			}
		}
		for (int i=0;i<studentsize;i++)
		{
			if (list[i]->GetLetter() == 'A')
                                Acount++;
                        else if (list[i]->GetLetter() == 'B')
                                Bcount++;
                        else if (list[i]->GetLetter() == 'C')
                                Ccount++;
                        else if (list[i]->GetLetter() == 'D')
                                Dcount++;
                        else if (list[i]->GetLetter() == 'F')
                                Fcount++;
		}
		g << endl << endl;
		g << "OVERALL GRADE DISTRIBUTION" << endl << endl;
		g << "A:	" << Acount << endl;
		g << "B:	" << Bcount << endl;
		g << "C:	" << Ccount << endl;
		g << "D:	" << Dcount << endl;
		g << "F:	" << Fcount << endl;
	}
	g.close();
	return true;
}

void StudentList::ShowList() const
{	
	cout << left;
	cout << setw(25) <<  "Last" << setw(30) << "First" <<  "Course" << endl << endl;
	for (int i = 0; i < studentsize; i++)
	{
		cout << setw(25) <<  list[i]->GetLast() << setw(30) <<  list[i]->GetFirst() << list[i]->GetCourse() << endl;
	}
	cout << right;
}

string Student::GetFirst() const
{
	return firstname;
}

string Student::GetLast() const
{
	return lastname;
}

string Student::GetCourse() const
{
	return course;
}

English::English(string firstnamee, string lastnamee, string coursee, double attendancee, double projecte, double midterme, double finalexame) : Student( firstnamee,lastnamee,coursee )
{
	attendance = attendancee;
	project = projecte;
	midterm = midterme;
	finalexam = finalexame;
}

double English::ComputeAvg()
{
	percentage = (attendance*.10) + (project*.30) + (midterm*.30) + (finalexam*.30);
		return percentage;
}

double English::GetFinal()
{
	return finalexam;
}

double English::GetPerc()
{
	return ComputeAvg();
}

char English::GetLetter()
{
	if (GetPerc() >= 90)
		return 'A';
	else if (GetPerc() >= 80)
		return 'B';
	else if (GetPerc() >= 70)
		return 'C';
	else if (GetPerc() >= 60)
		return 'D';
	else
		return 'F';
}

History::History(string firstnamee, string lastnamee,string coursee, double termpapere, double midterme, double finalexame) : Student (firstnamee,lastnamee,coursee)
{
	termpaper = termpapere;
	midterm = midterme;
	finalexam = finalexame;
}

double History::ComputeAvg()
{
	percentage = (termpaper*.25) + (midterm*.35) + (finalexam*.40);
		return percentage;
}

double History::GetFinal()
{
	return finalexam;
}

double History::GetPerc()
{
	return ComputeAvg();
}

char History::GetLetter()
{
	if (GetPerc() >= 90)
		return 'A';
	else if (GetPerc() >= 80)
		return 'B';
	else if (GetPerc() >= 70)
		return 'C';
	else if (GetPerc() >= 60)
		return 'D';
	else
		return 'F';
}

Mathematics::Mathematics(string firstnamee, string lastnamee,string coursee, double quiz1e, double quiz2e, double quiz3e, double quiz4e, double quiz5e, double test1e, double test2e, double finalexame) : Student( firstnamee,lastnamee,coursee)
{
	quiz1 = quiz1e;
	quiz2 = quiz2e;
	quiz3 = quiz3e;
	quiz4 = quiz4e;
	quiz5 = quiz5e;
	test1 = test1e;
	test2 = test2e;
	finalexam = finalexame;
}

double Mathematics::ComputeAvg()
{
	quiztotal = ((quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5)*(.15);
	examtotal = (test1*.25) + (test2*.25) + (finalexam*.35);
	percentage = (quiztotal + examtotal);
		return percentage;
}

double Mathematics::GetFinal()
{
	return finalexam;
}

double Mathematics::GetPerc()
{
	return ComputeAvg();
}

char Mathematics::GetLetter()
{
	if (GetPerc() >= 90)
		return 'A';
	else if (GetPerc() >= 80)
		return 'B';
	else if (GetPerc() >= 70)
		return 'C';
	else if (GetPerc() >= 60)
		return 'D';
	else
		return 'F';
}

Student::Student(string firstnamee, string lastnamee, string coursee)
{
	firstname = firstnamee;
	lastname = lastnamee;
	course = coursee;
}
