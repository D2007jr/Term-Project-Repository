#include<iostream> 
#include <string> 
using namespace std;

// Function Prototypes
void displayMenu();
void addStudent();
void deleteStudent(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[]);
void displayAllRecs(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[]);
void showStudentById(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[]);
void editStudentById(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[]);

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
		
		while (cin.fail()) // cin.fail vailidation check to ensure input of "opt" is of int type
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid Option or Input... Please try again: " << endl;
			cout << endl;
			displayMenu();
			cin >> opt;
		}

		switch (opt)

		{
		case 1: addStudent();

			break;

		case 2: deleteStudent(ID, fname, lname, midGrade, finalGrade);

			break;

		case 3: displayAllRecs(ID, fname, lname, midGrade, finalGrade);

			break;

		case 4: showStudentById(ID, fname, lname, midGrade, finalGrade);

			break;

		case 5: editStudentById(ID, fname, lname, midGrade, finalGrade);

			break;

		case 6:

			break;

		
		
		default:

			cout << "Invalid option" << endl;

			break;



		}

	} while (opt != 6);

	system("pause");
	return 0;

}

void displayMenu() 

{ // Simple Fucntion Displaying the Menu

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
	if (index == 20)	// Check if index is full, if true... throw max capacity error
						//if false... continue with adding students
	{
		cout << endl;
		cout << "Student Records at max capacity." << endl;
		cout << endl;
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



		while (midGrade[index] < 0 || midGrade[index] > 100 || cin.fail())				// Midterm grade validation check, ensures input is between 0 and 100 
																						// or is of correct input.
		{
			cin.clear();
			cin.ignore(1000, '\n');
			
			cout << "Invalid grade or input, enter a grade between 0 and 100: " << endl;
			cout << "Enter student's midterm grade: " << endl;

			cin >> midGrade[index];

		}

		cout << "Enter student's final grade: " << endl;

		cin >> finalGrade[index];

		while (finalGrade[index] < 0 || finalGrade[index] > 100 || cin.fail())			// Final grade validation check ensures input is between 0 and 100 
																						// or is of correct input.

		{
			cin.clear();
			cin.ignore(1000, '\n');
			
			cout << "Invalid grade or input, enter a grade between 0 and 100: " << endl;
			cout << "Enter student's final grade: " << endl;

			cin >> finalGrade[index];

		}
		index++;	// Increment index to add another student 
		cout << endl;
		cout << "Student Added" << endl;
		cout << endl;
	}
}


void deleteStudent(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[])

{
	if (index == 0)		// Checks if index is empty, if true throw error and exit function
	{
		cout << endl;
		cout << "No student records to delete: " << endl; 
		cout << endl;
		return;
	}
	
	cout << "Enter student record number from 1 to 20 to delete: " << endl; 
	cin >> searchId;

	while (cin.fail())								// Validate searchId input
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Input...Enter student record number from 1 to 20 to delete: " << endl;
		cin >> searchId;
	}


	if (searchId < 1 || searchId > 20 )	// Validate searchId input is between 1 and 20

	{
		cout << endl;
		cout << "Invalid record number, record number must be between 1 and 20. " << endl;
		cout << endl;
	}

	else

	{

		for (int i = searchId - 1; i < index - 1; i++)   // if the validation check for searchId input was between 1 and 20 enter this for loop
		{												 // and move all array values to the left array value, this ensures that there is no accesible student record
			ID[i] = ID[i + 1];							 // with blank values, in my testing after deleting a value, and then displaying all values, theere would be
			fname[i] = fname[i + 1];					 // various student records with blank or weird values, this was a good way of ensuring
			lname[i] = lname[i + 1];
			midGrade[i] = midGrade[i + 1];
			finalGrade[i] = finalGrade[i + 1];
		}

		cout << endl;
		cout << "Student succesfully deleted!" << endl;
		cout << endl;
		index--;
	}
}


void displayAllRecs(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[])

{
	if (index == 0)
	{
		cout << endl;
		cout << "There are no student records to display..." << endl;
		cout << endl;
		return;
	}
	
	cout << "ID" << "\t " << "First Name" << "\t" << "Last Name" << "\t" << "Midterm Grade" << "\t" << "FinalGrade" << endl;

	cout << "_________________________________________________________________________________________________________________" << endl;



	for (int i = 0; i < index; i++)

	{

		cout << ID[i] << "\t\t" << fname[i] << "\t\t" << lname[i] << "\t\t" << midGrade[i] << "\t\t" << finalGrade[i] << endl;

	}

}


void showStudentById(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[])

{

	int searchID;
	
	if (index == 0)
	{
		cout << endl;
		cout << "There are no student records to show..." << endl;
		cout << endl;
		return;
	}

	
	
	cout << "Enter student ID to search: ";
	cin >> searchID;

	bool found = false;

	for (int i = 0; i < 20; i++)

	{

		if (ID[i] == searchID)

		{

			cout << "--------------- Record found ---------------" << endl;

			cout << "Name: " << fname[i] << " " << lname[i] << endl;

			cout << "ID: " << ID[i] << endl;

			cout << "Midterm Grade: " << midGrade[i] << endl;

			cout << "Final Grade: " << finalGrade[i] << endl;

			found = true;

		}

	}

	if (!found)

	{

		cout << "Student with ID " << searchID << " not found." << endl;

	}

}


void editStudentById(int ID[], string fname[], string lname[], float midGrade[], float finalGrade[])

{

	int searchID;
	bool found = false;
	
	if (index == 0)
	{
		cout << endl;
		cout << "There are no student records to edit..." << endl;
		cout << endl;
		return;
	}
	
	cout << "Enter the ID of the student that you want to edit: " << endl;
	cin >> searchID;

	while (cin.fail()) // cin.fail vailidation check to ensure input is of int type
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Input... Please try again: " << endl;
		cout << endl;

		cout << "Enter the ID of the student that you want to edit: " << endl;
		cin >> searchID;
	}
	
	


	for (int i = 0; i < 20; i++)

	{

		if (ID[i] == searchID)

		{
			found = true;
			cout << "--------------- Record found ---------------" << endl;

			cout << "Name: " << fname[i] << " " << lname[i] << endl;

			cout << "ID: " << ID[i] << endl;

			cout << "Midterm Grade: " << midGrade[i] << endl;

			cout << "Final Grade: " << finalGrade[i] << endl;

			cout << "--------------------------------------------" << endl;

			cout << endl;



			cout << "Enter student's first name: " << endl;
			cin >> fname[i];

			while (cin.fail()) // cin.fail vailidation check to ensure input is of STRING type
			{
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Invalid Input... Please try again: " << endl;
				cout << endl;

				cout << "Enter student's first name: " << endl;
				cin >> fname[i];

			}



			cout << "Enter student's last name: " << endl;
			cin >> lname[i];
			
			while (cin.fail()) // cin.fail vailidation check to ensure input is of STRING type
			{
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Invalid Input... Please try again: " << endl;
				cout << endl;

				cout << "Enter student's last name: " << endl;
				cin >> lname[i];
			}



			
			cout << "Enter student's ID: " << endl;
			cin >> ID[i];
			
			while (cin.fail()) // cin.fail vailidation check to ensure input is of INT type
			{
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Invalid Input... Please try again: " << endl;
				cout << endl;
			
				cout << "Enter student's ID: " << endl;
				cin >> ID[i];
			}

			
			
		
			cout << "Enter student's midterm grade: " << endl;
			cin >> midGrade[i];
			
			while (midGrade[i] < 0 || midGrade[i] > 100 || cin.fail()) // Midterm grade validation check

			{

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid grade or input, enter a grade between 0 and 100: " << endl;
				cout << "Enter student's midterm grade: " << endl;

				cin >> midGrade[i];

			}



			
			
			cout << "Enter student's final grade: " << endl;
			cin >> finalGrade[i];
			
			while (finalGrade[i] < 0 || finalGrade[i] > 100 || cin.fail())   // Final grade validation check

			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid grade, enter a grade between 0 and 100: " << endl;
				cout << "Enter student's final grade: " << endl;
				cin >> finalGrade[i];

			}

		}

		
	}

	if (found != true)
	{
		cout << endl;
		cout << "Record not found..." << endl;
		cout << endl;
	}

}
