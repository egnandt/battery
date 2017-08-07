import QtQuick 2.8
import QtGraphicalEffects 1.0
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

    Item {
        id: errorMessageBox
        anchors.horizontalCenter:parent.horizontalCenter;
        y:10
        width: 800
        height: 500

        RectangularGlow {
            id: effect
            anchors.fill: rect
            glowRadius: 15
            spread: 0.2
            color: "#9999FF"
            cornerRadius: rect.radius + glowRadius
        }

        Rectangle {
            id: rect
            gradient: Gradient {
                GradientStop {position: 0; color: "#333333" }
                GradientStop {position: 1; color: "#111111"}
            }

            anchors.centerIn: parent
            width: Math.round(parent.width / 1.5)
            height: Math.round(parent.height / 2)
            radius: 25
        }
        Text {
              anchors.fill:effect
              anchors.horizontalCenterOffset: 1000
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              wrapMode: Text.WordWrap
              text: plotViewModel.errorMessage
              font.weight : Font.Bold
              font.family: "Helvetica"
              font.pointSize: 24
              color: "steelblue"
              maximumLineCount: 2
          }
    }

}

