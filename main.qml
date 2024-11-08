import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 1324
    height: 700
    visible: true
    title: qsTr("Liker")
    color: "black"
    Component.onCompleted: {
        showFullScreen()
    }
    Rectangle {
        id: topBar
        width: parent.width
        height: parent.height * 0.05
        color: "white"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        RowLayout {
            width: parent.width
            height: parent.height
            spacing: 15
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "HOME/REFRESH"
                font.pixelSize: 23
                font.bold: false

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        manager.onHomeClicked()
                        btn1.color = "pink"
                        btn2.color = "white"
                        btn3.color = "white"
                        btn4.color = "white"
                    }
                }

                Rectangle {
                    id: btn1
                    width: 5
                    color: "white"
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: -15
                    radius: 15
                }
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "ABOUT"
                font.pixelSize: 24
                font.bold: false
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        manager.onAboutClicked()
                        btn2.color = "pink"
                        btn1.color = "white"
                        btn3.color = "white"
                        btn4.color = "white"
                    }
                }

                Rectangle {
                    id: btn2
                    width: 5
                    color: "white"
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: -15
                    radius: 15
                }
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "QUIT"
                font.pixelSize: 24
                font.bold: false
                verticalAlignment: Text.AlignVCenter
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        manager.onQuitClicked()
                        btn3.color = "pink"
                        btn2.color = "white"
                        btn1.color = "white"
                        btn4.color = "white"
                    }
                }

                Rectangle {
                    id: btn3
                    width: 5
                    color: "white"
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: -15
                    radius: 15
                }
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "PROFILE"
                font.family: "Segoe UI Black"
                font.pixelSize: 24
                font.bold: false
                verticalAlignment: Text.AlignVCenter
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        manager.onProfileClicked()
                        btn4.color = "pink"
                        btn2.color = "white"
                        btn3.color = "white"
                        btn1.color = "white"
                    }
                }

                Rectangle {
                    id: btn4
                    width: 5
                    color: "white"
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: -15
                    radius: 15
                }
            }
        }
    }
    Rectangle {
        id: bottomBar
        width: parent.width
        height: parent.height - topBar.height
        color: "pink"
        anchors.top: topBar.bottom
        Rectangle {
            id: main
            color: "white"
            radius: 16
            width: parent.width * 0.6
            height: parent.height * 0.3
            anchors.centerIn: parent

            Text {
                text: manager.String
                font.pixelSize: 18
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                wrapMode: Text.WrapAnywhere
            }
            RowLayout {
                spacing: 25
                anchors.top: main.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 25

                RoundButton {

                    text: "❤️"
                    font.bold: false
                    font.pixelSize: 24
                    leftPadding: 25
                    rightPadding: 25
                }

                RoundButton {
                    text: "✓"

                    flat: false
                    font.bold: false
                    font.pixelSize: 24
                    leftPadding: 25
                    rightPadding: 25
                }

                RoundButton {
                    text: "№"
                    flat: false
                    font.bold: false
                    font.pixelSize: 24
                    leftPadding: 25
                    rightPadding: 25
                }
            }
        }
    }
}
