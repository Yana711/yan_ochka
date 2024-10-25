#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string Name;
    string Surname;
    string Group;
    int Age;
    int XP;
    int The_amount_of_money;
    float Student_time;
    int Computer_science_assessment;

public:
    Student() : Name("Физтех"), Surname("Обычный"), Group("Б04-304"), Age(19), XP(0), The_amount_of_money(0), Student_time(0), Computer_science_assessment(10) {}

    Student(string name, string surname, string group, int age, int xp, int money, float time, int assessment):
     Name(name), Surname(surname), Group(group), Age(age), XP(xp), The_amount_of_money(money), Student_time(time), Computer_science_assessment(assessment) {}

    void Eat(int n) {
        for (int i = 0; i < n; i++) {
            if (The_amount_of_money <= 0) {
                cout << "Ошибка! Нет денег...\n";
                return; 
            } else {
                XP += 10;
            }
            Student_time += 0.5;
            The_amount_of_money -= 300;
        }
    }

    void Study(int t) {
        if (t > 24) {
            XP -= 3 * 100;
        } else {
            XP -= 100;
        }
        Student_time += t;
    }

    void Sleep(int t) {
        if (t > 6) {
            Student_time = 0;
        } else {
            Student_time += t;
        }
        XP += 50 * t;
    }

    void Work(int t) {
        if (t > 24) {
            XP -= 3 * 75;
        } else {
            XP -= 75;
        }
        Student_time += t;
    }

    void Entertainments(int t) {
        Student_time += t;
        The_amount_of_money -= t * 50;
        if (Student_time > 24) {
            XP = XP / 3;
        }
        if (The_amount_of_money < 0) {
            cout << "Ошибка! Денег нет...\n";
        } else {
            XP += t * 25;
        }
    }

    int Information_about_life() {
        return XP;
    }

    int Information_about_money() {
        return The_amount_of_money;
    }

    float Time_information() {
        return 24 - Student_time;
    }

    void Print_information() {
        cout << "Фамилия: " << Surname << ", Имя: " << Name << "\n";
        cout << "Группа: " << Group << "\n";
        cout << "Возраст: " << Age << "\n";
        cout << "ХР: " << XP << "\n";
        cout << "Деньги: " << The_amount_of_money << "\n";
        cout << "Время: " << 24 - Student_time << "\n";
        cout << "Оценка: " << Computer_science_assessment << "\n";
    }

    void Academic() {
        if (XP <= 0) {
            cout << "Ошибка! Ушел в академ...:(\n";
        }
    }
};

int main() {
    cout << "Введите группу студента, его уровень жизни, количество денег и оценку по информатике (по умолчанию напишите 10) в одну строку:\n";
    string str, name, surname, group;
    int xp, the_amount_of_money, computer_science_assessment;
    cin >> group >> xp >> the_amount_of_money >> computer_science_assessment;

    cout << "Оставить имя по умолчанию (напишите yes) или введите (напишите no)\n";
    cin >> str;
    Student student;

    if (str == "no") {
        cout << "Введите имя и фамилию через запятую в одной строке\n";
        cin >> name >> surname; 
        student = Student(name, surname, group, 19, xp, the_amount_of_money, 0, computer_science_assessment); // Assign the new student
    } else {
        student = Student();
    }
    
    int n, t_1, t_2, t_3, t_4;
    cout << "Введите количество приемов пищи, количество часов учебы, сна, работы и развлечений в одну строку\n";
    cin >> n >> t_1 >> t_2 >> t_3 >> t_4;

    student.Eat(n);
    student.Study(t_1);
    student.Sleep(t_2);
    student.Work(t_3);
    student.Entertainments(t_4);

    student.Print_information();
    student.Academic();

    return 0;
}