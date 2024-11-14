#include <iostream>
#include <vector>
#include <memory> 

using namespace std;


class DomesticAnimal
{
protected:
    string name;

public:

    DomesticAnimal(const string& animal_name) : name(animal_name) {}


    virtual void Sound() const = 0;


    virtual void Show() const
    {
        cout << "Имя животного: " << name << endl;
    }


    virtual void Type() const = 0;


    virtual ~DomesticAnimal() {}
};


class Dog : public DomesticAnimal
{
public:
    Dog(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "Гав-гав!" << endl;
    }

    void Type() const override
    {
        cout << "Собака" << endl;
    }
};


class Cat : public DomesticAnimal
{
public:
    Cat(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "Мяу-мяу!" << endl;
    }

    void Type() const override
    {
        cout << "Кошка" << endl;
    }
};


class Parrot : public DomesticAnimal
{
public:
    Parrot(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "Чирик-чирик!" << endl;
    }

    void Type() const override
    {
        cout << "Попугай" << endl;
    }
};


class Hamster : public DomesticAnimal
{
public:
    Hamster(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "Пи-пи!" << endl;
    }

    void Type() const override
    {
        cout << "Хомяк" << endl;
    }
};

int main()
{

    vector<shared_ptr<DomesticAnimal>> animals;


    animals.push_back(make_shared<Dog>("Рекс"));
    animals.push_back(make_shared<Cat>("Мурка"));
    animals.push_back(make_shared<Parrot>("Кеша"));
    animals.push_back(make_shared<Hamster>("Тимми"));


    for (const auto& animal : animals)
    {
        animal->Show();
        animal->Type();
        animal->Sound();
        cout << endl;
    }

    return 0;
}