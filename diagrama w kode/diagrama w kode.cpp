#include <iostream>
#include <cmath>
#include <string>  

using namespace std;

int CalculateLeft(int x, int n, double start, double end, double step) {
    double sum = 0;
    for (double i = start; i <= end; i += step) {
        sum += (i + x * x);
    }
    return sum - 3 * pow(x, 3);
}

int CalculateRight(int x, int n, double start, double end, double step) {
    double mlt = 1;

    for (int j = 1; j <= n; j++) {
        double sum = 0;
        for (double i = start; i <= end; i += step) {
            if (8 + pow(j, 2) == 0) {
                cout << "Error: Division by zero detected." << endl;
                return 0;
            }
            sum += (2 * i + ((i - 4) / (8 + pow(j, 2))));
        }
        mlt *= sum;
    }

    return 6 - mlt;
}

bool isValidInteger(const string& input) {
    if (input.empty()) return false;

    for (char c : input) {
        if (!isdigit(c) && c != '-' && c != '+') {
            return false;
        }
    }

    return true;
}

bool isDouble(const string& input) {
    try {
        stod(input);
    }
    catch (...) {
        return false;
    }
    return true;
}

void ProcessInterval(int x, int n) {
    string inputStart, inputEnd, inputStep;
    double start, end, step;

    
    while (true) {
        cout << "Enter the start of the interval: ";
        cin >> inputStart;
        if (isDouble(inputStart)) {
            start = stod(inputStart);
            break;
        }
        cout << "Error: Start of the interval must be a valid number." << endl;
    }

    while (true) {
        cout << "Enter the end of the interval: ";
        cin >> inputEnd;
        if (isDouble(inputEnd)) {
            end = stod(inputEnd);
            if (start > end) {
                cout << "Error: The start of the interval cannot be greater than the end." << endl;
            }
            else {
                break;
            }
        }
        else {
            cout << "Error: End of the interval must be a valid number." << endl;
        }
    }


    while (true) {
        cout << "Enter the step size: ";
        cin >> inputStep;
        if (isDouble(inputStep)) {
            step = stod(inputStep);
            if (step <= 0) {
                cout << "Error: Step size must be greater than 0." << endl;
            }
            else if (step > (end - start)) {
                cout << "Error: Step size cannot be greater than the interval size." << endl;
            }
            else {
                break;
            }
        }
        else {
            cout << "Error: Step size must be a valid number." << endl;
        }
    }

  
    if (x < 1) {
        cout << "Result (x < 1): x = " << CalculateLeft(x, n, start, end, step) << endl;
    }
    else {
        cout << "Result (x >= 1): y = " << CalculateRight(x, n, start, end, step) << endl;
    }
}

int main() {
    string input;

    while (true) {
        cout << "Enter 'quit' to exit or 'x' and 'n' (n > 5) to continue:" << endl;

       
        cout << "Enter x (or type 'quit' to exit): ";
        cin >> input;

        if (input == "quit") {
            cout << "Exiting the program." << endl;
            break;
        }

        if (!isValidInteger(input)) {
            cout << "Error: x must be a valid integer." << endl;
            continue;
        }

        int x = stoi(input);

       
        int n;
        while (true) {
            cout << "Enter n (n > 5): ";
            cin >> input;

            if (!isValidInteger(input)) {
                cout << "Error: n must be a valid integer." << endl;
                continue;
            }

            n = stoi(input);

            if (n <= 5) {
                cout << "Error: n must be greater than 5." << endl;
                continue;
            }

            break;
        }

        ProcessInterval(x, n);
    }

    return 0;
}
