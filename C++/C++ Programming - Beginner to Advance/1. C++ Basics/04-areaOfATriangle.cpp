#include <iostream>
using namespace std;

int main() {
    float area, length, breath;
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the breath: ";
    cin >> breath;
    area = length * breath / 2;
    cout << "Area of the Triangle is " << area;
    return 0;
}