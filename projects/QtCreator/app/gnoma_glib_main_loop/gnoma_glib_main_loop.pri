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
#   File: gnoma_glib_main_loop.pri
#
# Author: $author$
#   Date: 5/7/2016
########################################################################

gnoma_glib_main_loop_INCLUDEPATH += \

gnoma_glib_main_loop_DEFINES += \

########################################################################
gnoma_glib_main_loop_HEADERS += \
$${GNOMA_SRC}/gnoma/samples/glib/main_loop/main.hpp \
$${GNOMA_SRC}/gnoma/glib/main_loop.hpp \
$${GNOMA_SRC}/gnoma/glib/main_context.hpp \
$${GNOMA_SRC}/gnoma/glib/source.hpp \
$${GNOMA_SRC}/gnoma/console/main_main.hpp \
$${GNOMA_SRC}/gnoma/console/main_opt.hpp \

gnoma_glib_main_loop_SOURCES += \
$${GNOMA_SRC}/gnoma/samples/glib/main_loop/main.cpp \
$${GNOMA_SRC}/gnoma/glib/main_loop.cpp \
$${GNOMA_SRC}/gnoma/glib/main_context.cpp \
$${GNOMA_SRC}/gnoma/glib/source.cpp \
$${GNOMA_SRC}/gnoma/console/main_main.cpp \
$${GNOMA_SRC}/gnoma/console/main_opt.cpp \

########################################################################
gnoma_glib_main_loop_LIBS += \

