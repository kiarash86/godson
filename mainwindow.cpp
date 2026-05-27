#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
this->setStyleSheet("QMainWindow { border-image: url(://C:/Users/kiarash/Downloads/backGround.png) 0 0 0 0 stretch stretch; }");
    // ۱. آدرس‌دهی درست کارت‌ها از داخل فایل ریسورس
        std::vector<std::pair<QString, QString>> myCards = {
            {"Big Taha", "://C:/Users/kiarash/Downloads/bigTaha.png"},
            {"Dr White", "://C:/Users/kiarash/Downloads/drWhite.png"},
            {"Dany Go", "://C:/Users/kiarash/Downloads/danyGo.png"},
            {"Little Taha", "://C:/Users/kiarash/Downloads/littleTaha.png"},
            {"Protector Amin", "://C:/Users/kiarash/Downloads/protectorAmin.png"}
        };

        QHBoxLayout* p1Layout = new QHBoxLayout();
        QHBoxLayout* p2Layout = new QHBoxLayout();

        for (const auto& card : myCards) {
            // --- ساخت کارت برای بازیکن ۱ ---
            QWidget* c1 = new QWidget();
            QVBoxLayout* l1 = new QVBoxLayout(c1);
            QCheckBox* cb1 = new QCheckBox(card.first);

            // نمایش عکس واقعی کارت برای بازیکن ۱
            QLabel* imgLabel1 = new QLabel();
            QPixmap pix1(card.second);
            if (!pix1.isNull()) {
                imgLabel1->setPixmap(pix1.scaled(360, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                imgLabel1->setText("[عکس یافت نشد]");



            }

            l1->addWidget(imgLabel1);
            l1->addWidget(cb1);
            p1Layout->addWidget(c1);
            player1CheckBoxes.push_back(cb1);

            connect(cb1, &QCheckBox::stateChanged, this, &MainWindow::updateCardSelectionLimits);

            // --- ساخت کارت برای بازیکن ۲ ---
            QWidget* c2 = new QWidget();
            QVBoxLayout* l2 = new QVBoxLayout(c2);
            QCheckBox* cb2 = new QCheckBox(card.first);

            // نمایش عکس واقعی کارت برای بازیکن ۲
            QLabel* imgLabel2 = new QLabel();
            QPixmap pix2(card.second);
            if (!pix2.isNull()) {
                imgLabel2->setPixmap(pix2.scaled(360, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                imgLabel2->setText("[عکس یافت نشد]");
            }

            l2->addWidget(imgLabel2);
            l2->addWidget(cb2);
            p2Layout->addWidget(c2);
            player2CheckBoxes.push_back(cb2);

            connect(cb2, &QCheckBox::stateChanged, this, &MainWindow::updateCardSelectionLimits);
        }

    if(ui->scrollArea1) ui->scrollArea1->setLayout(p1Layout);
    if(ui->scrollArea2) ui->scrollArea2->setLayout(p2Layout);
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::updateCardSelectionLimits()
{
    // ۱. مدیریت و شمارش کارت‌های بازیکن اول
    int p1Count = 0;
    for (QCheckBox* cb : player1CheckBoxes) {
        if (cb->isChecked()) p1Count++;
    }

    for (QCheckBox* cb : player1CheckBoxes) {
        // اگر ۳ کارت انتخاب شده و این چک‌باکس تیک ندارد، قفلش کن. در غیر این صورت باز بگذار.
        if (p1Count >= 3 && !cb->isChecked()) {
            cb->setEnabled(false);
        } else {
            cb->setEnabled(true);
        }
    }

    // ۲. مدیریت و شمارش کارت‌های بازیکن دوم
    int p2Count = 0;
    for (QCheckBox* cb : player2CheckBoxes) {
        if (cb->isChecked()) p2Count++;
    }

    for (QCheckBox* cb : player2CheckBoxes) {
        if (p2Count >= 3 && !cb->isChecked()) {
            cb->setEnabled(false);
        } else {
            cb->setEnabled(true);
        }
    }
}

void MainWindow::on_btnGoToGame_clicked()
{
    ui ->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnConfirmSelection_clicked()
{
    int p1Count = 0;
        int p2Count = 0;

        for (QCheckBox* cb : player1CheckBoxes) if (cb->isChecked()) p1Count++;
        for (QCheckBox* cb : player2CheckBoxes) if (cb->isChecked()) p2Count++;

        if (p1Count != 3 || p2Count != 3) {
            QMessageBox::warning(this, "خطا در انتخاب کارت",
                QString("هر دو بازیکن باید دقیقاً ۳ کارت انتخاب کنند!\nبازیکن اول: %1 کارت\nبازیکن دوم: %2 کارت")
                .arg(p1Count).arg(p2Count));
        } else {
            QMessageBox::information(this, "شروع بازی", "هر دو بازیکن کارت‌های خود را انتخاب کردند. وارد محیط بازی می‌شوید!");
            // ui->stackedWidget->setCurrentIndex(2); // رفتن به صفحه اصلی بازی
        }
}
