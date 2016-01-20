import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.0
Rectangle {
    width: 100
    height: 62
    Column{
        width: parent.width
        height: parent.height
        Text {
            text: qsTr("Please tell us where binarycreator is installed to.")
        }
        Button{
            text: qsTr("Add binarycreator")
            onClicked: binaryDialog.open()
        }
    }

    FileDialog {
         id: binaryDialog
         title: "Please chose binarycreator"
         visible: false
         folder: homeDir + "/"
         nameFilters: ["binarycreator"]
         onAccepted: {
             console.log("You chose: " + fileDialog.fileUrls)

             //             domWriter.setBinaryCreatorLocation()
         }
         Component.onCompleted: visible = false
     }

}



