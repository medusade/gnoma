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
%#   File: gnoma-created-hxx.t
%#
%# Author: $author$
%#   Date: 5/11/2016
%########################################################################
%with(%
%extension,%(%else-then(%extension%,%(hpp)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%hpp,%(%equal(hpp,%Extension%)%%equal(hxx,%Extension%)%%equal(h,%Extension%)%)%,%
%framework,%(%else-then(%framework%,%(Gnoma)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%kit,%(%else-then(%kit%,%(Gdk)%)%)%,%
%Kit,%(%else-then(%Kit%,%(%kit%)%)%)%,%
%KIT,%(%else-then(%KIT%,%(%toupper(%Kit%)%)%)%)%,%
%kit,%(%else-then(%_Kit%,%(%tolower(%Kit%)%)%)%)%,%
%class,%(%else-then(%class%,%(Class)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%attached,%(%else-then(%attached%,%(Attached)%)%)%,%
%Attached,%(%else-then(%Attached%,%(%attached%)%)%)%,%
%ATTACHED,%(%else-then(%ATTACHED%,%(%toupper(%Attached%)%)%)%)%,%
%attached,%(%else-then(%_Attached%,%(%tolower(%Attached%)%)%)%)%,%
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
///   File: %class%.%extension%
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(#ifndef _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%
#define _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%

#include "%framework%/%kit%/%kit%.hpp")%,%(#include "%framework%/%kit%/%class%.hpp")%)%

namespace %framework% {
namespace %kit% {

%if(%hpp%,%(typedef %Attached%* %Class%_attached_t;
typedef xos::base::creatort<implement_base> %Class%_creator;
typedef xos::base::attachert<%Class%_attached_t, int, 0, %Class%_creator> %Class%_attacher;
typedef xos::base::attachedt<%Class%_attached_t, int, 0, %Class%_attacher, base> %Class%_attached;
typedef xos::base::createdt<%Class%_attached_t, int, 0, %Class%_attacher, %Class%_attached> %Class%_created;
typedef %Class%_attacher %Class%_implements;
typedef %Class%_created %Class%_extends;
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
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("%kit%_%Class%_new()...");
        if ((detached = %kit%_%Class%_new())) {
            %FRAMEWORK%_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = %kit%_%Class%_new()");
        } else {
            %FRAMEWORK%_LOG_ERROR("...failed 0 = %kit%_%Class%_new()");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            %FRAMEWORK%_LOG_MESSAGE_DEBUG("...%kit%_%Class%_destroy(" << gpointer_to_string(detached) << ")");
            %kit%_%Class%_destroy(detached);
            return true;
        }
        return false;
    }
    virtual operator attached_t() const {
        attached_t detached = this->attached_to();
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %Class%t<> %Class%;)%)%

} // namespace %kit%
} // namespace %framework%

%if(%hpp%,%(#endif // _%FRAMEWORK%_%KIT%_%CLASS%_%EXTENSION%
)%)%%
%)%)%        

