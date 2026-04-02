#include<iostream>
#include <string>
using namespace std;


// Function Prototypes
//void deleteStudent();
void displayMenu();
void addStudent();
void deleteStudent();
void displayAllRecs();
void showStudentById();
void editStudentById();

//variable declarations
int ID[20];
string fname[20], lname[20];
float midGrade[20], finalGrade[20];
int index = 0, searchId;

int main()
{

	int opt;


	// do while loop to keep printing menu so long as the user does not type 6
	//variable "opt" is used to keep track of menu input
	do
	{
		displayMenu();
		cin >> opt;

		switch (opt)
		{

		case 1: addStudent();
			break;
		case 2: deleteStudent();
			break;
		case 3: displayAllRecs();
			break;
		case 4: showStudentById();
			break;

		default: editStudentById();
			break;

		}

	} while (opt != 6);



	system("pause");
	return 0;

}
void displayMenu()
{
	cout << "Please select one of the following options:" << endl;
	cout << "[1] Add a new student record." << endl;
	cout << "[2] Delete a student record." << endl;
	cout << "[3] Display all student records." << endl;
	cout << "[4] Show a student record by ID." << endl;
	cout << "[5] Edit a student record." << endl;
	cout << "[6] Exit." << endl;

}
void addStudent()
{


	if (index == 20)
	{
		cout << "Student Records at max capacity." << endl;
	}
	else
	{

		cout << "Enter student's first name: " << endl;
		cin >> fname[index];

		cout << "Enter student's last name: " << endl;
		cin >> lname[index];

		cout << "Enter student's ID: " << endl;
		cin >> ID[index];
		cout << "Enter student's midterm grade: " << endl;
		cin >> midGrade[index];

		while (midGrade[index] < 0 || midGrade[index] > 100)
		{
			cout << "invalid grade, enter a grade between 0 and 100: " << endl;
			cout << "Enter student's midterm grade: " << endl;
			cin >> midGrade[index];
		}
		cout << "Enter student's final grade: " << endl;
		cin >> finalGrade[index];

		while (finalGrade[index] < 0 || finalGrade[index] > 100)
		{
			cout << "invalid grade, enter a grade between 0 and 100: " << endl;
			cout << "Enter student's final grade: " << endl;
			cin >> finalGrade[index];
		}

		index++;
		cout << "Student Added" << endl;

	}

}

void deleteStudent(string fname[], string lname[], int ID[], float medGrade[], float finalGrade[])
{

	cout << "Enter student record number from 1 to 20 to delete: " << endl;
	cin >> searchId;
	if (searchId < 1 || searchId > 20)
	{
		cout << "Invalid record number, record number must be between 1 and 20. " << endl;
	}
	else
	{
		fName[index - 1] = " ";
		lName[studentIndex - 1] = " ";
		ID[studentIndex - 1] = 0;
		midGrade[studentIndex - 1] = 0;
		finalGrade[studentIndex - 1] = 0;

		cout << "Student deleted successfully." << endl;
	}



	void displayAllRecs()
	{
		cout << "ID" << "\t " << "First Name" << "\t" << "Last Name" << "\t" << "Midterm Grade" << "\t" << "FinalGrade" << endl;
		cout << "_________________________________________________________________________________________________________________" << endl;

		for (int i = 0; i < index; i++)
		{
			cout << ID[i] << "\t" << fname[i] << "\t" << lname[i] << "\t" << midGrade[i] << "\t" << finalGrade[i] << endl;
		}
	}
	void showStudentById()
	{
		int searchID;
		cout << "Enter student ID to search: ";
		cin >> searchID;

		bool found = false;
		for (int i = 0; i < 20; i++)
		{
			if (ID[i] == searchID)
			{

				cout << "Record found:";
				cout << "Name: " << fName[i] << " " << lName[i] << endl;
				cout << "ID: " << ID[i] << endl;
				cout << "Midterm Grade: " << midGrade[i] << endl;
				cout << "Final Grade: " << finalGrade[i] << endl;

				found = true;

			}
		}

		if (!found)
		{
			cout << "Student with ID " << ID << " not found." << endl;
		}
	}