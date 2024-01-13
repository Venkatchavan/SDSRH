# COVID-19 Patient Data and Vaccination Management - Functional Programming

## Overview

This C++ project adopts functional programming principles to manage COVID-19 patient data and vaccination appointments. It emphasizes side-effect-free functions, leverages closures and anonymous functions, and makes extensive use of higher-order functions.

## Data Structures

### Patient Data

```cpp
struct Patient {
    char dbuno[15];
    char name[20];
    char age[5];
    char phone[11];
    char hospital[20];
};

```

### Index

```cpp
struct Index {
    char ibuno[15];
    char addr[5];
};

```

### Secondary Index

```cpp
struct SIndex {
    char sname[20];
    char sbuno[15];
};

```

### Vaccination Data

```cpp
struct Vaccination {
    char daadaar[15];
    char name[15];
    char age[5];
    char gender[2];
    char phone[11];
    char address[25];
};

```

### Vaccination Index

```cpp
struct VIndex {
    char iaadaar[15];
    char addr[5];
};

```

### Vaccination Secondary Index

```cpp
struct SVIndex {
    char sname[20];
    char saadaar[15];
};

```

### Appointment Slot

```cpp
struct Appointment {
    int status;
    char start[10];
    char end[10];
    char max[10];
    char min[10];
    struct Appointment* Next;
};

```

## Functional Programming Concepts

1. **Side-Effect-Free Functions:** Functions are designed to minimize side effects, ensuring data purity.

2. **Closures/Anonymous Functions:** Leveraged for encapsulation, creating functions within functions for localized behavior.

3. **Higher-Order Functions:** Functions that take functions as parameters or return functions:

    - `search` and `sec_search` accept a function pointer for customized searching.
    
    - `initial` and `sinitial` initialize index and secondary index structures.
    
    - `write` and `swrite` update index and secondary index files.

    - `unpack` and `display_SLL` are higher-order functions for data unpacking and display in different contexts.

## Usage

1. Compile and run the project in a C++ environment.
2. Explore the codebase for detailed implementations of data structures and functional programming concepts.
3. Refer to the comments within the source code for additional insights.

## Functional Programming Cheat Sheet

- Design functions to be stateless, avoiding side effects on external variables.
- Leverage lambda functions for encapsulation and concise, localized behavior.
- Use function pointers for customizing behaviors within higher-order functions.
- Minimize mutable state; prefer immutable data structures for enhanced predictability.

