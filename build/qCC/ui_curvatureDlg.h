/********************************************************************************
** Form generated from reading UI file 'curvatureDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVATUREDLG_H
#define UI_CURVATUREDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CurvatureDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label_2;
    QComboBox *curvatureTypeComboBox;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QDoubleSpinBox *kernelDoubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CurvatureDialog)
    {
        if (CurvatureDialog->objectName().isEmpty())
            CurvatureDialog->setObjectName(QStringLiteral("CurvatureDialog"));
        CurvatureDialog->resize(300, 109);
        vboxLayout = new QVBoxLayout(CurvatureDialog);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label_2 = new QLabel(CurvatureDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        hboxLayout->addWidget(label_2);

        curvatureTypeComboBox = new QComboBox(CurvatureDialog);
        curvatureTypeComboBox->addItem(QString());
        curvatureTypeComboBox->addItem(QString());
        curvatureTypeComboBox->addItem(QString());
        curvatureTypeComboBox->setObjectName(QStringLiteral("curvatureTypeComboBox"));

        hboxLayout->addWidget(curvatureTypeComboBox);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        label = new QLabel(CurvatureDialog);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout1->addWidget(label);

        kernelDoubleSpinBox = new QDoubleSpinBox(CurvatureDialog);
        kernelDoubleSpinBox->setObjectName(QStringLiteral("kernelDoubleSpinBox"));
        kernelDoubleSpinBox->setDecimals(6);
        kernelDoubleSpinBox->setMaximum(1e+9);
        kernelDoubleSpinBox->setValue(1);

        hboxLayout1->addWidget(kernelDoubleSpinBox);


        vboxLayout->addLayout(hboxLayout1);

        buttonBox = new QDialogButtonBox(CurvatureDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(CurvatureDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CurvatureDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CurvatureDialog, SLOT(reject()));

        curvatureTypeComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CurvatureDialog);
    } // setupUi

    void retranslateUi(QDialog *CurvatureDialog)
    {
        CurvatureDialog->setWindowTitle(QApplication::translate("CurvatureDialog", "Curvature", nullptr));
        label_2->setText(QApplication::translate("CurvatureDialog", "Curvature", nullptr));
        curvatureTypeComboBox->setItemText(0, QApplication::translate("CurvatureDialog", "Gaussian", nullptr));
        curvatureTypeComboBox->setItemText(1, QApplication::translate("CurvatureDialog", "Mean", nullptr));
        curvatureTypeComboBox->setItemText(2, QApplication::translate("CurvatureDialog", "Normal change rate", nullptr));

        label->setText(QApplication::translate("CurvatureDialog", "kernel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurvatureDialog: public Ui_CurvatureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVATUREDLG_H
