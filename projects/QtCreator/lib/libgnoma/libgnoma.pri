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
#   File: libgnoma.pri
#
# Author: $author$
#   Date: 5/7/2016
########################################################################

libgnoma_INCLUDEPATH += \
$${gnoma_INCLUDEPATH} \

libgnoma_DEFINES += \
$${gnoma_DEFINES} \

libgnoma_HEADERS += \
$${GNOMA_SRC}/gnoma/gtk/gtk.hpp \
$${GNOMA_SRC}/gnoma/gdk/gdk.hpp \
$${GNOMA_SRC}/gnoma/glib/object.hpp \
$${GNOMA_SRC}/gnoma/glib/boxed.hpp \
$${GNOMA_SRC}/gnoma/glib/glib.hpp \
$${GNOMA_SRC}/gnoma/io/logger.hpp \
$${GNOMA_SRC}/gnoma/base/base.hpp \

libgnoma_SOURCES += \
$${GNOMA_SRC}/gnoma/gtk/gtk.hpp \
$${GNOMA_SRC}/gnoma/gdk/gdk.hpp \
$${GNOMA_SRC}/gnoma/glib/object.cpp \
$${GNOMA_SRC}/gnoma/glib/boxed.cpp \
$${GNOMA_SRC}/gnoma/glib/glib.cpp \
$${GNOMA_SRC}/gnoma/io/logger.cpp \
$${GNOMA_SRC}/gnoma/base/base.cpp \

libgnoma_LIBS += \
$${gnoma_LIBS} \
