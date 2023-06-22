#include <iostream>
#include <vector>

using namespace std;

template <typename type>
type get_user_value(unsigned short mod = 0) {
    type value;
    if (mod == 1)
        cout << "Enter: ";
    cin >> value;
    return value;
}

class Student
{
private:
    string name;
    string adress;
    int phone;
    int birthday;
    int group_number;

public:
    Student(string name, string adress, int phone, int birthday, int group_number) {
        this->name = name;
        this->adress = adress;
        this->phone = phone;
        this->birthday = birthday;
        this->group_number = group_number;
    }

    void set_name(string name) {
        this->name = name;
    }
    void set_address(string adress) {
        this->adress = adress;
    }
    void set_phone(int phone) {
        this->phone = phone;
    }
    void set_birthday(int birthday) {
        this->birthday = birthday;
    }
    void set_group_number(int group_number) {
        this->group_number = group_number;
    }

    string get_name() {
        return this->name;
    }
    string get_adress() {
        return this->adress;
    }
    int get_phone() {
        return this->phone;
    }
    int get_birthday() {
        return this->birthday;
    }
    int get_group_number() {
        return this->group_number;
    }

    void display_student() {
        cout << "Student\n";
        cout << "Name: " << this->name << endl;
        cout << "Adress: " << this->adress << endl;
        cout << "Phone: " << this->phone << endl;
        cout << "Birthday: " << this->birthday << endl;
        cout << "Group number: " << this->group_number << endl;
    }
};

int main()
{
    int user_value;
    bool exit_status = false;
    vector<Student> students_array;

    cout << "Students DB";
    do
    {
        string name, adress;
        int phone, birthday, group_number;

        if (students_array.empty())
            cout << " is empty!";

        cout << "\n1 - for add new student\n";

        if (!students_array.empty()) {
            cout << "2 - for display all students\n";
            cout << "3 - for change student data\n";
        }
        cout << "0 - for Exit\n";

        user_value = get_user_value<int>(1);

        switch (user_value)
        {
        case 0:
            exit_status = true;
            cout << "Exit";
            break;
        case 1:
            cout << "Add new student\n";
            cout << "Enter student name: ";
            name = get_user_value<string>();
            cout << "Enter student adress: ";
            adress = get_user_value<string>();
            cout << "Enter student phone: ";
            phone = get_user_value<int>();
            cout << "Enter student birthday: ";
            birthday = get_user_value<int>();
            cout << "Enter student group number: ";
            group_number = get_user_value<int>();
            cout << endl;

            students_array.push_back(Student(name, adress, phone, birthday, group_number));
            break;
        case 2:
            for (auto& student : students_array) {
                cout << endl;
                student.display_student();
            }                
            break;
        case 3:
            if (!students_array.empty()) {
                int array_size = students_array.size();
                cout << "Select student by name\n";
                for (int i = 0; i < array_size; ++i)
                    cout << i + 1 << " - for change " << students_array[i].get_name() << " data\n";
                cout << "0 - for return to main menu";

                user_value = get_user_value<int>();

                if (user_value >= 1 && user_value <= array_size) {
                    Student& selected_student = students_array[user_value - 1];
                    cout << "Selected student: " << selected_student.get_name() << endl;

                    int student_choice;

                    do {
                        cout << "\nStudent Actions\n";
                        cout << "1 - Display student data\n";
                        cout << "2 - Change student name\n";
                        cout << "3 - Change student address\n";
                        cout << "4 - Change student phone\n";
                        cout << "5 - Change student birthday\n";
                        cout << "6 - Change student group number\n";
                        cout << "0 - Return to main menu\n";
                        cout << "Enter: ";

                        student_choice = get_user_value<int>();

                        switch (student_choice) {
                        case 0:
                            cout << "Returning to main menu\n";
                            break;
                        case 1:
                            selected_student.display_student();
                            break;
                        case 2:
                            cout << "Enter new name: ";
                            selected_student.set_name(get_user_value<string>());
                            cout << "Name updated\n";
                            break;
                        case 3:
                            cout << "Enter new address: ";
                            selected_student.set_address(get_user_value<string>());
                            cout << "Address updated\n";
                            break;
                        case 4:
                            cout << "Enter new phone number: ";
                            selected_student.set_phone(get_user_value<int>());
                            cout << "Phone number updated\n";
                            break;
                        case 5:
                            cout << "Enter new birthday: ";
                            selected_student.set_birthday(get_user_value<int>());
                            cout << "Birthday updated\n";
                            break;
                        case 6:
                            cout << "Enter new group number: ";
                            selected_student.set_group_number(get_user_value<int>());
                            cout << "Group number updated\n";
                            break;
                        default:
                            cout << "Invalid choice\n";
                            break;
                        }
                    } while (student_choice != 0);
                }
                else if (user_value == 0) {
                    cout << "Back to main menu\n";
                }
                else {
                    cout << "Invalid input\n";
                }
                break;
            }            
        default:
            cout << "Error!";
            break;
        }
        
    } while (!exit_status);

    return 0;
}