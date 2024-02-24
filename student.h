#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

#include <vector>
#include <string>

using namespace std;

struct Student {
    int id, final, midterm;
    string name;
    vector<int> hw_grades;

    Student() {}; // empty constructor ?
    Student(int id, string name, int midterm, int final, vector<int> &hw_grades) :
        id(id), name(name), midterm(midterm), final(final), hw_grades(hw_grades) {
    }
    int get_id() {return id;};
    string get_name() {return name;};
    int get_final_exam() {return final;};
    int get_midterm() {return midterm;};
    vector<int> &get_hw_grades() {return hw_grades;};

    double compute_class_score() const;
    double hw_avg() const;
    void print_student_data() const;
    void print_class_score() const;
    void retrieve_student_data();
};

#endif