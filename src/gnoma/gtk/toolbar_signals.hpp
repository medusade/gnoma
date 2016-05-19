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
///   File: toolbar_signals.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOLBAR_SIGNALS_HPP
#define _GNOMA_GTK_TOOLBAR_SIGNALS_HPP

#include "gnoma/gtk/toolbar_activate_signals.hpp"
#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GCallback toolbar_signal_callback_t;
typedef implement_base toolbar_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: toolbar_signalst
///////////////////////////////////////////////////////////////////////
template <class TImplements = toolbar_signals_implements>
class _EXPORT_CLASS toolbar_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef toolbar_activate_signalst<toolbar_signalst> activate_signals_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_toolbar_signal_activate
    (GtkWidget* toolbar_detached, gint activate_id) {
        toolbar_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_toolbar_signal_activate(toolbar_detached = " << pointer_to_string(toolbar_detached) << ")...");
        if ((to = toolbar_signals_forward_to())) {
            to->on_toolbar_signal_activate(toolbar_detached, activate_id);
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_toolbar_signal_activate(toolbar_detached = " << pointer_to_string(toolbar_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void toolbar_signal_activate_callback
    (GtkToolItem* toolitem_detached, activate_signals_t* activate_signals) {
        GNOMA_LOG_MESSAGE_DEBUG("toolbar_signal_activate_callback(toolitem_detached = " << pointer_to_string(toolitem_detached) << ")...");
        if ((toolitem_detached) && (activate_signals)) {
            gint id = activate_signals->id;
            toolbar_signalst* to = activate_signals->to;
            GtkWidget* toolbar = activate_signals->toolbar;
            if ((to) && (toolbar)) {
                to->on_toolbar_signal_activate(toolbar, id);
            } else {
                if ((toolbar)) {
                    GNOMA_LOG_ERROR("unexpected activate_signals->to == 0");
                } else {
                    GNOMA_LOG_ERROR("unexpected activate_signals->toolbar == 0");
                }
            }
        } else {
            if ((toolitem_detached)) {
                GNOMA_LOG_ERROR("unexpected activate_signals == 0");
            } else {
                GNOMA_LOG_ERROR("unexpected toolitem_detached == 0");
            }
        }
        GNOMA_LOG_MESSAGE_DEBUG("...toolbar_signal_activate_callback(toolitem_detached = " << pointer_to_string(toolitem_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual toolbar_signalst* forward_toolbar_signals(toolbar_signalst* to) {
        return 0;
    }
    virtual toolbar_signalst* toolbar_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef toolbar_signalst<> toolbar_signals;
typedef toolbar_signals::activate_signals_t toolbar_activate_signals;
typedef std::list<toolbar_activate_signals> toolbar_activate_signals_list;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOLBAR_SIGNALS_HPP
        

