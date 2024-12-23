#include <iostream>
using namespace std;

void displayMenu() {
    cout << "==========================\n";
    cout << "       CALCULATOR        \n";
    cout << "==========================\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "==========================\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;

            switch (choice) {
                case 1:
                    result = num1 + num2;
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
                    break;
                case 2:
                    result = num1 - num2;
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
                    break;
                case 3:
                    result = num1 * num2;
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
                    break;
                case 4:
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                    } else {
                        cout << "Error: Division by zero is not allowed.\n";
                    }
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } else if (choice == 5) {
            cout << "Exiting the calculator. Goodbye!\n";
        } else {
            cout << "Invalid option. Please choose a valid option.\n";
        }

        cout << "\n"; // Add space before the next menu
    } while (choice != 5);

    return 0;
}
