#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "student.h"


TEST_CASE("testing class score") {

    SUBCASE("no hw case") {
        vector<int> no_student_hw_grades = {};
        Student no_student(800800, "I DroppedOut", 100, 100, no_student_hw_grades);

        DOCTEST_REQUIRE_THROWS(no_student.compute_class_score());
    };

    SUBCASE("the failure") {
        vector<int> zero_student_hw_grades = {0, 0, 0};
        Student zero_student(101011, "The DogAteIt", 0, 0, zero_student_hw_grades);

        try {
            CHECK_EQ(zero_student.compute_class_score(), 0);
        } catch(string empty_exception) {
            CHECK_EQ(empty_exception, "Error: Student has no homework grades.");
        }

    };

    SUBCASE("the goat") {
        vector<int> student1_hw_grades = {100, 100, 100};
        Student student1(999999, "The Goat", 100, 100, student1_hw_grades);

        CHECK_EQ(student1.compute_class_score(), 100);
    };

    SUBCASE("Joe Schmoe") {
        vector<int> student2_hw_grades = {80, 90, 100};
        Student student2(432902, "Joe Schmoe", 90, 90, student2_hw_grades);

        CHECK_EQ(student2.compute_class_score(), 90);
    };

    SUBCASE("Joe Schmoe 2") {
        vector<int> student3_hw_grades = {100, 95};
        Student student3(653492, "Joe Schmoe 2", 100, 80, student3_hw_grades);

        CHECK_EQ(student3.hw_avg(), 97.5);
        CHECK_EQ(student3.compute_class_score(), 93);
    };


};