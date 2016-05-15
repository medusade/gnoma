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
///   File: widget_signals.hpp
///
/// Author: $author$
///   Date: 5/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_WIDGET_SIGNALS_HPP
#define _GNOMA_GTK_WIDGET_SIGNALS_HPP

#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GCallback widget_signal_callback_t;
typedef implement_base widget_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: widget_signalst
///////////////////////////////////////////////////////////////////////
template <class TImplements = widget_signals_implements>
class _EXPORT_CLASS widget_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_widget_signal_destroy(GtkWidget* widget_detached) {
        widget_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_widget_signal_destroy(widget_detached = " << pointer_to_string(widget_detached) << ")...");
        if ((to = widget_signals_forward_to())) {
            to->on_widget_signal_destroy(widget_detached);
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_widget_signal_destroy(widget_detached = " << pointer_to_string(widget_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void widget_signal_destroy_callback
    (GtkWidget* widget_detached, widget_signalst* widget_signals) {
        GNOMA_LOG_MESSAGE_DEBUG("widget_signal_destroy_callback(widget_detached = " << pointer_to_string(widget_detached) << ")...");
        if ((widget_detached) && (widget_signals)) {
            widget_signals->on_widget_signal_destroy(widget_detached);
        } else {
        if ((widget_detached)) {
            GNOMA_LOG_ERROR("unexpected widget_signals == 0");
        } else {
            GNOMA_LOG_ERROR("unexpected widget_detached == 0");
        }
        }
        GNOMA_LOG_MESSAGE_DEBUG("...widget_signal_destroy_callback(widget_detached = " << pointer_to_string(widget_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual widget_signalst* forward_widget_signals(widget_signalst* to) {
        return 0;
    }
    virtual widget_signalst* widget_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef widget_signalst<> widget_signals;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_WIDGET_SIGNALS_HPP
        

