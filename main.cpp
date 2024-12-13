#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool LoggedIn() {
    string username,password;
    string un, pw;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
    
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    
    if (un == username && pw == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int choice;
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "-------------------------"<< endl;
    cout << "1.Register" << endl;
    cout << "2.Login" << endl;
    cin >> choice;
    
    if (choice == 1) {
        string username, password;
        cout << "Registration:" << endl;
        cout << endl;
        cout << "Select a username: " << endl;
        cin >> username;
        cout << "Select a password: " << endl;
        cin >> password;
        
        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Welcome " << username << "!" << endl;
        
    } else if (choice == 2) {
        bool status = LoggedIn();
        if (!status) {
            system("cls"); 
            cout << endl;
            cout << "Invalid Login." << endl;
            return 0; 
        } else {
            cout << "Successfully Logged in." << endl;
            cout << endl;
            int choiceTwo;
            cout << "Welcome Back" << endl;
            cout << endl;
            cout << "DASHBOARD" << endl;
            cout << "No new messages :)" << endl;
            cout << endl;
            cout << "1. Sign out" << endl;
            cout << "2. Back To Menu" << endl;
            cout << "Your Choice: " << endl;
            cin >> choiceTwo;
            
            if (choiceTwo == 1) {
                exit(0);  
            } else if (choiceTwo == 2) {
                main();  
            }
        }
    }
    return 0;
    
}
