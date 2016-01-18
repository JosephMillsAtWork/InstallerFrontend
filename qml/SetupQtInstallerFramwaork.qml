import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.0
Dialog {
    id: noQtBinaryDialog
    visible: false
    width: Screen.width / 1.7
    height: Screen.height / 1.7
    title: qsTr("Basic Setup")
    contentItem:LoaderHelper{
        width: parent.width
        height: parent.height
        item:
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
            }
            Button{
                width: parent.width / 1.07
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("I do not have Qt Installer Framework installed on this machine.")
            }

        }
    }
}
