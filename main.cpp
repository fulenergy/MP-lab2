#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <future>
#include <stdexcept>
using namespace std;

// 1. Main Function

// Q1: Program that prints number of arguments and lists them
void main_function_Q1(int argc, char* argv[]) {
    cout << "Number of arguments: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
}

// Q2:
// main = entry point of program. In Java it is static so JVM can call it without creating an object

// Q3:
// C++: int return type, args can be none or (int argc, char* argv[]), no modifiers, static not required
// Java: void return type, (String[] args), must be public static, JVM handles exit

// Q4:
// C++: return int, 0 = success, non-zero = error
// Java: main returns void, use System.exit(code) for non-zero exit


// 2. Variables

// Q1: Swap without third variable
void variables_Q1() {
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "After swap: a = " << a << ", b = " << b << endl;
}

// Q2:
// Primitive types: stored directly on stack, variable holds value
// Reference types: store address on stack, data in heap (manual delete in C++)

// Q3:
// Scope = region where variable is accessible
// Local scope: inside function. Static/class scope: tied to class and exists for program lifetime

// Q4:
// Statically-typed (C++/Java): type checked at compile-time, must declare types
// Dynamically-typed: type bound at runtime (e.g. Python)


// 3. Control Flow

// Q1: Fibonacci first 10 numbers
void controlflow_Q1() {
    int n1 = 0, n2 = 1, next;
    cout << "Fibonacci: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 1) { cout << n1 << " "; continue; }
        if (i == 2) { cout << n2 << " "; continue; }
        next = n1 + n2;
        n1 = n2;
        n2 = next;
        cout << next << " ";
    }
    cout << endl;
}

// Q2:
// while: checks condition before body
// do-while: executes body once before condition check

// Q3:
// switch: multi-branch. case: match, break: prevent fallthrough, default: fallback

// Q4:
// Short-circuit: && stops if left is false, || stops if left is true
// Useful: if (ptr && ptr->val) avoids null dereference


// 4. Functions / Methods

// Q1: Palindrome
bool isPalindrome(const string& s) {
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

// Q2:
// C++: pass-by-value (copy), pass-by-pointer, pass-by-reference
// Java: everything pass-by-value, but object references are copied.

// Q3:
// Overloading: same name, different parameter list (number/types). Return type alone not enough

// Q4:
// Recursion: function calls itself. Base case = stop condition to avoid infinite loop


// 5. Comments

// Q1 Example comments:
/**
 * Documentation style
 */

// Single-line comment
/* Multi-line comment */

// Q2: Comments improve maintainability and teamwork
// Q3: Systems like Javadoc/Doxygen auto-generate docs from comments
// Q4: Good code is self-documenting, but comments help for complex logic


// 6. Classes

class BankAccount {
    double balance;
public:
    BankAccount(double initial) { balance = (initial >= 0) ? initial : 0; }
    void deposit(double amt) { if (amt > 0) balance += amt; }
    double getBalance() { return balance; }
};

// Q2:
// class = blueprint, object = instance
// Q3:
// public: accessible everywhere, private: only inside class, protected: class + subclasses
// Q4:
// Constructor = initializes object. Default constructor provided if none defined


// 7. Enum

enum class Season { SPRING, SUMMER, AUTUMN, WINTER };

string recommendActivity(Season s) {
    switch (s) {
        case Season::SPRING: return "Plant flowers";
        case Season::SUMMER: return "Go to the beach";
        case Season::AUTUMN: return "Rake leaves";
        case Season::WINTER: return "Build a snowman";
    }
    return "Rest";
}

// Q2: Enums safer and more readable than ints/strings
// Q3: Enums improve type safety and clarity
// Q4: Java enums can have fields/methods, C++ scoped enums are type-safe but lighter


// 8. Inheritance

class Vehicle {
public:
    void startEngine() { cout << "Engine started" << endl; }
};

class Car : public Vehicle {
public:
    void drive() { cout << "Car is driving" << endl; }
};

// Q2:
// is-a = inheritance, has-a = composition
// Q3:
// Overriding: redefine base method. Use virtual/override in C++, @Override in Java
// Q4
// Diamond problem: multiple inheritance ambiguity. C++ solves with virtual inheritance, Java avoids by interfaces


// 9. Mixins / Interfaces

class IStringable {
public:
    virtual string toString() const = 0;
    virtual ~IStringable() = default;
};

class Printable {
public:
    void print(const IStringable& obj) { cout << obj.toString() << endl; }
};

class Book : public IStringable {
    string title, author;
public:
    Book(string t, string a): title(t), author(a) {}
    string toString() const override { return "'" + title + "' by " + author; }
};

// Q2: Mixins/interfaces = code reuse without strict is-a
// Q3: Java default methods in interfaces act like mixins
// Q4: Inheritance = is-a, composition = has-a, mixins = reuse behavior


// 10. Polymorphism

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height): w(width), h(height) {}
    double getArea() const override { return w * h; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius): r(radius) {}
    double getArea() const override { return 3.14159 * r * r; }
};

// Q2:
// Compile-time polymorphism = overloading/templates
// Runtime = overriding + virtual functions
// Q3:
// Abstract class = cannot instantiate, may have implementations. Interface = only contracts
// Q4:
// Interfaces in Java, pure virtual in C++ = polymorphism via contract


// 11. Async Operations

long long calculateSum() {
    long long sum = 0;
    for (long long i = 1; i <= 1000000; i++) sum += i;
    return sum;
}

// Q2: Async solves blocking I/O problems
// Q3: Parallel = true simultaneous, Concurrent = interleaved
// Q4: Future/Promise = handle async result


// 12. Exceptions

void processAge(int age) {
    if (age < 0) throw invalid_argument("Age cannot be negative");
    cout << "Age: " << age << endl;
}

// Q2:
// try = risky code, catch = handle, finally = always run (RAII in C++ ensures cleanup)
// Q3:
// Java has checked (must declare) vs unchecked. C++ doesn’t enforce
// Q4:
// Exceptions separate error handling from normal flow. But can be expensive and misused


// main demo

int main(int argc, char* argv[]) {
    cout << "--- Main Function Q1 ---" << endl;
    main_function_Q1(argc, argv);

    cout << "\n--- Variables Q1 ---" << endl;
    variables_Q1();

    cout << "\n--- Control Flow Q1 ---" << endl;
    controlflow_Q1();

    cout << "\n--- Functions Q1 ---" << endl;
    cout << "madam palindrome? " << (isPalindrome("madam") ? "true" : "false") << endl;

    cout << "\n--- Classes Q1 ---" << endl;
    BankAccount acc(100);
    acc.deposit(50);
    cout << "Balance: " << acc.getBalance() << endl;

    cout << "\n--- Enums Q1 ---" << endl;
    cout << recommendActivity(Season::SUMMER) << endl;

    cout << "\n--- Inheritance Q1 ---" << endl;
    Car c;
    c.startEngine();
    c.drive();

    cout << "\n--- Mixins Q1 ---" << endl;
    Book b("The Hobbit", "Tolkien");
    Printable p;
    p.print(b);

    cout << "\n--- Polymorphism Q1 ---" << endl;
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(10, 5));
    shapes.push_back(make_unique<Circle>(3));
    for (auto& s : shapes) cout << "Area: " << s->getArea() << endl;

    cout << "\n--- Async Q1 ---" << endl;
    future<long long> fut = async(launch::async, calculateSum);
    cout << "Calculating..." << endl;
    cout << "Sum = " << fut.get() << endl;

    cout << "\n--- Exceptions Q1 ---" << endl;
    try {
        processAge(-5);
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
