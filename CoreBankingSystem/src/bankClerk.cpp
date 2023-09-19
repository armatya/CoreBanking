#include "../includes/bankClerk.h"

void writeCustomersToCSV(vector<Customer>& customers);
void writeCustomersToCSVAfterDelete(vector<Customer>& customers);
void writeCustomersToCSVAfterModify(vector<Customer>& customers);
void writeAccountsToCSV(vector<Account>& accounts);
void writeAccountsToCSVAfterDelete(vector<Account>& accounts);
void writeAccountsToCSVAfterCreditDebit(vector<Account>& accounts) ;
void readCustomersFromCSV(vector<Customer>& customers);
void readAccountsFromCSV(vector<Account>& accounts);
void readTransactionsFromCSV(vector<Transaction>& transactions);
void writeTransactionsToCSV(vector<Transaction>& transactions);
void writeUserToCSV(vector<User>& users);
void readUserFromCSV(vector<User>& users);
void writeUserToCSVAfterLogin(vector <User>& users);
void writeUserToCSVAfterDelete(vector <User>& users);
void writeAccountsToCSVAfterTransfer(vector<Account>& accounts);

void BankClerk :: addCustomer(vector<User>& users, vector<Customer>& customers, vector<Account>& accounts, User &user, Customer& customer, Account& account) {
    customers.push_back(customer);
    writeCustomersToCSV(customers);

    accounts.push_back(account);
    writeAccountsToCSV(accounts);

    users.push_back(user);
    writeUserToCSV(users);
    
    cout << "\n\x1b[32mCustomer data added successfully to customers.csv\x1b[0m" << endl;
    cout << "\x1b[32mAccount data added successfully to accounts.csv\x1b[0m" << endl;
    cout << "\x1b[32mUser data added successfully to accounts.csv\x1b[0m" << endl;
}
void BankClerk :: deleteCustomer(vector<User>& users, vector<Customer>& customers,vector<Account>& accounts, string& customerId) {
    readCustomersFromCSV(customers);
    readAccountsFromCSV(accounts);
    readUserFromCSV(users);
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->getCustomerId() == customerId) {
            customers.erase(it);
            writeCustomersToCSVAfterDelete(customers);
            cout << "\x1b[31m\nCustomer Data deleted successfully.\x1b[0m\n";
            break;
        }
    }   
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {        
        if (it->getCustomerId() == customerId) {            
            accounts.erase(it);
            writeAccountsToCSVAfterDelete(accounts);
            cout << "\x1b[31mAccounts Data for perticular Customer is Deleted successfully.\x1b[0m\n";
            break;
        }
    }
    for (auto it = users.begin(); it != users.end(); ++it) {        
        if (it->getCustomerId() == customerId) {            
            users.erase(it);
            writeUserToCSVAfterDelete(users);
            cout << "\x1b[31mUsers Data for perticular Customer is Deleted successfully.\x1b[0m\n";
            return;
        }
    }
    cout << "\x1b[31mCustomer already does not Exists !!!.\x1b[0m\n";
}
void BankClerk :: modifyCustomer(vector<Customer>& customers, Customer& customer, string &customerId) {
    for (auto& existingCustomer : customers) {
        if (existingCustomer.getCustomerId() == customerId) {
            existingCustomer = customer;
            writeCustomersToCSVAfterModify(customers);
            return;
        }        
    }   
}
void BankClerk :: creditMoney(vector<Account> &accounts, vector<Transaction> &transactions, int accountNumber, double amount) {
    readAccountsFromCSV(accounts);
    readTransactionsFromCSV(transactions);
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            if(account.getAccountStatus() == "enable" or account.getAccountStatus() == "Enable") {
                account.setAccountBalance(account.getAccountBalance() + amount); 
                writeAccountsToCSVAfterCreditDebit(accounts);            //account.balance += amount;
                cout << "\n\x1b[32mMoney credited to account successfully.\x1b[0m\n";
                long long int transactionId = stoll(generateTransactionId());
                Transaction transaction(transactionId, 'C', account.getAccountNumber(),
                                        account.getAccountNumber(), amount, account.getAccountNumber());
                transactions.push_back(transaction);
                writeTransactionsToCSV(transactions);
                return;
            }
            else {
                cout << "\n\x1b[31mAccount Disabled, Can't Credit Money.!!.\x1b[0m\n";
                return;
            }
        }
    }
    cout << "\n\x1b[31mAccount not found.\x1b[0m\n";
}
void BankClerk :: debitMoney(vector<Account>& accounts, vector<Transaction> &transactions, int accountNumber, double amount) {
    readAccountsFromCSV(accounts);
    readTransactionsFromCSV(transactions);
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            if(account.getAccountStatus() == "enable" or account.getAccountStatus() == "Enable") {
                if (account.getAccountBalance() >= amount) {
                    account.setAccountBalance(account.getAccountBalance() - amount);
                    writeAccountsToCSVAfterCreditDebit(accounts);         //account.balance -= amount;
                    
                    long long int transactionId = stoll(generateTransactionId());
                    Transaction transaction(transactionId, 'D', account.getAccountNumber(),
                                            account.getAccountNumber(), amount, account.getAccountNumber());
                    transactions.push_back(transaction);
                    writeTransactionsToCSV(transactions);
                    cout << "\x1b[32m\nMoney debited from account successfully.\x1b[0m\n";
                    return;
                } else {
                    cout << "\x1b[31m\nInsufficient balance in the account.\x1b[0m\n";
                    return;
                }
            } 
            else {
                cout << "\n\x1b[31mAccount Disabled, Can't Debit Money.!!.\x1b[0m\n";
                return;
            }           
        }
    }
    cout << "\x1b[31m\nAccount not found.\x1b[0m\n";
}
void BankClerk :: queryAccount(vector<Account>& accounts, int accountNumber) {
    readAccountsFromCSV(accounts);
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            cout << "Account Number: " << account.getAccountNumber() << endl;
            cout << "Account Type: " << account.getAccountType() << endl;
            cout << "Account Status: " << account.getAccountStatus() << endl;
            cout << "Balance: " << account.getAccountBalance() << endl;
            return;
        }
    }
    cout << "\n\x1b[31mAccount not found.\x1b[0m\n";
} 
