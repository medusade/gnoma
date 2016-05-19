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
///   File: tool_item.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOL_ITEM_HPP
#define _GNOMA_GTK_TOOL_ITEM_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements tool_item_implements;
typedef widget tool_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: tool_itemt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = tool_item_implements, class TExtends = tool_item_extends>
class _EXPORT_CLASS tool_itemt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tool_itemt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~tool_itemt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkIconSize get_icon_size() {
        GtkIconSize icon_size = GTK_ICON_SIZE_INVALID;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_item_get_icon_size(GTK_TOOL_ITEM(detached = " << gpointer_to_string(detached) << "))...");
            icon_size = gtk_tool_item_get_icon_size(GTK_TOOL_ITEM(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << GtkIconSize_to_string(icon_size) << " = gtk_tool_item_get_icon_size(GTK_TOOL_ITEM(detached = " << gpointer_to_string(detached) << "))");
        }
        return icon_size;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_homogeneous(gboolean homogeneous = TRUE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_tool_item_set_homogeneous(GTK_TOOL_ITEM(detached = " << gpointer_to_string(detached) << "), homogeneous = " << gboolean_to_string(homogeneous) << ")");
            gtk_tool_item_set_homogeneous(GTK_TOOL_ITEM(detached), homogeneous);
            return true;
        }
        return false;
    }
    virtual gboolean get_homogeneous() {
        gboolean homogeneous = FALSE;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_item_get_homogeneous(GTK_TOOL_ITEM(detached = " << gpointer_to_string(detached) << "))...");
            homogeneous = gtk_tool_item_get_homogeneous(GTK_TOOL_ITEM(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gboolean_to_string(homogeneous) << " = gtk_tool_item_get_homogeneous(GTK_TOOL_ITEM(detached = " << gpointer_to_string(detached) << "))");
        }
        return homogeneous;
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
        GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_item_new()...");
        if ((detached = GTK_WIDGET(gtk_tool_item_new()))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_tool_item_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_tool_item_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef tool_itemt<> tool_item;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOL_ITEM_HPP


