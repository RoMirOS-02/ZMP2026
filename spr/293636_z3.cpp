#include <iostream>
#include <string>

enum Alignment { good, neutral, evil };

class Character {
private:
    std::string name;
    std::string title;
    bool status;
    int power;
    Alignment alignment;
protected:
    Character(const std::string &n, const std::string &t, int p, Alignment a)
        : name(n), title(t), status(true), power(p), alignment(a) {}
public:
    virtual ~Character() = default;
    const std::string &getName() const { return name; }
    const std::string &getTitle() const { return title; }
    bool isAlive() const { return status; }
    int getPower() const { return power; }
    Alignment getAlignment() const { return alignment; }
    void setStatus(bool s) { status = s; }
    void setAlignment(Alignment a) { alignment = a; }
    virtual void triumph() const {
        std::cout << name << " " << title << " triumph." << std::endl;
    }
    virtual void death() {
        status = false;
        std::cout << name << " " << title << " has died." << std::endl;
    }
    static const char *alignmentName(Alignment a) {
        switch (a) {
            case good: return "good";
            case neutral: return "neutral";
            case evil: return "evil";
        }
        return "unknown";
    }
    friend std::ostream &operator<<(std::ostream &os, const Character &c) {
        os << "Name: " << c.name
           << ", Title: " << c.title
           << ", Power: " << c.power
           << ", Status: " << (c.status ? "alive" : "dead")
           << ", Alignment: " << alignmentName(c.alignment);
        return os;
    }
};

class Hero : public Character {
public:
    Hero(const std::string &n, const std::string &t, int p)
        : Character(n, t, p, good) {}
    void triumph() const override {
        std::cout << getName() << " " << getTitle() << " triumf swiatlosci" << std::endl;
    }
    void death() override {
        setStatus(false);
        std::cout << getName() << " " << getTitle() << "  dla prawdziwgo bohatera smierc nie oznacza, ze zostal pokonany." << std::endl;
    }
};

class Villain : public Character {
    public:
    Villain(const std::string &n, const std::string &t, int p)
        : Character(n, t, p, evil) {}
    void triumph() const override {
        std::cout << getName() << " " << getTitle() << " triumf ciemnosci" << std::endl;
    }
    void death() override {
        setStatus(false);
        std::cout << getName() << " " << getTitle() << " postac ta zostala wrzucona do jeziora plynnego lodu." << std::endl;
    }
};


std::string clash(Character &first, Character &second) {
    if (first.getPower() >= second.getPower()) {
        first.triumph();
        second.death();
        return first.getName() + " wins";
    }
    if (first.getPower() < second.getPower()) {
        second.triumph();
        first.death();
        return second.getName() + " wins";
    }
}



using namespace std;

int main() {
    string n1, t1, n2, t2;
    int p1 = 0, p2 = 0;
    cin >> n1 >> t1 >> p1 >> n2 >> t2 >> p2;

    Hero hero(n1, t1, p1);
    Villain villain(n2, t2, p2);
    cout << hero << std::endl;
    cout << villain << std::endl;
    cout << "Clash result: " << clash(hero, villain) << std::endl;
    cout << hero << std::endl;
    cout << villain << std::endl;
    return 0;
}
