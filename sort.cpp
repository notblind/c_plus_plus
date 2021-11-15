#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


class Sort
{
protected:
	string main_name;

	Sort(string name): main_name(name)
	{
	}


public:
	string getName() 
	{
		return "\n" + main_name + " sort\n";
	}

	void printName() 
	{
		cout << getName();
	}

	void printVector(vector <int> list) 
	{
		for (int i = 0; i < list.size(); i++) 
		{
			cout << list[i];
		}
	}


	void start()
	{	
		vector <int> v = {3, 10, 2, 3, 7, 5, 5, 9, 1, 4};
		printVector(v);
		printName();

		float start_time = clock();
		sorting(v);
		float end_time = clock();

		printVector(v);

		cout << "\nTime: ";
		cout << (end_time - start_time) / 1000;
		cout << "с\n\n";
	}

	virtual void sorting(vector <int>& list)
	{
	}

};

class Bubble: public Sort
{
public:
	Bubble(string name): Sort(name)
	{
	}

	void sorting(vector <int>& list)
	{
		for (int i = 0; i < list.size(); i++) 
		{
			for (int j = 0; j < list.size(); j++)
			{
				if (list[j] > list[j + 1]) 
				{
					int b = list[j];
					list[j] = list[j + 1];
					list[j + 1] = b;
				}
			}
		}
	}
};

class Quick: public Sort
{
public:
	Quick(string name): Sort(name)
	{
	}

	void qSorting(vector <int>& list, int size)
	{
		int i = 0;
		int j = size - 1;

		int middle = list[size / 2];
		do 
		{
			while (list[i] < middle)
			{
				i++;
			}

			while (list[j] > middle)
			{
				j--;
			}

			if (i <= j){
				int b = list[i];
				list[i] = list[j];
				list[j] = b;
				i++;
				j--;
			}


		} while (i <= j);
		
		if (j > 0){
			qSorting(list, j + 1);
		}
		if (i < size){
			qSorting(list, size - 1);
		}
	}

	void sorting(vector <int>& list)
	{	
		qSorting(list, list.size());
	}
};


int main()
{
	Bubble bubble("Bubble");
	bubble.start();

	Quick quick("Quick");
	quick.start();


	return 0;
}