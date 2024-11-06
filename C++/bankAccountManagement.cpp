#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;
bool LOGGED_IN = false;
map<string,string> ACTIVE;

void checkDatabase();
void resetDatabase(string);
void writeData(ofstream&, map<string,string>);
map<string,string> createAccount();
void title(string&);
string enterSpecific(string, ifstream&);
bool isNumeric(string);
bool tillUnique(string, ifstream&, string);
int fileSize(ifstream&);
map<string,string> readData(ifstream&);
int randint(int, int);
void displayAccount(map<string,string>);
map<string,string> loginAccount();
void displayDatabase();
void displayMap(map<string,string>);
void deleteDatabase();
void editAccount(map<string,string>&);
void updateDatabase(map<string,string>, bool);
void transaction(string);
float acceptAmount();
void pay();
string acceptUsername(map<string,string>&);
void deleteAccount();
string upper(string&);

const string mainMenu1 = "\n\
    MAIN MENU   \n\
1. Create Account\n\
2. Login Account\n\
3. Quit\n\
\n";
const string mainMenu2 = "\n\
    MAIN MENU   \n\
1. Account Details\n\
2. Edit Details\n\
3. Deposit\n\
4. Withdraw\n\
5. Pay\n\
6. Balance Enquiry\n\
7. Delete Account\n\
8. Log Out\n";
string check;

int main() {
    checkDatabase();

    while (true) {
        if (not LOGGED_IN) {
            cout << mainMenu1;
            cout << endl << "Enter a choice: "; cin >> check; cout << endl;

            if (check == "1") createAccount();
            else if (check == "2") {
                if (LOGGED_IN) cout << endl << "ALready Logged In" << endl;
                else ACTIVE = loginAccount();
            } else if (check == "3") {
                cout << endl << "Thank you for using!" << endl;
                break;
            } else if (check == "reset") resetDatabase("loud");
            else if (check == "inspect") {
                displayDatabase();
                cout << "press enter to continue..."; cin.get(); cin.get();
            }
            else if (check == "delete") {
                deleteDatabase();
                break;
            } else cout << "Invalid Input. Try Again..." << endl;
        } else {
            cout << mainMenu2 << endl;
            cout << endl << "Enter your choice: "; cin >> check; cout << endl;

            if (check == "1") displayAccount(ACTIVE);
            else if (check == "2") editAccount(ACTIVE);
            else if (check == "3") transaction("deposit");
            else if (check == "4") transaction("withdraw");
            else if (check == "5") pay();
            else if (check == "6") {
                cout << "Your Current Balance is " << ACTIVE["balance"] << endl << "press enter to continue...";
                cin.get(); cin.get();
            } else if (check == "7") deleteAccount();
            else if (check == "8") {
                LOGGED_IN = false;
                map<string,string> empty;
                ACTIVE = empty;
            } else cout << "Invalid Input. Try Again...";
        }
    }
    return 0;
}

/*checks the existence of the necessary file to run the program,
if not available then it creates it with default configuration*/
void checkDatabase() {
    ifstream file("bankDetails.dat", ios::binary);
    if (!file) resetDatabase("silent"); 
}

/*resets the configuration of the database to default
silent mode --> doesn't display the reset successful message
loud mode --> shows the reset successful message*/
void resetDatabase(string type) {
    map<string,string> defaultDetails;
    defaultDetails["account no."] = "1000",  
    defaultDetails["username"] = "admin", 
    defaultDetails["password"] = "2503",
    defaultDetails["name"] = "dream",
    defaultDetails["gender"] = "M",
    defaultDetails["phone no."] = "12345",
    defaultDetails["balance"] = "10000.00";
    ofstream file("bankDetails.dat", ios::binary);
    if (!file) throw "File wasn't opened successfully";
    writeData(file, defaultDetails);
    file.close();
    if (type == "loud") cout << "Data Successfully Restored" << endl << endl;
}

/*writes the map object to the file with necessary type-casting*/
void writeData(ofstream &file, map<string,string> details) {
    ostringstream oss;
    for (auto element: details) oss << element.first << ':' << element.second << ';';
    string str = oss.str();
    int size = str.size();
    file.write((char*)size, sizeof(int)).write(str.c_str(), size);
}

/*creates bank account and updates the necessary files with the new details*/
map<string,string> createAccount() {
    string name, lastName, gender, phoneNo, username, password, accountNo;
    int file_size, size;
    bool unique;
    map<string,string> detailMap, userDetails;

    cout << "Creating Account" << endl;
    cout << "Enter name: "; cin >> name >> lastName;
    name.push_back(' '); name.append(lastName);
    title(name);
    
    while (true) {
        cout << "Enter gender(M/F): "; cin >> gender;
        gender[0] = toupper(gender[0]);
        if ((gender[0] == 'M' or gender[0] == 'F') and gender.size() == 1) break;
        else cout << "Choose either 'M' or 'F'." << endl << endl;
    }
    ifstream file("bankDetails.dat", ios::binary);
    phoneNo = enterSpecific("phone no.", file);
    
    while (username == "") {
        cout << "Enter a unique username: "; cin >> username;
        if (not tillUnique("username", file, username)) username = "";
    }
    password = enterSpecific("password", file);

    while (true) {
        accountNo = to_string(randint(1000, 9999));
        if (tillUnique("account no.", file, accountNo)) break;
    }
    file.close();
    userDetails["account no."] = accountNo,
    userDetails["username"] = username,
    userDetails["password"] = password,
    userDetails["name"] = name,
    userDetails["gender"] = gender,
    userDetails["phone no."] = phoneNo,
    userDetails["balance"] = "0.00";

    ofstream log("bankDetails.dat", ios::binary | ios::app);
    writeData(log, userDetails);
    cout << "Account Created!" << endl << endl;
    displayAccount(userDetails);
    log.close();
    file.close();
    return userDetails;
}

/*converts a string to title case*/
void title(string &str) {
    str[0] = toupper(str[0]);
    int size = str.size();

    for (int idx = 1; idx < size; idx++) {
        if (str[idx] == ' ' and idx < str.size() - 1) {
            idx++;
            str[idx] = toupper(str[idx]);
        } else
            str[idx] = tolower(str[idx]);
    }
}

/*accepts the specific type of input from the user
password type --> accepts a password with specific requirements
phone no. type --> accepts a phone number with specific requirements*/
string enterSpecific(string type, ifstream &file) {
    if (type == "password") {
        const string specialCharacters = "!#$%&( )*+,-./:;<=>?@[]^_`{|}~";
        const int size = 30;
        vector <bool> valid = {false, false, false}, check = {true, true, true};
        string password, confirmPassword;

        while (true) {
            cout << endl << "The password must atleast be 8 character long and must contain one alphabet, number and special symbol." << endl;
            cout << "Enter password: "; cin >> password;

            for (char ch: password) {
                if (isalpha(ch)) valid[0] = true;
                else if (isdigit(ch)) valid[1] = true;
                else if (specialCharacters.find(ch) < size) valid[2] = true;
                else {
                    valid = {false, false, false};
                    break;
                }
            }
            if (valid == check) { 
                cout << "Enter password again: "; cin >> confirmPassword;

                if (password == confirmPassword) {
                    cout << "Password accepted" << endl << endl;
                    return password;
                } else {
                    cout << "Incorrect Password. Try Again..." << endl;
                    return enterSpecific("password", file);
                }
            } else cout << "Invalid Password. Try Again..." << endl << endl;
        }
    } else if (type == "phone no.") {
        string phoneNo;

        while (true) {
            cout << "Enter phone no.: "; cin >> phoneNo;

            if (not (isNumeric(phoneNo) and phoneNo.size() == 10))
                cout << "Enter only '10 DIGIT PHONE NUMBER'." << endl << endl;
            else if (tillUnique("phone no.", file, phoneNo))
                return phoneNo;
            else cout << "Phone number is already taken." << endl << endl;
        }
    } else throw "Invalid type";
    return "";
}

/*checks whether a string a numeric or not*/
bool isNumeric(string str) {
    for (char ch: str) if (not isdigit(ch)) return false;
    return true;
}

/*checks until the field is unique*/
bool tillUnique(string type, ifstream &file, string arg) {
    bool unique = true;
    int size = fileSize(file);
    map<string,string> detailMap;

    while (file.tellg() < size) {
        detailMap = readData(file);

        if (detailMap[type] == arg){
            title(type);
            cout << type << " is already taken. Try Again..." << endl << endl;
            unique = false;
            break;
        }
    }
    file.seekg(0);
    return unique;
}

/*returns the size of files in bytes*/
int fileSize(ifstream &file) {
    file.seekg(0, ios::end);
    int size = file.tellg();
    file.seekg(0, ios::beg);
    return size;
}

/*reads the files and returns the map object*/
map<string,string> readData(ifstream &file) {
    int size, pos;
    map<string,string> details;
    string pair, key, value;

    file.read((char*)size, sizeof(int));
    char str[size + 1];
    file.read(str, size);
    str[size] = '\0';
    istringstream iss(str);
    
    while (getline(iss, pair, ';')) {
        pos = pair.find(':');
        key = pair.substr(0, pos);
        value = pair.substr(pos + 1);
        details[key] = value;
    }
    return details;
}

/*generates a random number of given range*/
int randint(int min, int max) {
    srand(time(0));
    return min + rand() % (max - min + 1);
}

/*displays all the details of the provided account*/
void displayAccount(map<string,string> details) {
    string temp;
    cout << "Account Details" << endl << endl;

    for (auto element: details) {
        cout << element.first << ": ";

        if (element.first == "password") {
            for (char i = 0; i < element.second.size(); i++) cout << '*';
            cout << endl;
        } else cout << element.second << endl;
    }
    cout << endl << "press enter to continue..."; cin.get(); cin.get();
}
                                                   
/*logs into an account and returns the map object associated with it*/
map<string,string> loginAccount() {
    string username, password;
    map<string,string> account;
    char check;
    cout << "Logging In Account" << endl;
    cout << "Enter username: "; cin >> username;
    ifstream file("bankDetails.dat", ios::binary);
    int size = fileSize(file);

    while (file.tellg() < size) {
        account = readData(file);

        if (account["username"] == username) {
            while (true) {
                cout << "Enter password: "; cin >> password;

                if (account["password"] == password) {
                    cout << endl << "Login Successful!" << endl;
                    cout << "press enter to continue..."; cin.get(); cin.get();
                    LOGGED_IN = true;
                    return account;
                } else cout << "Incorrect password, try again" << endl << endl;
            }
        }
    }
    cout << "No such username found." << endl << endl;

    while (not LOGGED_IN) {
        cout << "Press '1' to create an account or '2' to try again: "; cin >> check;

        if (check == '1') return createAccount();
        else if (check == '2') return loginAccount();
        else cout << "Invalid Input." << endl << endl;
    }
}

/*displays all details contained in the database*/
void displayDatabase() {
    ifstream file("bankDetails.dat", ios::binary);
    int size = fileSize(file);
    map<string,string> details;

    while (file.tellg() < size) {
        details = readData(file);
        displayMap(details);
        cout << endl;
    }
}

/*display a map object to the console*/
void displayMap(map<string,string> details) {
    for (pair<string,string> element: details)
        cout << element.first << ": " << element.second << endl;
}

/*deletes all the database files
***THE DELETED DATA ARE NOT RECOVERABLE ANYMORE!***/
void deleteDatabase() {
    if(remove("bankDetails.dat") == 0) cout << endl << "Data Successfully Deleted" << endl;
    else cout << "Error deleting the file";
}

/*edits the account details provided and updates the database*/
void editAccount(map<string,string> &details) {

    /*edits the account details of provided type*/
    auto editDetail = [&details](string type) -> void {
        string input;
        ifstream file("bankDetails.dat", ios::binary);

        while (true) {
            cout << "Enter password: "; cin >> input;
            if (input == details["password"]) break;
            cout << "Incorrect password, Try Again..." << endl << endl;
        }
        if (type == "name") {
            string name, lastName;
            cout << "Enter new name: "; cin >> name >> lastName;
            name.push_back(' '); name.append(lastName);
            title(name);
            details["name"] = name;
        } else details[type] = enterSpecific(type, file);
        updateDatabase(details, true);
    };

    string editMenu = "\
1. Name\n\
2. Password\n\
3. Phone Number\n";
    char input;
    cout << "Editing Account Details" << endl;
    cout << editMenu << endl;

    while (true) {
        cout << "Select what to edit --> "; cin >> input;

        if (input == '1') {
            editDetail("name");
            cout << endl << "Successfully New Name Updated." << endl;
        } else if (input == '2') {
            editDetail("password");
            cout << "Successfully New Password Updated." << endl;
        } else if (input == '3') {
            editDetail("phone no.");
            cout << endl << "Successfully New Phone Number Updated." << endl;
        } else{
            cout << "Enter Valid Input. Try Again..." << endl << endl;
            continue;
        }
        cout << "press enter to continue..."; cin.get(); cin.get();
        break;
    }
}

/*updates the database with the new or existing account*/
void updateDatabase(map<string,string> details, bool mode) {
    vector <map<string,string>> list;
    map<string,string> data;
    ifstream file("bankDetails.dat", ios::binary);
    int size = fileSize(file);

    while (file.tellg() < size) {
        data = readData(file);
        if (data["account no."] == details["account no."]) {
            if (mode) list.push_back(details);
            else continue;
        } else list.push_back(data);
    }
    file.close();
    ofstream log("bankDetails.dat", ios::binary);
    for (auto item: list) writeData(log, item);
    log.close();
}

/*deposits or withdraws the amount of money from the account provided*/
void transaction(string type) {
    float amount = acceptAmount(), currentAmount = stof(ACTIVE["balance"]);
    cout << endl << "Initiating Transaction." << endl;
    
    while (true) {
        if (type == "deposit") {
            currentAmount += amount;
            break;
        } else if (type == "withdraw") {
            if (currentAmount >= amount) {
                currentAmount -= amount;
                break;
            } else {
                cout << "Invalid funds. Try Again..." << endl;
                amount = acceptAmount();
            }
        }
    }
    ACTIVE["balance"] = to_string(currentAmount);
    updateDatabase(ACTIVE, true);
    cout << "Transaction Successful" << endl << "press enter to continue..."; cin.get(); cin.get();
}

/*accepts the amount, validates it and returns the value*/
float acceptAmount() {
    float amount;

    while (true) {
        cout << "Enter amount: "; cin >> amount;
        if (amount < 0) cout << "Input Valid Number. Try Again..." << endl;
        else return amount;
    }
}

/*pays the amount to the username from the account provided*/
void pay() {
    map<string,string> receiver;
    string username = acceptUsername(receiver);
    float amount, balance;

    while (true) {
        amount = acceptAmount();
        if (balance = (stof(ACTIVE["balance"]) - amount) >= 0) break;
        cout << "Insufficient Funds. Try again..." << endl << endl;
    }
    ACTIVE["balance"] = to_string(balance);
    receiver["balance"] = to_string(stof(receiver["balance"]) + amount);
    updateDatabase(ACTIVE, true); updateDatabase(receiver, true);
    cout << "press enter to continue..."; cin.get(); cin.get();
}

/*accepts a username and checks whether or its account and returns the username and account details (by reference)*/
string acceptUsername(map<string,string> &receiver) {
    ifstream file("bankDetails.dat", ios::binary);
    int size = fileSize(file);
    bool flag = true;
    string username;

    while (true) {
        cout << "Enter receiver's username: "; cin >> username;

        while(file.tellg() < size) {
            receiver = readData(file);
            if (receiver["username"] == username) return username;
        }
        cout << "Username doesn't exist. Try again..." << endl << endl;
    }    
}

/*deletes the account from the database and logs out*/
void deleteAccount() {
    string password1, password2, conformation;
    cout << "Deleting account" << endl;

    while (true) {
        cout << "Enter password: "; cin >> password1;
        cout << "Enter password again: "; cin >> password2;
        
        if (not (ACTIVE["password"] == password1 and password1 == password2)) {
            cout << "Incorrect Password. Try Again..." << endl << endl;
            continue;
        }
        cout << endl << "DO YOU REALLY WANT TO DELETE YOUR ACCOUNT. TYPE 'YES' TO CONTINUE OR 'NO' TO ABORT: "; cin >> conformation;

        if (upper(conformation) == "NO") cout << "Account Deletion Unsuccessful!" << endl;
        else if (upper(conformation) != "YES") cout << "Invalid Input. Try Again..." << endl;
        else {
            updateDatabase(ACTIVE, false);
            cout << "Account Successfully Deleted!" << endl;
            LOGGED_IN = false;
            ACTIVE.clear();
        }
    }
}

/*converts the string to uppercase*/
string upper(string &str) {
    for (char &ch: str) toupper(ch);
    return str;
}