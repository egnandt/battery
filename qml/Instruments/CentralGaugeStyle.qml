import QtQuick 2.8
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

CircularGaugeStyle {
    needle: Item {
        width: childrenRect.width;
        height: childrenRect.height
        DropShadow {
            anchors.fill: needlebody
            radius: 30.0
            samples: 60
            color: "#FFA000"
            source: needlebody
        }

        Rectangle {
            id: needlebody
            y: outerRadius * 0.15
            implicitWidth: outerRadius * 0.018
            implicitHeight: outerRadius * 0.8
            antialiasing: true
            color: "#FF5000"
        }
    }

    tickmark: Item {
        width: childrenRect.width;
        height: childrenRect.height

        DropShadow {
            anchors.fill: tickMarkk
            radius: 10.0
            samples: 17
            color: "darkGray"
            source: tickMarkk
        }

        Rectangle {
            id: tickMarkk
            height: 8
            width: 3
            color: "white"
            antialiasing: true
            smooth: true
        }
    }

    minorTickmark: Item {
        width: childrenRect.width;
        height: childrenRect.height

        DropShadow {
            anchors.fill: tickMarkMinorr
            radius: 10.0
            samples: 17
            color: "darkGray"
            source: tickMarkMinorr
        }

        Rectangle {
            id: tickMarkMinorr
            height: 4
            width: 2
            color: "white"
            antialiasing: true
            smooth: true
        }
    }

    tickmarkLabel: Item {
        width: childrenRect.width;
        height: childrenRect.height

        DropShadow {
            anchors.fill: tickMarkLabel
            radius: 10.0
            samples: 17
            color: "darkGray"
            source: tickMarkLabel
        }

        Text {
            id: tickMarkLabel
            text: styleData.value;
            font.pointSize: 23;
            color: "white"
        }
    }

    foreground: Item{}
}
