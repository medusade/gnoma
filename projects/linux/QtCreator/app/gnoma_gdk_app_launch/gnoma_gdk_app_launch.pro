########################################################################
# Copyright (c) 1988-2016 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: gnoma_gdk_app_launch.pro
#
# Author: $author$
#   Date: 5/9/2016
########################################################################
include(../../../../../build/QtCreator/gtk.pri)
include(../../gtk.pri)
include(../../../../QtCreator/gnoma.pri)
include(../../gnoma.pri)
include(../../../../QtCreator/app/gnoma_gdk_app_launch/gnoma_gdk_app_launch.pri)

TARGET = gnoma_gdk_app_launch

INCLUDEPATH += \
$${gnoma_INCLUDEPATH} \

DEFINES += \
$${gnoma_DEFINES} \

########################################################################
HEADERS += \
$${gnoma_gdk_app_launch_HEADERS} \

SOURCES += \
$${gnoma_gdk_app_launch_SOURCES} \

########################################################################
LIBS += \
$${gnoma_LIBS} \
