#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connections
    connect(ui->load1, SIGNAL(clicked()), this, SLOT(SelectInputFigure1()));
    connect(ui->load2, SIGNAL(clicked()), this, SLOT(SelectInputFigure2()));
    connect(ui->aplication, SIGNAL(clicked()), this, SLOT(Run()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Slots
void MainWindow::SelectInputFigure1()
{


    QString suffix = QFileInfo(ui->input1->text()).suffix();
    inputFilename1 = ui->input1->text().toStdString();

    if(suffix=="vtk")
    {
        //reader1->SetFileName("model1.vtk");
        reader1->SetFileName(inputFilename1.c_str());
        reader1->Update();

        mapper1->SetInputConnection(reader1->GetOutputPort());
        mapper1->ScalarVisibilityOff();

        actor1->SetMapper(mapper1);
        actor1->GetProperty()->SetOpacity(.3);
        actor1->GetProperty()->SetColor(0,0,1);

        QVTKWidget *inputWidget = new QVTKWidget(ui->inputDisplay);
        vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
        vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();

        renWin->AddRenderer(ren);

        ren->AddActor(actor2);
        ren->AddActor(actor1);
        ren->SetBackground(1.0, 1.0, 1.0);

        ren->ResetCamera();

        inputWidget->SetRenderWindow(renWin);
        inputWidget->resize(301,251);

        inputWidget->show();


    }
    else
    {
        std::cout<<"Les fichiers requis doivent posseder l'extension .vtk"<<std::endl;
    }

}

void MainWindow::SelectInputFigure2()
{


    inputFilename2 = ui->input2->text().toStdString();
    QString suffix = QFileInfo(ui->input2->text()).suffix();

    if(suffix=="vtk")
    {

        //reader2->SetFileName("model2.vtk");
        reader2->SetFileName(inputFilename2.c_str());
        reader2->Update();

        mapper2->SetInputConnection(reader2->GetOutputPort());
        //mapper2->ScalarVisibilityOff();

        actor2->SetMapper(mapper2);
        actor2->GetProperty()->SetOpacity(.3);
        actor2->GetProperty()->SetColor(1,0,0);

        QVTKWidget *inputWidget = new QVTKWidget(ui->inputDisplay);
        vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
        vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();

        renWin->AddRenderer(ren);

        ren->AddActor(actor2);
        ren->AddActor(actor1);
        ren->SetBackground(1.0, 1.0, 1.0);

        ren->ResetCamera();

        inputWidget->SetRenderWindow(renWin);
        inputWidget->resize(301,251);

        inputWidget->show();

    }
    else
    {
        std::cout<<"Les fichiers requis doivent posseder l'extension .vtk"<<std::endl;
    }

}

void MainWindow::Run()
{

    vtkSmartPointer<vtkBooleanOperationPolyDataFilter> booleanOperation = vtkSmartPointer<vtkBooleanOperationPolyDataFilter>::New();
    if(ui->diff->isChecked())
    {
        booleanOperation->SetOperationToDifference();
    }
    if(ui->unio->isChecked())
    {
        booleanOperation->SetOperationToUnion();
    }
    if(ui->inter->isChecked())
    {
        booleanOperation->SetOperationToIntersection();
    }
    booleanOperation->SetInputConnection( 0, reader1->GetOutputPort()  );
    booleanOperation->SetInputConnection( 1, reader2->GetOutputPort() );
    vtkSmartPointer<vtkPolyDataMapper> booleanOperationMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    booleanOperationMapper->SetInputConnection( booleanOperation->GetOutputPort() );
    booleanOperationMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> booleanOperationActor = vtkSmartPointer<vtkActor>::New();
    booleanOperationActor->SetMapper( booleanOperationMapper );

    QVTKWidget *inputWidget = new QVTKWidget(ui->outputDisplay);
    vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
    vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();

    renWin->AddRenderer(ren);

    ren->AddActor(booleanOperationActor);
    ren->SetBackground(1.0, 1.0, 1.0);

    ren->ResetCamera();

    inputWidget->SetRenderWindow(renWin);
    inputWidget->resize(301,251);

    inputWidget->show();
}


