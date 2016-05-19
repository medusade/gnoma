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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_APP_GTK_GNUTEXT_MAIN_HPP
#define _GNOMA_APP_GTK_GNUTEXT_MAIN_HPP

#include "gnoma/app/gtk/gnutext/window.hpp"
#include "gnoma/gtk/application_window_main.hpp"
#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace app {
namespace gtk {
namespace gnutext {

typedef gnoma::gtk::application_window_main_implements main_implements;
typedef gnoma::gtk::application_window_main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool before_create_application_window(GtkApplication* application) {
        if ((application)) {
            if ((window_.before_create(application))) {
                return true;
            }
        }
        return false;
    }
    virtual bool after_create_application_window
    (GtkWidget* application_window, GtkApplication* application) {
        if ((application) && (application_window)
            && (application_window == (window_.attached_to()))) {
            if ((window_.after_create(application))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkWidget* create_application_window(GtkApplication* application) {
        if ((application)) {
            GtkWidget* application_window = 0;
            if ((application_window = window_.create_attached(application))) {
                return application_window;
            }
        }
        return 0;
    }
    virtual bool destroy_application_window
    (GtkWidget* application_window, GtkApplication* application) {
        if ((application) && (application_window)
            && (application_window == (window_.attached_to()))) {
            if ((window_.destroy())) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    window window_;
};
typedef maint<> main;

} // namespace gnutext 
} // namespace gtk 
} // namespace app 
} // namespace gnoma 

#endif // _GNOMA_APP_GTK_GNUTEXT_MAIN_HPP 
