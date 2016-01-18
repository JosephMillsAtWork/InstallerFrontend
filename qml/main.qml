import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
import InstallerFrontEnd 1.0

ApplicationWindow{
    id: root
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    color: palette.midlight
    property string wizardStyle
    toolBar: ToolBar{
        id: panelButtons
        visible: false
        //        RowLayout {
        //            anchors.fill: parent
        //            ToolButton {
        //                iconSource: "new.png"
        //            }
        //            ToolButton {
        //                iconSource: "open.png"
        //            }
        //            ToolButton {
        //                iconSource: "save-as.png"
        //            }
        //            Item { Layout.fillWidth: true }
        //            CheckBox {
        //                text: "Enabled"
        //                checked: true
        //                Layout.alignment: Qt.AlignRight
        //            }
        //        }
    }

    statusBar:Rectangle{
        width:  root.width
        height: 26
        color: palette.mid
    }
    menuBar: MenuBar {

        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    SystemPalette{id:palette}


    Loader{
        id:mainLoader
        width: parent.width
        height: parent.hight
        source: "WizardStyle.qml"
    }


    Component.onCompleted: {
        domWriter.downloadPrebuilt("2.0.1");
        if (domWriter.hasTheBinaryPath() === false){
            noQtBinaryDialog.open();
        }
    }

    QQmlDom{
        id: domWriter
        onError: errorDialog.open()
    }

    SetupQtInstallerFramwaork{
        id: noQtBinaryDialog
        visible: false


    }

    Dialog {
        id: errorDialog
        visible: false
        title: "Error "
        contentItem: Rectangle {
            color: palette.base
            implicitWidth: 400
            implicitHeight: 100
            Text {
                color: "navy"
                anchors.centerIn: parent
            }
        }
    }
}
