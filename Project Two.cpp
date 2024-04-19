#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define Course class
class Course {
private:
    string courseNumber;
    string name;
    vector<string> prerequisites;

public:
    // Constructor
    Course(string courseNumber, string name, vector<string> prerequisites = {})
        : courseNumber(courseNumber), name(name), prerequisites(prerequisites) {}

    // Getter methods
    string getCourseNumber() const { return courseNumber; }
    string getName() const { return name; }
    vector<string> getPrerequisites() const { return prerequisites; }
};

// Function to print a list of courses
void printCourseList(const vector<Course>& courses) {
    vector<string> courseNames;
    for (const Course& course : courses) {
        courseNames.push_back(course.getCourseNumber() + ", " + course.getName());
    }
    sort(courseNames.begin(), courseNames.end());
    cout << "Here is a sample schedule:" << endl;
    for (const string& courseName : courseNames) {
        cout << courseName << endl;
    }
}

// Function to print course information
void printCourseInfo(const vector<Course>& courses, const string& courseNumber) {
    for (const Course& course : courses) {
        if (course.getCourseNumber() == courseNumber) {
            cout << course.getCourseNumber() << ", " << course.getName() << endl;
            cout << "Prerequisites: ";
            for (const string& prerequisite : course.getPrerequisites()) {
                cout << prerequisite << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Course not found." << endl;
}

int main() {
    // Define course data
    vector<Course> courses = {
        Course("MATH201", "Discrete Mathematics"),
        Course("CSCI300", "Introduction to Algorithms", {"CSCI200", "MATH201"}),
        Course("CSCI350", "Operating Systems", {"CSCI300"}),
        Course("CSCI101", "Introduction to Programming in C++", {"CSCI100"}),
        Course("CSCI100", "Introduction to Computer Science"),
        Course("CSCI301", "Advanced Programming in C++", {"CSCI101"}),
        Course("CSCI400", "Large Software Development", {"CSCI301", "CSCI350"}),
        Course("CSCI200", "Data Structures", {"CSCI101"})
    };

    // Display menu and prompt user for option
    int option = 0;
    string courseNumber;
    do {
        cout << "Welcome to the course planner." << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> option;

        switch (option) {
        case 1:
            // Already loaded data from file
            cout << "Data Structure loaded successfully." << endl;
            break;
        case 2:
            printCourseList(courses);
            break;
        case 3:
            cout << "What course do you want to know about? ";
            cin >> courseNumber;
            printCourseInfo(courses, courseNumber);
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break; // Add a break statement here
        }
    } while (option != 9);

    return 0;
}
