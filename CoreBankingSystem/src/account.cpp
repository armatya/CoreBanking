#include "../includes/account.h"

int Account :: accountNumberRef = 5001;
Account :: Account(){
    accountNumber = accountNumberRef;
    accountType = "";             //saving or current
    customerId = "";
    accountStatus = "";
    accountBalance = 0;
    accountOpenDate = "";

}
Account :: Account(string& accountType, string& customerId, string& accountStatus, double accountBalance){
	readAccountNumberRefFromFile();

	this->accountNumber = accountNumberRef;
    this->accountType = accountType;             //saving or current
    this->customerId = customerId;
    this->accountStatus = accountStatus;
    this->accountBalance = accountBalance;
    this->accountOpenDate = getDate();

	accountNumberRef++;
	writeAccountNumberRefToFile();
}
int Account :: getAccountNumber() {
	return accountNumber;
}
void Account :: setAccountNumber(int accountNumber) {
	this->accountNumber = accountNumber;
}
string& Account :: getAccountType() {
	return accountType;
}
void Account :: setAccountType(string& accountType)  {
	this->accountType = accountType;
}
string& Account :: getCustomerId() {
	return customerId;
}
void Account :: setCustomerId(string& customerId) {
	this->customerId = customerId;
}
string& Account :: getAccountStatus() {
	return accountStatus;
}
void Account :: setAccountStatus(string& accountStatus) {
	this->accountStatus = accountStatus;
}
double Account :: getAccountBalance() {
	return accountBalance;
}
void Account :: setAccountBalance(double accountBalance) {
	this->accountBalance = accountBalance;
}
string& Account :: getAccountOpenDate() {
	return accountOpenDate;
}
void Account :: setAccountOpenDate(string& accountOpenDate) {
	this->accountOpenDate = accountOpenDate;
}