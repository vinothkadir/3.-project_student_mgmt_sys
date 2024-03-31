
#include <iostream>
#include <vector>
#include <string>

class Course {
public:
    std::string code;
    std::string title;
    int capacity;
    std::vector<std::string> enrolledStudents;

    Course(std::string courseCode, std::string courseTitle, int courseCapacity)
        : code(courseCode), title(courseTitle), capacity(courseCapacity) {}

    bool enrollStudent(std::string studentID) {
        if (enrolledStudents.size() < capacity) {
            enrolledStudents.push_back(studentID);
            return true;
        } else {
            std::cout << "Enrollment failed. Course is at full capacity." << std::endl;
            return false;
        }
    }
};

class Student {
public:
    std::string ID;
    std::string name;
    int age;
    std::vector<std::string> enrolledCourses;

    Student(std::string studentID, std::string studentName, int studentAge)
        : ID(studentID), name(studentName), age(studentAge) {}
};

class StudentManagementSystem {
private:
    std::vector<Student> students;
    std::vector<Course> courses;

public:
    void enrollStudentInCourse() {
        std::string studentID, studentName, courseCode;
        int studentAge;

        std::cout << "Enter student ID: ";
        std::cin >> studentID;
        std::cout << "Enter student name: ";
        std::cin.ignore(); // To clear the newline character left in the buffer
        std::getline(std::cin, studentName);
        std::cout << "Enter student age: ";
        std::cin >> studentAge;

        students.push_back(Student(studentID, studentName, studentAge));

        std::cout << "\nAvailable Courses:" << std::endl;
        displayAvailableCourses();

        std::cout << "Enter the course code to enroll the student: ";
        std::cin >> courseCode;

        for (auto& course : courses) {
            if (course.code == courseCode) {
                if (course.enrollStudent(studentID)) {
                    students.back().enrolledCourses.push_back(course.title);
                    std::cout << "Student enrolled successfully!" << std::endl;
                }
                return;
            }
        }

        std::cout << "Course not found." << std::endl;
    }

    void displayEnrolledStudentsInCourse() {
        std::string courseCode;

        std::cout << "Enter the course code to display enrolled students: ";
        std::cin >> courseCode;

        for (const auto& course : courses) {
            if (course.code == courseCode) {
                std::cout << "\nEnrolled Students in " << course.title << ":" << std::endl;
                for (const auto& studentID : course.enrolledStudents) {
                    for (const auto& student : students) {
                        if (student.ID == studentID) {
                            std::cout << "ID: " << student.ID << ", Name: " << student.name << ", Age: " << student.age << std::endl;
                            break;
                        }
                    }
                }
                return;
            }
        }

        std::cout << "Course not found." << std::endl;
    }

    void displayCoursesEnrolledByStudent() {
        std::string studentID;

        std::cout << "Enter student ID to display enrolled courses: ";
        std::cin >> studentID;

        for (const auto& student : students) {
            if (student.ID == studentID) {
                std::cout << "\nCourses Enrolled by Student " << student.ID << ":" << std::endl;
                for (const auto& courseTitle : student.enrolledCourses) {
                    std::cout << courseTitle << std::endl;
                }
                return;
            }
        }

        std::cout << "Student not found." << std::endl;
    }

    void displayAvailableCourses() {
        for (const auto& course : courses) {
            std::cout << course.code << " - " << course.title << " (Capacity: " << course.capacity << ")" << std::endl;
        }
    }

    void addCourse(std::string courseCode, std::string courseTitle, int capacity) {
        courses.push_back(Course(courseCode, courseTitle, capacity));
    }
};

int main() {
    StudentManagementSystem system;

    system.addCourse("CSC101", "Introduction to Computer Science", 30);
    system.addCourse("MTH201", "Calculus I", 25);
    system.addCourse("ENG101", "English Composition", 20);

    bool repeat = true;

    while (repeat) {
        std::cout << "\nWelcome to the Student Management System!\n"
                     "1. Enroll Student in a Course\n"
                     "2. Display Enrolled Students in a Course\n"
                     "3. Display Courses Enrolled by a Student\n"
                     "4. Exit\n\n"
                     "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.enrollStudentInCourse();
                break;
            case 2:
                system.displayEnrolledStudentsInCourse();
                break;
            case 3:
                system.displayCoursesEnrolledByStudent();
                break;
            case 4:
                repeat = false;
                std::cout << "Exiting the Student Management System. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}









