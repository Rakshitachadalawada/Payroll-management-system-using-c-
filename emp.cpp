#include <iostream>
#include <string>
using namespace std;

// Base class for person
class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    string getName() const { return name; }
    void setName(string n) { name = n; }
};

// Derived class for employee
class Employee : public Person {
private:
    int empID;
    long long package;
    string role;

public:
    Employee(int id, string n, long long p, string r)
        : Person(n), empID(id), package(p), role(r) {}

    int getEmpID() const { return empID; }
    long long getPackage() const { return package; }
    string getRole() const { return role; }

    void setPackage(long long p) { package = p; }
    void setRole(string r) { role = r; }

    void displayEmployeeDetails() const {
        cout << "ID: " << empID << ", Name: " << name << ", Package: " << package << ", Role: " << role << endl;
    }

    void generateSalarySlip() const {
        double hra, da, tax, gross, net;
        cout << "\n---------------------------------------------------------";
        cout << "\n                    PAY SLIP                                \n";
        cout << "-----------------------------------------------------------";
        cout << "\nEMPLOYEE NAME: " << name;
        cout << "\t\t\t\tDATE: 14/12/22";
        cout << "\nROLE: " << role;
        cout << "\nPACKAGE: " << package;
        cout << "\n------------------------------------------------------";
        if (package < 100000) {
            hra = (double)(15 * package) / 100;
            da = (double)(10 * package) / 100;
            tax = (double)(22 * package) / 100;
        } else {
            hra = (double)(20 * package) / 100;
            da = (double)(15 * package) / 100;
            tax = (double)(28 * package) / 100;
        }
        gross = (double)(package + hra + da);
        cout << "\n\n\nGROSS SALARY: " << gross << "\t\t*HRA=" << hra;
        cout << "\n                                        \t\t*DA=" << da;
        cout << "\n                                        \t\t*TAX=" << tax;
        cout << "\n***********************************************";
        cout << "\nNET SALARY=" << gross - tax << endl;
    }
};

// Payroll system class
class PayrollSystem {
private:
    Employee* employee;

public:
    PayrollSystem() : employee(nullptr) {}

    void addEmployee(int id, string name, long long package, string role) {
        if (employee == nullptr) {
            employee = new Employee(id, name, package, role);
        } else {
            cout << "Employee already exists. Modify the existing record or delete it first." << endl;
        }
    }

    void modifyEmployeeRecord() {
        if (employee != nullptr) {
            string newName, newRole;
            long long newPackage;
            cout << "Enter new name: ";
            cin >> newName;
            cout << "Enter new package: ";
            cin >> newPackage;
            cout << "Enter new role: ";
            cin >> newRole;

            employee->setName(newName);
            employee->setPackage(newPackage);
            employee->setRole(newRole);
            cout << "Record modified successfully!" << endl;
        } else {
            cout << "Employee record does not exist. Add a new employee first." << endl;
        }
    }

    void deleteEmployeeRecord() {
        if (employee != nullptr) {
            delete employee;
            employee = nullptr;
            cout << "Record deleted successfully!" << endl;
        } else {
            cout << "Employee record does not exist." << endl;
        }
    }

    void displayEmployeeDetails() const {
        if (employee != nullptr) {
            employee->displayEmployeeDetails();
        } else {
            cout << "Employee record does not exist." << endl;
        }
    }

    void generateSalarySlip() const {
        if (employee != nullptr) {
            employee->generateSalarySlip();
        } else {
            cout << "Employee record does not exist." << endl;
        }
    }

    ~PayrollSystem() {
        if (employee != nullptr) {
            delete employee;
        }
    }
};

int main() {
    PayrollSystem payroll;
    int choice;

    while (true) {
        cout << "\n\t\t\t.........WELCOME TO EMPLOYEE PAYROLL SLIP..............";
        cout << "\n";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   1:   To Add New Employee Details";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   2:   To Modify Employee Record";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   3:   To Delete Employee Record";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   4:   To Print Employee Salary slip/pay slip";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   5:   To Display Employee Record";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   6:   To EXIT";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\n\t\t\t   Please Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, role;
                long long package;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter employee package: ";
                cin >> package;
                cout << "Enter role: ";
                cin >> role;
                payroll.addEmployee(id, name, package, role);
                break;
            }
            case 2:
                payroll.modifyEmployeeRecord();
                break;
            case 3:
                payroll.deleteEmployeeRecord();
                break;
            case 4:
                payroll.generateSalarySlip();
                break;
            case 5:
                payroll.displayEmployeeDetails();
                break;
            case 6:
                return 0;
            default:
                cout << "Please enter a valid choice." << endl;
        }
    }

    return 0;
}
