#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   // For input validation
#include <graphics.h> // Graphics library

// Nested structure and union for student information
struct contact {
    char Name[50];
    long Phone;
    
};



struct character {

    char name[50];
 // Nested structure

    int rank;
    union fee_or_scholarship financials; // Nested union
};

// Function prototypes
void inputStudentData(struct student *s, int index);
void calculateRanks(struct student *students, int n);
void calculateScholarships(struct student *students, int n);
void displayTabularData(struct student *students, int n);
void plotMarks3D(struct student *students, int n);
void saveToCSV(struct student *students, int n, const char *filename); // New function
void sortByAverage(struct student *students, int n);
void swap(struct student *a, struct student *b);

int main() {
    int n;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for students
    struct student *students = (struct student *)malloc(n * sizeof(struct student));

    // Input data for all students
    for (int i = 0; i < n; i++) {
        inputStudentData(&students[i], i + 1);
    }

    // Calculate ranks and scholarships
    calculateRanks(students, n);
    calculateScholarships(students, n);

    // Display all students' data in a tabular form
    displayTabularData(students, n);

    // Save student data to a CSV file
    const char *filename = "students_data.csv";
    saveToCSV(students, n, filename);
    printf("\nStudent data has been saved to '%s'\n", filename);

    // Visualize marks using a 3D graph
    plotMarks3D(students, n);

    // Free allocated memory
    free(students);
    return 0;
}

// Function to input data for a single student
void inputStudentData(struct student *s, int index) {
    s->roll = index;
    printf("Enter name for student %d: ", index);
    scanf(" %[^\n]s", s->name);

    printf("Enter address: ");
    scanf(" %[^\n]s", s->info.address);

    while (1) {
        printf("Enter phone number: ");
        char phone_input[20];
        scanf(" %[^\n]s", phone_input);

        // Validate if the input is a valid numeric string
        int is_valid = 1;
        for (int i = 0; phone_input[i] != '\0'; i++) {
            if (!isdigit(phone_input[i])) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid && strlen(phone_input) <= 10) {
            s->info.phone = atol(phone_input); // Convert to long
            break;
        } else {
            printf("Invalid phone number. Please enter a valid numeric phone number (max 10 digits).\n");
        }
    }
    
    printf("Enter email: ");
    scanf(" %[^\n]s", s->info.email);

    printf("Enter marks for C, Math, and Chemistry: ");
    scanf("%f %f %f", &s->c, &s->m, &s->ch);

    s->avg = (s->c + s->m + s->ch) / 3;
}

// Function to calculate ranks based on average marks
void calculateRanks(struct student *students, int n) {
    sortByAverage(students, n);
    for (int i = 0; i < n; i++) {
        students[i].rank = i + 1;
    }
}

// Function to sort students by average marks
void sortByAverage(struct student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].avg < students[j].avg) {
                swap(&students[i], &students[j]);
            }
        }
    }
}

// Swap function for student structures
void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate scholarships and adjust tuition fees
void calculateScholarships(struct student *students, int n) {
    for (int i = 0; i < n; i++) {
        switch (students[i].rank) {
            case 1:
                students[i].financials.scholarship = 100; // 100% scholarship
                break;
            case 2:
                students[i].financials.scholarship = 75; // 75% scholarship
                break;
            case 3:
                students[i].financials.scholarship = 50; // 50% scholarship
                break;
            case 4:
                students[i].financials.scholarship = 25; // 25% scholarship
                break;
            default:
                students[i].financials.tuition_fee = 141240 * 1.25; // Increased by 1.25 times
                break;
        }
    }
}

// Function to display data in tabular form
void displayTabularData(struct student *students, int n) {
    float base_fee = 141240;
    printf("\n-------------------------------------------------------------\n");
    printf("Roll\tName\t\tAverage\tRank\tScholarship/Fee\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (students[i].rank <= 4) {
            float reduced_fee = base_fee * (1 - students[i].financials.scholarship / 100);
            printf("%d\t%-15s\t%.2f\t%d\t%.2f%% Scholarship | Reduced Fee: %.2f\n",
                students[i].roll, students[i].name, students[i].avg, students[i].rank,
                students[i].financials.scholarship, reduced_fee);
        } else {
            printf("%d\t%-15s\t%.2f\t%d\t%.2f Tuition Fee\n",
                students[i].roll, students[i].name, students[i].avg, students[i].rank,
                students[i].financials.tuition_fee);
        }
    }

    printf("-------------------------------------------------------------\n");
}

// Function to save student data to a CSV file
void saveToCSV(struct student *students, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write the header row
    fprintf(file, "Roll,Name,Address,Phone,Email,C Marks,Math Marks,Chemistry Marks,Average,Rank,Scholarship/Fee\n");

    // Write each student's data
    float base_fee = 141240;
    for (int i = 0; i < n; i++) {
        if (students[i].rank <= 4) {
            float reduced_fee = base_fee * (1 - students[i].financials.scholarship / 100);
            fprintf(file, "%d,%s,%s,%ld,%s,%.2f,%.2f,%.2f,%.2f,%d,%.2f%% Scholarship (Reduced Fee: %.2f)\n",
                    students[i].roll, students[i].name, students[i].info.address, students[i].info.phone,
                    students[i].info.email, students[i].c, students[i].m, students[i].ch, students[i].avg,
                    students[i].rank, students[i].financials.scholarship, reduced_fee);
        } else {
            fprintf(file, "%d,%s,%s,%ld,%s,%.2f,%.2f,%.2f,%.2f,%d,%.2f Tuition Fee\n",
                    students[i].roll, students[i].name, students[i].info.address, students[i].info.phone,
                    students[i].info.email, students[i].c, students[i].m, students[i].ch, students[i].avg,
                    students[i].rank, students[i].financials.tuition_fee);
        }
    }

    fclose(file);
}


void plotMarks3D(struct student *students, int n) {
    // Initialize graphics in full-screen mode
    int gd = DETECT, gm;
    initwindow(getmaxwidth(), getmaxheight(), "3D Marks Graph", -3, -3);

    // Determine dynamic dimensions
    int y_max = 100;               // Maximum marks
    int x_spacing = 80;            // Horizontal spacing between students
    int graph_width = n * x_spacing + 100; // Extend graph width based on number of students
    int x_origin = 50;             // X-axis origin
    int y_origin = 400;            // Y-axis origin

    // Draw axes
    line(x_origin, y_origin, x_origin, 50);             // Y-axis
    line(x_origin, y_origin, x_origin + graph_width, y_origin); // X-axis
    line(x_origin, y_origin, x_origin + graph_width / 2, y_origin - 150); // Z-axis (decorative)

    // Add labels
    outtextxy(x_origin - 20, 40, "Marks");
    outtextxy(x_origin + graph_width - 50, y_origin + 10, "Students");
    outtextxy(x_origin + graph_width / 2 - 30, y_origin - 160, "Subjects");

    int bar_width = 20;            // Width of each bar
    int bar_spacing = 0;          // Spacing between bars for the same student
    int start_x = x_origin + 30;   // Starting X position for first student

    // Loop through students                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    for (int i = 0; i < n; i++) {
        int x_offset = start_x + i * x_spacing;

        // Bar for C marks
        setfillstyle(SOLID_FILL, RED);
        bar(x_offset, y_origin - students[i].c, x_offset + bar_width, y_origin);
        char c_marks[10];
        sprintf(c_marks, "%.1f", students[i].c);
        outtextxy(x_offset, y_origin - students[i].c - 15, c_marks);

        // Bar for Math marks
        setfillstyle(SOLID_FILL, GREEN);
        bar(x_offset + bar_width + bar_spacing, y_origin - students[i].m, x_offset + 2 * bar_width + bar_spacing, y_origin);
        char m_marks[10];
        sprintf(m_marks, "%.1f", students[i].m);
        outtextxy(x_offset + bar_width + bar_spacing, y_origin - students[i].m - 15, m_marks);

        // Bar for Chemistry marks
        setfillstyle(SOLID_FILL, BLUE);
        bar(x_offset + 2 * (bar_width + bar_spacing), y_origin - students[i].ch, x_offset + 3 * bar_width + 2 * bar_spacing, y_origin);
        char ch_marks[10];
        sprintf(ch_marks, "%.1f", students[i].ch);
        outtextxy(x_offset + 2 * (bar_width + bar_spacing), y_origin - students[i].ch - 15, ch_marks);

        // Student name
        outtextxy(x_offset, y_origin + 20, students[i].name);
    }

    getch();  // Wait for key press
    closegraph(); // Close graphics
}
