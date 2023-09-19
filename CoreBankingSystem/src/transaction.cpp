#include"../includes/transaction.h"

Transaction :: Transaction(){
    transactionId = 0;
    transactionType = '\0'; // credit or debit
    sourceAccountId = 0;
    destinationAccountId = 0;
    transactionAmount = 0.0;
    accountNumber = 0;
} 
Transaction :: Transaction(long long int transactionId, char transactionType, int sourceAccountId, int destinationAccountId, double transactionAmount, int accountNumber){
    this->transactionId = transactionId;
    this->transactionType = transactionType; // credit or debit
    this->sourceAccountId = sourceAccountId;
    this->destinationAccountId = destinationAccountId;
    this->transactionAmount = transactionAmount;
    this->accountNumber = accountNumber;
}
long long int Transaction :: getTransactionId(){
    return transactionId;
}
char Transaction :: getTransactionType(){
    return transactionType;
}
int Transaction :: getSourceAccountId(){
    return sourceAccountId;
}
int Transaction :: getDestinationAccountId() {
    return destinationAccountId;
}
double Transaction :: getTransactionAmount(){
    return transactionAmount;
}
int Transaction :: getAccountNumber(){
    return accountNumber;
}
void Transaction :: setTransactionId(long long int transactionId){
    this->transactionId = transactionId;
}
void Transaction :: setTransactionType(char transactionType){
    this->transactionType = transactionType ;
}
void Transaction :: setSourceAccountId(int sourceAccountId){
    this->sourceAccountId = sourceAccountId;
}
void Transaction :: setDestinationAccountId(int destinationAccountId){
    this->destinationAccountId = destinationAccountId;
}
void Transaction :: setTransactionAmount(double transactionAmount){
    this->transactionAmount = transactionAmount;
}
void Transaction :: setAccountNumber(int accountNumber){
    this->accountNumber = accountNumber;
}
