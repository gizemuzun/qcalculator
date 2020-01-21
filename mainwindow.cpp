#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

double first_Numb;
bool userIsTypingSecondNumber = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pb0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb9,SIGNAL(released()),this,SLOT(digit_pressed()));

    //Rakamlar hariç tüm tuşların sinyal kodları:

    connect(ui->pbMinusPlus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pbPercent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    //4 İşlem için yazılan kodlar toplamı:

    connect(ui->pbAdd, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbSubtract, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbMultiplay, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbDivide, SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pbAdd->setCheckable(true);
    ui->pbSubtract->setCheckable(true);
    ui->pbMultiplay->setCheckable(true);
    ui->pbDivide->setCheckable(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()

//BASILAN RAKAM

{
    QPushButton * button = static_cast<QPushButton*>(sender());

    double labelNumber;
    QString newLabel;
    if(ui->pbAdd->isChecked()|| ui->pbSubtract->isChecked()
        || ui->pbMultiplay->isChecked() || ui->pbDivide->isChecked() && (!userIsTypingSecondNumber))
    {

        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);


    }
    else
    {
        //if(ui->label->text().contains("."))

        labelNumber = (ui->label->text() + button->text()).toDouble();
    }

    //labelNumber = (ui->label->text() + button->text()).toDouble();



    //Text Label'de yazan hassasiyet miktarı: 15 olarak belirlendi.'g' =f (15)

    newLabel = QString::number(labelNumber,'g',15);


    ui->label->setText(newLabel);

//    ui->label->setText(ui->label->text() + button->text());
//    if(button ==  ui->pb0){
//        qDebug() << "buraya geldi

//    }

}

//.(Decimal) Tuşu özelliklerinin atanması kısımı:


void MainWindow::on_pbDecimal_released()
{
    ui->label->setText(ui->label->text() + ".");

}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = static_cast<QPushButton*>(sender());
    double labelNumber;
    QString newLabel;


    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();

        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);

    }

    if(button->text() == "%")

    {

        labelNumber = ui->label->text().toDouble();

        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pbClear_released()

{
    ui->pbAdd->setChecked(false);
     ui->pbSubtract->setChecked(false);
      ui->pbMultiplay->setChecked(false);
       ui->pbDivide->setChecked(false);

       userIsTypingSecondNumber = false;

       ui->label->setText("0");

}

//4 İşlem için gerekli olan kodlar "Equals" tuşunun altına yazılır!

void MainWindow::on_pbEquals_released()

{
    double labelNumber;
    double secondNumber;

    QString newLabel;
    secondNumber = ui->label->text().toDouble();

// true-false : Döngü- kontrol edip öyle işlem yapıyor


    //Toplama işlemi için: [Add tuşuna basıldığında olacaklar]
    if(ui->pbAdd->isChecked())
    {
        labelNumber = first_Numb + secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pbAdd->setChecked(false);
    }
    //Çıkartma işlemi için: [Substract tuşuna basıldığında olacaklar]
    else if (ui->pbSubtract->isChecked())
    {
        labelNumber = first_Numb - secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pbSubtract->setChecked(false);
    }
    //Çarpma işlemi için: [Multiplay tuşuna basıldığı zaman olacaklar]
    else if (ui->pbMultiplay->isChecked())
    {
        labelNumber = first_Numb * secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pbMultiplay->setChecked(false);

    }
    //Bölme işlemi için: [Divide tuşuna basıldığı zaman olacaklar]
    else if (ui->pbDivide->isChecked())
    {

        labelNumber = first_Numb / secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pbDivide->setChecked(false);

    }

    userIsTypingSecondNumber = false;


}

void MainWindow::binary_operation_pressed()
{
   QPushButton * button = static_cast<QPushButton*>(sender());
    first_Numb = ui->label->text().toDouble();
     button->setChecked(true);

}
