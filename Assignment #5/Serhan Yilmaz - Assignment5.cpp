#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "student.h"

using namespace std;

//Prepared by Serhan Yilmaz. Student Number: 00031275

bool checkFile( ifstream &gradeFile, ifstream &studentFile){

	string gradeFile_name, studentFile_name;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> gradeFile_name;	
	gradeFile.open(gradeFile_name.c_str());
	if (gradeFile.fail()){
		cout << "Can not find the requested file. Terminating application ..." << endl;
		return true;
	}
	cout << "Please enter a filename for Students Names: ";
	cin >> studentFile_name;
	studentFile.open(studentFile_name.c_str());
	if (studentFile.fail()){
		cout << "Can not find the requested file. Terminating application ..." << endl;
		return true;
	}

	return false;
}
//no need to change this part

void assignStudents(ifstream &studentFile, vector<Student>& StuVector){

	string line;
	while(getline(studentFile, line)){

		istringstream input(line);
		string specificID;
		input >> specificID;
		Student myStu;
		myStu.setId(specificID);
		myStu.setName(line);
		StuVector.push_back(myStu);
	}

	//StuVector.pop_back(myStu);

}
//this part is taken from the4 again, and readjuýsted to the Student-class vector.
//by the end of this assignStudents part, we now hold a Student-class vector with all Student's assigned
//by this point, each Student-object in the Student-vector, holds three of the private data values
//these are: ID, firstName and lastName
//now comes the match of ID with grades, the initial value of points, that is assigned in student.cpp is 0.0
//therefore, the grade of each assignment will be calculated with the getGrade method
//and will be added to the existing points of the student, using the setPoints member function

void finalizeGrades(ifstream &gradeFile, vector<Student> &StuVector)
{
	string line, studentID, studentGrade, assignmentType;

	while(getline(gradeFile, line))
	{
		if (line == "***HOMEWORK***" || line == "***MIDTERM***" || line == "***FINAL***")
		{
			if (line == "***HOMEWORK***")
			{
				assignmentType = "***HOMEWORK***";
			}
			
			else if (line == "***MIDTERM***")
			{
				assignmentType = "***MIDTERM***";
			}

			else if (line == "***FINAL***")
			{
				assignmentType = "***FINAL***";
			}
		}
		else
		{
			if (line != "")
			{
				studentID = line.substr(0,8);
				studentGrade = line.substr(9);

				for (int i = 0; i < StuVector.size(); i++)
				{
					StuVector[i].setExamWeights(0.1, 0.2, 0.3);

					if(studentID == StuVector[i].getId())
					{
						if (StuVector[i].getPoints() != -1.0)
						{
							StuVector[i].setPoints(StuVector[i].getPoints() + StuVector[i].getGrade(assignmentType, stoi(studentGrade)));
						}
						else
						{
							StuVector[i].setPoints(StuVector[i].getGrade(assignmentType, stoi(studentGrade)));
						}
					}
				}
			}
			else 
			{
				continue;
			}
		}
	}
}

//now, by this point, we have a Student-class vector, including all Student's
//by this point, each Student object in the Student class Vector has all of the private variables assigned
//the private data variables are ID, firstName, lastName and points for the part that we will use later
//the private data variables also include hwWeight, midtermWeight and finalWeight, which all of them are set to their values
//howwever, these three will not be needed later
//at this point, we will use the sorting algorithm, provided by gülþen hoca in the class, to sort out the vector
//the process will be as follows:
//the points data from each student will be taken, then according to the points variable,
//the Student-objects in the Student-class vector will be rearranged, in a descending (and non-ascending) order

void sortStuVector(vector<Student>& StuVector)
{
	int vectorSize = StuVector.size(); // indicating the number of the students
	int neededLocation; //assigning a location variable
	double interimDouble; //double variable to hold the temporary double variable
	Student interimStudent; //string variable to hold the temporary Student variable

	//now, let the sorting begin

	for (int i = 0; i < vectorSize-1; i++)
	{
		Student tempStudent = StuVector[i+1];
		double tempDouble = StuVector[i+1].getPoints();
		neededLocation = i+1;

		while(i+1 >0 && tempDouble > StuVector[i].getPoints())
		{
			StuVector[i+1] = StuVector[i];
			i--;
		}
		StuVector[i+1] = tempStudent;
	}

	for (int i = 1; i<StuVector.size(); i++)
	{
		if(StuVector[i-1].getPoints() == StuVector[i].getPoints())
		{
			if (StuVector[i-1].getLastName() > StuVector[i].getLastName())
			{
				interimStudent = StuVector[i];
				StuVector[i] = StuVector[i-1];
				StuVector[i-1] = interimStudent;
			}
		}
	}

}

//now, following the sorting algorithm above, we should have an ordered vector
//the Student elements of this Student-class vector are ordered
//this ordering is done according to two private data variables: points and lastName, respectively
//so, the students are listed with descending points, and in cases where they have equal points,
//they are listed alphabetically, according to their last name
//now, before moving onto the main function, we have one final function to write
//this will be a printer function, that will give us the final output
//the function should first ask for an input, that will be the rank of the student
//then, the function will checl if the rank is valid or not
//if the rank is not valid, the program will output that the input is false
//and then the program will ask for another input
//if the rank is valid, the program will output the student in the desired rank, 
//and the program will ask for another input, until the user enters 0.
//here begins the function:

void wantedRank(vector<Student>& StuVector)
{
	int rankNum;
	cout << "Enter the rank you want to query (enter 0 to exit): ";
	cin >> rankNum;
	while(rankNum != 0)
	{
		if (rankNum > StuVector.size() || rankNum < 0)
		{
			cout << "Rank needs to be greater than 0 and smaller than " << StuVector.size()+1 << "!" << endl;
			cout << "Enter the rank you want to query (enter 0 to exit): ";
			cin >> rankNum;
		}
		else
		{
			StuVector[rankNum-1].display(StuVector, rankNum);
			cout << "Enter the rank you want to query (enter 0 to exit): ";
			cin >> rankNum;
		}
	}
	cout << "Exiting..." << endl;
}

//all right, now that the final function is done as well
//we can start writing our main function, in which we will mainly call our functions
//functions which we created so far

int main()
{
	vector<Student> StuVector;
	string gradeFile_name, studentFile_name, gradeLine;
	ifstream gradeFile, studentFile;

	if (checkFile(gradeFile, studentFile))
	{
		return 0;
	}

	assignStudents(studentFile, StuVector);

	finalizeGrades(gradeFile, StuVector);

	sortStuVector(StuVector);

	for (int j = 0; j < StuVector.size(); j++)
	{
		if (StuVector[j].getPoints() == -1)
		{
			StuVector.pop_back();
			j--;
		}
	}

	wantedRank(StuVector);

	return 0;
}
