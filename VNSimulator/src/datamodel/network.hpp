/*
 * network.hpp
 *
 *  Created on: 03.12.2015
 *      Author: alexander
 */

#ifndef SRC_DATAMODEL_NETWORK_HPP_
#define SRC_DATAMODEL_NETWORK_HPP_

class Network
{
public:
	void setPosition();
	void getPosition();
	void getDistance();
	void getEdges();
	void getConnectedEdges();
	void getNodes();
	void addNode();
	void initNode();
	void addEdge();
	void initEdge();
	void setCPU();
	void getCPU();
	void setMEM();
	void getMEM();
	void setBandwidth();
	void getBandwidth();
	void setDelay();
	void getDelay();
	void setType();
	void getType();
	void getGraph();
	void getAllNodeAttribs();
	void getAllEdgeAttribs();

	Network();

};



#endif /* SRC_DATAMODEL_NETWORK_HPP_ */
