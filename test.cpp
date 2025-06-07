#include "test.h"
#include <QtCore/QDebug>
#include <stdexcept>

void test() {
    Calculator calc;

    // Test addition
    calc.setFirstOperand(3);
    calc.setSecondOperand(5);
    calc.setOperator('+');
    double result = calc.calculateResult();
    if (result != 8) {
        handleError("Addition test failed.");
    }

    // Test subtraction
    calc.setFirstOperand(10);
    calc.setSecondOperand(4);
    calc.setOperator('-');
    result = calc.calculateResult();
    if (result != 6) {
        handleError("Subtraction test failed.");
    }

    // Test multiplication
    calc.setFirstOperand(3);
    calc.setSecondOperand(7);
    calc.setOperator('*');
    result = calc.calculateResult();
    if (result != 21) {
        handleError("Multiplication test failed.");
    }

    // Test division
    calc.setFirstOperand(20);
    calc.setSecondOperand(4);
    calc.setOperator('/');
    result = calc.calculateResult();
    if (result != 5) {
        handleError("Division test failed.");
    }

    // Test division by zero and recovery
    calc.setFirstOperand(20);
    calc.setSecondOperand(0);
    calc.setOperator('/');
    try {
        result = calc.calculateResult();
        handleError("Division by zero test failed.");
    } catch (const std::logic_error& e) {
        handleError("Division by zero test passed: " + QString::fromStdString(e.what()));
    } catch (...) {
        handleError("Division by zero test failed.");
    }
    calc.clear();
    calc.setFirstOperand(1);
    calc.setSecondOperand(1);
    calc.setOperator('+');
    result = calc.calculateResult();
    if (result != 2) {
        handleError("Calculator not cleared after division by zero.");
    }

    qDebug() << "All tests passed.";
}
