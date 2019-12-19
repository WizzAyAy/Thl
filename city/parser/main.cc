#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"
#include "construction.hh"
#include <iostream>
#include <fstream>
#include <cstring>

int main( int  argc, char* argv[]) {
    Driver driver;
    Scanner scanner(std::cin, std::cout);
    yy::Parser parser(scanner, driver);

    parser.parse();
    //std::cout<<"taille -> "<<driver.getLesInstructions().size()<<std::endl;
    driver.afficherDriver();
    return 0;
}
