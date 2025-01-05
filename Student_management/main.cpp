#include <bits/stdc++.h>
using namespace std;


using namespace std;

// Static admin credentials
const string ADMIN_ID = "1";
const string ADMIN_PASSWORD = "1234";

void adminMenu();

// Structure to hold student details
struct Student
{
    string id;
    string name;
    string email;
    string phone;
    string dob;
    string address;
    string hashedPassword;
    string section;
    double cgpa;
    int totalMarks;
    string behavior;
};

vector<Student> students;
unordered_map<string, string> roles;
unordered_map<string, string> names;

// Utility function to hash a password
// string hashPassword(const string &password)
// {
//     unsigned char hash[SHA256_DIGEST_LENGTH];
//     SHA256((unsigned char *)password.c_str(), password.size(), hash);
//     stringstream ss;
//     for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//     {
//         ss << hex << setw(2) << setfill('0') << (int)hash[i];
//     }
//     return ss.str();
// }

void newLine()
{
    cout <<"\n";
    cout <<"\n";
}

void loadStudents()
{
    ifstream file("students.txt");
    if (!file.is_open())
    {
        cout << "\t\t\tFailed to open students.txt file.\n";
        return;
    }

    string line;
    while (getline(file, line))
    {
        Student s;
        stringstream ss(line);
        string totalMarksStr;

        getline(ss, s.id, ',');
        getline(ss, s.name, ',');
        getline(ss, s.email, ',');
        getline(ss, s.phone, ',');
        getline(ss, s.dob, ',');
        getline(ss, s.address, ',');
        getline(ss, s.hashedPassword, ',');
        getline(ss, s.section, ',');
        ss >> s.cgpa;
        ss.ignore(); // To ignore the comma after CGPA
        getline(ss, totalMarksStr, ',');
        s.totalMarks = stoi(totalMarksStr);
        getline(ss, s.behavior);

        students.push_back(s);
    }

    file.close();
}

void saveStudents()
{
    ofstream file("students.txt");
    if (!file.is_open())
    {
        cout << "\t\t\tFailed to open students.txt file for writing.\n";
        return;
    }

    for (const auto &s : students)
    {
        file << s.id << "," << s.name << "," << s.email << "," << s.phone << ","
             << s.dob << "," << s.address << "," << s.hashedPassword << ","
             << s.section << "," << fixed << setprecision(2) << s.cgpa << ","
             << s.totalMarks << "," << s.behavior << "\n";
    }

    file.close();
}

// Function to add a new student
void addStudent()
{
    system("clear");

    Student s;
    cout << "\n\n\t\t\tEnter Student ID: ";
    cin >> s.id;
    cout << "\t\t\tEnter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "\t\t\tEnter Email: ";
    getline(cin, s.email);
    cout << "\t\t\tEnter Phone Number: ";
    getline(cin, s.phone);
    cout << "\t\t\tEnter Date of Birth: ";
    getline(cin, s.dob);
    cout << "\t\t\tEnter Address: ";
    getline(cin, s.address);
    string password;
    cout << "\t\t\tEnter Password: ";
    getline(cin, password);
    s.hashedPassword = password;
    // s.hashedPassword = hashPassword(password);
    cout << "\t\t\tEnter Section: ";
    getline(cin, s.section);
    cout << "\t\t\tEnter CGPA: ";
    cin >> s.cgpa;
    cout << "\t\t\tEnter Total Marks: ";
    cin >> s.totalMarks;
    cin.ignore();
    cout << "\t\t\tEnter Behavior: ";
    getline(cin, s.behavior);

    students.push_back(s);
    saveStudents();
    cout << "\t\t\tStudent added successfully!\n";

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Add More\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        addStudent();
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}

// Function to update student details
void updateStudentDetails(const string &id)
{
    system("clear");

    bool isFound = false ;
    for (auto &s : students)
    {
        if (s.id == id)
        {
            // Display current details before updating
            cout << "\n\n\t\t\tCurrent Details for Student ID: " << s.id << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t1. Name          : " << s.name << endl;
            cout << "\t\t\t2. Email         : " << s.email << endl;
            cout << "\t\t\t3. Phone         : " << s.phone << endl;
            cout << "\t\t\t4. Date of Birth : " << s.dob << endl;
            cout << "\t\t\t5. Address       : " << s.address << endl;
            cout << "\t\t\t6. Section       : " << s.section << endl;
            cout << "\t\t\t7. CGPA          : " << fixed << setprecision(2) << s.cgpa << endl;
            cout << "\t\t\t8. Total Marks   : " << s.totalMarks << endl;
            cout << "\t\t\t9. Behavior      : " << s.behavior << endl;
            cout << "\t\t\t------------------------------------------" << endl;

            // Menu for selecting fields to update
            while (true)
            {
                cout << "\n\t\t\tWhich field would you like to update?" << endl;
                cout << "\t\t\tEnter the corresponding number (or 0 to finish): ";
                int choice;
                cin >> choice;
                cin.ignore(); // Clear the input buffer

                if (choice == 0)
                {
                    break; // Exit the update loop
                }

                string input;
                switch (choice)
                {
                case 1:
                    cout << "\t\t\tEnter New Name: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.name = input;
                    break;
                case 2:
                    cout << "\t\t\tEnter New Email: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.email = input;
                    break;
                case 3:
                    cout << "\t\t\tEnter New Phone Number: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.phone = input;
                    break;
                case 4:
                    cout << "\t\t\tEnter New Date of Birth: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.dob = input;
                    break;
                case 5:
                    cout << "\t\t\tEnter New Address: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.address = input;
                    break;
                case 6:
                    cout << "\t\t\tEnter New Section: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.section = input;
                    break;
                case 7:
                    cout << "\t\t\tEnter New CGPA: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.cgpa = stod(input);
                    break;
                case 8:
                    cout << "\t\t\tEnter New Total Marks: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.totalMarks = stoi(input);
                    break;
                case 9:
                    cout << "\t\t\tEnter New Behavior: ";
                    getline(cin, input);
                    if (!input.empty())
                        s.behavior = input;
                    break;
                default:
                    cout << "\t\t\tInvalid choice! Please try again." << endl;
                    break;
                }

                saveStudents();
                updateStudentDetails(id);
                break; // Exit the update loop
            }
            isFound = true ;
            break ;
        }
    }

    if(!isFound)
    {
        cout << "\t\t\tStudent ID not found!\n";
    }
    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Try Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        updateStudentDetails(id);
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}

// Function to delete a student
void deleteStudent(const string &id)
{
    system("clear");

    auto it = remove_if(students.begin(), students.end(), [&id](const Student &s)
                        { return s.id == id; });
    if (it != students.end())
    {
        students.erase(it, students.end());
        saveStudents();
        cout << "\n\n\t\t\tStudent deleted successfully!\n";
    }
    else
    {
        cout << "\n\n\t\t\tStudent ID not found!\n";
    }

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Delete Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        string stId ;
        cout << "\t\t\tEnter Student id :";
        cin >> stId;
        deleteStudent(stId);
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}

// Function to search for a student by ID
void searchStudent(const string &id)
{
    system("clear");

    bool isFound = false ;
    for (const auto &s : students)
    {
        if (s.id == id)
        {
            cout << "\n\t\t\tStudent Details:\n";
            cout << "\t\t\tID           : " << s.id << endl;
            cout << "\t\t\tName         : " << s.name << endl;
            cout << "\t\t\tEmail        : " << s.email << endl;
            cout << "\t\t\tPhone        : " << s.phone << endl;
            cout << "\t\t\tDOB          : " << s.dob << endl;
            cout << "\t\t\tAddress      : " << s.address << endl;
            cout << "\t\t\tSection      : " << s.section << endl;
            cout << "\t\t\tCGPA         : " << s.cgpa << endl;
            cout << "\t\t\tTotal Marks  : " << s.totalMarks << endl;
            cout << "\t\t\tBehavior     : " << s.behavior << endl;
            isFound = true ;
            break;
        }
    }

    if(!isFound)
    {
        cout << "\n\t\t\tStudent ID not found!\n";
    }

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Search Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        string stId ;
        cout << "\t\t\tEnter Student id :";
        cin >> stId;
        searchStudent(stId);
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}

// Function to search for a student by section
void searchStudentBySection(const string &section)
{
    system("clear");

    bool found = false;
    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";
    cout << "| " << setw(12) << left << "Student Id"
         << "| " << setw(20) << left << "Name"
         << "| " << setw(20) << left << "Email"
         << "| " << setw(20) << left << "Phone"
         << "| " << setw(15) << left << "DOB"
         << "| " << setw(20) << left << "Address"
         << "| " << setw(15) << left << "Section"
         << "| " << setw(10) << left << "CGPA"
         << "| " << setw(15) << left << "Total Marks"
         << "| " << setw(15) << left << "Behavior" << " |\n";
    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";

    for (const auto &s : students)
    {
        if (s.section == section)
        {
            cout << "| " << setw(12) << left << s.id
                 << "| " << setw(20) << left << s.name
                 << "| " << setw(20) << left << s.email
                 << "| " << setw(20) << left << s.phone
                 << "| " << setw(15) << left << s.dob
                 << "| " << setw(20) << left << s.address
                 << "| " << setw(15) << left << s.section
                 << "| " << fixed << setprecision(2) << setw(10) << s.cgpa
                 << "| " << setw(15) << s.totalMarks
                 << "| " << setw(15) << s.behavior << " |\n";

            found = true;
        }
    }
    if (!found)
    {
        cout << "\n\t\t\tNo students found in this section.\n";
    }

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Search Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        string stSection ;
        cout << "\t\t\tEnter Student section :";
        cin >> stSection;
        searchStudentBySection(stSection);
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}

void viewAllStudents()
{
    system("clear");

    if (students.empty())
    {
        cout << "\n\t\t\tNo students to display.\n";
        return;
    }

    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";
    cout << "| " << setw(12) << left << "Student Id"
         << "| " << setw(20) << left << "Name"
         << "| " << setw(20) << left << "Email"
         << "| " << setw(20) << left << "Phone"
         << "| " << setw(15) << left << "DOB"
         << "| " << setw(20) << left << "Address"
         << "| " << setw(20) << left << "Password"
         << "| " << setw(15) << left << "Section"
         << "| " << setw(10) << left << "CGPA"
         << "| " << setw(15) << left << "Total Marks"
         << "| " << setw(15) << left << "Behavior" << " |\n";
    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";

    for (const auto &s : students)
    {
        cout << "| " << setw(12) << left << s.id
             << "| " << setw(20) << left << s.name
             << "| " << setw(20) << left << s.email
             << "| " << setw(20) << left << s.phone
             << "| " << setw(15) << left << s.dob
             << "| " << setw(20) << left << s.address
             << "| " << setw(20) << left << s.hashedPassword.substr(0, 10) + ".."
             << "| " << setw(15) << left << s.section
             << "| " << fixed << setprecision(2) << setw(10) << s.cgpa
             << "| " << setw(15) << s.totalMarks
             << "| " << setw(15) << s.behavior << " |\n";
    }

    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. See Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        viewAllStudents();
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }
}


void viewAllStudents(string stateSort)
{
    system("clear");

    if (students.empty())
    {
        cout << "\n\t\t\tNo students to display.\n";
        return;
    }

    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";
    cout << "| " << setw(12) << left << "Student Id"
         << "| " << setw(20) << left << "Name"
         << "| " << setw(20) << left << "Email"
         << "| " << setw(20) << left << "Phone"
         << "| " << setw(15) << left << "DOB"
         << "| " << setw(20) << left << "Address"
         << "| " << setw(20) << left << "Password"
         << "| " << setw(15) << left << "Section"
         << "| " << setw(10) << left << "CGPA"
         << "| " << setw(15) << left << "Total Marks"
         << "| " << setw(15) << left << "Behavior" << " |\n";
    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";

    for (const auto &s : students)
    {
        cout << "| " << setw(12) << left << s.id
             << "| " << setw(20) << left << s.name
             << "| " << setw(20) << left << s.email
             << "| " << setw(20) << left << s.phone
             << "| " << setw(15) << left << s.dob
             << "| " << setw(20) << left << s.address
             << "| " << setw(20) << left << s.hashedPassword.substr(0, 10) + ".."
             << "| " << setw(15) << left << s.section
             << "| " << fixed << setprecision(2) << setw(10) << s.cgpa
             << "| " << setw(15) << s.totalMarks
             << "| " << setw(15) << s.behavior << " |\n";
    }

    cout << "+------------+------------------------+----------------------+------------+------------+------------+----------------------------+------------+--------+--------------+------------------------+\n";

}

// Function to sort students by name, CGPA, or total marks
void sortStudents()
{
    system("clear");

    int choice;
    newLine();
    cout << "\n\t\t\tSort by:\n";
    cout << "\t\t\t1. Id\n\t\t\t2. Name\n\t\t\t3. Cgpa\n\t\t\t4. Total marks\n\t\t\tEnter your choice: ";
    cin >> choice;
    if(choice == 1)
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.id > b.id; });
    }
    else if (choice == 2)
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.name < b.name; });
    }
    else if (choice == 3)
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.cgpa > b.cgpa; });
    }
    else if (choice == 4)
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.totalMarks > b.totalMarks; });
    }
    else
    {
        newLine();
        cout << "\t\t\tInvalid choice!\n";
        return;
    }
    viewAllStudents("sortStudents");
    cout << "\n\t\t\tStudents sorted successfully!\n";

    int ch;
    cout << "\n\t\t\tGo to :\n";
    cout << "\t\t\t1. Main menu\n\t\t\t2. Sort Again\n\t\t\t0. Exit\n\t\t\tEnter your choice:";
    cin >> ch;
    if (ch == 2)
    {
        sortStudents();
    }
    else if (ch = 1)
    {
        adminMenu();
    }
    else if (ch == 0)
    {
        system("clear");
        exit(1);
    }


}

void adminMenu()
{
    system("clear");
    newLine();
    cout << "\t\t\t\033[1m----Welcome Student Management System----\033[0m\n";

    int adminChoice;
    do
    {
        cout << "\n\t\t\tAdmin Menu:\n\n";
        cout << "\t\t\t1. Add Student\n";
        cout << "\t\t\t2. Update Student Details\n";
        cout << "\t\t\t3. Delete Student\n";
        cout << "\t\t\t4. Search Student\n";
        cout << "\t\t\t5. Search Student by Section\n";
        cout << "\t\t\t6. Sort Students\n";
        cout << "\t\t\t7. View All Students\n";
        cout << "\t\t\t8. Exit\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> adminChoice;

        // Clear screen after each menu choice

        switch (adminChoice)
        {
        case 1:
            addStudent();
            break;
        case 2:
        {
            system("clear");
            string id;
            newLine();
            cout << "\t\t\tEnter Student ID to update: ";
            cin >> id;
            updateStudentDetails(id);
            break;
        }
        case 3:
        {
            system("clear");
            string id;
            newLine();
            cout << "\t\t\tEnter Student ID to delete: ";
            cin >> id;
            deleteStudent(id);
            break;
        }
        case 4:
        {
            system("clear");
            string id;
            newLine();
            cout << "\t\t\tEnter Student ID to search: ";
            cin >> id;
            searchStudent(id);
            break;
        }
        case 5:
        {
            system("clear");
            string section;
            newLine();
            cout << "\t\t\tEnter Student section to search: ";
            cin >> section;
            searchStudentBySection(section);
            break;
        }
        case 6:
            sortStudents();
            break;
        case 7:
            viewAllStudents();
            break;
        case 8:
            newLine();
            cout << "\t\t\tExiting Admin Menu...\n";
            system("clear");
            exit(1);
            break;
        default:
            newLine();
            system("clear");
            cout << "\t\t\tInvalid choice! Please try again.\n";
        }
    } while (adminChoice != 8);
}


int main()
{
    loadStudents();

    int choice;
    cout << "\n\n\t\t\t\033[1mLogin as:\033[0m\n";
    cout << "\t\t\t1. Admin\n";
    cout << "\t\t\t2. Exit\n";
    cout << "\t\t\tEnter your choice: ";

    cin >> choice;

    if (choice == 1)
    {
        system("clear"); // Clear the screen (use "cls" on Windows)

        string id, password;
        int attempts = 0;
        bool accessGranted = false;

        while (attempts < 3 && !accessGranted)
        {
            newLine();
            cout << "\t\t\tEnter Admin ID: ";
            cin >> id;
            cout << "\t\t\tEnter Admin Password: ";
            cin >> password;

            if (id == ADMIN_ID && password == ADMIN_PASSWORD)
            {
                accessGranted = true;
                adminMenu();
            }
            else
            {
                if (attempts < 3) system("clear");
                attempts++;
                cout << "Invalid Admin credentials! You have " << (3 - attempts) << " attempt(s) left.\n";

            }
        }
        if (!accessGranted)
        {
            cout << "Too many failed attempts! Access denied (Please contact with system Admin).\n";
        }
    }
    else if (choice == 2)
    {
        cout << "Exiting the program...\n";
    }
    else
    {
        cout << "Invalid choice! Please try again.\n";
    }

    return 0;
}
