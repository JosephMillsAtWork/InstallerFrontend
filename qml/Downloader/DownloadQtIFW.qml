import QtQuick 2.0
import QtQuick.Controls 1.2
import InstallerFrontEnd 1.0
Rectangle {
    width: 100
    height: 62
    color: palette.base
    Column{
        width:  parent.width
        height: parent.height
        spacing:  20
        Text {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22
            text: qsTr("Please Pick a version in which you would like to use")
        }
        ComboBox{
            id:versionPicker
            width: parent.width / 1.07
            anchors.horizontalCenter: parent.horizontalCenter
            model: versionsModel
        }
        Button{
            width: parent.width / 1.07
            text: qsTr("Download Qt Installer Framework ( %1 )").arg(versionPicker.currentText)
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {

                domWriter.setCorrectPreBuilt(versionPicker.currentText);
                downloadQtIFW = domWriter.getCorrectPreBuilt;
                downloaderLoader.source = "qrc:/Downloader/DownloadPackage.qml"
                // open dl page
            }
        }
    }
    Component.onCompleted: {
        for (var i = 0 ; i < domWriter.getPrebuiltVersions.length;i++){
            versionsModel.append({"text" : domWriter.getPrebuiltVersions[i]})
        }
    }

    ListModel{id: versionsModel}
}
