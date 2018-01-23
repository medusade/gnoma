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
///   File: box.hpp
///
/// Author: $author$
///   Date: 5/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_BOX_HPP
#define _GNOMA_GTK_BOX_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements box_implements;
typedef widget box_extends;
///////////////////////////////////////////////////////////////////////
///  Class: boxt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = box_implements, class TExtends = box_extends>
class _EXPORT_CLASS boxt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    boxt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~boxt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool pack_start
    (GtkWidget* child, gboolean expand = FALSE,
     gboolean fill = FALSE, guint padding = 0) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((child)) {
                gtk_box_pack_start
                (GTK_BOX(detached), child, expand, fill, padding);
                return true;
            }
        }
        return false;
    }
    virtual bool pack_end
    (GtkWidget* child, gboolean expand = FALSE,
     gboolean fill = FALSE, guint padding = 0) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((child)) {
                gtk_box_pack_end
                (GTK_BOX(detached), child, expand, fill, padding);
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_spacing(gint spacing) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_box_set_spacing(GTK_BOX(detached = " << gpointer_to_string(detached) << "), spacing = " << gint_to_string(spacing) << ")");
            gtk_box_set_spacing(GTK_BOX(detached), spacing);
            return true;
        }
        return false;
    }
    virtual gint get_spacing() {
        gint spacing = -1;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_box_get_spacing(GTK_BOX(detached = " << gpointer_to_string(detached) << "))...");
            spacing = gtk_box_get_spacing(GTK_BOX(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gint_to_string(spacing) << " = gtk_box_get_spacing(GTK_BOX(detached = " << gpointer_to_string(detached) << "))");
        }
        return spacing;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_homogeneous(gboolean homogeneous = TRUE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_box_set_homogeneous(GTK_BOX(detached = " << gpointer_to_string(detached) << "), homogeneous = " << gboolean_to_string(homogeneous) << ")");
            gtk_box_set_homogeneous(GTK_BOX(detached), homogeneous);
            return true;
        }
        return false;
    }
    virtual gboolean get_homogeneous() {
        gboolean homogeneous = FALSE;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_box_get_homogeneous(GTK_BOX(detached = " << gpointer_to_string(detached) << "))...");
            homogeneous = gtk_box_get_homogeneous(GTK_BOX(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gboolean_to_string(homogeneous) << " = gtk_box_get_homogeneous(GTK_BOX(detached = " << gpointer_to_string(detached) << "))");
        }
        return homogeneous;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached
    (GtkOrientation orientation, gint spacing) {
        attached_t detached = 0;
        if ((detached = create_detached(orientation, spacing))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached
    (GtkOrientation orientation, gint spacing) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_box_new(orientation = " << orientation << ", spacing = " << spacing << ")...");
        if ((detached = gtk_box_new(orientation, spacing))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_box_new(orientation = " << orientation << ", spacing = " << spacing << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_box_new(orientation = " << orientation << ", spacing = " << spacing << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef boxt<> box;

namespace horizontal {
typedef gtk::box_implements box_implements;
typedef gtk::box box_extends;
///////////////////////////////////////////////////////////////////////
///  Class: boxt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = box_implements, class TExtends = box_extends>
class _EXPORT_CLASS boxt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    boxt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~boxt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached(gint spacing) {
        attached_t detached = 0;
        if ((detached = this->create_detached(spacing))) {
            this->attach(detached);
        }
        return detached;
    }
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = this->create_detached(0);
        return detached;
    }
    virtual attached_t create_detached(gint spacing) const {
        attached_t detached = this->create_detached
        (GTK_ORIENTATION_HORIZONTAL, spacing);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef boxt<> box;
} // namespace horizontal

namespace vertical {
typedef gtk::box_implements box_implements;
typedef gtk::box box_extends;
///////////////////////////////////////////////////////////////////////
///  Class: boxt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = box_implements, class TExtends = box_extends>
class _EXPORT_CLASS boxt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    boxt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~boxt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached(gint spacing) {
        attached_t detached = 0;
        if ((detached = this->create_detached(spacing))) {
            this->attach(detached);
        }
        return detached;
    }
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = this->create_detached(0);
        return detached;
    }
    virtual attached_t create_detached(gint spacing) const {
        attached_t detached = this->create_detached
        (GTK_ORIENTATION_VERTICAL, spacing);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef boxt<> box;
} // namespace vertical

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_BOX_HPP
