import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtShark.Images 1.0

Window {
    id: window
    visible: true

    width: 640
    height: 480

    title: qsTr("QtQuick.Images")

    Image {
        id: exampleImage
        anchors.centerIn: parent
    }

    Text {
        id: tooltip
        anchors.centerIn: parent
        text: qsTr("CLICK ME")
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            var url = QtImages.load("demo.png", ":/demo.png");
            exampleImage.source = url;
            window.title = exampleImage.source;
            tooltip.visible = false;
        }
    }
}
