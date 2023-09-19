#include"../src/bankClerk.cpp"

class CoreBankingSystem {    
public:
    void viewCustomerDetails(vector<Customer> &customers, Customer& customer);
    void transferMoney(vector<Transaction> &transactions, vector<Account> &accounts, Transaction&, Transaction& , double);
    void queryAccountTransactions( vector<Transaction> &transactions, int );
    void quitApplication();
private:
    string generateTransactionId() {
        time_t currentTime = time(NULL);
        stringstream ss;
        ss << put_time(localtime(&currentTime), "%Y%m%d%H%M%S");
        return ss.str();
    }
};
