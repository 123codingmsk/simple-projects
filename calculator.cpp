#include <iostream>
#include <cmath>

using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return NAN; // Return NaN for division by zero
    }
}

// Function for square root
double squareRoot(double a) {
    return sqrt(a);
}

// Function for power
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Function for sine
double sine(double angle) {
    return sin(angle);
}

// Function for cosine
double cosine(double angle) {
    return cos(angle);
}

// Function for tangent
double tangent(double angle) {
    return tan(angle);
}

// Main function
int main() {
    double num1, num2;
    char operation;
    cout << "Scientific Calculator" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Select operation (+, -, *, /, sqrt, pow, sin, cos, tan): ";
    cin >> operation;

    if (operation == 's') { // square root
        cout << "Square root of " << num1 << " = " << squareRoot(num1) << endl;
    } else if (operation == 'p') { // power
        cout << "Enter exponent: ";
        cin >> num2;
        cout << num1 << " raised to the power " << num2 << " = " << power(num1, num2) << endl;
    } else {
        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) {
            case '+':
                cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                break;
            case 's':
                cout << "sin(" << num1 << ") = " << sine(num1) << endl;
                break;
            case 'c':
                cout << "cos(" << num1 << ") = " << cosine(num1) << endl;
                break;
            case 't':
                cout << "tan(" << num1 << ") = " << tangent(num1) << endl;
                break;
            default:
                cout << "Error: Invalid operation!" << endl;
        }
    }

    return 0;
}
