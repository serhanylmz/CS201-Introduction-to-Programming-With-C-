#include "student.h"
#include <iostream>
#include <vector>

//Code written by Serhan Yilmaz. Student number: 00031275

Student::Student()
{
	firstName = "";
	lastName = "";
	ID = "";
	points = -1.0;

	midtermWeight = 0.0; 
	finalWeight = 0.0;
	hwWeight = 0.0;

}

void Student::setId(string myID)
{
	ID = myID;
}

string Student::getId() const
{
	return ID;
}

void Student::setName(string line)
{
	string line_temp = line;
	line_temp.erase(0,9);
	int index = line_temp.rfind(" ");
	lastName = line_temp.substr(index+1);
	line_temp.erase(index);
	firstName = line_temp;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

void Student::setPoints(double point)
{
	points = point;
}

double Student::getPoints() const
{
	return points;
}

void Student::display(vector<Student> &rankedStuVec, int rank)
{
	cout << rank << ", " << rankedStuVec[rank-1].getId() << ", " << rankedStuVec[rank-1].getFirstName() << " " 
		<< rankedStuVec[rank-1].getLastName() << ", " << rankedStuVec[rank-1].getPoints() << endl;
}

void Student::setExamWeights(double Homework, double Midterm, double Final)
{
	hwWeight = Homework;
	midtermWeight = Midterm;
	finalWeight = Final;
}

double Student::getGrade(string examName, double examGrade) const
{
	double weight = 0.0, weightedGrade;
	if (examName == "***HOMEWORK***")
	{
		weight = hwWeight;
	}
	else if (examName == "***MIDTERM***")
	{
		weight = midtermWeight;
	}
	else if (examName == "***FINAL***")
	{
		weight = finalWeight;
	}
	
	weightedGrade = examGrade*weight;

	return weightedGrade;
}