#include <iostream>

using namespace std;

// Abstraction in Object-Oriented Programming (OOP) refers to the concept of hiding the complex implementation details
// and showing only the necessary functionalities to the user. It allows the user to interact with the system without
// worrying about the underlying complexity.

// To demonstrate abstraction, let’s create a C++ program where we abstract the internal details of a BankAccount class.
// The user will only be concerned with operations like deposit(), withdraw(), and checkBalance(), while the internal workings are hidden.

class BankAccount
{ // BankAccount class demonstrates abstraction by hiding internal details
private:
    double balance; // Private attribute to store account balance

public:
    // Constructor to initialize the balance
    BankAccount(double initialBalance)
    {
        balance = initialBalance;
    }

    // Public method to deposit money (abstracting the internal balance update)
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public method to withdraw money (abstracting the internal balance check)
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Public method to check the balance (abstracting the internal balance representation)
    double checkBalance() const
    {
        return balance;
    }
};

int main()
{
    // Creating a BankAccount object with an initial balance of $1000
    BankAccount myAccount(1000);

    // Using abstracted methods to perform operations on the account
    myAccount.deposit(500);  // Deposit $500
    myAccount.withdraw(200); // Withdraw $200

    // Checking the balance
    cout << "Current Balance: $" << myAccount.checkBalance() << endl;

    // Attempt to withdraw more than the balance
    myAccount.withdraw(2000);

    // Check balance after failed withdrawal
    cout << "Current Balance: $" << myAccount.checkBalance() << endl;

    // Key Points in the Example:

    // 1. Abstraction: The BankAccount class hides the complex details of how the balance is stored and modified.
    //    The user only interacts with simple, well-defined methods: deposit(), withdraw(), and checkBalance().

    // 2. Private Data: The balance is stored as a private member variable, and the user cannot modify it directly.
    //    The class provides controlled access through public methods.

    // 3. Simple Interface: The public methods provide an easy-to-understand interface, so the user doesn’t need
    //    to worry about the internal workings of the BankAccount.

    return 0;
}