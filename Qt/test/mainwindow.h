#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QVTKWidget.h"
#include "QFileInfo"

#include "vtkGenericDataObjectReader.h"
#include "vtkStructuredGrid.h"
#include "vtkSmartPointer.h"
#include "vtkPolyData.h"
#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include <vtkIntersectionPolyDataFilter.h>
#include <vtkProperty.h>
#include <vtkSphereSource.h>
#include <vtkBooleanOperationPolyDataFilter.h>

#include <iostream>
#include <string>

#include <vtkVersion.h>
#include <vtkBooleanOperationPolyDataFilter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

public slots:
    void SelectInputFigure1();
    void SelectInputFigure2();
    void Run();

private:
    Ui::MainWindow *ui;

    //input 1
    std::string inputFilename1;
    vtkSmartPointer<vtkGenericDataObjectReader> reader1 =vtkSmartPointer<vtkGenericDataObjectReader>::New();
    vtkSmartPointer<vtkPolyDataMapper> mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkActor> actor1 = vtkSmartPointer<vtkActor>::New();

    //input2
    std::string inputFilename2;
    vtkSmartPointer<vtkGenericDataObjectReader> reader2 =vtkSmartPointer<vtkGenericDataObjectReader>::New();
    vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkActor> actor2 = vtkSmartPointer<vtkActor>::New();

};

#endif // MAINWINDOW_H
