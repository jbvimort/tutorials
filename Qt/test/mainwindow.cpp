#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connections
    connect(ui->load1, SIGNAL(clicked()), this, SLOT(SelectInputFigure1()));
    connect(ui->load2, SIGNAL(clicked()), this, SLOT(SelectInputFigure2(int)));
    connect(ui->aplication, SIGNAL(clicked()), this, SLOT(Run()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Slots
void MainWindow::SelectInputFigure1()
{
    inputFilename1 = ui->input1->text().toStdString();

    ren->RemoveActor(actor1);

    reader1->SetFileName(inputFilename1.c_str());
    reader1->Update();

    mapper1->SetInputConnection(reader1->GetOutputPort());
    mapper1->ScalarVisibilityOff();

    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetOpacity(.3);
    actor1->GetProperty()->SetColor(0,0,1);

//    QVTKWidget *inputWidget = new QVTKWidget(ui->inputDisplay);

//    ren->AddActor(actor1);
//    ren->SetBackground(0.2, 0.1, 0.4);

//    renWin=inputWidget->GetRenderWindow();
//    renWin->AddRenderer(ren);
//    renWin->SetSize(400, 400);

//    renWinInt=inputWidget->GetInteractor();
//    renWinInt->SetRenderWindow(renWin);

//    renWin->Render();
//    renWinInt->Start();
}

void MainWindow::SelectInputFigure2()
{
    inputFilename2 = ui->input2->text().toStdString();

    ren->RemoveActor(actor2);

    reader2->SetFileName(inputFilename2.c_str());
    reader2->Update();

    mapper2->SetInputConnection(reader2->GetOutputPort());
    mapper2->ScalarVisibilityOff();

    actor2->SetMapper(mapper2);
    actor2->GetProperty()->SetOpacity(.3);
    actor2->GetProperty()->SetColor(0,1,0);

//    QVTKWidget *inputWidget = new QVTKWidget(ui->inputDisplay);

//    ren->AddActor(actor2);
//    ren->SetBackground(0.2, 0.1, 0.4);

//    renWin=inputWidget->GetRenderWindow();
//    renWin->AddRenderer(ren);
//    renWin->SetSize(400, 400);

//    renWinInt=inputWidget->GetInteractor();
//    renWinInt->SetRenderWindow(renWin);

//    renWin->Render();
//    renWinInt->Start();
}

void MainWindow::run()
{

}

