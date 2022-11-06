#include <iostream>
#include <string>

using namespace std;

bool inputCheck(double speed, double weight, double minute)
{
	if (weight < 30) 
	{
		cout << "Weight out of range!" << endl;
		return false;
	}
	if (speed < 4 || speed > 30)
	{
		cout << "Speed out of range!" << endl;
		return false;
	}
	if ( minute < 0 || minute > 2000) 
	{
		cout << "Minute out of range!" << endl;
		return false;
	}
	
	return true;

	}

double calculateMET(double speed, string exercise)
{
	double met;
	if(exercise == "Walking")
	{
		if (speed >= 6.5)
		{
			met = 6.5;
		}
		if (speed < 6.5 && speed >= 4)
		{
			met = 4;
		}
		return met;
	}

	if(exercise == "Running")
	{
		if (speed >= 11)
		{
			met = 12.5;
		}
		if (speed < 11 && speed >= 4)
		{
			met = 9;
		}
		return met;
	}

	if(exercise == "Cycling")
	{
		if (speed >= 25)
		{
			met = 10.5;
		}
		if (speed < 25 && speed >= 20)
		{
			met = 8;
		}
		if (speed < 20 && speed >= 4)
		{
			met = 6;
		}
		return met;
	}

	return 0;
}

void displayResults(double difference, double total, double weight, double walkMET, double runMET, double cyclingMET, double walkCalorie, double runCalorie, double cycleCalorie)
{
	cout << "From walking, you burned " << walkCalorie << " calories." << endl;
	cout <<	"From running, you burned " << runCalorie << " calories." << endl;
	cout << "From cycling, you burned " << cycleCalorie << " calories." << endl;
	cout << "You burned " << total << " calories." << endl;

	if (difference == 0)
	{
		cout << "Congratulations! You have reached your goal!" << endl;
	}
	
	else if (difference < 0) 
	{
		double newdif = difference * (-1);
		cout << "You have surpassed your goal! You can eat something worth " << newdif << " calories :)" << endl;
	}

	else if (difference > 0)
	{
		double walkrate = (weight * walkMET) / 60.0;
		double runrate = (weight*runMET) / 60.0;
		double cyclerate = (weight*cyclingMET) / 60.0; //the calories burned, per minute
		double walktime = difference/walkrate;
		double runtime = difference/runrate;
		double cycletime = difference/cyclerate;
		cout << "You did not reach your goal by " << difference << " calories." << endl;
		cout << "You need to walk " << walktime << " minutes more to reach your goal or," << endl;
		cout << "You need to run " << runtime << " minutes more to reach your goal or," << endl;
		cout << "You need to do cycling " << cycletime << " minutes more to reach your goal." << endl;
	}
}

void computeResults(double weight, double goal, double speedWalk, double speedRun, double speedCycling, double minWalk, double minRun, double minCycling)
{
	double walkMET, runMET, cyclingMET, walkCalorie, runCalorie, cycleCalorie, total, difference;

	walkMET = calculateMET(speedWalk, "Walking");
	runMET = calculateMET(speedRun, "Running");
	cyclingMET = calculateMET(speedCycling, "Cycling");
	walkCalorie = weight * walkMET * minWalk / 60.0;
	runCalorie = weight * runMET * minRun / 60.0;
	cycleCalorie = weight * cyclingMET * minCycling / 60.0;
	total = walkCalorie + runCalorie + cycleCalorie;
	difference = goal - total;

	displayResults(difference, total, weight, walkMET, runMET, cyclingMET, walkCalorie, runCalorie, cycleCalorie);
	
}

void getInput(string username)
{
	double weight, goal, speedWalk, speedRun, speedCycling, minWalk, minRun, minCycling;
	cout << "Welcome " << username << ", please enter your weight(kg): ";
	cin >> weight;
	cout << username << ", please enter speed(km/h) and minutes spent in a week for the activities below." << endl;	cout << "Walking: ";	cin >> speedWalk >> minWalk;	cout << "Running: ";	cin >> speedRun >> minRun;	cout << "Cycling: ";	cin >> speedCycling >> minCycling;	cout << username << ", please enter your weekly calorie burn goal: ";	cin >> goal;

	if (inputCheck(speedWalk, weight, minWalk))
	{
		if(inputCheck(speedRun, weight, minRun))
		{
			if(inputCheck(speedCycling, weight, minCycling))
			{
				computeResults(weight, goal, speedWalk, speedRun, speedCycling, minWalk, minRun, minCycling);
			}
		}

	}
}

int main()
{
	string username;
	cout << "Please enter your name: ";
	cin >> username;
	getInput(username);
	cout << endl;
	cout << "Please enter your name: ";
	cin >> username;
	getInput(username);

	return 0;
}