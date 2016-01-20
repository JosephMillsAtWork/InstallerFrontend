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
        item:Loader{
            id: downloaderLoader
            anchors.fill: parent
            source: "qrc:/Downloader/IntroPage.qml"

        }
    }
    onVisibleChanged: {
        if(visible == false){
            downloaderLoader.source = "qrc:/Downloader/IntroPage.qml"
        }
    }
}
