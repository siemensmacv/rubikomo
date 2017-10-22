#include "./View3DHeaders/orbittransformcontroller.h"

OrbitTransformController::OrbitTransformController(QObject *parent, bool isCorner)
    : QObject(parent)
    , m_target(nullptr)
    , m_radius(1.0f)
    , m_angle(0.0f)
    , m_angleDifference(0.0f)
    , m_isCorner(isCorner)
{
}

void OrbitTransformController::setTarget(Qt3DCore::QTransform *target)
{
    if (m_target != target) {
        m_target = target;
        emit targetChanged();
    }
}

Qt3DCore::QTransform *OrbitTransformController::target() const
{
    return m_target;
}

void OrbitTransformController::setRadius(float radius)
{
    if (!qFuzzyCompare(radius, m_radius)) {
        m_radius = radius;
        emit radiusChanged();
    }
}

float OrbitTransformController::radius() const
{
    return m_radius;
}

void OrbitTransformController::setAngle(float angle)
{
    if (!qFuzzyCompare(angle, m_angle)) {
        m_angleDifference = angle - m_angle;
        m_angle = angle;
        updateMatrix();
        emit angleChanged();
    }
}

float OrbitTransformController::angle() const
{
    return m_angle;
}
