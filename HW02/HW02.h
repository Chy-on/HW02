#pragma once

class Animal {
public:
	virtual void makeSound() = 0;
	virtual ~Animal() {};
};

class Dog : public Animal {
public:
	void makeSound();
};

class Cat : public Animal {
public:
	void makeSound();
};

class Cow :public Animal {
public:
	void makeSound();
};

class Zoo {
private:
	Animal* animals[10];
	int count = 0;
public:
	void addAnimal(Animal* animal);
	void performActions();
	~Zoo();
};