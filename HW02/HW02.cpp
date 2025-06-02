#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HW02.h"
using namespace std;

void Dog::makeSound() {
    cout <<"멍멍!" << endl;
}
void Cat::makeSound() {
    cout <<"냐옹~" << endl;
}
void Cow::makeSound() {
    cout <<"음메~" << endl;
}

void Zoo::addAnimal(Animal* animal) {
    if (this->count > 9) {
        delete this->animals[0];
        for (int i = 1; i < this->count; i++) {
            this->animals[i-1] = this->animals[i];
        }
        this->count--;
    }
    this->animals[this->count] = animal;
    this->count++;
}
void Zoo::performActions() {
    for (int i = 0; i < this->count; i++) {
        this->animals[i]->makeSound();
    }
}
Zoo::~Zoo() {
    for (int i = 0; i < this->count; i++) {
        delete animals[i];
        cout << i << "번째 동물객체 삭제" << endl;
    }
}

Animal* createRandomAnimal() {
    int rand_num = rand() % 3;
    if (rand_num == 0) {
        return new Dog();
    }
    else if (rand_num == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

int main(){
    srand((unsigned int)time(NULL));

    Dog ani_dog;
    Cat ani_cat;
    Cow ani_cow;
    Animal* animals[3] = { &ani_dog,&ani_cat,&ani_cow };
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }
    cout << "-------" << endl;
    Zoo zoo;
    for (int i = 0; i < 10; i++) {
        zoo.addAnimal(createRandomAnimal());
    }
    zoo.performActions();
    cout << "-------" << endl;
    zoo.addAnimal(createRandomAnimal());
    zoo.performActions();

    cout << "-------" << endl;
    return 0;
}