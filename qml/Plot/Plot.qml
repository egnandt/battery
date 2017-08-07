import QtQuick 2.8
import QtCharts 2.2


Item {
    id: plotRoot
    width: 1150;
    height: 290;

    //our ChartView
    ChartView {
        theme: ChartView.ChartThemeDark;
        anchors.fill: parent
        antialiasing: true
        backgroundRoundness: 5
   //X and Y axis
        ValueAxis
        {
            id:valueAxisY
            min: plotViewModel.minValueY
            max:100
            tickCount: 10
            labelFormat: "%.0f"
        }
        ValueAxis
        {
            id:valueAxisX
            tickCount: plotViewModel.temperaturePoints.length / 3
            labelFormat: "%.0f"
            max: plotViewModel.temperaturePoints.length - 1
        }

   //represented LineSeries

        AreaSeries
        {
            name: "Gradient<br>(%)"
            color: "#AAAA0000"
            borderColor: "black"
            axisX:valueAxisX
            axisY:valueAxisY

            lowerSeries: LineSeries
            {
                XYPoint {x:0; y:0}
                XYPoint {x:plotViewModel.temperaturePoints.length; y:0}
            }

            upperSeries: LineSeries
            {
                id:gradientLine
                axisY:valueAxisY
            }
        }
        SplineSeries
        {
            id: tempLine
            name :"Temperature<br>(Celsius)"
            axisY:valueAxisY
        }
        LineSeries
        {
            id:batteryStatusLine
            name :"Battery State of Charge<br>(%)"
            axisY:valueAxisY
        }


  //coonection with the viewModel
        Connections {
            target: plotViewModel
            onTemperaturePointsChanged:
            {
                loadTemperaturePoints();
            }
            onGradientPointsChanged:
            {
                loadGradientPoints();
            }
            onBatteryStateOfChargePointsChanged:
            {
                loadBatteryStatusPoints();
            }
        }

    }

    Component.onCompleted:
    {
        loadTemperaturePoints();
        loadGradientPoints();
        loadBatteryStatusPoints();
    }
    //funtions for loading data
    function loadTemperaturePoints() {
        tempLine.clear();
        for(var i = 0; i < plotViewModel.temperaturePoints.length; ++i)
        {
            tempLine.append(plotViewModel.temperaturePoints[i].x, plotViewModel.temperaturePoints[i].y)
        }
    }
    function loadGradientPoints() {
        gradientLine.clear();
        for(var i = 0; i < plotViewModel.gradientPoints.length; ++i)
        {
            gradientLine.append(plotViewModel.gradientPoints[i].x, plotViewModel.gradientPoints[i].y)
        }
    }
    function loadBatteryStatusPoints() {
        batteryStatusLine.clear();
        for(var i = 0; i < plotViewModel.batteryStateOfChargePoints.length; ++i)
        {
           batteryStatusLine.append(plotViewModel.batteryStateOfChargePoints[i].x, plotViewModel.batteryStateOfChargePoints[i].y)
        }
}
}
