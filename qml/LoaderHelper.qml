import QtQuick 2.2
import QtQuick.Controls 1.2

Item{
    property alias item: theItem.children
    Rectangle{
    id: startHead
    width: parent.width
    height: 100
    color: Qt.darker(root.color,3)
    Row{
        id: theRow
        anchors.fill: parent
        spacing: 15
        Rectangle {
            color: "transparent"
            width: 20
            height:    1
        }
        Image {
            id: icon
            height: startHead.height -10
            width: height
            source: "artwork/Qt-logo-medium.png"
            anchors.verticalCenter: parent.verticalCenter
        }
        Label {
            id: welcome
            text: qsTr(" The Qt Installer Framework provides a set of tools and utilities to create installers for the supported desktop Qt platforms: Linux, Microsoft Windows, and OS X.")
            wrapMode: Text.WordWrap
            color:"white"
            font.pixelSize: 18
            width: startHead.width - icon.width - 20
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    Item{
        id: theItem
        width: parent.width
        height: parent.height - theRow,height
        anchors.top: theRow.bottom


    }


}


}
