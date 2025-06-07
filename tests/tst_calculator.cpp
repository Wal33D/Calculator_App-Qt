#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
private slots:
    void addition();
    void subtraction();
    void multiplication();
    void division();
    void divisionByZero();
    void clearAfterError();
    void decimalAddition();
};

void CalculatorTest::addition()
{
    Calculator calc;
    calc.setFirstOperand(3);
    calc.setSecondOperand(5);
    calc.setOperator('+');
    QCOMPARE(calc.calculateResult(), 8.0);
}

void CalculatorTest::subtraction()
{
    Calculator calc;
    calc.setFirstOperand(10);
    calc.setSecondOperand(4);
    calc.setOperator('-');
    QCOMPARE(calc.calculateResult(), 6.0);
}

void CalculatorTest::multiplication()
{
    Calculator calc;
    calc.setFirstOperand(3);
    calc.setSecondOperand(7);
    calc.setOperator('*');
    QCOMPARE(calc.calculateResult(), 21.0);
}

void CalculatorTest::division()
{
    Calculator calc;
    calc.setFirstOperand(20);
    calc.setSecondOperand(4);
    calc.setOperator('/');
    QCOMPARE(calc.calculateResult(), 5.0);
}

void CalculatorTest::divisionByZero()
{
    Calculator calc;
    calc.setFirstOperand(20);
    calc.setSecondOperand(0);
    calc.setOperator('/');
    QVERIFY_EXCEPTION_THROWN(calc.calculateResult(), std::logic_error);
}

void CalculatorTest::clearAfterError()
{
    Calculator calc;
    calc.setFirstOperand(20);
    calc.setSecondOperand(0);
    calc.setOperator('/');
    try {
        calc.calculateResult();
    } catch (const std::logic_error &) {
        // expected
    }
    calc.clear();
    calc.setFirstOperand(1);
    calc.setSecondOperand(1);
    calc.setOperator('+');
    QCOMPARE(calc.calculateResult(), 2.0);
}

void CalculatorTest::decimalAddition()
{
    Calculator calc;
    calc.setFirstOperand(2.5);
    calc.setSecondOperand(0.5);
    calc.setOperator('+');
    QCOMPARE(calc.calculateResult(), 3.0);
}

QTEST_MAIN(CalculatorTest)
#include "tst_calculator.moc"
