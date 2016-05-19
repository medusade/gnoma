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
///   File: widget.hpp
///
/// Author: $author$
///   Date: 5/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_WIDGET_HPP
#define _GNOMA_GTK_WIDGET_HPP

#include "gnoma/gtk/widget_signals.hpp"
#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef GtkWidget* widget_attached_t;
typedef xos::base::creatort<implement_base> widget_creator;
typedef xos::base::attachert<widget_attached_t, int, 0, widget_creator> widget_attacher;
typedef xos::base::attachedt<widget_attached_t, int, 0, widget_attacher, base> widget_attached;
typedef xos::base::createdt<widget_attached_t, int, 0, widget_attacher, widget_attached> widget_created;
typedef widget_attacher widget_implements;
typedef widget_created widget_extends;
///////////////////////////////////////////////////////////////////////
///  Class: widgett
///////////////////////////////////////////////////////////////////////
template
<class TImplements = widget_implements, class TExtends = widget_extends>
class _EXPORT_CLASS widgett
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    widgett
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~widgett() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached(GType type) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(type))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached(GType type) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_widget_new(type = " << type << ", NULL)...");
        if ((detached = gtk_widget_new(type, NULL))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_widget_new(type = " << type << ", NULL)");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_widget_new(type = " << type << ", NULL)");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_widget_destroy(" << gpointer_to_string(detached) << ")");
            gtk_widget_destroy(detached);
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
    virtual bool show_all() {
        attached_t detached = this->attached_to();
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_widget_show_all(" << gpointer_to_string(detached) << ")");
            gtk_widget_show_all(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool container_add(attached_t widget) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((widget)) {
                GNOMA_LOG_MESSAGE_DEBUG("...gtk_container_add(GTK_CONTAINER(detached = " << gpointer_to_string(detached) << "), widget = " << gpointer_to_string(widget) << ")")
                gtk_container_add(GTK_CONTAINER(detached), widget);
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef widgett<> widget;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_WIDGET_HPP
        

