#include "../includes/coreBankingSystem.h"

void CoreBankingSystem :: viewCustomerDetails(vector<Customer> &customers, Customer& customer) {
    readCustomersFromCSV(customers);
    bool flag = false;
    for (auto& existingCustomer : customers) {
        if (existingCustomer.getCustomerId() == customer.getCustomerId()) {
            cout << "\n-----Customer Details-----\n";
            cout << "Customer ID: " << existingCustomer.getCustomerId() << endl;
            cout << "Customer Name: " << existingCustomer.getCustomerName() << endl;
            cout << "Type of Customer: " << existingCustomer.getTypeOfCustomer() << endl;
            cout << "Address  : " << existingCustomer.getCustomerAddress() << endl;
            cout << "City: " << existingCustomer.getCustomerCity() << endl;
            cout << "State: " << existingCustomer.getCustomerState() << endl;
            cout << "Country: " << existingCustomer.getCustomerCountry() << endl;
            cout << "Pincode: " << existingCustomer.getCustomerPincode() << endl;
            cout << "Phone Number: " << existingCustomer.getCustomerPhoneNumber() << endl;
            cout << "Email: " << existingCustomer.getCustomerEmail() << endl;
            cout << "PAN: " << existingCustomer.getCustomerPan() << endl;
            flag = true;
        }
    }
    if(flag == true) cout<<"\x1b[32m\nYour Customer Details is mentioned above.\n\x1b[0m";
    else cout<<"\n\x1b[31mCustomer Not Found\n\x1b[0m";
}
void CoreBankingSystem :: transferMoney(vector<Transaction> &transactions, vector<Account> &accounts, Transaction &sourceAccount, Transaction &destinationAccount, double amount) {
    readAccountsFromCSV(accounts);
    readTransactionsFromCSV(transactions);
    bool flag = false;
    for(auto & account : accounts) {  
        if(account.getAccountNumber() == sourceAccount.getSourceAccountId()) {
            if(account.getAccountStatus() == "enable" or account.getAccountStatus() == "Enable") {
                if(account.getAccountBalance() >= amount) {
                    sourceAccount.setTransactionAmount(account.getAccountBalance() - amount);
                    account.setAccountBalance(account.getAccountBalance() - amount);
                    //destinationAccount.setTransactionAmount(account.getAccountBalance() + amount);
                    writeAccountsToCSVAfterTransfer(accounts);

                    long long int transactionId = stoll(generateTransactionId());
                    Transaction transaction(transactionId, 'D', sourceAccount.getSourceAccountId(),
                                            destinationAccount.getDestinationAccountId(), amount, account.getAccountNumber());
                    transactions.push_back(transaction);
                    writeTransactionsToCSV(transactions);
                    cout << "\n\x1b[32mMoney transferred successfully.\x1b[0m" << endl;
                    flag = true;
                    break;
                }
                else {
                    cout << "\x1b[31mInsufficient funds in the source account.\x1b[0m" << endl;
                    return;//
                }
            }
            else {
                cout << "\n\x1b[31mAccount Disabled, Cannot Transfer Money.!!.\x1b[0m\n";
                return;
            }
        }       
    }
    if(flag == true) {  
        for(auto& account : accounts) {  
            if(account.getAccountNumber() == destinationAccount.getDestinationAccountId()) {
                //destinationAccount.setTransactionAmount(account.getAccountBalance() + amount);
                account.setAccountBalance(account.getAccountBalance() + amount);
                writeAccountsToCSVAfterTransfer(accounts);

                long long int transactionId = stoll(generateTransactionId()) - 1;
                Transaction transaction(transactionId, 'C', sourceAccount.getSourceAccountId(),
                                        destinationAccount.getDestinationAccountId(), amount, account.getAccountNumber());
                transactions.push_back(transaction);
                writeTransactionsToCSV(transactions);
                break;
            }       
        } 
    }
    else {
        cout<<"\n\x1b[31mAccount not Found !!!\x1b[0m\n";
    } 
}
void CoreBankingSystem :: queryAccountTransactions(vector<Transaction> &transactions, int accountNumber) {
    readTransactionsFromCSV(transactions);
    bool flag = false;
    for (auto &transaction : transactions) {
        if (transaction.getAccountNumber() == accountNumber) {
            cout << "\nTransaction ID: " << transaction.getTransactionId() << endl;
            cout << "Transaction Type: " << transaction.getTransactionType() << endl;
            cout << "Source Account ID: " << transaction.getSourceAccountId() << endl;
            cout << "Destination Account ID: " << transaction.getDestinationAccountId() << endl;
            cout << "Transaction Amount: " << transaction.getTransactionAmount() << endl;
            cout << endl;
            flag = true;
        }
    }
    if(flag == true) cout<<"\x1b[32mDetails Displayed successfully.\x1b[0m\n";
    else cout<<"\n\x1b[31mTransactions not Found!!.\x1b[0m\n";
}
void CoreBankingSystem :: quitApplication() {
    cout << "\x1b[33mQuitting the application. Goodbye!\x1b[0m\n";
    exit(0);
}
