/*
Jaztin Tabunda
6/16/2020
*/
#include "LineBestFitEquation.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	LineBestFitEquation genEquation;
	char menuSelection;
	double passingX;
	double passingY;
	int numVars;
	do
	{
		cout << "Hello Welcome to the Linear Regression Program!\n"
			<< "This program can generate a line of best fit \n"
			<< "equation based on the values you give.\n\n"
			<< "--------------------------------------\n\n"
			<< "a) Make a line of best fit equation\n"
			<< "q) Quit the Program\n" << endl;
		cin >> menuSelection;

		if (menuSelection == 'a' || menuSelection == 'A')
		{
			do
			{
				cout << "How many independent variables do you have?\n";
				cin >> numVars;
				genEquation.setTotalNumOrderedPairs(numVars);
				if (genEquation.setTotalNumOrderedPairs(numVars) == 0)
				{
					cout << "That's invalid. Please enter a number greater than zero.\n\n";
				}
			} while (genEquation.setTotalNumOrderedPairs(numVars) == 0);
			
			cout << "Please type in the independent (X) values for each ordered pair [values must be between -100 to 100]\n";
			for (int counter = 0; counter < numVars; counter++)
			{
				cout << "Independent (X) Value for Ordered pair #" << counter + 1 << ": \n";
				cin >> passingX;
				genEquation.setOrderedPairValueX(passingX , counter);
				while (genEquation.setOrderedPairValueX(passingX, counter) == 0)
				{
					cout << "Invalid Entry. Please try again. Please enter a value between -100 to 100.\n";
					cin >> passingX;
				}
			}

			cout << "Please type in the dependent (Y) values for each ordered pair [values must be between -100 to 100]\n";
			for (int counter = 0; counter < numVars; counter++)
			{
				cout << "Dependent Value (Y) for Ordered pair #" << counter + 1 << ": \n";
				cin >> passingY;
				genEquation.setOrderedPairValueY(passingY, counter);
				while (genEquation.setOrderedPairValueY(passingY, counter) == 0)
				{
					cout << "Invalid Entry. Please try again. Please enter a value between -100 to 100.\n";
					cin >> passingY;
				}
			}

			cout << setprecision(2) << fixed << "From the values you entered: \n"
				<< "The X Mean Value is: " << genEquation.calcMeanValueX() << "\n"
				<< "The Y Mean Value is: " << genEquation.calcMeanValueY() << "\n"
				<< "The Best Fit slope is: " << genEquation.calcBestFitSlope() << "\n"
				<< "The Y Intercept of the Best Fit Line is: " << genEquation.calcYIntercept() << "\n"
				<< "The Best Fit Line Equation is: y = " << genEquation.calcBestFitSlope() << "x + " << genEquation.calcYIntercept() << endl;


		}
		else if (menuSelection == 'q' || menuSelection == 'Q')
		{
			cout << "You chose to Quit the Program. Goodbye.\n\n";
		}
		else
		{
			cout << "Invalid Selection. Please select either a or q.\n\n";
		}
	} while (menuSelection != 'q' && menuSelection != 'Q');




}