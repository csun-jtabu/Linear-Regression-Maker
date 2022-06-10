/*
Jaztin Tabunda
6/16/2020
*/

#ifndef LINEBESTFITEQUATION_H
#define LINEBESTFITEQUATION_H
#include <cmath>

class LineBestFitEquation
{
	private:

		int totalNumOrderedPairs;
		double *orderedPairValueX;
		double *orderedPairValueY;
		double *orderedPairXMinusMeanX;
		double *orderedPairYMinusMeanY;

	public: 

		LineBestFitEquation();
		bool setTotalNumOrderedPairs(int);
		bool setOrderedPairValueX(double, int);
		bool setOrderedPairValueY(double, int);
		double getOrderedPairValueX(int);
		double getOrderedPairValueY(int);
		double calcMeanValueX();
		double calcMeanValueY();
		double calcBestFitSlope();
		double calcYIntercept();
};


#endif // !LINEBESTFITEQUATION_H
