#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Item {
    private:
        string name;
        float price;
        int quantity;

    public:
        Item() {}
        Item(string name, float price, int quantity);
        friend ifstream &operator>>(ifstream &file, Item &item);
        friend ofstream &operator<<(ofstream &file, Item &item);
        friend ostream &operator<<(ostream &out, Item &item);
};

Item::Item(string name, float price, int quantity) {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}
ofstream &operator<<(ofstream &file, Item &item) {
    file << item.name << endl << item.price << endl << item.quantity << endl;
    return file;
}
ifstream &operator>>(ifstream &file, Item &item) {
    file >> item.name >> item.price >> item.quantity;
    return file;
}
ostream &operator<<(ostream &out, Item &item) {
    out << item.name << endl << item.price << endl << item.quantity << endl;
    return out;
}

int main() {
    int num, quantity;
    string name;
    float price;

    cout << "Enter number of Item: ";
    cin >> num;

    vector <Item *> list;
    cout << "Enter All Item " << endl;

    for(int i = 0; i < num; i++) {
        cout << "Enter " << i+1 << " Item Name: ";
        cin >> name;
        cout << "Enter " << i+1 << " Item Price: ";
        cin >> price;
        cout << "Enter " << i+1 << " Item Quantity: ";
        cin >> quantity;
        list.push_back(new Item(name, price, quantity));
    }

    ofstream file("Items.txt");
    vector <Item *> :: iterator iter;

    for (iter = list.begin(); iter != list.end(); iter++)
        file << **iter;

    Item item;
    ifstream log("Items.txt");

    for(int i = 0; i < num; i++) {
        log >> item;
        cout << "Item " << i << item << endl;
    }
    return 0;
}