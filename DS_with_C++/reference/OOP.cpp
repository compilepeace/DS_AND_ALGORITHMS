/*
    Connecting code to the living world
    
    GOD consists of Trimurti 
        - Creator Vishnu  ->  constructor (default, parameterized)
        - Manager Brahma  ->  manager - US 
        - Destroyer Shiva ->  destructor  (default)
    
    that's what life of any object is !
*/


#include <iostream>
#include <cstring>
using namespace std;


class Human
{
    private:            // By default every member has a 'private' access specifier        
        int age;

    public:
        char *name;     // If a variable is a 'const' (i.e. Read-Only), it must be initialized
                        // inside 'Initialization list' before function body starts.
       
//------------------------- VISHNU - calling CONSTRUCTORS : creating objects ---------------------

    // Simple Constructor - with initialization list to initialize its data members
    Human() : age(0), name(NULL) {
        printf("Inside simple constructor\n");
    
        /* If no initialization list is given to the constructor, we would have done this
        age = 0;
        name = NULL;
        */
    }


    // parameterized constructor (overriding the default constructor)
    Human(char *s, int a) : age(a)
    {
        printf("Inside parameterized constructor: %s\n", s);

        size_t l = strlen(s);
        name = new char[l + 1];
        strncpy(name, s, l + 1);
    }


//----------------------------- When OBJECT is passed as parameter ------------------------------
    // 'Deep Copy Constructor' (to avoid 'shallow copy performed by 'default copy constructor'
    Human(Human &obj) : age(obj.age)
    {
        printf("Inside Deep Copy Constructor: %s\n", obj.name);
        
        size_t l = strlen(obj.name);
        name = new char[l + 1];
        strncpy(name, obj.name, l + 1);
    }
       

    // 'Copy Assignment Operator' (operator overloading) to prevent shallow copy of (obj1 = obj2)
    void operator = (Human &obj)
    {
        printf("Inside Copy Assignment operator=(): copying %s\n", obj.name);
        age = obj.age;

        size_t l = strlen(obj.name);
        name = new char[l + 1];
        strncpy(name, obj.name, l + 1);
    }
   
//----------------------------------------------------------------------------------------------   

//------------------------------- Brahma - writing member functions ---------------------------
    
    // A constant function - means that this function cannot modify any value inside its body
    void print() const{
        printf("%s: %d\n", name, age);    
    }
//---------------------------------------------------------------------------------------------


//------------------------------- Shiva - Ensuring complete destruction ----------------------

    ~Human()
    {
        printf("Inside destructor: %s\n", name);
        // Write code to delete all the dynamic members of the object
        if (name != NULL) delete name;
    }

};


int main()
{

    Human h1("Abhinav", 21);        // Invokes parameterized constructor
    /*
    Human h2("Manish", 20);         

    h1.print();
    h2.print();
   

    Human h3(h1);       // Invokes deep copy constructor
    h1.print();
    h3.print();
   

    Human h4;           // Invokes simple constructor
    h4 = h1;            // Invokes copy asignment operator=()
    h4.print();
    */

    Human h2;


    
}

