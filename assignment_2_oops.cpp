//Assignment 2(oops)
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX=100;
//PERSON CLASS AND CONSTUCTORS
class Person{
    string per_name;
    int age;
    string id;
    string contact_info;
    public:
    Person();
    Person(string per_name,int age,string id,string contact_info);
    // Getters
    string getName() { return per_name; }  
    int getAge() { return age; }
    string getID() { return id; }
    string getContactInfo() { return contact_info; }

    // Setters with validation
    void setName(string name) { if (!name.empty()) per_name = name; }
    void setAge(int a) { if (a > 0 && a < 120) age = a; }
    void setID(string i) { if (!i.empty()) id = i; }
    void setContactInfo(int c) { if (c > 0) contact_info = c; }

    virtual void displayDetails(){
        cout<<"Name : "<<per_name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Contact Info. : "<<contact_info<<endl;

    }
    virtual float calculatePayment() { return 0.0; }
};
Person::Person() : per_name(" "), age(0), id(" "), contact_info("0") {}

Person::Person(string per_name, int age, string id, string contact_info) : per_name(per_name), age(age), id(id), contact_info(contact_info) {}
// Person::Person(){
//     this->per_name=" ";
//     this->age=0;
//     this->id=" " ;
//     this->contact_info=0;
// }
// Person::Person(string per_name,int age,string id,int contact_info){
//     this->per_name=per_name;
//     this->age=age;
//     this->id=id;
//     this->contact_info=contact_info;
// }
//STUDENT CLASS AND CONSTRUCTORS AND GETTER
class Student : public Person{
    string enroll_date;
    string program;
    float gpa;
    public:
    static int stu_count;
    Student();
    Student(string per_name, int age, string id, string contact_info,string enroll_date, string program, float gpa);
    string getEnrollDate() { return enroll_date; }
    string getProgram() { return program; }
    float getGPA() { return gpa; }

    void setEnrollDate(string ed) { if (!ed.empty()) enroll_date = ed; }
    void setProgram(string p) { if (!p.empty()) program = p; }
    void setGPA(float g) { if (g >= 0.0 && g <= 4.0) gpa = g; }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Enrollment Date : " << enroll_date << endl;
        cout << "Program : " << program << endl;
        cout << "GPA : " << gpa << endl;
    }
    float calculatePayment() override { return 10000.0f; }

};
int Student::stu_count=0;

Student::Student() : Person(), enroll_date(""), program(""), gpa(0.0f) {}

Student::Student(string per_name, int age, string id, string contact_info, string enroll_date, string program, float gpa): Person(per_name, age, id, contact_info), enroll_date(enroll_date), program(program), gpa(gpa) {}

// Student::Student() : Person() {
//     this->enroll_date = "";
//     this->program = "";
//     this->gpa = 0.0;
// }
// Student::Student(string per_name, int age, string id, int contact_info,string enroll_date, string program, float gpa): Person(per_name, age, id, contact_info) {
// this->enroll_date = enroll_date;
// this->program = program;
// this->gpa = gpa;
// }
//PROFESSOR CLASS AND CONSTRUCTORS AND GETTER
class Professor : public Person{
    string dept_name;
    string specialization;
    string hire_date;
    public:
    Professor();
    Professor(string per_name, int age, string id, string contact_info,string dept_name,string specialization,string hire_date);
    string getDeptName() { return dept_name; }
    string getSpecialization() { return specialization; }
    string getHireDate() { return hire_date; }

    void setDeptName(string d) { if (!d.empty()) dept_name = d; }
    void setSpecialization(string s) { if (!s.empty()) specialization = s; }
    void setHireDate(string h) { if (!h.empty()) hire_date = h; }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department : " << dept_name << endl;
        cout << "Specialization : " << specialization << endl;
        cout << "Hire Date : " << hire_date << endl;
    }
    float calculatePayment() override { return 50000.0f; }
};
Professor::Professor() : Person(), dept_name(""), specialization(""), hire_date("") {}

Professor::Professor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date) : Person(per_name, age, id, contact_info), dept_name(dept_name), specialization(specialization), hire_date(hire_date) {}

// Professor::Professor(){
//     this->dept_name = " ";
//     this->specialization=" ";
//     this->hire_date=" ";
// }
// Professor::Professor(string per_name, int age, string id, int contact_info,string dept_name,string specialization,string hire_date):Person(per_name,age,id,contact_info){
//     this->dept_name=dept_name;
//     this->hire_date=hire_date;
//     this->specialization=specialization;
// }
//COURSE CLASS AND CONSTRUCTORS AND GETTER
class Course{
    string code;
    string title;
    int credits;
    string description;
    public:
    // Course(string c, string t, int cr, string desc) {
    //     code = c;
    //     title = t;
    //     credits = cr;
    //     description = desc;
    // }
    Course() : code(""), title(""), credits(0), description("") {}

    Course(string c, string t, int cr, string desc)
    : code(c), title(t), credits(cr), description(desc) {}

    void course_details(){
        cout<<"Course code : "<<code<<endl;
        cout<<"Course name : "<<title<<endl;
        cout<<"Credits : "<<credits<<endl;
        cout<<"Description : "<<description<<endl;
    }


};
//DEPARTMENT CLASS AND CONSTRUCTORS AND GETTER
class Department{
    string dept_name;
    string location;
    string budget;
    public:
    // Department(string d,string l,string b){
    //     dept_name=d;
    //     location=l;
    //     budget=b;
    // }
    Department() : dept_name(""), location(""), budget("") {}

    Department(string d, string l, string b)
    : dept_name(d), location(l), budget(b) {}
    void department_details(){
        cout<<"Department Name : "<<dept_name<<endl;
        cout<<"Location : "<<location<<endl;
        cout<<"Budget : "<<budget<<endl;
    }
};

class GradeBook : public Student {
private:
    vector<string> studentIDs;
    vector<float> grades;

public:
    void addGrade(Student& s, float grade) {
        if (grade >= 0.0 && grade <= 100.0) {
            studentIDs.push_back(s.getID());
            grades.push_back(grade);
        }
    }

    float calculateAverageGrade() {
        if (grades.empty()) return 0.0f;
        float total = 0.0f;
        for (float g : grades) total += g;
        return total / grades.size();
    }

    float getHighestGrade() {
        if (grades.empty()) return 0.0f;
        return *max_element(grades.begin(), grades.end());
    }

    void getFailingStudents() {
        cout << "Failing Students (Grade < 40):" << endl;
        for (size_t i = 0; i < grades.size(); ++i) {
            if (grades[i] < 40.0f)
                cout << "Student ID: " << studentIDs[i] << ", Grade: " << grades[i] << endl;
        }
    }

    void displayDetails() override {
        cout << "GradeBook Details:" << endl;
        cout << "Total Students: " << studentIDs.size() << endl;
        cout << "Average Grade: " << calculateAverageGrade() << endl;
        cout << "Highest Grade: " << getHighestGrade() << endl;
        getFailingStudents();
    }
};

// ENROLLMENT MANAGER CLASS 
class EnrollmentManager : public Student {
    private:
        vector<string> studentIDs;
        vector<string> courseCodes;
    
    public:
        void enrollPerson(Student& s, const string& courseCode) {
            studentIDs.push_back(s.getID());
            courseCodes.push_back(courseCode);
        }
    
        void dropPerson(Student& s, const string& courseCode) {
            for (size_t i = 0; i < studentIDs.size(); ++i) {
                if (studentIDs[i] == s.getID() && courseCodes[i] == courseCode) {
                    studentIDs.erase(studentIDs.begin() + i);
                    courseCodes.erase(courseCodes.begin() + i);
                    break;
                }
            }
        }
    
        int getEnrollmentCount(const string& courseCode) {
            int count = 0;
            for (const string& c : courseCodes) {
                if (c == courseCode) count++;
            }
            return count;
        }
    
        void displayDetails() override {
            cout << "Enrollment Details:" << endl;
            for (size_t i = 0; i < studentIDs.size(); ++i) {
                cout << "Student ID: " << studentIDs[i] << ", Course: " << courseCodes[i] << endl;
            }
            cout << "Total Enrollments: " << studentIDs.size() << endl;
        }
    };
    

// MAIN FUNCTION
int main() {
    Person* Ptr;
    
    Student s1("Jonny", 20, "S001", "1236187387", "2025-08-01", "CSE", 3.5);
    Student s2("Mary", 22, "S002", "4236182789", "2025-08-01", "ECE", 3.9);
    Ptr = &s1;
    // Without virtual, this would call Base::display()
    // With virtual, it calls Derived::display()
    Ptr->displayDetails(); // Display method of Derived class.

    // Setting Values
    Professor prof1("Dr. Nistha", 45, "PR001", "9998887777", "CSE", "AI", "2015-06-01");
    Professor prof2("Prof. Ishita", 50, "PR002", "9667778888", "ECE", "Embedded", "2010-03-15");

    Course c1("CS101", "Fundamentals of C++ programming", 3, "Basics of C++");
    Course c2("EC201", "Hacking and tricks", 4, "Intro to ethical hacking and types");

    Department d1("CSE" , "Block A", "5 Cr");
    Department d2("ECE" , "Block B", "3 Cr");

    // Student s1("Jonny", 20, "S001", "1236187387", "2025-08-01", "CSE", 3.5);
    // Student s2("Mary", 22, "S002", "4236182789", "2025-08-01", "ECE", 3.9);

    GradeBook gb;
    gb.addGrade(s1, 78);
    gb.addGrade(s2, 65);

    EnrollmentManager em;
    em.enrollPerson(s1, "CSE101");
    em.enrollPerson(s2, "CSE101");

    // Displaying Details
    cout << "Student Details:" << endl;
    s1.displayDetails();
    cout << endl;
    s2.displayDetails();
    cout << endl;

    cout << "GradeBook Details:" << endl;
    gb.displayDetails();
    cout << endl;

    cout << "Enrollment Manager Details:" << endl;
    em.displayDetails();
    cout << endl;

    cout << "Professor Details:" << endl;
    prof1.displayDetails(); 
    cout << endl;
    prof2.displayDetails();
    cout << endl;

    cout << "Course Details:" << endl;
    c1.course_details();
    cout << endl;
    c2.course_details();
    cout << endl;

    cout << "Department Details:" << endl;
    d1.department_details();
    cout << endl;
    d2.department_details();
    cout << endl;


    return 0;
}




