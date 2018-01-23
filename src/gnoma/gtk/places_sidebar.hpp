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
///   File: places_sidebar.hpp
///
/// Author: $author$
///   Date: 5/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_PLACES_SIDEBAR_HPP
#define _GNOMA_GTK_PLACES_SIDEBAR_HPP

#include "gnoma/gtk/scrolled_window.hpp"
#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef scrolled_window_implements places_sidebar_implements;
typedef scrolled_window places_sidebar_extends;
///////////////////////////////////////////////////////////////////////
///  Class: places_sidebart
///////////////////////////////////////////////////////////////////////
template
<class TImplements = places_sidebar_implements, class TExtends = places_sidebar_extends>
class _EXPORT_CLASS places_sidebart
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    places_sidebart
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~places_sidebart() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_open_flags(GtkPlacesOpenFlags open_flags) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_places_sidebar_set_open_flags(GTK_PLACES_SIDEBAR(detached = " << gpointer_to_string(detached) << "), open_flags = " << GtkPlacesOpenFlags_to_string(open_flags) << ")");
            gtk_places_sidebar_set_open_flags(GTK_PLACES_SIDEBAR(detached), open_flags);
        }
    }
    virtual GtkPlacesOpenFlags get_open_flags() const {
        GtkPlacesOpenFlags open_flags = ((GtkPlacesOpenFlags)0);
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_places_sidebar_get_open_flags(GTK_PLACES_SIDEBAR(detached = " << gpointer_to_string(detached) << "))...");
            open_flags = gtk_places_sidebar_get_open_flags(GTK_PLACES_SIDEBAR(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << GtkPlacesOpenFlags_to_string(open_flags) << " = gtk_places_sidebar_get_open_flags(GTK_PLACES_SIDEBAR(detached = " << gpointer_to_string(detached) << "))");
        }
        return open_flags;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_places_sidebar_new()...");
        if ((detached = gtk_places_sidebar_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_places_sidebar_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_places_sidebar_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef places_sidebart<> places_sidebar;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_PLACES_SIDEBAR_HPP


