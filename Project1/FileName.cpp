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

struct maintenance {
	string partName;
	string serviceName;
};

struct maintenanceSchedule {
	string model;
	int year;
	int mileage;
	int months;
	vector<maintenance> maintenances;
};

vector<services_struct> services;
vector<maintenanceSchedule> schedule;

//Admin Functions Declaration

void services_edit();
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
void schedule_edit(string model, int year, int mileage, int months, vector<maintenance>schedule);
void display_schedule()
{
	cout << "--------------------------------------------------------------------\n";
	cout << "Model\t\t" << "year\t\t" << "Mileage/months\t\t" << "Maintenance" << endl;
	cout << "--------------------------------------------------------------------\n";
	for (int i = 0; i < schedule.size(); i++)
	{
		cout << schedule[i].model<<"\t\t\t";

		cout << schedule[i].year<<"\t\t\t";

		cout << schedule[i].mileage<<" / "<< schedule[i].months<<"\t\t\t";

		for (int j = 0; j < schedule[i].maintenances.size(); j++)
		{
			cout << "Parts:" << endl<<" ";
			cin >> schedule[i].maintenances[j].partName;
			cout << "Services:" << endl << " ";
			cin >> schedule[i].maintenances[j].serviceName;
		}
	}

}
float updateTaxRate();




int main() {

	//services_edit();
	//updateTaxRate();
	schedule_edit();
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

void schedule_edit(string model, int year, int mileage, int months,vector<maintenance>schedule)
{
	cout << "<--- Welcome to Maintenance Schedule --->" << endl;
	string answer;
	do
	{
		cout << "Add Maintenance or update the schedule:" << endl;
		cin >> answer;

		if (answer == "add")
		{
				cout << "Enter the car model:" << endl;
				cin >> model;
				cout << "Enter the model year:" << endl;
				cin >> year;
				cout << "Enter the mileage of the car:" << endl;
				cin >> mileage;
				cout << "per(/) ";
				cin >> months;

				//display_parts();
				cout << "Enter the name of the parts:"<<endl;
				cin >> schedule[i].maintenances[j].partName;

				display_services();
				cout << "Enter the services name:" << endl;
				cin >> schedule[i].maintenances[j].serviceName;

				schedule.push_back({model,year,mileage,months,{}})

			display_schedule();
			
		}

	} while (answer!="exit");
}
