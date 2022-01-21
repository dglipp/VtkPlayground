#include <iostream>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

int main()
{
    vtkCylinderSource * cylinder = vtkCylinderSource::New();

    vtkPolyDataMapper * cylinderMapper = vtkPolyDataMapper::New();
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    vtkActor * cylinderActor = vtkActor::New();
    cylinderActor->SetMapper(cylinderMapper);

    vtkRenderer * ren1 = vtkRenderer::New();
    ren1->AddActor(cylinderActor);

    vtkRenderWindow * renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren1);

    vtkRenderWindowInteractor * iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    renWin->Render();
    iren->Start();
}
