import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3

Rectangle{
    width: root.width
    height:root.height
    Component.onCompleted: setupStyle()

    Rectangle{
        id: startHead
        width: parent.width
        height: 100
        color: Qt.darker(root.color,3)
        Row{
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
    }


    Label {
        id: name
        text: qsTr("Please choose a Style that you would like to use.")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: startHead.bottom
        anchors.topMargin: 20
        font.pixelSize: 20
    }





    GridView{
        id: wView
        width: parent.width / 1.07
        height: parent.height - 20
        cellHeight: parent.height/ 4
        cellWidth: parent.width / 2.5

        anchors.top: name.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        model: stylesModel
        delegate: WizardStyleButton{
            text: tx
            width: wView.cellWidth
            height: wView.cellHeight
            icon: "artwork/"+tx+".png"
            onClicked:{
                if (domWriter.hasTheBinaryPath() === false){
                    noQtBinaryDialog.open();
                }else{
                root.wizardStyle = tx
                mainLoader.source = "StartHere.qml"
                }
            }

        }
    }
    function setupStyle(){

        var styles = ['Modern','Mac','Aero','Classic']
        for (var i = 0 ; i < styles.length;i++){
            stylesModel.append({"tx":styles[i]})
        }
    }
    ListModel{id:stylesModel}
}
