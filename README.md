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



