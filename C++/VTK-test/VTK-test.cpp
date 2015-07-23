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

#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    ///check of the number of informations given
    /// ---------------------------------------------------------

    if (argc != 2)
    {
        std::cout<< "Usage: "<<argv[0]<<" InputFileNAme"<<std::endl;
        exit(-1);
    }

    ///Opening of the file
    /// ------------------------

    // Get the filename from the command line
    std::string inputFilename = argv[1];

    // Get all data from the file
    vtkSmartPointer<vtkGenericDataObjectReader> reader =vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader->SetFileName(inputFilename.c_str());
    reader->Update();

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());
    mapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetOpacity(.3);
    actor->GetProperty()->SetColor(0,1,0);

    ///creation of a sphere
    /// --------------------------
    vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetCenter(0.0, -5.0, 10.0);
    sphereSource->SetRadius(5.0f);
    sphereSource->Update();

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );
    sphereMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper( sphereMapper );
    sphereActor->GetProperty()->SetOpacity(.3);
    sphereActor->GetProperty()->SetColor(1,0,0);

    ///application of a filter
    /// ----------------------------

    vtkSmartPointer<vtkIntersectionPolyDataFilter> intersectionPolyDataFilter = vtkSmartPointer<vtkIntersectionPolyDataFilter>::New();
    intersectionPolyDataFilter->SetInputConnection( 0, sphereSource->GetOutputPort() );
    intersectionPolyDataFilter->SetInputConnection( 1, reader->GetOutputPort() );
    intersectionPolyDataFilter->Update();

    vtkSmartPointer<vtkPolyDataMapper> intersectionMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    intersectionMapper->SetInputConnection( intersectionPolyDataFilter->GetOutputPort() );
    intersectionMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> intersectionActor = vtkSmartPointer<vtkActor>::New();
    intersectionActor->SetMapper( intersectionMapper );

    ///displaying of the image
    /// -------------------------------

    vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
    vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren);
    vtkSmartPointer<vtkRenderWindowInteractor> renWinInt = vtkRenderWindowInteractor::New();
    renWinInt->SetRenderWindow(renWin);

    //ren->AddActor(actor);
    //ren->AddActor(sphereActor);
    ren->AddActor(intersectionActor);
    ren->SetBackground(0.2, 0.1, 0.4);
    renWin->SetSize(400, 400);

    ren->ResetCamera();
    renWin->Render();

    renWinInt->Start();
    
    return 0;
}
