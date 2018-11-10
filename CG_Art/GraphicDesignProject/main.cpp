#include "MainWindow.h"
#include <QtWidgets/QApplication>

 // driver file
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
