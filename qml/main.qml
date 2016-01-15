import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.0

import InstallerFrontEnd 1.0

ApplicationWindow{
    id: root
    visible: true
    width: Screen.width
    height: Screen.height
    color: palette.midlight
    property string wizardStyle
    toolBar: ToolBar{
        id: panelButtons
        visible: true
        RowLayout {
            anchors.fill: parent
            ToolButton {
                iconSource: "new.png"
            }
            ToolButton {
                iconSource: "open.png"
            }
            ToolButton {
                iconSource: "save-as.png"
            }
            Item { Layout.fillWidth: true }
            CheckBox {
                text: "Enabled"
                checked: true
                Layout.alignment: Qt.AlignRight
            }
        }
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
        width: parent.width ///- leftBar.width
        height: parent.hight
        source: "WizardStyle.qml"
    }



    QQmlDom{
        id: domWriter
    }

}
