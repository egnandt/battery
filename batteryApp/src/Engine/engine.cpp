#include <engine.h>
#include <QDebug>

Engine::Engine(std::unique_ptr<AbstractModel> model, AbstractPlotViewModel &plotViewModel,
               IState &csvLoader, IState &tempLoader, IState &gradCalc, IState &rangeCalc, IState &uiDrawer) :
    m_model(std::move(model)),
    m_plotViewModel{plotViewModel},
    m_csvLoader{csvLoader},
    m_tempLoader{tempLoader},
    m_gradCalc{gradCalc},
    m_rangeCalc{rangeCalc},
    m_uiDrawer{uiDrawer}
{

}

void Engine::run()
{
    m_plotViewModel.setLoading(true);
    qDebug()<<"Entered Engine run";
    m_currentState = States::CSVLoading;
    m_csvLoader.runState();
}

void Engine::stateFinished()
{
    switch(m_currentState)
    {
    case States::CSVLoading:
        m_currentState = States::TemperatureLoading;
        m_tempLoader.runState();
        break;
    case States::TemperatureLoading:
        m_currentState = States::GradientCalculating;
        m_gradCalc.runState();
        break;
    case States::GradientCalculating:
        m_currentState = States::RangeCalculating;
        m_rangeCalc.runState();
    case States::RangeCalculating:
        m_currentState = States::UIDrawing;
        m_uiDrawer.runState();
        break;
    case States::UIDrawing:
        m_currentState = States::Idle;
        // Do other stuff
        // m_idle.runstate() - implementation?
        break;
    case States::Idle:
        /*NOP...*/
        break;
    default:
        /* Do nothing */
        break;
    }
}

void Engine::errorOccured()
{

}
