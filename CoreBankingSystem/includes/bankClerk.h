#include"../src/transaction.cpp"

class BankClerk {
public :
    void addCustomer(vector<User>& users, vector<Customer>& customers, vector<Account>& accounts, User &user, Customer& customer, Account& account);
    void deleteCustomer(vector<User>& users, vector<Customer>& customers,vector<Account>& accounts, string& customerId);
    void modifyCustomer(vector<Customer>& customers, Customer& customer, string &customerId);
    void creditMoney(vector<Account>& accounts, vector<Transaction> &transactions, int accountNumber, double amount);
    void debitMoney(vector<Account>& accounts, vector<Transaction> &transactions, int accountNumber, double amount);
    void queryAccount(vector<Account>& accounts, int accountNumber);
private:
    string generateTransactionId() {
        time_t currentTime = time(NULL);
        stringstream ss;
        ss << put_time(localtime(&currentTime), "%Y%m%d%H%M%S");
        return ss.str();
    }
};
