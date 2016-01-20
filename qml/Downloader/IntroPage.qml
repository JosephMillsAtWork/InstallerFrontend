import QtQuick 2.0
import QtQuick.Controls 1.2
Rectangle {
    width: 100
    height: 62
    Column{
        anchors.fill: parent
        Text {
            wrapMode: Text.WordWrap
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width / 1.07
            text: qsTr("Installer Framework depends on Qt's Installer Framework.  Eiter this is the first time that you have ran this. Or Something has gone wrong and you need to reset where Qt Installer Framework is located. ")
        }


        Text {
            wrapMode: Text.WordWrap
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width / 1.07
            text: qsTr("Please take a moment to set up Qt Installer Framework ")
        }

        Button{
            width: parent.width / 1.07
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("I already Have Qt Installer Framework installed to this Machine")
            onClicked: {
                downloaderLoader.source = "qrc:/QSettings/QtIfwBinarySettings.qml"
            }
        }
        Button{
            width: parent.width / 1.07
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("I do not have Qt Installer Framework installed on this machine.")
            onClicked: {
                downloaderLoader.source = "qrc:/Downloader/DownloadQtIFW.qml"
            }
        }

    }
}
