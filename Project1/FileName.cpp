#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


//Global variables
float cost = 0;

struct{
	vector<string> names = {"Change Oil" , "Change Tyres"};
	vector<float> cost = {100,200};
} services;





//Admin Functions Declaration

void services_edit();
void schedule_edit();
float updateTaxRate();


int main() {
	services_edit();
	//updateTaxRate();
}

void services_edit(){
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

			//update the array
			services.names.push_back(name);
			services.cost.push_back(price);

			//display results
			cout << "______________________________\n";
			cout << "Name\t\t\t" << "Cost" << endl;
			cout << "------------------------------\n";
			for (int i = 0; i < services.names.size(); i++)
			{
				cout << i + 1 << ". " << services.names[i] << "\t\t$";
				cout << services.cost[i] << endl;
			}
			cout << "______________________________\n";
			cout << "Successfully Added!!" << endl;
		}
		else if (answer == "update")
		{
			cout << "______________________________\n";
			cout << "Name\t\t\t" << "Cost" << endl;
			cout << "------------------------------\n";
			for (int i = 0; i < services.names.size(); i++)
			{
				cout << i + 1 << ". " << services.names[i] << "\t\t";
				cout << services.cost[i] << endl;
			}
			cout << "______________________________\n";
			cout << "Choose a service to edit by its name:\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clear the input buffer
			getline(cin,answer);

			for (int i = 0; i < services.names.size(); i++)
			{
				float cost_update;
				if (answer == services.names[0])
				{

					cout << "Enter the new cost for "+services.names[i]<<endl;
					cin >> cost_update;
					services.cost[i] = cost_update;	//update the cost

					cout << "______________________________\n";
					cout << "Name\t\t\t" << "Cost" << endl;
					cout << "------------------------------\n";
					for (int i = 0; i < services.names.size(); i++)
					{
						cout << i + 1 << ". " << services.names[i] << "\t\t";
						cout << services.cost[i] << endl;
					}
					cout << "Successfully Updated!!" << endl;
					break;

				}
				else
				{
					cout << "This service does not exist!!..Try another one"<<endl;
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
