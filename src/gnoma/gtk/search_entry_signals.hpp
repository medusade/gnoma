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
///   File: search_entry_signals.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_SEARCH_ENTRY_SIGNALS_HPP
#define _GNOMA_GTK_SEARCH_ENTRY_SIGNALS_HPP

#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GCallback search_entry_signal_callback_t;
typedef gint search_entry_signal_event_mask_t;
typedef implement_base search_entry_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: search_entry_signalst
///////////////////////////////////////////////////////////////////////
template <class TImplements = search_entry_signals_implements>
class _EXPORT_CLASS search_entry_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_search_entry_signal_activate
    (GtkSearchEntry* search_entry_detached, const gchar* chars) {
        search_entry_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_search_entry_signal_activate(search_entry_detached = " << pointer_to_string(search_entry_detached) << ", chars = " << gchars_to_string(chars) << ")...");
        if ((to = search_entry_signals_forward_to())) {
            to->on_search_entry_signal_activate(search_entry_detached, chars);
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_search_entry_signal_activate(search_entry_detached = " << pointer_to_string(search_entry_detached) << ", chars = " << gchars_to_string(chars) << ")");
    }
    virtual void on_search_entry_signal_activate
    (GtkSearchEntry* search_entry_detached) {
        search_entry_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_search_entry_signal_activate(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")...");
        if ((to = search_entry_signals_forward_to())) {
            to->on_search_entry_signal_activate(search_entry_detached);
        }
        const gchar* chars = 0;
        if ((chars = gtk_entry_get_text(GTK_ENTRY(search_entry_detached)))) {
            on_search_entry_signal_activate(search_entry_detached, chars);
        } else {
            GNOMA_LOG_ERROR("failed 0 = gtk_entry_get_text()");
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_search_entry_signal_activate(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")");
    }
    static void search_entry_signal_activate_callback
    (GtkSearchEntry* search_entry_detached, search_entry_signalst* search_entry_signals) {
        GNOMA_LOG_MESSAGE_DEBUG("search_entry_signal_activate_callback(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")...");
        if ((search_entry_detached) && (search_entry_signals)) {
            search_entry_signals->on_search_entry_signal_activate(search_entry_detached);
        } else {
        if ((search_entry_detached)) {
            GNOMA_LOG_ERROR("unexpected search_entry_signals == 0");
        } else {
            GNOMA_LOG_ERROR("unexpected search_entry_detached == 0");
        }
        }
        GNOMA_LOG_MESSAGE_DEBUG("...search_entry_signal_activate_callback(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_search_entry_signal_search_changed
    (GtkSearchEntry* search_entry_detached, const gchar* chars) {
        search_entry_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_search_entry_signal_search_changed(search_entry_detached = " << pointer_to_string(search_entry_detached) << ", chars = " << gchars_to_string(chars) << ")...");
        if ((to = search_entry_signals_forward_to())) {
            to->on_search_entry_signal_search_changed(search_entry_detached);
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_search_entry_signal_search_changed(search_entry_detached = " << pointer_to_string(search_entry_detached) << ", chars = " << gchars_to_string(chars) << ")");
    }
    virtual void on_search_entry_signal_search_changed(GtkSearchEntry* search_entry_detached) {
        search_entry_signalst* to = 0;
        GNOMA_LOG_MESSAGE_DEBUG("on_search_entry_signal_search_changed(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")...");
        if ((to = search_entry_signals_forward_to())) {
            to->on_search_entry_signal_search_changed(search_entry_detached);
        }
        const gchar* chars = 0;
        if ((chars = gtk_entry_get_text(GTK_ENTRY(search_entry_detached)))) {
            on_search_entry_signal_search_changed(search_entry_detached, chars);
        } else {
            GNOMA_LOG_ERROR("failed 0 = gtk_entry_get_text()");
        }
        GNOMA_LOG_MESSAGE_DEBUG("...on_search_entry_signal_search_changed(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")");
    }
    static void search_entry_signal_search_changed_callback
    (GtkSearchEntry* search_entry_detached, search_entry_signalst* search_entry_signals) {
        GNOMA_LOG_MESSAGE_DEBUG("search_entry_signal_search_changed_callback(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")...");
        if ((search_entry_detached) && (search_entry_signals)) {
            search_entry_signals->on_search_entry_signal_search_changed(search_entry_detached);
        } else {
        if ((search_entry_detached)) {
            GNOMA_LOG_ERROR("unexpected search_entry_signals == 0");
        } else {
            GNOMA_LOG_ERROR("unexpected search_entry_detached == 0");
        }
        }
        GNOMA_LOG_MESSAGE_DEBUG("...search_entry_signal_search_changed_callback(search_entry_detached = " << pointer_to_string(search_entry_detached) << ")");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual search_entry_signalst*
    forward_search_entry_signals(search_entry_signalst* to) {
        return 0;
    }
    virtual search_entry_signalst* search_entry_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef search_entry_signalst<> search_entry_signals;
typedef search_entry_signals* search_entry_signal_data_t;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_SEARCH_ENTRY_SIGNALS_HPP
