#include "calculator.h"
#include <stdexcept>

// Constructor: initializes member variables
Calculator::Calculator() {
    m_firstOperand = 0;
    m_secondOperand = 0;
    m_operator = '\0';
}

// Function to add two numbers
double Calculator::add(double x, double y) {
    return x + y;
}

// Function to subtract two numbers
double Calculator::subtract(double x, double y) {
    return x - y;
}

// Function to multiply two numbers
double Calculator::multiply(double x, double y) {
    return x * y;
}

// Function to divide two numbers
double Calculator::divide(double x, double y) {
    if (y == 0) {
        throw std::logic_error("Division by zero");
    }
    return x / y;
}

// Function to calculate the result based on the operator and operands
double Calculator::calculateResult() {
    switch (m_operator) {
        case '+':
            return add(m_firstOperand, m_secondOperand);
        case '-':
            return subtract(m_firstOperand, m_secondOperand);
        case '*':
            return multiply(m_firstOperand, m_secondOperand);
        case '/':
            return divide(m_firstOperand, m_secondOperand);
        default:
            return 0;
    }
}

// Function to set the first operand
void Calculator::setFirstOperand(double x) {
    m_firstOperand = x;
}

// Function to set the second operand
void Calculator::setSecondOperand(double y) {
    m_secondOperand = y;
}

// Function to set the operator
void Calculator::setOperator(char op) {
    m_operator = op;
}

// Function to clear the calculator state
void Calculator::clear() {
    m_firstOperand = 0;
    m_secondOperand = 0;
    m_operator = '\0';
    m_currentInput.clear();
}

// Function to get the current input as a QString
QString Calculator::getCurrentInput() const {
    return m_currentInput;
}

// Function to append a digit to the current input
void Calculator::setDigit(int digit) {
    m_currentInput.append(QString::number(digit));
}

// Function to append a decimal point to the current input if not already present
void Calculator::setDecimalPoint() {
    if (!m_currentInput.contains('.')) {
        if (m_currentInput.isEmpty()) {
            m_currentInput.append("0.");
        } else {
            m_currentInput.append('.');
        }
    }
}

// Function to set the addition operator and store the first operand
void Calculator::setOperatorAdd() {
    setFirstOperand(m_currentInput.toDouble());
    setOperator('+');
    m_currentInput.clear();
}

// Function to set the subtraction operator and store the first operand
void Calculator::setOperatorSubtract() {
    setFirstOperand(m_currentInput.toDouble());
    setOperator('-');
    m_currentInput.clear();
}

// Function to set the multiplication operator and store the first operand
void Calculator::setOperatorMultiply() {
    setFirstOperand(m_currentInput.toDouble());
    setOperator('*');
    m_currentInput.clear();
}

// Function to set the division operator and store the first operand
void Calculator::setOperatorDivide() {
    setFirstOperand(m_currentInput.toDouble());
    setOperator('/');
    m_currentInput.clear();
}
