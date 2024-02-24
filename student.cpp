#include "student.h"

double Student::compute_class_score() const{
    return (.3 * midterm) + (.3 * final) + (.4 * hw_avg());
}

double Student::hw_avg() const {
    if (hw_grades.size()==0) throw string("Error: Student has no homework grades.");
    double hw_total=0;
    for (auto hw : hw_grades) hw_total += hw;
    size_t num_homeworks = hw_grades.size();
    return hw_total / num_homeworks;
}

void Student::retrieve_student_data() {
    cout << "Enter student name: ";
    getline(std::cin, name);
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter final exam score: ";
    cin >> final;
    cout << "Enter midterm score: ";
    cin >> midterm;
    cout << "Enter hw grades, hit enter after each. Submit \"-1\" when complete:" << endl;
    int hw_grade;
    while (true) {
        cin >> hw_grade;
        if (hw_grade==-1) break;
        hw_grades.push_back(hw_grade);
    }
}

void Student::print_student_data() const {
    cout << "Student name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Midterm: " << midterm << endl;
    cout << "Final: " << final << endl;
    cout << "Homework grades: ";
    for (auto hw_grade : hw_grades) cout << hw_grade << " ";
    cout << endl;
    try {
        cout << "Homework average: " << hw_avg();
        cout << endl;
        print_class_score();
        cout << endl;
    } catch (string no_hw_error) {
        cout << "Caught " << no_hw_error << endl;
    }
}

void Student::print_class_score() const {
    cout << "Final Class Score: " << compute_class_score();
}