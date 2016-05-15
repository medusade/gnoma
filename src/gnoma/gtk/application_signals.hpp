///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: application_signals.hpp
///
/// Author: $author$
///   Date: 5/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_APPLICATION_SIGNALS_HPP
#define _GNOMA_GTK_APPLICATION_SIGNALS_HPP

#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GCallback application_signal_callback_t;
typedef implement_base application_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: application_signalst
///////////////////////////////////////////////////////////////////////
template <class TImplements = application_signals_implements>
class _EXPORT_CLASS application_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_application_signal_activate(GtkApplication* application_detached) {
        application_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_application_signal_activate(application_detached = " << pointer_to_string(application_detached) << ")...");
        if ((to = application_signals_forward_to())) {
            to->on_application_signal_activate(application_detached);
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_application_signal_activate(application_detached = " << pointer_to_string(application_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void application_signal_activate_callback
    (GtkApplication* application_detached, application_signalst* application_signals) {
        GNOMA_LOG_MESSAGE_DEBUG("application_signal_activate_callback(application_detached = " << pointer_to_string(application_detached) << ")...");
        if ((application_detached) && (application_signals)) {
            application_signals->on_application_signal_activate(application_detached);
        } else {
        if ((application_detached)) {
            GNOMA_LOG_ERROR("unexpected application_signals == 0");
        } else {
            GNOMA_LOG_ERROR("unexpected application_detached == 0");
        }
        }
        GNOMA_LOG_MESSAGE_DEBUG("...application_signal_activate_callback(application_detached = " << pointer_to_string(application_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual application_signalst*
    forward_application_signals(application_signalst* to) {
        return 0;
    }
    virtual application_signalst* application_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef application_signalst<> application_signals;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_APPLICATION_SIGNALS_HPP
        

