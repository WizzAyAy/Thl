#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <QtGui>
#include <QApplication>

#include <cstring>

int main( int argc, char **argv) {
    QApplication app(argc,argv);

    Driver * driver = new Driver;
    Scanner * scanner = new Scanner(std::cin, std::cout);
    yy::Parser * parser = new yy::Parser(*scanner, *driver);

    parser->parse();

    driver->exec();
    driver->getville()->show();
    driver->construireVille();

    return app.exec();
}
