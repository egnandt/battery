#ifndef ABSTRACTINSTRUMENTSMODEL_H
#define ABSTRACTINSTRUMENTSMODEL_H

#include <QObject>

class AbstractInstrumentsModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(double power READ power NOTIFY powerChanged)
    Q_PROPERTY(bool turnLefQ_OBJECTt READ turnLeft NOTIFY turnLeftChanged)
    Q_PROPERTY(bool turnRight READ turnRight NOTIFY turnRightChanged)
    Q_PROPERTY(bool light READ light NOTIFY lightChanged)
    Q_PROPERTY(bool driveLight READ driveLight NOTIFY driveLightChanged)
    Q_PROPERTY(bool fogFront READ fogFront NOTIFY fogFrontChanged)
    Q_PROPERTY(bool fogRear READ fogRear NOTIFY fogRearChanged)
    Q_PROPERTY(bool charge READ charge NOTIFY chargeChanged)
    Q_PROPERTY(bool airbag READ airbag NOTIFY airbagChanged)
    Q_PROPERTY(bool engine READ engine NOTIFY engineChanged)
    Q_PROPERTY(bool abs READ abs NOTIFY absChanged)

public:

    /**
     * @brief Constructor
     * @param aParent - a QObject* argument, the parent object
     */
    explicit AbstractInstrumentsModel(QObject* aParent = 0);

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractInstrumentsModel();

    /**
     * @brief Gets the current speed
     * @return double
     */
    virtual double speed() const = 0;

    /**
     * @brief Gets the current power
     * @return double
     */
    virtual double power() const = 0;

    /**
     * @brief Gets the current state of turn left signal
     * @return bool
     */
    virtual bool turnLeft() const = 0;

    /**
     * @brief Gets the current state of turn right signal
     * @return bool
     */
    virtual bool turnRight() const = 0;

    /**
     * @brief Gets the current state of lights
     * @return bool
     */
    virtual bool light() const = 0;

    /**
     * @brief Gets the current state of drive lights
     * @return bool
     */
    virtual bool driveLight() const = 0;

    /**
     * @brief Gets the current state of front fog lights
     * @return bool
     */
    virtual bool fogFront() const = 0;

    /**
     * @brief Gets the current state of rear fog lights
     * @return bool
     */
    virtual bool fogRear() const = 0;

    /**
     * @brief Gets the current state of low state of charge warning
     * @return bool
     */
    virtual bool charge() const = 0;

    /**
     * @brief Gets the current state of airbag warning
     * @return bool
     */
    virtual bool airbag() const = 0;

    /**
     * @brief Gets the current state of MIL warning
     * @return bool
     */
    virtual bool engine() const = 0;

    /**
     * @brief Gets the current state of abs warning
     * @return bool
     */
    virtual bool abs() const = 0;

signals:

    /**
     * @brief SIGNAL emitted when the speed changed
     */
    void speedChanged();

    /**
     * @brief SIGNAL emitted when the power changed
     */
    void powerChanged();

    /**
     * @brief SIGNAL emitted when the state of turn left signal changed
     */
    void turnLeftChanged();

    /**
     * @brief SIGNAL emitted when the state of turn rigt signal changed
     */
    void turnRightChanged();

    /**
     * @brief SIGNAL emitted when the state of lights changed
     */
    void lightChanged();

    /**
     * @brief SIGNAL emitted when the state of drive lights changed
     */
    void driveLightChanged();

    /**
     * @brief SIGNAL emitted when the state of front fog lights changed
     */
    void fogFrontChanged();

    /**
     * @brief SIGNAL emitted when the the state of rear fog lights changed
     */
    void fogRearChanged();

    /**
     * @brief SIGNAL emitted when the state of low state of charge changed
     */
    void chargeChanged();

    /**
     * @brief SIGNAL emitted when the state of airbad warning changed
     */
    void airbagChanged();

    /**
     * @brief SIGNAL emitted when the state of engine warning changed
     */
    void engineChanged();

    /**
     * @brief SIGNAL emitted when the state of abs warning changed
     */
    void absChanged();

};

#endif // ABSTRACTINSTRUMENTSMODEL_H
