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
%#   File: gnoma-gtk-widget-hxx.t
%#
%# Author: $author$
%#   Date: 5/16/2016
%########################################################################
%with(%
%class,%(%else-then(%class%,%(Class)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%widget,%(%else-then(%widget%,%(widget)%)%)%,%
%Widget,%(%else-then(%Widget%,%(%widget%)%)%)%,%
%WIDGET,%(%else-then(%WIDGET%,%(%toupper(%Widget%)%)%)%)%,%
%widget,%(%else-then(%_Widget%,%(%tolower(%Widget%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%Widget%_implements)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%Widget%)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%attached,%(%else-then(%attached%,%(GtkWidget)%)%)%,%
%Attached,%(%else-then(%Attached%,%(%attached%)%)%)%,%
%ATTACHED,%(%else-then(%ATTACHED%,%(%toupper(%Attached%)%)%)%)%,%
%attached,%(%else-then(%_Attached%,%(%tolower(%Attached%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Class%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%extension,%(%else-then(%extension%,%(hpp)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%hpp,%(%equal(hpp,%Extension%)%%equal(hxx,%Extension%)%%equal(h,%Extension%)%)%,%
%framework,%(%else-then(%framework%,%(gnoma)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%kit,%(%else-then(%kit%,%(gtk)%)%)%,%
%Kit,%(%else-then(%Kit%,%(%kit%)%)%)%,%
%KIT,%(%else-then(%KIT%,%(%toupper(%Kit%)%)%)%)%,%
%kit,%(%else-then(%_Kit%,%(%tolower(%Kit%)%)%)%)%,%
%KIT,%(%parse(%KIT%,/,,_)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: %File%.%Extension%
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(#ifndef _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%
#define _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%

#include "%Framework%/%Kit%/%Extends%.hpp")%,%(#include "%Framework%/%Kit%/%Class%.hpp")%)%

namespace %Framework% {
%parse(%Kit%,/,,
,,%(namespace %Kit% {)%,Kit)%

%if(%hpp%,%(typedef %Implements% %Class%_implements;
typedef %Extends% %Class%_extends;
)%)%///////////////////////////////////////////////////////////////////////
///  Class: %Class%t
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(template
<class TImplements = %Class%_implements, class TExtends = %Class%_extends>
class _EXPORT_CLASS %Class%t
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %Class%t
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~%Class%t() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((detached = create_detached())) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("%Kit%_%Class%_new()...");
        if ((detached = %Kit%_%Class%_new())) {
            %FRAMEWORK%_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = %Kit%_%Class%_new()");
        } else {
            %FRAMEWORK%_LOG_ERROR("...failed 0 = %Kit%_%Class%_new()");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            %FRAMEWORK%_LOG_MESSAGE_DEBUG("...%Kit%_%Class%_destroy(" << gpointer_to_string(detached) << ")");
            %Kit%_%Class%_destroy(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %Class%t<> %Class%;)%)%

%reverse-parse(%Kit%,/,,
,,%(} // namespace %Kit%)%,Kit)%
} // namespace %Framework%

%if(%hpp%,%(#endif // _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%
)%)%%
%)%)%

