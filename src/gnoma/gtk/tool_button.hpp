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
///   File: tool_button.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOL_BUTTON_HPP
#define _GNOMA_GTK_TOOL_BUTTON_HPP

#include "gnoma/gtk/tool_item.hpp"
#include "gnoma/gtk/image.hpp"
#include "gnoma/gtk/widget.hpp"
#include "gnoma/gdk/pixbuf.hpp"

namespace gnoma {
namespace gtk {

typedef tool_item_implements tool_button_implements;
typedef tool_item tool_button_extends;
///////////////////////////////////////////////////////////////////////
///  Class: tool_buttont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = tool_button_implements, class TExtends = tool_button_extends>
class _EXPORT_CLASS tool_buttont
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tool_buttont
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~tool_buttont() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_label(const gchar* label) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_tool_button_set_label(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "), label = " << gchars_to_string(label) << ")");
            gtk_tool_button_set_label(GTK_TOOL_BUTTON(detached), label);
            return true;
        }
        return false;
    }
    virtual const gchar* get_label() {
        const gchar* label = 0;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_button_get_label(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "))...");
            label = gtk_tool_button_get_label(GTK_TOOL_BUTTON(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gchars_to_string(label) << " = gtk_tool_button_get_label(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "))");
        }
        return label;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_use_underline(gboolean use_underline = TRUE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_tool_button_set_use_underline(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "), use_underline = " << gboolean_to_string(use_underline) << ")");
            gtk_tool_button_set_use_underline(GTK_TOOL_BUTTON(detached), use_underline);
            return true;
        }
        return false;
    }
    virtual gboolean get_use_underline() {
        gboolean use_underline = FALSE;
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_button_get_use_underline(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "))...");
            use_underline = gtk_tool_button_get_use_underline(GTK_TOOL_BUTTON(detached));
            GNOMA_LOG_MESSAGE_DEBUG("..." << gboolean_to_string(use_underline) << " = gtk_tool_button_get_use_underline(GTK_TOOL_BUTTON(detached = " << gpointer_to_string(detached) << "))");
        }
        return use_underline;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((detached = create_detached(NULL, NULL))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_attached(GtkWidget* icon) {
        attached_t detached = 0;
        if ((detached = create_detached(icon, NULL))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_attached(const gchar *label) {
        attached_t detached = 0;
        if ((detached = create_detached(NULL, label))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_attached(GtkWidget* icon, const gchar *label) {
        attached_t detached = 0;
        if ((detached = create_detached(icon, label))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached(GtkWidget* icon, const gchar* label) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_button_new(icon = " << gpointer_to_string(icon) << ", label = " << gchars_to_string(label) << ")...");
        if ((detached = GTK_WIDGET(gtk_tool_button_new(icon, label)))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_tool_button_new(icon = " << gpointer_to_string(icon) << ", label = " << gchars_to_string(label) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_tool_button_new(icon = " << gpointer_to_string(icon) << ", label = " << gchars_to_string(label) << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_from_stock_attached(const gchar* stock_id) {
        attached_t detached = 0;
        if ((detached = create_from_stock_detached(stock_id))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_from_stock_detached(const gchar* stock_id) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_tool_button_new_from_stock(stock_id = " << gchars_to_string(stock_id) << ")...");
        if ((detached = GTK_WIDGET(gtk_tool_button_new_from_stock(stock_id)))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_tool_button_new_from_stock(stock_id = " << gchars_to_string(stock_id) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_tool_button_new_from_stock(stock_id = " << gchars_to_string(stock_id) << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef tool_buttont<> tool_button;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOL_BUTTON_HPP


