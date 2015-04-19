import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Time Tracker")
    width: 640
    height: 300
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.fill: parent
        saveButton.onClicked: {
            if(activity.editText != '') {
                timeTracker.saveActivity(activity.editText, description.text, timeSpent.value);
                Qt.quit();
            } else {
                messageDialog.show("Activity name can't be blank");
            }
        }

        Keys.onPressed: {
           switch (event.key) {
           case Qt.Key_Escape:
                   Qt.quit();
               break;
           }
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("Notification")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

}

