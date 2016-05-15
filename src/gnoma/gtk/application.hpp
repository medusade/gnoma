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
///   File: application.hpp
///
/// Author: $author$
///   Date: 5/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_APPLICATION_HPP
#define _GNOMA_GTK_APPLICATION_HPP

#include "gnoma/gtk/application_signals.hpp"
#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GtkApplication* application_attached_t;
typedef xos::base::creatort<implement_base> application_creator;
typedef xos::base::attachert<application_attached_t, int, 0, application_creator> application_attacher;
typedef xos::base::attachedt<application_attached_t, int, 0, application_attacher, base> application_attached;
typedef xos::base::createdt<application_attached_t, int, 0, application_attacher, application_attached> application_created;
typedef application_attacher application_implements;
typedef application_created application_extends;
///////////////////////////////////////////////////////////////////////
///  Class: applicationt
///////////////////////////////////////////////////////////////////////
template
<class TSignalsImplements = application_signals,
 class TImplements = application_implements, class TExtends = application_extends>
class _EXPORT_CLASS applicationt
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TSignalsImplements application_signals_t;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    applicationt
    (application_signals_t* application_signals = 0,
     attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      application_signals_(application_signals) {
    }
    virtual ~applicationt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached
    (const gchar* application_id, GApplicationFlags application_flags) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(application_id, application_flags))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached
    (const gchar* application_id, GApplicationFlags application_flags) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_application_new(application_id = \"" << application_id << "\", application_flags = " << application_flags << ")...");
        if ((detached = gtk_application_new(application_id, application_flags))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_application_new(application_id = \"" << application_id << "\", application_flags = " << application_flags << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_application_new(application_id = \"" << application_id << "\", application_flags = " << application_flags << ")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...g_object_unref(" << gpointer_to_string(detached) << ")");
            g_object_unref(detached);
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
    virtual bool connect_signal_activate() {
        attached_t detached = this->attached_to();
        if ((detached)) {
            const char* signal_name = "activate";
            gulong handler_id = 0;
            GNOMA_LOG_MESSAGE_DEBUG("g_signal_connect(" << gpointer_to_string(detached) << ", \"" << signal_name << "\",...)...");
            if ((handler_id = g_signal_connect
                 (detached, signal_name,
                  G_CALLBACK(application_signals_t::application_signal_activate_callback),
                  G_POINTER((application_signals_t*)this)))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << handler_id << " = g_signal_connect(" << gpointer_to_string(detached) << ", \"" << signal_name << "\",...)...");
                return true;
            } else {
                GNOMA_LOG_ERROR("...failed on g_signal_connect(" << gpointer_to_string(detached) << ", \"" << signal_name << "\",...)");
            }
        }
        return false;
    }
    virtual bool disconnect_signal_activate() {
        attached_t detached = this->attached_to();
        if ((detached)) {
            guint handlers = 0;
            GNOMA_LOG_MESSAGE_DEBUG("g_signal_handlers_disconnect_by_func(" << gpointer_to_string(detached) << ",...)...");
            if ((handlers = g_signal_handlers_disconnect_by_func
                 (detached,
                  G_POINTER(application_signals_t::application_signal_activate_callback),
                  G_POINTER((application_signals_t*)this)))) {
                GNOMA_LOG_MESSAGE_DEBUG("...g_signal_handlers_disconnect_by_func(" << gpointer_to_string(detached) << ",...)");
                return true;
            } else {
                GNOMA_LOG_ERROR("...failed on g_signal_handlers_disconnect_by_func(" << gpointer_to_string(detached) << ",...)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual application_signals_t*
    forward_application_signals(application_signals_t* to) {
        application_signals_ = to;
        return application_signals_;
    }
    virtual application_signals_t* application_signals_forward_to() const {
        return application_signals_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    application_signals_t* application_signals_;
};
typedef applicationt<> application;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_APPLICATION_HPP
