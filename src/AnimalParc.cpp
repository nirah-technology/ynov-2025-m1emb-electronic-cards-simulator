#include <string>

class Animal {

private:
    // Champs Statiques
    
    // Propriétés
    unsigned int birth_date;
    std::string breed;
    
protected:
Animal() {
    this->total_animals_created++;
}

public:
    static int total_animals_created;
    void eat() {};        
};
    
class Cat : public Animal {
    private:
    static int total_cats_created;
public:
    Cat() {
        this->total_cats_created++;
    }

    static void sauvegarder() {
    }
    void miauler();
    void courir() {

    };
};

class Dog : public Animal {
    
};

