#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include <vtkGenericDataObjectReader.h>
#include <vtkStructuredGrid.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkActor.h>

#include <vtkNrrdReader.h>

#include <iostream>
#include <string>



int main(int argc, char *argv[])
{

    ///check of the number of informations given
    /// ---------------------------------------------------------

    if (argc != 2)
    {
        std::cout<< "Usage: "<<argv[0]<<" InputFileNAme1"<<std::endl;
        exit(-1);
    }

    ///Opening of the files
    /// -------------------------

    std::string inputFilename1 = argv[1];

    std::cout<<"0"<<std::endl;
    vtkSmartPointer<vtkNrrdReader> reader1 =vtkSmartPointer<vtkNrrdReader>::New();
std::cout<<"0"<<std::endl;
    reader1->SetFileName(inputFilename1.c_str());
    std::cout<<"0"<<std::endl;
    reader1->Update();

    std::cout<<"1"<<std::endl;
    vtkSmartPointer<vtkPolyDataMapper> mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper1->SetInputConnection(reader1->GetOutputPort());
    mapper1->ScalarVisibilityOff();

    std::cout<<"2"<<std::endl;
    vtkSmartPointer<vtkActor> actor1 = vtkSmartPointer<vtkActor>::New();
    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetOpacity(.3);
    actor1->GetProperty()->SetColor(0,0,1);

    std::cout<<"3"<<std::endl;


    ///displaying of the image
    /// -------------------------------

    vtkSmartPointer<vtkRenderer> ren = vtkRenderer::New();
    vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren);
    vtkSmartPointer<vtkRenderWindowInteractor> renWinInt = vtkRenderWindowInteractor::New();
    renWinInt->SetRenderWindow(renWin);

    std::cout<<"4"<<std::endl;
    ren->AddViewProp(actor1);
    ren->SetBackground(0.2, 0.1, 0.4);
    renWin->SetSize(400, 400);

    //ren->ResetCamera();
    renWin->Render();

    renWinInt->Start();

    return 0;
}
