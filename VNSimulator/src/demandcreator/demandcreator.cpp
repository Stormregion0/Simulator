/*
 * demandcreator.cpp
 *
 *  Created on: 24.11.2015
 *      Author: alexander
 */



#include <cstdlib>
#include "demandcreator.hpp"





	Demand Demandcreator::createConstantDemand()
	{
		Demand onedemand;
		/* initialize random seed: */
		//srand (time(NULL));

		/* generate secret number between 1 and 10: */
		int iSecret = rand() % 10 + 1;
		onedemand.testdemand=2;
		return onedemand;
	}

	std::vector <Demand> Demandcreator::createConstantDemands(int Demands)
	{
		std::vector <Demand> demands;

		int i=0;
		while (i<Demands)
		{
			i++;
			//Demand onedemand= createConstantDemand();
			demands.push_back(createConstantDemand());
		}
		return demands;
	}
