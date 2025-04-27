using namespace std;
#include <iostream>
#include <fstream>
#include "Transport.h"
#include "SpecialTransport.h"
#include "Invalid_Filter.h"
#include "Person.h"
#include "Cargo.h"

int main()
{
    try
    {
        ifstream in("file.txt");
        if (!in.is_open())
            throw runtime_error("Error opening file");

        int n;
        in >> n;
        in.ignore(); 
        if (n <= 0)
            throw invalid_argument("Invalid number of transports");

        BaseTransport** t = new BaseTransport * [n];

        for (int i = 0; i < n; i++)
        {
            string type;
            getline(in, type);

            if (type == "transport")
            {
                string destination;
                double price;
                string passenger_name;
                int passenger_age;

                getline(in, destination);
                in >> price;
                in.ignore();
                getline(in, passenger_name);
                in >> passenger_age;
                in.ignore();

                Person person(passenger_name, passenger_age);
                t[i] = new Transport<Person>(destination, price, person);
            }
            else if (type == "special")
            {
                string destination;
                double price;
                string cargo_name;
                double cargo_weight;
                string specialDelivery;

                getline(in, destination);
                in >> price;
                in.ignore();
                getline(in, cargo_name);
                in >> cargo_weight;
                in.ignore();
                getline(in, specialDelivery);

                Cargo cargo(cargo_name, cargo_weight);
                t[i] = new SpecialTransport<Cargo>(destination, price, cargo, specialDelivery);
            }
            else
            {
                throw runtime_error("Unknown transport type in file");
            }

            t[i]->print();
        }

        int numberOfTransport = 0;
        while (true)
        {
            cout << "Enter the number of transport(1-" << n << "): ";
            cin >> numberOfTransport;
            if (numberOfTransport >= 1 && numberOfTransport <= n)
                break;
            cout << "Invalid number, try again." << endl;
        }

        int choice = 0;
        while (true)
        {
            cout << "1. Change destination" << endl;
            cout << "2. Change cargo" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1 || choice == 2)
                break;
            cout << "Invalid choice, try again." << endl;
        }

        if (choice == 1)
        {
            string destination;
            cout << "Enter new destination: ";
            cin.ignore(); 
            getline(cin, destination);
            t[numberOfTransport - 1]->setDestination(destination);
        }
        else
        {
            cout << "Cargo cannot be changed directly for this demo version." << endl;
        }

        cout << "New details after change: " << endl;
        t[numberOfTransport - 1]->print();

        string filter;
        cout << "Enter filter(cargo or passengers): ";
        cin >> filter;
        if (filter != "cargo" && filter != "passengers")
            throw Invalid_Filter("allowed filters are cargo or passengers");

        for (int i = 0; i < n; i++)
        {
            SpecialTransport<Cargo>* special = dynamic_cast<SpecialTransport<Cargo>*>(t[i]);
            if (filter == "cargo" && special != nullptr)
            {
                special->print();
            }
            else if (filter == "passengers" && special == nullptr)
            {
                t[i]->print();
            }
        }

        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += t[i]->getPrice();
        }
        cout << "Total price: " << sum << endl;

        for (int i = 0; i < n; i++)
        {
            delete t[i];
        }
        delete[] t;
        in.close();
    }
    catch (const exception& e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
