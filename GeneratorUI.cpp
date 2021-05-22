#include "GeneratorUI.h"
#include "ui_GeneratorUI.h"

#include <string>
#include <sstream>

#include <stdio.h>

GeneratorUI::GeneratorUI(PowerGenerator *pGenerator, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneratorUI),
    mGenerator(pGenerator)
{
    ui->setupUi(this);

    ui->mQCustomPlot->addGraph();
    ui->mQCustomPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));
    ui->mQCustomPlot->graph(0)->setName("Max Consumption");

    ui->mQCustomPlot->addGraph();
    ui->mQCustomPlot->graph(1)->setPen(QPen(QColor(0, 255, 40)));
    ui->mQCustomPlot->graph(1)->setName("Power Capacity");

    ui->mQCustomPlot->addGraph();
    ui->mQCustomPlot->graph(2)->setPen(QPen(QColor(0, 0, 255)));
    ui->mQCustomPlot->graph(2)->setName("Power Consumption");

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->mQCustomPlot->xAxis->setTicker(timeTicker);
    ui->mQCustomPlot->axisRect()->setupFullAxesBox();
    ui->mQCustomPlot->yAxis->setRange(-5, mGenerator->getMaximumConsumption()+30);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->mQCustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->mQCustomPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->mQCustomPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->mQCustomPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible

    ui->mQCustomPlot->legend->setVisible(true);
    ui->mQCustomPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->mQCustomPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->mQCustomPlot->legend->setFont(legendFont);
    ui->mQCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

//-----------------------------------------------------------------------------

void GeneratorUI::realtimeDataSlot()
{
    static QTime timeStart = QTime::currentTime();
    double key = timeStart.msecsTo(QTime::currentTime())/1000.0; // time elapsed since start of demo, in seconds

    // add data to lines:
    ui->mQCustomPlot->graph(0)->addData(key, mGenerator->getMaximumConsumption());
    ui->mQCustomPlot->graph(1)->addData(key, mGenerator->getPowerCapacity());
    ui->mQCustomPlot->graph(2)->addData(key, mGenerator->getPowerConsumption());

    // make key axis range scroll with the data (at a constant range size of 5):
    ui->mQCustomPlot->xAxis->setRange(key, 5, Qt::AlignRight);

    std::stringstream str;
    str << "Total Fuel: " << mGenerator->getTotalFuel();
    ui->mTotalFuelLbl->setText(str.str().c_str());

    str.str("");
    str << "Fuel: " << Fuel::typeToStr(mGenerator->getCurrentFuelType());
    ui->mCurrentFuelLbl->setText(str.str().c_str());

    str.str("");
    QTime ttl(0, 0, mGenerator->getCurrentFuel()->mFuelValue * 1);
    str << "TTL: " << ttl.toString("mm:ss.zzz").toStdString();
    ui->mCurrentTTLLbl->setText(str.str().c_str());

    mGenerator->getCurrentFuel()->breakDown();
    if (mGenerator->getCurrentFuel()->mFuelValue <= 0)
    {
        mGenerator->consumeFuel();
    }

    //str.str("");
    //QTime tttl(0, 0, mGenerator->getCurrentFuel().mFuelValue * mGenerator->getTotalFuel() * 1 - key);
    //str << "Total TTL: " << tttl.toString("mm:ss.zzz").toStdString();
    //ui->mTotalTTLLbl->setText(str.str().c_str());

    ui->mQCustomPlot->replot();

}

//-----------------------------------------------------------------------------

GeneratorUI::~GeneratorUI()
{
    delete ui;
}
