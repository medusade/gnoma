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
///   File: scrolled_window.hpp
///
/// Author: $author$
///   Date: 5/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_SCROLLED_WINDOW_HPP
#define _GNOMA_GTK_SCROLLED_WINDOW_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements scrolled_window_implements;
typedef widget scrolled_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: scrolled_windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = scrolled_window_implements, class TExtends = scrolled_window_extends>
class _EXPORT_CLASS scrolled_windowt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    scrolled_windowt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~scrolled_windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_min_content_height(gint height) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(detached = " << gpointer_to_string(detached) << "), height = " << height << ")");
            gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(detached), height);
            return true;
        }
        return false;
    }
    virtual bool set_min_content_width(gint width) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(detached), width);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached
    (GtkAdjustment *hadjustment, GtkAdjustment *vadjustment) {
        attached_t detached = 0;
        if ((detached = create_detached(hadjustment, vadjustment))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached
    (GtkAdjustment *hadjustment, GtkAdjustment *vadjustment) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_scrolled_window_new(hadjustment = " << gpointer_to_string(hadjustment) << ", vadjustment = " << gpointer_to_string(vadjustment) << ")...");
        if ((detached = gtk_scrolled_window_new(hadjustment, vadjustment))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_scrolled_window_new(hadjustment = " << gpointer_to_string(hadjustment) << ", vadjustment = " << gpointer_to_string(vadjustment) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_scrolled_window_new(hadjustment = " << gpointer_to_string(hadjustment) << ", vadjustment = " << gpointer_to_string(vadjustment) << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef scrolled_windowt<> scrolled_window;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_SCROLLED_WINDOW_HPP


