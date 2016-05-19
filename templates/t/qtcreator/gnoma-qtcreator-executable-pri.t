%########################################################################
%# Copyright (c) 1988-2016 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: gnoma-qtcreator-executable-pri.t
%#
%# Author: $author$
%#   Date: 5/16/2016
%########################################################################
%with(%
%app,%(%else-then(%app%,%(App)%)%)%,%
%App,%(%else-then(%App%,%(%app%)%)%)%,%
%APP,%(%else-then(%APP%,%(%toupper(%App%)%)%)%)%,%
%app,%(%else-then(%_App%,%(%tolower(%App%)%)%)%)%,%
%target,%(%else-then(%target%,%(%App%)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%file,%(%else-then(%file%,%(%App%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%extension,%(%else-then(%extension%,%(pri)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(gnoma)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%kit,%(%else-then(%kit%,%(Kit)%)%)%,%
%Kit,%(%else-then(%Kit%,%(%kit%)%)%)%,%
%KIT,%(%else-then(%KIT%,%(%toupper(%Kit%)%)%)%)%,%
%kit,%(%else-then(%_Kit%,%(%tolower(%Kit%)%)%)%)%,%
%%(%
%########################################################################
# Copyright (c) 1988-%year()% $organization$
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
#   File: %File%.%Extension%
#
# Author: $author$
#   Date: %date()%
########################################################################

%App%_INCLUDEPATH += \

%App%_DEFINES += \

########################################################################
%App%_HEADERS += \
$${%FRAMEWORK%_SRC}/%Framework%/console/main.hpp \
$${%FRAMEWORK%_SRC}/%Framework%/console/main_main.hpp \
$${%FRAMEWORK%_SRC}/%Framework%/console/main_opt.hpp \

%App%_SOURCES += \
$${%FRAMEWORK%_SRC}/%Framework%/console/main_main.cpp \
$${%FRAMEWORK%_SRC}/%Framework%/console/main_opt.cpp \

########################################################################

%App%_LIBS += \

%
%)%)%
