📚 Student Information Management System

A C program that manages student records, calculates ranks, awards scholarships, and visualizes marks using a 3D graphical representation.

---

🎯 Features
- Input and store student details including name, roll number, contact info, and marks.
- Compute the average marks and assign ranks.
- Award scholarships based on ranks and adjust tuition fees accordingly.
- Display student data in a tabular format.
- Save student details to a CSV file for easy access.
- 3D graphical visualization of student marks using bars (C, Math, Chemistry).

---

🛠 Installation & Usage
1. Clone the repository
   ```bash
   git clone https://github.com/yourusername/student-management.git
   cd student-management
   ```
2. Compile the program
   ```bash
   gcc student_management.c -o student_management -lgraph
   ```
3. Run the program
   ```bash
   ./student_management
   ```

---

📝 Code Explanation
🔹 Structures and Unions Used:
- <span style="color:#FF5733">`struct contact`</span> → Stores address, phone number, and email.
- <span style="color:#33FF57">`union fee_or_scholarship`</span> → Holds either scholarship percentage or tuition fee.
- <span style="color:#3399FF">`struct student`</span> → Combines student details, marks, and financials.

🔹 Key Functions:
- `inputStudentData()` → Takes input from the user.
- `calculateRanks()` → Assigns ranks based on average marks.
- `calculateScholarships()` → Determines scholarship or tuition fees.
- `displayTabularData()` → Prints student details in a formatted table.
- `saveToCSV()` → Saves student data to a CSV file.
- `plotMarks3D()` → Uses **graphics.h** to draw a 3D bar chart.

---

📊 Graphical Representation
The 3D graph plots the marks of each student in:
- 🔴 Red → C Language Marks
- 🟢 Green → Math Marks
- 🔵 Blue → Chemistry Marks

The bars for each student appear side by side with their respective scores displayed.

---

🏆 Scholarship Criteria
| Rank  | Scholarship  |
|-------|-------------|
| 1     | 100%       |
| 2     | 75%        |
| 3     | 50%        |
| 4     | 25%        |
| 5+    | Full Tuition Fee |

---

🗂 File Structure
```
student-management/
│── student_management.c  # Main C program
│── students_data.csv     # Output file (generated after running the program)
│── README.md             # Documentation
```

---

🔥 Contributing
Feel free to **fork** the repository and submit **pull requests** if you want to improve the project. Contributions are welcome!

---

📜 License
This project is licensed under the **MIT License**.
DEVELOPER -- NIKHIL KUMAR

Happy coding! 🚀


