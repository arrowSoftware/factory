/********************************************************************************
** Form generated from reading UI file 'GeneratorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATORUI_H
#define UI_GENERATORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GeneratorUI
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mVerticalLayout;
    QCustomPlot *mQCustomPlot;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *mCurrentFuelLbl;
    QLabel *mCurrentTTLLbl;
    QLabel *mTotalFuelLbl;
    QLabel *mTotalTTLLbl;

    void setupUi(QWidget *GeneratorUI)
    {
        if (GeneratorUI->objectName().isEmpty())
            GeneratorUI->setObjectName(QString::fromUtf8("GeneratorUI"));
        GeneratorUI->resize(400, 350);
        verticalLayoutWidget = new QWidget(GeneratorUI);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        mVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        mVerticalLayout->setObjectName(QString::fromUtf8("mVerticalLayout"));
        mVerticalLayout->setContentsMargins(0, 0, 0, 0);
        mQCustomPlot = new QCustomPlot(verticalLayoutWidget);
        mQCustomPlot->setObjectName(QString::fromUtf8("mQCustomPlot"));

        mVerticalLayout->addWidget(mQCustomPlot);

        horizontalLayoutWidget = new QWidget(GeneratorUI);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 299, 401, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mCurrentFuelLbl = new QLabel(horizontalLayoutWidget);
        mCurrentFuelLbl->setObjectName(QString::fromUtf8("mCurrentFuelLbl"));

        horizontalLayout->addWidget(mCurrentFuelLbl);

        mCurrentTTLLbl = new QLabel(horizontalLayoutWidget);
        mCurrentTTLLbl->setObjectName(QString::fromUtf8("mCurrentTTLLbl"));

        horizontalLayout->addWidget(mCurrentTTLLbl);

        mTotalFuelLbl = new QLabel(horizontalLayoutWidget);
        mTotalFuelLbl->setObjectName(QString::fromUtf8("mTotalFuelLbl"));

        horizontalLayout->addWidget(mTotalFuelLbl);

        mTotalTTLLbl = new QLabel(horizontalLayoutWidget);
        mTotalTTLLbl->setObjectName(QString::fromUtf8("mTotalTTLLbl"));

        horizontalLayout->addWidget(mTotalTTLLbl);


        retranslateUi(GeneratorUI);

        QMetaObject::connectSlotsByName(GeneratorUI);
    } // setupUi

    void retranslateUi(QWidget *GeneratorUI)
    {
        GeneratorUI->setWindowTitle(QCoreApplication::translate("GeneratorUI", "Form", nullptr));
        mCurrentFuelLbl->setText(QCoreApplication::translate("GeneratorUI", "TextLabel", nullptr));
        mCurrentTTLLbl->setText(QCoreApplication::translate("GeneratorUI", "TextLabel", nullptr));
        mTotalFuelLbl->setText(QCoreApplication::translate("GeneratorUI", "TextLabel", nullptr));
        mTotalTTLLbl->setText(QCoreApplication::translate("GeneratorUI", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneratorUI: public Ui_GeneratorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATORUI_H
