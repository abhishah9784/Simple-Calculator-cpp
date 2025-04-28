#include<iostream>
using namespace std;

class Calculator {
    int num[100], choice;

public:
    Calculator() {
        cout << "Enter the First Number: ";
        cin >> num[0];
    }

    void takeOperation() {
        cout << "\nChoose the Operation You want to perform\n";
        cout << "1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n5. Exit\n";
        cin >> choice;
        
        if (choice < 1 || choice > 5) {
            cout << "Invalid Choice! Please select a valid option (1-5).\n";
            choice = 0;
        }
    }

    void newNum(int i) {
        cout << "Input Next Number: ";
        cin >> num[i];
    }

    void calculate(int i) {
        switch (choice) {
            case 1:
                num[0] += num[i];
                break;
            case 2:
                num[0] -= num[i];
                break;
            case 3:
                if (num[i] == 0) {
                    cout << "Error! Division by zero is not possible.\n";
                } else {
                    num[0] /= num[i];
                }
                break;
            case 4:
                if (num[i] == 0) {
                    char opt;
                    cout << "Multiplying by zero will make the result zero.\nDo you wish to continue? (Y/N): ";
                    cin >> opt;
                    if (opt == 'Y' || opt == 'y') {
                        num[0] *= num[i];
                    }
                } else {
                    num[0] *= num[i];
                }
                break;
            case 5:
                cout << "Exiting the calculator...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
        cout << "Current Result: " << num[0] << endl;
    }

    void nextNumber() {
        int i = 1;
        while (true) {
            takeOperation();
            if (choice == 5) break;
            if (choice != 0) {
                newNum(i);
                calculate(i);
                i++;
            }
        }
    }
};

int main() {
    Calculator obj;
    obj.nextNumber();
    return 0;
}
