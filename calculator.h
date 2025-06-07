#pragma once

#include <QObject>
#include <QString>

// Calculator class inherits from QObject and uses the Q_OBJECT macro
class Calculator : public QObject {
    Q_OBJECT

  public:
    // Constructor
    Calculator();

    // Basic arithmetic operations
    double add(double x, double y);
    double subtract(double x, double y);
    double multiply(double x, double y);
    double divide(double x, double y);
    double modulo(double x, double y);
    double power(double base, double exponent);

    // Calculates the result based on the operator and operands
    double calculateResult();

    // Setters for operands and operator
    void setFirstOperand(double x);
    void setSecondOperand(double y);
    void setOperator(char op);

    // Clears the calculator state
    void clear();

    // Getter for the current input
    QString getCurrentInput() const;

  public slots:
    // Slot functions for handling user input
    void setDigit(int digit);
    void setDecimalPoint();
    void setOperatorAdd();
    void setOperatorSubtract();
    void setOperatorMultiply();
    void setOperatorDivide();
    void setOperatorModulo();
    void setOperatorPower();

  private:
    // Member variables to store operands, operator, and current input
    double m_firstOperand;
    double m_secondOperand;
    char m_operator;
    QString m_currentInput;
};
