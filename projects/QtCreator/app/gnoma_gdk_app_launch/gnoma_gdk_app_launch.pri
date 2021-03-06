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
#   File: gnoma_gdk_app_launch.pri
#
# Author: $author$
#   Date: 5/9/2016
########################################################################

gnoma_gdk_app_launch_INCLUDEPATH += \

gnoma_gdk_app_launch_DEFINES += \

########################################################################
gnoma_gdk_app_launch_HEADERS += \
$${GNOMA_SRC}/gnoma/samples/gdk/app_launch/main.hpp \
$${GNOMA_SRC}/gnoma/gdk/app_launch_context.hpp \
$${GNOMA_SRC}/gnoma/gdk/main.hpp \
$${GNOMA_SRC}/gnoma/gdk/window.hpp \
$${GNOMA_SRC}/gnoma/gdk/window_attr.hpp \
$${GNOMA_SRC}/gnoma/gdk/display.hpp \
$${GNOMA_SRC}/gnoma/gdk/screen.hpp \
$${GNOMA_SRC}/gnoma/console/main.hpp \
$${GNOMA_SRC}/gnoma/console/main_main.hpp \
$${GNOMA_SRC}/gnoma/console/main_opt.hpp \

gnoma_gdk_app_launch_SOURCES += \
$${GNOMA_SRC}/gnoma/samples/gdk/app_launch/main.cpp \
$${GNOMA_SRC}/gnoma/gdk/app_launch_context.cpp \
$${GNOMA_SRC}/gnoma/gdk/window.cpp \
$${GNOMA_SRC}/gnoma/gdk/window_attr.cpp \
$${GNOMA_SRC}/gnoma/gdk/display.cpp \
$${GNOMA_SRC}/gnoma/gdk/screen.cpp \
$${GNOMA_SRC}/gnoma/console/main_main.cpp \
$${GNOMA_SRC}/gnoma/console/main_opt.cpp \

########################################################################
gnoma_gdk_app_launch_LIBS += \

