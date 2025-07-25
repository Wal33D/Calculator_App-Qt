#include "calculator.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <stdexcept>

// Function to handle errors by displaying a message box
void handleError(const QString &message, QWidget *parent = nullptr) { QMessageBox::critical(parent, "Error", message); }

// Function to update the display of the calculator with the current input
void updateDisplay(QLineEdit &inputDisplay, const Calculator &myCalculator) {
    inputDisplay.setText(myCalculator.getCurrentInput());
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator myCalculator;
    QWidget mainWindow;
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    QLineEdit *inputDisplay = new QLineEdit(&mainWindow);
    QGridLayout *buttonLayout = new QGridLayout(&mainWindow);

    // Create digit buttons
    for (int i = 0; i <= 9; ++i) {
        QPushButton *digitButton = new QPushButton(QString::number(i));
        digitButton->setObjectName(QString("button%1").arg(i));
        int row = 3 - i / 3;
        int col = i % 3;
        if (i == 0) {
            row = 4;
            col = 1;
        }
        buttonLayout->addWidget(digitButton, row, col);
    }

    // Create operator buttons
    QPushButton *buttonAdd = new QPushButton("+");
    QPushButton *buttonSubtract = new QPushButton("-");
    QPushButton *buttonMultiply = new QPushButton("*");
    QPushButton *buttonDivide = new QPushButton("/");
    QPushButton *buttonModulo = new QPushButton("%");
    QPushButton *buttonPower = new QPushButton("^");
    buttonLayout->addWidget(buttonAdd, 1, 3);
    buttonLayout->addWidget(buttonSubtract, 2, 3);
    buttonLayout->addWidget(buttonMultiply, 3, 3);
    buttonLayout->addWidget(buttonDivide, 4, 3);
    buttonLayout->addWidget(buttonModulo, 0, 0);
    buttonLayout->addWidget(buttonPower, 0, 2);

    // Create clear and calculate buttons
    QPushButton *buttonClear = new QPushButton("C");
    QPushButton *buttonDecimal = new QPushButton(".");
    QPushButton *buttonCalculate = new QPushButton("=");
    buttonLayout->addWidget(buttonClear, 0, 1);
    buttonLayout->addWidget(buttonDecimal, 4, 0);
    buttonLayout->addWidget(buttonCalculate, 4, 2);

    // Add layouts to the main layout
    mainLayout->addWidget(inputDisplay);
    mainLayout->addLayout(buttonLayout);

    // Connect the buttons to the corresponding slots
    for (int i = 0; i <= 9; ++i) {
        QPushButton *digitButton = buttonLayout->findChild<QPushButton *>(QString("button%1").arg(i));
        QObject::connect(digitButton, &QPushButton::clicked, &myCalculator, [&, i] { myCalculator.setDigit(i); });
    }
    QObject::connect(buttonDecimal, &QPushButton::clicked, &myCalculator, &Calculator::setDecimalPoint);

    QObject::connect(buttonAdd, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorAdd);
    QObject::connect(buttonSubtract, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorSubtract);
    QObject::connect(buttonMultiply, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorMultiply);
    QObject::connect(buttonDivide, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorDivide);
    QObject::connect(buttonModulo, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorModulo);
    QObject::connect(buttonPower, &QPushButton::clicked, &myCalculator, &Calculator::setOperatorPower);

    // Connect the buttons to update the display
    auto updateDisplayLambda = [&]() { updateDisplay(*inputDisplay, myCalculator); };

    for (int i = 0; i <= 9; ++i) {
        QPushButton *digitButton = buttonLayout->findChild<QPushButton *>(QString("button%1").arg(i));
        QObject::connect(digitButton, &QPushButton::clicked, updateDisplayLambda);
    }
    QObject::connect(buttonDecimal, &QPushButton::clicked, updateDisplayLambda);

    QObject::connect(buttonAdd, &QPushButton::clicked, updateDisplayLambda);
    QObject::connect(buttonSubtract, &QPushButton::clicked, updateDisplayLambda);
    QObject::connect(buttonMultiply, &QPushButton::clicked, updateDisplayLambda);
    QObject::connect(buttonDivide, &QPushButton::clicked, updateDisplayLambda);
    QObject::connect(buttonModulo, &QPushButton::clicked, updateDisplayLambda);
    QObject::connect(buttonPower, &QPushButton::clicked, updateDisplayLambda);

    // Handle the equal button
    QObject::connect(buttonCalculate, &QPushButton::clicked, [&]() {
        myCalculator.setSecondOperand(myCalculator.getCurrentInput().toDouble());
        try {
            double result = myCalculator.calculateResult();
            inputDisplay->setText(QString::number(result));
        } catch (const std::logic_error &e) {
            handleError(QString::fromStdString(e.what()), &mainWindow);
        }
        myCalculator.clear();
    });

    // Handle the clear button
    QObject::connect(buttonClear, &QPushButton::clicked, [&]() {
        myCalculator.clear();
        inputDisplay->clear();
    });

    mainWindow.setLayout(mainLayout);
    mainWindow.show();

    return app.exec();
}
