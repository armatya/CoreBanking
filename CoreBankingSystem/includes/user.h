#include<bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <fstream>
// #include <iomanip>
// #include <time.h>
// #include <chrono>
// #include <algorithm>
// #include <regex>
// #pragma GCC diagnostic ignored "-Wc++11-extensions"
// #pragma GCC diagnostic ignored "-Wlocal-type-template-args"
using namespace std;

class User {
private:
    static int userIdRef;
    int userId;
    string customerId;
    string userPassword;
    char userType; //U- user and A-administrator
    int loginStatus;
public :
    User();
    User(string, string, char, int);
    int getUserId();
    string getCustomerId();
    string getUserPassword();
    char getUserType(); 
    int getLoginStatus();
    
    void setUserId(int);
    void setCustomerId(string);
    void setUserPassword(string);
    void setUserType(char); 
    void setLoginStatus(int);

private :
    static void writeUserIdRefToFile() {
        ofstream file("../resources/userIdRef.txt");
        if (file.is_open()) {
            file << userIdRef;
            file.close();
        } else {
            cout << "Error opening userIdRef.txt" << endl;
        }
    }

    static void readUserIdRefFromFile() {
        ifstream file("../resources/userIdRef.txt");
        if (file.is_open()) {
            file >> userIdRef;
            file.close();
        } else {
            cout << "Error opening userIdRef.txt" << endl;
        }
    }
};
