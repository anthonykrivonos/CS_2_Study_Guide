//
//
//  Chapter 9
//  Pointers
//
//


// Address-of operator (&)
int num = -99;
cout << &num;
/* The actual address of a variable in memory cannot
   be known before runtime. /*


// Pointer Variable
/* Often just called a pointer, it's a variable that holds an
   address

   When you declare a pointer variable, its content is not initialized. In other
   words, it contains an address of "somewhere", which is of course not a
   valid location.
*/
int *ptr;


// Dereference/Indirection operator
int myvar = 25;
int *foo = &myvar;
int baz = *foo
/* baz would have the value of myvar */


// Null Pointers
int *q = NULL;


// Pointer Arrays
int vals[] = {4, 7, 11};
cout << *vals; // displays 4
cout << *(vals + 1); // displays 4


// Pointer Arithmetic
char *mychar = 1000;
cout << ++mychar; //displays 1001


// Char Pointer
const char *foo = "foo";
cout << *(foo+2); // displays 'o'
cout << foo[2]; //displays 'o'


// Comparing Pointers
if (ptr1 == ptr2) // compares addresses
if (*ptr1 == *ptr2)// compares contents


// Pass By Reference
// Pointer Arguments
void func(int *foo) {
      cout << foo; // Displays address of foo
      cout << *foo; // Displays contents of foo
}
// Reference Arguments
void func(int &foo) {
      cout << &foo; // Displays address of foo
      cout << foo; // Displays contents of foo
}


// Pointers and Const
int x;
int y = 10;
const int *p = &y;
x = *p; // Works: x equals 10
*p = x; // Error: cannot modify constant


// Stacks and Heaps
/*
   The stack: All variables declared inside the function will take up memory
   from the stack.
   The heap: This is unused memory of the program and can be used to
   allocate the memory dynamically when program runs.
*/


// new and new[]
int *foo;
foo = new int[5];
/*
   In this case, the system dynamically allocates space
   for five elements of type int and returns a Pointerto the
   first element of the sequence, which is assigned to foo.

   If allocation fails, an exemption is thrown.
*/
foo = new int[5]; // To prevent a bad_alloc error, add (nothrow)
foo - new (nothrow) int[5];

// Deleting Pointers
double *pvalue = NULL; // pointer initialized with NULL
pvalue = new double; // request memory for a double
*pvalue=29494.99; // store a value
delete pvalue; // free up memory


// Delete Pointer Array
int *foo;
foo = new int[10];
delete[] foo;
// Always match new[] and delete[], but it's advised not to use new[]


// Loop Using Pointer Notation
int *foo = new int[3];
foo = {1, 2, 3};
for (int i = 0; i < 3; i++) { *(foo+i)++; }


// Rectangle Class With Pointers
#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle {
private:
      double width;
      double length;
      static int counter;
      int id;
public:
      Rectangle() {
            counter++; id = counter; width = 0; length = 0;
            cout << "Inside constructor" << id << endl;
      }
      ~Rectangle() {
            cout << "Inside destructor " << id <<endl;
      }
};
int main()
{
      Rectangle *polyArrPtr[5]; // array of 5 pointers to objects
      for (int i=0; i<5; i++)
            polyArrPtr[i]=new Rectangle;
      for (int i=0; i<5; i++)
            delete polyArrPtr[i];
      delete[] polyArrPtr;
      return 0;
}
/* Prints:
   Inside constructor 1
   Inside constructor 2
   Inside constructor 3
   Inside constructor 4
   Inside constructor 5
   Inside destructor 1
   Inside destructor 2
   Inside destructor 3
   Inside destructor 4
   Inside destructor 5
*/


// Destructors and Dynamically Allocated Class Objects
/*
   If a class object has been dynamically allocated by the new operator, its
   memory should be released when the object is no longer needed.
*/
Foo *fooPtr;
fooPtr = new Foo;
delete fooPtr;


// Returning Pointers from Functions
int * squarePtr(int number)
{
      int * dynamicAllocatedResult = new int(number*number);
      return dynamicAllocatedResult;
}


// Using Smart Pointers to Avoid Memory Leaks
/*
   unique_ptr
   shared_ptr
   weak_ptr
*/
#include <memory>
unique_ptr<int> ptr(new int);


//
//
//  Chapter 11
//  Classes
//
//


// class
/* Like a struct, but variables and functions in the class
   can have different properties than in a struct. */
#include <iostream>
#ifndef CLASSNAME_H //include guard
#define CLASSNAME_H
class ClassName {
private:
      int var;
public:
      int publicVar;
      Object() { var = 0; publicVar = 0; protectedVar = 0; }
protected:
      int protectedVar;
};
#endif


// Objects
/* An object is an instance of a class */
ClassName object();


// Access Specifiers
class ClassName {
public:
      /* The members declared as Public are accessible from
         outside the class through an object of the class. */
private:
      /* These members are only accessible from within the
         class. No outside access is allowed. */
protected:
      /* The members declared as Protected are accessible from
         outside the class BUT only in a class derived from it. */
};


// const with Member Functions
/*
   Specifies that the function will not change any data
   stored in the calling object.
*/
double getWidth() const;
double getHeight() const;
double getArea() const;


// Defining Member Functions
class Rectangle /*...*/ int getHeight() /*...*/
int Rectangle::getHeight() {
      return this->height;
}


// Accessor/Getter
int Rectangle::getHeight() {
      return this->height;
}


// Mutator/Setter
void Rectangle::setHeight(int height) {
      this->height = height;
}


// Accessing an Object's Members
box.setLength(4.8); // Set box's length to 4.8.
double x = box.getWidth(); // Assign box's width to x.
cout << box.getLength(); // Display box's length.
cout << box.getArea(); // Display box's area


// Class Specification File
/* Stores class declarations ex. Rectangle.h c*/


// Copy Constructor
/* Stores class definitions ex. Rectangle.cpp */


// Inline Member Function
/* Class declaration...*/
double getLength() const {
      return this->length;
}


// Default Constructor and Overloading Constructors
ClassName () { // Default constructor
      this->memberVariable = 0;
      this->anotherMemberVariable = 0;
}
ClassName (int memberVariable, int anotherMemberVariable) {
      this->memberVariable = memberVariable;
      this->anothermemberVariable = anotherMemberVariable;
}


// Dynamically Allocated Objects
Rectangle *recPtr;
recPtr = new Rectangle; // Default constructor automatically executed


// Passing Arguments into Constructors
ClassName (int memberVariable, int anotherMemberVariable) {
      this->memberVariable = memberVariable;
      this->anothermemberVariable = anotherMemberVariable;
}
/* ... */
ClassName object(memberVariable, anothermemberVariable);


// Destructors
~ClassName () {
      cout << "ClassName deleted!";
}
/* ... */
ClassName object;
delete object; // Displays "ClassName deleted!"
/*
   Like constructors, destructors have no return type.
   Destructors cannot accept arguments, so they never have a parameter list.
*/


// Arrays of Objects
InventoryItem inventory[3] = {"Hammery", InventoryItem("Wrench", 8.75, 20), "Pliers"};
inventory[2].setUnits(30); // Sets units variable of "Pliers" item to 30


//
//
//  Chapter 14
//  More About Classes
//
//


// Member Initializer Lists
class Something {
private:
      int m_value1;
      double m_value2;
      int *m_value3;
public:
      Something() : m_value1(0), m_value2(0.0), m_Value3(&m_value1) {}
      SomethingElse(int a, double b, int* c) : m_value1(a), m_value2(b), m_Value3(c) {}
}


// Instance and Static Members
/*
   instance variable: a member variable in a class. Each object has its own copy.
   static variable: one variable shared among all objects of a class
   static member function: can be used to access static member variable;
      can be called before any objects are defined
*/
// Tree class
class Tree
{
private:
      static int objectCount; // Static member variable.
public:
      Tree() // Constructor
      { objectCount++; }
      // Accessor function for objectCount
      int getObjectCount() const
      { return objectCount; }
};
      // Definition of the static member variable, written
      // outside the class.
int Tree::objectCount = 0;
#include <iostream>
using namespace std;
int main()
{
      //Define three tree objects
      Tree oak;
      Tree elm;
      Tree pine;
      //Display the number of trees we have
      cout << "We have "<< pine.getObjectCount()
      << " trees in our program!\n";
      return 0;
}


// Static Member Functions
static int getObjectCount() const
{ return objectCount; }
/*
   Static member functions can only access static member data
   Can be called independent of objects:
*/
int num = Tree::getObjectCount();


// Friends of Classes
/*
   Friend: a function or class that is not a member of a class, but has access to
      private members of the class
   A friend function can be a stand-alone function or a member function of
      another class
   It is declared a friend of a class with friend keyword in the function
      prototype
*/
#include <iostream>
using namespace std;
#ifndef BOX_H
#define BOX_H
class Box {
      double width;
public:
      friend void printWidth(Box box);
      void setWidth(double width);
};
#endif
// Member function definition
void Box::setWidth(double width) {
      this->width = width;
}
// Note: printWidth() is not a member function of any class.
void printWidth(Box box) {
      /* Because printWidth() is a friend of Box, it can
      directly access any member of this class */
      cout << "Width of box : " << box.width <<endl;
}


// Copy Constructors
#include <iostream>
using namespace std;
class Line {
public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor
private:
      int *ptr;
};
// Member functions definitions including constructor
Line::Line(int len) {/*...*/}
Line::Line(const Line &obj) {
      cout << "Copy constructor allocating ptr." << endl;
      ptr = new int;
      *ptr = *obj.ptr; // copy the value
}
Line::~Line(void)  {/*...*/}
int Line::getLength( void )  {/*...*/}
void display(Line obj)  {/*...*/}
// Main function for the program
int main() {
      Line line1(10);
      Line line2 = line1; // This calls copy constructor
      return 0;
}


// Implicitly Defined/Default Copy Constructor
/*
    If a class doesn’t have a copy constructor, C++ creates a default copy
    constructor for it.
*/


// Operator Overloading
Set Set::operator+(const Set set) {
    return this->setUnion(set);
}
void Set::operator+(const Set set) {
    this->add(num);
}
Set Set::operator^(const Set set) {
    return this->setIntersection(set);
}


//
//
//  Chapter 15
//  Inheritance and Polymorphism
//
//

// Inheritance
/*
      Base class (or parent): is inherited from
      Derived class (or child): inherits from the base class
      Ex. A poodle (derived class) is a dog (base class).
*/


// Child Components
/*
      An object of the derived class has:
            - all members defined in the child class
            - all members declared in the parent class
      can use:
            - all public members in the child class
            - all public members defined in the parent class
*/


// Protected Class Access
class ClassName {
protected:
      int accessibleOnlyByObjectsOfDerivedClass;
};


// Passing Arguments to Base Class Constructor
Square::Square(int side) : Rectangle(side, side) {/*...*/}


// Redefining Base Class Functions
class BaseClass {
public:
      BaseClass(int var) { this->var = var; }
      int getVar () { return this->var; }
private:
      int var;
};
class DerivedClass : public BaseClass {
public:
      DerivedClass(int var, int anotherVar) : BaseClass (var) { this->anotherVar = anotherVar; }
      int getVar () { return this->var - this->anotherVar; } // Redifined setScore function
private:
      int var;
};


// Virtual Member Function
class BaseClass {
public:
      BaseClass(int var) { this->var = var; }
      virtual int getVar () { return this->var; }
private:
      int var;
};
class DerivedClass : public BaseClass {
public:
      DerivedClass(int var, int anotherVar) : BaseClass (var) { this->anotherVar = anotherVar; }
      virtual int getVar () { return this->var - this->anotherVar; } // Redifined setScore function
private:
      int var;
};
getVar(); // Call the most-derived version of getVar();


// Dynamic Binding
/*
   Dynamic binding means that references are resolved at run time.
   In C++, redefined functions are statically bound and overridden
      functions are dynamically bound.
   So, a virtual function is overridden, and a non-virtual function is
      redefined.
*/


// Virtual Destructor
class Base
{/*Some virtual methods*/};
class Derived : public Base
{
    ~Derived()
    {
        /*Do some important cleanup*/
    }
}
Base *b = new Derived();
// use b
delete b; // Here, b is being deleted from the Derived class.


// Override Keyword
/* The override key word tells the compiler that the function is
   supposed to override a function in the base class. */
class Base
{
      virtual int foo() const;
};
class Derived : Base
{
      virtual int foo()
      {
      // ...
      }
};


// Final Keyword
/*
   When a member function is declared with the final key word, it
   cannot be overridden in a derived class.
*/
class A
{
 void foo() final; // A::foo is overridden and it is the final override
 void bar() final; // Error: non-virtual function cannot be overridden or be final
};


// Abstract Base Class
/* Abstract base class: class that can have no objects. Serves as a
   basis for derived classes that may/will have objects */
class Polygon {
protected:
      int width, height;
public:
      void set_values (int a, int b){
            width=a;
            height=b;
      }
private:
      virtual int area = 0;
};


// Multiple Inheritance
Cube::Cube(int side) : Square(side), RectSolid(side, side, side);
