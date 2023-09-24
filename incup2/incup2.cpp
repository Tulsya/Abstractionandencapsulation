#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

    std::string getCity() const {
        return city;
    }
};

bool compareAddresses(const Address* a1, const Address* a2) {
    return a1->getCity() < a2->getCity();
}

void sortAddresses(Address** addresses, int size) {
    std::sort(addresses, addresses + size, compareAddresses);
}

int main() {
    std::ifstream inputFile("in3.txt");
    std::ofstream outputFile("out3.txt");

    int n;
    inputFile >> n;
    outputFile << n << std::endl;
    inputFile.ignore();

    Address** addresses = new Address * [n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int houseNumber, flatNumber;

        std::getline(inputFile, city);
        std::getline(inputFile, street);
        inputFile >> houseNumber;
        inputFile >> flatNumber;
        inputFile.ignore();

        addresses[i] = new Address(city, street, houseNumber, flatNumber);
    }

    sortAddresses(addresses, n);

    for (int i = 0; i < n; i++) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
        delete addresses[i];
    }

    delete[] addresses;

    inputFile.close();
    outputFile.close();

    return 0;
}

