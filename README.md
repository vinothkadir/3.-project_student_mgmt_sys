﻿# student_mgmt_sys
Project Title: Student Management System

Project Description: 
Developed a console-based Student Management System in C++ to manage student enrollments in courses, track enrolled students, and display course enrollment details.

Technologies Used:
C++
Standard Template Library (STL)
Object-Oriented Programming (OOP) principles

Key Features:
Implemented classes for Course, Student, and StudentManagementSystem to model courses, students, and the student management system.
Students can be enrolled in courses with details such as student ID, name, and age.
Courses have a capacity limit, and enrollment is checked against this limit.
Functionality to display enrolled students in a course, courses enrolled by a student, and available courses.
Implemented error handling for invalid input and course not found scenarios.

Your Contribution:
Designed and implemented the Course, Student, and StudentManagementSystem classes.
Developed functionalities for enrolling students in courses and displaying course and student details.
Ensured proper encapsulation and data management within the system.

Challenges and Solutions:
Handling the association between courses and students and managing enrollments efficiently.
Solution: Implemented logic to link students with their enrolled courses and display relevant information when requested.

Results or Impact:
Created a functional Student Management System that facilitates easy enrollment management and course tracking for educational institutions.

Future Enhancements:
Implement additional features such as student authentication, course scheduling, and grading functionalities for a comprehensive student management solution.

Time Complexity:
1.Enrolling a student in a course: O(n)
2.Displaying enrolled students in a course: O(n^2)
3.Displaying courses enrolled by a student: O(n)
4.Displaying available courses: O(n)

Space Complexity:
1.Student class: O(1) per instance
2.Course class: O(m) per instance (where m is the number of enrolled students)
3.StudentManagementSystem class: O(n + m) (where n is the number of students and m is the total number of enrolled students across all courses)
4.Additional space for vectors storing courses and students: O(n + m)

