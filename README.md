# LearningCPP

A collection of small C and C++ programs used to learn core C++ concepts, mostly through C++98-era examples. The repository is organized like a topic-by-topic notebook: each folder contains focused programs that demonstrate one language feature, object model rule, design pattern, or data-structure idea.

## Contents

- [C++98](C++98/) - main set of examples and notes.
- [Why C++](C++98/00_Why_CPP/) - modular C versus C++ examples, including Date implementations.
- [Object basics](C++98/01_Object_Creation/) - object creation, constructors, initialization, member functions, namespaces, static data, const, mutable, inline functions, friends, and destructors.
- [Memory and resources](C++98/14_CIRCULAR_DOUBLY_LINKED_LIST/) - linked lists, dynamic arrays, singleton class, `new`/`delete`, memory leaks, and ownership examples.
- [Templates](C++98/18_template/) - function templates, class templates, non-type template parameters, sorting, and template-based DSA examples.
- [Inheritance and polymorphism](C++98/19_Inheritence/) - inheritance basics, access control, virtual functions, multiple inheritance, virtual inheritance, and RTTI.
- [References and copy control](C++98/20_Refernce_variables/) - references, shallow/deep copy, copy constructor and assignment control, and related pitfalls.
- [Operator overloading](C++98/21_Operator_overloading/) - binary/unary operators, stream operators, subscript operators, callable objects, matrix and complex examples.
- [Patterns](C++98/24_Iterator_Patterns/) - iterator and interface pattern examples.
- [Casting and low-level C/C++](C++98/26_TypeCasting/) - `void*`, offset/container macros, endianness, generic linked lists in C, and explicit C++ casts.
- [Temporary/experimental examples](C++98/28_Temp/) - RTTI, exceptions, smart pointer internals, linked lists, DSA headers, and assorted practice programs.

## Repository Layout

```text
C++98/
  00_Why_CPP/                    C and C++ Date examples
  01_Object_Creation/            Object creation basics
  02_Constructor/                First constructor example
  03_Initialization/             Initialization basics
  ...
  18_template/                   Template examples and template DSA
  21_Operator_overloading/       Operator overloading examples
  24_Iterator_Patterns/          Iterator pattern practice
  25_Interface_Pattern/          Interface-based designs
  26_TypeCasting/                C and C++ casting examples
  27_Explicit_TypeCasting/       static_cast, const_cast, reinterpret_cast, RTTI
  28_Temp/                       Extra experiments and practice code
```

## Requirements

Use a C and C++ compiler. On Linux, `gcc` and `g++` are enough for most files.

Recommended:

- `g++` with C++98 support
- `gcc` for the C examples
- A POSIX-like shell

## Build And Run

Most examples are standalone files, so compile the file you want to study directly.

```sh
g++ -std=c++98 -Wall -Wextra C++98/18_template/implementing_a_class_template.cpp -o template_demo
./template_demo
```

For C examples:

```sh
gcc -Wall -Wextra C++98/26_TypeCasting/endianness.c -o endianness
./endianness
```

Some examples are split across multiple files. Compile all required translation units together:

```sh
g++ -std=c++98 -Wall -Wextra \
  C++98/00_Why_CPP/DATE_CPP/Date.cpp \
  C++98/00_Why_CPP/DATE_CPP/Date_client.cpp \
  -o date_demo
./date_demo
```

## Notes

- Folder names preserve the original learning sequence, including a few spelling inconsistencies.
- Some files are intentionally written to demonstrate pitfalls, errors, or unsafe techniques. Read the file name and comments before treating an example as recommended production style.
- The code is primarily educational and does not use a single project-wide build system.

## Suggested Learning Path

1. Start with `00_Why_CPP` to compare C-style modular programming with C++ classes.
2. Move through object creation, constructors, initialization, member functions, namespaces, and `const`.
3. Study destructors, dynamic allocation, and copy control together.
4. Learn templates, operator overloading, inheritance, and polymorphism.
5. Finish with iterator/interface patterns, casting, RTTI, and the DSA practice examples.

## Contributing

Keep examples small and focused. When adding a new topic, prefer a separate folder or clearly named source file, and include comments that explain the concept being demonstrated.
