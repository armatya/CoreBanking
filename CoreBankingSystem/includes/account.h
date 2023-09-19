#include"../src/customer.cpp"

class Account {
private:
    static int accountNumberRef;
    int accountNumber;
    string accountType;             //saving or current
    string customerId;
    string accountStatus;
    double accountBalance;
    string accountOpenDate;

public:
    Account();
    Account(string&, string&, string&, double);
    int getAccountNumber();
    string& getAccountType();    
    string& getCustomerId();
    string& getAccountStatus();
    double getAccountBalance();
    string& getAccountOpenDate();
    
    void setAccountNumber(int);
    void setAccountType(string&);     
    void setCustomerId(string&);
    void setAccountStatus(string&);
    void setAccountBalance(double);
    void setAccountOpenDate(string&);

private :
    string getDate() {
        time_t currentTime = time(NULL);
        stringstream ss;
        ss << put_time(localtime(&currentTime), "%Y-%m-%d") ;
        return ss.str();
    }
    static void writeAccountNumberRefToFile() {
        ofstream file("../resources/accountNumberRef.txt") ;
        if (file.is_open()) {
            file << accountNumberRef;
            file.close();
        } else {
            cout << "Error opening accountNumberRef.txt" << endl;
        }
    }

    static void readAccountNumberRefFromFile() {
        ifstream file("../resources/accountNumberRef.txt") ;
        if (file.is_open()) {
            file >> accountNumberRef;
            file.close();
        } else {
            cout << "Error opening userIdRef.txt" << endl;
        }
    }
};
