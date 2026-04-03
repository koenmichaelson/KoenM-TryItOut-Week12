#include <iostream>
#include <vector>
using namespace std;

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
private:
    int id;

public:
    IDCard(int ID) {
        id = ID;
    }

    int getID() {
        return id;
    }

    void setID(int newID) {
        id = newID;
    }
};

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
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

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
public:
    string title;

    Textbook(string t) {
        title = t;
    }
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
public:
    static int calculateAverage(int a, int b, int c) {

        return (a + b + c) / 3;

    }
};

/*
========================================
Student Class
========================================
*/
class Student : public Person {
private:
    IDCard idCard; 

public:
    Student(string n, int id): Person(n), idCard(id) {
    }

    void study(const Textbook& book) {

        cout << name << " studied the book: " << book.title << endl;

    }

    void printAverage(int a, int b, int c) {

        int avg = GradeCalculator::calculateAverage(a, b, c);
        cout << name << "'s average: " << avg << endl;
    }
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
private:
    vector<Student*> students;

public:
    void addStudent(Student* s) {
        students.push_back(s);
    }

    void listStudents() {
        for (const auto& p : students) {

            cout << p->getName() << endl;

        }
    }
};

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
    Student s1("James", 101);
    Student s2("Anna", 102);
    Student s3("Billy Bob", 103);

    // TODO: Create Course and add students
    Course course;
    course.addStudent(&s1);
    course.addStudent(&s2);
    course.addStudent(&s3);

    cout << "Course Students:" << endl;
    course.listStudents();

    // TODO: Create Textbook and call study()
    Textbook book("C++ Programming 101");
    s1.study(book);
    s2.study(book);
    s3.study(book);

    // TODO: Call printAverage()
    s1.printAverage(90, 85, 88);
    s2.printAverage(70, 75, 80);
    s3.printAverage(99, 89, 92);

    return 0;
}