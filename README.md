# Simple Qt Calculator

A straightforward calculator application written in C++ that leverages the Qt library for the graphical user interface (GUI). This calculator offers basic arithmetic operations, including addition, subtraction, multiplication, and division.

## Features

- Basic arithmetic operations: addition, subtraction, multiplication, and division
- User-friendly interface with a display for input and results
- Buttons for digits, operators, and essential calculator functions like clearing and calculating the final result

## Prerequisites

- Qt 5 or higher (tested with Qt 5.15)
- C++ compiler with C++11 support

## Building and Running

1. Clone the repository:
```bash
git clone https://github.com/your_username/simple-qt-calculator.git
cd simple-qt-calculator
```
2. Generate the Makefile using `qmake` and build the project:
```bash
qmake calculator.pro
make
```
3. Run the calculator:
```bash
./calculator
```
The application executes a set of simple tests defined in `test.cpp` when it starts.
The results are printed to the console before the GUI appears.
