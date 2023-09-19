#include"../src/account.cpp"
class Transaction {
private:
    long long int transactionId;
    char transactionType; // credit or debit
    int sourceAccountId;
    int destinationAccountId;
    double transactionAmount;
    int accountNumber;

public:
    Transaction(); 
    Transaction(long long int, char, int, int, double, int);
    long long int getTransactionId();
    char getTransactionType();      //credit or debit
    int getSourceAccountId();
    int getDestinationAccountId();
    double getTransactionAmount();
    int getAccountNumber();
    
    void setTransactionId(long long int);
    void setTransactionType(char);      //credit or debit
    void setSourceAccountId(int);
    void setDestinationAccountId(int);
    void setTransactionAmount(double);
    void setAccountNumber(int);
};