#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    int code;
    string designation;
    int experience;
    int age;
};

const int maxEmployees = 10;
Employee employees[maxEmployees];
int employeeCount = 0;

void addEmployee()
{
    if (employeeCount < maxEmployees)
    {
        Employee emp;
        cout << "Enter Employee Name: ";
        cin >> emp.name;
        cout << "Enter Employee Code: ";
        cin >> emp.code;
        cout << "Enter Designation: ";
        cin >> emp.designation;
        cout << "Enter Years of Experience: ";
        cin >> emp.experience;
        cout << "Enter Age: ";
        cin >> emp.age;
        employees[employeeCount] = emp;
        employeeCount++;
        cout << "Employee added successfully." << endl;
    }
    else
    {
        cout << "Employee database is full. Cannot add more employees." << endl;
    }
}

void modifyEmployee()
{
    int code;
    cout << "Enter Employee Code to modify: ";
    cin >> code;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].code == code)
        {
            cout << "Enter New Employee Name: ";
            cin >> employees[i].name;
            cout << "Enter New Designation: ";
            cin >> employees[i].designation;
            cout << "Enter New Years of Experience: ";
            cin >> employees[i].experience;
            cout << "Enter New Age: ";
            cin >> employees[i].age;
            cout << "Employee details modified successfully." << endl;
            return;
        }
    }
    cout << "Employee with code " << code << " not found." << endl;
}

void displayEmployees()
{
    cout << "Employee Information:" << endl;
    for (int i = 0; i < employeeCount; i++)
    {
        cout << "Employee Code: " << employees[i].code << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Designation: " << employees[i].designation << endl;
        cout << "Years of Experience: " << employees[i].experience << " years" << endl;
        cout << "Age: " << employees[i].age << " years" << endl;
        cout << endl;
    }
}

void searchEmployeeByName(string query)
{
    bool found = false;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].name.find(query) != string::npos)
        {
            cout << "Employee Code: " << employees[i].code << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Designation: " << employees[i].designation << endl;
            cout << "Years of Experience: " << employees[i].experience << " years" << endl;
            cout << "Age: " << employees[i].age << " years" << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No employees found with a name containing '" << query << "'." << endl;
    }
}

int main()
{
    int choice;
    string searchQuery;

    while (true)
    {
        cout << "\nEmployee Information System Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Modify Employee Details" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Search Employee by Name" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            modifyEmployee();
            break;
        case 3:
            displayEmployees();
            break;
        case 4:
            cout << "Enter a part of the employee's name to search: ";
            cin >> searchQuery;
            searchEmployeeByName(searchQuery);
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
