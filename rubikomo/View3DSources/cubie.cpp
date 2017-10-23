#include "./View3DHeaders/cubie.h"


Cubie::Cubie(Qt3DCore::QEntity *rootEntity,bool isCorner)
{
    m_cuboid=new Cuboid(rootEntity,isCorner);
}

void Cubie::startXAxisClockAnim()
{
    m_cuboid->animHandler()->startXAxisClockAnim();
}

void Cubie::startXAxisCClockAnim()
{
    m_cuboid->animHandler()->startXAxisCClockAnim();
}

void Cubie::startYAxisClockAnim()
{
    m_cuboid->animHandler()->startYAxisClockAnim();
}

void Cubie::startYAxisCClockAnim()
{
    m_cuboid->animHandler()->startYAxisCClockAnim();
}

void Cubie::startZAxisClockAnim()
{
    m_cuboid->animHandler()->startZAxisClockAnim();
}

void Cubie::startZAxisCClockAnim()
{
    m_cuboid->animHandler()->startZAxisCClockAnim();
}

Qt3DCore::QEntity *Cubie::entity()
{
    return m_cuboid->entity();
}

Qt3DCore::QTransform *Cubie::transf()
{
    return m_cuboid->shapeTransform();
}

Cuboid *Cubie::cuboid() const
{
    return m_cuboid;
}
