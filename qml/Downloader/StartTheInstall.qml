import QtQuick 2.0
import QtQuick.Controls 1.2

import InstallerFrontEnd 1.0
Column{
    width: parent.width
    height:  parent.height //progressBar.height + dlInfoText.paintedHeight + whatIsLeft.paintedHeight + 10
    spacing: 5
     Component.onCompleted: {permissionsRunner.start()}
    Text {
        id: permissionsText
        width: parent.width / 1.07
        wrapMode: Text.WordWrap

        horizontalAlignment:  Text.AlignHCenter
        font.pixelSize: 22
        text: qsTr("Checking Permissions for The Qt Installer Framework" )
    }


    BusyIndicator{
        id: busy
        running: false
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QQmlProcess{
        id: processRunner
        program: root.qtIFWFIle
        runType: QQmlProcess.Attached
        onRunning: {
            console.log("Running the QTIFW ")
            busy.running = true
        }
        onNewMessage: {
            console.log("Message "  + message)
        }
        onFinished: {
            busy.running = false
            permissionsText.text = qsTr("Ok Now that you have installed the Qt Installer Framework. You must set where it is installed so that any time you open this application again you dpo not need to set it again" )
            downloaderLoader.source = "QtIfwBinarySettings.qml"
        }

        onError: console.log(errorString)
    }




//    QQmlFilePermissions{
//        id: filePermissions
//        file: root.qtIFWFIle
//        Component.onCompleted: {

//            filePermissions.appendPermissions(QQmlFilePermissions.ReadGroup)
//            filePermissions.appendPermissions(QQmlFilePermissions.ReadOwner)

//            filePermissions.appendPermissions(QQmlFilePermissions.ExecOwner)
//            filePermissions.appendPermissions(QQmlFilePermissions.ExecOther)
//            filePermissions.appendPermissions(QQmlFilePermissions.ExecGroup)
//            // ok so we made sure that the permissions are good lets run a timer real fast
//            // then run the process to install QTIFW
//            ifwTimer.start()
//        }
//    }

    QQmlProcess{
        id: permissionsRunner
        program: "chmod"
        arguments: ['+x', root.qtIFWFIle]
        onFinished:{console.log("DONE CHANGING PERMISSIONS "); ifwTimer.start()}
        onRunning:  console.log("changing permissions of the file ")
        runType: QQmlProcess.Attached
    }
    Timer{
        id:ifwTimer
        interval: 1200
        running: false
        repeat: false
        onTriggered: {
            // here we start the process
            permissionsText.text = qsTr("The Qt Installer Framework Permissions are set. Going to now run the installer. Please come back to this page and setup the rest of this setup process after you install the Qt Installer Framework " )

            console.log("starting " + processRunner.program)
            processRunner.start() //.start()

        }
    }
}
