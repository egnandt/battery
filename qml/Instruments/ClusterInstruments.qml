import QtQuick 2.8
import QtQuick.Extras 1.4
import BatteryApp 1.0

Item {
    id: instrumentsRoot

    Column {
        anchors.centerIn: speedometer
        anchors.verticalCenterOffset: 130
        spacing: 100
        Row {
            spacing: 195;
            anchors.horizontalCenter: parent.horizontalCenter;
            Image {
                id: abs
                source: "qrc:/img/abs.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.abs ? 1 : 0;
            }
        }
    }
    Column {
        anchors.centerIn:speedometer
        spacing: 100
        Row{
            spacing: 270
        Image {
            id: engine
            source: "qrc:/img/engine.png"
            smooth: true
            antialiasing: true
            anchors.verticalCenter: parent.verticalCenter
            scale: 1.5
            opacity: instrumentsModel.engine ? 1 : 0;
        }
        Image {
            id: airbag
            source: "qrc:/img/airbag.png"
            smooth: true
            antialiasing: true
            anchors.verticalCenter: parent.verticalCenter
            scale: 1.5
            opacity: instrumentsModel.airbag ? 1 : 0;
        }
    }
    }
    Column {
        anchors.centerIn: powerMeter
        anchors.verticalCenterOffset: 130
        spacing: 100
        Row{
            spacing: 280
            Image {
                id: fogRear
                fillMode: Image.TileVertically
                source: "qrc:/img/fog_rear.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.fogRear ? 1 : 0;
            }
        }
    }
    Column {
        anchors.centerIn: powerMeter
        spacing: 100
        Row{
            spacing: 260

            Image{
                id: fogFront
                source: "qrc:/img/fog_front.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.fogFront ? 1 : 0;
            }
            Image {
                id: charge
                source: "qrc:/img/charge.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.charge ? 1 : 0;
            }
        }
    }
    Column {
        y: 60
        spacing: 100
        anchors.horizontalCenter: parent.horizontalCenter
        Row {
            spacing: 200;
            anchors.horizontalCenter: parent.horizontalCenter;
            Image {
                id: turnLeft
                source: "qrc:/img/turn_left.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.turnLeft ? 1 : 0;
            }
            Image {
                id: light
                source: "qrc:/img/light.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.light ? 1 : 0;
            }
            Image {
                id: driveLight
                source: "qrc:/img/drive_light.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.driveLight ? 1 : 0;
            }
            Image {
                id: turnRight
                source: "qrc:/img/turn_right.png"
                smooth: true
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                scale: 1.5
                opacity: instrumentsModel.turnRight ? 1 : 0;
            }
        }
    }
    CircularGauge {
        id: speedometer
        x: 50;
        y: 70;
        width: 600
        height: 600
        value: instrumentsModel !== undefined ? instrumentsModel.speed : 0;
        Behavior on value { PropertyAnimation{duration: 500; easing.type: Easing.InOutQuad}}
        minimumValue: 0
        maximumValue: 150

        style: CentralGaugeStyle {
            minimumValueAngle: -180;
            maximumValueAngle: 90;
            labelStepSize: 10
            labelInset: 50
        }

        Text {
            anchors.centerIn: parent;
            anchors.verticalCenterOffset: - parent.height / 4
            text: "KPH"
            color: "white"
            font.pointSize: 23
            z: parent.z - 1
        }
    }
    CircularGauge {
        id: powerMeter
        x: 1270;
        y: 70;
        width: 600
        height: 600
        value: instrumentsModel !== undefined ? instrumentsModel.power : 0;
        Behavior on value { PropertyAnimation{duration: 500; easing.type: Easing.InOutQuad}}
        minimumValue: 0
        maximumValue: 100
        style: CentralGaugeStyle {
            minimumValueAngle: -90;
            maximumValueAngle: 180;
            labelStepSize: 10
            labelInset: 50
        }

        Text {
            anchors.centerIn: parent;
            anchors.verticalCenterOffset: - parent.height / 4
            text: "RPHx100"
            color: "white"
            font.pointSize: 23
            z: parent.z - 1
        }
    }

}

