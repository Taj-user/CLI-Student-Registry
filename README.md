# CLI-Student-Registry

This is a command-line student records management system written in pure C. Supports adding, searching, deleting and listing student records. All data is persisted to a binary(.dat) file between sessions using a dynamically resizing heap-allocated array.

---

## Features

- Add students with name, major, age, GPA and year
- Search student registry by name or ID
- Delete students by ID
- List all registered students
- Automatic unique ID assignment
- Binary file persistence - data survives after program restarts
- Dynamic memory - the internal array grows automatically as students are added

---

## Project Structure

```
student_registry/
├───build				# Contains build files
│
├───data
│       student.dat		# Binary data file (auto created on first save)
│
├───include
│       fileio.h		# File path constant nad I/O prototypes
│       menu.h			# menu_run prototype
│       registry.h		# Registry struct definition and prototypes
│       student.h		# Student struct definition and prototypes
│
├───src
│       fileio.c		# Binary file save and load
│       main.c			# Entry point - Initializes registry, loads registry from file, runs menu, saves registry and frees registry after use
│		menu.c			# User input loop and menu dispatch
│		registry.c		# In memory array management with dynamic resizing
│		student.c		# Single record operations - create student, validate student, print student
│
├───CMakeLists.txt
└───README.md
```

---

## Build Instructions

### Using CMake (recommended)

```bash
mkdir build
cd build
cmake ..
ninja/make based on if your system uses Unix MakeFiles
```

The executable is placed in the 'build/' directory.

### Using Make directly

```bash
make
```

---

## Running the Program

Always run from the project root so the binary file resolves to 'data/student.dat' correctly:

```bash
./build/student_registry
```

---

## Usage

On launch the program loads any previously saved records and presents a menu:

```
=== Student Registry ===
1. Add Student
2. Delete Student
3. Search student by ID
4. Search student by Name
5. List all students
0. Exit
Enter you choice: 
```

### Add Student
