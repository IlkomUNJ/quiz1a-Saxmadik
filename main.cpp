#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
enum AdminPrompt{ACCOUNT_MANAGEMENT, SYSTEM_REPORT, ADMIN_LOGOUT};
enum AccountManagementPrompt{VIEW_ALL_BUYERS, VIEW_ALL_SELLERS, VIEW_ALL_DETAILS, SEARCH_ACCOUNTS, CREATE_ACCOUNTS, REMOVE_ACCOUNTS, BACK_TO_ADMIN_MAIN};
using namespace std;

// Forward declarations for the functions
void createBuyerAccount();
void createSellerAccount();

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu

                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER:
                regPrompt = CREATE_BUYER; // reset regPrompt to CREATE_BUYER when entering register menu
                while (regPrompt != BACK){
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            createBuyerAccount();
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            createSellerAccount();
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                break;
            case EXIT:
                cout << "Exiting." << endl;
                break;
            case ADMIN_LOGIN:
                /* Prompt for username & password then check the entries with our hard coded features */
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
                    cout << "Admin login successful!" << endl;
                    
                    AdminPrompt adminPrompt = ACCOUNT_MANAGEMENT;
                    while (adminPrompt != ADMIN_LOGOUT) {
                        cout << "\n=== ADMIN PANEL ===" << endl;
                        cout << "Select an option: " << endl;
                        cout << "1. Account Management" << endl;
                        cout << "2. System Report" << endl;
                        cout << "3. Logout" << endl;
                        
                        int adminChoice;
                        cin >> adminChoice;
                        adminPrompt = static_cast<AdminPrompt>(adminChoice - 1);
                        
                        switch (adminPrompt) {
                            case ACCOUNT_MANAGEMENT: {
                                AccountManagementPrompt accMgmtPrompt = VIEW_ALL_BUYERS;
                                while (accMgmtPrompt != BACK_TO_ADMIN_MAIN) {
                                    cout << "\n--- Account Management ---" << endl;
                                    cout << "1. View All Buyers" << endl;
                                    cout << "2. View All Sellers" << endl;
                                    cout << "3. View All Details of Buyers/Sellers" << endl;
                                    cout << "4. Search Accounts" << endl;
                                    cout << "5. Create New Accounts" << endl;
                                    cout << "6. Remove Accounts" << endl;
                                    cout << "7. Back to Admin Main" << endl;
                                    
                                    int accMgmtChoice;
                                    cin >> accMgmtChoice;
                                    accMgmtPrompt = static_cast<AccountManagementPrompt>(accMgmtChoice - 1);
                                    
                                    switch (accMgmtPrompt) {
                                        case VIEW_ALL_BUYERS:
                                            cout << "Viewing all buyers..." << endl;
                                            // Implementation for viewing all buyers
                                            break;
                                        case VIEW_ALL_SELLERS:
                                            cout << "Viewing all sellers..." << endl;
                                            // Implementation for viewing all sellers
                                            break;
                                        case VIEW_ALL_DETAILS:
                                            cout << "Viewing all details of buyers and sellers..." << endl;
                                            // Implementation for viewing all details
                                            break;
                                        case SEARCH_ACCOUNTS:
                                            cout << "Search accounts feature..." << endl;
                                            {
                                                string searchTerm;
                                                cout << "Enter search term (Name/Account ID/Address/Phone): ";
                                                cin.ignore();
                                                getline(cin, searchTerm);
                                                cout << "Searching for: " << searchTerm << endl;
                                                // Implementation for searching accounts
                                            }
                                            break;
                                        case CREATE_ACCOUNTS:
                                            cout << "Create new accounts feature..." << endl;
                                            {
                                                int accountType;
                                                cout << "Select account type to create:" << endl;
                                                cout << "1. Buyer Account" << endl;
                                                cout << "2. Seller Account" << endl;
                                                cout << "3. Bank Account" << endl;
                                                cin >> accountType;
                                                // Implementation for creating accounts
                                            }
                                            break;
                                        case REMOVE_ACCOUNTS:
                                            cout << "Remove accounts feature..." << endl;
                                            {
                                                int accountId;
                                                cout << "Enter Account ID to remove: ";
                                                cin >> accountId;
                                                cout << "Removing account ID: " << accountId << " (all related info will be deleted)" << endl;
                                                // Implementation for removing accounts
                                            }
                                            break;
                                        case BACK_TO_ADMIN_MAIN:
                                            cout << "Returning to admin main menu..." << endl;
                                            break;
                                        default:
                                            cout << "Invalid account management option." << endl;
                                            break;
                                    }
                                }
                                break;
                            }
                            case SYSTEM_REPORT:
                                cout << "\n--- System Report ---" << endl;
                                cout << "Generating system report..." << endl;
                                // Implementation for system report
                                cout << "Total number of Buyers: [Implementation needed]" << endl;
                                cout << "Total number of Sellers: [Implementation needed]" << endl;
                                cout << "Total number of Banking Accounts: [Implementation needed]" << endl;
                                break;
                            case ADMIN_LOGOUT:
                                cout << "Admin logout successful." << endl;
                                break;
                            default:
                                cout << "Invalid admin option." << endl;
                                break;
                        }
                    }
                } else {
                    cout << "Invalid admin credentials!" << endl;
                }
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 0;
}

// Function definitions
void createBuyerAccount() {
    string name;
    double initialDeposit;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Initial deposit amount: ";
    cin >> initialDeposit;
    // Note: You'll need to implement proper ID generation
    BankCustomer* newBankAccount = new BankCustomer(1, name, initialDeposit);
    Buyer* newBuyer = new Buyer(1, name, *newBankAccount);
    cout << "Buyer account created successfully!" << endl;
}

void createSellerAccount() {
    string name;
    double initialDeposit;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Initial deposit amount: ";
    cin >> initialDeposit;
    // Note: You'll need to implement proper ID generation
    BankCustomer* newBankAccount = new BankCustomer(1, name, initialDeposit);
    // Seller* newSeller = new Seller(1, name, *newBankAccount);
    cout << "Seller account created successfully!" << endl;
}