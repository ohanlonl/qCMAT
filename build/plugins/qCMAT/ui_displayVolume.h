/********************************************************************************
** Form generated from reading UI file 'displayVolume.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYVOLUME_H
#define UI_DISPLAYVOLUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_displayVolume
{
public:
    QFrame *frame;
    QLabel *title;
    QTextEdit *Text;
    QPushButton *Close;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(500, 431);
        frame = new QFrame(Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 481, 411));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        title = new QLabel(frame);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(10, 10, 461, 20));
        title->setAlignment(Qt::AlignCenter);
        Text = new QTextEdit(frame);
        Text->setObjectName(QStringLiteral("Text"));
        Text->setGeometry(QRect(10, 40, 461, 361));
        Close = new QPushButton(frame);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setGeometry(QRect(380, 10, 80, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("displayVolume", "Dialog", nullptr));
        title->setText(QApplication::translate("displayVolume", "Format: Bottom  -  Top  -  Volume ", nullptr));
        Close->setText(QApplication::translate("displayVolume", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displayVolume: public Ui_displayVolume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYVOLUME_H
