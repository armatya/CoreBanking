#include"coreBankingSystem.cpp"

bool isValidEmail(const string& email) {
    const regex pattern("(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+.[A-Za-z]{2,}$)");
    return regex_match(email, pattern);
}
bool isValidPan(const string& pan) {
    const regex pattern("([A-Z]{5}[0-9]{4}[A-Z]{1})");
    return regex_match(pan, pattern);
}
bool isValidPhoneNumber(const string& phoneNumber) {
    const regex pattern("(^[0-9]{10}$)");
    return regex_match(phoneNumber, pattern);
}
bool isValidPincode(const string& pincode) {
    const regex pattern("(^[0-9]{6}$)");
    return regex_match(pincode, pattern);
}

string clerkId, customerId;
void createUser() {
    string customerId, userPassword;
    char userType;
    int loginStatus;
    cout << "Enter Customer ID: ";
    cin >> customerId;
    cout << "Enter User Password: ";
    cin >> userPassword;
    for(int i=0; i<userPassword.length(); i++){         //password Encryption
        userPassword[i]=(int)userPassword[i]+1;
    }
    vector <User > users;
    User newUser(customerId, userPassword, 'A', 0);
    users.push_back(newUser);
    writeUserToCSV(users);
}
bool bankClerkLogin() {
    vector <User> users;
    string password;
    cout << "Enter Clerk ID : ";
    cin >> clerkId;
    cout << "Enter your password : ";
    cin.ignore();
    getline(cin, password);
    for(int i=0; i<password.length(); i++){     //password Encryption
        password[i]=(int)password[i]+1;
    }
    readUserFromCSV(users);
    for (auto& existingUser : users) {
        if (existingUser.getCustomerId() == clerkId && existingUser.getUserType() == 'A') {
            if (existingUser.getUserPassword() == password) {
                if (existingUser.getLoginStatus() == 0) {
                    existingUser.setLoginStatus(1);
                    writeUserToCSVAfterLogin(users);
                    return true;
                } else {
                    cout << "\n\x1b[31mAlready Logged in!!\x1b[0m Enter password again to Logout: ";
                    getline(cin, password);
                    for (int i = 0; i < password.length(); i++) {  // password Encryption
                        password[i] = (int)password[i] + 1;
                    }
                    if (existingUser.getUserPassword() == password) {
                        existingUser.setLoginStatus(0);
                        writeUserToCSVAfterLogin(users);
                    } else {
                        cout << "\x1b[31mInvalid password. Exiting...\x1b[0m" << endl;
                        return false;
                    }
                }
            } else {
                cout << "\n\x1b[31mInvalid password!\x1b[0m" << endl;
                cout << "\x1b[32mForgot Password? Enter 'Y' for Yes or 'N' for No: \x1b[0m";
                char choice;
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    cout << "Enter your new password: ";
                    cin.ignore();
                    getline(cin, password);

                    for (int i = 0; i < password.length(); i++) {  // password Encryption
                        password[i] = (int)password[i] + 1;
                    }

                    existingUser.setUserPassword(password);
                    writeUserToCSVAfterLogin(users);

                    cout << "\x1b[32mPassword updated successfully. Please try to login again.\x1b[0m" << endl;
                    return false;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}
bool customerLogin() {
    vector <User> users;
    string password;
    cout << "Enter Customer ID : ";
    cin >> customerId;
    cout << "Enter your password : ";
    cin.ignore();
    getline(cin, password);
    for(int i=0; i<password.length(); i++){         //password Encryption
        password[i]=(int)password[i]+1;
    }
    readUserFromCSV(users);
    for (auto &existingUser : users) {
        if(existingUser.getCustomerId() == customerId and existingUser.getUserType() == 'U') {
            if(existingUser.getUserPassword() == password) {
                if(existingUser.getLoginStatus() == 0){
                    existingUser.setLoginStatus(1);
                    writeUserToCSVAfterLogin(users);
                    return true;
                }
                else {
                    cout<<"\n\x1b[31mALready Logged in !!\x1b[0m Enter password again to Logout : ";
                    getline(cin, password);
                    for(int i=0; i<password.length(); i++){     //password Encryption
                        password[i]=(int)password[i]+1;
                    }
                    if(existingUser.getUserPassword() == password) {
                        existingUser.setLoginStatus(0);
                        writeUserToCSVAfterLogin(users);
                    } 
                    else {
                        cout << "\x1b[31mInvalid password. Exiting...\x1b[0m" << endl;
                        return false;
                    }
                }
            }
            else {
                cout<<"\n\x1b[31mInvalid password!\x1b[0m"<<endl;
                cout<<"Forget Password, Press Y/y for YES or N/n or NO : ";
                char choice;
                cin >> choice;
                if(choice == 'y' or choice == 'Y') {
                    cout<<"Enter new Password : ";
                    cin.ignore();
                    getline(cin, password);
                    for(int i=0; i<password.length(); i++) password[i] = (int)password[i] + 1;
                    existingUser.setUserPassword(password);
                    writeUserToCSVAfterLogin(users);

                    cout<<"\x1b[32mPassword updated successfully. Please try to login again.\x1b[0m"<<endl;
                    return false;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

void performBankClerkOperations() {   
    while(true) {
        BankClerk* bankClerk = new BankClerk();
        vector<Customer> customers;
        vector<Account> accounts;
        vector <User> users;
        vector<Transaction> transactions;
        cout << "\n\x1b[36mBank Clerk Menu : \x1b[0m" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Delete Customer" << endl;
        cout << "3. Modify Customer Details" << endl;
        cout << "4. Credit Money" << endl;
        cout << "5. Debit Money" << endl;
        cout << "6. Query Account" << endl;
        cout << "7. Logout and Go Back" << endl;
        int clerkChoice;
        cout << "\nEnter your choice: ";
        if (!(cin >> clerkChoice)){
            cin.clear();  // Clear error flags      
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Skip bad input           
        }
        switch (clerkChoice) {
            case 1:{                                    //addCustomer  
                string customerId, customerName, typeOfCustomer, customerAddress, customerCity, customerState;
                string customerCountry, customerPincode, customerPhoneNumber, customerEmail, customerPan;

                cout << "\n---- Personal Details to Open Account ----\n";
                //cout << "Enter Customer ID: ";
                cin.ignore();
                // getline(cin, customerId);
                cout << "Enter Customer Name: ";
                getline(cin, customerName);
                while(customerName.empty()) {
                    cout<<"Customer Name cannot be empty : ";
                    getline(cin, customerName);
                }
                cout << "Enter Type of Customer (individual or corporate): ";
                getline(cin, typeOfCustomer);
                cout << "Enter Customer Address: ";
                getline(cin, customerAddress);
                cout << "Enter Customer City: ";
                getline(cin, customerCity);
                cout << "Enter Customer State: ";
                getline(cin, customerState);
                cout << "Enter Customer Country: ";
                getline(cin, customerCountry);
                cout << "Enter Customer Pincode: ";
                getline(cin, customerPincode);
                while (!isValidPincode(customerPincode)) {
                    cout << "\x1b[31mInvalid pincode.\x1b[0m Please enter 6-digit pincode: ";
                    getline(cin, customerPincode);
                }
                cout << "Enter Customer Phone Number: ";
                getline(cin, customerPhoneNumber);
                while (!isValidPhoneNumber(customerPhoneNumber)) {
                    cout << "\x1b[31mInvalid phone number.\x1b[0m Please enter 10-digit phone number: ";
                    getline(cin, customerPhoneNumber);
                }
                cout << "Enter Customer Email: ";
                getline(cin, customerEmail);
                while (customerEmail.empty() || !isValidEmail(customerEmail)) {
                    cout << "\x1b[31mInvalid email address.\x1b[0m Please enter valid email: ";
                    getline(cin, customerEmail);
                }
                cout << "Enter Customer PAN Number: ";
                getline(cin, customerPan);
                while (!customerPan.empty() && !isValidPan(customerPan)) {
                    cout << "\x1b[31mInvalid PAN number.\x1b[0m Please enter valid PAN: ";
                    getline(cin, customerPan);
                }
                cout << "\n----- Account Details ----\n";
                string accountType, accountStatus, accountOpenDate;
                double accountBalance;
                cout << "Enter Account Type (saving or current): ";
                getline(cin, accountType);
                cout << "Enter Account Status (Enable or Disable): ";
                getline(cin, accountStatus);
                // cout << "Enter Account Open Date: ";
                // getline(cin, accountOpenDate);
                cout << "Enter Initial Balance: ";
                cin >> accountBalance;

                cout << "\n----- UserId & Password Generation ----\n";
                string userPassword;
                char userType;
                int loginStatus;
                cout << "Create your Password: ";
                cin >> userPassword;
                for(int i=0; i<userPassword.length(); i++){         //password Encryption
                    userPassword[i]=(int)userPassword[i]+1;
                }

                Customer *customer = new Customer(customerName, typeOfCustomer, customerAddress, customerCity,
                            customerState, customerCountry, customerPincode, customerPhoneNumber, customerEmail, customerPan);
                Account *account = new Account(accountType, customer->getCustomerId(), accountStatus, accountBalance);

                User *user = new User(customer->getCustomerId(), userPassword, 'U', 0);
                bankClerk->addCustomer(users, customers, accounts, *user, *customer, *account);
                delete customer;
                delete account;
                delete user;
                break;
            }
            case 2:{        //Delete Operation
                string customerId;
                cout << "\nEnter Customer ID : ";
                cin.ignore();
                getline(cin,customerId);
                bankClerk->deleteCustomer(users, customers, accounts, customerId);
                break;
            }
            case 3:{        //Modify Operation
                string customerId, customerName, typeOfCustomer, customerAddress, customerCity, customerState;
                string customerCountry, customerPincode, customerPhoneNumber, customerEmail, customerPan;
                cout<<"\n---- Enter Customer ID to Modify The Data ----\n"<<endl;
                cout << "Enter Customer ID : ";
                cin.ignore();
                getline(cin,customerId);
                readCustomersFromCSV(customers);
                bool flag = false;
                for(auto &c : customers) {
                    if(c.getCustomerId() == customerId) {
                        cout << "Enter Customer Name : ";
                        getline(cin, customerName);
                        c.setCustomerName(customerName);
                        cout << "Enter Type of Customer (invidual or coorporate): ";
                        getline(cin, typeOfCustomer);
                        c.setTypeOfCustomer(typeOfCustomer);
                        cout << "Enter Customer Address : ";
                        getline(cin, customerAddress);
                        c.setCustomerAddress(customerAddress);
                        cout << "Enter Customer City : ";
                        getline(cin, customerCity);
                        c.setCustomerCity(customerCity);
                        cout << "Enter Customer State : ";
                        getline(cin, customerState);
                        c.setCustomerState(customerState);
                        cout << "Enter Customer Country : ";
                        getline(cin, customerCountry);
                        c.setCustomerCountry(customerCountry);
                        cout << "Enter Customer Pincode: ";
                        getline(cin, customerPincode);
                        c.setCustomerPincode(customerPincode);
                        while (!isValidPincode(customerPincode)) {
                            cout << "\x1b[31mInvalid pincode.\x1b[0m Please enter 6-digit pincode: ";
                            getline(cin, customerPincode);
                            c.setCustomerPincode(customerPincode);
                        }
                        cout << "Enter Customer Phone Number: ";
                        getline(cin, customerPhoneNumber);
                        c.setCustomerPhoneNumber(customerPhoneNumber);
                        while (!isValidPhoneNumber(customerPhoneNumber)) {
                            cout << "\x1b[31mInvalid phone number.\x1b[0m Please enter 10-digit phone number: ";
                            getline(cin, customerPhoneNumber);
                            c.setCustomerPhoneNumber(customerPhoneNumber);
                        }
                        cout << "Enter Customer Email: ";
                        getline(cin, customerEmail);
                        c.setCustomerEmail(customerEmail);
                        while (customerEmail.empty() || !isValidEmail(customerEmail)) {
                            cout << "\x1b[31mInvalid email address.\x1b[0m Please enter valid email: ";
                            getline(cin, customerEmail);
                            c.setCustomerEmail(customerEmail);
                        }
                        cout << "Enter Customer PAN Number: ";
                        getline(cin, customerPan);
                        c.setCustomerPan(customerPan);
                        while (!customerPan.empty() && !isValidPan(customerPan)) {
                            cout << "\x1b[31mInvalid PAN number.\x1b[0m Please enter valid PAN: ";
                            getline(cin, customerPan);
                            c.setCustomerPan(customerPan);
                        }
                
                        // Customer *customer = new Customer(customerName, typeOfCustomer, customerAddress, customerCity, 
                        // customerState, customerCountry, customerPincode, customerPhoneNumber,  customerEmail, customerPan);

                        bankClerk->modifyCustomer(customers, c, c.getCustomerId());
                        flag = true;
                        //delete customer;
                    }
                } 
                if(flag == true) cout << "\n\x1b[32mCustomer details modified successfully.\n\x1b[0m";
                else cout << "\n\x1b[31mCustomer does not exists.\n\x1b[0m";
                break;
            }
            case 4:{        //Amount Credit Operation
                int accountNumber;
                double amount;
                cout << "\nEnter the Account Number : ";
                cin >> accountNumber;
                cout << "Enter the amount to credit : ";
                cin >> amount;
                bankClerk->creditMoney(accounts, transactions, accountNumber, amount);
                break;
            }
            case 5:{        //Amount Debit Operation
                int accountNumber;
                double amount;
                cout << "\nEnter the Account Number : ";
                cin >> accountNumber;
                cout << "Enter the amount to debit : ";
                cin >> amount;
                bankClerk->debitMoney(accounts, transactions, accountNumber, amount);       
                break;
            }
            case 6:{        //Query Account Transaction
                int accountNumber;
                cout << "\nEnter the Account Number : ";
                cin >> accountNumber;
                bankClerk->queryAccount(accounts, accountNumber);               
                break;
            }
            case 7:{        //Clerk Logout 
                readUserFromCSV(users);
                for(auto &user : users) {
                    if(clerkId == user.getCustomerId()) {
                        user.setLoginStatus(0);
                        writeUserToCSVAfterLogin(users);
                    }
                }                
                cout<<"\x1b[33m\nClerk LogOut Successfull \x1b[0m\n";
                return;
            }
            default:
                cout << "\n\x1b[31mInvalid choice! Please try again.\x1b[0m" << endl;
                break;
        }
        delete bankClerk;
    }  
    cout << "\x1b[32mBankClerk operation completed.\x1b[0m" << endl;
}
void performCustomerOperations() {
    while(true) {
        CoreBankingSystem* coreBankingSystem = new CoreBankingSystem();
        vector <Transaction> transactions;
        vector <Customer> customers;
        vector <Account> accounts;
        vector <User> users;
        cout << "\n\x1b[36mCustomer Menu : \x1b[0m" << endl;
        cout << "1. View Customer Details" << endl;
        cout << "2. Transfer Money" << endl;
        cout << "3. Query Account Transactions" << endl;
        cout << "4. Logout and Go Back" << endl;
        int customerChoice;
        cout << "\nEnter your choice: ";
        if (!(cin >> customerChoice)){
            cin.clear();  // Clear error flags      
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Skip bad input            
        }
        switch (customerChoice) {
            case 1:{        //View Customers Details
                Customer *customer = new Customer();
                string customerId;
                cout << "\nEnter Customer ID : ";
                cin.ignore();
                getline(cin,customerId);
                customer->setCustomerId(customerId);
                coreBankingSystem->viewCustomerDetails(customers, *customer);
                delete customer;
                break;
            }               
            case 2:{        //Transfer Money
                Transaction *transaction = new Transaction();
                int sourceAccountNumber, destinationAccountNumber;
                double amount;
                cout <<"\nEnter Source Account Number : ";
                cin >>sourceAccountNumber;
                transaction->setSourceAccountId(sourceAccountNumber);
                cout << "Enter Destination Account Number : ";
                cin >> destinationAccountNumber;
                cout <<"Enter Amount to Transfer : ";
                cin >> amount;
                transaction->setDestinationAccountId(destinationAccountNumber);
                coreBankingSystem->transferMoney(transactions, accounts, *transaction, *transaction, amount);
                delete transaction;                    
                break;
            }
            case 3:{        //Transactions Query           
                int accountNumber;
                cout<<"\nEnter Account Number : ";
                cin >> accountNumber;
                coreBankingSystem->queryAccountTransactions(transactions, accountNumber);               
                break;
            }
            case 4:{        //Customer Logout
                readUserFromCSV(users);
                for(auto &user : users) {
                    if(customerId == user.getCustomerId()) {
                        user.setLoginStatus(0);
                        writeUserToCSVAfterLogin(users);
                    }
                }      
                cout<<"\x1b[33m\nClerk LogOut Successfull \x1b[0m\n";
                return;
                coreBankingSystem->quitApplication();
                break;
            }
            default:
                cout << "\x1b[31m\nInvalid choice! Please try again.\x1b[0m" << endl;
                break;
        }  
        delete coreBankingSystem;
    } 
    cout << "\x1b[32mCustomer operations completed.\x1b[0m" << endl;
}

void readUserFromCSV(vector<User>& users) {
    fstream file("../resources/users.csv");
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    string data;
    while (getline(file, data)) {
        User* user = new User();
        stringstream ss(data);
        string word;
        int cnt = 0;
        while (getline(ss, word, ',')) {
            if (cnt == 0) user->setUserId(stoi(word));
            if (cnt == 1) user->setCustomerId((word));
            if (cnt == 2) user->setUserPassword(word);
            if (cnt == 3) user->setUserType(word[0]);
            if (cnt == 4) user->setLoginStatus(stoi(word));
            cnt++;
        }
        if (cnt != 0) users.push_back(*user);
        delete user;
    }
    
    file.close();//
} 
void readCustomersFromCSV(vector<Customer>& customers) {    
    ifstream file("../resources/customers.csv" , ios :: in | ios :: binary );
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open customers.csv file.\x1b[0m" << endl;
        return;
    }
    string data;
    while(!file.eof()) {
        getline(file, data);
        Customer *customer = new Customer();
        stringstream ss(data);
        string word;
        int cnt = 0;
        while(getline(ss, word, ',')) {
            if(cnt == 0) customer->setCustomerId(word);
            if(cnt == 1) customer->setCustomerName(word);
            if(cnt == 2) customer->setTypeOfCustomer(word);
            if(cnt == 3) customer->setCustomerAddress(word);
            if(cnt == 4) customer->setCustomerCity(word);
            if(cnt == 5) customer->setCustomerState(word);
            if(cnt == 6) customer->setCustomerCountry(word);
            if(cnt == 7) customer->setCustomerPincode(word);
            if(cnt == 8) customer->setCustomerPhoneNumber(word);
            if(cnt == 9) customer->setCustomerEmail(word);
            if(cnt == 10) customer->setCustomerPan(word);
            cnt++;
        }
        if(cnt != 0) customers.push_back(*customer);
        delete customer;        
    }
    file.close();
}
void readAccountsFromCSV(vector<Account>& accounts) {
    fstream file("../resources/accounts.csv");
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    string data;
    while (getline(file, data)) {
        Account *account = new Account();
        stringstream ss(data);
        string word;
        int cnt = 0;
        while (getline(ss, word, ',')) {
            if (cnt == 0) account->setAccountNumber(stoi(word));
            if (cnt == 1) account->setAccountType(word);
            if (cnt == 2) account->setCustomerId(word);
            if (cnt == 3) account->setAccountStatus(word);
            if (cnt == 4) account->setAccountBalance(stod(word));
            if (cnt == 5) account->setAccountOpenDate(word);
            cnt++;
        }
        if (cnt != 0) accounts.push_back(*account);
        delete account;
    }
    file.close();//
} 
void readTransactionsFromCSV(vector<Transaction>& transactions){
    fstream file("../resources/transactions.csv");
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    string data;
    while (getline(file, data)) {
        Transaction *transaction = new Transaction();
        stringstream ss(data);
        string word;
        int cnt = 0;
        while (getline(ss, word, ',')) {
            if (cnt == 0) transaction->setTransactionId(stoll(word));
            if (cnt == 1) transaction->setTransactionType(word[0]);
            if (cnt == 2) transaction->setSourceAccountId(stoi(word));
            if (cnt == 3) transaction->setDestinationAccountId(stoi(word));
            if (cnt == 4) transaction->setTransactionAmount(stod(word));
            if (cnt == 5) transaction->setAccountNumber(stoi(word));
            cnt++;
        }
        if (cnt != 0) transactions.push_back(*transaction);
        delete transaction;
    }
    file.close();//
}

void writeUserToCSV(vector <User>& users) {
    fstream file("../resources/users.csv", ios::app);
    if (!file.is_open()) {
        cout << "\x1b[31mUnable to open file.\x1b[0m" << endl;
        return;
    } 
    for(auto &user : users) {
        file << user.getUserId() << ",";
        file << user.getCustomerId() << ",";
        file << user.getUserPassword() << ",";
        file << user.getUserType() << ",";
        file << user.getLoginStatus() << ","<<endl;
    }
    file.close();
}
void writeUserToCSVAfterLogin(vector <User>& users) {
    fstream file("../resources/users.csv", ios :: out);
    if (!file.is_open()) {
        cout << "\x1b[31mUnable to open file.\x1b[0m" << endl;
    } 
    for(auto & user : users) {
        file << user.getUserId() << ",";
        file << user.getCustomerId() << ",";
        file << user.getUserPassword() << ",";
        file << user.getUserType() << ",";
        file << user.getLoginStatus() << ","<<endl;
    }
    file.close();//
}
void writeUserToCSVAfterDelete(vector <User>& users) {
    ofstream file("../resources/users.csv", ios :: out);
    if (!file.is_open()) {
        cout << "\x1b[31mUnable to open file.\x1b[0m" << endl;
    } 
    for(auto & user : users) {
        file << user.getUserId() << ",";
        file << user.getCustomerId() << ",";
        file << user.getUserPassword() << ",";
        file << user.getUserType() << ",";
        file << user.getLoginStatus() << ","<<endl;
    }
    //cout << "\n\x1b[32mUser data saved to user.csv\x1b[0m" << endl;
    file.close();//
} 

void writeCustomersToCSV(vector<Customer>& customers) {    
    fstream file("../resources/customers.csv", ios :: app);
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open customers.csv file.\x1b[0m" << endl;
    }
    for (auto& customer : customers) {
        file << customer.getCustomerId() << ",";
        file << customer.getCustomerName() << ",";
        file << customer.getTypeOfCustomer() << ",";
        file << customer.getCustomerAddress() << ",";
        file << customer.getCustomerCity() << ",";
        file << customer.getCustomerState() << ",";
        file << customer.getCustomerCountry() << ",";
        file << customer.getCustomerPincode() << ",";
        file << customer.getCustomerPhoneNumber() << ",";
        file << customer.getCustomerEmail() << ",";
        file << customer.getCustomerPan()<<",";
        file << endl;
    }
    file.close();//
}
void writeCustomersToCSVAfterDelete(vector<Customer>& customers) {    
    ofstream file("../resources/customers.csv",  ios :: out);
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open customers.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& customer : customers) {
        file << customer.getCustomerId() << ",";
        file << customer.getCustomerName() << ",";
        file << customer.getTypeOfCustomer() << ",";
        file << customer.getCustomerAddress() << ",";
        file << customer.getCustomerCity() << ",";
        file << customer.getCustomerState() << ",";
        file << customer.getCustomerCountry() << ",";
        file << customer.getCustomerPincode() << ",";
        file << customer.getCustomerPhoneNumber() << ",";
        file << customer.getCustomerEmail() << ",";
        file << customer.getCustomerPan() << ",";
        file << endl;
    }
    file.close();//
}
void writeCustomersToCSVAfterModify(vector<Customer>& customers) {    
    fstream file("../resources/customers.csv", ios :: out);
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open customers.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& customer : customers) {
        file << customer.getCustomerId() << ",";
        file << customer.getCustomerName() << ",";
        file << customer.getTypeOfCustomer() << ",";
        file << customer.getCustomerAddress() << ",";
        file << customer.getCustomerCity() << ",";
        file << customer.getCustomerState() << ",";
        file << customer.getCustomerCountry() << ",";
        file << customer.getCustomerPincode() << ",";
        file << customer.getCustomerPhoneNumber() << ",";
        file << customer.getCustomerEmail() << ",";
        file << customer.getCustomerPan()<<",";
        file << endl;
    }
    file.close();
}

void writeAccountsToCSV(vector<Account>& accounts) {
    fstream file("../resources/accounts.csv" , ios::app);
    if (!file.is_open()) {
           cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& account : accounts) {
        file << account.getAccountNumber() << ",";
        file << account.getAccountType() << ",";
        file << account.getCustomerId() << ",";
        file << account.getAccountStatus() << ",";
        file << account.getAccountBalance() << ",";
        file << account.getAccountOpenDate() << ",";
        file << endl;
    }
    file.close();
}
void writeAccountsToCSVAfterDelete(vector<Account>& accounts) {
    ofstream file("../resources/accounts.csv" , ios::out);
    if (!file.is_open()) {
           cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& account : accounts) {
        file << account.getAccountNumber() << ",";
        file << account.getAccountType() << ",";
        file << account.getCustomerId() << ",";
        file << account.getAccountStatus() << ",";
        file << account.getAccountBalance() << ",";
        file << account.getAccountOpenDate() << ",";
        file << endl;
    }
    file.close();
}
void writeAccountsToCSVAfterCreditDebit(vector<Account>& accounts) {
    fstream file("../resources/accounts.csv" , ios::out);
    if (!file.is_open()) {
           cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& account : accounts) {
        file << account.getAccountNumber() << ",";
        file << account.getAccountType() << ",";
        file << account.getCustomerId() << ",";
        file << account.getAccountStatus() << ",";
        file << account.getAccountBalance() << ",";
        file << account.getAccountOpenDate() << ",";
        file << endl;
    }
    file.close();
}
void writeAccountsToCSVAfterTransfer(vector<Account>& accounts) {
    fstream file("../resources/accounts.csv" , ios :: out);
    if (!file.is_open()) {
           cout << "\x1b[31mFailed to open accounts.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& account : accounts) {
        file << account.getAccountNumber() << ",";
        file << account.getAccountType() << ",";
        file << account.getCustomerId() << ",";
        file << account.getAccountStatus() << ",";
        file << account.getAccountBalance() << ",";
        file << account.getAccountOpenDate() << ",";
        file << endl;
    }
    file.close();
}

void writeTransactionsToCSV(vector<Transaction>& transactions) {
    fstream file("../resources/transactions.csv");
    if (!file.is_open()) {
        cout << "\x1b[31mFailed to open transactions.csv file.\x1b[0m" << endl;
        return;
    }
    for (auto& transaction : transactions) {
        file << transaction.getTransactionId() << ",";
        file << transaction.getTransactionType() << ",";
        file << transaction.getSourceAccountId() << ",";
        file << transaction.getDestinationAccountId() << ",";
        file << transaction.getTransactionAmount() << ",";
        file << transaction.getAccountNumber() << ",";
        file << endl;
    }
    file.close();
}

//clerk login.
// for (auto &existingUser : users) {
    //     if(existingUser.getCustomerId() == clerkId and existingUser.getUserPassword() == password and existingUser.getUserType() == 'A' ) {
    //         if(existingUser.getLoginStatus() == 0){
    //             existingUser.setLoginStatus(1);
    //             writeUserToCSVAfterLogin(users);
    //             return true;
    //         }
    //         else {
    //             cout<<"\n\x1b[31mALready Logged in !!\x1b[0m Enter password again to Logout : ";
    //             getline(cin, password);
    //             for(int i=0; i<password.length(); i++){     //password Encryption
    //                 password[i]=(int)password[i]+1;
    //             }
    //             if(existingUser.getUserPassword() == password) {
    //                 existingUser.setLoginStatus(0);
    //                 writeUserToCSVAfterLogin(users);
    //             }  
    //         }
    //     }
    // }
    // return false;