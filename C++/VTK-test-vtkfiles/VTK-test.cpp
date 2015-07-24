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

///_________________________________________________///
///The best result are with model1.vtk and model2.vtk ///
///________________________________________________///

int main(int argc, char *argv[])
{

    ///check of the number of informations given
    /// ---------------------------------------------------------

    if (argc != 3)
    {
        std::cout<< "Usage: "<<argv[0]<<" InputFileNAme1 InputFileNAme2"<<std::endl;
        exit(-1);
    }

    ///first try with spheres
    ///

    //    vtkSmartPointer<vtkSphereSource> reader1 = vtkSmartPointer<vtkSphereSource>::New();
    //    reader1->SetCenter(0.0, 0.0, 0.0);
    //    reader1->SetRadius(3.0f);
    //    reader1->SetThetaResolution(25);
    //    reader1->SetPhiResolution(25);
    //    reader1->Update();

    //    vtkSmartPointer<vtkSphereSource> reader2 = vtkSmartPointer<vtkSphereSource>::New();
    //    reader2->SetCenter(0.0, 0.0, 0.0);
    //    reader2->SetRadius(18.0f);
    //    reader2->SetThetaResolution(50);
    //    reader2->SetPhiResolution(50);
    //    reader2->Update();

    ///Opening of the files
    /// -------------------------

    std::string inputFilename1 = argv[1];

    vtkSmartPointer<vtkGenericDataObjectReader> reader1 =vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader1->SetFileName(inputFilename1.c_str());
    reader1->Update();

    std::string inputFilename2 = argv[2];

    vtkSmartPointer<vtkGenericDataObjectReader> reader2 =vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader2->SetFileName(inputFilename2.c_str());
    reader2->Update();


    vtkSmartPointer<vtkPolyDataMapper> mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper1->SetInputConnection(reader1->GetOutputPort());
    mapper1->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> actor1 = vtkSmartPointer<vtkActor>::New();
    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetOpacity(.3);
    actor1->GetProperty()->SetColor(0,0,1);


    vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper2->SetInputConnection( reader2->GetOutputPort() );
    mapper2->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> actor2 = vtkSmartPointer<vtkActor>::New();
    actor2->SetMapper( mapper2 );
    actor2->GetProperty()->SetOpacity(.3);
    actor2->GetProperty()->SetColor(1,0,0);

    ///application of a filters
    /// ------------------------------

    //filter1:  intersection
    vtkSmartPointer<vtkIntersectionPolyDataFilter> intersectionPolyDataFilter = vtkSmartPointer<vtkIntersectionPolyDataFilter>::New();
    intersectionPolyDataFilter->SetInputConnection( 0, reader1->GetOutputPort() );
    intersectionPolyDataFilter->SetInputConnection( 1, reader2->GetOutputPort() );
    intersectionPolyDataFilter->Update();

    vtkSmartPointer<vtkPolyDataMapper> intersectionMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    intersectionMapper->SetInputConnection( intersectionPolyDataFilter->GetOutputPort() );
    intersectionMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> intersectionActor = vtkSmartPointer<vtkActor>::New();
    intersectionActor->SetMapper( intersectionMapper );

    //filter2: boolean operations
    vtkSmartPointer<vtkBooleanOperationPolyDataFilter> booleanOperation = vtkSmartPointer<vtkBooleanOperationPolyDataFilter>::New();
    //booleanOperation->SetOperationToUnion();
    booleanOperation->SetOperationToIntersection();
    //booleanOperation->SetOperationToDifference();
    booleanOperation->SetInputConnection( 0, reader1->GetOutputPort()  );
    booleanOperation->SetInputConnection( 1, reader2->GetOutputPort() );
    vtkSmartPointer<vtkPolyDataMapper> booleanOperationMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    booleanOperationMapper->SetInputConnection( booleanOperation->GetOutputPort() );
    booleanOperationMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> booleanOperationActor = vtkSmartPointer<vtkActor>::New();
    booleanOperationActor->SetMapper( booleanOperationMapper );

    ///displaying of the image
    /// -------------------------------

    vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
    vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren);
    vtkSmartPointer<vtkRenderWindowInteractor> renWinInt = vtkRenderWindowInteractor::New();
    renWinInt->SetRenderWindow(renWin);

    ren->AddViewProp(actor1);
    ren->AddViewProp(actor2);
    ren->AddViewProp(intersectionActor);
    ren->AddViewProp(booleanOperationActor);
    ren->SetBackground(0.2, 0.1, 0.4);
    renWin->SetSize(400, 400);

    //ren->ResetCamera();
    renWin->Render();

    renWinInt->Start();
    
    return 0;
}
