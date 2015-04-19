import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {

    width: 640
    height: 280
    scale: 1

    property alias saveButton: saveButton
    property alias activity: activity
    property alias description: description
    property alias timeSpent: timeSpent

    GridLayout {
        height: 200
        columns: 2
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 10
        columnSpacing: 10
/*
        Label {
            text: "Activity"
        }
        TextField {
            id: activity
            text: ""
            focus: true
            Layout.fillWidth: true
            KeyNavigation.tab: description

        }
*/
        Label {
            text: "Activity"
        }
        ComboBox {
            id: activity
            focus: true
            editable: true
            Layout.fillWidth: true
            model: activityModel
            KeyNavigation.tab: description
            onAccepted: {
                 if (editableCombo.find(currentText) === -1) {
                     model.append({text: editText})
                     currentIndex = editableCombo.find(editText)
                 }
            }
        }

        Label {
            text: "Description"
        }
        TextArea {
            id: description
            text: ""
            Layout.fillWidth: true
            KeyNavigation.tab: timeSpent
        }

        Label {
            text: "Time spent"
        }
        SpinBox {
            id: timeSpent
            stepSize: 0.5
            decimals: 2
            value: 0.5
            suffix: " hours"
            KeyNavigation.tab: saveButton
        }

        Item {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            implicitHeight: saveButton.height

            Button {
                id: saveButton
                activeFocusOnPress: true
                anchors.centerIn: parent
                text: "Accept"

                Keys.onReturnPressed: {
                    if(activity.editText != '') {
                        timeTracker.saveActivity(activity.editText, description.text, timeSpent.value);
                        Qt.quit();
                    } else {
                        messageDialog.show("Activity name can't be blank");
                    }
                }


            }
        }
    }

}
