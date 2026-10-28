#include <iostream>
#include <stack>
#include <string>
#include <limits>

using namespace std;

int main() {
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText = "";
    int choice = 0;

    do {
        cout << "\n===== TEXT EDITOR: UNDO / REDO =====\n";
        cout << "Current text: " << currentText << "\n\n";
        cout << "1. Enter or replace text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string newText;
                cout << "Enter the new text: ";
                getline(cin, newText);

                undoStack.push(currentText);
                currentText = newText;

                // A new edit clears redo history.
                while (!redoStack.empty()) {
                    redoStack.pop();
                }

                cout << "Text updated successfully.\n";
                break;
            }

            case 2:
                if (undoStack.empty()) {
                    cout << "Nothing to undo.\n";
                } else {
                    redoStack.push(currentText);
                    currentText = undoStack.top();
                    undoStack.pop();
                    cout << "Undo successful.\n";
                }
                break;

            case 3:
                if (redoStack.empty()) {
                    cout << "Nothing to redo.\n";
                } else {
                    undoStack.push(currentText);
                    currentText = redoStack.top();
                    redoStack.pop();
                    cout << "Redo successful.\n";
                }
                break;

            case 4:
                cout << "Exiting editor. Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
