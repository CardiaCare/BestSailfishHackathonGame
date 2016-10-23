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

#include <QtQuick>
#include <QHostInfo>

#include <sailfishapp.h>
#include "Game.hpp"

extern "C"{
#include "ontology/ontology.h"
}

void MyClass::cppSlot(const QString &msg)
{
   qDebug() << "Called the C++ slot with message:" << msg;
}

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
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    sslog_node_t *node;

    node = sslog_new_node("PlayerKP", "X", "78.46.130.194", 10010);
    sslog_node_join(node);

    sslog_init();

    register_ontology();


    
    // getOpponentEntities
    // Subscibe to changes


    //    sslog_individual_t *player = sslog_new_individual(CLASS_GAMER);

    //    sslog_node_insert_individual(node, player);

    //    sslog_subscription_t *virus_subscription = sslog_new_subscription(node, true);
    //    sslog_sbcr_add_class(virus_subscription, CLASS_VIRUS);

    //    sslog_subsction_t *particles_subscription = sslog_new_subscription(node, true);
    //    sslog_sbcr_add_class(particles_subscription, CLASS_PARTICLE);





    /*
     * Publish Player
     * Publish its viruses
     * When particle sent Publish Particle and its charge
     * When particle reach destination Update property Score
     * Subscribe to particles and viruses (SIGNAL)
     *
     */

   QScopedPointer<QQmlComponent> component(SailfishApp::createView());
   QObject *item = view.rootObject();

   MyClass myClass;
   QObject::connect(item, SIGNAL(qmlSignal(QString)),
                    &myClass, SLOT(cppSlot(QString)));


    QScopedPointer<QQuickView> v(SailfishApp::createView());
    v->setSource(QUrl("qrc:///qml/Game.qml"));
    v->show();
    return app->exec();

 //   return SailfishApp::main(argc, argv);
}

void getOpponentEntities()
{




}
