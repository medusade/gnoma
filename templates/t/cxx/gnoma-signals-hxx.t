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
%callback,%(%else-then(%callback%,%(Callback)%)%)%,%
%Callback,%(%else-then(%Callback%,%(%callback%)%)%)%,%
%CALLBACK,%(%else-then(%CALLBACK%,%(%toupper(%Callback%)%)%)%)%,%
%callback,%(%else-then(%_Callback%,%(%tolower(%Callback%)%)%)%)%,%
%signals,%(%else-then(%signals%,%(Signals)%)%)%,%
%Signals,%(%else-then(%Signals%,%(%signals%)%)%)%,%
%SIGNALS,%(%else-then(%SIGNALS%,%(%toupper(%Signals%)%)%)%)%,%
%signals,%(%else-then(%_Signals%,%(%tolower(%Signals%)%)%)%)%,%
%return,%(%else-then(%return%,%(void)%)%)%,%
%Return,%(%else-then(%Return%,%(%return%)%)%)%,%
%RETURN,%(%else-then(%RETURN%,%(%toupper(%Return%)%)%)%)%,%
%return,%(%else-then(%_Return%,%(%tolower(%Return%)%)%)%)%,%
%return_type,%(%else-then(%return_type%,%(%else-then(%left(%Return%,=)%,%(%Return%)%)%)%)%)%,%
%Return_type,%(%else-then(%Return_type%,%(%return_type%)%)%)%,%
%RETURN_TYPE,%(%else-then(%RETURN_TYPE%,%(%toupper(%Return_type%)%)%)%)%,%
%return_type,%(%else-then(%_Return_type%,%(%tolower(%Return_type%)%)%)%)%,%
%return_value,%(%else-then(%return_value%,%(%else-then(%right(%Return%,=)%,%()%)%)%)%)%,%
%Return_value,%(%else-then(%Return_value%,%(%return_value%)%)%)%,%
%RETURN_VALUE,%(%else-then(%RETURN_VALUE%,%(%toupper(%Return_value%)%)%)%)%,%
%return_value,%(%else-then(%_Return_value%,%(%tolower(%Return_value%)%)%)%)%,%
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
///   File: %class%_signals.%extension%
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(#ifndef _%FRAMEWORK%_%KIT%_%CLASS%_SIGNALS_%EXTENSION%
#define _%FRAMEWORK%_%KIT%_%CLASS%_SIGNALS_%EXTENSION%

#include "%framework%/%kit%/%kit%.hpp")%,%(#include "%framework%/%kit%/%class%_signals.hpp")%)%

namespace %framework% {
namespace %kit% {

%if(%hpp%,%(typedef %Callback% %Class%_signal_callback_t;
typedef implement_base %Class%_signals_implements;
)%)%///////////////////////////////////////////////////////////////////////
///  Class: %Class%_signalst
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(template <class TImplements = %Class%_implements>
class _EXPORT_CLASS %Class%_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    %parse(%Signals%,;,,,,%(///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual %Return_type% on_%Class%_signal_%Signal%(%Attached%* %Class%_detached) {
        %else(%equal(void,%Return_type%)%,%(%Return_type% result = %Return_value%;
        %)%)%%Class%_signalst* to = 0;
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("on_%Class%_signal_%Signal%(%Class%_detached = " << pointer_to_string(%Class%_detached) << ")...");
        if ((to = %Class%_signals_forward_to())) {
            %else(%equal(void,%Return_type%)%,%(result = )%)%to->on_%Class%_signal_%Signal%(%Class%_detached);
        }
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("...on_%Class%_signal_%Signal%(%Class%_detached = " << pointer_to_string(%Class%_detached) << ")");%
%%else(%equal(void,%Return_type%)%,%(
        return result)%)%
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static %Return_type% %Class%_signal_%Signal%_callback
    (%Attached%* %Class%_detached, %Class%_signalst* %Class%_signals) {
        %else(%equal(void,%Return_type%)%,%(%Return_type% result = %Return_value%;
        %)%)%%FRAMEWORK%_LOG_MESSAGE_DEBUG("%Class%_signal_%Signal%_callback(%Class%_detached = " << pointer_to_string(%Class%_detached) << ")...");
        if ((%Class%_detached) && (%Class%_signals)) {
            %else(%equal(void,%Return_type%)%,%(result = )%)%to->on_%Class%_signal_%Signal%(%Class%_detached);
        } else {
        if ((%Class%_detached)) {
            %FRAMEWORK%_LOG_ERROR("unexpected %Class%_signals == 0");
        } else {
            %FRAMEWORK%_LOG_ERROR("unexpected %Class%_detached == 0");
        }
        }
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("...%Class%_signal_%Signal%_callback(%Class%_detached = " << pointer_to_string(%Class%_detached) << ")");%
%%else(%equal(void,%Return_type%)%,%(
        return result)%)%
    }
    )%,Signal)%///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual %Class%_signalst* forward_%Class%_signals(%Class%_signalst* to) {
        return 0;
    }
    virtual %Class%_signalst* %Class%_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %Class%_signalst<> %Class%_signals;)%)%

} // namespace %kit%
} // namespace %framework%

%if(%hpp%,%(#endif // _%FRAMEWORK%_%KIT%_%CLASS%_SIGNALS_%EXTENSION%
)%)%%
%)%)%        

