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
///   File: paned.hpp
///
/// Author: $author$
///   Date: 5/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_PANED_HPP
#define _GNOMA_GTK_PANED_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements paned_implements;
typedef widget paned_extends;
///////////////////////////////////////////////////////////////////////
///  Class: panedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = paned_implements, class TExtends = paned_extends>
class _EXPORT_CLASS panedt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    panedt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~panedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool pack1
    (GtkWidget* child, gboolean resize = TRUE, gboolean shrink = FALSE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((child)) {
                GNOMA_LOG_MESSAGE_DEBUG("...gtk_paned_pack1(GTK_PANED(detached), child, resize, shrink)");
                gtk_paned_pack1
                (GTK_PANED(detached), child, resize, shrink);
                return true;
            }
        }
        return false;
    }
    virtual bool pack2
    (GtkWidget* child, gboolean resize = TRUE, gboolean shrink = FALSE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((child)) {
                GNOMA_LOG_MESSAGE_DEBUG("...gtk_paned_pack2(GTK_PANED(detached), child, resize, shrink)");
                gtk_paned_pack2
                (GTK_PANED(detached), child, resize, shrink);
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gint set_position(guint position) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_paned_set_position(GTK_PANED(detached), position)");
            gtk_paned_set_position(GTK_PANED(detached), position);
            return gtk_paned_get_position(GTK_PANED(detached));
        }
        return -1;
    }
    virtual gint get_position() const {
        guint position = -1;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_paned_get_position(GTK_PANED(detached))...");
            position = gtk_paned_get_position(GTK_PANED(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << position << " = gtk_paned_get_position(GTK_PANED(detached))...");
        }
        return position;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached(GtkOrientation orientation) {
        attached_t detached = 0;
        if ((detached = create_detached(orientation))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached(GtkOrientation orientation) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_paned_new(orientation = " << orientation << ")...");
        if ((detached = gtk_paned_new(orientation))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_paned_new(orientation = " << orientation << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_paned_new(orientation = " << orientation << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef panedt<> paned;

namespace horizontal {
typedef gtk::paned_implements paned_implements;
typedef gtk::paned paned_extends;
///////////////////////////////////////////////////////////////////////
///  Class: panedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = paned_implements, class TExtends = paned_extends>
class _EXPORT_CLASS panedt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    panedt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~panedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = this->create_detached(GTK_ORIENTATION_HORIZONTAL);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef panedt<> paned;
} // namespace horizontal

namespace vertical {
typedef gtk::paned_implements paned_implements;
typedef gtk::paned paned_extends;
///////////////////////////////////////////////////////////////////////
///  Class: panedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = paned_implements, class TExtends = paned_extends>
class _EXPORT_CLASS panedt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    panedt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~panedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = this->create_detached(GTK_ORIENTATION_VERTICAL);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef panedt<> paned;
} // namespace vertical

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_PANED_HPP


