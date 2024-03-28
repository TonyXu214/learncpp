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

Sharing global constants across multiple files (using inline variables)
- The term “optimizing away” refers to any process where the compiler optimizes the performance of your program by removing things in a way that doesn’t affect the output of your program. For example, lets say you have some const variable x that’s initialized to value 4. Wherever your code references variable x, the compiler can just replace x with 4 (since x is const, we know it won’t ever change to a different value) and avoid having to create and initialize a variable altogether.
- We use const instead of constexpr in this method because constexpr variables can’t be forward declared, even if they have external linkage. This is because the compiler needs to know the value of the variable at compile time, and a forward declaration does not provide this information.
- In order for variables to be usable in compile-time contexts, such as array sizes, the compiler has to see the variable’s definition (not just a forward declaration).
- prefer defining your constants in a header file (either per the prior section, or per the next section)
- Constexpr functions are implicitly inline, but constexpr variables are not implicitly inline.
- If you need global constants and your compiler is C++17 capable, prefer defining inline constexpr global variables in a header file.
- Use std::string_view for constexpr strings.

Static local variables
- Using the static keyword on a local variable changes its duration from automatic duration to static duration. This means the variable is now created at the start of the program, and destroyed at the end of the program (just like a global variable). As a result, the static variable will retain its value even after it goes out of scope!
- Static local variables with a non-constexpr initializer are reinitialized the first time the variable definition is encountered.
- Static variables offer some of the benefit of global variables (they don’t get destroyed until the end of the program) while limiting their visibility to block scope. This makes them easier to understand and safer to use even if you change their values regularly.
- Initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls.
- Static local variables can be made const (or constexpr). One good use for a const static local variable is when you have a function that needs to use a const value, but creating or initializing the object is expensive (e.g. you need to read the value from a database)
- Avoid static local variables unless the variable never needs to be reset.

Scope, duration, and linkage summary
- When used as part of an identifier declaration, the static and extern keywords are called storage class specifiers
<img width="1448" alt="Screenshot 2024-01-11 at 10 40 50 PM" src="https://github.com/TonyXu214/learncpp/assets/13933543/d65edac7-7657-486d-b9c9-cdda7981de52">
<img width="1337" alt="Screenshot 2024-01-11 at 10 40 59 PM" src="https://github.com/TonyXu214/learncpp/assets/13933543/065aa2f9-e5d8-493f-9a2f-31a537104ece">

Using declarations and using directives
- A **qualified name** is a name that includes an associated scope. Most often, names are qualified with a namespace using the scope resolution operator (::)
```
std::cout // identifier cout is qualified by namespace std
::foo // identifier foo is qualified by the global namespace
class C; // some class

C::s_member; // s_member is qualified by class C
obj.x; // x is qualified by class object obj
ptr->y; // y is qualified by pointer to class object ptr
```
- An unqualified name is a name that does not include a scoping qualifier
- A **using declaration** allows us to use an unqualified name (with no scope) as an alias for a qualified name
- The using-declaration using std::cout; tells the compiler that we’re going to be using the object cout from the std namespace. So whenever it sees cout, it will assume that we mean std::cout. If there’s a naming conflict between std::cout and some other use of cout, std::cout will be preferred
- a **using directive** imports all of the identifiers from a namespace into the scope of the using-directive.
- Avoid using-directives (particularly using namespace std;), except in specific circumstances (such as using namespace std::literals to access the s and sv literal suffixes)

Unnamed and inline namespaces
- An unnamed namespace (also called an anonymous namespace) is a namespace that is defined without a name, like so:
```
namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}
```
- All content declared in an unnamed namespace is treated as if it is part of the parent namespace
- the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated as if they have internal linkage, which means that the content of an unnamed namespace can’t be seen outside of the file in which the unnamed namespace is defined.
- For functions, this is effectively the same as defining all functions in the unnamed namespace as static functions. The following program is effectively identical to the one above:
```
#include <iostream>

static void doSomething() // can only be accessed in this file
{
    std::cout << "v1\n";
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}
```
- Unnamed namespaces are typically used when you have a lot of content that you want to ensure stays local to a given file, as it’s easier to cluster such content in a single unnamed namespace than individually mark all declarations as static
- Unnamed namespaces will also keep program-defined types (something we’ll discuss in a later lesson) local to the file, something for which there is no alternative equivalent mechanism to do
- An **inline namespace** is a namespace that is typically used to version content

### Chapter 8

Control flow introduction
- The specific sequence of statements that the CPU executes is called the program’s execution path
- straight-line program. Straight-line programs take the same path (execute the same statements in the same order) every time they are run.
- C++ provides a number of different control flow statements (also called flow control statements), which are statements that allow the programmer to change the normal path of execution through the program
- A conditional statement is a statement that specifies whether some associated statement(s) should be executed or not
- Consider putting single statements associated with an if or else in blocks (particularly while you are learning). More experienced C++ developers sometimes disregard this practice in favor of tighter vertical spacing.

Constexpr if statements
- constexpr if statement, which requires the conditional to be a constant expression. The conditional of a constexpr-if-statement will be evaluated at compile-time.
- Favor constexpr if statements over non-constexpr if statements when the conditional is a constant expression.

Switch statement basics
- Compared to the original if statement, the switch statement has the advantage of only evaluating the expression once (making it more efficient)
- The one restriction is that the condition must evaluate to an integral type or an enumerated type

Switch fallthrough and scoping
- Use the [[fallthrough]] attribute (along with a null statement) to indicate intentional fallthrough.
- initialization of variables does require the definition to execute at runtime (since the value of the initializer must be determined at that point). Initialization of variables is disallowed in any case that is not the last case (because the initializer could be jumped over, which would leave the variable uninitialized)
- If defining variables used in a case statement, do so in a block inside the case.

Goto statements
- unconditional jumps are implemented via a goto statement, and the spot to jump to is identified through use of a statement label
- Statement labels utilize a third kind of scope: function scope, which means the label is visible throughout the function even before its point of declaration.
- The goto statement and its corresponding statement label must appear in the same function.
- note that statement labels must be associated with a statement (hence their name: they label a statement). Because the end of the function had no statement, we had to use a null statement so we had a statement to label
- Avoid goto statements (unless the alternatives are significantly worse for code readability).

Introduction to loops and while statements
- Favor while(true) for intentional infinite loops.
- Favor while loops over do-while when given an equal choice.

For statements
- Avoid operator!= when doing numeric comparisons in the for-loop condition.
- Defining multiple variables (in the init-statement) and using the comma operator (in the end-expression) is acceptable inside a for statement.
- Prefer for loops over while loops when there is an obvious loop variable.
- Prefer while loops over for loops when there is no obvious loop variable.

Break and Continue
- Use break and continue when they simplify your loop logic.
- Use early returns when they simplify your function’s logic.

Halts
- A halt is a flow control statement that terminates the program. In C++, halts are implemented as functions (rather than keywords), so our halt statements will be function calls
- std::exit() is a function that causes the program to terminate normally. Normal termination means the program has exited in an expected way
- Note that the term normal termination does not imply anything about whether the program was successful
- std::exit() performs a number of cleanup functions. First, objects with static storage duration are destroyed. Then some other miscellaneous file cleanup is done if any files were used. Finally, control is returned back to the OS, with the argument passed to std::exit() used as the status code
- The std::exit() function does not clean up local variables in the current function or up the call stack.
- A few notes here about std::atexit() and the cleanup function: First, because std::exit() is called implicitly when main() terminates, this will invoke any functions registered by std::atexit() if the program exits that way. Second, the function being registered must take no parameters and have no return value. Finally, you can register multiple cleanup functions using std::atexit() if you want, and they will be called in reverse order of registration (the last one registered will be called first
- The std::abort() function causes your program to terminate abnormally. Abnormal termination means the program had some kind of unusual runtime error and the program couldn’t continue to run. For example, trying to divide by 0 will result in an abnormal termination. std::abort() does not do any cleanup
- The std::terminate() function is typically used in conjunction with exceptions (we’ll cover exceptions in a later chapter). Although std::terminate can be called explicitly, it is more often called implicitly when an exception isn’t handled (and in a few other exception-related cases). By default, std::terminate() calls std::abort()
- The short answer is “almost never”. Destroying local objects is an important part of C++ (particularly when we get into classes), and none of the above-mentioned functions clean up local variables. Exceptions are a better and safer mechanism for handling error cases
- Only use a halt if there is no safe way to return normally from the main function. If you haven’t disabled exceptions, prefer using exceptions for handling errors safely.

Introduction to random number generation
- Most PRNGs that produce quality results use at least 16 bytes of state, if not significantly more. However, the size of the seed value can be smaller than the size of the state of the PRNG. When this happens, we say the PRNG has been underseeded.
- As of C++20, the Mersenne Twister algorithm is the only PRNG that ships with C++ that has both decent performance and quality

Generating random numbers using Mersenne Twister
- mt() is a concise syntax for calling the function mt.operator(), which for these PRNG types has been defined to return the next random result in the sequence. The advantage of using operator() instead of a named function is that we don’t need to remember the function’s name, and the concise syntax is less typing.
- Use std::random_device to seed your PRNGs (unless it’s not implemented properly for your target compiler/architecture).
- Only seed a given pseudo-random number generator once, and do not reseed it.
- When a PRNG is given a poor quality seed (or underseeded), the initial results of the PRNG may not be high quality. For this reason, some PRNGs benefit from being “warmed up”, which is a technique where the first N results generated from the PRNG are discarded.

### Chapter 9

Introduction to testing your code
- Write your program in small, well defined units (functions or classes), compile often, and test your code as you go.

Code coverage
- Aim for 100% branch coverage of your code.
- Use the 0, 1, 2 test to ensure your loops work correctly with different number of iterations.
- Test different categories of input values to make sure your unit handles them properly.

Detecting and handling errors
- C++ offers an entirely separate way to pass errors back to the caller: exceptions.
- The basic idea is that when an error occurs, an exception is “thrown”. If the current function does not “catch” the error, the caller of the function has a chance to catch the error

std::cin and handling invalid input
- When the user enters input in response to an extraction operation, that data is placed in a buffer inside of std::cin. A buffer (also called a data buffer) is simply a piece of memory set aside for storing data temporarily while it’s moved from one place to another. In this case, the buffer is used to hold user input while it’s waiting to be extracted to variables.

Assert and static_assert
- An assertion is an expression that will be true unless there is a bug in the program.
- When an assertion evaluates to false, your program is immediately stopped. This gives you an opportunity to use debugging tools to examine the state of your program and determine why the assertion failed. Working backwards, you can then find and fix the issue.
- Use assertions to document cases that should be logically impossible.
- static_assert. A static_assert is an assertion that is checked at compile-time rather than at runtime, with a failing static_assert causing a compile error.

### Chapter 10

Implicit type conversion
- The process of producing a new value of some type from a value of a different type is called a conversion.
- Conversions do not change the value or type being converted. Instead, a new value with the desired type is created as a result of the conversion.
- Implicit type conversion (also called automatic type conversion or coercion) is performed automatically by the compiler when one data type is required, but a different data type is supplied.
- The C++ language standard defines how different fundamental types (and in some cases, compound types) can be converted to other types. These conversion rules are called the standard conversions.

Floating-point and integral promotion
- The number of bits a data type uses is called its width. A wider data type is one that uses more bits, and a narrower data type is one that uses less bits.
- A numeric promotion is the type conversion of certain narrower numeric types (such as a char) to certain wider numeric types (typically int or double) that can be processed efficiently and is less likely to have a result that overflows.
- All numeric promotions are value-preserving, which means that the converted value will always be equal to the source value (it will just have a different type).

Numeric conversions
- C++ supports another category of numeric type conversions, called numeric conversions. These numeric conversions cover additional type conversions between fundamental types.
- Values converted using a reinterpretive conversion can be converted back to the source type, resulting in a value equivalent to the original value
- Lossy conversions are potentially unsafe numeric conversions where some data may be lost during the conversion
- Compilers will generally issue a warning (or in some cases, an error) when an implicit lossy conversion would be performed at runtime.

Narrowing conversions, list initialization, and constexpr initializers
- In C++, a narrowing conversion is a potentially unsafe numeric conversion where the destination type may not be able to hold all the values of the source type.
- Because they can be unsafe and are a source of errors, avoid narrowing conversions whenever possible.
- In such cases, it is a good idea to convert an implicit narrowing conversion into an explicit narrowing conversion using static_cast
- When the source value of a narrowing conversion is constexpr, the specific value to be converted must be known to the compiler. In such cases, the compiler can perform the conversion itself, and then check whether the value was preserved. If the value was not preserved, the compiler can halt compilation with an error. If the value is preserved, the conversion is not considered to be narrowing

Arithmetic conversions
- If one of these operators is invoked with operands of different types, one or both of the operands will be implicitly converted to matching types using a set of rules called the usual arithmetic conversions

Explicit type conversion (casting) and static_cast
- Because casts are explicit requests by the programmer, this form of type conversion is often called an explicit type conversion
- Avoid const casts and reinterpret casts unless you have a very good reason to use them.
- Although a C-style cast appears to be a single cast, it can actually perform a variety of different conversions depending on context. This can include a static cast, a const cast or a reinterpret cast (the latter two of which we mentioned above you should avoid). As a result, C-style casts are at risk for being inadvertently misused and not producing the expected behavior, something which is easily avoidable by using the C++ casts instead.
- Avoid using C-style casts.
- The main advantage of static_cast is that it provides compile-time type checking, making it harder to make an inadvertent error.
- Favor static_cast when you need to convert a value from one type to another type.
- Implicit type conversion is automatically performed whenever one data type is expected, but a different data type is supplied.
- Explicit type conversion happens when the programmer uses a type cast to explicitly convert a value from one type to another type.

Typedefs and type aliases
- In C++, using is a keyword that creates an alias for an existing data type
- Because the compiler does not prevent these kinds of semantic errors for type aliases, we say that aliases are not type safe
- Use type aliases judiciously, when they provide a clear benefit to code readability or code maintenance.

Type deduction for objects using the auto keyword
- Type deduction (also sometimes called type inference) is a feature that allows the compiler to deduce the type of an object from the object’s initializer
- In most cases, type deduction will drop the const or constexpr qualifier from deduced types
- Use type deduction for your variables when the type of the object doesn’t matter.
- Favor an explicit type when you require a specific type that differs from the type of the initializer, or when your object is used in a context where making the type obvious is useful

Type deduction for Functions
- Favor explicit return types over function return type deduction for normal functions.
- The auto keyword can also be used to declare functions using a trailing return syntax, where the return type is specified after the rest of the function prototype

### Chapter 11

Introduction to function overloading
- Function overloading allows us to create multiple functions with the same name, so long as each identically named function has different parameter types (or the functions can be otherwise differentiated). Each function sharing a name (in the same scope) is called an overloaded function (sometimes called an overload for short)
- Functions can be overloaded so long as each overloaded function can be differentiated by the compiler. If an overloaded function can not be differentiated, a compile error will result.
- Additionally, when a function call is made to a function that has been overloaded, the compiler will try to match the function call to the appropriate overload based on the arguments used in the function call. This is called overload resolution
- Use function overloading to make your program simpler.

Function overload differentiation
- Because type aliases (or typedefs) are not distinct types, overloaded functions using type aliases are not distinct from overloads using the aliased type
- For parameters passed by value, the const qualifier is also not considered
- A function’s type signature (generally called a signature) is defined as the parts of the function header that are used for differentiation of the function. In C++, this includes the function name, number of parameters, parameter type, and function-level qualifiers. It notably does not include the return type

Function overload resolution and ambiguous matches
- Since a function call can only resolve to one of them, the compiler has to determine which overloaded function is the best match. The process of matching function calls to a specific overloaded function is called overload resolution
- The trivial conversions are a set of specific conversion rules that will modify types (without modifying the value) for purposes of finding a match.
- Converting a non-reference type to a reference type (or vice-versa) is also a trivial conversion.

Deleting Functions
- In cases where we have a function that we explicitly do not want to be callable, we can define that function as deleted by using the = delete specifier
- = delete means “I forbid this”, not “this doesn’t exist”.

Default arguments
- A default argument is a default value provided for a function parameter
- Perhaps surprisingly, default arguments are handled by the compiler at the call site. In the above example, when the compiler sees print(3), it will rewrite this function call as print(3, 4), so that the number of arguments matches the number of parameters.
- If a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments.
- Once declared, a default argument can not be redeclared (in the same file). That means for a function with a forward declaration and a function definition, the default argument can be declared in either the forward declaration or the function definition, but not both
- If the function has a forward declaration (especially one in a header file), put the default argument there. Otherwise, put the default argument in the function definition.

Function templates
- The compiler can use a single template to generate a family of related functions or classes, each using a different set of types.
- Templates can work with types that didn’t even exist when the template was written. This helps make template code both flexible and future proof!
- A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types
- When we create our function template, we use placeholder types (also called type template parameters, or informally template types) for any parameter types, return types, or types used in the function body that we want to be specified later
- Second, we’re going to tell the compiler that this is a function template, and that T is a type template parameter that is a placeholder for any type. This is done using what is called a template parameter declaration
- Use a single capital letter starting with T (e.g. T, U, V, etc…) to name type template parameters that are used in trivial or obvious ways.
- If the type template parameter has a non-obvious usage or meaning, then a more descriptive name is warranted. (e.g. Allocator or TAllocator).

Function template instantiation
- This looks a lot like a normal function call -- the primary difference is the addition of the type in angled brackets (called a template argument), which specifies the actual type that will be used in place of template type T
- The process of creating functions (with specific types) from function templates (with template types) is called function template instantiation (or instantiation for short)
- When this process happens due to a function call, it’s called implicit instantiation. An instantiated function is often called a function instance (instance for short) or a template function
- In cases where the type of the arguments match the actual type we want, we do not need to specify the actual type -- instead, we can use template argument deduction to have the compiler deduce the actual type that should be used from the argument types in the function call
- Favor the normal function call syntax when making calls to a function instantiated from a function template (unless you need the function template version to be preferred over a matching non-template function)
- The compiler will instantiate and compile function templates that do not make sense semantically as long as they are syntactically valid. It is your responsibility to make sure you are calling such function templates with arguments that make sense.
- The most conventional way to address this issue is to put all your template code in a header (.h) file instead of a source (.cpp) file
- You may be wondering why this doesn’t cause a violation of the one-definition rule (ODR). The ODR says that types, templates, inline functions, and inline variables are allowed to have identical definitions in different files.
- The answer is that functions implicitly instantiated from templates are implicitly inline
- Template definitions are exempt from the part of the one-definition rule that requires only one definition per program, so it is not a problem to have the same template definition #included into multiple source files. And functions implicitly instantiated from function templates are implicitly inline, so they can be defined in multiple files, so long as each definition is identical.
- The templates themselves are not inline, as the concept of inline only applies to variables and functions.
- Templates that are needed in multiple files should be defined in a header file, and then #included wherever needed. This allows the compiler to see the full template definition and instantiate the template when needed.
- Because template types can be replaced with any actual type, template types are sometimes called generic types.
- And because templates can be written agnostically of specific types, programming with templates is sometimes called generic programming
- The bigger downside of function templates is that they tend to produce crazy-looking, borderline unreadable error messages that are much harder to decipher than those of regular functions.
- Use function templates to write generic code that can work with a wide variety of types whenever you have the need.

Function templates with multiple template types
- type conversion is done only when resolving function overloads, not when performing template argument deduction
- C++20 introduces a new use of the auto keyword: When the auto keyword is used as a parameter type in a normal function, the compiler will automatically convert the function into a function template with each auto parameter becoming an independent template type parameter. This method for creating a function template is called an abbreviated function template.
- this form is preferred as the removal of the template parameter declaration line makes your code more concise and readable
- Feel free to use abbreviated function templates with a single auto parameter, or where each auto parameter should be an independent type (and your language standard is set to C++20 or newer).

Non-type template parameters
- A non-type template parameter is a template parameter with a fixed type that serves as a placeholder for a constexpr value passed in as a template argument
- Use N as the name of an int non-type template parameter.
- Non-type template parameters are used primarily when we need to pass constexpr values to functions (or class types) so they can be used in contexts that require a constant expression.

### Chapter 12
Introduction to compound data types
- Compound data types (also sometimes called composite data types) are data types that can be constructed from fundamental data types (or other compound data types)

Value categories (lvalues and rvalues)
- all expressions in C++ have two properties: a type and a value category
- The value category of an expression (or subexpression) indicates whether an expression resolves to a value, a function, or an object of some kind.
- An lvalue (pronounced “ell-value”, short for “left value” or “locator value”, and sometimes written as “l-value”) is an expression that evaluates to an identifiable object or function (or bit-field)
- a modifiable lvalue is an lvalue whose value can be modified. A non-modifiable lvalue is an lvalue whose value can’t be modified (because the lvalue is const or constexpr)
- An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is an expression that is not an lvalue
- Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used
- Lvalue expressions evaluate to an identifiable object.
- Rvalue expressions evaluate to a value.
- If you’re not sure whether an expression is an lvalue or rvalue, try taking its address using operator&
- lvalue expressions will implicitly convert to rvalue expressions in contexts where an rvalue is expected but an lvalue is provided
- Lvalue expressions are those that evaluate to variables or other identifiable objects that persist beyond the end of the expression.
- Rvalue expressions are those that evaluate to literals or values returned by functions/operators that are discarded at the end of the expression.

Lvalue References
- reference is an alias for an existing object
- A reference is essentially identical to the object being referenced.
- An lvalue reference (commonly just called a reference since prior to C++11 there was only one type of reference) acts as an alias for an existing lvalue (such as a variable).
- An lvalue reference variable is a variable that acts as a reference to an lvalue (usually another variable)
- Much like constants, all references must be initialized.
- When a reference is initialized with an object (or function), we say it is bound to that object (or function). The process by which such a reference is bound is called reference binding. The object (or function) being referenced is sometimes called the referent
- lvalue references are occasionally called lvalue references to non-const
- the type of the reference must match the type of the referent
- Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object
- the lifetime of a reference and the lifetime of its referent are independent
- A reference can be destroyed before the object it is referencing
- The object being referenced can be destroyed before the reference
- When ref dies, variable x carries on as normal
- When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists. Such a reference is called a dangling reference
- references are not objects in C++. A reference is not required to exist or occupy storage
- you can’t have a reference to a reference, since an lvalue reference must reference an identifiable object

Lvalue references to const
- Lvalue references to const can also bind to modifiable lvalues. In such a case, the object being referenced is treated as const when accessed through the reference
- Favor lvalue references to const over lvalue references to non-const unless you need to modify the object being referenced.
- lvalues references to const can also bind to rvalues
- C++ has a special rule: When a const lvalue reference is directly bound to a temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference
- Lvalue references can only bind to modifiable lvalues
- Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. This makes them a much more flexible type of reference

Pass by lvalue reference
- One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type
- Pass by reference allows us to pass arguments to a function without making copies of those arguments each time the function is called.

Pass by const lvalue reference
- if we make a reference parameter const, then it will be able to bind to any type of argument
- Passing by const reference offers the same primary benefit as pass by reference (avoiding making a copy of the argument), while also guaranteeing that the function can not change the value being referenced
- Favor passing by const reference over passing by non-const reference unless you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).
- As a rule of thumb, pass fundamental types by value, and class (or struct) types by const reference
- Other common types to pass by value: enumerated types and std::string_view.
- Other common types to pass by (const) reference: std::string, std::array, and std::vector.
- binding a reference to an object is always fast (about the same speed as copying a fundamental type).
- Second, accessing an object through a reference is slightly more expensive than accessing an object through a normal variable identifier
- With a variable identifier, the running program can just go to the memory address assigned to that variable and access the value directly. With a reference, there usually is an extra step: the program must first access the reference to determine which object is being referenced, and only then can it go to that memory address for that object and access the value
- The compiler can also sometimes optimize code using objects passed by value more highly than code using objects passed by reference
- Prefer pass by value for objects that are cheap to copy, and pass by const reference for objects that are expensive to copy. If you’re not sure whether an object is cheap or expensive to copy, favor pass by const reference.
- should the type of the parameter be const std::string& or std::string_view
- In most cases, std::string_view is the better choice, as it can handle a wider range of argument types efficiently
- Prefer passing strings using std::string_view (by value) instead of const std::string&, unless your function calls other functions that require C-style strings or std::string parameter
- Because a std::string_view parameter is a normal object, the string being viewed can be accessed directly. Accessing a std::string& parameter requires an additional step to get to the referenced object before the string can be accessed

Introduction to pointers
- The address-of operator (&) returns the memory address of its operand
- The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue
- A pointer is an object that holds a memory address (typically of another variable) as its value
- When declaring a pointer type, place the asterisk next to the type name.
- Like normal variables, pointers are not initialized by default. A pointer that has not been initialized is sometimes called a wild pointer. Wild pointers contain a garbage address, and dereferencing a wild pointer will result in undefined behavior
- initializing a pointer with a literal value is disallowed
- Thus, pointers and references both provide a way to indirectly access another object. The primary difference is that with pointers, we need to explicitly get the address to point at, and we have to explicitly dereference the pointer to get the value. With references, the address-of and dereference happens implicitly
- References must be initialized, pointers are not required to be initialized (but should be).
- References are not objects, pointers are.
- References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
- References must always be bound to an object, pointers can point to nothing (we’ll see an example of this in the next lesson).
- References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson)
- The size of the pointer is always the same. This is because a pointer is just a memory address, and the number of bits needed to access a memory address is constant
- Much like a dangling reference, a dangling pointer is a pointer that is holding the address of an object that is no longer valid

Null pointers
- Besides a memory address, there is one additional value that a pointer can hold: a null value. A null value (often shortened to null) is a special value that means something has no value. When a pointer is holding a null value, it means the pointer is not pointing at anything. Such a pointer is called a null pointer
- Value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object.
- Much like the keywords true and false represent Boolean literal values, the nullptr keyword represents a null pointer literal. We can use nullptr to explicitly initialize or assign a pointer a null value
- Accidentally dereferencing null and dangling pointers is one of the most common mistakes C++ programmers make, and is probably the most common reason that C++ programs crash in practice
- Conditionals can only be used to differentiate null pointers from non-null pointers. There is no convenient way to determine whether a non-null pointer is pointing to a valid object or dangling (pointing to an invalid object)
- A pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for null, and can assume any non-null pointer is valid.
- Favor references over pointers unless the additional capabilities provided by pointers are needed.

Pointers and const
- we can’t set a normal pointer to point at a const variable
- A pointer to const treats the value being pointed to as constant, regardless of whether the object at that address was initially defined as const or not
- A const pointer is a pointer whose address can not be changed after initialization

Pass by address
- With pass by address, instead of providing an object as an argument, the caller provides an object’s address (via a pointer)
- Thus, just like pass by reference, pass by address is fast, and avoids making a copy of the argument object
- If a null pointer should never be passed to the function, an assert (which we covered in lesson 9.6 -- Assert and static_assert) can be used instead (or also) (as asserts are intended to document things that should never happen)
- Prefer pass by reference to pass by address unless you have a specific reason to use pass by address.
- References are normally implemented by the compiler using pointers
- we can conclude that C++ really passes everything by value! The properties of pass by address (and reference) come solely from the fact that we can dereference the passed address to change the argument, which we can not do with a normal value parameter

Return by reference and return by address
- We encounter a similar situation when returning by value: a copy of the return value is passed back to the caller
- Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the return value
- Using return by reference has one major caveat: the programmer must be sure that the object being referenced outlives the function returning the reference.
- Objects returned by reference must live beyond the scope of the function returning the reference, or a dangling reference will result. Never return a (non-static) local variable or temporary by reference.
- Reference lifetime extension does not work across function boundaries.
- Avoid returning references to non-const local static variables.
- If a function returns a reference, and that reference is used to initialize or assign to a non-reference variable, the return value will be copied (as if it had been returned by value)
- Also note that if a program returns a dangling reference, the reference is left dangling before the copy is made, which will lead to undefined behavior
- When an argument for a const reference parameter is an rvalue, it’s still okay to return that parameter by const reference
- When an argument is passed to a function by non-const reference, the function can use the reference to modify the value of the argument.
- The major advantage of return by address over return by reference is that we can have the function return nullptr if there is no valid object to return
- Prefer return by reference over return by address unless the ability to return “no object” (using nullptr) is important.

In and out parameters
- In most cases, a function parameter is used only to receive an input from the caller. Parameters that are used only for receiving input from the caller are sometimes called in parameters
- By convention, output parameters are typically the rightmost parameters
- Avoid out-parameters (except in the rare case where no better options exist).
- Prefer pass by reference for non-optional out-parameters.
- In rare cases, a function will actually use the value of an out-parameter before overwriting its value. Such a parameter is called an in-out parameter. In-out-parameters work identically to out-parameters and have all the same challenges.
- Second, use pass by non-const reference when a function would otherwise return an object by value to the caller, but making a copy of that object is extremely expensive. Especially if the function is called many times in a performance-critical section of code.

Type deduction with pointers, references, and const
- type deduction will drop const (and constexpr) qualifiers
- Const (or constexpr) can be (re)applied by adding the const (or constexpr) qualifier in the definition:
- In addition to dropping const qualifiers, type deduction will also drop references:
- A top-level const is a const qualifier that applies to an object itself. For example:
- In contrast, a low-level const is a const qualifier that applies to the object being referenced or pointed to:
- Dropping a reference may change a low-level const to a top-level const: const std::string& is a low-level const, but dropping the reference yields const std::string, which is a top-level const.
- If you want a const reference, reapply the const qualifier even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.
- Unlike references, type deduction does not drop pointers
- When we use either auto const or const auto, we’re saying, “make whatever the deduced type is const”.
- However, when we use auto*, the order of the const qualifier matters. A const on the left means “make the deduced pointer type a pointer to const”, whereas a const on the right means “make the deduced pointer type a const pointer”
- If you want a const pointer, reapply the const qualifier even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.

### Chapter 13
Introduction to program-defined (user-defined) types
- Just like type aliases, program-defined types must also be defined before they can be used. The definition for a program-defined type is called a type definition
- Name your program-defined types starting with a capital letter and do not use a suffix.
- Every code file that uses a program-defined type needs to see the full type definition before it is used.
- To propagate type definitions into the code files that need them, program-defined types are typically defined in header files, and then #included into any code file that requires that type definition. These header files are typically given the same name as the program-defined type (e.g. a program-defined type named Fraction would be defined in Fraction.h)
- A program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible.
- A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed
- To allow for this, types are partially exempt from the one-definition rule: a given type is allowed to be defined in multiple code files.
- First, you can still only have one type definition per code file (this usually isn’t a problem since header guards will prevent this). Second, all of the type definitions for a given type must be identical, otherwise undefined behavior will result.
- “program-defined type” to mean class types and enumerated types that are not defined as part of the standard library, implementation, or core language. In other words, “program-defined types” only include class types and enum types that are defined by us (or a third-party library)

Unscoped enumerations
- An enumeration (also called an enumerated type or an enum) is a compound data type whose values are restricted to a set of named symbolic constants (called enumerators)
- Enumerators are implicitly constexpr
- Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.
- Prefer putting your enumerations inside a named scope region (such as a namespace or class) so the enumerators don’t pollute the global namespace.

Unscoped enumeration input and output
- we mentioned that enumerators are symbolic constants. What we didn’t tell you then is that enumerators are integral symbolic constants
- Avoid assigning explicit values to your enumerators unless you have a compelling reason to do so.
- Specify the base type of an enumeration only when necessary.
- if an unscoped enumeration has a specified base, then the compiler will allow you to list initialize an unscoped enumeration using an integral value

Scoped enumerations (enum classes)
- unscoped enumerations are distinct types in C++, they are not type safe, and in some cases will allow you to do things that don’t make sense
- Scoped enumerations work similarly to unscoped enumerations, but have two primary differences: They won’t implicitly convert to integers, and the enumerators are only placed into the scope region of the enumeration (not into the scope region where the enumeration is defined).
- you can list initialize a scoped enumeration using an integral value without the static_cast (and unlike an unscoped enumeration, you don’t need to specify a base).
- Favor scoped enumerations over unscoped enumerations unless there’s a compelling reason to do otherwise.
- a using enum statement imports all of the enumerators from an enum into the current scope

Introduction to structs, members, and member selection
- A struct (short for structure) is a program-defined data type that allows us to bundle multiple variables together into a single type
- The variables that are part of the struct are called data members (or member variables)
- In C++, a member is a variable, function, or type that belongs to a struct (or class). All members must be declared within the struct (or class) definition.
- To access a specific member variable, we use the member selection operator `.`

Struct aggregate initialization
- data members are not initialized by default
- an aggregate data type (also called an aggregate) is any type that can contain multiple data members
  - in c++: No user-declared constructors
  - in c++: No private or protected non-static data members
  - in c++: No virtual functions
- The key thing to understand at this point is that structs with only data members are aggregates
- Aggregates use a form of initialization called aggregate initialization, which allows us to directly initialize the members of aggregates. To do this, we provide an initializer list as an initializer, which is just a braced list of comma-separated values
- Each of these initialization forms does a memberwise initialization, which means each member in the struct is initialized in the order of declaration
- If an aggregate is initialized but the number of initialization values is fewer than the number of members, then all remaining members will be value-initialized
- This means we can use an empty initialization list to value-initialize all members of the struct:
- When initializing a struct from a list of values, the initializers are applied to the members in order of declaration
- To help avoid this, C++20 adds a new way to initialize struct members called designated initializers.
- The members can be initialized using list or copy initialization, and must be initialized in the same order in which they are declared in the struct, otherwise a warning or error will result
- When adding a new member to an aggregate, it’s safest to add it to the bottom of the definition list so the initializers for other members don’t shift.
- Similar to initializing a struct with an initializer list, you can also assign values to structs using an initializer list (which does memberwise assignment)
- A struct may also be initialized using another struct of the same type

Default member initialization
- This process is called non-static member initialization, and the initialization value is called a default member initializer
- Using default member initializers (or other mechanisms that we’ll cover later), structs and classes can self-initialize even when no explicit initializers are provided!
- Explicit values in a list initializer always take precedence over default member initialization values
- we noted that if an aggregate is initialized but the number of initialization values is fewer than the number of members, then all remaining members will be value-initialized. However, if a default member initializer is provided for a given member, that default member initializer will be used instead
- If an aggregate is defined with an initialization list
  - If an explicit initialization value exists, that explicit value is used
  - If an initializer is missing and a default member initializer exists, the default is used
  - If an initializer is missing and no default member initializer exists, value initialization occurs
- If an aggregate is defined with no initialization list
  - If a default member initializer exists, the default is used
  - If no default member initializer exists, the member remains uninitialized
- Provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn’t include an initializer list.
- For aggregates, prefer value initialization (with an empty braces initializer) to default initialization (with no braces)

Passing and returning structs
- Structs are generally passed by (const) reference to avoid making copies
- Structs are usually returned by value, so as not to return a dangling reference

Struct miscellany
- types can also be nested inside other types, so if an Employee only existed as part of a Company, the Employee type could be nested inside the Company struct
- It turns out, we can only say that the size of a struct will be at least as large as the size of all the variables it contains. But it could be larger! For performance reasons, the compiler will sometimes add gaps into structures (this is called padding)
- You can minimize padding by defining your members in decreasing order of size.
- The C++ compiler is not allowed to reorder members, so this has to be done manually.

Member selection with pointers and References
- When using a pointer to access the value of a member, use the member selection from pointer operator (->) instead of the member selection operator (.).

Class Templates
- First, unlike functions, type definitions can’t be overloaded.
  - Second, although functions can be overloaded, our max(Pair) functions only differ by return type, and overloaded functions can’t be differentiated solely by return type
- Much like a function template is a template definition for instantiating functions, a class template is a template definition for instantiating class types.
- A “class type” is a struct, class, or union type
- The above example makes use of a feature called class template specialization
- Both template definitions and type definitions are exempt from the one-definition rule

Class template argument deduction (CTAD) and deduction guides
- CTAD is only performed if no template argument list is present
- To address this, we can provide the compiler with a deduction guide, which tells the compiler how to deduce the template arguments for a given class template
- C++20 added the ability for the compiler to automatically generate deduction guides for aggregates, so deduction guides should only need to be provided for C++17 compatibility.
- Just like function parameters can have default arguments, template parameters can be given default values. These will be used when the template parameter isn’t explicitly specified and can’t be deduced
- CTAD stands for class template argument deduction, not class template parameter deduction, so it will only deduce the type of template arguments, not template parameters

Alias templates
- To do this, we can define an alias template, which is a template that can be used to instantiate type aliases
- Here's our alias template
- Alias templates must be defined in global scope

### Chapter 14
Introduction to object-oriented programming
- In procedural programming, the focus is on creating “procedures” (which in C++ are called functions) that implement our program logic
- In procedural programming, the functions and the data those functions operate on are separate entities
- properties are represented by objects, and behaviors are represented by functions
- In object-oriented programming (often abbreviated as OOP), the focus is on creating program-defined data types that contain both properties and a set of well-defined behaviors
- Perhaps the biggest difficulty with structs is that they do not provide an effective way to document and enforce class invariants
  - we defined an invariant as, “a condition that must be true while some component is executing”
- a class invariant is a condition that must be true throughout the lifetime of an object in order for the object to remain in a valid state. An object that has a violated class invariant is said to be in an invalid state, and unexpected or undefined behavior may result from further use of that object
- Relying on the user of an object to maintain class invariants is likely to result in problems.
- Just like structs, a class is a program-defined compound type that can have many member variables with different types
- From a technical standpoint, structs and classes are almost identical -- therefore, any example that is implemented using a struct could be implemented using a class, or vice-versa. However, from a practical standpoint, we use structs and classes differently

Member functions
- Functions that belong to a class type are called member functions.
- Functions that are not member functions are called non-member functions (or occasionally free functions) to distinguish them from member functions.
- Member functions defined inside the class type definition are implicitly inline, so they will not cause violations of the one-definition rule if the class type definition is included into multiple code files
- The object that a member function is called on is implicitly passed to the member function. For this reason, the object that a member function is called on is often called the implicit object
- Inside a member function, any member identifier that is not prefixed with the member selection operator (.) is associated with the implicit object
- However, with member functions (and member data initializers), this limitation doesn’t apply, and we can define our members in any order we like
- However, the compiler has a neat trick up its sleeve: member initializers and member function definitions are compiled as if they had been defined after the class definition. The actual definitions inside the class are used as implicit forward declarations
- For simplicity, he ultimately decided that structs and classes would have a unified ruleset (meaning structs can do everything classes can, and vice-versa), and convention could dictate how structs would actually be used
- In modern C++, it is fine for structs to have member functions. This excludes constructors, which are a special type of member function that we cover in upcoming lesson, A class type with a constructor is no longer an aggregate, and we want our structs to remain aggregates.
- If your class type has no data members, prefer using a namespace.

Const class objects and const member functions
- Const objects may not call non-const member functions
- A const member function is a member function that guarantees it will not modify the object or call any non-const member functions
- For member functions defined outside of the class definition, the const keyword must be used on both the function declaration in the class definition, and on the function definition outside the class definition.
- Constructors may not be made const, as they need to initialize the members of the object, which requires modifying them
- A member function that does not (and will not ever) modify the state of the object should be made const, so that it can be called on both const and non-const objects.
- Later removal of const on a member function will break any code that calls that member function on a const object
- Although instantiating const local variables is one way to create const objects, a more common way to get a const object is by passing an object to a function by const reference
- it is possible to overload a member function to have a const and non-const version of the same function. This works because the const qualifier is considered part of the function’s signature, so two functions which differ only in their const-ness are considered distinct.

Public and private members and access specifiers
- Each member of a class type has a property called an access level that determines who can access that member.
- Whenever a member is accessed, the compiler checks whether the access level of the member permits that member to be accessed. If the access is not permitted, the compiler will generate a compilation error. This access level system is sometimes informally called access controls
- Public members are members of a class type that do not have any restrictions on how they can be accessed
- The members of a struct are public by default. Public members can be accessed by other members of the class type, and by the public.
- The term “the public” is used to refer to code that exists outside of the members of a given class type. This includes non-member functions, as well as the members of other class types.
- The members of a class are private by default. Private members can be accessed by other members of the class, but can not be accessed by the public.
- A class with private members is no longer an aggregate, and therefore can no longer use aggregate initialization.
- Consider naming your private members starting with an “m_” prefix to help distinguish them from the names of local variables, function parameters, and member functions.
- we can explicitly set the access level of our members by using an access specifier
- Structs should avoid access specifiers altogether, meaning all struct members will be public by default. We want our structs to be aggregates, and aggregates can only have public members
- Classes should generally make member variables private (or protected), and member functions public.

Access functions

Member functions returning references to data members
- It is okay to return a (const) lvalue reference to a data member. The implicit object (containing the data member) still exists in the scope of the caller after the function returns, so any returned references will be valid.
- A member function returning a reference should return a reference of the same type as the data member being returned, to avoid unnecessary conversions.
- An rvalue object is destroyed at the end of the full expression in which it is created. Any references to members of the rvalue object are left dangling at that point.
- The evaluation of a full expression ends after any uses of that full expression as an initializer. This allows objects to be initialized with an rvalue of the same type (as the rvalue won’t be destroyed until after initialization occurs)
- Prefer to use the return value of a member function that returns by reference immediately, to avoid issues with dangling references when the implicit object is an rvalue.
- Do not return non-const references to private data members
- Const member functions can’t return non-const references to data members

The benefits of data hiding (encapsulation)
- The interface of a class type defines how a user of the class type will interact with objects of the class type. Because only public members can be accessed from outside of the class type, the public members of a class type form its interface. For this reason, an interface composed of public members is sometimes called a public interface.
- The implementation of a class type consists of the code that actually makes the class behave as intended.
- In programming, data hiding (also called information hiding or data abstraction) is a technique used to enforce the separation of interface and implementation by hiding the implementation of a program-defined data type from users
- Classes defined in C++ should use data hiding. And in fact, all of the classes provided by the standard library do just that. Structs, on the other hand, should not use data hiding, as having non-public members prevents them from being treated as aggregates
- When we give users direct access to the implementation of a class, they become responsible for maintaining all invariants
- Data hiding makes it possible to change implementation details without breaking existing programs
- Declare public members first, protected members next, and private members last. This spotlights the public interface and de-emphasizes implementation details.

Introduction to constructors
- as soon as we make any member variables private (to hide our data), our class type is no longer an aggregate (because aggregates cannot have private members)
- A constructor is a special member function that is automatically called after a non-aggregate class type object is created.
- If an accessible matching constructor is found, memory for the object is allocated, and then the constructor function is called.
- If no accessible matching constructor can be found, a compilation error will be generated.
- Many new programmers are confused about whether constructors create the objects or not. They do not -- the compiler sets up the memory allocation for the object prior to the constructor call. The constructor is then called on the uninitialized object.
- However, if a matching constructor cannot be found for a set of initializers, the compiler will error. So while constructors don’t create objects, the lack of a matching constructor will prevent creation of an object.
- After the constructor finishes executing, we say that the object has been “constructed”

Constructor member initializer lists
- To have a constructor initialize members, we do so using a member initializer list
- the members in a member initializer list are always initialized in the order in which they are defined inside the class
- Member variables in a member initializer list should be listed in order that they are defined in the class.
- The bodies of constructors functions are most often left empty
- Prefer using the member initializer list to initialize your members over assigning values in the body of the constructor.

Default constructors and default arguments
- A default constructor is a constructor that accepts no arguments
- If a class type has a default constructor, both value initialization and default initialization will call the default constructor
```
Foo foo{}; // value initialization, calls Foo() default constructor
Foo foo2;  // default initialization, calls Foo() default constructor
```
- it’s safer to just use value initialization for everything and not worry about it
- If all of the parameters in a constructor have default arguments, the constructor is a default constructor (because it can be called with no arguments)
- If a non-aggregate class type object has no user-declared constructors, the compiler will generate a public default constructor (so that the class can be value or default initialized). This constructor is called an implicit default constructor
- In cases where we would write a default constructor that is equivalent to the implicitly generated default constructor, we can instead tell the compiler to generate a default constructor for us. This constructor is called an explicitly defaulted default constructor, and it can be generated by using the = default syntax
- In the above example, since we have a user-declared constructor (Foo(int, int)), an implicit default constructor would not normally be generated. However, because we’ve told the compiler to generate such a constructor, it will.
- Prefer an explicitly defaulted default constructor (= default) over a default constructor with an empty body.
- However, if the class has a default constructor that is not user-defined (that is, either an implicitly-defined constructor, or a default constructor created using = default), the object will be zero-initialized before being default initialized.
- Only create a default constructor when it makes sense

Delegating constructors
- Constructors should not be called directly from the body of another function. Doing so will either result in a compilation error, or will value initialize a temporary object and then discard it (which likely isn’t what you want).
- Constructors are allowed to delegate (transfer responsibility for) initialization to another constructor from the same class type. This process is sometimes called constructor chaining and such constructors are called delegating constructors
- If you have multiple constructors, consider whether you can use delegating constructors to reduce duplicate code.
- Members for which the user must provide initialization values should be defined first (and as the leftmost parameters of the constructor). Members for which the user can optionally provide initialization values (because the default values are acceptable) should be defined second (and as the rightmost parameters of the constructor)

Temporary class Objects
- A temporary object (sometimes called an anonymous object or an unnamed object) is an object that has no name and exists only for the duration of a single expression

Introduction to the copy constructor
- A copy constructor is a constructor that is used to initialize an object with an existing object of the same type. After the copy constructor executes, the newly created object should be a copy of the object passed in as the initializer.
- If you do not provide a copy constructor for your classes, C++ will create a public implicit copy constructor for you.
- By default, the implicit copy constructor will do memberwise initialization. This means each member will be initialized using the corresponding member of the class passed in as the initializer.
- A copy constructor should not do anything other than copy an object. This is because the compiler may optimize the copy constructor out in certain cases. If you are relying on the copy constructor for some behavior other than just copying, that behavior may or may not occur.
- Copy constructors should have no side effects beyond copying.
- Prefer the implicit copy constructor, unless you have a specific reason to create your own.
- If you write your own copy constructor, the parameter should be a const lvalue reference.
- If we prefer, we can explicitly request the compiler create a default copy constructor for us using the = default syntax
- Occasionally we run into cases where we do not want objects of a certain class to be copyable. We can prevent this by marking the copy constructor function as deleted, using the = delete syntax

Class initialization and copy elision
- List initialization disallows narrowing conversions
- Copy initialization only considers non-explicit constructors/conversion functions
- List initialization prioritizes matching list constructors over other matching constructors
- Copy elision is a compiler optimization technique that allows the compiler to remove unnecessary copying of objects.
- When the compiler optimizes away a call to the copy constructor, we say the constructor has been elided
- copy initialization is copying using =, whereas copy constructor takes an object of the same type
  - they are two different things!!
- Unlike other types of optimization, copy elision is exempt from the “as-if” rule. That is, copy elision is allowed to elide the copy constructor even if the copy constructor has side effects (such as printing text to the console)! This is why copy constructors should not have side effects other than copying -- if the compiler elides the call to the copy constructor, the side effects won’t execute, and the observable behavior of the program will change
- It’s not important to memorize when the compiler does / doesn’t do copy elision. Just know that it is an optimization that your compiler will perform if it can, and if you expect to see your copy constructor called and it isn’t, copy elision is probably why.

Converting constructors and the explicit keyword
- Instead, the compiler will look to see if we have defined some function that it can use to perform such a conversion. Such a function is called a user-defined conversion.
- A constructor that can be used to perform an implicit conversion is called a converting constructor. By default, all constructors are converting constructors.
- only one user-defined conversion may be applied to perform an implicit conversion, and this example requires two.
- An implicit conversion can be trivially converted into an explicit definition by using direct list initialization (or direct initialization).
- we can use the explicit keyword to tell the compiler that a constructor should not be used as a converting constructor
- An explicit constructor cannot be used to do copy initialization or copy list initialization
- An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization)
- copy initialization, copy list initialization used when passing in arguments
- Copy initialization is also used whenever values are implicitly copied or converted, such as when passing arguments to a function by value, returning from a function by value, or catching exceptions by value.
- The modern best practice is to make any constructor that will accept a single argument explicit by default. This includes constructors with multiple parameters where most or all of them have default values.
- Make any constructor that accepts a single argument explicit by default. If an implicit conversion between types is both semantically equivalent and performant, you can consider making the constructor non-explicit.
- Do not make copy or move constructors explicit, as these do not perform conversions.

### Chapter 15
The hidden “this” pointer and member function chaining
- Inside every member function, the keyword this is a const pointer that holds the address of the current implicit object
- Although the call to function setID(2) looks like it only has one argument, it actually has two! When compiled, the compiler rewrites the expression simple.setID(2); as follows
`Simple::setID(&simple, 2); // note that simple has been changed from an object prefix to a function argument!`
- `void setID(int id) { m_id = id; }` becomes `static void setID(Simple* const this, int id) { this->m_id = id; }`
- All non-static member functions have a this const pointer that holds the address of the implicit object.
- Second, it can sometimes be useful to have a member function return the implicit object as a return value. The primary reason to do this is to allow member functions to be “chained” together, so several member functions can be called on the same object in a single expression! This is called function chaining (or method chaining)
- For non-const member functions, this is a const pointer to a non-const value (meaning this cannot be pointed at something else, but the object pointing to may be modified). With const member functions, this is a const pointer to a const value (meaning the pointer cannot be pointed at something else, nor may the object being pointed to be modified).

Classes and header files
- Member functions can be defined outside the class definition just like non-member functions. The only difference is that we must prefix the member function names with the name of the class type (in this case, Date::) so the compiler knows we’re defining a member of that class type rather than a non-member
- Prefer to put your class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition.
- Prefer to define non-trivial member functions in a source file with the same name as the class.
- Member functions defined inside the class definition are implicitly inline
- Member functions defined outside the class definition are not implicitly inline
- Functions defined inside the class definition are implicitly inline, which allows them to be #included into multiple code files without violating the ODR.
- Functions defined outside the class definition are not implicitly inline. They can be made inline by using the inline keyword.
- Finally, for template classes, template member functions defined outside the class are almost always defined inside the header file, beneath the class definition. Just like non-member template functions, the compiler needs to see the full template definition in order to instantiate it.
- Put any default arguments for member functions inside the class definition.

Nested types (member types)
- Define any nested types at the top of your class type.
- Fourth, class types act as a scope region for names declared within, just as namespaces do
- Class types can also contain nested typedefs or type aliases:
- In C++, a nested class does not have access to the this pointer of the outer (containing) class, so nested classes can not directly access the members of the outer class
- because nested classes are members of the outer class, they can access any private members of the outer class that are in scope

Introduction to destructors
- classes have another type of special member function that is called automatically when an object of a non-aggregate class type is destroyed. This function is called a destructor.
- Like constructors, destructors have specific naming rules:
  - The destructor must have the same name as the class, preceded by a tilde (~).
  - The destructor can not take arguments.
  - The destructor has no return type.
- If a non-aggregate class type object has no user-declared destructor, the compiler will generate a destructor with an empty body.
- the std::exit() function, can be used to terminate your program immediately. When the program is terminated immediately, the program just ends. Local variables are not destroyed first, and because of this, no destructors will be called. Be wary if you’re relying on your destructors to do necessary cleanup work in such a case.

Class templates with member functions
- Any member function templates defined outside the class definition should be defined just below the class definition (in the same file).

Static member Variables
- Unlike normal member variables, static member variables are shared by all objects of the class.
- Although you can access static members through objects of the class (as shown with first.s_value and second.s_value in the example above), static members exist even if no objects of the class have been instantiated!
- Static members are global variables that live inside the scope region of the class.
- Because static member variables are essentially global variables, you must explicitly define (and optionally initialize) the static member outside of the class, in the global scope
- Note that this static member definition is not subject to access controls: you can define and initialize the value even if it’s declared as private (or protected) in the class.
- Do not put the static member definition in a header file (much like a global variable, if that header file gets included more than once, you’ll end up with multiple definitions, which will cause a compile error)
- when the static member is a constant integral type (which includes char and bool) or a const enum, the static member can be initialized inside the class definition:
- the preferred method of defining and initializing static members is using static inline
- static constexpr members can also be initialized inside the class definition without explicit use of the inline keyword
- Make your static members inline or constexpr so they can be initialized inside the class definition.

Static member functions
- Member variables aren’t the only type of member that can be made static. Member functions can be made static as well.
- Static member functions have no *this pointer
- static member functions can directly access other static members (variables or functions), but not non-static members
- Instead of writing a class with all static members, consider writing a normal class and instantiating a global instance of it (global variables have static duration).
- a static class is preferable when you have static data members and/or need access controls. Otherwise, prefer a namespace.
  - classes have access controls!

Friend non-member functions
- What we really need is some way to subvert the access control system on a case by case basis
- Inside the body of a class, a **friend declaration** (using the friend keyword) can be used to tell the compiler that some other class or function is now a friend.
- In C++, a friend is a class or function (member or non-member) that has been granted full access to the private and protected members of another class
- Friendship is always granted by the class whose members will be accessed (not by the class or function desiring access). Between access controls and granting friendship, a class always retains the ability to control who can access its members.
- A friend function is a function (member or non-member) that can access the private and protected members of a class as though it were a member of that class. In all other regards, the friend function is a normal function
- Friend functions defined inside a class are non-member functions
- Because print() is defined as a friend, it is instead treated as a non-member function
- A friend function should prefer to use the class interface over direct access whenever possible.
- we mentioned that we should prefer non-member functions over member functions. For the same reasons given there, we should prefer non-friend functions over friend functions
- Prefer to implement a function as a non-friend when possible and reasonable.

Friend classes and friend member functions
- A friend class is a class that can access the private and protected members of another class.
- First, even though Display is a friend of Storage, Display has no access to the *this pointer of Storage objects
- friendship is not reciprocal. Just because Display is a friend of Storage does not mean Storage is also a friend of Display
- Class friendship is also not transitive. If class A is a friend of B, and B is a friend of C, that does not mean A is a friend of C

Introduction to containers and arrays
- Containers also exist in programming, to make it easier to create and manage (potentially large) collections of objects. In general programming, a container is a data type that provides storage for a collection of unnamed objects (called elements).
- We typically use containers when we need to work with a set of related values.
- The elements of a container do not have their own names, so that the container can have as many elements as we want without having to give each element a unique name.
- Each container provides some method to access these elements, but how depends on the specific type of container.
- In programming, the number of elements in a container is often called it’s length (or sometimes count).
- We’ll prefer the term “length” when referring to the number of elements in a container, and use the term “size” to refer to amount of storage required by an object.
- In C++, containers are typically implemented as class templates, so that the user can provide the desired element type as a template type argument.
- The opposite of a homogenous container is a heterogenous container, which allows elements to be different types. Heterogeneous containers are typically supported by scripting languages (such as Python)
- The Containers library is a part of the C++ standard library that contains various class types that implement some common types of containers. A class type that implements a container is sometimes called a container class.
- In C++, the definition of “container” is narrower than the general programming definition. Only the class types in the Containers library are considered to be containers in C++.
- An array is a container data type that stores a sequence of values contiguously (meaning each element is placed in an adjacent memory location, with no gaps)
- The C++ standard calls these “arrays”, but in modern C++ these are often called C arrays or C-style arrays in order to differentiate them from the similarly named std::array

Introduction to std::vector and list constructors
- Containers typically have a special constructor called a list constructor that allows us to construct an instance of the container using an initializer list. The list constructor does three things
  - Ensures the container has enough storage to hold all the initialization values (if needed).
  - Sets the length of the container to the number of elements in the initializer list (if needed).
  - Initializes the elements to the values in the initializer list (in sequential order).
- Use list initialization with an initializer list of values to construct a container with those element values.
- In C++, the most common way to access array elements is by using the name of the array along with the subscript operator (operator[])
- To select a specific element, inside the square brackets of the subscript operator, we provide an integral value that identifies which element we want to select. This integral value is called a subscript (or informally, an index)
- operator[] does not do any kind of bounds checking, meaning it does not check to see whether the index is within the bounds of 0 to N-1 (inclusive). Passing an invalid index to operator[] will return in undefined behavior
- bc continguous, this means arrays do not have any per-element overhead. It also allows the compiler to quickly calculate the address of any element in the array.
- Arrays are one of the few container types that allow random access, meaning every element in the container can be accessed directly and with equal speed, regardless of the number of elements in the container.
- Fortunately, std::vector has an explicit constructor (explicit std::vector<T>(int)) that takes a single int value defining the length of the std::vector to construct
- Each of the created elements are value-initialized, which for int does zero-initialization (and for class types calls the default constructor).
- However, there is one non-obvious thing about using this constructor: it must be called using direct initialization.
- When constructing a class type object, a matching list constructor is selected over other matching constructors.
- When constructing a container (or any type that has a list constructor) with initializers that are not element values, use direct initialization.
- When providing a default initializer for a member of a class type:
  - We must use either copy initialization or list initialization.
```
struct Foo
{
    std::vector<int> v{ std::vector<int>(8) }; // ok
};
```
- A const std::vector must be initialized, and then cannot be modified. The elements of such a vector are treated as if they were const.
- One of the biggest downsides of std::vector is that it cannot be made constexpr. If you need a constexpr array, use std::array.

std::vector and the unsigned length and subscript problem
- Each of the standard library container classes defines a nested typedef member named size_type
- size_type is a nested typedef defined in standard library container classes, used as the type for the length (and indices, if supported) of the container class.
- size_type defaults to std::size_t, and since this is almost never changed, we can reasonably assume size_type is an alias for std::size_t.
- When accessing the size_type member of a container class, we must scope qualify it with the fully templated name of the container class. For example, std::vector<int>::size_type
- Unlike std::string and std::string_view, which have both a length() and a size() member function (that do the same thing), std::vector (and most other container types in C++) only has size()
- C++20 introduces the std::ssize() non-member function, which returns the length as a large signed integral type (usually std::ptrdiff_t, which is the type normally used as the signed counterpart to std::size_t)
- The at() member function can be used to do array access with runtime bounds checking
- Because it does runtime bounds checking on every call, at() is slower (but safer) than operator[]. Despite being less safe, operator[] is typically used over at(), primarily because it’s better to do bounds checking before we call at(), so we don’t call it with an invalid index in the first place
- The simplest thing to do in this case is use a variable of type std::size_t as your index, and do not use this variable for anything but indexing.

Passing std::vector
- Therefore, when we use a std::vector as a function parameter, we have to explicitly specify the element type
- Although CTAD will work to deduce an vector’s element type from initializers when it is defined, CTAD doesn’t (currently) work with function parameters.
- One option here is to assert on arr.size(), which will catch such errors when run in a debug build configuration. Because std::vector::size() is a non-constexpr function, we can only do a runtime assert here.
- A better option is to avoid using std::vectorin cases where you need to assert on array length. Using a type that supports constexpr arrays (e.g. std::array) is probably a better choice, as you can static_assert on the length of a constexpr array.

Returning std::vector, and an introduction to move semantics
- The term copy semantics refers to the rules that determine how copies of objects are made
- When ownership of data is transferred from one object to another, we say that data has been moved.
- The cost of such a move is typically trivial (usually just two or three pointer assignments, which is way faster than copying an array of data!)
- As an added benefit, when the temporary was then destroyed at the end of the expression, it would no longer have any data to destroy, so we wouldn’t have to pay that cost either
- This is the essence of move semantics, which refers to the rules that determine how the data from one object is moved to another object
- When move semantics is invoked, any data member that can be moved is moved, and any data member that can’t be moved is copied
- Move semantics is an optimization that allows us, under certain circumstances, to inexpensively transfer ownership of some data members from one object to another object (rather than making a more expensive copy).
- Data members that can’t be moved are copied instead.
- Normally, when an object is being initialized with or assigned an object of the same type, copy semantics will be used (assuming the copy isn’t elided).
  - However, when all of the following are true, move semantics will be invoked instead:
  - The type of the object supports move semantics.
  - The initializer or object being assigned from is an rvalue (temporary) object.
  - The move isn’t elided.
- Here’s the sad news: not that many types support move semantics. However, std::vector and std::string both do!
- We can return move-capable types (like std::vector and std::string) by value. Such types will inexpensively move their values instead of making an expensive copy.
- Such types should still be passed by const reference.

Arrays and loops
- Accessing each element of a container in some order is called traversal, or traversing the container. Traversal is also sometimes called iterating over or iterating through the container.

Arrays, loops, and sign challenge solutions
- Any name that depends on a type containing a template parameter is called a dependent name. Dependent names must be prefixed with the keyword typename in order to be used as a type.
- In the above example, std::vector<T> is a type with a template parameter, so nested type std::vector<T>::size_type is a dependent name, and must be prefixed with typename to be used as a type
- A more general solution is to have the compiler fetch the type of the array type object for us, so that we don’t have to explicitly specify the container type or template arguments. To do so, we can use the decltype keyword, which returns the type of its parameter
- If you are dealing with very large arrays, or if you want to be a bit more defensive, you can use the strangely named std::ptrdiff_t. This typedef is often used as the signed counterpart to std::size_t.
- In C++23, the Z suffix can be used to define a literal of the type that is the signed counterpart to std::size_t (probably std::ptrdiff_t):
- Avoid array indexing with integral values whenever possible.

Range-based for loops (for-each)
- For best results, element_declaration should have the same type as the array elements, otherwise type conversion will occur.
- Favor range-based for loops over regular for-loops when traversing containers.
- In range-based for loops, the element declaration should use a (const) reference whenever you would normally pass that element type by (const) reference.
- If using type deduction in a range-based for loop, consider always using const auto& unless you need to work with copies. This will ensure copies aren’t made even if the element type is later changed.
- However, as of C++20, you can use the std::views::reverse capability of the Ranges library to create a reverse view of the elements that can be traversed:

Array indexing and length using enumerators
- Because enumerators are implicitly constexpr, conversion of an enumerator to an unsigned integral type is not considered a narrowing conversion, thus avoiding signed/unsigned indexing problems
- Informally, we’ll call this a count enumerator, as its value represents the count of previously defined enumerators
- If your array is constexpr, then you should static_assert instead. std::vector doesn’t support constexpr, but std::array (and C-style arrays) do.
- Use a static_assert to ensure the length of your constexpr array matches your count enumerator.
- Use an assert to ensure the length of your non-constexpr array matches your count enumerator.
- because enum classes don’t have an implicit conversion to integral types, we run into a problem when we try to use their enumerators as array indices

std::vector resizing and capacity
- we’re going to focus on the one thing that makes std::vector significantly different than most of the other array types: the ability to resize itself after it has been instantiated.
- Most array types have a significant limitation: the length of the array must be known at the point of instantiation, and then cannot be changed. Such arrays are called fixed-size arrays or fixed-length arrays. Both std::array and C-style arrays are fixed-size array types
- On the other hand, std::vector is a dynamic array. A dynamic array (also called a resizable array) is an array whose size can be changed after instantiation.
- A std::vector can be resized after instantiation by calling the resize() member function with the new desired length
- First, when we resized the vector, the existing element values were preserved! Second, the new elements are value-initialized (which performs default-initialization for class types, and zero-initialization for other types)
- In the context of a std::vector, capacity is how many elements the std::vector has allocated storage for, and length is how many elements are currently being used
- When a std::vector changes the amount of storage it is managing, this process is called reallocation.
- From the outside, it looks like the std::vector has been resized. But internally, the memory (and all of the elements) have actually been replaced
- Reallocation is typically expensive. Avoid unnecessary reallocations.
- Tracking capacity separately from length allows the std::vector to avoid some reallocations when length is changed.
- A subscript is only valid if it is between 0 and the vector’s length (not its capacity)!
- To help address this situation, std::vector has a member function called shrink_to_fit() that requests that the vector shrink its capacity to match its length
  - This request is non-binding, meaning the implementation is free to ignore it

std::vector and stack behavior
- stack-like operations were instead added (as member functions) to the existing standard library container classes that support efficient insertion and removal of elements at one end (std::vector, std::deque and std::list).
- push_back() (and emplace_back()) will increment the length of the vector, and will cause a reallocation to occur if the capacity is not sufficient to insert the value
- The resize() member function changing the length of the vector is fine when we’re intending to use subscripts to access elements (since our indices need to be less than the length to be valid), but it causes problems when we’re using the vector as a stack
- The reserve() member function can be used to reallocate a std::vector without changing the current length.
- The resize() member function changes the length of the vector, and the capacity (if necessary).
- The reserve() member function changes just the capacity (if necessary)
- Use resize() when accessing a vector via indexing. This changes the length of the vector so your indices will be valid.
- Use reserve() when accessing a vector using stack operations. This adds capacity without changing the length of the vector.
- Both push_back() and emplace_back() push an element onto the stack. If the object to be pushed already exists, push_back() and emplace_back() are equivalent, and push_back() should be preferred.
- However, in cases where we are creating a temporary object (of the same type as the vector’s element) for the purpose of pushing it onto the vector, emplace_back() can be more efficient
- Instead, we pass the arguments that would be used to create the temporary object, and emplace_back() forwards them (using a feature called perfect forwarding) to the vector. This avoids a copy that would have otherwise been made.
- Of note, push_back() won’t use explicit constructors, whereas emplace_back() will
- Prefer emplace_back() when creating a new temporary object to add to the container, or when you need to access an explicit constructor.
  - Prefer push_back() otherwise

std::vector<bool>
- When a template class has a different implementation for a particular template type argument, this is called class template specialization.
- std::vector<bool> is not a vector (it is not required to be contiguous in memory), nor does it hold bool values (it holds a collection of bits), nor does it meet C++’s definition of a container
- The modern consensus is that std::vector<bool> should generally be avoided, as the performance gains are unlikely to be worth the incompatibility headaches due to it not being a proper container
- Favor constexpr std::bitset, std::vector<char>, or 3rd party dynamic bitsets over std::vector<bool>.

### Chapter 17

Introduction to std::array
- Dynamic arrays are powerful and convenient, but like everything in life, they make some tradeoffs for the benefits they offer.
  - std::vector is slightly less performant than the fixed-size arrays. In most cases you probably won’t notice the difference (unless you’re writing sloppy code that causes lots of inadvertent reallocations).
  - std::vector only supports constexpr in very limited contexts
- In modern C++, it is really this latter point that’s significant. Constexpr arrays offer the ability to write code that is more robust, and can also be optimized more highly by the compiler.
- Use std::array for constexpr arrays, and std::vector for non-constexpr arrays.
- the length of a std::array must be a constant expression
- non-const variables and runtime constants cannot be used for the length
- std::array is an aggregate. This means it has no constructors, and instead is initialized using aggregate initialization. As a quick recap, aggregate initialization allows us to directly initialize the members of aggregates
- If a std::array is defined without an initializer, the elements will be default initialized
- If more initializers are provided in an initializer list than the defined array length, the compiler will error. If fewer initializers are provided in an initializer list than the defined array length, the remaining elements without initializers are value initialized
- Even though the elements of a const std::array are not explicitly marked as const, they are still treated as const (because the whole array is const).
- Use class template argument deduction (CTAD) to have the compiler deduce the type and length of a std::array from its initializers.
- As a reminder, operator[] does not do bounds checking
- std::array is an aggregate! no ctors
  - The actual reason is because when we allocate std::array on the stack, its storage is also stack-allocated

std::array length and indexing
- sign conversions are narrowing conversions, except when constexpr
- the non-type template parameter representing the array length (N) has type std::size_t
- In the case of std::array, size_type is always an alias for std::size_t
- Note that the non-type template parameter defining the length of the std::array is explicitly defined as std::size_t rather than size_type. This is because size_type is a member of std::array, and isn’t defined at that point.
- the length of a std::array is constexpr
- To get compile-time bounds checking when we have a constexpr index, we can use the std::get() function template

Passing and returning std::array
- With a std::array, both the element type and array length are part of the type information of the object. Therefore, when we use a std::array as a function parameter, we have to explicitly specify both the element type and array length
- One advantage that template parameters have over function parameters is that template parameters are compile-time constants. This means we can take advantage of capabilities that require constant expressions
  - So one solution is to use std::get()
- Unlike std::vector, std::array is not move-capable, so returning a std::array by value will make a copy of the array. The elements inside the array will be moved if they are move-capable, and copied otherwise.
- It is okay to return a std:array by value when all of the following are true:
  - The array isn’t huge.
  - The element type is cheap to copy (or move).
  - The code isn’t being used in a performance-sensitive context.
- In cases where return by value is too expensive, we can use an out-parameter instead.
- If you’re returning a std::array by value, your std::array probably isn’t constexpr, and you should consider using (and returning) std::vector instead

std::array of class types, and brace elision
- When initializing a std::array with a struct, class, or array and not providing the element type with each initializer, you’ll need an extra pair of braces so that the compiler will properly interpret what to initialize
- aggregates in C++ support a concept called brace elision
- Generally, you can omit braces when initializing a std::array with scalar (single) values, or when initializing with class types or arrays where the type is explicitly named with each element
- There is no harm in always initializing std::array with double braces, as it avoids having to think about whether brace-elision is applicable in a specific case or not

Arrays of references via std::reference_wrapper
- because references are not objects, you cannot make an array of references
- The elements of an array must also be assignable, and references can’t be reseated
- std::reference_wrapper is a standard library class template that lives in the <functional> header. It takes a type template argument T, and then behaves like a modifiable lvalue reference to T
- There are a few things worth noting about std::reference_wrapper:
  - Operator= will reseat a std::reference_wrapper (change which object is being referenced).
  - std::reference_wrapper<T> will implicitly convert to T&.
  - The get() member function can be used to get a T&. This is useful when we want to update the value of the object being referenced
- std::ref() and std::cref() are shorter to type, they are still widely used to create std::reference_wrapper objects

std::array and enumerations
- eh some stuff here that seems obvious, might be worthwhile to go back and read

Introduction to C-style arrays
- they are the only array type natively supported by the language, the standard library array container types (e.g. std::array and std::vector) are typically implemented using a C-style array.
- Just like std::array, when declaring a C-style array, the length of the array must be a constant expression
- Unlike the standard library container classes (which use unsigned indices of type std::size_t only), the index of a C-style array can be a value of any integral type (signed or unsigned) or an unscoped enumeration. This means that C-style arrays are not subject to all of the sign conversion indexing issues that the standard library container classes have
- Prefer omitting the length of a C-style array when explicitly initializing every array element with a value.
- Just like std::array, C-style arrays can be const or constexpr
- Applied to a C-style array, sizeof() returns the number of bytes used by the entire array

C-style array decay
- In most cases, when a C-style array is used in an expression, the array will be implicitly converted into a pointer to the element type, initialized with the address of the first element (with index 0). Colloquially, this is called array decay
- A decayed array pointer does not know how long the array it is pointing to is. The term “decay” indicates this loss of length type information.
- C-style arrays are passed by address, even when it looks like they are passed by value.
- Two C-style arrays with the same element type but different lengths will decay into the same pointer type.
- One problem with declaring the function parameter as int* arr is that it’s not obvious that arr is supposed to be a pointer to an array of values rather than a pointer to a single integer. For this reason, when passing a C-style array, its preferable to use the alternate declaration form int arr[]
- A function parameter expecting a C-style array type should use the array syntax (e.g. int arr[]) rather than pointer syntax (e.g. int *arr).
- C-style strings (which are C-style arrays) use a null-terminator to mark the end of the string, so that they can be traversed even if they have decayed.
- Avoid C-style arrays whenever practical.
  - Prefer std::string_view for read-only strings (string literal symbolic constants and string parameters).
  - Prefer std::string for modifiable strings.
  - Prefer std::array for non-global constexpr arrays.
  - Prefer std::vector for non-constexpr arrays.
  - It is okay to use C-style arrays for global constexpr arrays. We’ll discuss this in a moment.
- As parameters to functions or classes that want to handle non-constexpr C-style string arguments directly (rather than requiring a conversion to std::string_view). There are two possible reasons for this: First, converting a non-constexpr C-style string to a std::string_view requires traversing the C-style string to determine its length. If the function is in a performance critical section of code and the length isn’t needed (e.g. because the function is going to traverse the string anyway) then avoiding the conversion may be useful. Second, if the function (or class) calls other functions that expect C-style strings, converting to a std::string_view just to convert back may be suboptimal (unless you have other reasons for wanting a std::string_view).

Pointer arithmetic and subscripting
- Pointer arithmetic is a feature that allows us to apply certain integer arithmetic operators (addition, subtraction, increment, or decrement) to a pointer to produce a new memory address.
- Given some pointer ptr, ptr + 1 returns the address of the next object in memory (based on the type being pointed to). So if ptr is an int*, and an int is 4 bytes, ptr + 1
- ptr - 1 returns the address of the previous object in memory (based on the type being pointed to).
- Pointer arithmetic returns the address of the next/previous object (based on the type being pointed to), not the next/previous address.
- ptr[n] is a concise syntax equivalent to the more verbose expression *((ptr) + (n))
- Because array elements are always sequential in memory, if ptr is a pointer to element 0 of an array, *(ptr + n) will return the n-th element in the array.
- This is the primary reason arrays are 0-based rather than 1-based.
- Favor subscripting when indexing from the start of the array (element 0), so the array indices line up with the element.
- Favor pointer arithmetic when doing relative positioning from a given element.

C-style strings
- When defining C-style strings with an initializer, we highly recommend omitting the array length and letting the compiler calculate the length
- Because C-style strings are C-style arrays, they will decay -- C-style string literals decay into a const char*
- If you try to print a string that does not have a null terminator (e.g. because the null-terminator was overwritten somehow), the result will be undefined behavior
- Array overflow or buffer overflow is a computer security issue that occurs when more data is copied into storage than the storage can hold. In such cases, the memory just beyond the storage will be overwritten, leading to undefined behavior. Malicious actors can potentially exploit such flaws to overwrite the contents of memory, hoping to change the program’s behavior in some advantageous way.
- One important point to note is that C-style strings follow the same rules as C-style arrays. This means you can initialize the string upon creation, but you can not assign values to it using the assignment operator after that
- Because C-style strings are C-style arrays, you can use std::size() (or in C++20, std::ssize()) to get the length of the string as an array. There are two caveats here:
  - This doesn’t work on decayed strings.
  - Returns the actual length of the C-style array, not the length of the string
- An alternate solution is to use the strlen() function, which lives in the <cstring> header. strlen() will work on decayed arrays, and returns the length of the string being held, excluding the null terminator
- Avoid non-const C-style string objects in favor of std::string.
- The answer is that the output streams (e.g. std::cout) make some assumptions about your intent. If you pass it a non-char pointer, it will simply print the contents of that pointer (the address that the pointer is holding). However, if you pass it an object of type char* or const char*, it will assume you’re intending to print a string.

Multidimensional C-style arrays
- The dimension of an array is the number of indices needed to select an element. An array containing only a single dimension is called a single-dimensional array or a one-dimensional array (sometimes abbreviated as a 1d array)
- Memory is linear (1-dimensional), so multidimensional arrays are actually stored as a sequential list of elements
- C++ uses row-major order, where elements are sequentially placed in memory row-by-row, ordered from left to right, top to bottom:
- Flattening an array is a process of reducing the dimensionality of an array (often down to a single dimension).
- Introduced in C++23, std::mdspan is a modifiable view that provides a multidimensional array interface for a contiguous sequence of elements. By modifiable view, we mean that a std::mdspan is not just a read-only view (like std::string_view) -- if the underlying sequence of elements is non-const, those elements can be modified
- std::mdspan let us define a view with as many dimensions as we want.

### Chapter 18
Sorting an array using selection sort

Introduction to iterators
- Range-based for-loops are a little more interesting, as the mechanism for iterating through our container is hidden -- and yet, they still work for all kinds of different structures (arrays, lists, trees, maps, etc…). How do these work? They use iterators.
- An iterator is an object designed to traverse through a container
- Once the appropriate type of iterator is created, the programmer can then use the interface provided by the iterator to traverse and access elements without having to worry about what kind of traversal is being done or how the data is being stored in the container
- Iterating is such a common operation that all standard library containers offer direct support for iteration
- The important thing is that the iterator takes care of the details of iterating through the container. All we need are four things: the begin point, the end point, operator++ to move the iterator to the next element (or the end), and operator* to get the value of the current element
- Much like pointers and references, iterators can be left “dangling” if the elements being iterated over change address or are destroyed. When this happens, we say the iterator has been invalidated.
- Some operations that modify containers (such as adding an element to a std::vector) can have the side effect of causing the elements in the container to change addresses. When this happens, existing iterators to those elements will be invalidated
- Invalidated iterators can be revalidated by assigning a valid iterator to them (e.g. begin(), end())
- The erase() function returns an iterator to the element one past the erased element (or end() if the last element was removed)

Introduction to standard library algorithms
- The functionality provided in the algorithms library generally fall into one of three categories:
  - Inspectors -- Used to view (but not modify) data in a container. Examples include searching and counting.
  - Mutators -- Used to modify data in a container. Examples include sorting and shuffling.
  - Facilitators -- Used to generate a result based on values of the data members. Examples include objects that multiply values, or objects that determine what order pairs of elements should be sorted in.
- Before using a particular algorithm, make sure performance and execution order guarantees work for your particular use case.
- Favor using functions from the algorithms library over writing your own functionality to do the same thing.

Timing your code
- First, make sure you’re using a release build target, not a debug build target. Debug build targets typically turn optimization off, and that optimization can have a significant impact on the results. For example, using a debug build target, running the above std::sort example on the author’s machine took 0.0235 seconds -- 33 times as long

### Chapter 19
Dynamic memory allocation with new and delete
- C++ supports three basic types of memory allocation, of which you’ve already seen two.
  - Static memory allocation happens for static and global variables. Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
  - Automatic memory allocation happens for function parameters and local variables. Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.
  - Dynamic memory allocation is the topic of this article.
- Third, most normal variables (including fixed arrays) are allocated in a portion of memory called the stack.
  - small, 1mb
- Dynamic memory allocation is a way for running programs to request memory from the operating system when needed.
- This memory does not come from the program’s limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating system called the heap.
  - large, gbs
- To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator
- The new operator creates the object using that memory, and then returns a pointer containing the address of the memory that has been allocated
- Note that accessing heap-allocated objects is generally slower than accessing stack-allocated objects. Because the compiler knows the address of stack-allocated objects, it can go directly to that address to get a value. Heap allocated objects are typically accessed via pointer. This requires two steps: one to get the address of the object (from the pointer), and another to get the value.
- When you dynamically allocate memory, you’re asking the operating system to reserve some of that memory for your program’s use.
- Unlike static or automatic memory, the program itself is responsible for requesting and disposing of dynamically allocated memory.
- When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse. For single variables, this is done via the scalar (non-array) form of the delete operator
- The delete operator does not actually delete anything. It simply returns the memory being pointed to back to the operating system. The operating system is then free to reassign that memory to another application (or to this application again later)
- Although it looks like we’re deleting a variable, this is not the case! The pointer variable still has the same scope as before, and can be assigned a new value just like any other variable
- Note that deleting a pointer that is not pointing to dynamically allocated memory may cause bad things to happen
- A pointer that is pointing to deallocated memory is called a dangling pointer. Dereferencing or deleting a dangling pointer will lead to undefined behavior
- Set deleted pointers to nullptr unless they are going out of scope immediately afterward.
- Consequently, the best practice is to check all memory requests to ensure they actually succeeded before using the allocated memory
- Deleting a null pointer is okay, and does nothing. There is no need to conditionalize your delete statements.
- Dynamically allocated memory stays allocated until it is explicitly deallocated or until the program ends (and the operating system cleans it up, assuming your operating system does that)
- This is called a memory leak. Memory leaks happen when your program loses the address of some bit of dynamically allocated memory before giving it back to the operating system.
- Memory leaks eat up free memory while the program is running, making less memory available not only to this program, but to other programs as well. Programs with severe memory leak problems can eat all the available memory, causing the entire machine to run slowly or even crash. Only after your program terminates is the operating system able to clean up and “reclaim” all leaked memory.

Dynamically allocating arrays
- Using the scalar version of delete on an array will result in undefined behavior, such as data corruption, memory leaks, crashes, or other problems
- The answer is that array new[] keeps track of how much memory was allocated to a variable, so that array delete[] can delete the proper amount
- A dynamic array functions identically to a decayed fixed array, with the exception that the programmer is responsible for deallocating the dynamic array via the delete[] keyword

Destructors
- A destructor is another special kind of class member function that is executed when an object of that class is destroyed

Pointers to pointers and dynamic multidimensional arrays
- We recommend avoiding using pointers to pointers unless no other options are available, because they’re complicated to use and potentially dangerous. It’s easy enough to dereference a null or dangling pointer with normal pointers — it’s doubly easy with a pointer to a pointer since you have to do a double-dereference to get to the underlying value!

Void pointers
- The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects of any data type! A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type
- Because a void pointer does not know what type of object it is pointing to, deleting a void pointer will result in undefined behavior. If you need to delete a void pointer, static_cast it back to the appropriate type first
- It is not possible to do pointer arithmetic on a void pointer. This is because pointer arithmetic requires the pointer to know what size object it is pointing to, so it can increment or decrement the pointer appropriately
- A void pointer is a pointer that can point to any type of object, but does not know what type of object it points to. A void pointer must be explicitly cast into another type of pointer to perform indirection. A null pointer is a pointer that does not point to an address. A void pointer can be a null pointer.
- Thus, a void pointer refers to the type of the pointer, whereas a null pointer refers to the value (address) of the pointer.

### Chapter 20
Function Pointers
- Functions have their own l-value function type -- in this case, a function type that returns an integer and takes no parameters. Much like variables, functions live at an assigned address in memory.
- When a function is called (via the () operator), execution jumps to the address of the function being called
- The syntax for creating a non-const function pointer is one of the ugliest things you will ever see in C++
```
// fcnPtr is a pointer to a function that takes no arguments and returns an integer
int (*fcnPtr)();
```
- The parentheses around *fcnPtr are necessary for precedence reasons, as int* fcnPtr() would be interpreted as a forward declaration for a function named fcnPtr that takes no parameters and returns a pointer to an integer
- To make a const function pointer, the const goes after the asterisk:
```
int (*const fcnPtr)();
```
- Note that the type (parameters and return type) of the function pointer must match the type of the function
- the implicit dereference method looks just like a normal function call -- which is what you’d expect, since normal function names are pointers to functions anyway!
- One interesting note: Default parameters won’t work for functions called through function pointers. Default parameters are resolved at compile-time (that is, if you don’t supply an argument for a defaulted parameter, the compiler substitutes one in for you when the code is compiled). However, function pointers are resolved at run-time. Consequently, default parameters cannot be resolved when making a function call with a function pointer
- One of the most useful things to do with function pointers is pass a function as an argument to another function. Functions used as arguments to another function are sometimes called callback functions
- Note: If a function parameter is of a function type, it will be converted to a pointer to the function type. This means:
```
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
void selectionSort(int* array, int size, bool comparisonFcn(int, int))
```
  - This only works for function parameters, and so is of somewhat limited use
- An alternate method of defining and storing function pointers is to use std::function, which is part of the standard library <functional> header. To define a function pointer using this method, declare a std::function object like so
```
#include <functional>
bool validate(int x, int y, std::function<bool(int, int)> fcn); // std::function method that returns a bool and takes two int parameters
```
- note that std::function only allows calling the function via implicit dereference (e.g. fcnPtr()), not explicit dereference (e.g. (*fcnPtr)()).
- When defining a type alias, we must explicitly specify any template arguments. We can’t use CTAD in this case since there is no initializer to deduce the template arguments from.
- Much like the auto keyword can be used to infer the type of normal variables, the auto keyword can also infer the type of a function pointer.
- Because the native syntax to declare function pointers is ugly and error prone, we recommend using std::function.
- In places where a function pointer type is only used once (e.g. a single parameter or return value), std::function can be used directly. In places where a function pointer type is used multiple times, a type alias to a std::function is a better choice (to prevent repeating yourself).

The stack and the heap
- The memory that a program uses is typically divided into a few different areas, called segments:
  - The code segment (also called a text segment), where the compiled program sits in memory. The code segment is typically read-only.
  - The bss segment (also called the uninitialized data segment), where zero-initialized global and static variables are stored.
  - The data segment (also called the initialized data segment), where initialized global and static variables are stored.
  - The heap, where dynamically allocated variables are allocated from.
  - The call stack, where function parameters, local variables, and other function-related information are stored
- it is worth knowing that sequential memory requests may not result in sequential memory addresses being allocated
- The heap has advantages and disadvantages:
  - Allocating memory on the heap is comparatively slow.
  - Allocated memory stays allocated until it is specifically deallocated (beware memory leaks) or the application ends (at which point the OS should clean it up).
  - Dynamically allocated memory must be accessed through a pointer. Dereferencing a pointer is slower than accessing a variable directly.
  - Because the heap is a big pool of memory, large arrays, structures, or classes can be allocated here
- The call stack keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution, and handles allocation of all function parameters and local variables
- When a function call is encountered, the function is pushed onto the call stack. When the current function ends, that function is popped off the call stack (this process is sometimes called unwinding the stack).
- Thus, by looking at the functions that are currently on the call stack, we can see all of the functions that were called to get to the current point of execution.
- the “items” we’re pushing and popping on the stack are called stack frames.
- A stack frame keeps track of all of the data associated with one function call.
- The “marker” is a register (a small piece of memory in the CPU) known as the stack pointer (sometimes abbreviated “SP”). The stack pointer keeps track of where the top of the call stack currently is.
- We can make one further optimization: When we pop an item off the call stack, we only have to move the stack pointer down -- we don’t have to clean up or zero the memory used by the popped stack frame (the equivalent of emptying the mailbox). This memory is no longer considered to be “on the stack” (the stack pointer will be at or below this address), so it won’t be accessed. If we later push a new stack frame to this same memory, it will overwrite the old value we never cleaned up.
- A stack frame is constructed and pushed on the stack. The stack frame consists of:
  - The address of the instruction beyond the function call (called the return address). This is how the CPU remembers where to return to after the called function exits.
  - All function arguments.
  - Memory for any local variables
  - Saved copies of any registers modified by the function that need to be restored when the function returns
  - when the stack frame pops, return values can be handled in a number of different ways, depending on the computer’s architecture. Some architectures include the return value as part of the stack frame. Others use CPU registers
  - A technical note: on some architectures, the call stack grows away from memory address 0. On others, it grows towards memory address 0. As a consequence, newly pushed stack frames may have a higher or a lower memory address than the previous ones
  - Stack overflow happens when all the memory in the stack has been allocated -- in that case, further allocations begin overflowing into other sections of memory
- The stack has advantages and disadvantages:
  - Allocating memory on the stack is comparatively fast.
  - Memory allocated on the stack stays in scope as long as it is on the stack. It is destroyed when it is popped off the stack.
  - All memory allocated on the stack is known at compile time. Consequently, this memory can be accessed directly through a variable.
  - Because the stack is relatively small, it is generally not a good idea to do anything that eats up lots of stack space. This includes allocating or copying large arrays or other memory-intensive structures.

Recursion
- A recursive function in C++ is a function that calls itself
- A tail call is a function call that occurs at the tail (end) of a function. Functions with recursive tail calls are fairly easy for the compiler to optimize into an iterative (non-recursive) function
- A recursive termination is a condition that, when met, will cause the recursive function to stop calling itself
- One technique, called memoization, caches the results of expensive function calls so the result can be returned when the same input occurs again
- Generally favor iteration over recursion, except when recursion really makes sense.

Command line arguments
- Command line arguments are optional string arguments that are passed by the operating system to the program when it is launched
- argc is an integer parameter containing a count of the number of arguments passed to the program (think: argc = argument count). argc will always be at least 1, because the first argument is always the name of the program itself.
- argv is where the actual argument values are stored (think: argv = argument values, though the proper name is “argument vectors”). Although the declaration of argv looks intimidating, argv is really just an array of char pointers
- When you type something at the command line (or run your program from the IDE), it is the operating system’s responsibility to translate and route that request as appropriate. This not only involves running the executable, it also involves parsing any arguments to determine how they should be handled and passed to the application
  - Generally, operating systems have special rules about how special characters like double quotes and backslashes are handled

Ellipsis (and why to avoid them)
- there are certain cases where it can be useful to be able to pass a variable number of parameters to a function. C++ provides a special specifier known as ellipsis (aka “…”) that allow us to do precisely this
- Functions that use ellipsis take the form:
```
return_type function_name(argument_list, ...)
```
  - The argument_list is one or more normal function parameters. Note that functions that use ellipsis must have at least one non-ellipsis parameter. Any arguments passed to the function must match the argument_list parameters first.
- The ellipsis (which are represented as three periods in a row) must always be the last parameter in the function. The ellipsis capture any additional arguments (if there are any). Though it is not quite accurate, it is conceptually useful to think of the ellipsis as an array that holds any additional parameters beyond those in the argument_list.
- Note that va_start() can be called again any time we want to reset the va_list to point to the first parameter in the ellipses again.
- However, note that ellipsis parameters have no type declarations.
- However, the downside is that the compiler will no longer be able to warn you if you call the function with ellipsis arguments that do not make sense. When using the ellipsis, it is completely up to the caller to ensure the function is called with ellipsis arguments that the function can handle.
- “Garbage in, garbage out”, which is a popular computer science phrase “used primarily to call attention to the fact that computers, unlike humans, will unquestioningly process the most nonsensical of input data and produce nonsensical output”
- Not only do the ellipsis throw away the type of the parameters, it also throws away the number of parameters in the ellipsis.
  - Method #2 is to use a sentinel value. A sentinel is a special value that is used to terminate a loop when it is encountered.
  - Method #3 is decoder string, that tells the program how to interpret the parameters. In this example, we pass a string that encodes both the number of optional variables and their types. The cool thing is that this lets us deal with parameters of different types.
    - e.g. pass in for first arg `'iidiid'` which means parse `int`, `int`, `double`, `int`, `int`, `double
    - For those of you coming from C, this is what printf does!
- In C++17, fold expressions were added, which significantly improves the usability of parameter packs, to the point where they are now a viable option.

Introduction to lambdas (anonymous functions)
- A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function
- The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. Lambdas take the form
```
[ captureClause ] ( parameters ) -> returnType
{
    statements;
}
```
  - The capture clause can be empty if no captures are needed.
  - The parameter list can be empty if no parameters are required. It can also be omitted entirely unless a return type is specified.
  - The return type is optional, and if omitted, auto will be assumed (thus using type deduction used to determine the return type). While we previously noted that type deduction for function return types should be avoided, in this context, it’s fine to use (because these functions are typically so trivial).
- Following the best practice of defining things in the smallest scope and closest to first use, lambdas are preferred over normal functions when we need a trivial, one-off function to pass as an argument to some other function.
- In the above example, we defined a lambda right where it was needed. This use of a lambda is sometimes called a function literal
- In actuality, lambdas aren’t functions (which is part of how they avoid the limitation of C++ not supporting nested functions). They’re a special kind of object called a functor. Functors are objects that contain an overloaded operator() that make them callable like a function.
- The only way of using the lambda’s actual type is by means of auto
- When storing a lambda in a variable, use auto as the variable’s type.
  - When passing a lambda to a function:
  - If C++20 capable, use auto as the parameter’s type.
  - Otherwise, use a function with a type template parameter or std::function parameter.
- When a lambda has one or more auto parameter, the compiler will infer what parameter types are needed from the calls to the lambda.
  - Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas
- When used in the context of a lambda, auto is just a shorthand for a template parameter.
- As of C++17, lambdas are implicitly constexpr if the result satisfies the requirements of a constant expression
  - This generally requires two things:
    - The lambda must either have no captures, or all captures must be constexpr.
    - The functions called by the lambda must be constexpr. Note that many standard library algorithms and math functions weren’t made constexpr until C++20 or C++23
- One thing to be aware of is that a unique lambda will be generated for each different type that auto resolves to
- In the above example, we define a lambda and then call it with two different parameters (a string literal parameter, and an integer parameter). This generates two different versions of the lambda (one with a string literal parameter, and one with an integer parameter).
  - Most of the time, this is inconsequential. However, note that if the generic lambda uses static duration variables, those variables are not shared between the generated lambdas.
- For common operations (e.g. addition, negation, or comparison) you don’t need to write your own lambdas, because the standard library comes with many basic callable objects that can be used instead. These are defined in the <functional> header

Lambda captures
- Unlike nested blocks, where any identifier defined in an outer block is accessible in the scope of the nested block, lambdas can only access specific kinds of identifiers: global identifiers, entities that are known at compile time, and entities with static storage duration
- The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that it normally would not have access to.
- When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda. These cloned variables are initialized from the outer scope variables of the same name at this point
- The captured variables of a lambda are copies of the outer scope variables, not the actual variables.
- Although lambdas look like functions, they’re actually objects that can be called like functions (these are called functors -- we’ll discuss how to create your own functors from scratch in a future lesson).
  - When the compiler encounters a lambda definition, it creates a custom object definition for the lambda. Each captured variable becomes a data member of the object.
  - At runtime, when the lambda definition is encountered, the lambda object is instantiated, and the members of the lambda are initialized at that point.
- When a lambda is called, operator() is invoked. By default, this operator() treats captures as const, meaning the lambda is not allowed to modify those captures.
- To allow modifications of variables that were captured, we can mark the lambda as mutable
- When the lambda was called, the lambda captured a copy of ammo. When the lambda decremented ammo from 10 to 9 to 8, it decremented its own copy, not the original ammo value in main()
- Because captured variables are members of the lambda object, their values are persisted across multiple calls to the lambda!
- Much like functions can change the value of arguments passed by reference, we can also capture variables by reference to allow our lambda to affect the value of the argument.
- To capture a variable by reference, we prepend an ampersand (&) to the variable name in the capture. Unlike variables that are captured by value, variables that are captured by reference are non-const, unless the variable they’re capturing is const
- Capture by reference should be preferred over capture by value whenever you would normally prefer passing an argument to a function by reference
- Multiple variables can be captured by separating them with a comma. This can include a mix of variables captured by value or by reference:
- A default capture (also called a capture-default) captures all variables that are mentioned in the lambda. Variables not mentioned in the lambda are not captured if a default capture is used.
- To capture all used variables by value, use a capture value of =.
- To capture all used variables by reference, use a capture value of &.
- Default captures can be mixed with normal captures. We can capture some variables by value and others by reference, but each variable can only be captured once.
```
// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};

// Capture enemies by reference and everything else by value.
[=, &enemies](){};

// Capture armor by value and everything else by reference.
[&, armor](){};

// Illegal, we already said we want to capture everything by reference.
[&, &armor](){};

// Illegal, we already said we want to capture everything by value.
[=, armor](){};

// Illegal, armor appears twice.
[armor, &health, &armor](){};

// Illegal, the default capture has to be the first element in the capture group.
[armor, &](){};
```
- Sometimes we want to capture a variable with a slight modification or declare a new variable that is only visible in the scope of the lambda. We can do so by defining a variable in the lambda-capture without specifying its type
- userArea will only be calculated once when the lambda is defined. The calculated area is stored in the lambda object and is the same for every call. If a lambda is mutable and modifies a variable that was defined in the capture, the original value will be overridden.
- Only initialize variables in the capture if their value is short and their type is obvious. Otherwise it’s best to define the variable outside of the lambda and capture it.
- Variables are captured at the point where the lambda is defined. If a variable captured by reference dies before the lambda, the lambda will be left holding a dangling reference.
- Be extra careful when you capture variables by reference, especially with a default reference capture. The captured variables must outlive the lambda.
- Because lambdas are objects, they can be copied. In some cases, this can cause problems.
```
#include <iostream>

int main()
{
  int i{ 0 };

  // Create a new lambda named count
  auto count{ [i]() mutable {
    std::cout << ++i << '\n';
  } };

  count(); // invoke count

  auto otherCount{ count }; // create a copy of count

  // invoke both count and the copy
  count();
  otherCount();

  return 0;
}
```
- Note that the output doesn’t change even if myInvoke takes fn by value. std::function doesn’t create a copy of the lambda if we create it with std::ref.
- Standard library functions may copy function objects (reminder: lambdas are function objects). If you want to provide lambdas with mutable captured variables, pass them by reference using std::ref.
- Try to avoid mutable lambdas. Non-mutable lambdas are easier to understand and don’t suffer from the above issues, as well as more dangerous issues that arise when you add parallel execution.

### Chapter 21
Introduction to operator overloading
- In C++, operators are implemented as functions
- Using function overloading to overload operators is called operator overloading
- Limitations
  - First, almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the casting operators
  - Second, you can only overload the operators that exist. You can not create new operators or rename existing operators. For example, you could not create an operator** to do exponents
  - Third, at least one of the operands in an overloaded operator must be a user-defined type. This means you could overload operator+(int, Mystring), but not operator+(int, double)
    - Because standard library classes are considered to be user-defined, this means you could define operator+(double, std::string)
  - Fourth, it is not possible to change the number of operands an operator supports.
  - Finally, all operators keep their default precedence and associativity (regardless of what they’re used for) and this can not be changed
- An overloaded operator should operate on at least one program-defined type (either as a parameter of the function, or the implicit object).
- When overloading operators, it’s best to keep the function of the operators as close to the original intent of the operators as possible.
- If the meaning of an overloaded operator is not clear and intuitive, use a named function instead.
- Operators that do not modify their operands (e.g. arithmetic operators) should generally return results by value.
- Operators that modify their leftmost operand (e.g. pre-increment, any of the assignment operators) should generally return the leftmost operand by reference.

Overloading the arithmetic operators using friend functions

Overloading operators using normal functions
- Prefer overloading operators as normal functions instead of friends if it’s possible to do so without adding additional functions.

Overloading the I/O operators
- However, if you try to return std::ostream by value, you’ll get a compiler error. This happens because std::ostream specifically disallows being copied

Overloading operators using member functions
- Not everything can be overloaded as a friend function
- The assignment (=), subscript ([]), function call (()), and member selection (->) operators must be overloaded as member functions, because the language requires them to be.
- However, we are not able to overload operator<< as a member function. Why not? Because the overloaded operator must be added as a member of the left operand. In this case, the left operand is an object of type std::ostream. std::ostream is fixed as part of the standard library. We can’t modify the class declaration to add the overload as a member function of std::ostream.
- Typically, we won’t be able to use a member overload if the left operand is either not a class (e.g. int), or it is a class that we can’t modify (e.g. std::ostream)
- When dealing with binary operators that don’t modify the left operand (e.g. operator+), the normal or friend function version is typically preferred, because it works for all parameter types (even when the left operand isn’t a class object, or is a class that is not modifiable).
- When dealing with binary operators that do modify the left operand (e.g. operator+=), the member function version is typically preferred.
- The following rules of thumb can help you determine which form is best for a given situation:
  - If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
  - If you’re overloading a unary operator, do so as a member function.
  - If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function.
  - If you’re overloading a binary operator that modifies its left operand, but you can’t add members to the class definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function.
  - If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function.

Overloading unary operators +, -, and !

Overloading the comparison operators
- Only define overloaded operators that make intuitive sense for your class.
- This means that we only need to implement logic for operator== and operator<, and then the other four comparison operators can be defined in terms of those two
```
    friend bool operator== (const Cents& c1, const Cents& c2) { return c1.m_cents == c2.m_cents; }
    friend bool operator!= (const Cents& c1, const Cents& c2) { return !(operator==(c1, c2)); }

    friend bool operator< (const Cents& c1, const Cents& c2) { return c1.m_cents < c2.m_cents; }
    friend bool operator> (const Cents& c1, const Cents& c2) { return operator<(c2, c1); }

    friend bool operator<= (const Cents& c1, const Cents& c2) { return !(operator>(c1, c2)); }
    friend bool operator>= (const Cents& c1, const Cents& c2) { return !(operator<(c1, c2)); }
```
- This way, if we ever need to change something, we only need to update operator== and operator< instead of all six comparison operators!
- C++20 introduces the spaceship operator (operator<=>)

Overloading the increment and decrement operators
- compiler looks to see if the overloaded operator has an int parameter. If the overloaded operator has an int parameter, the operator is a postfix overload.
```
    Digit& operator++(); // prefix has no parameter
    Digit& operator--(); // prefix has no parameter

    Digit operator++(int); // postfix has an int parameter
    Digit operator--(int); // postfix has an int parameter
```

Overloading the subscript operator
- C++23 adds support for overloading operator[] with multiple subscripts.
- if const and non const versions, the preferred solution is as follows:
  - Refactor the logic into another function (usually a private const member function, but could be a non-member function).
  - Have the non-const function call the const function and use const_cast to remove the const of the returned reference.
- If the expression inside the assert evaluates to false (which means the user passed in an invalid index), the program will terminate with an error message, which is much better than the alternative (corrupting memory).
- If you try to call operator[] on a pointer to an object, C++ will assume you’re trying to index an array of objects of that type.

Overloading the parenthesis operator
- The parenthesis operator (operator()) is a particularly interesting operator in that it allows you to vary both the type AND number of parameters it takes
- There are two things to keep in mind: first, the parenthesis operator must be implemented as a member function. Second, in non-object-oriented C++, the () operator is used to call functions.
- Operator() is also commonly overloaded to implement functors (or function object), which are classes that operate like functions. The advantage of a functor over a normal function is that functors can store data in member variables (since they are classes)
- Operator() is sometimes overloaded with two parameters to index multidimensional arrays, or to retrieve a subset of a one dimensional array (with the two parameters defining the subset to return). Anything else is probably better written as a member function with a more descriptive name
- Operator() is also often overloaded to create functors. Although simple functors (such as the example above) are fairly easily understood, functors are typically used in more advanced programming topics, and deserve their own lesson

Overloading typecasts
- User-defined conversions allow us to convert our class into another data type. Take a look at the following class
- There are three things to note:
  - To overload the function that casts our class to an int, we write a new function in our class called operator int(). Note that there is a space between the word operator and the type we are casting to. Such functions must be non-static members.
  - User-defined conversions do not have parameters, as there is no way to pass arguments explicitly to them. They do still have a hidden *this parameter, pointing to the implicit object (which is the object to be converted)
  - User-defined conversions do not declare a return type. The name of the conversion (e.g. int) is used as the return type, as it is the only return type allowed. This prevents redundancy.
- The compiler will first note that function printInt takes an integer parameter. Then it will note that variable cents is not an int. Finally, it will look to see if we’ve provided a way to convert a Cents into an int. Since we have, it will call our operator int() function, which returns an int, and the returned int will be passed to printInt().
- Such typecasts can also be invoked explicitly via static_cast
- Explicit typecasts can only be invoked explicitly (e.g. during non-copy initialization or by using an explicit cast like static_cast).
- Typecasts should be marked as explicit, except in cases where the class to be converted to is essentially synonymous.
- In general, a converting constructor should be preferred to an overloaded typecast, as it allows the type being constructed to own the construction.

Overloading the assignment operator
- The copy assignment operator (operator=) is used to copy values from one object to another already existing object.
- If a new object has to be created before the copying can occur, the copy constructor is used (note: this includes passing or returning objects by value).
- If a new object does not have to be created before the copying can occur, the assignment operator is used
- Because self-assignment is a rare event, some prominent C++ gurus recommend omitting the self-assignment guard even in classes that would benefit from it. We do not recommend this, as we believe it’s a better practice to code defensively and then selectively optimize later
- Unlike other operators, the compiler will provide an implicit public copy assignment operator for your class if you do not provide a user-defined one. This assignment operator does memberwise assignment (which is essentially the same as the memberwise initialization that default copy constructors do).
- Just like other constructors and operators, you can prevent assignments from being made by making your copy assignment operator private or using the delete keyword:
- Note that if your class has const members, the compiler will instead define the implicit operator= as deleted. This is because const members can’t be assigned, so the compiler will assume your class should not be assignable
- If you want a class with const members to be assignable (for all members that aren’t const), you will need to explicitly overload operator= and manually assign each non-const member.

Shallow vs. deep copying
- Because C++ does not know much about your class, the default copy constructor and default assignment operators it provides use a copying method known as a memberwise copy (also known as a shallow copy)
- A deep copy allocates memory for the copy and then copies the actual value, so that the copy lives in distinct memory from the source.
- Remember the rule of three? If a class requires a user-defined destructor, copy constructor, or copy assignment operator, then it probably requires all three. This is why. If we’re user-defining any of these functions, it’s probably because we’re dealing with dynamic memory allocation. We need the copy constructor and copy assignment to handle deep copies, and the destructor to deallocate memory.
- The default copy constructor and default assignment operators do shallow copies, which is fine for classes that contain no dynamically allocated variables.
- Classes with dynamically allocated variables need to have a copy constructor and assignment operator that do a deep copy.
- Favor using classes in the standard library over doing your own memory management.

Overloading operators and function templates

### Chapter 22
Introduction to smart pointers and move semantics
- A Smart pointer is a composition class that is designed to manage dynamically allocated memory and ensure that memory gets deleted when the smart pointer object goes out of scope
- Move semantics means the class will transfer ownership of the object rather than making a copy.
- Deleting a nullptr is okay, as it does nothing.

R-value references
- R-value references are more often used as function Parameters
- You should almost never return an r-value reference, for the same reason you should almost never return an l-value reference. In most cases, you’ll end up returning a hanging reference when the referenced object goes out of scope at the end of the function

Move constructors and move assignment
- Move constructors and move assignment should be marked as noexcept. This tells the compiler that these functions will not throw exceptions
- The move constructor and move assignment are called when those functions have been defined, and the argument for construction or assignment is an rvalue. Most typically, this rvalue will be a literal or temporary value
- The compiler will create an implicit move constructor and move assignment operator if all of the following are true:
  - There are no user-declared copy constructors or copy assignment operators.
  - There are no user-declared move constructors or move assignment operators.
  - There is no user-declared destructor
- If we construct an object or do an assignment where the argument is an l-value, the only thing we can reasonably do is copy the l-value. We can’t assume it’s safe to alter the l-value, because it may be used again later in the program. If we have an expression “a = b” (where b is an lvalue), we wouldn’t reasonably expect b to be changed in any way.
- However, if we construct an object or do an assignment where the argument is an r-value, then we know that r-value is just a temporary object of some kind.
- Move semantics is an optimization opportunity.
- In the generateResource() function of the Auto_ptr4 example above, when variable res is returned by value, it is moved instead of copied, even though res is an l-value. The C++ specification has a special rule that says automatic objects returned from a function by value can be moved even if they are l-values.
- But in move-enabled classes, it is sometimes desirable to delete the copy constructor and copy assignment functions to ensure copies aren’t made.
- Since the goal of move semantics is to move a resource from a source object to a destination object, you might think about implementing the move constructor and move assignment operator using std::swap(). However, this is a bad idea, as std::swap() calls both the move constructor and move assignment on move-capable objects, which would result in an infinite recursion.
- If you delete the copy constructor, the compiler will not generate an implicit move constructor (making your objects neither copyable nor movable). Therefore, when deleting the copy constructor, it is useful to be explicit about what behavior you want from your move constructors. Either explicitly delete them (making it clear this is the desired behavior), or default them (making the class move-only)
- The rule of five says that if the copy constructor, copy assignment, move constructor, move assignment, or destructor are defined or deleted, then each of those functions should be defined or deleted.
- While deleting only the move constructor and move assignment may seem like a good idea if you want a copyable but not movable object, this has the unfortunate consequence of making the class not returnable by value in cases where mandatory copy elision does not apply. This happens because a deleted move constructor is still declared, and thus is eligible for overload resolution. And return by value will favor a deleted move constructor over a non-deleted copy constructor.

std::move
- std::move is a standard library function that casts (using static_cast) its argument into an r-value reference, so that move semantics can be invoked
- the C++ standard says, “Unless otherwise specified, moved-from objects [of types defined in the C++ standard library] shall be placed in a valid but unspecified state.
- std::move() gives a hint to the compiler that the programmer doesn’t need the value of an object any more. Only use std::move() on persistent objects whose value you want to move, and do not make any assumptions about the value of the object beyond that point. It is okay to give a moved-from object a new value (e.g. using operator=) after the current value has been moved
- std::move can be used whenever we want to treat an l-value like an r-value for the purpose of invoking move semantics instead of copy semantics.

std::unique_ptr
- By always allocating smart pointers on the stack (as local variables or composition members of a class), we’re guaranteed that the smart pointer will properly go out of scope when the function or object it is contained within ends, ensuring the object the smart pointer owns is properly deallocated
- Because std::unique_ptr is designed with move semantics in mind, copy initialization and copy assignment are disabled. If you want to transfer the contents managed by std::unique_ptr, you must use move semantics.
- std::unique_ptr has an overloaded operator* and operator-> that can be used to return the resource being managed. Operator* returns a reference to the managed resource, and operator-> returns a pointer
- Remember that std::unique_ptr may not always be managing an object -- either because it was created empty (using the default constructor or passing in a nullptr as the parameter), or because the resource it was managing got moved to another std::unique_ptr. So before we use either of these operators, we should check whether the std::unique_ptr actually has a resource. Fortunately, this is easy: std::unique_ptr has a cast to bool that returns true if the std::unique_ptr is managing a resource
- Favor std::array, std::vector, or std::string over a smart pointer managing a fixed array, dynamic array, or C-style string.
- C++14 comes with an additional function named std::make_unique(). This templated function constructs an object of the template type and initializes it with the arguments passed into the function.
- Use std::make_unique() instead of creating std::unique_ptr and using new yourself.
- Instead, it’s better to just pass the resource itself (by pointer or reference, depending on whether null is a valid argument). This allows the function to remain agnostic of how the caller is managing its resources. To get a raw resource pointer from a std::unique_ptr, you can use the get() member function:

std::shared_ptr
- std::shared_ptr is meant to solve the case where you need multiple smart pointers co-owning a resource
- As long as at least one std::shared_ptr is pointing to the resource, the resource will not be deallocated, even if individual std::shared_ptr are destroyed
- Always make a copy of an existing std::shared_ptr if you need more than one std::shared_ptr pointing to the same resource.
- When a std::shared_ptr is created via a std::shared_ptr constructor, the memory for the managed object (which is usually passed in) and control block (which the constructor creates) are allocated separately. However, when using std::make_shared(), this can be optimized into a single memory allocation, which leads to better performance.
- This also explains why independently creating two std::shared_ptr pointed to the same resource gets us into trouble. Each std::shared_ptr will have one pointer pointing at the resource. However, each std::shared_ptr will independently allocate its own control block, which will indicate that it is the only pointer owning that resource.
- A std::unique_ptr can be converted into a std::shared_ptr via a special std::shared_ptr constructor that accepts a std::unique_ptr r-value. The contents of the std::unique_ptr will be moved to the std::shared_ptr.
- However, std::shared_ptr can not be safely converted to a std::unique_ptr. This means that if you’re creating a function that is going to return a smart pointer, you’re better off returning a std::unique_ptr and assigning it to a std::shared_ptr if and when that’s appropriate

Circular dependency issues with std::shared_ptr, and std::weak_ptr
- A Circular reference (also called a cyclical reference or a cycle) is a series of references where each object references the next, and the last object references back to the first, causing a referential loop.
- A std::weak_ptr is an observer -- it can observe and access the same object as a std::shared_ptr (or other std::weak_ptrs) but it is not considered an owner.
- One downside of std::weak_ptr is that std::weak_ptr are not directly usable (they have no operator->). To use a std::weak_ptr, you must first convert it into a std::shared_ptr. Then you can use the std::shared_ptr. To convert a std::weak_ptr into a std::shared_ptr, you can use the lock() member function.
- Because std::weak_ptr won’t keep an owned resource alive, it’s similarly possible for a std::weak_ptr to be left pointing to a resource that has been deallocated by a std::shared_ptr. However, std::weak_ptr has a neat trick up its sleeve -- because it has access to the reference count for an object, it can determine if it is pointing to a valid object or not! If the reference count is non-zero, the resource is still valid. If the reference count is zero, then the resource has been destroyed.
- Note that if a std::weak_ptr is expired, then we shouldn’t call lock() on it, because the object being pointed to has already been destroyed, so there is no object to share. If you do call lock() on an expired std::weak_ptr, it will return a std::shared_ptr to nullptr
- std::shared_ptr can be used when you need multiple smart pointers that can co-own a resource. The resource will be deallocated when the last std::shared_ptr goes out of scope. std::weak_ptr can be used when you want a smart pointer that can see and use a shared resource, but does not participate in the ownership of that resource.

### Chapter 23
Object relationships
- This process of building complex objects from simpler ones is called object composition
- When we build classes with data members, we’re essentially constructing a complex object from simpler parts, which is object composition. For this reason, structs and classes are sometimes referred to as composite types
- To qualify as a composition, an object and a part must have the following relationship:
  - The part (member) is part of the object (class)
  - The part (member) can only belong to one object (class) at a time
  - The part (member) has its existence managed by the object (class)
  - The part (member) does not know about the existence of the object (class)
- Because of this, composition is sometimes called a “death relationship”
- We call this a unidirectional relationship, because the body knows about the heart, but not the other way around
- A good rule of thumb is that each class should be built to accomplish a single task. That task should either be the storage and manipulation of some kind of data (e.g. Point2D, std::string), OR the coordination of its members (e.g. Creature). Ideally not both

Aggregation
- To qualify as an aggregation, a whole object and its parts must have the following relationship:
  - The part (member) is part of the object (class)
  - The part (member) can (if desired) belong to more than one object (class) at a time
  - The part (member) does not have its existence managed by the object (class)
  - The part (member) does not know about the existence of the object (class)
- Implement the simplest relationship type that meets the needs of your program, not what seems right in real-life.
- Compositions:
  - Typically use normal member variables
  - Can use pointer members if the class handles object allocation/deallocation itself
  - Responsible for creation/destruction of parts
- Aggregations:
  - Typically use pointer or reference members that point to or reference objects that live outside the scope of the aggregate class
  - Not responsible for creating/destroying parts
- fixed arrays and the various standard library lists can’t hold references (because list elements must be assignable, and references can’t be reassigned).
- std::reference_wrapper is a class that acts like a reference, but also allows assignment and copying, so it’s compatible with lists like std::vector.
- std::reference_wrapper lives in the <functional> header.
- When you create your std::reference_wrapper wrapped object, the object can’t be an anonymous object (since anonymous objects have expression scope, and this would leave the reference dangling).
- When you want to get your object back out of std::reference_wrapper, you use the get() member function.

Association
- To qualify as an association, an object and another object must have the following relationship:
  - The associated object (member) is otherwise unrelated to the object (class)
  - The associated object (member) can belong to more than one object (class) at a time
  - The associated object (member) does not have its existence managed by the object (class)
  - The associated object (member) may or may not know about the existence of the object (class)
- We can say that association models as “uses-a” relationship. The doctor “uses” the patient (to earn income). The patient uses the doctor (for whatever health purposes they need)
- Sometimes objects may have a relationship with other objects of the same type. This is called a reflexive association

Dependencies
- A dependency occurs when one object invokes another object’s functionality in order to accomplish some specific task.
- Dependencies typically are not members

Container classes
- a container class is a class designed to hold and organize multiple instances of another type (either another class, or a fundamental type)
- Value containers are compositions that store copies of the objects that they are holding (and thus are responsible for creating and destroying those copies). Reference containers are aggregations that store pointers or references to other objects (and thus are not responsible for creation or destruction of those objects).
- in C++, containers typically only hold one type of data

std::initializer_list
- When a compiler sees an initializer list, it automatically converts it into an object of type std::initializer_list. Therefore, if we create a constructor that takes a std::initializer_list parameter, we can create objects using the initializer list as an input
- std::initializer_list is often passed by value. Much like std::string_view, std::initializer_list is a view. Copying a std::initializer_list does not copy the elements in the list
- use the begin() member function to get an iterator to the std::initializer_list.
- The a1 case uses direct initialization (which doesn’t consider list constructors), so this definition will call IntArray(int), allocating an array of size 5.
- The a2 case uses list initialization (which favors list constructors). Both IntArray(int) and IntArray(std::initializer_list<int>) are possible matches here, but since list constructors are favored, IntArray(std::initializer_list<int>) will be called, allocating an array of size 1 (with that element having value 5)
- List initialization favors matching list constructors over matching non-list constructors.
- When initializing a container that has a list constructor:
  - Use brace initialization when intending to call the list constructor (e.g. because your initializers are element values)
  - Use direct initialization when intending to call a non-list constructor (e.g. because your initializers are not element values).
- Adding a list constructor to an existing class that did not have one may break existing programs.
- Note that if you implement a constructor that takes a std::initializer_list, you should ensure you do at least one of the following:
  - Provide an overloaded list assignment operator
  - Provide a proper deep-copying copy assignment operator
  - Delete the copy assignment operator
- If you provide list construction, it’s a good idea to provide list assignment as well.
- Implementing a constructor that takes a std::initializer_list parameter allows us to use list initialization with our custom classes. We can also use std::initializer_list to implement other functions that need to use an initializer list, such as an assignment operator

Introduction to inheritance
- inheritance involves creating new objects by directly acquiring the attributes and behaviors of other objects and then extending or specializing them

Basic inheritance in C++
- Inheritance in C++ takes place between classes. In an inheritance (is-a) relationship, the class being inherited from is called the parent class, base class, or superclass, and the class doing the inheriting is called the child class, derived class, or subclass
- A child class inherits both behaviors (member functions) and properties (member variables) from the parent (subject to some access restrictions that we’ll cover in a future lesson).

Order of construction of derived classes
- When C++ constructs derived objects, it does so in phases. First, the most-base class (at the top of the inheritance tree) is constructed first. Then each child class is constructed in order, until the most-child class (at the bottom of the inheritance tree) is constructed last.
- C++ constructs derived classes in phases, starting with the most-base class (at the top of the inheritance tree) and finishing with the most-child class (at the bottom of the inheritance tree)

Constructors and initialization of derived classes
- The only real difference between this case and the non-inherited case is that before the Derived constructor can do anything substantial, the Base constructor is called first
- C++ prevents classes from initializing inherited member variables in the member initializer list of a constructor
- The answer has to do with const and reference variables. Consider what would happen if m_id were const. Because const variables must be initialized with a value at the time of creation, the base class constructor must set its value when the variable is created. However, when the base class constructor finishes, the derived class constructor’s member initializer lists are then executed
- By restricting the initialization of variables to the constructor of the class those variables belong to, C++ ensures that all variables are initialized only once
- Fortunately, C++ gives us the ability to explicitly choose which Base class constructor will be called! To do this, simply add a call to the Base class constructor in the member initializer list of the derived class
- Note that it doesn’t matter where in the Derived constructor member initializer list the Base constructor is called -- it will always execute first
- Private members can only be accessed by member functions of the same class. Note that this means derived classes can not access private members of the base class directly!
- It is worth mentioning that constructors can only call constructors from their immediate parent/base class. Consequently, the C constructor could not call or pass parameters to the A constructor directly. The C constructor can only call the B constructor (which has the responsibility of calling the A constructor).
- When a derived class is destroyed, each destructor is called in the reverse order of construction. In the above example, when c is destroyed, the C destructor is called first, then the B destructor, then the A destructor
- If your base class has virtual functions, your destructor should also be virtual, otherwise undefined behavior will result in certain cases

Inheritance and access specifiers
- C++ has a third access specifier that we have yet to talk about because it’s only useful in an inheritance context. The protected access specifier allows the class the member belongs to, friends, and derived classes to access the member
- using the protected access specifier is most useful when you (or your team) are going to be the ones deriving from your own classes, and the number of derived classes is reasonable.
- Favor private members over protected members.
- First, there are three different ways for classes to inherit from other classes: public, protected, and private.
- If you do not choose an inheritance type, C++ defaults to private inheritance (just like members default to private access if you do not specify otherwise)
- When you inherit a base class publicly, inherited public members stay public, and inherited protected members stay protected
- Use public inheritance unless you have a specific reason to do otherwise.
- Protected inheritance is the least common method of inheritance. It is almost never used, except in very particular cases
- With private inheritance, all members from the base class are inherited as private
- Note that this does not affect the way that the derived class accesses members inherited from its parent! It only affects the code trying to access those members through the derived class
- Private inheritance can be useful when the derived class has no obvious relationship to the base class, but uses the base class for implementation internally. In such a case, we probably don’t want the public interface of the base class to be exposed through objects of the derived class (as it would be if we inherited publicly

Adding new functionality to a derived class
- To add new functionality to a derived class, simply declare that functionality in the derived class like normal

Calling inherited functions and overriding behavior
- When a member function is called with a derived class object, the compiler first looks to see if that member exists in the derived class. If not, it begins walking up the inheritance chain and checking whether the member has been defined in any of the parent classes. It uses the first one it finds.

Hiding inherited functionality
- You can only change the access specifiers of base members the derived class would normally be able to access.
- Perhaps surprisingly, given a set of overloaded functions in the base class, there is no way to change the access specifier for a single overload. You can only change them all
- You can also mark member functions as deleted in the derived class, which ensures they can’t be called at all through a derived object

Multiple inheritance
- Multiple inheritance enables a derived class to inherit members from more than one parent
- A mixin (also spelled “mix-in”) is a small class that can be inherited from in order to add properties to a class. The name mixin indicates that the class is intended to be mixed into other classes, not instantiated on its own
```
	button.Box::setTopLeft({ 1, 1 });
	button.Box::setBottomRight({ 10, 10 });
	button.Label::setText("Submit");
	button.Label::setFontSize(6);
	button.Tooltip::setText("Submit the form to the server");
```
- Perhaps surprisingly, a derived class can inherit from a mixin base class using the derived class as a template type parameter. Such inheritance is called Curiously Recurring Template Pattern (CRTP for short), which looks like this:
```
// The Curiously Recurring Template Pattern (CRTP)

template <class T>
class Mixin
{
    // Mixin<T> can use template type parameter T to access members of Derived
    // via (static_cast<T*>(this))
};

class Derived : public Mixin<Derived>
{
};
```
- Second, and more serious is the diamond problem, which your author likes to call the “diamond of doom”. This occurs when a class multiply inherits from two classes which each inherit from a single base class.
- Avoid multiple inheritance unless alternatives lead to more complexity.

### Chapter 25
Pointers and references to the base class of derived objects

Virtual functions and polymorphism
- A virtual function is a special type of member function that, when called, resolves to the most-derived version of the function for the actual type of the object being referenced or pointed to
- A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides
- Some modern compilers may give an error about having virtual functions and an accessible non-virtual destructor. If this is the case, add a virtual destructor to the base class. In the above program, add this to the definition of Base
- Note that virtual function resolution only works when a virtual member function is called through a pointer or reference to a class type object.
  - This works because the compiler can differentiate the type of the pointer or reference from the type of the object being pointed to or referenced.
- Virtual function resolution only works when a member function is called through a pointer or reference to a class type object.
- polymorphism refers to the ability of an entity to have multiple forms
- Compile-time polymorphism refers to forms of polymorphism that are resolved by the compiler. These include function overload resolution, as well as template resolution
- Runtime polymorphism refers to forms of polymorphism that are resolved at runtime. This includes virtual function resolution
- A word of warning: the signature of the derived class function must exactly match the signature of the base class virtual function in order for the derived class function to be used.
- If a function is virtual, all matching overrides in derived classes are implicitly virtual.
- Never call virtual functions from constructors or destructors.
- Since most of the time you’ll want your functions to be virtual, why not just make all functions virtual? The answer is because it’s inefficient -- resolving a virtual function call takes longer than resolving a regular one

The override and final specifiers, and covariant return types
- To address some common challenges with inheritance, C++ has two inheritance-related identifiers: override and final
  - Note that these identifiers are not keywords -- they are normal words that have special meaning only when used in certain contexts. The C++ standard calls them “identifiers with special meaning”, but they are often referred to as “specifiers”.
- To help address the issue of functions that are meant to be overrides but aren’t, the override specifier can be applied to any virtual function by placing the override specifier after the function signature (the same place a function-level const specifier goes)
- If the function does not override a base class function (or is applied to a non-virtual function), the compiler will flag the function as an error
- Because there is no performance penalty for using the override specifier and it helps ensure you’ve actually overridden the function you think you have, all virtual override functions should be tagged using the override specifier. Additionally, because the override specifier implies virtual, there’s no need to tag functions using the override specifier with the virtual keyword
- Use the virtual keyword on virtual functions in a base class.
- Use the override specifier (but not the virtual keyword) on override functions in derived classes. This includes virtual destructors.
- In the case where we want to restrict the user from overriding a function, the final specifier is used in the same place the override specifier is, like so:
- In the case where we want to prevent inheriting from a class, the final specifier is applied after the class name:
- There is one special case in which a derived class virtual function override can have a different return type than the base class and still be considered a matching override. If the return type of a virtual function is a pointer or a reference to some class, override functions can return a pointer or a reference to a derived class. These are called covariant return types.
- One interesting note about covariant return types: C++ can’t dynamically select types, so you’ll always get the type that matches the actual version of the function being called.

Virtual destructors, virtual assignment, and overriding virtualization
- You should always make your destructors virtual if you’re dealing with inheritance.
- Whenever you are dealing with inheritance, you should make any explicit destructors virtual.
- Now that the final specifier has been introduced into the language, our recommendations are as follows:
  - If you intend your class to be inherited from, make sure your destructor is virtual.
  - If you do not intend your class to be inherited from, mark your class as final. This will prevent other classes from inheriting from it in the first place, without imposing any other use restrictions on the class itself.

