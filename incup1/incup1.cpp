#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int flatNumber;
public:
    Address(const std::string& city_, const std::string& street_,
        int houseNumber_, int flatNumber_)
        : city(city_), street(street_), houseNumber(houseNumber_), flatNumber(flatNumber_) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(flatNumber);
    }
};

int main() {
    std::ifstream inputFile("in2.txt");
    std::ofstream outputFile("out2.txt");

    int n;
    inputFile >> n;
    outputFile << n << std::endl;

    Address** addresses = new Address * [n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int houseNumber, flatNumber;
        inputFile.ignore();

        std::getline(inputFile, city);
        std::getline(inputFile, street);
        inputFile >> houseNumber;
        inputFile >> flatNumber;

        addresses[i] = new Address(city, street, houseNumber, flatNumber);
    }

    for (int i = n - 1; i >= 0; i--) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
        delete addresses[i];
    }

    delete[] addresses;

    inputFile.close();
    outputFile.close();

    return 0;
}
