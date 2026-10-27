# Student Result System in C++

## 📌 Project Overview

The **Student Result System** is a simple console-based application developed using C++ as part of the Object-Oriented Programming (OOP) course. It helps manage student details, enter subject marks, and generate academic results efficiently.

The system validates student information, prevents duplicate roll numbers, calculates total marks and percentage, assigns grades, and displays the final result with pass/fail status.

## 🎯 Objectives

- To manage student details efficiently.
- To validate student names, sections, roll numbers, and marks.
- To prevent duplicate roll numbers.
- To calculate total marks and percentage automatically.
- To assign grades and determine pass/fail status.
- To implement fundamental Object-Oriented Programming concepts in C++.

## ✨ Features

- **Add Student Details:** Enter the student's roll number, name, section, and number of subjects.
- **Add Marks:** Enter or update marks for an existing student.
- **Input Validation:** Reject invalid names, sections, and marks outside the permitted range.
- **Duplicate Detection:** Prevent the entry of duplicate roll numbers.
- **Flexible Subjects:** Support different numbers of subjects for different students.
- **Automatic Result Calculation:** Calculate total marks, percentage, grade, and pass/fail status.
- **View Results:** Display student details and academic results in a readable format.
- **Simple Menu:** Navigate through the application using a menu-driven interface.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Concepts:** Object-Oriented Programming (OOP)
- **Compiler/IDE:** Dev-C++
- **Data Storage:** Array of objects (temporary storage during program execution)

## 🧠 OOP Concepts Implemented

- **Classes and Objects:** Represent student records and their operations.
- **Member Functions:** Organize operations such as adding details, entering marks, and displaying results.
- **Array of Objects:** Store multiple student records during program execution.
- **Encapsulation:** Combine student data and related operations within a class.
- **Function Modularization:** Divide the program into separate functions for better organization.
- **Data Validation:** Check user inputs before processing them.

## 📋 Main Menu

The application provides the following menu options:

1. Add Student Details
2. Add Marks
3. View Results
4. Exit

## ✅ Input Validation

The system performs several validation checks:

- Student names must contain alphabets and spaces only.
- Section must be a single alphabetic character.
- Roll numbers must be unique.
- The number of subjects must be between 1 and 10.
- Subject marks must be between 0 and 100.
- Invalid entries are rejected, and the user is prompted to enter valid information again.

## 📊 Result Calculation

The system calculates the following for each student:

- **Total Marks:** Sum of marks obtained in all subjects.
- **Percentage:** Total marks divided by the maximum possible marks, multiplied by 100.
- **Grade:** Assigned according to the percentage.
- **Result:** Determined using the percentage and minimum subject-mark requirements.

### Grading Criteria

| Percentage    | Grade |
| ------------- | ----- |
| 90% and above | A+    |
| 80%–89.99%    | A     |
| 70%–79.99%    | B     |
| 60%–69.99%    | C     |
| 50%–59.99%    | D     |
| 40%–49.99%    | E     |
| Below 40%     | F     |

**Pass Criteria:** The student must obtain at least 40% overall and at least 40 marks in every subject.

## 🚀 How to Run the Project

1. Clone or download this repository.
2. Open the project folder.
3. Open the C++ source file (`.cpp`) in Dev-C++ or another compatible C++ IDE.
4. Compile the program.
5. Run the executable.
6. Select an option from the main menu and follow the instructions displayed on the screen.

### Using a C++ Compiler

If a C++ compiler such as `g++` is installed, you can compile and run the program using:

```bash
g++ main.cpp -o StudentResultSystem
```

Run the executable on Windows:

```bash
StudentResultSystem.exe
```

*Replace `main.cpp` with the actual name of your source file if it differs.*

## 💻 Example

For a student with the following details:

- Roll Number: 101
- Name: Ravi Kumar
- Section: A
- Marks: 85, 90, 78

The system calculates:

- **Total Marks:** 253 / 300
- **Percentage:** 84.33%
- **Grade:** A
- **Result:** PASS

## ⚠️ Limitations

- Student records are stored in memory and are not saved permanently.
- All records are lost when the program terminates.
- The application uses a simple console-based interface.
- The system is designed for academic demonstration and small-scale use.

## 🔮 Future Enhancements

- Add permanent storage using files or a database.
- Introduce student record editing and deletion.
- Generate printable result reports.
- Add a graphical user interface.
- Include subject-wise performance analysis.
- Implement user authentication for secure access.

## 🎓 Learning Outcomes

This project provides practical experience in C++ programming, classes and objects, arrays of objects, member functions, input validation, conditional statements, loops, and modular programming. It demonstrates how OOP concepts can be applied to a real-world academic problem.

## 👨‍💻 Author

**Developed as an academic project** for the Object-Oriented Programming through C++ course.

## 📄 License

This project is intended for educational and learning purposes. You may adapt it for academic practice with appropriate attribution.
