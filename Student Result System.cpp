#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>

using namespace std;

class Student
{
public:
    string roll;
    int subjects;
    int marks[10];
    string name;
    string section;

    void addDetails();
    void addMarks();
    void displayResult();
};

Student students[100];
int count = 0;


// ============================================================
// Convert Roll Number to Uppercase
// This makes roll number comparison case-insensitive.
// Example: 25b11cs861 -> 25B11CS861
// ============================================================

string normalizeRoll(string roll)
{
    for (int i = 0; i < (int)roll.length(); i++)
    {
        roll[i] = toupper((unsigned char)roll[i]);
    }

    return roll;
}


// ============================================================
// Check Roll Number
// Rules:
// 1. Cannot be empty
// 2. Maximum 10 characters
// 3. Only alphabets and numbers
// 4. No spaces
// 5. No special characters
// ============================================================

bool validRollNumber(string roll)
{
    if (roll.length() == 0)
        return false;

    if (roll.length() > 10)
        return false;

    for (int i = 0; i < (int)roll.length(); i++)
    {
        if (!isalnum((unsigned char)roll[i]))
            return false;
    }

    return true;
}


// ============================================================
// Check Name
// Rules:
// 1. Cannot be empty
// 2. Must contain alphabets and spaces only
// 3. Cannot contain only spaces
// 4. No leading space
// 5. No trailing space
// 6. No consecutive spaces
// ============================================================

bool validName(string name)
{
    if (name.length() == 0)
        return false;

    bool hasAlphabet = false;

    for (int i = 0; i < (int)name.length(); i++)
    {
        if (isalpha((unsigned char)name[i]))
        {
            hasAlphabet = true;
        }
        else if (name[i] == ' ')
        {
            // Check leading space
            if (i == 0)
                return false;

            // Check trailing space
            if (i == (int)name.length() - 1)
                return false;

            // Check multiple consecutive spaces
            if (name[i + 1] == ' ')
                return false;
        }
        else
        {
            return false;
        }
    }

    return hasAlphabet;
}


// ============================================================
// Check Section
// Section must contain exactly one alphabet.
// ============================================================

bool validSection(string section)
{
    return section.length() == 1 &&
           isalpha((unsigned char)section[0]);
}


// ============================================================
// Convert Section to Uppercase
// ============================================================

string normalizeSection(string section)
{
    for (int i = 0; i < (int)section.length(); i++)
    {
        section[i] = toupper((unsigned char)section[i]);
    }

    return section;
}


// ============================================================
// Check Duplicate Roll Number
// Comparison is case-insensitive.
// ============================================================

bool rollExists(string roll)
{
    roll = normalizeRoll(roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
            return true;
    }

    return false;
}


// ============================================================
// Get Valid Integer
// Used for subjects, marks and menu choices.
// It checks the COMPLETE input.
// Example: "5abc" is rejected.
// ============================================================

bool getValidInteger(string input, int &number)
{
    if (input.length() == 0)
        return false;

    stringstream ss(input);

    char extra;

    if (!(ss >> number))
        return false;

    // If anything remains after the number,
    // the input is invalid.
    if (ss >> extra)
        return false;

    return true;
}


// ============================================================
// ADD STUDENT DETAILS
// ============================================================

void Student::addDetails()
{
    string input;

    // --------------------------------------------------------
    // Roll Number
    // --------------------------------------------------------

    while (true)
    {
        cout << "\nEnter Roll Number (Maximum 10 characters): ";
        cin >> roll;

        if (!validRollNumber(roll))
        {
            cout << "\nInvalid roll number format!\n";
            cout << "Roll number must contain only letters and numbers.\n";
            cout << "Maximum length is 10 characters.\n";
            cout << "Special characters and spaces are not allowed.\n";
        }
        else
        {
            roll = normalizeRoll(roll);

            if (rollExists(roll))
            {
                cout << "\nRoll number already exists!\n";
                cout << "Please enter another roll number.\n";
            }
            else
            {
                break;
            }
        }
    }


    // --------------------------------------------------------
    // Name
    // --------------------------------------------------------

    cin.ignore();

    while (true)
    {
        cout << "Enter Name: ";
        getline(cin, name);

        if (!validName(name))
        {
            cout << "\nInvalid name format!\n";
            cout << "Name must contain alphabets and single spaces only.\n";
            cout << "Leading, trailing and multiple spaces are not allowed.\n";
        }
        else
        {
            break;
        }
    }


    // --------------------------------------------------------
    // Section
    // --------------------------------------------------------

    while (true)
    {
        cout << "Enter Section (A-Z): ";
        cin >> section;

        if (!validSection(section))
        {
            cout << "\nInvalid section!\n";
            cout << "Enter one alphabet only (A-Z).\n";
        }
        else
        {
            section = normalizeSection(section);
            break;
        }
    }


    // --------------------------------------------------------
    // Number of Subjects
    // --------------------------------------------------------

    while (true)
    {
        cout << "Enter Number of Subjects (1-10): ";
        cin >> input;

        if (!getValidInteger(input, subjects))
        {
            cout << "\nInvalid number of subjects!\n";
            cout << "Please enter a number between 1 and 10.\n";
        }
        else if (subjects < 1 || subjects > 10)
        {
            cout << "\nInvalid number of subjects!\n";
            cout << "Please enter a number between 1 and 10.\n";
        }
        else
        {
            break;
        }
    }


    // --------------------------------------------------------
    // Add Marks
    // --------------------------------------------------------

    addMarks();
}


// ============================================================
// ADD / UPDATE MARKS
// ============================================================

void Student::addMarks()
{
    string input;

    for (int i = 0; i < subjects; i++)
    {
        while (true)
        {
            cout << "Enter Marks for Subject "
                 << i + 1 << " (0-100): ";

            cin >> input;

            if (!getValidInteger(input, marks[i]))
            {
                cout << "\nInvalid marks!\n";
                cout << "Please enter a numeric value between 0 and 100.\n";
            }
            else if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "\nInvalid marks!\n";
                cout << "Marks must be between 0 and 100.\n";
            }
            else
            {
                break;
            }
        }
    }

    cout << "\nMarks entered successfully!\n";
}


// ============================================================
// DISPLAY RESULT
// ============================================================

void Student::displayResult()
{
    int total = 0;
    bool pass = true;

    for (int i = 0; i < subjects; i++)
    {
        total += marks[i];

        if (marks[i] < 40)
            pass = false;
    }

    float percentage = (float)total / subjects;

    string grade;

    if (percentage >= 90)
        grade = "A+";
    else if (percentage >= 80)
        grade = "A";
    else if (percentage >= 70)
        grade = "B";
    else if (percentage >= 60)
        grade = "C";
    else if (percentage >= 50)
        grade = "D";
    else if (percentage >= 40)
        grade = "E";
    else
        grade = "F";

    if (percentage < 40)
        pass = false;


    // --------------------------------------------------------
    // Result Display
    // --------------------------------------------------------

    cout << "\n\n================================================";
    cout << "\n              STUDENT RESULT";
    cout << "\n================================================";

    cout << "\nRoll Number        : " << roll;
    cout << "\nName               : " << name;
    cout << "\nSection            : " << section;
    cout << "\nNumber of Subjects : " << subjects;

    cout << "\n------------------------------------------------";

    cout << "\nSubject\t\tMarks";
    cout << "\n------------------------------------------------";

    for (int i = 0; i < subjects; i++)
    {
        cout << "\nSubject " << i + 1
             << "\t" << marks[i];
    }

    cout << "\n------------------------------------------------";

    cout << "\nTotal              : "
         << total << " / " << subjects * 100;

    cout << "\nPercentage         : "
         << fixed << setprecision(2)
         << percentage << "%";

    cout << "\nGrade              : " << grade;

    cout << "\nResult             : "
         << (pass ? "PASS" : "FAIL");

    cout << "\n================================================\n";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    string input;
    string roll;
    int choice;
    int found;

    do
    {
        // ----------------------------------------------------
        // MAIN MENU
        // ----------------------------------------------------

        cout << "\n\n================================================";
        cout << "\n             STUDENT RESULT SYSTEM";
        cout << "\n================================================";
        cout << "\n1. Add Student Details";
        cout << "\n2. Add Marks";
        cout << "\n3. View Results";
        cout << "\n4. Exit";
        cout << "\n================================================";


        // ----------------------------------------------------
        // MENU INPUT VALIDATION
        // ----------------------------------------------------

        while (true)
        {
            cout << "\nEnter your choice: ";
            cin >> input;

            if (!getValidInteger(input, choice))
            {
                cout << "\nInvalid choice!";
                cout << " Please enter a number from 1 to 4.\n";
            }
            else if (choice < 1 || choice > 4)
            {
                cout << "\nInvalid choice!";
                cout << " Please enter a number from 1 to 4.\n";
            }
            else
            {
                break;
            }
        }


        // ----------------------------------------------------
        // MENU OPERATIONS
        // ----------------------------------------------------

        switch (choice)
        {
        case 1:

            if (count >= 100)
            {
                cout << "\nStudent storage is full!";
                cout << " Maximum 100 students can be added.\n";
                break;
            }

            students[count].addDetails();

            count++;

            cout << "\nStudent added successfully!";

            break;


        // ----------------------------------------------------
        // ADD / UPDATE MARKS
        // ----------------------------------------------------

        case 2:

            while (true)
            {
                cout << "\nEnter Roll Number: ";
                cin >> roll;

                if (!validRollNumber(roll))
                {
                    cout << "\nInvalid roll number format!\n";
                    cout << "Roll number must contain only letters and numbers.\n";
                    cout << "Maximum length is 10 characters.\n";
                    cout << "Special characters and spaces are not allowed.\n";
                    continue;
                }

                roll = normalizeRoll(roll);

                break;
            }

            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (students[i].roll == roll)
                {
                    students[i].addMarks();
                    found = 1;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent not found!";

            break;


        // ----------------------------------------------------
        // VIEW RESULTS
        // ----------------------------------------------------

        case 3:

            while (true)
            {
                cout << "\nEnter Roll Number: ";
                cin >> roll;

                if (!validRollNumber(roll))
                {
                    cout << "\nInvalid roll number format!\n";
                    cout << "Roll number must contain only letters and numbers.\n";
                    cout << "Maximum length is 10 characters.\n";
                    cout << "Special characters and spaces are not allowed.\n";
                    continue;
                }

                roll = normalizeRoll(roll);

                break;
            }

            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (students[i].roll == roll)
                {
                    students[i].displayResult();
                    found = 1;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent not found!";

            break;


        // ----------------------------------------------------
        // EXIT
        // ----------------------------------------------------

        case 4:

            cout << "\nThank you for using Student Result System!";

            break;
        }

    } while (choice != 4);


    return 0;
}
