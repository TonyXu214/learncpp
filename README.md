# learncpp Exercises from https://www.learncpp.com/

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

Inline functions and Variables
- Write the code as part of an existing function (called writing code “in-place” or “inline”).
- When a call to min() is encountered, the CPU must store the address of the current instruction it is executing (so it knows where to return to later) along with the values of various CPU registers (so they can be restored upon returning). Then parameters x and y must be instantiated and then initialized. Then the execution path has to jump to the code in the min() function. When the function ends, the program has to jump back to the location of the function call, and the return value has to be copied so it can be output.
- For functions that are large and/or perform complex tasks, the overhead of the function call is typically insignificant compared to the amount of time the function takes to run. However, for small functions (such as min() above), the overhead costs can be larger than the time needed to actually execute the function’s code! In cases where a small function is called often, using a function can result in a significant performance penalty over writing the same code in-place
- Fortunately, the C++ compiler has a trick that it can use to avoid such overhead cost: **Inline expansion** is a process where a function call is replaced by the code from the called function’s definition
- if the body of the function being expanded takes more instructions than the function call being replaced, then each inline expansion will cause the executable to grow larger. Larger executables tend to be slower (due to not fitting as well in memory caches)
- Modern optimizing compilers make the decision about when functions should be expanded inline
- A function that is declared using the inline keyword is called an **inline function**
```
inline int min(int x, int y) // inline keyword means this function is an inline function
{
    return (x < y) ? x : y;
}
```
- in modern C++, the inline keyword is no longer used to request that a function be expanded inline
- The inline keyword is defined at the wrong level of granularity. We use the inline keyword on a function definition, but inline expansion is actually determined per function call.
- Do not use the inline keyword to request inline expansion for your functions
- In modern C++, the term inline has evolved to mean “multiple definitions are allowed”. Thus, an inline function is one that is allowed to be defined in multiple files.
- Inline functions have two primary requirements:
  - The compiler needs to be able to see the full definition of an inline function in each translation unit where the function is used (a forward declaration will not suffice on its own). The definition can occur after the point of use if a forward declaration is also provided.
  - Every definition for an inline function must be identical, otherwise undefined behavior will result
- The compiler needs to be able to see the full definition of an inline function wherever it is used, and all such definitions must be identical (or undefined behavior will result).
- This is particularly useful for **header-only libraries**, which are one or more header files that implement some capability (no .cpp files are included). Header-only libraries are popular because there are no source files that need to be added to a project to use them and nothing that needs to be linked. You simply #include the header-only library and then can use it
- For the most part, you should not mark your functions or variables as inline unless you are defining them in a header file (and they are not already implicitly inline)
- Avoid the use of the inline keyword unless you have a specific, compelling reason to do so (e.g. you’re defining those functions or variables in a header file).
- C++17 introduces inline variables, which are variables that are allowed to be defined in multiple files

Constexpr and consteval functions
- constexpr keyword, which we used to create compile-time (**symbolic**) constants
- A **constexpr function** is a function whose return value may be computed at compile-time.
- To be eligible for compile-time evaluation, a function must have a constexpr return type and not call any non-constexpr functions when evaluated at compile-time. Additionally, a call to the function must have constexpr arguments
- Constexpr functions can also be evaluated at runtime
  - occurs when args are not constexpr
- a constexpr function that is eligible for compile-time evaluation must be evaluated at compile-time if the return value is used where a constant expression is required. Otherwise, the compiler is free to evaluate the function at either compile-time or runtime.
- Unless you have a specific reason not to, a function that can be made constexpr generally should be made constexpr
- we can force a constexpr function that is eligible to be evaluated at compile-time to actually evaluate at compile-time by ensuring the return value is used where a constant expression is required. This needs to be done on a per-call basis.
- The most common way to do this is to use the return value to initialize a constexpr variable
- C++20 introduces the keyword **consteval**, which is used to indicate that a function must evaluate at compile-time, otherwise a compile error will result. Such functions are called **immediate functions**
- Use consteval if you have a function that must run at compile-time for some reason (e.g. performance).
- The downside of consteval functions is that such functions can’t evaluate at runtime, making them less flexible than constexpr functions, which can do either. Therefore, it would still be useful to have a convenient way to force constexpr functions to evaluate at compile-time (even when the return value is being used where a constant expression is not required), so that we could have compile-time evaluation when possible, and runtime evaluation when we can’t
- This works because consteval functions require constant expressions as arguments -- therefore, if we use the return value of a constexpr function as an argument to a consteval function, the constexpr function must be evaluated at compile-time
- Note that the consteval function returns by value. While this might be inefficient to do at runtime (if the value was some type that is expensive to copy, e.g. std::string), in a compile-time context, it doesn’t matter because the entire call to the consteval function will simply be replaced with the calculated return value
- Because constexpr functions may be evaluated at compile-time, the compiler must be able to see the full definition of the constexpr function at all points where the function is called. A forward declaration will not suffice, even if the actual function definition appears later in the same compilation unit.
- This means that a constexpr function called in multiple files needs to have its definition included into each such file -- which would normally be a violation of the one-definition rule. To avoid such problems, constexpr functions are implicitly inline, which makes them exempt from the one-definition rule.
- As a result, constexpr functions are often defined in header files, so they can be #included into any .cpp file that requires the full definition.
- Consteval functions are also implicitly inline for the same reasons
- The compiler must be able to see the full definition of a constexpr or consteval function, not just a forward declaration.
- Constexpr/consteval functions used in a single source file (.cpp) can be defined in the source file above where they are used.
- Constexpr/consteval functions used in multiple source files should be defined in a header file so they can be included into each source file.
- The parameters of a constexpr function are not constexpr (and thus cannot be used in constant expressions). Such parameters can be declared as const (in which case they are treated as runtime constants), but not constexpr
- However, an exception is made in one case: a constexpr function can pass those parameters as arguments to another constexpr function, and that subsequent constexpr function can be resolved at compile-time. This allows constexpr functions to still be resolved at compile-time when they call other constexpr functions (including themselves recursively)
- Calling a non-constexpr function is allowed so that a constexpr function can do something like this:
```
#include <type_traits> // for std::is_constant_evaluated

constexpr int someFunction()
{
    if (std::is_constant_evaluated()) // if compile-time evaluation
        return someConstexprFcn();    // calculate some value at compile time
    else                              // runtime evaluation
        return someNonConstexprFcn(); // calculate some value at runtime
}
```
- Now consider this variant:
```
constexpr int someFunction(bool b)
{
    if (b)
        return someConstexprFcn();
    else
        return someNonConstexprFcn();
}
```
- This is legal as long as someFunction(false) is never called in a constant expression
- The C++ standard says that a constexpr function must return a constexpr value for at least one set of arguments, otherwise it is technically ill-formed

Introduction to std::string
- To read a full line of input into a string, you’re better off using the std::getline() function instead. std::getline() requires two arguments: the first is std::cin, and the second is your string variable
- C++ also supports input manipulators, which alter the way that input is accepted. The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction.
- When you enter a value using operator>>, std::cin not only captures the value, it also captures the newline character ('\n') that occurs when you hit the enter key. So when we type 2 and then hit enter, std::cin captures the string "2\n" as input. It then extracts the value 2 to variable choice, leaving the newline character behind for later. Then, when std::getline() goes to extract text to name, it sees "\n" is already waiting in std::cin, and figures we must have previously entered an empty string!
- If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace. This needs to be done for each std::getline() call, as std::ws is not preserved across calls
- Using the extraction operator (>>) with std::cin ignores leading whitespace. It stops extracting when encountering non-leading whitespace.
- std::getline() does not ignore leading whitespace unless you use input manipulator std::ws. It stops extracting when encountering a newline
- The length() function isn’t a normal standalone function -- it’s a special type of function that is nested within std::string called a member function.
- Also note that std::string::length() returns an unsigned integral value (most likely of type size_t)
- With normal functions, we call function(object). With member functions, we call object.function()
- Whenever a std::string is initialized, a copy of the string used to initialize it is made. Making copies of strings is expensive, so care should be taken to minimize the number of copies made.
- When a std::string is passed to a function by value, the std::string function parameter must be instantiated and initialized with the argument. This results in an expensive copy. We’ll discuss what to do instead (use std::string_view)
- Do not pass std::string by value, as it makes an expensive copy
- In most cases, use a std::string_view parameter instead
- When a function returns by value to the caller, the return value is normally copied from the function back to the caller. So you might expect that you should not return std::string by value, as doing so would return an expensive copy of a std::string.
  - However, as a rule of thumb, it is okay to return a std::string by value when the expression of the return statement resolves to any of the following:
    - A local variable of type std::string.
    - A std::string that has been returned by value from a function call or operator.
    - A std::string that is created as part of the return statement.
- If returning a C-style string literal, use a std::string_view return type instead
- you can also use the std::ssize() function to get the length of a std::string as a signed integral value
- We can create string literals with type std::string by using a s suffix after the double-quoted string literal
```
    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
```
- If you try to define a constexpr std::string, your compiler will probably generate an error

Introduction to std::string_view
- std::string_view provides read-only access to an existing string (a C-style string, a std::string, or another std::string_view) without making a copy.
- Prefer std::string_view over std::string when you need a read-only string, especially for function parameters.
- A std::string_view object can be initialized with a C-style string, a std::string, or another std::string_view:
- Because std::string makes a copy of its initializer (which is expensive), C++ won’t allow implicit conversion of a std::string_view to a std::string
- However, if this is desired, we have two options:
  - Explicitly create a std::string with a std::string_view initializer (which is allowed, since this will rarely be done unintentionally)
  - Convert an existing std::string_view to a std::string using static_cast
- Assigning a new string to a std::string_view causes the std::string_view to view the new string. It does not modify the prior string being viewed in any way
- We can create string literals with type std::string_view by using a sv suffix after the double-quoted string literal.
- Unlike std::string, std::string_view has full support for constexpr:

std::string_view (part 2)
- std::string is an owner
- An initialized object has no control over what happens to the initialization value after initialization is finished.
- std::string_view is a viewer
- A view is dependent on the object being viewed. If the object being viewed is modified or destroyed while the view is still being used, unexpected or undefined behavior will result.
- A std::string_view that is viewing a string that has been destroyed is sometimes called a **dangling** view
- Return values are temporary objects that are destroyed at the end of the full expression containing the function call. We must either use this return value immediately, or copy it to use later.
- But std::string_view doesn’t make copies. Instead, it creates a view to the temporary return value, which is then destroyed. That leaves our std::string_view dangling (viewing an invalid object), and printing the view results in undefined behavior
- Do not initialize a std::string_view with a std::string literal, as this will leave the std::string_view dangling.
- It is okay to initialize a std::string_view with a C-style string literal or a std::string_view literal. It’s also okay to initialize a std::string_view with a C-style string object, a std::string object, or a std::string_view object, as long as that string object outlives the view.
- When a std::string is modified, all views into that std::string are invalidated, meaning those views are now invalid. Using an invalidated view will result in undefined behavior.
- std::string_view can be used as the return value of a function. However, this is often dangerous.
- Because local variables are destroyed at the end of the function, returning a std::string_view to a local variable will result in the returned std::string_view being invalid, and further use of that std::string_view will result in undefined
- because C-style string literals exist for the entire program, it’s fine to return C-style string literals from a function that has a return type of std::string_view
- If an argument is a temporary that is destroyed at the end of the full expression containing the function call, the returned std::string_view must be used immediately, as it will be left dangling after the temporary is destroyed.
- Because std::string_view is a view, it contains functions that let us modify our view by “closing the curtains”. This does not modify the string being viewed in any way, just the view itself.
  - The remove_prefix() member function removes characters from the left side of the view.
  - The remove_suffix() member function removes characters from the right side of the view.
- Unlike real curtains, once remove_prefix() and remove_suffix() have been called, the only way to reset the view is by reassigning the source string to it again
- This brings up an important use of std::string_view. While std::string_view can be used to view an entire string without making a copy, they are also useful when we want to view a substring without making a copy.
- The ability to view just a substring of a larger string comes with one consequence of note: a std::string_view may or may not be null-terminated
- A C-style string literal and a std::string are always null-terminated.
- A std::string_view may or may not be null-terminated.
- In almost all cases, this doesn’t matter -- a std::string_view keeps track of the length of the string or substring it is viewing, so it doesn’t need the null-terminator. Converting a std::string_view to a std::string will work regardless of whether or not the std::string_view is null-terminated
- If you have a non-null-terminated std::string_view and you need a null-terminated string for some reason, convert the std::string_view into a std::string.

### Chapter 6

Operator precedence and associativity

- the operator’s **associativity** tells the compiler whether to evaluate the operators from left to right or from right to left.
- The C++ standard uses the term **value computation** to mean the execution of operators in an expression to produce a value.
- The precedence and associativity rules generally determine the order of value computation (of operators).
- Operands, function arguments, and subexpressions may be evaluated in any order.
- Ensure that the expressions (or function calls) you write are not dependent on operand (or argument) evaluation order.

Arithmetic operators
- unary operators are operators that only take one operand
- Do not confuse the unary minus operator with the binary subtraction operator
- If either (or both) of the operands are floating point values, the division operator performs floating point division. Floating point division returns a floating point value, and the fraction is kept
- If both of the operands are integers, the division operator performs integer division instead. Integer division drops any fractions and returns an integer value
- Integer division with a divisor of 0 will cause undefined behavior, as the results are mathematically undefined
- The result of dividing by floating point value 0.0 is implementation-defined (meaning the behavior is determined by the compiler/architecture).

Remainder and Exponentiation
- The remainder operator can also work with negative operands. x % y always returns results with the sign of x
- if you’re going to compare the result of a remainder operation, it’s better to compare against 0, which does not have positive/negative number issues
- Prefer to compare the result of the remainder operator (operator%) against 0 if possible
- To do exponents in C++, #include the <cmath> header, and use the pow() function
- Note that the parameters (and return value) of function pow() are of type double

Increment/decrement operators, and side effects
-  Note that the postfix version takes a lot more steps, and thus may not be as performant as the prefix version.
- Favor the prefix versions, as they are more performant and less likely to cause surprises.
- A function or expression is said to have a side effect if it has some observable effect beyond producing a return value
```
x = 5; // the assignment operator has side effect of changing value of x
++x; // operator++ has side effect of incrementing x
std::cout << x; // operator<< has side effect of modifying the state of the console
```
- In many cases, C++ also does not specify when the side effects of operators must be applied. This can lead to undefined behavior in cases where an object with a side effect applied is used more than once in the same statement.
- These problems can generally all be avoided by ensuring that any variable that has a side-effect applied is used no more than once in a given statement
- C++ does not define the order of evaluation for function arguments or the operands of operators.

The comma operator
- The comma operator (,) allows you to evaluate multiple expressions wherever a single expression is allowed. The comma operator evaluates the left operand, then the right operand, and then returns the result of the right operand
- Note that comma has the lowest precedence of all the operators, even lower than assignment. Because of this, the following two lines of code do different things:
```
z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.
```
- Most programmers do not use the comma operator at all, with the single exception of inside for loops, where its use is fairly common
- Avoid using the comma operator, except within for loops.
- In C++, the comma symbol is often used as a separator, and these uses do not invoke the comma operator. Some examples of separator commas
```
void foo(int x, int y) // Separator comma used to separate parameters in function definition
{
    add(x, y); // Separator comma used to separate arguments in function call
    constexpr int z{ 3 }, w{ 5 }; // Separator comma used to separate multiple variables being defined on the same line (don't do this)
}
```

Relational operators and floating point comparisons
- By default, conditions in an if statement or conditional operator (and a few other places) evaluate as Boolean values
- Don’t add unnecessary == or != to conditions. It makes them harder to read without offering any additional value.
- Comparing floating point values using any of the relational operators can be dangerous. This is because floating point values are not precise
- Because even the smallest rounding error will cause two floating point numbers to not be equal, operator== is at high risk for returning false when a true might be expected
- There is one notable exception case to the above: it is okay to compare a low-precision (few significant digits) floating point literal to the same literal value of the same type
```
if (someFcn() == 0.0) // okay if someFcn() returns 0.0 as a literal only
    // do something
```
- if we have a const or constexpr floating point variable that we can guarantee is a literal, it is safe to do a direct comparison
```
constexpr double gravity { 9.8 }
if (gravity == 9.8) // okay if gravity was initialized with a literal
    // we're on earth
```
- Why does this work? Consider the double literal 0.0. This literal has some specific and unique representation in memory
- It is okay to compare a low-precision (few significant digits) floating point literal to the same literal value of the same type.
- The most common method of doing floating point equality involves using a function that looks to see if two numbers are almost the same. If they are “close enough”, then we call them equal. The value used to represent “close enough” is traditionally called **epsilon**
- instead of epsilon being an absolute number, epsilon is now relative to the magnitude of a or b
```
// Return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
```
- One way to avoid this is to use both an absolute epsilon (as we did in the first approach) and a relative epsilon (as we did in Knuth’s approach):
```
// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}
```
- In this algorithm, we first check if a and b are close together in absolute terms, which handles the case where a and b are both close to zero. The absEpsilon parameter should be set to something very small (e.g. 1e-12). If that fails, then we fall back to Knuth’s algorithm, using the relative epsilon.

Logical operators
- If logical NOT is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses.
- In this case, the logical AND operator will go ahead and return false immediately without even evaluating the right operand! This is known as short circuit evaluation, and it is done primarily for optimization purposes.
- Short circuit evaluation may cause Logical OR and Logical AND to not evaluate the right operand. Avoid using expressions with side effects in conjunction with these operators.
- The Logical OR and logical AND operators are an exception to the rule that the operands may evaluate in any order, as the standard explicitly states that the left operand must evaluate first.
- Only the built-in versions of these operators perform short-circuit evaluation. If you overload these operators to make them work with your own types, those overloaded operators will not perform short-circuit evaluation.
- logical AND has higher precedence than logical OR
- When mixing logical AND and logical OR in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intend.

### Chapter 7

Compound statements (blocks)
- A compound statement (also called a block, or block statement) is a group of zero or more statements that is treated by the compiler as if it were a single statement.
- Blocks begin with a { symbol, end with a } symbol, with the statements to be executed being placed in between. Blocks can be used anywhere a single statement is allowed. No semicolon is needed at the end of a block;
```
int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

int main()
{ // start block

    // multiple statements
    int value {}; // this is initialization, not a block
    add(3, 4);

    return 0;

} // end block (no semicolon)
```
- When blocks are nested, the enclosing block is typically called the outer block and the enclosed block is called the inner block or nested block.
- The nesting level (also called the nesting depth) of a function is the maximum number of nested blocks you can be inside at any point in the function (including the outer block)
- Keep the nesting level of your functions to 3 or less. If your function has a need for more nested levels, consider refactoring your function into sub-functions.
- C++ allows us to define our own namespaces via the namespace keyword. Namespaces that you create in your own programs are casually called user-defined namespaces (though it would be more accurate to call them program-defined namespaces).
```
namespace namespaceIdentifier
{
    // content of namespace here
}
```
- A namespace must be defined either in the global scope, or inside another namespace
- The best way to tell the compiler to look in a particular namespace for an identifier is to use the scope resolution operator (::). The scope resolution operator tells the compiler that the identifier specified by the right-hand operand should be looked for in the scope of the left-hand operand.
- The scope resolution operator can also be used in front of an identifier without providing a namespace name (e.g. ::doSomething). In such a case, the identifier (e.g. doSomething) is looked for in the global namespace.
- If an identifier inside a namespace is used and no scope resolution is provided, the compiler will first try to find a matching declaration in that same namespace. If no matching identifier is found, the compiler will then check each containing namespace in sequence to see if a match is found, with the global namespace being checked last
- All declarations within the namespace are considered part of the namespace
- The standard library makes extensive use of this feature, as each standard library header file contains its declarations inside a namespace std block contained within that header file.
- Note that this capability also means you could add your own functionality to the std namespace. Doing so causes undefined behavior most of the time, because the std namespace has a special rule prohibiting extension from user code
- Do not add custom functionality to the std namespace.
- Namespaces can be nested inside other namespaces.
- Because typing the qualified name of a variable or function inside a nested namespace can be painful, C++ allows you to create namespace aliases, which allow us to temporarily shorten a long sequence of namespaces into something shorter
- In general, you should avoid deeply nested namespaces.

Local variables
- Local variables have block scope, which means they are in scope from their point of definition to the end of the block they are defined within
- A variable’s storage duration (usually just called duration) determines what rules govern when and how a variable will be created and destroyed.
- For example, local variables have automatic storage duration, which means they are created at the point of definition and destroyed at the end of the block they are defined in.
- For this reason, local variables are sometimes called automatic variables
- Identifiers have another property named linkage. An identifier’s linkage determines whether other declarations of that name refer to the same object or not.
- Local variables have no linkage, which means that each declaration refers to a unique object.
- Scope and linkage may seem somewhat similar. However, scope defines where a single declaration can be seen and used. Linkage defines whether multiple declarations refer to the same object or not
- Variables should be defined in the most limited scope
- Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.
- A variable’s scope determines where the variable is accessible. Duration defines the rules that govern when a variable is created and destroyed. A variable’s lifetime is the actual time between its creation and destruction.

Introduction to global Variables
- In C++, variables can also be declared outside of a function. Such variables are called global variables
- By convention, global variables are declared at the top of a file, below the includes, in the global namespace
- Identifiers declared in the global namespace have global namespace scope (commonly called global scope, and sometimes informally called file scope), which means they are visible from the point of declaration until the end of the file in which they are declared
- Global variables are created when the program starts, and destroyed when it ends. This is called static duration. Variables with static duration are sometimes called static variables.
- By convention, some developers prefix non-const global variable identifiers with “g” or “g_” to indicate that they are global. This prefix serves several purposes
- Consider using a “g” or “g_” prefix when naming non-const global variables, to help differentiate them from local variables and function parameters.
- Unlike local variables, which are uninitialized by default, variables with static duration are zero-initialized by default.
- Just like local variables, global variables can be constant. As with all constants, constant global variables must be initialized
- what happens when we have a variable inside a nested block that has the same name as a variable in an outer block? When this happens, the nested variable “hides” the outer variable in areas where they are both in scope. This is called name hiding or shadowing
- local variables with the same name as a global variable will shadow the global variable wherever the local variable is in scope:
- because global variables are part of the global namespace, we can use the scope operator (::) with no prefix to tell the compiler we mean the global variable instead of the local variable
- Shadowing of local variables should generally be avoided, as it can lead to inadvertent errors where the wrong variable is used or modified

Internal Linkage
- Global variable and functions identifiers can have either internal linkage or external linkage
- An identifier with internal linkage can be seen and used within a single translation unit, but it is not accessible from other translation units (that is, it is not exposed to the linker)
- This means that if two source files have identically named identifiers with internal linkage, those identifiers will be treated as independent (and do not result in an ODR violation for having duplicate definitions).
- Global variables with internal linkage are sometimes called internal variables
- To make a non-constant global variable internal, we use the static keyword
- Const and constexpr global variables have internal linkage by default (and thus don’t need the static keyword -- if it is used, it will be ignored).
- Functions default to external linkage (which we’ll cover in the next lesson), but can be set to internal linkage via the static keyword
- It’s worth noting that internal objects (and functions) that are defined in different files are considered to be independent entities (even if their names and types are identical), so there is no violation of the one-definition rule.
- In modern C++, use of the static keyword for giving identifiers internal linkage is falling out of favor. Unnamed namespaces can give internal linkage to a wider range of identifiers (e.g. type identifiers), and they are better suited for giving many identifiers internal linkage
- Give identifiers internal linkage when you have an explicit reason to disallow access from other files.
- Consider giving all identifiers you don’t want accessible to other files internal linkage (use an unnamed namespace for this)
- An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program!
- functions have external linkage by default.
- In order to call a function defined in another file, you must place a forward declaration for the function in any other files wishing to use the function. The forward declaration tells the compiler about the existence of the function, and the linker connects the function calls to the actual function definition
- Global variables with external linkage are sometimes called external variables. To make a global variable external (and thus accessible by other files), we can use the extern keyword to do so
- Non-const global variables are external by default (if used, the extern keyword will be ignored)
- To actually use an external global variable that has been defined in another file, you also must place a forward declaration for the global variable in any other files wishing to use the variable. For variables, creating a forward declaration is also done via the extern keyword (with no initialization value)
- Note that the extern keyword has different meanings in different contexts. In some contexts, extern means “give this variable external linkage”. In other contexts, extern means “this is a forward declaration for an external variable that is defined somewhere else”.
- If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.
- Although constexpr variables can be given external linkage via the extern keyword, they can not be forward declared as constexpr. This is because the compiler needs to know the value of the constexpr variable (at compile time). If that value is defined in some other file, the compiler has no visibility on what value was defined in that other file.
- Note that function forward declarations don’t need the extern keyword -- the compiler is able to tell whether you’re defining a new function or making a forward declaration based on whether you supply a function body or not. Variables forward declarations do need the extern keyword to help differentiate uninitialized variables definitions from variable forward declarations (they look otherwise identical)
```
// non-constant
int g_x; // variable definition (can have initializer if desired)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y; // forward declaration (no initializer)
```
```
// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared
```
- Scope determines where a variable is accessible. Duration determines when a variable is created and destroyed. Linkage determines whether the variable can be exported to another file or not.
- Global variables have global scope (a.k.a. file scope), which means they can be accessed from the point of declaration to the end of the file in which they are declared.
- Global variables have static duration, which means they are created when the program is started, and destroyed when it ends.
- Global variables can have either internal or external linkage, via the static and extern keywords respectively.

Why (non-const) global variables are evil
- Use local variables instead of global variables whenever possible.
- Initialization of static variables (which includes global variables) happens as part of program startup, before execution of the main function. This proceeds in two phases
- The first phase is called static initialization. In the static initialization phase, global variables with constexpr initializers (including literals) are initialized to those values. Also, global variables without initializers are zero-initialized
- The second phase is called dynamic initialization. This phase is more complex and nuanced, but the gist of it is that global variables with non-constexpr initializers are initialized.
- Within a single file, for each phase, global variables are generally initialized in order of definition (there are a few exceptions to this rule for the dynamic initialization phase). Given this, you need to be careful not to have variables dependent on the initialization value of other variables that won’t be initialized until later
- Much more of a problem, the order of initialization across different files is not defined
- Dynamic initialization of global variables causes a lot of problems in C++. Avoid dynamic initialization whenever possible.
- As a rule of thumb, any use of a global variable should meet at least the following two criteria: There should only ever be one of the thing the variable represents in your program, and its use should be ubiquitous throughout your program.
- Put all globals in a namespace
- instead of allowing direct access to the global variable, it’s a better practice to “encapsulate” the variable. Make sure the variable can only be accessed from within the file it’s declared in, e.g. by making the variable static or const, then provide external global “access functions” to work with the variable. T
-
