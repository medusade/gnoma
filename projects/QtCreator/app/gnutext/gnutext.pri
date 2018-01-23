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
#   File: gnutext.pri
#
# Author: $author$
#   Date: 5/16/2016
########################################################################

gnutext_INCLUDEPATH += \
$${gnoma_INCLUDEPATH} \

gnutext_DEFINES += \
$${gnoma_DEFINES} \

########################################################################
gnutext_HEADERS += \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/main.hpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/window.hpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/bars.hpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/panels.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_window_main.hpp \
$${GNOMA_SRC}/gnoma/gtk/application_window.hpp \
$${GNOMA_SRC}/gnoma/gtk/scrolled_window.hpp \
$${GNOMA_SRC}/gnoma/gtk/window.hpp \
$${GNOMA_SRC}/gnoma/gtk/paned.hpp \
$${GNOMA_SRC}/gnoma/gtk/box.hpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar.hpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar_activate_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/tool_button.hpp \
$${GNOMA_SRC}/gnoma/gtk/tool_item.hpp \
$${GNOMA_SRC}/gnoma/gtk/tool_separator.hpp \
$${GNOMA_SRC}/gnoma/gtk/search_bar.hpp \
$${GNOMA_SRC}/gnoma/gtk/search_entry.hpp \
$${GNOMA_SRC}/gnoma/gtk/search_entry_signals.hpp \
$${GNOMA_SRC}/gnoma/gtk/places_sidebar.hpp \
$${GNOMA_SRC}/gnoma/gtk/image.hpp \
$${GNOMA_SRC}/gnoma/gtk/widget.hpp \
$${GNOMA_SRC}/gnoma/gtk/gtk.hpp \
$${GNOMA_SRC}/gnoma/gdk/pixbuf.hpp \
$${GNOMA_SRC}/gnoma/gdk/gdk.hpp \
$${GNOMA_SRC}/gnoma/glib/glib.hpp \
$${GNOMA_SRC}/gnoma/console/main.hpp \
$${GNOMA_SRC}/gnoma/console/main_main.hpp \
$${GNOMA_SRC}/gnoma/console/main_opt.hpp \

gnutext_SOURCES += \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/main.cpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/window.cpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/bars.cpp \
$${GNOMA_SRC}/gnoma/app/gtk/gnutext/panels.cpp \
$${GNOMA_SRC}/gnoma/gtk/scrolled_window.cpp \
$${GNOMA_SRC}/gnoma/gtk/paned.cpp \
$${GNOMA_SRC}/gnoma/gtk/box.cpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar.cpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar_signals.cpp \
$${GNOMA_SRC}/gnoma/gtk/toolbar_activate_signals.cpp \
$${GNOMA_SRC}/gnoma/gtk/tool_button.cpp \
$${GNOMA_SRC}/gnoma/gtk/tool_item.cpp \
$${GNOMA_SRC}/gnoma/gtk/tool_separator.cpp \
$${GNOMA_SRC}/gnoma/gtk/search_bar.cpp \
$${GNOMA_SRC}/gnoma/gtk/search_entry.cpp \
$${GNOMA_SRC}/gnoma/gtk/search_entry_signals.cpp \
$${GNOMA_SRC}/gnoma/gtk/places_sidebar.cpp \
$${GNOMA_SRC}/gnoma/gtk/image.cpp \
$${GNOMA_SRC}/gnoma/gdk/pixbuf.cpp \
$${GNOMA_SRC}/gnoma/gdk/gdk.cpp \
$${GNOMA_SRC}/gnoma/console/main_main.cpp \
$${GNOMA_SRC}/gnoma/console/main_opt.cpp \

########################################################################

gnutext_LIBS += \


