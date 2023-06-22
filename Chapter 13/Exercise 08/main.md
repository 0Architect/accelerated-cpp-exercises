#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>

// Include the class definitions for Core, Grad, PassFailStudent, and AuditStudent

// Function to generate the grade report for a collection of students
void generateGradeReport(const std::vector<Core*>& students) {
    std::cout << "Grade Report" << std::endl;
    std::cout << "---------------------" << std::endl;

    for (const Core* student : students) {
        std::cout << "Name: " << student->name() << std::endl;
        std::cout << "Type: " << typeid(*student).name() << std::endl;

        std::cout << "Grade: " << std::fixed << std::setprecision(2) << student->grade() << std::endl;

        // Check if the student met the relevant requirements (applicable for Core and Grad)
        if (typeid(*student) == typeid(Core) || typeid(*student) == typeid(Grad)) {
            bool requirementsMet = student->metRequirements();
            std::cout << "Requirements Met: " << (requirementsMet ? "Yes" : "No") << std::endl;
        }

        std::cout << "---------------------" << std::endl;
    }
}

int main() {
    // Create a collection of student objects
    std::vector<Core*> students;

    // Add different types of students to the collection
    students.push_back(new Core());
    students.push_back(new Grad());
    students.push_back(new PassFailStudent());
    students.push_back(new AuditStudent());

    // Generate the grade report for all the students
    generateGradeReport(students);

    // Cleanup: Delete dynamically allocated student objects
    for (Core* student : students) {
        delete student;
    }

    return 0;
}
