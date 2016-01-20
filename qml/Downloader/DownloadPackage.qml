import QtQuick 2.0
import QtQuick.Controls 1.2
import InstallerFrontEnd 1.0


Column{
    width: root.width
    height: progressBar.height + dlInfoText.paintedHeight + whatIsLeft.paintedHeight + 10
    spacing: 5
    Component.onCompleted: dl.execute();

    Text {
        id: dlInfoText
        width: parent.width / 1.07
        horizontalAlignment:  Text.AlignHCenter
        font.pixelSize: 22

        text: qsTr("Downloading The Qt Installer Framework" )
    }

    ProgressBar{
        id: progressBar
        width: parent.width / 1.07
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text {
        id: whatIsLeft
        visible: progressBar.visible
        horizontalAlignment: Text.AlignHCenter
        width: parent.width / 1.07
        text:{
            var dis = dl.incommingSpeed
            var toFixed = dis.toFixed(2)
            "Speed " + toFixed + " " + dl.units
        }
    }


    QQmlNetwork{
        id: dl
        type: QQmlNetwork.Get
        url: root.downloadQtIFW
        savePath: downloadDir + "/"
        onFinished: {
//            console.log("Finished DOwnloading " + url)
            var nameOfFile = url.substring(url.lastIndexOf("/")+1);
//            console.log(savePath + nameOfFile)
            root.qtIFWFIle = savePath  + nameOfFile

            downloaderLoader.source = "qrc:/Downloader/StartTheInstall.qml"
        }
        onBytesReceivedChanged:{
            progressBar.value =  bytesReceived
        }
        onBytesTotalChanged:{
            progressBar.maximumValue = bytesTotal
        }
    }
}
