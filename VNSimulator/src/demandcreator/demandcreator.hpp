/*
 * demandcreator.hpp
 *
 *  Created on: 24.11.2015
 *      Author: alexander
 */

#ifndef SRC_DEMANDCREATOR_HPP_
#define SRC_DEMANDCREATOR_HPP_

#include <vector>
#include <string>
#include <iostream>
/*TESTKLASSE MUSS DANACH AUSGELAGERT WERDEN*/
class Demand
{
public:
	int testdemand;
};
/***********************************/



class Demandcreator
{
public:
	int test;
	Demand createConstantDemand();
	std::vector <Demand> createConstantDemands(int Demands);

private:
	int test2;
};




#endif /* SRC_DEMANDCREATOR_HPP_ */
