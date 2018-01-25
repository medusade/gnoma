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
#   File: gnoma.pri
#
# Author: $author$
#   Date: 5/7/2016
########################################################################
GNOMA_PKG = ../../../../..
GNOMA_BLD = ../..
GNOMA_PRJ = $${GNOMA_PKG}
GNOMA_BIN = $${GNOMA_BLD}/bin
GNOMA_LIB = $${GNOMA_BLD}/lib
GNOMA_SRC = $${GNOMA_PKG}/src

CONFIG(debug, debug|release) {
GNOMA_CONFIG = Debug
BUILD_CONFIG = Debug
gnoma_DEFINES += DEBUG_BUILD
} else {
GNOMA_CONFIG = Release
BUILD_CONFIG = Release
gnoma_DEFINES += RELEASE_BUILD
}

########################################################################
# nadir
NADIR_PKG = $${GNOMA_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \
NO_USE_XOS_LOGGER_INTERFACE \

nadir_LIBS += \

########################################################################
# lamna
LAMNA_PKG = $${GNOMA_PKG}/../lamna
LAMNA_PRJ = $${LAMNA_PKG}
LAMNA_SRC = $${LAMNA_PKG}/src

lamna_INCLUDEPATH += \
$${LAMNA_SRC} \

lamna_DEFINES += \

lamna_LIBS += \

########################################################################
# gnoma
gnoma_INCLUDEPATH += \
$${GNOMA_SRC} \
$${nadir_INCLUDEPATH} \

gnoma_DEFINES += \
$${nadir_DEFINES} \

gnoma_LIBS += \
-L$${GNOMA_LIB}/libgnoma \
-lgnoma \

