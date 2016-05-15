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
///   File: application_window_main.hpp
///
/// Author: $author$
///   Date: 5/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_APPLICATION_WINDOW_MAIN_HPP
#define _GNOMA_GTK_APPLICATION_WINDOW_MAIN_HPP

#include "gnoma/gtk/application_main.hpp"
#include "gnoma/gtk/application_window.hpp"

namespace gnoma {
namespace gtk {

typedef application_main_implements application_window_main_implements;
typedef application_main application_window_main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: application_window_maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = application_window_main_implements,
 class TExtends = application_window_main_extends>

class _EXPORT_CLASS application_window_maint
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    application_window_maint() {
    }
    virtual ~application_window_maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_application_signal_activate(GtkApplication* application) {
        if ((application)) {
            if ((before_create_application_window(application))) {

                if ((application_window_detached_ = create_application_window(application))) {

                    if ((after_create_application_window(application_window_detached_, application))) {

                        if (application_window_detached_ != (application_window_.attached_to())) {
                            application_window_.attach(application_window_detached_);
                        }
                        application_window_.show_all();
                    } else {
                        destroy_application_window(application_window_detached_, application);
                    }
                }
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkWidget* create_application_window(GtkApplication* application) {
        if ((application)) {
            GtkWidget* application_window = 0;
            if ((application_window = application_window_.create_attached(application))) {
                return application_window;
            }
        }
        return 0;
    }
    virtual bool destroy_application_window
    (GtkWidget* application_window, GtkApplication* application) {
        if ((application) && (application_window)
            && (application_window == (application_window_.attached_to()))) {
            if ((application_window_.destroy())) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool before_create_application_window(GtkApplication* application) {
        return true;
    }
    virtual bool after_create_application_window
    (GtkWidget* application_window, GtkApplication* application) {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GtkWidget* application_window_detached_;
    gnoma::gtk::application_window application_window_;
};
typedef application_window_maint<> application_window_main;

} // namespace gtk 
} // namespace gnoma 

#endif // _GNOMA_GTK_APPLICATION_WINDOW_MAIN_HPP 
