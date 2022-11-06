// Serhan Yilmaz
// Student ID: 00031275


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	double grade1, grade2, weighted_exam_grade, weighted_exam_avr, the1, the2, the3, the4, take_home_avr, ratio, recit, participation, course_grade, take_home_avr_new, avg_grade_to_pass;
	cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
	cin >> name;
	cout << "Hello " << name << ", what are your midterm and final exam grades? "; 
	cin >> grade1 >> grade2;
	weighted_exam_grade = 0.33 * grade1 + 0.35 * grade2;
	weighted_exam_avr = weighted_exam_grade/(0.68);
	avg_grade_to_pass = (30 * 0.33 + 30 * 0.35) / 0.68;
	if (weighted_exam_avr < avg_grade_to_pass) 
	{
		cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
	}
	else 
	{
		cout << "What are the grades of your 4 take-home exams? " ;
		cin >> the1 >> the2 >> the3 >> the4;
		take_home_avr = (the1 + the2 + the3 + the4)/4;
		ratio = take_home_avr / weighted_exam_avr;
		if (ratio <= 2) 
		{
			cout << "You'll get all the points earned from take-home exams!" << endl;
			cout << "How many days have you attended recitations? " ;
			cin >> recit;
			participation = (recit/13) * 100;
			course_grade = participation * 0.07 + take_home_avr* 0.25 + weighted_exam_grade;
			cout << name << ", your grade for CS201 is: " << course_grade << endl;
		}
		else if (ratio < 3 && ratio > 2) 
		{
			take_home_avr_new = take_home_avr * (3 - ratio);
			cout << "You'll get " << take_home_avr_new << " from the points earned from take-home exams!" << endl;
			cout << "How many days have you attended recitations? " ;
			cin >> recit;
			participation = (recit/13) * 100;
			course_grade = participation * 0.07 + take_home_avr_new* 0.25 + weighted_exam_grade;
			cout << name << ", your grade for CS201 is: " << course_grade << endl;
		}
		else if (ratio > 3) 
		{
			take_home_avr_new = 0;
			cout << "You'll get NONE of the points earned from take-home exams!" << endl;
			cout << "How many days have you attended recitations? " ;
			cin >> recit;
			participation = (recit/13) * 100;
			course_grade = participation * 0.07 + take_home_avr_new* 0.25 + weighted_exam_grade;
			cout << name << ", your grade for CS201 is: " << course_grade << endl;
		}
	}
}