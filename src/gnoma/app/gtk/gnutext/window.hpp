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
///   File: window.hpp
///
/// Author: $author$
///   Date: 5/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_APP_GTK_GNUTEXT_WINDOW_HPP
#define _GNOMA_APP_GTK_GNUTEXT_WINDOW_HPP

#include "gnoma/gtk/application_window.hpp"
#include "gnoma/app/gtk/gnutext/bars.hpp"
#include "gnoma/app/gtk/gnutext/panels.hpp"
#include "gnoma/gtk/toolbar.hpp"
#include "gnoma/gtk/tool_button.hpp"
#include "gnoma/gtk/tool_item.hpp"
#include "gnoma/gtk/tool_separator.hpp"
#include "gnoma/gtk/separator.hpp"

#define GNOMA_APP_GTK_GNUTEXT_WINDOW_WIDTH 750
#define GNOMA_APP_GTK_GNUTEXT_WINDOW_HEIGHT 450

namespace gnoma {
namespace app {
namespace gtk {
namespace gnutext {

typedef gnoma::gtk::toolbar toolbar;
typedef gnoma::gtk::tool_button tool_button;
typedef gnoma::gtk::tool_separator tool_separator;
typedef gnoma::gtk::horizontal::separator horizontal_separator;
typedef gnoma::gtk::vertical::separator vertical_separator;

typedef gnoma::gtk::application_window_implements window_implements;
typedef gnoma::gtk::application_window window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>
class _EXPORT_CLASS windowt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      width_(GNOMA_APP_GTK_GNUTEXT_WINDOW_WIDTH),
      height_(GNOMA_APP_GTK_GNUTEXT_WINDOW_HEIGHT) {
    }
    virtual ~windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool before_create(GtkApplication* application) {
        return true;
    }
    virtual bool after_create(GtkApplication* application) {
        GtkWidget* bars_detached = 0;

        this->set_default_size(width_, height_);

        if ((bars_detached = bars_.create_attached())) {
            GtkWidget* toolbar_panels_detached = 0;

            if ((toolbar_panels_detached = toolbar_panels_.create_attached())) {
                GtkWidget* toolbar_detached = 0;

                if ((toolbar_detached = toolbar_.create_attached())) {
                    GtkWidget* tool_item_detached = 0;

                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_QUIT))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_separator_.create_detached())) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_NEW))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_OPEN))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_CLOSE))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_separator_.create_detached())) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_CUT))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_COPY))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_PASTE))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_separator_.create_detached())) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_PREFERENCES))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    if ((tool_item_detached = tool_button_.
                         create_from_stock_detached(GTK_STOCK_HELP))) {
                        toolbar_.insert(GTK_TOOL_ITEM(tool_item_detached));
                    }
                    toolbar_panels_.pack_start(toolbar_detached);
                }
                bars_.pack_start(toolbar_panels_detached);
            }
            this->container_add(bars_detached);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    gint width_, height_;
    bars bars_;
    toolbar toolbar_;
    tool_button tool_button_;
    tool_separator tool_separator_;
    horizontal_separator horizontal_separator_;
    vertical_separator vertical_separator_;
    panels toolbar_panels_, editbar_panels_, statusbar_panels_;
};
typedef windowt<> window;

} // namespace gnutext 
} // namespace gtk 
} // namespace app 
} // namespace gnoma 

#endif // _GNOMA_APP_GTK_GNUTEXT_WINDOW_HPP 
