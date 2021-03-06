/********************************************************************************
** Form generated from reading UI file 'dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_H
#define UI_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CMATDlg
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QPushButton *optionsPushButton;
    QPushButton *volumePushButton;
    QPushButton *surfacePushButton;
    QPushButton *shorelinePushButton;
    QPushButton *extractProfilePushButton;
    QDialogButtonBox *cancelButton;

    void setupUi(QDialog *CMATDlg)
    {
        if (CMATDlg->objectName().isEmpty())
            CMATDlg->setObjectName(QStringLiteral("CMATDlg"));
        CMATDlg->resize(118, 490);
        CMATDlg->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(CMATDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(CMATDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        optionsPushButton = new QPushButton(frame);
        optionsPushButton->setObjectName(QStringLiteral("optionsPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(optionsPushButton->sizePolicy().hasHeightForWidth());
        optionsPushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(optionsPushButton);

        volumePushButton = new QPushButton(frame);
        volumePushButton->setObjectName(QStringLiteral("volumePushButton"));
        sizePolicy.setHeightForWidth(volumePushButton->sizePolicy().hasHeightForWidth());
        volumePushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(volumePushButton);

        surfacePushButton = new QPushButton(frame);
        surfacePushButton->setObjectName(QStringLiteral("surfacePushButton"));
        sizePolicy.setHeightForWidth(surfacePushButton->sizePolicy().hasHeightForWidth());
        surfacePushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(surfacePushButton);

        shorelinePushButton = new QPushButton(frame);
        shorelinePushButton->setObjectName(QStringLiteral("shorelinePushButton"));
        sizePolicy.setHeightForWidth(shorelinePushButton->sizePolicy().hasHeightForWidth());
        shorelinePushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(shorelinePushButton);

        extractProfilePushButton = new QPushButton(frame);
        extractProfilePushButton->setObjectName(QStringLiteral("extractProfilePushButton"));
        sizePolicy.setHeightForWidth(extractProfilePushButton->sizePolicy().hasHeightForWidth());
        extractProfilePushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(extractProfilePushButton);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        cancelButton = new QDialogButtonBox(CMATDlg);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStandardButtons(QDialogButtonBox::Cancel);

        gridLayout->addWidget(cancelButton, 1, 0, 1, 1);


        retranslateUi(CMATDlg);

        QMetaObject::connectSlotsByName(CMATDlg);
    } // setupUi

    void retranslateUi(QDialog *CMATDlg)
    {
        CMATDlg->setWindowTitle(QApplication::translate("CMATDlg", "qCMAT", nullptr));
#ifndef QT_NO_TOOLTIP
        optionsPushButton->setToolTip(QApplication::translate("CMATDlg", "Set options/parameters or perform pre-processing.", nullptr));
#endif // QT_NO_TOOLTIP
        optionsPushButton->setText(QApplication::translate("CMATDlg", "Options", nullptr));
#ifndef QT_NO_TOOLTIP
        volumePushButton->setToolTip(QApplication::translate("CMATDlg", "Calculate beach volume", nullptr));
#endif // QT_NO_TOOLTIP
        volumePushButton->setText(QApplication::translate("CMATDlg", "Volume", nullptr));
#ifndef QT_NO_TOOLTIP
        surfacePushButton->setToolTip(QApplication::translate("CMATDlg", "Calculate beach volume", nullptr));
#endif // QT_NO_TOOLTIP
        surfacePushButton->setText(QApplication::translate("CMATDlg", "Surface", nullptr));
#ifndef QT_NO_TOOLTIP
        shorelinePushButton->setToolTip(QApplication::translate("CMATDlg", "Calculate beach volume", nullptr));
#endif // QT_NO_TOOLTIP
        shorelinePushButton->setText(QApplication::translate("CMATDlg", "Shoreline", nullptr));
#ifndef QT_NO_TOOLTIP
        extractProfilePushButton->setToolTip(QApplication::translate("CMATDlg", "Calculate beach volume", nullptr));
#endif // QT_NO_TOOLTIP
        extractProfilePushButton->setText(QApplication::translate("CMATDlg", "Profiles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMATDlg: public Ui_CMATDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_H
