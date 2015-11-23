#include <iostream>                                     // Ein- und Ausgabebibliothek
#include <string>
#include "scenariocreator.hpp"

int main(int argc, char *argv[]){                                             // Hauptfunktion

    std::cout << "Anzahl Argumente: " << argc <<std::endl;

    if(argc>3)
    {
    	std::string inputname;

    	inputname=argv[1];
    	std::cout << "Größer als drei!"<< std::endl;

    	Scenariocreator s;
    	s.generateScenario();
    	s.createScenariosFromXML();

    }
    else
    {
    	std::cout << "kleiner als drei"<< std::endl;
    }

    return 0;                                           // Optionale Rückgabe an das Betriebssystem

}
