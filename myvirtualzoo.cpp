#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
using std::string;

//Базовый класс животных 
class Animals {
	public: Animals(
	 string name,
	 int age,
	 string habitat): name_(name), age_(age), habitat_(habitat) {}

//Общие методы
void eating() {
	cout << name_ << "eats." << endl;
}
void sleeping(){
	cout << name_ << "sleeps." << endl;

}
void type_of_moving(){
	cout << name_ << "moves." << endl;
}

//Общие свойства
    string name_;
    int age_;
    string habitat_;
};

//Класс хищники
class Predator: public Animals {
	public: Predator (string name, int age, string habitat, bool warmblooded, bool hasClaws,
	bool hasFur): Animals(name, age, habitat), warmblooded_(warmblooded), hasClaws_(hasClaws), hasFur_(hasFur) {}
//Уникальные свойства
	bool warmblooded_;
	bool hasClaws_;
	bool hasFur_;
//Уникальные методы:
    void eating_other_animals() {
		cout << name_ << "eats other animals." << endl;
	}
	void having_teeth() {
        cout << name_ << "has teeth." << endl;
	}
	void clumbing(){
		cout << name_ << "climbs trees." << endl;
	}
	};

//Класс птиц
class Bird: public Animals {
	public: Bird (string name, int age, string habitat, bool canFly, bool hasWings, bool migratory, bool havingNest): Animals(name, age,
	habitat),canFly_(canFly), hasWings_(hasWings), migratory_(migratory), havingNest_(havingNest) {}
//Уникальные методы
     void flying(){
			cout << name_ << "can fly." << endl;
	 }
	 void building_nests() {
		    cout << name_ << "builds nests." << endl;
	 }
	 void hatching_from_egg() {
		    cout << name_ << "hatchs from egg." << endl;
	 }
//Уникальные свойства:
bool canFly_;
bool hasWings_;
bool migratory_;
bool havingNest_;
};

//Класс насекомых
class Insect: public Animals {
	public: Insect (string name, int age, string habitat, bool hasWings, bool poisonous, bool canSting, bool canPollinatePlants): Animals(name, age,
	habitat), hasWings_(hasWings), poisonous_(poisonous), canSting_(canSting), canPollinatePlants_(canPollinatePlants) {}
//Уникальные свойства:
bool canSting_;
bool canPollunatePlants_;
//Уникальные методы:
    void biting(){
		cout << name_ << "can bite." << endl;
	}
	void jumping(){
		cout << name_ << "can jump." << endl;
	}
	void hasWings(){
	    cout <<name_ <<"has wings." << endl;
	}
//Класс рыб
class Fish: public Animals {
	public: Fish (string name, int age, string habitat, bool livesInSaltWater, bool livesInFreshWater, bool poisonous): Animals(name, age, habitat),
	livesInSaltWater_(livesInSaltWater), livesInFreshWater_(livesInFreshWater), poisonous_(poisonous) {}	
//Уникальные свойства:
bool livesInSaltWater_;
bool livesInFreshWater_;
//Уникальные методы:
     void swimming(){
		cout << name_ << "can swim." << endl;
	 }
	 void circling() {
		cout << name_ << "can circle." << endl;
	 }
};
//Функция добавления животных
void addNewAnimals(vector<Animals*>& animals) {
    string name, habitat;
    int age;
    char type;
    cout << "Virtual Zoo\n\n" ;

    cout << "Please, name an animal: " ;
    cin >> name;

    cout << "Enter the age of the animal: " ;
    cin >> age;

	cout << "What is the animal's breed?: " ;
    cin >> age;

    cout << "What is the animal's habitat?: " ;
    cin >> habitat;

    cout << "Enter the type of the animal (Predator, Bird, Insect, Fish): " ;
    cin >> type;
	
//Условия
	if (type=='P') {
        bool warmblooded;
        cout << "Is this predator warm-blooded? (Y/N) ";
        char warmblooded;
        cin >> warmblooded;
        warmblooded = (warmblooded == 'Y');

        bool hasClaws;
        cout << "Does this predator have claws? (Y/N) ";
        char hasClaws;
        cin >> hasClaws;
        hasClaws = (hasClaws == 'Y');

		bool hasFur;
		cout << "Does this predator have fur? (Y/N) ";
		char hasFur;
		cin >> hasFur;
		hasFur = (hasFur == 'Y');

		animals.push_back(new Predator(name, age, habitat, warmblooded, hasClaws, hasFur));
    }
	else if (type=='B') {
	    bool canFly;
		cout << "Can this Bird fly? (Y/N) ";
		char canFly;
		cin >> canFly;
		canFly = (canFly == 'Y');

		bool hasWings;
		cout << "Does this Bird have Wings? (Y/N) ";
		char hasWings;
		cin >> hasWings;
		hasWings = (hasWings == 'Y');

		bool migratory;
		cout << "Is this Bird migratory? (Y/N) ";
		char migratory;
		cin >> migratory;
		migratory = (migratory == 'Y');

		bool havingNest;
		cout << "Does this Bird have its own nest? (Y/N)";
		char havingNest;
		cin >> havingNest;
		havingNest = (havingNest == 'Y');

		animals.push_back(new Bird(name, age, habitat, canFly, hasWings, migratory, havingNest));
    }
	else if (type == 'I') {
		bool hasWings;
		cout << "Does this Insect have Wings? (Y/N) ";
		char hasWings;
		cin >> hasWings;
		hasWings = (hasWings == 'Y');

		bool poisonous;
		cout << "Is this Insect poisonous? (Y/N) ";
		char poisonous;
		cin >> poisonous;
		poisonous = (poisonous== 'Y');

		bool canSting;
		cout << "Can this Insect sting? (Y/N) ";
		char canSting;
		cin >> canSting;
		canSting = (canSting == 'Y');

		bool canPollinatePlants;
		cout << "Can this Insect pollinate plants? (Y/N) ";
		char canPollinatePlants;
		cin >> canPollinatePlants;
		canPollinatePlants = (canPollinatePlants == 'Y');

		animals.push_back(new Insect(name, age, habitat, hasWings, poisonous, canSting, canPollinatePlants));
    }
    else if (type == 'F') {
	    bool livesInSaltWater;
	    cout << "Does this Fish live in salt water? (Y/N) ";
		char livesInSaltWater;
		cin >> livesInSaltWater;
		livesInSaltWater = (livesInSaltWater == 'Y');

		bool livesInFreshWater;
	    cout << "Does this Fish live in fresh water? (Y/N) ";
		char livesInFreshWater;
		cin >> livesInFreshWater;
		livesInFreshWater = (livesInFreshWater == 'Y');

		bool poisonous;
		cout << "Is this Fish poisonous? (Y/N) ";
		char poisonous;
		cin >> poisonous;
		poisonous = (poisonous== 'Y');
        
		animals.push_back(new Fish(name, age, habitat,livesInFreshWater, livesInFreshWater, poisonous));
    };

int main() {
	list<Predator> predatorlist = {};
	list<Bird> birdlist = {};
	list<Insect> insectlist = {};
	list<Fish> fishlist = {};

vector<Animals*>animals;
animals.push_back(new Predator("Panther", 8, "Savannah", true, true, true));
animals.push_back(new Predator("Wolf", 11, "Tundra", true, true, true));
animals.push_back(new Predator("Otter", 3, "Reservoir", true, true, true));

animals.push_back(new Bird("Hummingbird", 4, "Tropics", true, true, false, false));
animals.push_back(new Bird("Bullfinch", 11, "Coniferous forest", true, true, true, true));
animals.push_back(new Bird("Seagull", 14, "Seashore areal", true, true, true, true));

animals.push_back(new Insect("Ladybug", 1, "Reed", true, true, false, false, false));
animals.push_back(new Insect("Dragonfly", 1, "Meadow", true, true, false, false, true ));
animals.push_back(new Insect("Ant", 2, "Anthill", false, false, true, true, false));

animals.push_back(new Fish("Carp", 14, "Lake", true, true));
animals.push_back(new Fish("Lumpen Fish", 6, "Pacific Ocean", false, true));
animals.push_back(new Fish("Salmon", 21, "Pacific Ocean", true, false));
animals.push_back(new Fish("Sphinx-Sea-Dog", 10, "Black Sea", true, false));

addAnimals(animals); //Добавление животных
addAnimals(animals);
addAnimals(animals);
addAnimals(animals);


// Вызывов общих методов
for (Animals* animals : animals) {
	animals->eating();
	animals->sleeping();
	animals->moving();

// Вызов уникальных методов
	Predator* predator = dynamic_cast<Predator*>(animals);
	if (predator != nullptr) {
		predator->eats other animals();
	if (predator != nullptr) {
		predator->has teeth();
	}
	}

	Bird* bird = dynamic_cast<Bird*>(animals);
	if (bird != nullptr) {
		bird->can fly();
	}

	Insect* insect = dynamic_cast<Insect*>(animals);
	if (insect!= nullptr) {
		insect->can bite();
	}

	Fish* fish = dynamic_cast<Fish*>(animals);
	if (fish!= nullptr) {
			fish->can swim();
	}

	cout << endl;
};

cout << "Do you want to continue (Y/N)? ";
char continueOption;
cin >> continueOption;

if (continueOption == 'Y') {
	main();
}
else {
	exit(0);
}


// Освобождаем память
for (Animals* animals : animals) {
	delete animals;
}

return 0;
}
