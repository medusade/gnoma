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
///   File: toolbar.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOLBAR_HPP
#define _GNOMA_GTK_TOOLBAR_HPP

#include "gnoma/gtk/toolbar_signals.hpp"
#include "gnoma/gtk/toolbar_activate_signals.hpp"
#include "gnoma/gtk/tool_button.hpp"
#include "gnoma/gtk/tool_item.hpp"
#include "gnoma/gtk/tool_separator.hpp"
#include "gnoma/gtk/image.hpp"
#include "gnoma/gtk/widget.hpp"
#include "gnoma/gdk/pixbuf.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements toolbar_implements;
typedef widget toolbar_extends;
///////////////////////////////////////////////////////////////////////
///  Class: toolbart
///////////////////////////////////////////////////////////////////////
template
<class TImplements = toolbar_implements, class TExtends = toolbar_extends>
class _EXPORT_CLASS toolbart
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    toolbart
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~toolbart() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool insert(GtkToolItem* item, gint pos = -1) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            if ((item)) {
                GNOMA_LOG_MESSAGE_DEBUG("...gtk_toolbar_insert(GTK_TOOLBAR(detached = " << gpointer_to_string(detached) << "), item = " << gpointer_to_string(item) << ", pos = " << pos << ")");
                gtk_toolbar_insert(GTK_TOOLBAR(detached), item, pos);
                return true;
            }
        }
        return false;
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
        GNOMA_LOG_MESSAGE_DEBUG("gtk_toolbar_new()...");
        if ((detached = gtk_toolbar_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_toolbar_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_toolbar_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef toolbart<> toolbar;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOLBAR_HPP


