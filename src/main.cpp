#include <iostream>
#include <vector>
using namespace std;

/*
========================================
STEP 1: INHERITANCE (is-a)
----------------------------------------
A Student IS-A Person.

TODO:
- Create a base class called Person
- Give it a protected string "name"
- Add a constructor to initialize name
- Add a getName() function

Then:
- Create a Student class that inherits from Person
========================================
*/

class Person {
    // TODO
};

class Student : public Person {
    // TODO
};

/*
========================================
STEP 2: COMPOSITION (strong has-a)
----------------------------------------
A Student HAS-A IDCard.

- The IDCard should ONLY exist inside Student
- If Student is destroyed, IDCard is destroyed

TODO:
- Create an IDCard class with an int id
- Add a constructor and getter
- Add an IDCard as a MEMBER VARIABLE inside Student
========================================
*/

class IDCard {
    // TODO
};

// Add IDCard to Student


/*
========================================
STEP 3: ASSOCIATION (uses-a)
----------------------------------------
A Student USES a Textbook.

- The Student does NOT own the Textbook
- It is passed into a function temporarily

TODO:
- Create a Textbook class with a title
- Add a function in Student:
      void study(const Textbook& book);
========================================
*/

class Textbook {
    // TODO
};


/*
========================================
STEP 4: AGGREGATION (weak has-a)
----------------------------------------
A Course HAS Students.

- The Course does NOT own Students
- Students exist outside the Course

TODO:
- Create a Course class
- Store a vector of Student pointers
- Add:
      void addStudent(Student* s);
      void listStudents();
========================================
*/

class Course {
    // TODO
};


/*
========================================
STEP 5: DEPENDENCY (temporary use)
----------------------------------------
A Student USES GradeCalculator temporarily.

- NOT stored as a variable
- Only used inside a function

TODO:
- Create a GradeCalculator class
- Add a static function:
      calculateAverage(int a, int b, int c)

- Add a function in Student:
      void printAverage(...)
========================================
*/

class GradeCalculator {
    // TODO
};


// Add printAverage to Student


/*
========================================
STEP 6: TEST EVERYTHING
----------------------------------------
In main():

- Create 2 Students
- Create a Course and add students
- Create a Textbook and call study()
- Call printAverage()
- Print student info

Think:
Which objects OWN others?
Which just USE others?
========================================
*/

int main() {
    // TODO: Create Students

    // TODO: Create Course and add students

    // TODO: Create Textbook and call study()

    // TODO: Call printAverage()

    return 0;
}