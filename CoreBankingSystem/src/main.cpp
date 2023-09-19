#include "allOperations.cpp"
#include <conio.h>
using namespace std;

int main() {   
    //system("clear"); 
    //clrscr();
    cout<<"\t\t\t\t\t\x1b[34m██   ██ ██    ██ ███████     ██████   █████  ███    ██ ██   ██ \x1b[0m"<<endl;
    cout<<"\t\t\t\t\t\x1b[36m ██ ██   ██  ██     ███      ██   ██ ██   ██ ████   ██ ██  ██  \x1b[0m"<<endl;
    cout<<"\t\t\t\t\t\x1b[33m  ███     ████     ███       ██████  ███████ ██ ██  ██ █████   \x1b[0m"<<endl;
    cout<<"\t\t\t\t\t\x1b[36m ██ ██     ██     ███        ██   ██ ██   ██ ██  ██ ██ ██  ██  \x1b[0m"<<endl;
    cout<<"\t\t\t\t\t\x1b[34m██   ██    ██    ███████     ██████  ██   ██ ██   ████ ██   ██ \x1b[0m"<<endl;
    while(true) {
        try {
            while (true) {
                cout << "\n\x1b[36mXYZ_BANK Main_Menu : \x1b[0m" << endl;
                cout << "1. BankClerk Login" << endl;
                cout << "2. Customer Login" << endl;
                cout << "3. Quit" << endl;
                int choice;
                cout << "\nEnter your choice (1-3) : ";
                if (!(cin >> choice)){
                    cin.clear();  // Clear error flags      
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');// Skip bad input or clear the buffer
                    throw runtime_error("invalid input");         
                }
                switch (choice) {
                    case 1: {
                        if (bankClerkLogin()) {
                            cout << "\n\x1b[32mBank Clerk Login Successfull.\x1b[0m"<< endl;
                            performBankClerkOperations();
                        } else {
                            cout << "\n\x1b[31mBankClerk login failed, Please Try Again.\x1b[0m" << endl;
                        }
                        break;
                    }
                    case 2: {
                        if (customerLogin()) {
                            cout << "\n\x1b[32mCustomer Login Successfull.\x1b[0m" << endl;
                            performCustomerOperations();
                        } else {
                            cout << "\n\x1b[31mCustomer login failed, Please Try Again.\x1b[0m" << endl;
                        }
                        break;
                    }
                    case 3:{
                        cout << "\n\x1b[33mGoodbye!!! ThankYou for Banking...\n\x1b[0m" << endl;
                        return 0;
                        break;
                    }
                    default:{
                        cout << "\n\x1b[31mInvalid choice! Please try again.\x1b[0m" << endl;
                        break;
                    }
                }
            }
        }
        catch (exception &e) {
            cerr << "Exception :" << e.what() <<endl;
        }
        catch(...) {
            cout << "Unknown exception !!!!";
        }
    }
    return 0;
} 