#include <iostream>
#include <vector>
#include <memory>
#include "wizard_2.cpp" /*We include the code from the "main file" in this one to determine the class of human.*/
using namespace std;

/*the idea is that a person can have only 3 types of weapons, there are 5 possible ones, and a knife must be present in the inventory*/

/*we do all the same actions as with spells, but with weapons. We prescribe a virtual function so that the weapon can act on an object of the aang class*/

class Weapon {
protected:
    string name;
    int damage;
    int clip = 0;

public:
    virtual void use(Aang* people) = 0;   
    virtual void inf() const {
        cout << "Weapon: " << name << " Damage: " << damage << "\n";
    }
    virtual ~Weapon() = default;
};

class Knife : public Weapon {
public:
    Knife() { 
        name = "The knife"; 
        damage = 5; 
    }
    void use(Aang* people) override {
        if(!people->resistance){
        people->gain.push_back("Stabbed");
        people->health -= damage;
        }
        else{
            people->resistance --;
        }
    }
};

class Grenade : public Weapon {
public:
    Grenade() { 
        name = "Grenade"; 
        damage = 100; 
        clip = 1;
    }
    void use(Aang* people) override {
        if(clip!=0){
        if(!people->resistance){
        people->gain.push_back("Grenade explosion");
        people->health = 0;
        }
        else{
            people->resistance --;
        }
        clip-=1;
    }  
    }
};

class SubmachineGun : public Weapon {
public:
    SubmachineGun() { 
        name = "Submachine gun"; 
        damage = 7; 
        clip = 20;
    }
    void use(Aang* people) override {
        if(clip!=0){
        if(!people->resistance){
        people->gain.push_back("Wounded by a submachine gun");
        people->health -= damage;
        }
        else{
            people->resistance --;
        }
        clip -=1;
    }
    }
};

class Pistol : public Weapon {
public:
    Pistol() { 
        name = "Gun"; 
        damage = 10;
        clip = 10; 
    }
    void use(Aang* people) override {
        if(clip!=0){
        if(!people->resistance){
        people->gain.push_back("Wounded by a gun");
        people->health -= damage;
        }
        else{
            people->resistance --;
        }
        clip -=1 ;
    }
    }
};

class AssaultRifle : public Weapon {
public:
    AssaultRifle() { 
        name = "AssaultRifle"; 
        damage = 12; 
        clip = 40;
    }
    void use(Aang* people) override {
        if(clip!=0){
        if(!people->resistance){
        people->gain.push_back("Wounded by a assaultRifle");
        people->health -= damage;
        clip -=1 ;
        }
        else{
            people->resistance --;
        }
    }
    }
};

/*We prescribe a function so that you can organize an inventory of 3 types of weapons*/
shared_ptr<Weapon> chooseWeap(string name)
{
    if(name == "Granate")
    {
        return make_shared<Grenade>();
    }
    else if(name == "Pistol")
    {
        return make_shared<Pistol>();
    }
    else if(name == "AssaultRifle")
    {
        return make_shared<AssaultRifle>();
    }
    else if(name == "SubmachineGun")
    {
        return make_shared<SubmachineGun>();
    }
    else
    {
        return make_shared<Knife>();
    }
}
/*creating a person's inventory*/
class Inventory {
private:
    vector<shared_ptr<Weapon>> weapons;

public:
    /*adding 3 types of weapons*/
    Inventory(string one, string two) {
        weapons.push_back(make_shared<Knife>());
        weapons.push_back(chooseWeap(one));
        weapons.push_back(chooseWeap(two));
    }

    void useWeapons(Aang* people) {
        int quantity = 0;

        people->gain.clear();
        for (const auto& weapon : weapons) {
            if (quantity < 3) {
                weapon->use(people);
                quantity++;
            }
        }
    }

    void inf() {
        for (const auto& weapon : weapons) {
            weapon->inf();
        }
    }
};

class People : public Aang {
    string name;
public: 
    Inventory* inv;
    People* adres = this;
    People(string n, int h, int s, Inventory* i)
    {
        name = n;
        health = h;
        shield = s;
        inv = i;
    }
    void inf() override {
        cout <<name<< ": Health =  " << health << ", Shield = " << shield << "\n";
        cout<<"Inventory: \n";
        inv->inf();
    }
};