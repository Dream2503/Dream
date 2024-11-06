#include <iostream>
#include <fstream>
#include <vector>
#define length 3
using namespace std;
typedef unsigned short unshort;

const string HEADER = "[Model No., RAM, Memory Type, Memory Size]\n";
unshort fileSize(ifstream &file);
bool checkUnique(unshort model);
string upper(string &str);
void create_append(string type);
void display_search(string type);
void update_delete(string type);
void deleteFile();

int main() {
    unshort choice;

    while (true) {
        cout << endl << endl << endl << "\t\tMAIN MENU" << endl;
        cout << "*****************************************" << endl << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Append Record" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Update Record" << endl;
        cout << "6. Delete Record" << endl;
        cout << "7. Delete Record File (Laptop.dat)" << endl;
        cout << "8. Exit from Project" << endl << endl;
        cout << "*****************************************" << endl << endl;
        cout << "Enter your choice between 1 to 8 ---> "; cin >> choice;
        cout << endl;

        if (choice == 1) create_append("create");
        else if (choice == 2) display_search("display");
        else if (choice == 3) create_append("append");
        else if (choice == 4) display_search("search");
        else if (choice == 5) update_delete("update");
        else if (choice == 6) update_delete("delete");
        else if (choice == 7) deleteFile();
        else if (choice == 8) {
            cout << "EXIT SUCCESSFUL";
            break;
        } else
            cout << "Invalid Input";
    }
    return 0;
}

/*returns the file size in bytes*/
unshort fileSize(ifstream &file) {
    file.seekg(0, ios::end);
    unshort size = file.tellg();
    file.seekg(0, ios::beg);
    return size;
}

/*checks whether the model number is unique or not*/
bool checkUnique(unshort model) {
    ifstream file("Laptop.dat", ios::binary);
    if (!file) throw "File wasn't opened successfully";
    unshort data[3], size = fileSize(file);
    char str[4];

    while (file.tellg() < size) {
        file.read((char*)data, sizeof(data)).read(str, length);
        str[length] = '\0';
        if (model == data[0]) return false;
    }
    return true;
}

/*converts the string to uppercase*/
string upper(string &str) {
    for (unsigned char idx = 0; idx < str.size(); idx++) toupper(str[idx]);
    return str;
}

/*creates or appends the record to the file*/
void create_append(string type) {
    ofstream file;
    if (type == "create") file.open("Laptop.dat", ios::binary);
    else if (type == "append") file.open("Laptop.dat", ios::binary | ios::app);
    else throw "Invalid type";

    if (!file) throw "File wasn't opened successfully";
    unshort data[3];
    string memType;
    char chk;

    while (true) {
        cout << "Enter Model No.: "; cin >> data[0];

        if (not checkUnique(data[0])) {
            cout << "Enter a unique model number" << endl << endl;
            continue;
        }
        cout << "Enter RAM (in GB): "; cin >> data[1];
        cout << "Enter Memory Type (SSD/HDD): "; cin >> memType;

        if (not (upper(memType) == "SSD" or memType == "HDD")) {
            cout << "Enter a valid memory type" << endl << endl;
            continue;
        }
        cout << "Enter Memory Size (in GB): "; cin >> data[2];
        cout << endl;

        file.write((char*)data, sizeof(data)).write(memType.c_str(), length).flush();
        if (type == "append") break;
        cout << "Add more Records(y/n): "; cin >> chk;
        cout << endl;
        if (chk == 'n') break;
    }
    if (type == "append") cout << "RECORD APPENDED" << endl << endl;
    else if (type == "create") cout << "RECORD CREATED" << endl << endl;
    else throw "Invalid input";
    file.close();
}

/*displays or searches the record(s) from the file*/
void display_search(string type) {
    ifstream file("Laptop.dat", ios::binary);
    if (!file) throw "File wasn't opened successfully";
    bool found = false;
    unshort mod, data[3], size = fileSize(file);
    char str[length + 1];
    cout << HEADER;
    if (type == "search") {cout << "Enter Model no.: "; cin >> mod;}

    while (file.tellg() < size) {
        file.read((char*)data, sizeof(data)).read(str, length);
        str[length] = '\0';
        string memType(str);
        if (type == "display" or mod == data[0]) {
            cout << '[' << data[0] << ", " << data[1] << ", " << memType << ", " << data[2] << ']' << endl;
            found = true;
        }
        if (found and type == "search") return;
    }
    if (found and  type == "display") cout << endl << "ALL RECORDS DISPLAYED" << endl;
    else if (found);
    else cout << "NO RECORD FOUND";
    file.close();
}

/*updates or deletes a record from thr file*/
void update_delete(string type) {
    ifstream file("Laptop.dat", ios::binary);
    if (!file) throw "File wasn't opened successfully";
    vector <unshort *> content;
    vector <string> types;
    bool flag = false;
    unshort mod, size = fileSize(file);
    char str[4];
    cout << "Enter Model no.: "; cin >> mod;

    while (file.tellg() < size) {
        unshort *data = new unshort[3];
        file.read((char*)data, sizeof(data)).read(str, length);
        str[length] = '\0';
        string memType(str);
        
        if (mod == data[0]) {
            flag = true;

            if (type == "update") {
                cout << "Enter New RAM (in GB): "; cin >> data[1];
                cout << "Enter New Memory Type (SSD/HDD): "; cin >> memType;
                cout << "Enter New Memory Size (in GB): "; cin >> data[2];
                upper(memType);
            }
            else if (type == "delete") continue;
            else throw "Invalid type";
        }
        content.push_back(data);
        types.push_back(memType);
    }
    file.close();

    if (!flag) {
        cout << endl << "NO RECORD FOUND" << endl << endl;
        return;
    }
    ofstream log("Laptop.dat", ios::binary);
    if (!log) throw "File wasn't opened successfully";

    for (unshort i = 0; i < content.size(); i++) {
        log.write((char*)content[i], sizeof(content)).write(types[i].c_str(), length);
        delete[] content[i];
    }
    if (type == "update") cout << endl << "RECORD UPDATED" << endl << endl;
    else if (type == "delete") cout << endl << "RECORD DELETE" << endl << endl;
    else throw "Invalid type";
    log.close();
}

/*deletes the file*/
void deleteFile() {
    if (remove("Laptop.data") == 0) cout << "File deleted successfully";
    else cout << "Error deleting the file";
}