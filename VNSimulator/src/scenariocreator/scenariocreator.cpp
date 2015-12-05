/*
 * scenariocreator.cpp
 */

#include <iostream>
#include "scenariocreator.hpp"
#include "../pugixml/pugixml.hpp"
#include "../demandcreator/demandcreator.hpp"
#include "../test.hpp"
#include <string>
#include <typeinfo>
#include <vector>

/**
	\brief generates a scenario

	This function generates a scenario and returns the object.

	@param[in]     parameters
*/
void Scenariocreator::generateScenario(std::vector<int> parameters)
	{
		std::cout << "generate Scenario" <<std::endl;

		if(algorithm_method=="AC")
		{
			std::cout << "AC wurde aktiviert"<<std::endl;

		}
		else if(algorithm_method=="GR")
		{
			std::cout << "GR wurde aktiviert"<<std::endl;

		}
		else
		{
			std::cout << "Keins von beiden"<<std::endl;

		}

		Demandcreator dem_gen;

		std::vector <Demand> demands=dem_gen.createConstantDemands(2);

		std::cout<<"Demands[0].testdemand: "<<demands[0].testdemand<<std::endl;

		TestingGraph gt;

		gt.koschtest();
	}

/**
	\brief creates scenarios

	This function creates scenarios out of xml files and starts the running process
*/
void Scenariocreator::createScenariosFromXML()
	{
		std::cout <<"createScenarioFromXML"<<std::endl;
		int c=loadDocument();
		getMethod();

		std::vector <std::vector <int> > allVecs, solutionVecs;
		std::vector<int> emptyVec;

		poolingValueVectors(allVecs);
		cartesianProduct(allVecs, solutionVecs, 0, emptyVec);

		for(int scenarionum=0;scenarionum<solutionVecs.size(); scenarionum++)
		{
			generateScenario(solutionVecs[scenarionum]);
		}


	}

/**
	\brief pools all parameter vectors into a new vector

	This function pools all parameter vector into a new vector.
	This is necessary to process the data later.

	@param[out]    allVecs This is the vector were all parameter vectors are stored in
*/
void Scenariocreator::poolingValueVectors(std::vector <std::vector <int> > &allVecs)
{

	std::cout <<"poolingValueVectors"<<std::endl;
	std::vector <int> phmincpu=maxmintoVector("physicalnet", "mincpu");
	std::vector <int> phmaxcpu=maxmintoVector("physicalnet", "maxcpu");
	std::vector <int> phminmem=maxmintoVector("physicalnet", "minmem");
	std::vector <int> phmaxmem=maxmintoVector("physicalnet", "maxmem");
	std::vector <int> phminbw=maxmintoVector("physicalnet", "minbw");
	std::vector <int> phmaxbw=maxmintoVector("physicalnet", "maxbw");
	std::vector <int> phmindelay=maxmintoVector("physicalnet", "mindelay");
	std::vector <int> phmaxdelay=maxmintoVector("physicalnet", "maxdelay");


	std::vector <int> virmincpu=maxmintoVector("virtualnet", "mincpu");
	std::vector <int> virmaxcpu=maxmintoVector("virtualnet", "maxcpu");
	std::vector <int> virminmem=maxmintoVector("virtualnet", "minmem");
	std::vector <int> virmaxmem=maxmintoVector("virtualnet", "maxmem");
	std::vector <int> virminbw=maxmintoVector("virtualnet", "minbw");
	std::vector <int> virmaxbw=maxmintoVector("virtualnet", "maxbw");
	std::vector <int> virmindelay=maxmintoVector("virtualnet", "mindelay");
	std::vector <int> virmaxdelay=maxmintoVector("virtualnet", "maxdelay");

	std::vector <int> alpha=maxmintoVector("algorithm", "alpha");
	std::vector <int> beta=maxmintoVector("algorithm", "beta");
	//std::vector <int> rho=maxmintoVector("algorithm", "rho");//floatproblem
	std::vector <int> phi=maxmintoVector("algorithm", "phi");
	std::vector <int> numberofiterations=maxmintoVector("algorithm", "numberofiterations");
	std::vector <int> numberofants=maxmintoVector("algorithm", "numberofants");
	std::vector <int> hops=maxmintoVector("algorithm", "hops");
	std::vector <int> radius=maxmintoVector("algorithm", "radius");
	std::vector <int> startpheromone=maxmintoVector("algorithm", "startpheromon");
	std::vector <int> minpheromone=maxmintoVector("algorithm", "minpheromon");
	std::vector <int> maxpheromon=maxmintoVector("algorithm", "maxpheromon");
	//std::vector <int> importance_elitism=maxmintoVector("algorithm", "elitism");//float problem


	//method ist private variable
	std::vector <int> numberofdemands= maxmintoVector("demands", "number");
	std::vector <int> averagearrival=maxmintoVector("demands", "avgarrival");
	std::vector <int> lifetime=maxmintoVector("demands", "lifetime");
	//std::vector <int> seed=maxmintoVector("demands", "seed");

	allVecs.push_back(phmincpu);
	allVecs.push_back(phmaxcpu);
	allVecs.push_back(phminmem);
	allVecs.push_back(phmaxmem);
	allVecs.push_back(phminbw);
	allVecs.push_back(phmaxbw);
	allVecs.push_back(phmindelay);
	allVecs.push_back(phmaxdelay);

	allVecs.push_back(virmincpu);
	allVecs.push_back(virmaxcpu);
	allVecs.push_back(virminmem);
	allVecs.push_back(virmaxmem);
	allVecs.push_back(virminbw);
	allVecs.push_back(virmaxbw);
	allVecs.push_back(virmindelay);
	allVecs.push_back(virmaxdelay);

	allVecs.push_back(alpha);
	allVecs.push_back(beta);
	//allVecs.push_back(rho);
	allVecs.push_back(phi);
	allVecs.push_back(numberofiterations);
	allVecs.push_back(numberofants);
	allVecs.push_back(hops);
	allVecs.push_back(radius);
	allVecs.push_back(startpheromone);
	allVecs.push_back(minpheromone);
	allVecs.push_back(maxpheromon);
	//allVecs.push_back(importance_elitism);

	allVecs.push_back(numberofdemands);
	allVecs.push_back(averagearrival);
	allVecs.push_back(lifetime);
	//allVecs.push_back(seed);


}

/**
	\brief This function creates a cartesian product of the input.

	The function produces a cartesian product of the input.
	The input are vectors within a vector called allVecs.
	The solution is produced recursive and stored im emptyVec.
	When finished this partial solution is stored in solution Vecs.

	@param[in]     allVecs contains all input vectors
	@param[out]    solutionVecs stores all solutions
	@param[in] 	   vecIndex marks the current parameterVec which is processed
	@param[in]     emptyVec stores the solution of the current branch
*/
void Scenariocreator::cartesianProduct(const std::vector<std::vector<int> > &allVecs, std::vector<std::vector<int> > &solutionVecs, size_t vecIndex, std::vector<int> emptyVec)
{
	//std::cout << "jup" << std::endl;

    if (vecIndex >= allVecs.size())
    {
        //std::cout << "jup" << std::endl;

        solutionVecs.push_back(emptyVec);
        //emptyVec.clear();
        return;
    }
    for (size_t i=0; i<allVecs[vecIndex].size(); i++)
    {
    	emptyVec.push_back(allVecs[vecIndex][i]);
    	cartesianProduct(allVecs, solutionVecs, vecIndex+1, emptyVec);
        emptyVec.pop_back();
    }
}

/**
	\brief generates a vector with all values from min to max with a certain step.

	@param[in]     netType determines which pugichild is choosen.
	@param[in]     param determines which value has to be parsed.
	@return returns the completed vector with all values
*/
std::vector <int> Scenariocreator::maxmintoVector(std::string netType, std::string param)
	{
		std::vector <int> rawVector=getParameter(netType, param);
		std::vector <int> valueVector;

		int minValue=rawVector[0];
		int maxValue=rawVector[1];
		int step=rawVector[2];
		int x=minValue;

		while(x<=maxValue)
		{
			//std::cout << "x: "<<x<<std::endl;
			valueVector.push_back(x);
			x+=step;
		}

		return valueVector;



	}

/**
	\brief loads document

	Loads the document and stores the doc object in a class variable.

	@return zero if successfull, -1 if not.
*/
int Scenariocreator::loadDocument()
{
	if (!doc.load_file("elitism_ac.xml"))
	{
		return -1;
	}
	return 0;
}

/**
	\brief parses the algorithm method and stores in in class variable.

*/
void Scenariocreator::getMethod()
{
	algorithm_method=doc.child("scenarios").child("algorithm").attribute("method").value();

}

/**
	\brief returns the parameter with raw values and determines which part of the xml file should be read.

	@param[in]     netType determines which pugichild is choosen.
	@param[in]     param determines which value has to be parsed.
	@return is the vector with the range and step.
*/
std::vector <int> Scenariocreator::getParameter(std::string netType, std::string param)
	{
		if (netType=="physicalnet")
		{
			pugi::xml_node tools = doc.child("scenarios").child("physicalnet").child("data");
			std::vector <int> rawVector=getParameterVector(tools, param);
			return rawVector;
		}
		else if (netType=="virtualnet")
		{
			pugi::xml_node tools = doc.child("scenarios").child("virtualnet").child("data");
			std::vector <int> rawVector=getParameterVector(tools, param);
			return rawVector;
		}
		else if (netType=="algorithm")
		{
			pugi::xml_node tools = doc.child("scenarios").child("algorithm").child("data");
			std::vector <int> rawVector=getParameterVector(tools, param);
			return rawVector;
		}
		else if (netType=="demands")
		{
			pugi::xml_node tools = doc.child("scenarios").child("demands").child("data");
			std::vector <int> rawVector=getParameterVector(tools, param);
			return rawVector;
		}
	}

/**
	\brief parses the parameters of the XML file.

	The function parses all parameters and stores it in a vector.
	The arguments in the vector are min, max and the step.

	@param[in]     tools is the pugiobject for reading the file
	@param[in]     param determines which value has to be parsed
	@return is the vector with the range and step.
*/
std::vector <int> Scenariocreator::getParameterVector(pugi::xml_node tools, std::string param)
{

	for (pugi::xml_node tool = tools.first_child(); tool; tool = tool.next_sibling())
	{
		for (pugi::xml_attribute attr = tool.first_attribute(); attr; attr = attr.next_attribute())
		{
			std::string attribute= attr.value();
			if (param.compare(attribute)==0)
			{
				int param_from=tool.child("from").text().as_int();
				int param_to=tool.child("to").text().as_int();
				int param_step=tool.child("step").text().as_int();

				std::vector <int> param_vec;
				param_vec.push_back(param_from);
				param_vec.push_back(param_to);
				param_vec.push_back(param_step);
				//int param_array[3]={param_from, param_to, param_step};
				//std::cout <<param_array<<std::endl;
				return param_vec;

			}
		}
	}
}
