/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#include <QHostInfo>

#endif

#include <sailfishapp.h>

//extern "C"{
//#include "ontology/ontology.h"
//}

int main(int argc, char *argv[])
{

    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).

//    sslog_node_t *node;
//    sslog_init();

//    register_ontology();

//    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)){

//            QString myIp =  address.toString();
//            QByteArray ar = myIp.toLocal8Bit();
//            char *addr = ar.data();
//            qDebug() << addr;
//            // Initialize smart space information.
//            ss_info_t **infos = ss_discovery(NULL, 0);
//            qDebug() << "1";
//            if (infos == NULL) {
//                qDebug() << "No SIBs around KP :(";
//            } else {
//                qDebug() << "2";
//                int infos_index = 0;
//                qDebug() << "3";
//                ss_info_t *info = infos[infos_index];
//                qDebug() << "4";
//                while (info != NULL)
//                {
//                    qDebug() << "SS Info for " << info->space_id << " Address: " << info->address.ip << " Port: " << info->address.port ;
//                    ++infos_index;
//                    info = infos[infos_index];
//                }
//            }

//        }
//    }



    //QQmlEngine engine;
    //engine.addImportPath("qrc:///");
    return SailfishApp::main(argc, argv);
}
