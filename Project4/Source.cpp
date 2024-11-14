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
        cout << "��� ���������: " << name << endl;
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
        cout << "���-���!" << endl;
    }

    void Type() const override
    {
        cout << "������" << endl;
    }
};


class Cat : public DomesticAnimal
{
public:
    Cat(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "���-���!" << endl;
    }

    void Type() const override
    {
        cout << "�����" << endl;
    }
};


class Parrot : public DomesticAnimal
{
public:
    Parrot(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "�����-�����!" << endl;
    }

    void Type() const override
    {
        cout << "�������" << endl;
    }
};


class Hamster : public DomesticAnimal
{
public:
    Hamster(const string& name) : DomesticAnimal(name) {}

    void Sound() const override
    {
        cout << "��-��!" << endl;
    }

    void Type() const override
    {
        cout << "�����" << endl;
    }
};

int main()
{

    vector<shared_ptr<DomesticAnimal>> animals;


    animals.push_back(make_shared<Dog>("����"));
    animals.push_back(make_shared<Cat>("�����"));
    animals.push_back(make_shared<Parrot>("����"));
    animals.push_back(make_shared<Hamster>("�����"));


    for (const auto& animal : animals)
    {
        animal->Show();
        animal->Type();
        animal->Sound();
        cout << endl;
    }

    return 0;
}