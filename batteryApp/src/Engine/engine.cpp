#include <engine.h>
#include <QDebug>

Engine::Engine(AbstractPlotViewModel &plotViewModel,
               IState &csvLoader, IState &tempLoader, IState &gradCalc, IState &rangeCalc, IState &uiDrawer) :
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
        qDebug() << "CSVLoaded!";
        m_currentState = States::TemperatureLoading;
        m_tempLoader.runState();
        break;
    case States::TemperatureLoading:
        qDebug() << "TemperatureLoaded!";
        m_currentState = States::GradientCalculating;
        m_gradCalc.runState();
        break;
    case States::GradientCalculating:
        qDebug() << "GradientLoaded!";
        m_currentState = States::RangeCalculating;
        m_rangeCalc.runState();
        break;
    case States::RangeCalculating:
        qDebug() << "RangeLoaded!";
        m_currentState = States::UIDrawing;
        m_uiDrawer.runState();
        break;
    case States::UIDrawing:
        qDebug() << "ViewModelLoaded!";
        m_currentState = States::Idle;
        // Do other stuff
        // m_idle.runstate() - implementation ?
        break;
    case States::Idle:
        /*NOP...*/
        break;
    default:
        /* Do nothing */
        break;
    }
}

void Engine::errorOccured(Errors currentError)
{
    switch(currentError)
    {
    case Errors::NoTemperatureValuesError:
        m_plotViewModel.setErrorMessage("Not Available !");
        break;
    case Errors::FileCorruptedError:
        m_plotViewModel.setErrorMessage("File Corrupted Error !");
        break;
    case Errors::OtherError:
        m_plotViewModel.setErrorMessage("Other Error !");
        break;
//    case NoError ?
    default:
        /* Do nothing */
        break;
    }
}
