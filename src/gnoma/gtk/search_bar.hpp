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
///   File: search_bar.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_SEARCH_BAR_HPP
#define _GNOMA_GTK_SEARCH_BAR_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements search_bar_implements;
typedef widget search_bar_extends;
///////////////////////////////////////////////////////////////////////
///  Class: search_bart
///////////////////////////////////////////////////////////////////////
template
<class TImplements = search_bar_implements, class TExtends = search_bar_extends>
class _EXPORT_CLASS search_bart
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    search_bart
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~search_bart() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_search_mode(gboolean search_mode = TRUE) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "), search_mode = " << gboolean_to_string(search_mode) << ")");
            gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(detached), search_mode);
            return true;
        }
        return false;
    }
    virtual gboolean get_search_mode() const {
        gboolean search_mode = FALSE;
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_search_bar_get_search_mode(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "))...");
            search_mode = gtk_search_bar_get_search_mode(GTK_SEARCH_BAR(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gboolean_to_string(search_mode) << " = gtk_search_bar_get_search_mode(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "))");
        }
        return search_mode;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_show_close_button(gboolean visible = TRUE) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_search_bar_set_show_close_button(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "), visible = " << gboolean_to_string(visible) << ")");
            gtk_search_bar_set_show_close_button(GTK_SEARCH_BAR(detached), visible);
            return true;
        }
        return false;
    }
    virtual gboolean get_show_close_button() const {
        gboolean visible = FALSE;
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "))...");
            visible = gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gboolean_to_string(visible) << " = gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR(detached = " << gpointer_to_string(detached) << "))");
        }
        return visible;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((detached = create_detached())) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_search_bar_new()...");
        if ((detached = gtk_search_bar_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_search_bar_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_search_bar_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef search_bart<> search_bar;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_SEARCH_BAR_HPP
