#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConfirmSelection_clicked();

    // این اسلات جدید وظیفه دارد هر زمان تیکی زده شد، محدودیت ۳ کارت را اعمال کند
    void updateCardSelectionLimits();

    void on_btnGoToGame_clicked();

private:
    Ui::MainWindow *ui;

    // دو وکتور جداگانه برای چک‌باکس‌های هر بازیکن
    std::vector<QCheckBox*> player1CheckBoxes;
    std::vector<QCheckBox*> player2CheckBoxes;
};

#endif // MAINWINDOW_H
