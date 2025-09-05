# 🖥️ CPP00 - 1337 Project

### Introduction to C++: Namespaces, Classes, and Basic Concepts

---

## 📜 Project Overview

This module is the starting point of your C++ journey. It introduces you to **Object-Oriented Programming (OOP)** in a step-by-step manner. The exercises gradually increase in complexity, covering essential C++ concepts.  

> ⚠️ All code must follow the **C++98 standard**.

---

## 🚀 Features

### ✅ Mandatory Exercises

1. **Exercise 00: Megaphone**  
   - Takes command-line arguments and prints them in **uppercase**.  
   - If no arguments are provided, prints the default message:  
     ```
     * LOUD AND UNBEARABLE FEEDBACK NOISE *
     ```

2. **Exercise 01: My Awesome PhoneBook**  
   - Implements a simple phonebook with two classes: `PhoneBook` and `Contact`.  
   - Supports **adding, searching, and displaying contacts**.  
   - Stores a maximum of **8 contacts** in an array.  
   - **Dynamic memory allocation is forbidden**.

### ⚠️ Optional Exercise

3. **Exercise 02: The Job Of Your Dreams**  
   - Recreate a lost C++ source file (`Account.cpp`) using the provided header (`Account.hpp`) and a log file as reference.  
   - Completing this exercise is **optional** for passing the module.

---

## 🛠️ Installation & Compilation

Navigate to the exercise directory and run:

```bash
make
```

### 📌 Compilation Flags

```bash
-Wall -Wextra -Werror -std=c++98
```

> Ensures your code adheres to the **C++98 standard**.

### 🔧 Cleanup Commands

```bash
make clean      # Remove object files
make fclean     # Remove executable and object files
make re         # Full rebuild
```

---

## 📏 Rules & Guidelines

* **Language Standard:** Follow **C++98**.
* **Forbidden Functions:** `printf()`, `malloc()`, `free()`, etc. Violations result in a **grade of 0**.
* **STL:** Standard Template Library containers (`vector`, `list`, `map`, etc.) are forbidden until Modules 08 and 09.
* **Memory Management:** Properly deallocate any memory allocated with `new`.
* **Headers:** Include **include guards** in all header files.
* **Output:** Every message must end with a newline and be printed to **standard output**.

---

## ⚙️ Core Concepts Covered

* **Namespaces:** Organize code and prevent name conflicts.
* **Classes & Member Functions:** Combine data and functions, introducing OOP principles.
* **Standard I/O Streams:** Use `std::cin` and `std::cout` instead of C-style I/O.

---

## 📄 References

For complete project details, see the subject file:
[en.subject.pdf](https://github.com/Redadaghouj/42-cpp00_1337/subject/en.subject.pdf)

```
