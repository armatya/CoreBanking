#include"../src/user.cpp"

class Customer  {
private:
    static string customerIdRef;
    string customerId;
    string customerName;
    string typeOfCustomer;          //individual or coorporate
    string customerAddress;
    string customerCity;
    string customerState;
    string customerCountry;
    string customerPincode;
    string customerPhoneNumber;
    string customerEmail;
    string customerPan;
public:
    Customer();
    Customer(string&, string&, string&, 
             string&, string&, string&,
             string&, string&, string&, string&);
    string& getCustomerId();
    string& getCustomerName();
    string& getTypeOfCustomer();
    string& getCustomerAddress();
    string& getCustomerCity();
    string& getCustomerState();
    string& getCustomerCountry();
    string& getCustomerPincode();
    string& getCustomerPhoneNumber();
    string& getCustomerEmail();
    string& getCustomerPan();
    
    void setCustomerId(string&);
    void setCustomerName(string&);
    void setTypeOfCustomer(string&);
    void setCustomerAddress(string&);
    void setCustomerCity(string&);
    void setCustomerState(string&);
    void setCustomerCountry(string&);
    void setCustomerPincode(string&);
    void setCustomerPhoneNumber(string&);
    void setCustomerEmail(string&);
    void setCustomerPan(string&);

private : 
    static void writeCustomerIdRefToFile() {
        ofstream file("../resources/customerIdRef.txt");
        if (file.is_open()) {
            file << customerIdRef;
            file.close();
        } else {
            cout << "Error opening userIdRef.txt" << endl;
        }
    }
    static void readCustomerRefFromFile() {
        ifstream file("../resources/customerIdRef.txt");
        if (file.is_open()) {
            file >> customerIdRef;
            file.close();
        } else {
            cout << "Error opening userIdRef.txt" << endl;
        }
    }
};
