#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    std::string name;
    double grade;
    char moreInput;

    std::cout << "Welcome to the Student Grades Management System!" << std::endl;

    // Input student names and grades
    do {
        std::cout << "Enter student's name: ";
        std::cin >> name;

        std::cout << "Enter " << name << "'s grade: ";
        while (!(std::cin >> grade) || grade < 0 || grade > 100) {
            std::cout << "Invalid input. Please enter a grade between 0 and 100: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        }

        students.push_back({name, grade});

        std::cout << "Do you want to enter another student? (y/n): ";
        std::cin >> moreInput;

    } while (moreInput == 'y' || moreInput == 'Y');

    if (students.empty()) {
        std::cout << "No student data entered." << std::endl;
        return 0;
    }

    // Calculate average, highest, and lowest grades
    double sum = 0;
    double highestGrade = std::numeric_limits<double>::min();
    double lowestGrade = std::numeric_limits<double>::max();

    for (const auto& student : students) {
        sum += student.grade;
        if (student.grade > highestGrade) {
            highestGrade = student.grade;
        }
        if (student.grade < lowestGrade) {
            lowestGrade = student.grade;
        }
    }

    double averageGrade = sum / students.size();

    // Display the results
    std::cout << "\nSummary of Grades:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.name << ": " << student.grade << std::endl;
    }
    std::cout << "\nAverage Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade << std::endl;

    return 0;
}
