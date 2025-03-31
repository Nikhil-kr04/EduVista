<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Management System - README</title>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Poppins', sans-serif;
            background-color: #f8f9fa;
            color: #333;
            margin: 20px;
            padding: 20px;
        }
        h1, h2, h3 {
            color: #2c3e50;
        }
        code {
            background-color: #e3e3e3;
            padding: 4px 6px;
            border-radius: 4px;
        }
        pre {
            background: #2c3e50;
            color: #ecf0f1;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
        .container {
            max-width: 900px;
            margin: auto;
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Student Management System</h1>
        <h2>Overview</h2>
        <p>This C program is a <strong>Student Management System</strong> that allows users to input student data, calculate ranks, determine scholarships, display data in tabular form, save records to a CSV file, and visualize marks using a <strong>3D graph</strong>.</p>

        <h2>Features</h2>
        <ul>
            <li><strong>Input Student Data</strong> - Collects student details.</li>
            <li><strong>Rank Calculation</strong> - Determines ranking based on average marks.</li>
            <li><strong>Scholarship Allocation</strong> - Assigns scholarships to top students.</li>
            <li><strong>CSV Export</strong> - Saves student data for record-keeping.</li>
            <li><strong>3D Visualization</strong> - Uses graphics to display marks in a bar chart.</li>
        </ul>

        <h2>Compilation & Execution</h2>
        <h3>Using GCC (Linux/Windows)</h3>
        <pre><code>gcc student_management.c -o student_management -lgraph
./student_management</code></pre>

        <h2>Sample Output</h2>
        <pre>
-------------------------------------------------------------
Roll    Name            Average Rank    Scholarship/Fee
-------------------------------------------------------------
1       Alice           85.67    1      100% Scholarship
2       Bob             78.33    2      75% Scholarship
3       Charlie         75.00    3      50% Scholarship
-------------------------------------------------------------
        </pre>

        <h2>License</h2>
        <p>This project is open-source and free to use under the <strong>MIT License</strong>.</p>
    </div>
</body>
</html>
