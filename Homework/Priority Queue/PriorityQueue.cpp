#include <iostream>
#include <climits>
#include "PriorityQueue.hpp"
using namespace std;



PriorityQueue:: PriorityQueue(int _queueSize)
{
	currentQueueSize = 0;
	maxQueueSize = _queueSize;
	priorityQueue = new PatientNode[_queueSize+1];
}

PriorityQueue::~PriorityQueue()
{
	delete[] priorityQueue;

}
void PriorityQueue::enqueue (std::string _name, int _injurySeverity, int _treatmentTime)
{
	if(isFull())
	{
		cout << "Priority Queue Full. Send remaining patients to another hospital. " << endl;
		return;
	}
	PatientNode newPatient;
	newPatient.name = _name;
	newPatient.injurySeverity = _injurySeverity;
	newPatient.treatmentTime= _treatmentTime;

	priorityQueue[currentQueueSize+1] = newPatient;
	currentQueueSize += 1;
	repairUpward(currentQueueSize); 
}

string PriorityQueue::peekName()
{
	return priorityQueue[1].name;
}

int PriorityQueue::peekInjurySeverity()
{
	return priorityQueue[1].injurySeverity;
}

int PriorityQueue::peekTreatmentTime()
{
	return priorityQueue[1].treatmentTime;
}

void PriorityQueue::dequeue()
{
	if(!isEmpty())
	{
		priorityQueue[1] = priorityQueue[currentQueueSize];
		repairDownward(1);
		currentQueueSize -= 1; 
	}
}

bool PriorityQueue::isFull()
{
	return(currentQueueSize == maxQueueSize); 
}

bool PriorityQueue:: isEmpty()
{
	return(currentQueueSize == 0);
}

//member functions 
void PriorityQueue::repairUpward(int nodeIndex)
{
	if(nodeIndex != 1)
	{
		int parent = nodeIndex /2;//index of parent node

		if(priorityQueue[parent].injurySeverity <priorityQueue[nodeIndex].injurySeverity || 
			(priorityQueue[parent].injurySeverity == priorityQueue[nodeIndex].injurySeverity) && 
			(priorityQueue[parent].treatmentTime > priorityQueue[nodeIndex].treatmentTime)) //compares injury severity, if equal takes lowest treatment time
		{
			PatientNode temp = priorityQueue[parent];
			priorityQueue[parent] = priorityQueue[nodeIndex];
			priorityQueue[nodeIndex] = temp;
			repairUpward(parent); 
		}
	}
	return; 

}
void PriorityQueue::repairDownward(int nodeIndex)
{
	if(nodeIndex < currentQueueSize)
	{
		int leftChild = nodeIndex * 2;
		int rightChild = nodeIndex * 2 +1;
		int largeChild; 

		if(leftChild < currentQueueSize)
		{
			if(rightChild < currentQueueSize)
			{
				if(priorityQueue[leftChild].injurySeverity > priorityQueue[rightChild].injurySeverity || 
					(priorityQueue[leftChild].injurySeverity == priorityQueue[rightChild].injurySeverity && priorityQueue[leftChild].treatmentTime <
					priorityQueue[rightChild].treatmentTime ))//checks for severity and if theyre equal lowest treatment time 
				{
					largeChild = leftChild;
				}
				else
				{
					largeChild = rightChild;
				}
			}
			else
			{
				largeChild = leftChild;
			}
			if(priorityQueue[largeChild].injurySeverity > priorityQueue[nodeIndex].injurySeverity || (priorityQueue[largeChild].injurySeverity
				==priorityQueue[nodeIndex].injurySeverity && priorityQueue[largeChild].treatmentTime <priorityQueue[nodeIndex].treatmentTime))
				{
					PatientNode temp = priorityQueue[nodeIndex];
					priorityQueue[nodeIndex] = priorityQueue[largeChild];
					priorityQueue[largeChild]= temp;
					repairDownward(largeChild);
				}
		}
	}
	return; 
}