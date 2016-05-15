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
///   File: screen.hpp
///
/// Author: $author$
///   Date: 5/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_SCREEN_HPP
#define _GNOMA_GDK_SCREEN_HPP

#include "gnoma/gdk/gdk.hpp"

namespace gnoma {
namespace gdk {

typedef GdkScreen* screen_attached_t;
typedef xos::base::creatort<implement_base> screen_creator;
typedef xos::base::attachert<screen_attached_t, int, 0, screen_creator> screen_attacher;
typedef xos::base::attachedt<screen_attached_t, int, 0, screen_attacher, base> screen_attached;
typedef xos::base::createdt<screen_attached_t, int, 0, screen_attacher, screen_attached> screen_created;
typedef screen_attacher screen_implements;
typedef screen_created screen_extends;
///////////////////////////////////////////////////////////////////////
///  Class: screent
///////////////////////////////////////////////////////////////////////
template
<class TImplements = screen_implements, class TExtends = screen_extends>
class _EXPORT_CLASS screent
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    screent
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~screent() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached(GdkDisplay *display) {
        attached_t detached = 0;
        if ((detached = create_detached(display))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached(GdkDisplay *display) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_display_get_default_screen(display = " << gpointer_to_string(display) << ")...");
        if ((detached = gdk_display_get_default_screen(display))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_display_get_default_screen(display = " << gpointer_to_string(display) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gdk_display_get_default_screen(display = " << gpointer_to_string(display) << ")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            return true;
        }
        return false;
    }
    virtual operator attached_t() const {
        attached_t detached = this->attached_to();
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GdkWindow* get_root_window() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GdkWindow* window = 0;
            GNOMA_LOG_MESSAGE_DEBUG("gdk_screen_get_root_window(detached = " << gpointer_to_string(detached) << ")...");
            if ((window = gdk_screen_get_root_window(detached))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(window) << " = gdk_screen_get_root_window(detached = " << gpointer_to_string(detached) << ")");
                return window;
            } else {
                GNOMA_LOG_ERROR("...failed 0 = gdk_screen_get_root_window(detached = " << gpointer_to_string(detached) << ")");
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef screent<> screen;

} // namespace gdk 
} // namespace gnoma 

#endif // _GNOMA_GDK_SCREEN_HPP 
