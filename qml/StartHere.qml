import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.0
import QtQuick.XmlListModel 2.0
import InstallerFrontEnd 1.0


Item {
    id: name
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

    ColumnLayout{
        id: welcomeColoumn
        anchors.top:startHead.bottom
        width: mainLoader.width
        height: mainLoader.height - 20 - startHead.height
        spacing: 20

        Label{
            anchors.horizontalCenter: parent.horizontalCenter
            text:qsTr("\nPlease Provide the Needed information below to Create a Configuration\n")
            font.pixelSize: 16
        }


        RowLayout{
            Layout.preferredWidth: parent.width / 1.07
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Label{
                id: outSource
                text: qsTr("Where to Build ?")

            }
            TextField{
                id: outDir
                Layout.preferredWidth: appName.width - outSource.paintedWidth
                Layout.alignment: Qt.AlignHCenter
                text: buildDefaultDir

            }
            Button{
                id:outFileDialog
                text: qsTr("Browse Source...")
                onClicked: {
                }
            }

        }
        // Name
        RowLayout{
            Layout.preferredWidth: parent.width / 1.07
            Layout.alignment: Qt.AlignHCenter
            Label{
                id: nameApp
                text: qsTr("Name of the Applications  ")

            }
            TextField{
                id: appName
                Layout.preferredWidth: welcomeColoumn.width / 1.07 - nameApp.paintedWidth
                Layout.alignment: Qt.AlignHCenter
                text: configXml.name
            }
        }

        // PACKAGE name
        RowLayout{
            Layout.preferredWidth: parent.width / 1.07
            Layout.alignment: Qt.AlignHCenter
            Label{
                text: qsTr("Name of the project  ")

            }
            TextField{
                id: packageName
                Layout.preferredWidth: welcomeColoumn.width / 1.07 - nameApp.paintedWidth
                Layout.alignment: Qt.AlignRight
                text: "org."+configXml.name + ".something"   //configXml.productUrl
            }
        }





        RowLayout{
            Layout.preferredWidth: parent.width / 1.07
            Layout.alignment: Qt.AlignHCenter
            Button{
                text: qsTr("Cancel")
                Layout.preferredWidth: parent.width / 2.27
            }
            Button{
                text: qsTr("Next")
                Layout.preferredWidth: parent.width / 2.27
                Layout.alignment: Qt.AlignHCenter
                onClicked:{
                    // we need a error checker to make sure that the manditory
                    // properys are set.
                    var Already = domWriter.dirExists(outDir.text+ "/"+appName.text +"/config")
                    console.log(Already)
                    if( Already === true ){
                        console.log("Dir is there maybe remove or alter ?")
                        errorDialog.open();
                    }else{
                        domWriter.mkDefaultDirs( outDir.text+"/"+ appName.text
                                                 ,"packages/"+ packageName.text
                                                 ,appName.text
                                                )

//                        domWriter.writeConfigPage(outDir.text+ "/"+appName.text +"/config/")
                    }
                }
            }
        }
    }







    function checkManditory(){
        var manditoryList = [sourcecodeDir.text ,startMenuName.text ];
        for (var i = 0 ; i < manditoryList.length; i++){
            isManEmpty(i,manditoryList[i],true)
        }
    }


    function isManEmpty(id,str,man){
          var currentCheck = "";
        if (str.length <= 0 && man === true){
                   switch(id){
                   case 0:
                       currentCheck = "Source Code Directory"
                       break
                   }
               console.log("Here is a error on the element " + str + " It must be set" + currentCheck)
               }
               else if (str.length > 0 && man === true){
                   console.log(str + " Has been set to " + str.length)
               }
    }


    function isEmpty(str){
        var stdErr = "NaN"
        if(str.length <= 0){
            return stdErr;
        }else{
           console.log(str);
        }
    }



    // FOXME handle with C++
function setAllElements(){
    // First thing we do is make a default templete for config.xml
    //FIXME This SHOULD HAPPEN BEFORE THIS
    domWriter.writeInstallerPage();


    console.log( "Writing Config.xml file" )
    configXml.name = isEmpty(str)
    configXml.version = isEmpty(str)
    configXml.title = isEmpty(str)
    configXml.publisher = isEmpty(str)
    configXml.productUrl = isEmpty(str)
    configXml.icon = isEmpty(str)
    configXml.installerApplicationIcon = isEmpty(str)
    configXml.installerWindowIcon = isEmpty(str)
    configXml.logo = isEmpty(str)
    configXml.watermark = isEmpty(str)
    configXml.banner = isEmpty(str)
    configXml.background = isEmpty(str)
    configXml.wizardStyle = isEmpty(str)
    configXml.wizardDefaultWidth =  isEmpty(str)
    configXml.wizardDefaultHeight = isEmpty(str)
    configXml.titleColor = isEmpty(str)
    configXml.runProgram = isEmpty(str)
    configXml.runProgramArguments =  isEmpty(str)
    configXml.runProgramDescription = isEmpty(str)
    configXml.startMenuDir = isEmpty(str)
    configXml.targetDir = isEmpty(str)
    configXml.adminTargetDir = isEmpty(str)
    configXml.remoteRepositories = isEmpty(str)
    configXml.maintenanceToolName = isEmpty(str)
    configXml.maintenanceToolIniFile = isEmpty(str)
    configXml.removeTargetDir = isEmpty(str)
    configXml.allowNonAsciiCharacters = isEmpty(str)
    configXml.repositorySettingsPageVisible = isEmpty(str)
    configXml.allowSpaceInPath = isEmpty(str)
    configXml.dependsOnLocalInstallerBinary = isEmpty(str)
    configXml.targetConfigurationFile = isEmpty(str)
    configXml.translations = isEmpty(str)
    configXml.urlQueryString = isEmpty(str)
    configXml.controlScript = isEmpty(str)
    configXml.createLocalRepository = isEmpty(str)

    // Now that we have all the values of the config.xml file lets write it to disk.
    //
}

ConfigXml{ id: configXml }
}
