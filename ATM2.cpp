#include <iostream>
using namespace std;

class Account {

private:
    int accNo;
    int pin;
    double balance;

public:

    void createAccount() {

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cout << "Enter PIN: ";
        cin >> pin;

        cout << "Enter Balance: ";
        cin >> balance;
    }

    bool login(int a, int p) {

        if(accNo == a && pin == p) {
            return true;
        }

        return false;
    }

    void menu() {

        int choice;
        double amount;

        do {

            cout << "\n====== ATM MENU ======" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter Choice: ";
            cin >> choice;

            switch(choice) {

                case 1:

                    cout << "\nCurrent Balance: " << balance << endl;
                    break;

                case 2:

                    cout << "\nEnter Amount: ";
                    cin >> amount;

                    balance += amount;

                    cout << "\nDeposit Successful!" << endl;
                    break;

                case 3:

                    cout << "\nEnter Amount: ";
                    cin >> amount;

                    if(amount <= balance) {

                        balance -= amount;

                        cout << "\nWithdraw Successful!" << endl;
                    }
                    else {

                        cout << "\nInsufficient Balance!" << endl;
                    }

                    break;

                case 4:

                    cout << "\nThank You!" << endl;
                    break;

                default:

                    cout << "\nInvalid Choice!" << endl;
            }

        } while(choice != 4);
    }
};

int main() {

    int n;

    cout << "Enter Number of Users: ";
    cin >> n;

    Account users[n];

    for(int i=0; i<n; i++) {

        cout << "\n===== Create Account " << i + 1 << " =====" << endl;

        users[i].createAccount();
    }

    int acc, pin;
    bool found = false;

    cout << "\n===== ATM LOGIN =====" << endl;

    cout << "Enter Account Number: ";
    cin >> acc;

    cout << "Enter PIN: ";
    cin >> pin;

    for(int i=0; i<n; i++) {

        if(users[i].login(acc, pin)) {

            cout << "\nLogin Successful!" << endl;

            users[i].menu();

            found = true;

            break;
        }
    }

    if(found == false) {

        cout << "\nInvalid Account or PIN!" << endl;
    }

    return 0;
}
