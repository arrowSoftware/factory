#include "GeneratorUI.h"

#include <QApplication>

#include "PowerGenerator.h"
#include "Fuel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PowerGenerator *generator = new PowerGenerator(30, 0, 30);
    generator->addFuel(new Leaves(0));
    generator->addFuel(new Leaves(1));
    generator->addFuel(new Leaves(2));

    GeneratorUI w(generator);
    w.show();
    return a.exec();
}
