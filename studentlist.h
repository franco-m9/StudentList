/*
Name: Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework 6
Purpose: This header file contains a Student class with has three derived course classes, alongside a StudentList class which contains all the member data and functions necessary to store student information
*/

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student // student base class with virtual functions for derived classes
{
public:
        Student(string firstnamee, string lastnamee, string coursee);
        string GetFirst() const;
        string GetLast() const;
        string GetCourse() const;
        double virtual GetFinal() = 0;	// accessor functions
        double virtual GetPerc() = 0;
        char virtual GetLetter() = 0;
protected:
        double virtual ComputeAvg() = 0;
        string firstname;
        string lastname;
        string course;


};


class StudentList
{
public:
	StudentList();		// starts out empty
	~StudentList();		// cleanup (destructor)

	bool ImportFile(const char* filename);
	bool CreateReportFile(const char* filename);
	void ShowList() const;	// print basic list data


protected:
	Student**list;	// pointer to a pointer
	int studentsize; // size variable
};

class English :public Student // derived classes
{
public:
	English(string firstnamee, string lastnamee,string coursee, double attendancee, double projecte, double midterme, double finalexame);
	double ComputeAvg();
	double GetFinal();
	double GetPerc();
	char GetLetter();

private:
	double attendance;
	double project;
	double midterm;
	double finalexam;
	double percentage;

};

class History :public Student
{
public:
	History(string firstnamee, string lastnamee,string coursee, double termpapere, double midterme, double finalexame);
	double ComputeAvg();
	double GetFinal();
	double GetPerc();
	char GetLetter();

private:
	double termpaper;
	double midterm;
	double finalexam;
	double percentage;
};

class Mathematics :public Student
{
public:
	Mathematics(string firstnamee, string lastnamee,string coursee, double quiz1e, double quiz2e, double quiz3e, double quiz4e, double quiz5e, double test1e, double test2e, double finalexame);
	double ComputeAvg();
	double GetFinal();
	double GetPerc();
	char GetLetter();

private:
	double quiz1;
	double quiz2;
	double quiz3;
	double quiz4;
	double quiz5;
	double quiztotal;
	double test1;
	double test2;
	double finalexam;
	double examtotal;
	double percentage;
};
