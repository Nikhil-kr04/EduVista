Student Management System

Overview

This C program is a Student Management System that allows users to input student data, calculate ranks based on marks, determine scholarships, display data in tabular form, save student records to a CSV file, and visualize marks using a 3D graph (using graphics.h).

Features

Input Student Data: Collects details like name, roll number, marks, contact info, and financial details.

Rank Calculation: Ranks students based on their average marks.

Scholarship Calculation: Assigns scholarships to top-ranking students.

Tabular Display: Presents student details in a structured format.

CSV File Export: Saves student records for future reference.

3D Marks Visualization: Uses graphics to display subject-wise marks in a bar chart.

Data Structures Used

struct contact: Stores address, phone number, and email.

union fee_or_scholarship: Holds either scholarship percentage or tuition fee.

struct student: Main structure storing student details.

Compilation & Execution

Requirements

C Compiler (GCC, MinGW, Turbo C, etc.)

graphics.h library (required for plotting marks in a 3D graph)

Windows OS recommended (for graphics.h compatibility)

Steps to Compile & Run

Using GCC (Linux/Windows)

Install required graphics library:

Windows (MinGW users): Add graphics.h to the compiler's library.

Linux: Use SDL_bgi instead of graphics.h.

Compile the program:

gcc student_management.c -o student_management -lgraph

Run the executable:

./student_management

Functionalities Explained

1. Input Student Data

Collects details like name, roll number, marks in C, Mathematics, and Chemistry.

Validates phone numbers to ensure numeric input.

Computes the average marks.

2. Calculate Ranks

Sorts students in descending order based on their average marks.

Assigns rank 1 to the highest scorer.

3. Determine Scholarships

Rank 1: 100% Scholarship

Rank 2: 75% Scholarship

Rank 3: 50% Scholarship

Rank 4: 25% Scholarship

Others: Pay tuition fee (141240 * 1.25).

4. Display Data in Table

Shows student details including marks, rank, and scholarship/fee details.

5. Save Data to CSV

Exports all student data to a CSV file (students_data.csv).

6. 3D Visualization of Marks

Uses graphics.h to create a bar chart of marks in C, Mathematics, and Chemistry.

Colors:

Red: C marks

Green: Mathematics marks

Blue: Chemistry marks

Labels students and their marks on the graph.

Sample Output

-------------------------------------------------------------
Roll    Name            Average Rank    Scholarship/Fee
-------------------------------------------------------------
1       Alice           85.67    1      100% Scholarship | Reduced Fee: 0.00
2       Bob             78.33    2      75% Scholarship | Reduced Fee: 35310.00
3       Charlie         75.00    3      50% Scholarship | Reduced Fee: 70620.00
4       David           70.50    4      25% Scholarship | Reduced Fee: 105930.00
5       Eva             60.00    5      176550.00 Tuition Fee
-------------------------------------------------------------
Student data has been saved to 'students_data.csv'

Future Enhancements

GUI-based student management system

Additional subjects and dynamic grading system

Integration with a database

License

This project is open-source and free to use under the MIT License.

Author

Developed by [Your Name]

