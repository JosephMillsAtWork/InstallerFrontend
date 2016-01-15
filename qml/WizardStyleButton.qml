import QtQuick 2.3
Item {
    id: wStyleIcon
    property string icon
    property string text
    signal clicked()

    Column {
        width: parent.width
        height: parent.height
        Image {
            id: theImage
            source: icon
            width: parent.width
            height: parent.height - wText.paintedHeight * 1.3
        }
        Text {
            id: wText
            font.pixelSize: 18
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr(wStyleIcon.text)
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: wStyleIcon.clicked();
    }
}
