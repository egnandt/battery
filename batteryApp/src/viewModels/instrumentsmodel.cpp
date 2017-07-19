#include "InstrumentsModel.h"

InstrumentsModel::InstrumentsModel(QObject* aParent) :
    AbstractInstrumentsModel(aParent),
    m_speed(20.0),
    m_power(5.0),
    m_turnLeft(false),
    m_turnRight(false),
    m_light(false),
    m_driveLight(false),
    m_fogFront(false),
    m_fogRear(false),
    m_charge(false),
    m_airbag(false),
    m_engine(false),
    m_abs(false)
{

}

InstrumentsModel::~InstrumentsModel()
{

}

double InstrumentsModel::speed() const
{
    return m_speed;
}

double InstrumentsModel::power() const
{
    return m_power;
}

bool InstrumentsModel::turnLeft() const
{
    return m_turnLeft;
}

bool InstrumentsModel::turnRight() const
{
    return m_turnRight;
}

bool InstrumentsModel::light() const
{
    return m_light;
}

bool InstrumentsModel::driveLight() const
{
    return m_driveLight;
}

bool InstrumentsModel::fogFront() const
{
    return m_fogFront;
}

bool InstrumentsModel::fogRear() const
{
    return m_fogRear;
}

bool InstrumentsModel::charge() const
{
    return m_charge;
}

bool InstrumentsModel::airbag() const
{
    return m_airbag;
}

bool InstrumentsModel::engine() const
{
    return m_engine;
}

bool InstrumentsModel::abs() const
{
    return m_abs;
}

void InstrumentsModel::setSpeed(double value)
{
    m_speed = value;
    emit speedChanged();
}

void InstrumentsModel::setPower(double value)
{
    m_power = value;
    emit powerChanged();
}

void InstrumentsModel::setTurnLeft(bool value)
{
    m_turnLeft = value;
    emit turnLeftChanged();
}

void InstrumentsModel::setTurnRight(bool value)
{
    m_turnRight = value;
    emit turnRightChanged();
}

void InstrumentsModel::setLight(bool value)
{
    m_light = value;
    emit lightChanged();
}

void InstrumentsModel::setDriveLight(bool value)
{
    m_driveLight = value;
    emit driveLightChanged();
}

void InstrumentsModel::setFogFront(bool value)
{
    m_fogFront = value;
    emit fogFrontChanged();
}

void InstrumentsModel::setFogRear(bool value)
{
    m_fogRear = value;
    emit fogRearChanged();
}

void InstrumentsModel::setCharge(bool value)
{
    m_charge = value;
    emit chargeChanged();
}

void InstrumentsModel::setAirbag(bool value)
{
    m_airbag = value;
    emit airbagChanged();
}

void InstrumentsModel::setEngine(bool value)
{
    m_engine = value;
    emit engineChanged();
}

void InstrumentsModel::setAbs(bool value)
{
    m_abs = value;
    emit absChanged();
}
