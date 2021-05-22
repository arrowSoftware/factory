#ifndef GENERATORUI_H
#define GENERATORUI_H

#include <QWidget>
#include <QTimer>

#include "PowerGenerator.h"

namespace Ui {
class GeneratorUI;
}

class GeneratorUI : public QWidget
{
    Q_OBJECT

    public:
        explicit GeneratorUI(PowerGenerator *pGenerator, QWidget *parent = nullptr);
        ~GeneratorUI();

    private slots:
      void realtimeDataSlot();

    private:
        Ui::GeneratorUI *ui;
        QTimer dataTimer;
        PowerGenerator *mGenerator;
};

#endif // GENERATORUI_H
