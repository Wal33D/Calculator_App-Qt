QT += core testlib
CONFIG += console c++11 testcase
TARGET = calculator_test
TEMPLATE = app

SOURCES += calculator.cpp \
           tests/tst_calculator.cpp

HEADERS += calculator.h
