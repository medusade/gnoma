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
///   Date: 5/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_WINDOW_HPP
#define _GNOMA_GDK_WINDOW_HPP

#include "gnoma/gdk/gdk.hpp"

namespace gnoma {
namespace gdk {

typedef GdkWindow* window_attached_t;
typedef xos::base::creatort<implement_base> window_creator;
typedef xos::base::attachert<window_attached_t, int, 0, window_creator> window_attacher;
typedef xos::base::attachedt<window_attached_t, int, 0, window_attacher, base> window_attached;
typedef xos::base::createdt<window_attached_t, int, 0, window_attacher, window_attached> window_created;
typedef window_attacher window_implements;
typedef window_created window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>
class _EXPORT_CLASS windowt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached
    (GdkWindow* parent, GdkWindowAttr* attributes, gint attributes_mask) {
        attached_t detached = 0;
        if ((detached = create_detached(parent, attributes, attributes_mask))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached
    (GdkWindow* parent, GdkWindowAttr* attributes, gint attributes_mask) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_window_new(parent = " << gpointer_to_string(parent) << ", attributes = " << gpointer_to_string(attributes) << ", attributes_mask = " << attributes_mask << ")...");
        if ((detached = gdk_window_new(parent, attributes, attributes_mask))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_window_new(parent = " << gpointer_to_string(parent) << ", attributes = " << gpointer_to_string(attributes) << ", attributes_mask = " << attributes_mask << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gdk_window_new(parent = " << gpointer_to_string(parent) << ", attributes = " << gpointer_to_string(attributes) << ", attributes_mask = " << attributes_mask << ")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_window_destroy(" << gpointer_to_string(detached) << ")");
            gdk_window_destroy(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool show() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_window_show(" << gpointer_to_string(detached) << ")");
            gdk_window_show(detached);
            return true;
        }
        return false;
    }
    virtual bool hide() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_window_hide(" << gpointer_to_string(detached) << ")");
            gdk_window_hide(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef windowt<> window;

} // namespace gdk 
} // namespace gnoma 

#endif // _GNOMA_GDK_WINDOW_HPP 
