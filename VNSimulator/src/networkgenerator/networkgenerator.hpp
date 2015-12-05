/*
 * networkgenerator.hpp
 *
 *  Created on: 03.12.2015
 *      Author: alexander
 */

#ifndef SRC_NETWORKGENERATOR_HPP_
#define SRC_NETWORKGENERATOR_HPP_

class NetworkGenerator
{
public:
	void generateRandomNetwork();
};

class VirtualNetworkGenerator : NetworkGenerator
{
public:
   void generateObject();
   void randomNodeData();
   void randomNodeCPU();
   void randomNodeMEM();
   void randomNodeType();
};

class PhysicalNetWorkGenerator : NetworkGenerator
{

};


#endif /* SRC_NETWORKGENERATOR_HPP_ */
