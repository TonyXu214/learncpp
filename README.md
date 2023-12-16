# learncpp
Exercises from https://www.learncpp.com/

## Notes
### Chapter 0
Build Configuration
- Add -ggdb to the command line when debugging and -O2 -DNDEBUG for release builds.
- You can disable compiler extensions by adding the -pedantic-errors flag to the compile command line.
- For warnings, add the following flags to your command line: -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion
  - To treat warnings as errors, add the following flag to your command line: -Werror
- To configure language standard, you can pass compiler flags -std=c++11, -std=c++14, -std=c++17, or -std=c++20 to enable C++11/14/17/20 support respectively

### Chapter 1
Variable assignment and initialization
- =*operator* is called the **assignment** operator
  - assignment copies the value on the right-hand side of the = operator to the variable on the left-hand side of the operator. This is called copy assignment
- When a variable is defined, you can also provide an initial value for the variable at the same time. This is called initialization.
- Initializations
  - int a; // default initialization
  - int b = 5; // copy initialization
    - Copy initialization is also used whenever values are implicitly copied or converted, such as when passing arguments to a function by value, returning from a function by value, or catching exceptions by value.
  - int c(6); // direct initialization
  - int d {7}; // direct list initialization
    - it disallows “narrowing conversions”
    - Prefer direct list initialization (or value initialization) for initializing your variables.
  - int e = {8}; // copy list initialization
  - int f {}; // value initialization
    -  In most cases, value initialization will initialize the variable to zero (or empty, if that’s more appropriate for a given type). In such cases where zeroing occurs, this is called zero initialization.
- Initialization gives a variable an initial value at the point when it is created. Assignment gives a variable a value at some point after the variable is created.
- Default initialization is when a variable initialization has no initializer (e.g. int x;). In most cases, the variable is left with an indeterminate value.
- Value initialization is when a variable initialization has an empty brace (e.g. int x{};). In most cases this will perform zero-initialization

Introduction to iostream: cout, cin, and endl
- no notes

Uninitialized variables and undefined behavior
- Initialized = The object is given a known value at the point of definition.
- Assignment = The object is given a known value beyond the point of definition.
- Uninitialized = The object has not been given a known value yet.
- Using the value from an uninitialized variable is our first example of undefined behavior. **Undefined behavior** (often abbreviated UB) is the result of executing code whose behavior is not well-defined by the C++ language. In this case, the C++ language doesn’t have any rules determining what happens if you use the value of a variable that has not been given a known value.
- **Implementation-defined** behavior means the behavior of some syntax is left up to the implementation (the compiler) to define. Such behaviors must be consistent and documented, but different compilers may produce different results.

Keywords and naming identifiers
- As a reminder, the name of a variable (or function, type, or other kind of item) is called an identifier.

Whitespace and basic formatting

Introduction to literals and operators
- A "literal" (also known as a literal constant) is a fixed value that has been inserted directly into the source code
- A literal’s value is placed directly in the executable, and the executable itself can’t be changed after it is created. A variable’s value is placed in memory, and the value of memory can be changed while the executable is running.
- e.g. `int x {5}`; The compiler will generate code that copies the literal value 5 into whatever memory location is given to x
- Literals are values that are inserted directly into the source code. These values usually appear directly in the executable code (unless they are optimized out).
- Objects and variables represent memory locations that hold values. These values can be fetched on demand.
- for operators that are symbols, it is common to append the operator’s symbol to the word operator.
- An operator (or function) that has some observable effect beyond producing a return value is said to have a **side effect**. For example, when x = 5 is evaluated, the assignment operator has the side effect of assigning the value 5 to variable x
- Operators with side effects are usually called for the behavior of the side effect rather than for the return value (if any) those operators produce

Expressions
- An expression is a combination of literals, variables, operators, and function calls that calculates a single value. The process of executing an expression is called evaluation, and the single value produced is called the result of the expression.
- As you can see, literals evaluate to their own values. Variables evaluate to the value of the variable. Operators (such as operator+) use their operands to evaluate to some other value. We haven’t covered function calls yet, but in the context of an expression, function calls evaluate to whatever value the function returns.
- expressions cannot be executed by themselves -- they must exist as part of a statement.
- An expression statement is a statement that consists of an expression followed by a semicolon
- When an expression is used in an expression statement, any return value generated by the expression is discarded
- Simplifying a bit, a subexpression is an expression used as an operand
- A full expression is an expression that is not a subexpression
- In casual language, a compound expression is an expression that contains two or more uses of operators

### Chapter 2

Introduction to functions
- A function call is an expression that tells the CPU to interrupt the current function and execute another function. The CPU “puts a bookmark” at the current point of execution, and then calls (executes) the function named in the function call. When the called function ends, the CPU returns back to the point it bookmarked, and resumes execution.
- Nested functions are not supported
- return value is copied from the function back to the caller. This process is called return by value.
- When the program is executed, the operating system makes a function call to main. Execution then jumps to the top of main. The statements in main are executed sequentially. Finally, main returns an integer value (usually 0), and your program terminates. The return value from main is sometimes called a status code (also sometimes called an exit code, or rarely a return code), as it is used to indicate whether the program ran successfully or not.
- By definition, a status code of 0 means the program executed successfully.
- A function that returns a value is called a value-returning function. A function is value-returning if the return type is anything other than void

Function return values (value-returning functions)

Void functions (non-value returning functions)
- Returning a value from a void function is a compile error

Introduction to function parameters and arguments
- A function parameter is a variable used in the header of a function. Function parameters work almost identically to variables defined inside the function, but with one difference: they are initialized with a value provided by the caller of the function.
- When a function is called, all of the parameters of the function are created as variables, and the value of each of the arguments is copied into the matching parameter (using copy initialization). This process is called pass by value. Function parameters that utilize pass by value are called value parameters
- In certain cases, you will encounter functions that have parameters that are not used in the body of the function. These are called unreferenced parameters.
- In a function definition, the name of a function parameter is optional. Therefore, in cases where a function parameter needs to exist but is not used in the body of the function, you can simply omit the name. A parameter without a name is called an unnamed parameter

Introduction to local scope
- Variables defined inside the body of a function are called local Variables
- Function parameters are also generally considered to be local Variables
- Local variables are destroyed in the opposite order of creation at the end of the set of curly braces in which it is defined
- an object’s lifetime is defined to be the time between its creation and destruction. Note that variable creation and destruction happen when the program is running (called runtime), not at compile time. Therefore, lifetime is a runtime property
- An identifier’s scope determines where the identifier can be seen and used within the source code. When an identifier can be seen and used, we say it is in scope. When an identifier can not be seen, we can not use it, and we say it is out of scope. Scope is a compile-time property, and trying to use an identifier when it is not in scope will result in a compile error.
- Local variables defined in one function are also not in scope in other functions that are called.
- An identifier is out of scope anywhere it cannot be accessed within the code. In the example above, the identifier x is in scope from its point of definition to the end of the main function. The identifier x is out of scope outside of that code region.
- The term “going out of scope” is typically applied to objects rather than identifiers. We say an object goes out of scope at the end of the scope (the end curly brace) in which the object was instantiated. In the example above, the object named x goes out of scope at the end of the function main.
- A local variable’s lifetime ends at the point where it goes out of scope, so local variables are destroyed at this point.
- Note that not all types of variables are destroyed when they go out of scope. We’ll see examples of these in future lessons.
- the best practice is that local variables inside the function body should be defined as close to their first use as reasonable:

Forward declarations and definitions
- When addressing compilation errors or warnings in your programs, resolve the first issue listed and then compile again.
- A forward declaration allows us to tell the compiler about the existence of an identifier before actually defining the identifier.
- To write a forward declaration for a function, we use a function declaration statement
- However, if a forward declaration is made and the function is called, but the program never defines the function, the program will compile okay, but the linker will complain that it can’t resolve the function call.
- However, forward declarations can also be used with other identifiers in C++, such as variables and types
- A declaration tells the compiler about the existence of an identifier and its associated type information.
- A definition is a declaration that actually implements (for functions and types) or instantiates (for variables) the identifier.
- In C++, all definitions are declarations. Therefore int x; is both a definition and a declaration.
- Declarations that aren’t definitions are called pure declarations
- The one definition rule (or ODR for short) is a well-known rule in C++
  - Within a file, each function, variable, type, or template can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
    - causes compilation error
  - Within a program, each function or variable can only have one definition. This rule exists because programs can have more than one file (we’ll cover this in the next lesson). Functions and variables not visible to the linker are excluded from this rule
    - causes linker error
  - Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical.
    - causes undefined behavior
- A function prototype is a declaration statement that includes a function’s name, return type, parameter types, and optionally the parameter names

Programs with multiple code files

