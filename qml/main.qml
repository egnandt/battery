import QtQuick 2.8
import "Instruments/"
import "Plot/"


MouseArea {
    id: root

    width: 1920;
    height: 720;

    Rectangle {
        id: background
        anchors.fill: parent;
        color: "black";
    }

    ClusterInstruments {
        id: instruments
        anchors.fill: parent;
    }

    Plot {
        id: plot
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
    }
}
