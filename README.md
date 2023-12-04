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


