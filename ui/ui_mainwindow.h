#ifndef MAINWINDOWE10196_H
#define MAINWINDOWE10196_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_set_car_length;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_set_car_width;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_set_car_height;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_set_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_set_y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_set_z;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_set_roll;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_set_pitch;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_set_yaw;
    QPushButton *pushButton_load_adjust;
    QPushButton *pushButton_save_adjust;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(378, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 20, 351, 441));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 40, 335, 423));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        doubleSpinBox_set_car_length = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_car_length->setObjectName(QStringLiteral("doubleSpinBox_set_car_length"));
        doubleSpinBox_set_car_length->setMinimum(0);
        doubleSpinBox_set_car_length->setMaximum(50);
        doubleSpinBox_set_car_length->setSingleStep(0.1);
        doubleSpinBox_set_car_length->setValue(5);

        horizontalLayout_10->addWidget(doubleSpinBox_set_car_length);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        doubleSpinBox_set_car_width = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_car_width->setObjectName(QStringLiteral("doubleSpinBox_set_car_width"));
        doubleSpinBox_set_car_width->setMinimum(0);
        doubleSpinBox_set_car_width->setMaximum(10);
        doubleSpinBox_set_car_width->setSingleStep(0.1);
        doubleSpinBox_set_car_width->setValue(2);

        horizontalLayout_9->addWidget(doubleSpinBox_set_car_width);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        doubleSpinBox_set_car_height = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_car_height->setObjectName(QStringLiteral("doubleSpinBox_set_car_height"));
        doubleSpinBox_set_car_height->setMinimum(0);
        doubleSpinBox_set_car_height->setMaximum(5);
        doubleSpinBox_set_car_height->setSingleStep(0.1);
        doubleSpinBox_set_car_height->setValue(1.8);

        horizontalLayout_8->addWidget(doubleSpinBox_set_car_height);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        doubleSpinBox_set_x = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_x->setObjectName(QStringLiteral("doubleSpinBox_set_x"));
        doubleSpinBox_set_x->setMinimum(-5);
        doubleSpinBox_set_x->setMaximum(5);
        doubleSpinBox_set_x->setSingleStep(0.1);

        horizontalLayout->addWidget(doubleSpinBox_set_x);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_set_y = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_y->setObjectName(QStringLiteral("doubleSpinBox_set_y"));
        doubleSpinBox_set_y->setMinimum(-5);
        doubleSpinBox_set_y->setMaximum(5);
        doubleSpinBox_set_y->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_set_y);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        doubleSpinBox_set_z = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_z->setObjectName(QStringLiteral("doubleSpinBox_set_z"));
        doubleSpinBox_set_z->setMinimum(-5);
        doubleSpinBox_set_z->setMaximum(5);
        doubleSpinBox_set_z->setSingleStep(0.1);
        doubleSpinBox_set_z->setValue(2);

        horizontalLayout_3->addWidget(doubleSpinBox_set_z);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        doubleSpinBox_set_roll = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_roll->setObjectName(QStringLiteral("doubleSpinBox_set_roll"));
        doubleSpinBox_set_roll->setMinimum(-180);
        doubleSpinBox_set_roll->setMaximum(180);
        doubleSpinBox_set_roll->setSingleStep(0.5);
        doubleSpinBox_set_roll->setDecimals(1);

        horizontalLayout_4->addWidget(doubleSpinBox_set_roll);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        doubleSpinBox_set_pitch = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_pitch->setObjectName(QStringLiteral("doubleSpinBox_set_pitch"));
        doubleSpinBox_set_pitch->setMinimum(-180);
        doubleSpinBox_set_pitch->setMaximum(180);
        doubleSpinBox_set_pitch->setSingleStep(0.5);
        doubleSpinBox_set_pitch->setDecimals(1);

        horizontalLayout_5->addWidget(doubleSpinBox_set_pitch);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        doubleSpinBox_set_yaw = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_set_yaw->setObjectName(QStringLiteral("doubleSpinBox_set_yaw"));
        doubleSpinBox_set_yaw->setMinimum(-180);
        doubleSpinBox_set_yaw->setMaximum(180);
        doubleSpinBox_set_yaw->setSingleStep(0.5);
        doubleSpinBox_set_yaw->setDecimals(1);

        horizontalLayout_6->addWidget(doubleSpinBox_set_yaw);


        verticalLayout_3->addLayout(horizontalLayout_6);

        pushButton_load_adjust = new QPushButton(verticalLayoutWidget_3);
        pushButton_load_adjust->setObjectName(QStringLiteral("pushButton_load_adjust"));

        verticalLayout_3->addWidget(pushButton_load_adjust);

        pushButton_save_adjust = new QPushButton(verticalLayoutWidget_3);
        pushButton_save_adjust->setObjectName(QStringLiteral("pushButton_save_adjust"));

        verticalLayout_3->addWidget(pushButton_save_adjust);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 378, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lidar Mounting Calibration Tool", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "", 0));
        label_10->setText(QApplication::translate("MainWindow", "set vehicle length (m):", 0));
        label_9->setText(QApplication::translate("MainWindow", "set vehicle width (m):", 0));
        label_8->setText(QApplication::translate("MainWindow", "set vehicle height (m):", 0));
        label_2->setText(QApplication::translate("MainWindow", "set trans_X (m):", 0));
        label_3->setText(QApplication::translate("MainWindow", "set trans_Y (m):", 0));
        label_4->setText(QApplication::translate("MainWindow", "set trans_Z (m):", 0));
        label_5->setText(QApplication::translate("MainWindow", "set Rotation Roll (°):", 0));
        label_6->setText(QApplication::translate("MainWindow", "set Rotation Pitch (°):", 0));
        label_7->setText(QApplication::translate("MainWindow", "set Rotation Yaw (°):", 0));
        pushButton_load_adjust->setText(QApplication::translate("MainWindow", "load", 0));
        pushButton_save_adjust->setText(QApplication::translate("MainWindow", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWE10196_H
