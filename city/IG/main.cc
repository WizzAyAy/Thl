#include <iostream>
#include "villeGUI.hh"
#include <QtGui>
#include <QApplication>

int main( int argc, char **argv )
{
  VilleGUI * V;
  QApplication app(argc,argv);
  V = new VilleGUI();
     
  V->show();
  V->construireMaison(1,1,1);
  return app.exec();
}

