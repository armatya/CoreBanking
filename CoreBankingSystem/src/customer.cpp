#include"../includes/customer.h"

string Customer :: customerIdRef = "101";

Customer :: Customer() {
    customerId = customerIdRef;
    customerName = "";
    typeOfCustomer = "";          //individual or coorporate
    customerAddress = "";
    customerCity = "";
    customerState = "";
    customerCountry = "";
    customerPincode = "";
    customerPhoneNumber = "";
    customerEmail = "";
    customerPan = "";
}
Customer :: Customer(string& customerName, string& typeOfCustomer, string& customerAddress, 
         string& customerCity, string& customerState, string& customerCountry, 
         string& customerPincode, string& customerPhoneNumber, string& customerEmail, string& customerPan) {
    readCustomerRefFromFile();
    this->customerId = customerIdRef;
    this->customerName = customerName;
    this->typeOfCustomer = typeOfCustomer;        
    this->customerAddress = customerAddress;
    this->customerCity = customerCity;
    this->customerState = customerState;
    this->customerCountry = customerCountry;
    this->customerPincode = customerPincode;
    this->customerPhoneNumber = customerPhoneNumber;
    this->customerEmail = customerEmail;
    this->customerPan = customerPan;

    customerIdRef = to_string(stoi(customerId) + 1);
    writeCustomerIdRefToFile();
}
string& Customer :: getCustomerId() {
    return customerId;
}
void Customer :: setCustomerId(string& customerId) {
    this->customerId = customerId;
}
string& Customer :: getCustomerName(){
    return customerName;
}
void Customer :: setCustomerName(string& customerName){
    this->customerName = customerName;
}
string& Customer :: getTypeOfCustomer(){
    return typeOfCustomer;
}
void Customer :: setTypeOfCustomer(string & typeOfCustomer) {
    this->typeOfCustomer = typeOfCustomer;
}
string& Customer :: getCustomerAddress(){
    return customerAddress;
}
void Customer :: setCustomerAddress(string& customerAddress){
    this->customerAddress = customerAddress;
}
string& Customer :: getCustomerCity(){
    return customerCity;
}
void Customer :: setCustomerCity(string& customerCity){
    this->customerCity = customerCity;
}
string& Customer :: getCustomerState(){
    return customerState;
}
void Customer :: setCustomerState(string& customerState){
    this->customerState = customerState;
}
string& Customer :: getCustomerCountry(){
    return customerCountry;
}
void Customer :: setCustomerCountry(string& customerCountry){
    this->customerCountry = customerCountry;
}
string& Customer :: getCustomerPincode(){
    return customerPincode;
}
void Customer :: setCustomerPincode(string& customerPincode){
    this->customerPincode = customerPincode;
}
string& Customer :: getCustomerPhoneNumber(){
    return customerPhoneNumber;
}
void Customer :: setCustomerPhoneNumber(string& customerPhoneNumber){
    this->customerPhoneNumber = customerPhoneNumber;
}
string& Customer :: getCustomerEmail(){
    return customerEmail;
}
void Customer :: setCustomerEmail(string& customerEmail){
    this->customerEmail = customerEmail;
}
string& Customer :: getCustomerPan(){
    return customerPan;
}
void Customer :: setCustomerPan(string& customerPan){
    this->customerPan = customerPan;
}