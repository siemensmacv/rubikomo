#include "./View3DHeaders/plane.h"

Plane::Plane()
{

}

void Plane::setPlaneMesh(Qt3DExtras::QPlaneMesh *planeMesh)
{
    m_planeMesh = planeMesh;
}
