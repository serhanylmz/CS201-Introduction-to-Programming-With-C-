#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

void assignStudents(ifstream &studentFile, vector<string> &studentIDS, vector<string> &studentNames, vector<string> &studentLastnames){

	string line, specificID, specificName, specificLastname;

	while(getline(studentFile, line)){

		istringstream input(line);
		input >> specificID >> specificName >> specificLastname;
		studentIDS.push_back(specificID);
		studentNames.push_back(specificName);
		studentLastnames.push_back(specificLastname);
}		

	studentNames.pop_back();
	studentLastnames.pop_back();
	studentIDS.pop_back();

}

void sortVector(vector<string> & studentName, vector<string> & studentLastname, vector<string> & studentIDS, vector<double> & studentPoints){
// Let us have a vestor myVec, with myVec.size() elements. Then, we aim to sort myVec in such a way that the elements are increasing or remaining equal (non-descending order).
// Hence, writing a vector sorting algorithm, using the methods shown in the lecture.
	int vectorSize = studentPoints.size(); //first assigning the vector size to a variable
    int neededLocation; //assigning a location variable.
	double interimDouble; // creating a double variable to hold the temporary double value
	string interimString; // creating a string variable to hold the temporary string value

	//Let the sorting begin. The vector will shift objects and iterate one-by-one.

    for (int k=0; k < vectorSize-1; k++){ 
        double tempDouble = studentPoints[k+1];
		string tempName = studentName[k+1], tempLastname = studentLastname[k+1], tempID = studentIDS[k+1];
        neededLocation = k+1;              
        while (0 < neededLocation  && tempDouble > studentPoints[neededLocation-1]){
            studentPoints[neededLocation] = studentPoints[neededLocation-1];
			studentName[neededLocation] = studentName[neededLocation-1];
			studentLastname[neededLocation] = studentLastname[neededLocation-1];
			studentIDS[neededLocation] = studentIDS[neededLocation-1];
            neededLocation--;
        }
        studentPoints[neededLocation] = tempDouble;
		studentName[neededLocation] = tempName;
		studentLastname[neededLocation] = tempLastname;
		studentIDS[neededLocation] = tempID;


    }

	for (int i = 1; i < studentPoints.size(); i++){
			if (studentPoints[i-1] == studentPoints[i]){
				if(studentLastname[i-1] > studentLastname[i]){
					interimString = studentLastname[i];
					studentLastname[i] = studentLastname[i-1];					
					studentLastname[i-1] = interimString;

					interimString = studentName[i];
					studentName[i] = studentName[i-1];					
					studentName[i-1] = interimString;

					interimDouble = studentPoints[i];
					studentPoints[i] = studentPoints[i-1];					
					studentPoints[i-1] = interimDouble;		
				}
			}
		}
	}

void calculateHW(ifstream &gradeFile, vector<string> &studentIDS, vector<double> &studentPoints){

	string lineHW, studentGrade, studentID;

		getline(gradeFile, lineHW);

	while( lineHW != ""){
		studentID = lineHW.substr(0,8);
		studentGrade = lineHW.substr(9);

		for (int i = 0; i < studentIDS.size(); i++){

			if(studentID == studentIDS[i]){

				if (studentPoints[i] == -1){
					studentPoints[i] = stoi(studentGrade)*0.1;
				}

				else{
					studentPoints[i] += stoi(studentGrade)*0.1;
				}
			}
		}

		getline(gradeFile, lineHW);
	}
}

void calculateMT(ifstream &gradeFile, vector<string> &studentIDS, vector<double> &studentPoints){
	string lineMT, studentGrade, studentID;
		getline(gradeFile, lineMT);
	while( lineMT != ""){

		studentGrade = lineMT.substr(9);
		studentID = lineMT.substr(0,8);

		for (int i = 0; i < studentIDS.size(); i++){
			if(studentID == studentIDS[i]){
				if (studentPoints[i] == -1){
					studentPoints[i] = stoi(studentGrade)*0.2;
				}
				else{
					studentPoints[i] += stoi(studentGrade)*0.2;
				}
			}
		}

		getline(gradeFile, lineMT);
	}
}

void calculateFinal(ifstream &gradeFile, vector<string> &studentIDS, vector<double> &studentPoints){
	string lineFinal, studentGrade, studentID;
		getline(gradeFile, lineFinal);
	while( lineFinal != ""){

		studentGrade = lineFinal.substr(9);
		studentID = lineFinal.substr(0,8);

		for (int i = 0; i < studentIDS.size(); i++){
			if(studentID == studentIDS[i]){
				if (studentPoints[i] == -1){
					studentPoints[i] = stoi(studentGrade)*0.3;
				}
				else{
					studentPoints[i] += stoi(studentGrade)*0.3;
				}
			}
			
		}

		getline(gradeFile, lineFinal);

	}
}

void requestedOrder(vector<string> &studentName, vector<string> &studentLastname, vector<string> &studentIDS, vector<double> &studentPoints)
{
	int orderNum;
	cout << "Enter the rank you want to query (enter 0 to exit): ";
	cin >> orderNum;
	while(orderNum != 0){
		if(orderNum > studentName.size() || orderNum < 0 ){
			cout << "Rank needs to be greater than 0 and smaller than " << studentName.size() + 1 << "!" << endl;
			cout << "Enter the rank you want to query (enter 0 to exit): ";
			cin >> orderNum;
		}
		else{
			cout << orderNum << ", " << studentIDS[orderNum-1] << ", "<< studentName[orderNum-1] << " " << studentLastname[orderNum-1] << ", " << studentPoints[orderNum-1] << endl;
			cout << "Enter the rank you want to query (enter 0 to exit): ";
			cin >> orderNum;
		}
	}
	cout <<"Exiting..." << endl;
}

int main(){

	vector<string> studentName, studentLastname, studentIDS;
	string gradeFile_name, studentFile_name, gradeLine;
	ifstream gradeFile, studentFile;

	if(checkFile(gradeFile, studentFile)){
		return 0;
	}

	assignStudents(studentFile, studentIDS, studentName, studentLastname);

	vector<double> studentPoints(studentIDS.size(),-1);


	while(getline(gradeFile, gradeLine)){
		if (gradeLine == "***HOMEWORK***"){
		calculateHW(gradeFile, studentIDS, studentPoints);
		}
		else if(gradeLine == "***MIDTERM***"){
		calculateMT(gradeFile, studentIDS, studentPoints);
		}
		else if (gradeLine == "***FINAL***"){
		calculateFinal(gradeFile, studentIDS, studentPoints);
		}
	}

	sortVector(studentName, studentLastname, studentIDS, studentPoints);
	for (int k = 0; k < studentName.size(); k++){

		if(studentPoints[k] == -1){
			studentName.pop_back();
			studentLastname.pop_back();
			studentIDS.pop_back();
			studentPoints.pop_back();
			k--;

		}
	}

	requestedOrder(studentName, studentLastname, studentIDS, studentPoints);

	return 0;
}
