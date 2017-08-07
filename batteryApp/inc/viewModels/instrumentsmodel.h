#ifndef INSTRUMENTSMODEL_H
#define INSTRUMENTSMODEL_H

#include <QTimer>
#include "abstractinstrumentsmodel.h"

class InstrumentsModel: public AbstractInstrumentsModel
{
    Q_OBJECT

public:

    /**
     * @brief Constructor
     * @param aParent - a QObject* argument, the parent object
     */
    explicit InstrumentsModel(QObject* aParent = 0);

    /**
     * @brief Destructor
     */
    ~InstrumentsModel();

public: // From AbstractInstrumentsModel
    double speed() const;
    double power() const;
    bool turnLeft() const;
    bool turnRight() const;
    bool light() const;
    bool driveLight() const;
    bool fogFront() const;
    bool fogRear() const;
    bool charge() const;
    bool airbag() const;
    bool engine() const;
    bool abs() const;

private:

    /**
     * @brief Sets the speed to a given value
     * @param value - a double argument, the value to set
     */
    void setSpeed(double value);

    /**
     * @brief Sets the power to a given value
     * @param value - a double argument, the value to set
     */
    void setPower(double value);

    /**
     * @brief Sets the state of the turn left signal to a given value
     * @param value - a bool argument, the value to set
     */
    void setTurnLeft(bool value);

    /**
     * @brief Sets the state of the turn right signal to a given value
     * @param value - a bool argument, the value to set
     */
    void setTurnRight(bool value);

    /**
     * @brief Sets the state of the lights to a given value
     * @param value - a bool argument, the value to set
     */
    void setLight(bool value);

    /**
     * @brief Sets the state of the drive lights to a given value
     * @param value - a bool argument, the value to set
     */
    void setDriveLight(bool value);

    /**
     * @brief Sets the state of the front fog lights to a given value
     * @param value - a bool argument, the value to set
     */
    void setFogFront(bool value);

    /**
     * @brief Sets the state of the rear for lights to a given value
     * @param value - a bool argument, the value to set
     */
    void setFogRear(bool value);

    /**
     * @brief Sets the state of the low state of charge warning to a given value
     * @param value - a bool argument, the value to set
     */
    void setCharge(bool value);

    /**
     * @brief Sets the state of the airbag warning to a given value
     * @param value - a bool argument, the value to set
     */
    void setAirbag(bool value);

    /**
     * @brief Sets the state of the MIL warning to a given value
     * @param value - a bool argument, the value to set
     */
    void setEngine(bool value);

    /**
     * @brief Sets the state of the ABS warning to a given value
     * @param value - a bool argument, the value to set
     */
    void setAbs(bool value);

private slots:

    void onTimerElapsed();

private:

    /**
     * @brief Timer member
     */
    QTimer m_timer;

    /**
     * @brief The current speed
     */
    double m_speed;

    /**
     * @brief The current power
     */
    double m_power;

    /**
     * @brief The current state of turn left signal
     */
    bool m_turnLeft;

    /**
     * @brief The current state of turn right signal
     */
    bool m_turnRight;

    /**
     * @brief The current state of lights
     */
    bool m_light;

    /**
     * @brief The current state of drive lights
     */
    bool m_driveLight;

    /**
     * @brief The current state of front fog lights
     */
    bool m_fogFront;

    /**
     * @brief The current state of rear fog lights
     */
    bool m_fogRear;

    /**
     * @brief The current state of low state of charge warning
     */
    bool m_charge;

    /**
     * @brief The current state of airbag warning
     */
    bool m_airbag;

    /**
     * @brief The current state of MIL warning
     */
    bool m_engine;

    /**
     * @brief The current state of ABS warning
     */
    bool m_abs;
};

#endif // INSTRUMENTSMODEL_H
