#ifndef ENGINE_H
#define ENGINE_H
#include "istatecallback.h"
#include "istate.h"
#include "abstractplotviewmodel.h"
#include <memory>

enum class States
{
    CSVLoading,
    TemperatureLoading,
    GradientCalculating,
    RangeCalculating,
    UIDrawing,
    Idle,
};

class Engine : public IStateCallback
{
public:

    Engine(AbstractPlotViewModel &plotViewModel,
           IState &csvLoader, IState &tempLoader, IState &gradCalc, IState &rangeCalc, IState &uiDrawer);

    void stateFinished();

    void errorOccured(Errors currentError);

    void run();

private:
    AbstractPlotViewModel& m_plotViewModel;
    IState& m_csvLoader;
    IState& m_tempLoader;
    IState& m_gradCalc;
    IState& m_rangeCalc;
    IState& m_uiDrawer;
    States m_currentState;
};

#endif // ENGINE_H
