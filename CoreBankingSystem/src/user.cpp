#include "../includes/user.h"  

int User::userIdRef = 1000;

User :: User(){
    userId = userIdRef;
    customerId = "";
    userPassword = "";
    userType = '\0';
    loginStatus = 0; 
}
User :: User(string customerId, string userPassword, char userType, int loginStatus){
    readUserIdRefFromFile();
    this->userId = userIdRef;
    this->customerId = customerId;
    this->userPassword = userPassword;
    this->userType = userType;
    this->loginStatus = loginStatus;

    userIdRef++; 
    writeUserIdRefToFile();
}
int User :: getUserId(){
    return userId;
}
string User :: getCustomerId(){
    return customerId;
}
string User :: getUserPassword(){
    return userPassword;
}
char User :: getUserType() {                //U- user and A-administrator 
    return userType;
}
int User :: getLoginStatus(){
    return loginStatus;
}  
void User :: setUserId(int userId){
    this->userId = userId;
}  
void User :: setCustomerId(string customerId){
    this->customerId = customerId;
}
void User :: setUserPassword(string userPassword){
    this->userPassword = userPassword;
}
void User :: setUserType(char userType){                 //U- user and A-administrator
    this->userType = userType;
} 
void User :: setLoginStatus(int loginStatus){
    this->loginStatus = loginStatus;
}