import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import Limbo.Test 1.0

Window{
    id:mm
    title: "Chaos"
    width: 580; height: 500

    visible: true

    MCtrl{id:mt}

    function ad11(){      
        bar.value=bar.value+0.001;
    if(bar.value==1)
    {bar.value=0;}
    }


    Item {
        Timer {
            id:timer1;
            interval: 10; running: true; repeat: true
            onTriggered: ad11();
        }
    }

ListModel {
   id: libraryModel
   ListElement{ title: "A Masterpiece" ; author: "Gabriel" }
   ListElement{ title: "Brilliance"    ; author: "Jens" }
   ListElement{ title: "Outstanding"   ; author: "Frederik" }
}


TableView {
   Keys.onSpacePressed:  {
       mm.alert(1000)
       if (timer1.running==true){
           timer1.stop();
       }
       else{
           timer1.start();
       }
   }
   focus: true
   id:tableview
   width:mm.width
   TableViewColumn{ role: "1"  ; title: "1" ; width: mm.width/6 }
   TableViewColumn{ role: "2" ; title: "2" ; width: mm.width/6 }
   TableViewColumn{ role: "3"  ; title: "3" ; width: mm.width/6 }
   TableViewColumn{ role: "4" ; title: "4" ; width: mm.width/6 }
   TableViewColumn{ role: "5"  ; title: "5" ; width: mm.width/6 }
   TableViewColumn{ role: "6" ; title: "6" ; width: mm.width/6 }
   model: ats
}

    ProgressBar {
        id:bar
       anchors.top:tableview.bottom
       width:mm.width
      value:0
    }

    GridView {
        width: mm.width
        height: 500
       anchors.top:bar.bottom
      // anchors.fill: parent
       model: ats
       delegate: Rectangle {
          Text {
             text: display;
          }
       }
    }

}

