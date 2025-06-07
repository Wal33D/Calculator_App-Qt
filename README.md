# Qt Calculator

A simple calculator application built with **C++** and **Qt Widgets**. It provides a basic interface for performing addition, subtraction, multiplication and division with support for decimal numbers. The project includes a unit test suite using the Qt Test framework and a GitHub Actions workflow to build and test the code automatically.

## Features

- Buttons for digits 0&ndash;9 and the four standard arithmetic operators
- Decimal point input
- Clear and equals buttons
- Error handling for invalid operations such as division by zero
- Modulo operator (`%`)
- Exponentiation operator (`^`)

## Requirements

- Qt 5.15 or newer
- A C++11 compatible compiler

## Building

1. Clone the repository
   ```bash
   git clone <repo_url>
   cd Calculator_App-Qt
   ```
2. Generate the Makefile with `qmake` and build
   ```bash
   qmake calculator.pro
   make
   ```

## Running

After building you can start the calculator with:
```bash
./calculator
```

## Running the Tests

The test suite is located in `tests/`.
```bash
qmake tests.pro
make
make check    # runs ./calculator_test
```
The environment variable `QT_QPA_PLATFORM=offscreen` can be used to run tests without a display, as shown in the workflow file.

## Code Style

Formatting rules are defined in `.clang-format`. Run
```bash
clang-format -i <file>
```
before committing to keep the style consistent.

## Continuous Integration

The GitHub Actions workflow in `.github/workflows/qt.yml` builds the project and executes the test suite on every push and pull request.

## License

This project is released under the [MIT License](LICENSE).
