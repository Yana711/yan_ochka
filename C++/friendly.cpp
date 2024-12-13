#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() const = 0;
};

class Dog : public Animal {
private:
    string Nickname;
    string Breed;
    int Age;
    int Health;
public:
    Dog(string nickname, string breed, int age, int health = 100)
        : Nickname(nickname), Breed(breed), Age(age), Health(health) {}
    void makeSound() const override {
        cout << "Гав-гав\n";
    }
    string Nickname_1() const {
        return Nickname;
    }
    string Breed_1() const {
        return Breed;
    }
    int Health_1() const {
        return Health;
    }
    void Health_2(int health) {
        Health = health;
    }
};
class Cat : public Animal {
private:
    string Nickname;
    string Breed;
    int Age;
    int Health;
public:
    Cat(string nickname, string breed, int age, int health = 100)
        : Nickname(nickname), Breed(breed), Age(age), Health(health) {}
    void makeSound() const override {
        cout << "Мяу-мяу\n";
    }
    string Nickname_1() const {
        return Nickname;
    }
    string Breed_1() const {
        return Breed;
    }
    int Health_1() const {
        return Health;
    }
    void Health_2(int health) {
        Health = health;
    }
};

struct FIO {
    string Name;
    string Surname;
};

class Owner {
private:
    FIO fio;
    int Age;
    vector<Animal*> pets;
public:
    Owner(string name, string surname, int age)
        : fio{name, surname}, Age(age) {}
    void add_pet(Animal* pet) {
        pets.push_back(pet);
    }
    void show() {
        cout << "Хозяин\n";
        cout << "Имя: " << fio.Name << "\n";
        cout << "Фамилия: " << fio.Surname << "\n";
        cout << "Возраст: " << Age << "\n";
        cout << "\n";
        cout << "Питомцы: \n";
        cout <<"\n";
        for (int i = 0; i < pets.size(); i++) {
            cout << "Питомец " << (i + 1) << ":\n ";
            if (Dog* dog = dynamic_cast<Dog*>(pets[i])) {
                cout << "Кличка: " << dog->Nickname_1() <<"\n";
                cout << "Порода: " << dog->Breed_1() << "\n";
                cout <<"Звук: ";
                dog->makeSound();
                cout <<"\n";
            }
            if (Cat* cat = dynamic_cast<Cat*>(pets[i])) {
                cout << "Кличка: " << cat->Nickname_1() << "\n";
                cout << "Порода: " << cat->Breed_1() << "\n";
                cout <<"Звук: ";
                cat->makeSound();
                cout <<"\n";
            }
        }
    }
    friend class Veterinarian;
};

class Veterinarian {
public:
   void check_health(Owner& owner) {
        for (Animal* animal : owner.pets) {
        if (Dog* dog = dynamic_cast<Dog*>(animal)) {
            cout << "Проверка здоровья для " << dog->Nickname_1() << "\n";
            int health = dog->Health_1() + 18;
            dog->Health_2((health > 100) ? 100 : health);
            cout << dog->Nickname_1() << " здоровье " << dog->Health_1() << "\n";
        } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
            cout << "Проверка здоровья для " << cat->Nickname_1() << "\n";
            int health = cat->Health_1() + 18;
            cat->Health_2((health > 100) ? 100 : health);
            cout << cat->Nickname_1() << " здоровье " << cat->Health_1() << "\n";
        }
    }
   }
    void health_problems(Owner& owner) {
        for (Animal* animal : owner.pets) {
        if (Dog* dog = dynamic_cast<Dog*>(animal)) {
            cout << "Лечение " << dog->Nickname_1() << "\n";
            int health = dog->Health_1() - 18;
            dog->Health_2((health < 0) ? 0 : health);
            cout << dog->Nickname_1() << " здоровье " << dog->Health_1() << "\n";
        } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
            cout << "Лечение " << cat->Nickname_1() << "\n";
            int health = cat->Health_1() - 18;
            cat->Health_2((health < 0) ? 0 : health);
            cout << cat->Nickname_1() << " здоровье " << cat->Health_1() << "\n";
        }
    }
    }
    void talk(const Owner& owner) {
        cout << "Ветеринар говорит с хозяином..." << "\n";
    }
    friend class Owner;
};
int main() {
    Owner owner("Яна", "Козырская", 19);
    vector<Animal*> pets_2; 
    
    Cat* cat = new Cat("Виски", "шотландец", 10);
    pets_2.push_back(cat);
    owner.add_pet(cat);
    
     
    Dog* dog = new Dog("Бурбон", "Лабрадор", 5);
    pets_2.push_back(dog);
    owner.add_pet(dog);
    
    owner.show();
    
    Veterinarian veterinarian;

    veterinarian.check_health(owner);
    veterinarian.health_problems(owner);
    
    veterinarian.talk(owner);
    delete cat;
    delete dog;
    return 0;
}
