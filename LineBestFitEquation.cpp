/*
Jaztin Tabunda
6/16/2020
*/
#include "LineBestFitEquation.h"


LineBestFitEquation::LineBestFitEquation()
{
	
}

bool LineBestFitEquation::setTotalNumOrderedPairs(int statedNumVars)
{
	if (statedNumVars > 0)
	{
		totalNumOrderedPairs = statedNumVars;
		orderedPairValueX = new double[totalNumOrderedPairs];
		orderedPairValueY = new double[totalNumOrderedPairs];
		orderedPairXMinusMeanX = new double[totalNumOrderedPairs];
		orderedPairYMinusMeanY = new double[totalNumOrderedPairs];
		return true;
	}
	else
	{
		return false;
	}
}

bool LineBestFitEquation::setOrderedPairValueX(double passedValueX, int passedCounter)
{
	if (passedValueX >= -100 && passedValueX <= 100)
	{
		orderedPairValueX[passedCounter] = passedValueX;
		return true;
	}
	else
	{
		return false;
	}
}

bool LineBestFitEquation::setOrderedPairValueY(double passedValueY, int passedCounter)
{
	if (passedValueY >= -100 && passedValueY <= 100)
	{
		orderedPairValueY[passedCounter] = passedValueY;
		return true;
	}
	else
	{
		return false;
	}

}

double LineBestFitEquation::getOrderedPairValueX(int passedCounter)
{
	return orderedPairValueX[passedCounter];
}

double LineBestFitEquation::getOrderedPairValueY(int passedCounter)
{
	return orderedPairValueY[passedCounter];
}

double LineBestFitEquation::calcMeanValueX()
{
	double meanValueX = 0;
	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		meanValueX = orderedPairValueX[counter] + meanValueX;
	}
	meanValueX = meanValueX / totalNumOrderedPairs;
	return meanValueX;
}

double LineBestFitEquation::calcMeanValueY()
{
	double meanValueY = 0;
	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		meanValueY = orderedPairValueY[counter] + meanValueY;
	}
	meanValueY = meanValueY / totalNumOrderedPairs;
	return meanValueY;
}

double LineBestFitEquation::calcBestFitSlope()
{
	double bestFitSlope = 0;
	double multipliedXandY = 0;
	double squaredX = 0;
	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		orderedPairXMinusMeanX[counter] = orderedPairValueX[counter] - calcMeanValueX();
	}

	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		orderedPairYMinusMeanY[counter] = orderedPairValueY[counter] - calcMeanValueY();
	}
	
	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		multipliedXandY = (orderedPairXMinusMeanX[counter] * orderedPairYMinusMeanY[counter]) + multipliedXandY;
	}

	for (int counter = 0; counter < totalNumOrderedPairs; counter++)
	{
		squaredX = (pow(orderedPairXMinusMeanX[counter], 2)) + squaredX;
	}

	bestFitSlope = multipliedXandY / squaredX;
	return bestFitSlope;

}

double LineBestFitEquation::calcYIntercept()
{
	double YIntercept = 0;
	YIntercept = calcMeanValueY() - (calcBestFitSlope() * calcMeanValueX());
	return YIntercept;
}