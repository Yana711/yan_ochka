#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
T SUM(const T& a, const T& b) {
    return a + b;
}

class Aang {
public:
    int health;
    int shield;
    vector<string> blinding;
    vector<string> gain;

    virtual void inf() = 0; 
};

class Spell {
protected:
    string name;

public:
    virtual void apply(Aang* aang) = 0; 
    virtual void inf() const {
        cout << "spell: " << name << "\n";
    }
    virtual ~Spell() = default;
};

class Attack : public Spell {
public:
    Attack() { name = "Attack"; }
    void apply(Aang* aang) {
        aang->blinding.push_back("Burning");
        aang->health -= 17;
    }
};

class Protect : public Spell {
public:
    Protect() { name = "Protect"; }
    void apply(Aang* aang)  {
        aang->gain.push_back("Shielded");
    }
};

class Household : public Spell {
public:
    Household() { name = "Household"; }
    void apply(Aang* aang) {
        cout << "Бытовое заклинание не предназначено для боя.\n";
    }
};

class Unforgivable : public Spell {
public:
    Unforgivable() { name = "Unforgivable"; }
    void apply(Aang* aang) {
        cout << "Не стоит использовать это заклинание.\n";
    }
};

class Heal : public Spell {
private:
    int healAmount;

public:
    Heal(int amount) : healAmount(amount) {
        name = "Heal";
    }

    void apply(Aang* aang) {
        aang->health += healAmount; 
        cout << "Цель восстановила " << healAmount << " здоровья.\n";
    }

    void inf() const override {
        cout << "Заклинание: " << name << " (восстанавливает " << healAmount << " здоровья)\n";
    }
};

class Element {
protected:
    string name;
    int attack = 0;
    int protection = 0;

public:
    virtual void effect(Aang* aang) = 0;
    friend class NatureSpell;
};

class Fire : public Element {
public:
    Fire() { name = "Fire"; attack = 11; }
    void effect(Aang* aang) {
        aang->blinding.push_back("Burning");
    }
};

class Water : public Element {
public:
    Water() { name = "Water"; attack = 7; }
    void effect(Aang* aang)  {
        aang->blinding.push_back("Drenched");
    }
};

class Earth : public Element {
public:
    Earth() { name = "Earth"; protection = 3; }
    void effect(Aang* aang)  {
        aang->gain.push_back("Stoned"); 
    }
};

class Air : public Element {
public:
    Air() { name = "Air"; protection = 9; } 
    void effect(Aang* aang)  {
        aang->gain.push_back("Air barrier"); 
    }
};

class NatureSpell {
private:
    vector<shared_ptr<Element>> elements;

public:
    NatureSpell(const vector<shared_ptr<Element>>& elems) : elements(elems) {}

    void apply(Aang* aang) {
        int total_damage = 0, total_protection = 0;

        for (const auto& elem : elements) {
            elem->effect(aang);
            total_damage = SUM(total_damage,elem->attack);
            total_protection = SUM(total_protection, elem->protection);
        }
        if (aang->health <= 0) {
            throw("Barbie");
        }
        if (total_damage > aang->shield) {
            total_damage -= aang->shield;
            aang->shield = 0;
            aang->health -= total_damage;
        } else {
            aang->shield -= total_damage;
        }
        aang->shield += total_protection; 
    }

    void inf() {
        cout << "Nature Spell: ";
        for (const auto& elem : elements) {
            cout << elem->name << " ";
        }
        cout << "\n";
    }
};

class Book {
private:
    string name;
    vector<shared_ptr<Spell>> spells;
    vector<shared_ptr<NatureSpell>> natureSpells;

public:
    Book(const string& n) : name(n) {}

    void addSpell(const shared_ptr<Spell>& spell) {
        spells.push_back(spell);
    }

    void addNatureSpell(const shared_ptr<NatureSpell>& spell) {
        natureSpells.push_back(spell);
    }

    void inf() const {
        cout << "Книга: " << name << "\n"<<"Заклинания:\n";
        for (const auto& spell : spells) {
            spell->inf();
        }
        for (const auto& nSpell : natureSpells) {
            nSpell->inf();
        }
    }
};

class Wizard : public Aang {
private:
    string name;

public:
    Wizard(const string& n, int h, int s) : name(n) {
        health = h;
        shield = s;
    }

    void inf() override {
        cout << "Маг: " << name <<"\n"<< "Здоровье: " << health << "\n"<<"Щит: " << shield << "\n";
        cout << "Плюшки: ";
        for (const auto& buff : gain) {
            cout << buff << " ";
        }
        cout << "********: ";
        for (const auto& debuff : blinding) {
            cout << debuff  << " ";
        }
        cout << "\n";
    }
};

main() {
    auto fire = make_shared<Fire>();
    auto water = make_shared<Water>();
    auto earth = make_shared<Earth>();
    auto air = make_shared<Air>(); 
    
    vector<shared_ptr<Element>> elements = {fire, water, earth, air};
    auto natureSpell = make_shared<NatureSpell>(elements);

 
    auto attackSpell = make_shared<Attack>();
    auto protectSpell = make_shared<Protect>();
    auto healSpell = make_shared<Heal>();
    auto unforgSpell = make_shared<Unforgivable>();
    auto houseSpell = make_shared<Household>();


    
    Book book("Shiryaev. Probability Theory:(");
    book.addSpell(attackSpell);
    book.addSpell(protectSpell);
    book.addSpell(healSpell);
    book.addSpell(unforgSpell);
    book.addNatureSpell(natureSpell);
    book.addSpell(houseSpell);

    
    Wizard Gosling("Gosling", 100, 20);
    Wizard Ken("Ken", 80, 30);

    book.inf();
    cout << "Перед боем:\n";
    Ken.inf();

    try {
        natureSpell->apply(&Ken);
    } catch (...) {
        cout << "Жаль этого добряка...\n";
    }

    cout << "После применения заклинания:\n";
    Ken.inf();
}
