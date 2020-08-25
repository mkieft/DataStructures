/*
Maura Kieft
Homework 8
Boese
*/
#include <iostream>
#include <fstream>
#include <sstream> 
#include "PriorityQueue.hpp"
using namespace std;

int main(int argc, char* argv[])
{

	
	PriorityQueue priorityQueue(stoi(argv[1])); 

	 
	int totalWaitTime = 0;

	string userInput;
	int input;

	//loop until user quits
	while(input != 6)
	{
		cout<< "======Main Menu======" <<endl;
		cout << "1. Get Patient Information from File " << endl;
		cout << "2. Add Patient to Priority Queue " <<endl;
		cout << "3. Show Next Patient " << endl;
		cout << "4. Admit Next Patient " << endl;
		cout << "5. Process Entire Queue " << endl;
		cout << "6. Quit " << endl; 

		getline(cin, userInput);
		try
		{
			input = stoi(userInput);
		}
		catch (exception& e)
		{
			input = 10;
		}
		switch(input)
		{
			case 1:
			{
				ifstream inFile;
				inFile.open(argv[2]);
				if(inFile.is_open())
				{
					string _name, _injurySeverity, _treatmentTime;
					string line;
					int currentQueueSize = 0;
					getline(inFile, line);
					while(getline(inFile,line))
					{
						stringstream ss(line);
						ss>> _name >> _injurySeverity >> _treatmentTime;
						currentQueueSize++; 
						if(priorityQueue.isFull())
						{
							cout << "Priority Queue full. Send remaining patients to another hospital. " << endl;
							
						}
						else
						{
							priorityQueue.enqueue(_name, stoi(_injurySeverity), stoi(_treatmentTime));
						}
					}
				}
				inFile.close(); 
			
				break; 
			}


			case 2: 
			{
				if(priorityQueue.isFull())
				{
					cout << "Priority Queue full. Send patient to another hospital." <<endl;
					
					
				}
				else
				{
					string name, injurySeverityStr, treatmentTimeStr;
					int _injurySeverity, _treatmentTime;
					cout << "Enter Patient Name: " << endl;
					getline(cin, name);
					cout << "Enter Injury Severity: " <<endl;
					getline(cin, injurySeverityStr);
					cout << "Enter Treatment Time: " <<endl;
					getline(cin, treatmentTimeStr);

					_injurySeverity = stoi(injurySeverityStr);
					_treatmentTime = stoi(treatmentTimeStr);

					priorityQueue.enqueue(name, _injurySeverity, _treatmentTime);
				}
				
			
				break; 
			}

			case 3: 
			{
				if(priorityQueue.isEmpty())
				{
					cout << "Queue empty. " <<endl;
					
				}
				else
				{
					cout << "Patient Name: " << priorityQueue.peekName() << endl;
					cout << "Injury Severity: " << priorityQueue.peekInjurySeverity() <<endl;
					cout << "Treatment Time: " << priorityQueue.peekTreatmentTime() << endl; 

				}
				
			
				break; 
			}

			case 4:
			{
				if(priorityQueue.isEmpty())
				{
					cout << "Queue empty. " <<endl; 
					
				}
				else
				{
					totalWaitTime += priorityQueue.peekTreatmentTime(); 
					cout << "Patient Name: " <<priorityQueue.peekName() << " - Total Time Treating Patients: " << totalWaitTime << endl;

					priorityQueue.dequeue();
				}
				 
				break; 
			}

			case 5: 
			{
				if(priorityQueue.isEmpty())
				{
					cout << "Queue empty. " <<endl;
					
				}
				else
				{
					while(!priorityQueue.isEmpty())
					{

						totalWaitTime += priorityQueue.peekTreatmentTime();


						cout << "Patient Name: " <<priorityQueue.peekName() << " -Total Wait Time: " << totalWaitTime << endl; 
					
						priorityQueue.dequeue(); 
					}

					
				}
				
			break; 
			}

			case 6:
			{
				cout << "Goodbye! " <<endl; 
				
			break; 
			}

		}
	}

	





	return 0;
}