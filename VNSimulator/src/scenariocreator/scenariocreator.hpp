/*
 * scenariocreator.hpp
 *
 *  Created on: 21.11.2015
 *      Author: alexander
 */

#ifndef SCENARIOCREATOR_HPP_
#define SCENARIOCREATOR_HPP_
#include <vector>
#include <string>
#include "../pugixml/pugixml.hpp"
#include "../demandcreator/demandcreator.hpp"
// in myclass.h


/** \brief generates a scenario or multiple scenarios
 *  \author    Alexander Kosch
 *  \version   0.1alpha
 *  \date      2015
*/
class Scenariocreator
{
public:
  void generateScenario(std::vector<int> parameters);
  void createScenariosFromXML();
  std::vector <int> getParameter(std::string netType, std::string param);
  std::vector <int> maxmintoVector(std::string netType, std::string param);
  std::vector <int> getParameterVector(pugi::xml_node tools, std::string param);
  int loadDocument();
  void getMethod();
  void cartesianProduct(const std::vector<std::vector<int> > &allVecs, std::vector<std::vector<int> > &solutionVecs, size_t vecIndex, std::vector<int> emptyVec);
  void poolingValueVectors(std::vector <std::vector <int> > &allVecs);

private:
	std::string algorithm_method;
	pugi::xml_document doc;
};






#endif /* SCENARIOCREATOR_HPP_ */
