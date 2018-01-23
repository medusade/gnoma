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
///   File: search_entry.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_SEARCH_ENTRY_HPP
#define _GNOMA_GTK_SEARCH_ENTRY_HPP

#include "gnoma/gtk/search_entry_signals.hpp"
#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements search_entry_implements;
typedef widget search_entry_extends;
///////////////////////////////////////////////////////////////////////
///  Class: search_entryt
///////////////////////////////////////////////////////////////////////
template
<class TSignalsImplements = search_entry_signals,
 class TImplements = search_entry_implements,
 class TExtends = search_entry_extends>
class _EXPORT_CLASS search_entryt
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TSignalsImplements search_entry_signals_t;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    search_entryt
    (search_entry_signals_t* search_entry_signals = 0,
     attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      search_entry_signals_(search_entry_signals) {
    }
    virtual ~search_entryt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const gchar* get_text() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            const gchar* chars = 0;
            GNOMA_LOG_MESSAGE_DEBUG("gtk_entry_get_text(GTK_ENTRY(detached = " << gpointer_to_string(detached) << "))...");
            if ((chars = gtk_entry_get_text(GTK_ENTRY(detached)))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << gchars_to_string(chars) << " = gtk_entry_get_text(GTK_ENTRY(detached = " << gpointer_to_string(detached) << "))");
                return chars;
            } else {
                GNOMA_LOG_ERROR("failed 0 = gtk_entry_get_text(GTK_ENTRY(detached = " << gpointer_to_string(detached) << "))");
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_search_entry_new()...");
        if ((detached = gtk_search_entry_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_search_entry_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_search_entry_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_activate() {
        const char* signal_name = "activate";
        return connect_signal
        (signal_name,
         (search_entry_signal_callback_t)
         (this->search_entry_signal_activate_callback),
         (search_entry_signal_data_t)(this));
    }
    virtual bool disconnect_signal_activate() {
        return disconnect_signal
        ((search_entry_signal_callback_t)
         (this->search_entry_signal_activate_callback),
         (search_entry_signal_data_t)(this));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_search_changed() {
        const char* signal_name = "search-changed";
        return connect_signal
        (signal_name,
         (search_entry_signal_callback_t)
         (this->search_entry_signal_search_changed_callback),
         (search_entry_signal_data_t)(this));
    }
    virtual bool disconnect_signal_search_changed() {
        return disconnect_signal
        ((search_entry_signal_callback_t)
         (this->search_entry_signal_search_changed_callback),
         (search_entry_signal_data_t)(this));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal
    (const char* signal_name,
     search_entry_signal_callback_t signal_callback,
     search_entry_signal_data_t signal_data,
     search_entry_signal_event_mask_t signal_event_mask = 0) {
        return Extends::connect_signal
        (signal_name,
         (widget_signal_callback_t)(signal_callback),
         (widget_signal_data_t)(signal_data),
         (widget_signal_event_mask_t)(signal_event_mask));
    }
    virtual bool disconnect_signal
    (search_entry_signal_callback_t signal_callback,
     search_entry_signal_data_t signal_data) {
        return Extends::disconnect_signal
        ((widget_signal_callback_t)(signal_callback),
         (widget_signal_data_t)(signal_data));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal
    (gpointer instance, const char* signal_name,
     search_entry_signal_callback_t signal_callback,
     search_entry_signal_data_t signal_data,
     search_entry_signal_event_mask_t signal_event_mask = 0) {
        return Extends::connect_signal
        (instance, signal_name,
         (widget_signal_callback_t)(signal_callback),
         (widget_signal_data_t)(signal_data),
         (widget_signal_event_mask_t)(signal_event_mask));
    }
    virtual bool disconnect_signal
    (gpointer instance,
     search_entry_signal_callback_t signal_callback,
     search_entry_signal_data_t signal_data) {
        return Extends::disconnect_signal
        (instance, (widget_signal_callback_t)(signal_callback),
         (widget_signal_data_t)(signal_data));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual search_entry_signals_t*
    forward_search_entry_signals(search_entry_signals_t* to) {
        search_entry_signals_ = to;
        return search_entry_signals_;
    }
    virtual search_entry_signals_t* search_entry_signals_forward_to() const {
        return search_entry_signals_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    search_entry_signals_t* search_entry_signals_;
};
typedef search_entryt<> search_entry;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_SEARCH_ENTRY_HPP


