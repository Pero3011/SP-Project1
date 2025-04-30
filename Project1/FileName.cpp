#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <fstream>
using namespace std;


struct services_struct{
	string names;
	float cost;
};

struct Schedule {
	string model;
	int year;
	int mileage;
	int months;
	vector<string> partNames; // Dynamic list of parts
	vector<string> serviceNames; //Dynamic list of services
};

vector<services_struct> services;
vector<Schedule> schedule;

//Admin Functions Declaration

void services_edit();
void display_services();
void schedule_edit();
void display_schedule();
float updateTaxRate();




int main() {

	//services_edit();
	//updateTaxRate();
	schedule_edit();
}

void display_services()
{
	cout << "______________________________\n";
	cout << "Name\t\t\t" << "Cost" << endl;
	cout << "------------------------------\n";
	for (int i = 0; i < services.size(); i++)
	{
		cout << i + 1 << ". " << services[i].names << "\t\t$";
		cout << services[i].cost << endl;
	}
	cout << "______________________________\n";
}

void display_schedule() {
	cout << "\n--- Maintenance Schedule ---\n";
	for (auto& s : schedule) {
		cout << "Model: " << s.model <<endl<< "Year: " << s.year<<endl
			<< "Mileage: " << s.mileage << " per " << s.months << " months\n";
		cout << "Parts:\n";
		for (auto& part : s.partNames) {
			cout << " - " << part << endl;
		}
		cout << endl;
		cout << "Services:\n";
		for (auto& service : s.serviceNames) {
			cout << " - " << service << endl;
		}
		cout << endl;
	}
}

void services_edit(){

	cout << "<--- Welcome to the Services section --->" << endl;
	string answer;
	do
	{
		cout << "Add a service or Update an exicting service(Add,update or exit): \n ";
		cin >> answer;
		if (answer == "add") /*checking the type of feature*/ 
		{
			//variables
			string name;
			float price;


			//input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clear the input buffer

			cout << "enter the name of the new service:\n";
			getline(cin, name); //read multiple words from the user
			cout << "enter the cost of the new service:\n";
			cin >> price;
			transform(name.begin(), name.end(), name.begin(), ::tolower);

			//update the array
			services.push_back({ name,price });

			//display results
			display_services();
			cout << "Successfully Added!!" << endl;
		}
		else if (answer == "update")
		{

			display_services();

			cout << "Choose a service to edit by its name:\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clear the input buffer
			getline(cin,answer);
			transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

			for (int i = 0; i < services.size(); i++)
			{
				float cost_update;
				if (answer == services[i].names)
				{

					cout << "Enter the new cost for "+services[i].names<<endl;
					cin >> cost_update;
					services[i].cost = cost_update;	//update the cost

					display_services();
					cout << "Successfully Updated!!" << endl;

					break;

				}
				else if (i == (services.size() - 1) && answer != services[i].names)
				{
					cout << "Invalid service..Try Again!!" << endl;
				}

			}
		}
	} while (answer != "exit");
}

float updateTaxRate()
{
	float taxRate = 0.15;
	cout << "Current Tax Rate: " << taxRate * 100 << "%\n";
	cout << "Enter New Tax Rate (%): ";
	float newTax;
	cin >> newTax;
	taxRate = newTax / 100; // Convert percentage to decimal
	cout << "Tax Rate Updated Successfully to " << taxRate * 100 << "%\n";
	return taxRate;
}

void schedule_edit()
{
	cout << "<--- Welcome to Maintenance Schedule --->" << endl;
	string answer;
	do
	{
       
		cout << "\nType 'add' to add maintenance,or 'update' to update existing maintenance, or 'exit' to quit: ";
		cin >> answer;

		if (answer == "add") {
			Schedule newEntry;
			cout << "Enter the car model: ";
			cin >> newEntry.model;
			cout << "Enter the model year: ";
			cin >> newEntry.year;
			cout << "Enter the mileage of the car: ";
			cin >> newEntry.mileage;
			cout << "Enter maintenance interval (in months): ";
			cin >> newEntry.months;

			int partscounter;
			cout << "How many parts do you want to add? ";
			cin >> partscounter;

			string partname;
			for (int i = 0; i < partscounter; i++) {
				cout << "Enter part name #" << i + 1 << ": ";
				cin >> partname;
				newEntry.partNames.push_back(partname);
			}

			int servicecounter;
			cout << "How many services do you want to add? ";
			cin >> servicecounter;

			string servicename;
			for (int i = 0; i < servicecounter; i++) {
				cout << "Enter service name #" << i + 1 << ": ";
				cin >> servicename;
				newEntry.serviceNames.push_back(servicename);
			}

			schedule.push_back(newEntry); // Add to global schedule
			display_schedule();
		}
		else if(answer=="update")
		{

		}
	} while (answer!="exit");

}
