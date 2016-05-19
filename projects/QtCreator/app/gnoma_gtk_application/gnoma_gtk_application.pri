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
#   File: gnoma_gtk_application.pri
#
# Author: $author$
#   Date: 5/13/2016
########################################################################

gnoma_gtk_application_INCLUDEPATH += \

gnoma_gtk_application_DEFINES += \

########################################################################
_gnoma_gtk_application_HEADERS += \

gnoma_gtk_application_HEADERS += \
$${GNOMA_SRC}/gnoma/samples/gtk/application/main.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_window_main.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_window.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_main.hpp \
$${GNOMA_SRC}/gnoma/gtk/application.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/main.hpp \
$${GNOMA_SRC}/gnoma/gtk/window.hpp \
$${GNOMA_SRC}/gnoma/gtk/widget.hpp \
$${GNOMA_SRC}/gnoma/gtk/widget_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/gtk.hpp \
$${GNOMA_SRC}/gnoma/gdk/gdk.hpp \
$${GNOMA_SRC}/gnoma/glib/glib.hpp \
$${GNOMA_SRC}/gnoma/console/main.hpp \
$${GNOMA_SRC}/gnoma/console/main_main.hpp \
$${GNOMA_SRC}/gnoma/console/main_opt.hpp \

_gnoma_gtk_application_SOURCES += \

gnoma_gtk_application_SOURCES += \
$${GNOMA_SRC}/gnoma/samples/gtk/application/main.cpp \
$${GNOMA_SRC}/gnoma/gtk/application_main.cpp \
$${GNOMA_SRC}/gnoma/gtk/application_window_main.cpp \
$${GNOMA_SRC}/gnoma/gtk/application_window.cpp \
$${GNOMA_SRC}/gnoma/gtk/application.cpp \
$${GNOMA_SRC}/gnoma/gtk/application_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/window.cpp \
$${GNOMA_SRC}/gnoma/gtk/widget.cpp \
$${GNOMA_SRC}/gnoma/gtk/widget_signals.cpp \
$${GNOMA_SRC}/gnoma/console/main_main.cpp \
$${GNOMA_SRC}/gnoma/console/main_opt.cpp \

########################################################################
gnoma_gtk_application_LIBS += \

