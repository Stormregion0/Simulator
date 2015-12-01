#include <iostream>                                     // Ein- und Ausgabebibliothek
#include <string>
#include "scenariocreator/scenariocreator.hpp"
/*! \mainpage My Personal Index Page
 *  \author    Alexander Kosch
 *  \version   0.1alpha
 *  \date      2015
 *  \section intro_sec Introduction
 *
 *  This is the introduction.
 *
 *  \section install_sec Installation
 *
 *  Not ready yet.
 *
 */
int main(int argc, char *argv[]){                                             // Hauptfunktion

    std::cout << "Anzahl Argumente: " << argc <<std::endl;

    if(argc>3)
    {
    	std::string inputname;

    	inputname=argv[1];
    	std::cout << "Größer als drei!"<< std::endl;

    	Scenariocreator s;
    	s.createScenariosFromXML();

    }
    else
    {
    	std::cout << "kleiner als drei"<< std::endl;
    }

    return 0;                                           // Optionale Rückgabe an das Betriebssystem

}
