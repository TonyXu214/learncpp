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
- if a definition exists in the same file, the compiler will connect the use of the identifier to its definition
- if a definition exists in a different file (and is visible to the linker), the linker will connect the use of the identifier to its definition
- the linker will issue an error indicating that it couldn’t find a definition for the identifier
- If two identical identifiers are introduced into the same program in a way that the compiler or linker can’t tell them apart, the compiler or linker will produce an error. This error is generally referred to as a naming collision

Naming collisions and an introduction to namespaces
- A namespace is a region that allows you to declare names inside of it for the purpose of disambiguation. The namespace provides a scope region (called namespace scope) to the names declared inside of it -- which simply means that any name declared inside the namespace won’t be mistaken for identical names in other scopes
- In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly defined namespace called the global namespace (sometimes also called the global scope).
- Only declarations and definitions can appear in a namespace. this also means that other types of statements (such as expression statements) cannot be placed in the global namespace.
  - executable statements are not allowed in the global namespace
- The :: symbol is an operator called the scope resolution operator. The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. If no identifier to the left of the :: symbol is provided, the global namespace is assumed.
- When an identifier includes a namespace prefix, the identifier is called a qualified name
- A using directive allows us to access the names in a namespace without using a namespace prefix

Introduction to the preprocessor
- prior to compilation, each code (.cpp) file goes through a preprocessing phase
- the preprocessor does have one very important role: it is what processes #include directives
- When the preprocessor has finished processing a code file, the result is called a translation unit
- The entire process of preprocessing, compiling, and linking is called translation.
- Preprocessor directives (often just called directives) are instructions that start with a # symbol and end with a newline (NOT a semicolon)
- When you #include a file, the preprocessor replaces the #include directive with the contents of the included file
- The #define directive can be used to create a macro. In C++, a macro is a rule that defines how input text is converted into replacement output text.
- There are two basic types of macros: object-like macros, and function-like macros.
- Function-like macros act like functions, and serve a similar purpose. Their use is generally considered unsafe, and almost anything they can do can be done by a normal function.
- Object-like macros can be defined in one of two ways:
```
#define identifier
#define identifier substitution_text
```
- preprocessor directives (not statements), note that neither form ends with a semicolon.
- When the preprocessor encounters this directive, any further occurrence of the identifier is replaced by substitution_text. The identifier is traditionally typed in all capital letters, using underscores to represent spaces.
- The conditional compilation preprocessor directives allow you to specify under what conditions something will or won’t compile
  - The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has been previously `#defined`
- Object-like macros don’t affect other preprocessor directives
- This means that directives are only valid from the point of definition to the end of the file in which they are defined.

Header Files
- The other type of file is called a header file. Header files usually have a .h extension, but you will occasionally see them with a .hpp extension or no extension at all. The primary purpose of a header file is to propagate declarations to code (.cpp) files
- Unlike source files, header files should not be added to your compile command (they are implicitly included by #include statements and compiled as part of your source files).
- Header files are often paired with code files, with the header file providing forward declarations for the corresponding code file.
- In C++, it is a best practice for code files to #include their paired header file (if one exists). In the example above, add.cpp includes add.h.
- This allows the compiler to catch certain kinds of errors at compile time instead of link time.
- angled brackets vs double quotes helps give the preprocessor a clue as to where it should look for header files
- When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t write ourselves. The preprocessor will search for the header only in the directories specified by the include directories. The include directories are configured as part of your project/IDE settings/compiler settings, and typically default to the directories containing the header files that come with your compiler and/or OS. The preprocessor will not search for the header file in your project’s source code directory.
- When we use double-quotes, we’re telling the preprocessor that this is a header file that we wrote. The preprocessor will first search for the header file in the current directory. If it can’t find a matching header there, it will then search the include directories.
- When including a header file from the standard library, use the version without the .h extension if it exists.
- If a header file without a .h extension declares names into the global namespace, avoid those names, as they may not be available in the global namespace on other compilers. Prefer the names declared in the std namespace instead.
- Using g++, you can use the -I option to specify an alternate include directory:
  - `g++ -o main -I/source/includes main.cpp`
- When your code file #includes the first header file, you’ll also get any other header files that the first header file includes (and any header files those include, and so on). These additional header files are sometimes called transitive includes, as they’re included implicitly rather than explicitly
- Unfortunately, there is no easy way to detect when your code file is accidentally relying on content of a header file that has been included by another header file.
- To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows:
  - The paired header file
  - Other headers from your project
  - 3rd party library headers
  - Standard library headers
- The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).
- That way, if one of your user-defined headers is missing an #include for a 3rd party library or standard library header, it’s more likely to cause a compile error so you can fix it.
- Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.

Header guards
- `#pragma once` serves the same purpose as header guards
- Duplicate declarations are fine -- but even if your header file is composed of all declarations (no definitions) it’s still a best practice to include header guards.
- Note that header guards do not prevent the contents of a header file from being copied (once) into separate project files.
- When including headers, use angled brackets when including system headers (e.g. those in the C++ standard library), and use double quotes when including user-defined headers (the ones you write)


### Chapter 3

Syntax and semantic errors

The debugging process

A strategy for debugging

Basic debugging tactics
- When printing information for debugging purposes, use std::cerr instead of std::cout
- When adding temporary debug statements, it can be helpful to not indent them

More debugging tactics
- One way to make it easier to disable and enable debugging throughout your program is to make your debugging statements conditional using preprocessor directives

Using an integrated debugger: Stepping
- If you’re compiling your project using a release configuration instead, the functionality of the debugger may not work correctly (e.g. when you try to step into your program, it will just run the program instead).
- To ensure that all output from std::cout is output immediately, you can temporarily add the following statement to the top of your main() function:
```
std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
```
- If you don’t want to continually add/remove/comment/uncomment the above, you can wrap the statement in a conditional compilation preprocessor directive
```
#ifdef DEBUG
std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
#endif
```


Using an integrated debugger: Running and breakpoints

Using an integrated debugger: Watching variables
- The watch window is a window where you can add variables you would like to continually inspect, and these variables will be updated as you step through your program.

Using an integrated debugger: The call stack
- The call stack is a list of all the active functions that have been called to get to the current point of execution.

Finding issues before they become problems
- Defensive programming is a practice whereby the programmer tries to anticipate all of the ways the software could be misused, either by end-users, or by other developers (including the programmer themselves) using the code
- One common method of doing constraint based testing is via assert and static_assert,
- Programmers tend to make certain kinds of common mistakes, and some of those mistakes can be discovered by programs trained to look for them. These programs, generally known as static analysis tools (sometimes informally called linters) are programs that analyze your code to identify specific semantic issues (in this context, static means that these tools analyze the source code)
- You already have one static analysis tool at your disposal -- your compiler! In addition to ensuring your program is syntactically correct, most modern C++ compilers will do some light static analysis to identify some common problems
- Use a static analysis tool on your programs to help find areas where your code is non-compliant with best practices.

### Chapter 4

Introduction to fundamental data types
- To recap briefly, computers have random access memory (RAM) that is available for programs to use. When a variable is defined, a piece of that memory is set aside for that variable.
- Memory is organized into sequential units called **memory addresses** (or addresses for short).
- each bit does not get its own unique memory address. This is because the number of memory addresses is limited, and the need to access data bit-by-bit is rare. Instead, each memory address holds 1 byte of data. A byte is a group of bits that are operated on as a unit. The modern standard is that a byte is comprised of 8 sequential bits.
- Because all data on a computer is just a sequence of bits, we use a **data type** (often called a “type” for short) to tell the compiler how to interpret the contents of memory in some meaningful way.
- When we declare a variable as an integer, we are telling the compiler “the piece of memory that this variable uses is going to be interpreted as an integer value”.
- When you give an object a value, the compiler and CPU take care of encoding your value into the appropriate sequence of bits for that data type, which are then stored in memory
- C++ comes with built-in support for many different data types. These are called fundamental data types, but are often informally called basic types, primitive types, or built-in types.
- C++ also supports a number of other more complex types, called compound types.
- In C++, strings aren’t a fundamental type (they’re a compound type).
- Many of the types defined in newer versions of C++ (e.g. std::nullptr_t) use a _t suffix. This suffix means “type”, and it’s a common nomenclature applied to modern types
- The term integral means “like an integer”. Most often, integral is used as part of the term “integral type”, which includes the broader set of types that are stored in memory as integers, even though their behaviors might vary (which we’ll see later in this chapter when we talk about the character types). This includes bool, the integer types, and all the various character types.

Void
- void means “no type”
- Void is our first example of an incomplete type. An incomplete type is a type that has been declared but not yet defined
- The compiler knows about the existence of such types, but does not have enough information to determine how much memory to allocate for objects of that type. void is intentionally incomplete since it represents the lack of a type, and thus cannot be defined.
- Incomplete types can not be instantiated:
```
void value; // won't work, variables can't be defined with incomplete type void
```
- void is used to indicate that a function does not return a value
- If you use a return statement to try to return a value in such a function, a compile error will result

Object sizes and the sizeof operator
- The amount of memory that an object uses is based on its data type
- When we access some variable x, the compiler knows how many bytes of data to retrieve (based on the type of variable x)
- To generalize, an object with n bits (where n is an integer) can hold 2n (2 to the power of n, also commonly written 2^n) unique values
- `sizeof` does not include dynamically allocated memory used by an object. We discuss dynamic memory allocation in a future lesson.

Signed integers
- By default, integers in C++ are signed, which means the number’s sign is stored as part of the number. Therefore, a signed integer can hold both positive and negative numbers (and 0).
- In binary representation, a single bit (called the sign bit) is used to store the sign of the number. The non-sign bits (called the magnitude bits) determine the magnitude of the number.
- We call the set of specific values that a data type can hold its range. The range of an integer variable is determined by two factors: its size (in bits), and whether it is signed or not.
- By definition, an 8-bit signed integer has a range of -128 to 127.
- n-bit signed variable has a range of -(2^(n-1)) to 2^(n-1)-1.
- The C++20 standard makes this blanket statement: “If during the evaluation of an expression, the result is not mathematically defined or not in the range of representable values for its type, the behavior is undefined”. Colloquially, this is called overflow.
- When doing division with two integers (called integer division), C++ always produces an integer result. Since integers can’t hold fractional values, any fractional portion is simply dropped (not rounded!).

Unsigned integers, and why to avoid them
- Unsigned integers are integers that can only hold non-negative whole numbers
- To define an unsigned integer, we use the unsigned keyword. By convention, this is placed before the type
- Oddly, the C++ standard explicitly says “a computation involving unsigned operands can never overflow”. This is contrary to general programming consensus that integer overflow encompasses both signed and unsigned use cases (cite). Given that most programmers would consider this overflow, we’ll call this overflow despite the C++ standard’s statements to the contrary.
- If an unsigned value is out of range, it is divided by one greater than the largest number of the type, and only the remainder kept
- First, with signed values, it takes a little work to accidentally overflow the top or bottom of the range because those values are far from 0. With unsigned numbers, it is much easier to overflow the bottom of the range, because the bottom of the range is 0, which is close to where the majority of our values are
- Second, and more insidiously, unexpected behavior can result when you mix signed and unsigned integers. In C++, if a mathematical operation (e.g. arithmetic or comparison) has one signed integer and one unsigned integer, the signed integer will usually be converted to an unsigned integer

Fixed-width integers and size_t
- C99 defined a set of fixed-width integers (in the stdint.h header) that are guaranteed to be the same size on any architecture.
- most compilers define and treat std::int8_t and std::uint8_t (and the corresponding fast and least fixed-width types) identically to types signed char and unsigned char respectively. This means these 8-bit types may (or may not) behave differently than the rest of the fixed-width types, which can lead to errors.
- there is little consensus on integral best practices, Our stance is that it’s better to be correct than fast, and better to fail at compile time than runtime. Therefore, if you need an integral type with a fixed size, we recommend avoiding the fast/least types in favor of the fixed-width types.
- The answer is that sizeof (and many functions that return a size or length value) return a value of type std::size_t. std::size_t is defined as an unsigned integral type, and it is typically used to represent the size or length of objects.
- Therefore, the largest object creatable on a system has a size (in bytes) equal to the largest value std::size_t can hold

Introduction to scientific notation

Floating point numbers
- A floating point type variable is a variable that can hold a number with a fractional component, such as 4320.0, -3.33, or 0.01226
- The floating part of the name floating point refers to the fact that the decimal point can “float” -- that is, it can support a variable number of digits before and after the decimal point
- When using floating point literals, always include at least one decimal place (even if the decimal is 0). This helps the compiler understand that the number is a floating point number and not an integer
- Always make sure the type of your literals match the type of the variables they’re being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.
- The precision of a floating point type defines how many significant digits it can represent without information loss
- When outputting floating point numbers, std::cout has a default precision of 6 -- that is, it assumes all floating point variables are only significant to 6 digits (the minimum precision of a float), and hence it will truncate anything after that
- Output manipulators alter how data is output, and are defined in the iomanip header
- Output manipulators (and input manipulators) are sticky -- meaning if you set them, they will remain set
- When precision is lost because a number can’t be stored precisely, this is called a rounding error
- Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.
- Floating point numbers are tricky to work with due to non-obvious differences between binary (how data is stored) and decimal (how we think) numbers. Consider the fraction 1/10. In decimal, this is easily represented as 0.1, and we are used to thinking of 0.1 as an easily representable number with 1 significant digit. However, in binary, decimal value 0.1 is represented by the infinite sequence: 0.00011001100110011…
- mathematical operations (such as addition and multiplication) tend to make rounding errors grow. So even though 0.1 has a rounding error in the 17th significant digit, when we add 0.1 ten times, the rounding error has crept into the 16th significant digit. Continued operations would cause this error to become increasingly significant.
- Rounding errors aren’t the exception -- they’re the norm.

Introduction to if statements
- A condition (also called a conditional expression) is an expression that evaluates to a Boolean value.
- The equality operator (==) is used to test whether two values are equal. Operator== returns true if the operands are equal, and false if they are not.
- The less than operator (<) is used to test whether one value is less than another. Similarly, the greater than operator (>) is used to test whether one value is greater than another
- non-zero values get converted to Boolean true, and zero-values get converted to Boolean false

Chars
- The char data type was designed to hold a single character. A character can be a single letter, number, symbol, or whitespace.
- The char data type is an integral type, meaning the underlying value is stored as an integer. Similar to how a Boolean value 0 is interpreted as false and non-zero is interpreted as true, the integer stored by a char variable are intepreted as an ASCII character.

Introduction to type conversion and static_cast
- In most cases, C++ will allow us to convert values of one fundamental type to another fundamental type. The process of converting a value from one type to another type is called `type conversion`.
- When the compiler does type conversion on our behalf without us explicitly asking, we call this `implicit type conversion`
- Even though it is called a conversion, a type conversion does not actually change the value or type of the value being converted. Instead, the value to be converted is used as input, and the conversion results in a new value of the target type (via direct initialization)
- Type conversion uses direct initialization to produce a new value of the target type from a value of a different type
- Explicit type conversion allow us (the programmer) to explicitly tell the compiler to convert a value from one type to another type, and that we take full responsibility for the result of that conversion (meaning that if the conversion results in the loss of value, it’s our fault).
- To perform an explicit type conversion, in most cases we’ll use the static_cast operator. The syntax for the static cast looks a little funny:
```
static_cast<new_type>(expression)
```
- Whenever you see C++ syntax (excluding the preprocessor) that makes use of angled brackets (<>), the thing between the angled brackets will most likely be a type. This is typically how C++ deals with code that need a parameterized type.
- It’s worth noting that the argument to static_cast evaluates as an expression. When we pass in a variable, that variable is evaluated to produce its value, and that value is then converted to the new type. The variable itself is not affected by casting its value to a new type.
- The static_cast operator doesn’t do any range checking, so if you cast a value to a type whose range doesn’t contain that value, undefined behavior will result.

### Chapter 5

Constant variables (named constants)
- Named constants are constant values that are associated with an identifier. These are also sometimes called symbolic constants, or occasionally just constants.
- Literal constants are constant values that are not associated with an identifier
- Const variables must be initialized when you define them, and then that value can not be changed via assignment:
```
    const double gravity; // error: const variables must be initialized
    gravity = 9.9;        // error: const variables can not be changed
```
- Note that const variables can be initialized from other variables (including non-const ones)
- Function parameters can be made constants via the const keyword
```
void printInt(const int x)
{
    std::cout << x << '\n';
}
```
- Don’t use const when passing by value.
- we’ll talk about two other ways to pass arguments to functions: pass by reference, and pass by address. When using either of these methods, proper use of const is important.
- A function’s return value may also be made const
```
const int getValue()
{
    return 5;
}
```
- For fundamental types, the const qualifier on a return type is simply ignored
- Don’t use const when returning by value
- object-like macros with substitution text are also named constants
- Prefer constant variables to preprocessor macros
- Constant variables have none of these problems: they follow normal scoping rules, can be seen by the compiler and debugger, and behave consistently (vs. preprocessor macros)
- Prefer constant variables over object-like macros with substitution text
- A type qualifier (sometimes called a qualifier for short) is a keyword that is applied to a type that modifies how that type behaves. The const used to declare a constant variable is called a const type qualifier (or const qualifier for short).
- As of C++23, C++ only has two type qualifiers: const and volatile

Constant expressions, compile-time const, and runtime const
- as-if rule says that the compiler can modify a program however it likes in order to produce more optimized code, so long as those modifications do not affect a program’s “observable behavior”.
- A **constant expression** is an expression that can be evaluated by the compiler at compile-time. To be a constant expression, all the values in the expression must be known at compile-time (and all the operators and functions called must support compile-time evaluation)
- Note that the expression std::cout << x is not a constant expression, because our program can’t output values to the console at compile-time. So this expression will always evaluate at runtime. An expression that must be evaluated at runtime is sometimes called a **runtime expression**
- A compile-time constant is a constant whose value is known at compile-time. Literals (e.g. ‘1’, ‘2.3’, and “Hello, world!”) are one type of compile-time constant
- A const variable is a compile-time constant if its initializer is a constant expression
```
	const int x { 3 };  // x is a compile-time const
	const int y { 4 };  // y is a compile-time const

	const int z { x + y }; // x + y is a constant expression, so z is compile-time constant
```
- Runtime constants are constants whose initialization values can’t be determined until runtime.
- Compile-time constants can be used in constant expressions and allow for better optimization.
- Runtime constants can only be used in non-constant expressions. Their primary use is to ensure an object’s value is not modified.

Constexpr Variables
```
int x { 5 };       // not const at all
const int y { x }; // obviously a runtime const (since initializer is non-const)
const int z { 5 }; // obviously a compile-time const (since initializer is a constant expression)
const int w { getValue() }; // not obvious whether this is a runtime or compile-time const
```
- A **constexpr** (which is short for “constant expression”) variable can only be a compile-time constant
- If the initialization value of a constexpr variable is not a constant expression, the compiler will error
- Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
- Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const
- Caveat: In the future we will discuss some types that are not currently compatible with constexpr (including std::string, std::vector, and other types that use dynamic memory allocation). For constant objects of these types, use const instead
- Normal function calls are evaluated at runtime, with the supplied arguments being used to initialize the function’s parameters. This means const function parameters are treated as runtime constants, even when the supplied argument is a compile-time constant
- Because constexpr objects must be initialized with a compile-time constant (not a runtime constant), function parameters cannot be declared as constexpr
- The compiler is only required to evaluate constant expressions at compile-time in contexts that require a constant expression (such as the initializer of a compile-time constant):
```
constexpr int x { 3 + 4 }; // 3 + 4 will always evaluate at compile time
const int x { 3 + 4 };     // 3 + 4 will always evaluate at compile time
int x { 3 + 4 }; // 3 + 4 may evaluate at compile-time or runtime
```
- The answer is generally “yes”. Compilers have long been able to optimize constant subexpressions, even when the full expression is a runtime expression. This optimization process is called “constant folding”.
```
std::cout << 3 + 4 << '\n'; // this is a runtime expression but 3 + 4 may still get optimized at compile time
```

Literal
- Literals are sometimes called **literal constants** because their meaning cannot be redefined (5 always means the integral value 5)
- Just like objects have a type, all literals have a type. The type of a literal is deduced from the literal’s value. For example, a literal that is a whole number (e.g. 5) is deduced to be of type int
- If the default type of a literal is not as desired, you can change the type of a literal by adding a suffix
- Most of the suffixes are not case sensitive. Because lower-case L can look like numeric 1 in some fonts, some developers prefer to use upper-case literals
- Unlike most other literals (which are values, not objects), C-style string literals are const objects that are created at the start of the program and are guaranteed to exist for the entirety of the program
- Unlike C-style string literals, std::string and std::string_view create temporary objects. These temporary objects must be used immediately, as they are destroyed at the end of the full expression in which they are created
- Avoid magic numbers in your code (use constexpr variables instead)

The conditional operator
- The `conditional operator` (?:) (also sometimes called the arithmetic if operator) is a ternary operator (an operator that takes 3 operands).
- Parenthesize the entire conditional operator when used in a compound expression.
- For readability, parenthesize the condition if it contains any operators (other than the function call operator)
- To comply with C++’s type checking rules, one of the following must be true:
  - The type of the second and third operand must match.
  - The compiler must be able to find a way to convert one or both of the second and third operands to matching types. The conversion rules the compiler uses are fairly complex and may yield surprising results in some cases

