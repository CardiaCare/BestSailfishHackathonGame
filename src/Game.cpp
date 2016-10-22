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
#endif

#include <sailfishapp.h>
extern "C"{
#include "ontology/ontology.h"
}

typedef struct kp_data_s {
    int port;
    char address[KP_PARAM_MAX_LEN + 1];
} kp_data_t;
static void print_kp_data(kp_data_t *data);
static void init_kp_data(int argc, char **argv, kp_data_t *data);
/**
 * @brief Contains data of the KP.
 */


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
    sslog_node_t *node;
    sslog_init();
    // node = sslog_new_node("KP_Player", "X", "78.46.130.194", 10010);

    register_ontology();
    
    init_kp_data(argc, argv, &kp_data);
    
    print_kp_data(&kp_data);

    char *address = (kp_data.address[0] == '\0') ? NULL : kp_data.address;

    // Initialize smart space information.
    ss_info_t **infos = ss_discovery(address, kp_data.port);

    //QQmlEngine engine;
    //engine.addImportPath("qrc:///");
    return SailfishApp::main(argc, argv);
}

/******************************************************************************/
/***************************** Static functions *******************************/
/**
 * @brief Initializes KP data using parameters or default values.
 * 
 * @param[in] argc Number of parameters
 * @param[in] argv parameter's array.
 * @param[in] data kp data to initialize.
 */
static void init_kp_data(int argc, char **argv, kp_data_t *data)
{
    if (data == NULL) {
        return;
    }

    // Set default values.
    data->port = -1;
    data->address[0] = '\0';

    if (argc < 2 || argv == NULL) {
        return;
    }

    // Start checking parameters after program name.
    for (int i = 1; i + 1 < argc; i += 2) {
        if (argv[i] == NULL) {
            continue;
        }

        if (strncmp(KP_PARAM_SS_ADDRESS, argv[i], KP_PARAM_MAX_LEN) == 0) {
            snprintf(data->address, KP_PARAM_MAX_LEN, "%s", argv[i + 1]);
        } else if (strncmp(KP_PARAM_SS_PORT, argv[i], KP_PARAM_MAX_LEN) == 0) {
            data->port = (int) strtol(argv[i + 1], NULL, 10);
        }
    }
}
/** @brief Prints information about KP. */
static void print_kp_data(kp_data_t *data)
{

    if (data == NULL) {
        return;
    }

    qDebug() << "Adderess: " << data->address << " Port: " << data->port;
}
