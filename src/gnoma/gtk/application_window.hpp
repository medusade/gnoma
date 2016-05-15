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
///   File: application_window.hpp
///
/// Author: $author$
///   Date: 5/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_APPLICATION_APPLICATION_WINDOW_HPP
#define _GNOMA_GTK_APPLICATION_APPLICATION_WINDOW_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements application_window_implements;
typedef widget application_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: application_windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = application_window_implements,
 class TExtends = application_window_extends>

class _EXPORT_CLASS application_windowt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    application_windowt() {
    }
    virtual ~application_windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached(GtkApplication* application) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(application))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached(GtkApplication* application) const {
        attached_t detached = 0;
        if ((application)) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_application_window_new(application = " << gpointer_to_string(application) << ")...");
            if ((detached = gtk_application_window_new(application))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_application_window_new(application = " << gpointer_to_string(application) << ")");
            } else {
                GNOMA_LOG_ERROR("failed on gtk_application_window_new(application = " << gpointer_to_string(application) << ")");
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef application_windowt<> application_window;

} // namespace gtk 
} // namespace gnoma 

#endif // _GNOMA_GTK_APPLICATION_APPLICATION_WINDOW_HPP 
