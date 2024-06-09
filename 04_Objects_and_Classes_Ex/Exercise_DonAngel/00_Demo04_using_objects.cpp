#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Person{
    class Body {
        public:
            double heightM;
            double weightKg;
    };

    public:
    string name;
    int age;

    Body body;
};

void printPersonInfo (const Person & person){
    cout<<"name: "<<person.name<<endl;
    cout<<"age: "<<person.age<<endl;
    cout<<"height: "<<person.body.heightM<<endl;
    cout<<"weight: "<<person.body.weightKg<<endl;
}

void makePersonolder(Person & person, int years) {
    person.age+=years;
}

int main() {
    Person person;

    cout<<"person (not initialized) = ";
    printPersonInfo(person);

    person.name="Bache Kiko";
    person.age=51;
    person.body.heightM=1.65;
    person.body.weightKg=62;

    cout<<endl;
    printPersonInfo(person);

    Person people[3];
    people[0]=person;

    cout<<endl;
    cout<<"people[0]= "<<endl;
    printPersonInfo(people[0]);

    makePersonolder(people[0],2);
    cout<<endl;
    cout<<"people[0] after aging= "<<endl;
    printPersonInfo(people[0]);

    Person *newPerson = new Person();
    newPerson->name="Kikovica";
    newPerson->age=32;
    newPerson->body.heightM=1.58;
    newPerson->body.weightKg=42;

    cout<<endl;
    cout<<"newPerson= "<<endl;
    printPersonInfo(*newPerson);
    delete newPerson;

    
    
    system("pause");
    return 0;
}
