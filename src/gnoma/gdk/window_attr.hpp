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
///   File: window_attr.hpp
///
/// Author: $author$
///   Date: 5/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_WINDOW_ATTR_HPP
#define _GNOMA_GDK_WINDOW_ATTR_HPP

#include "gnoma/gdk/gdk.hpp"

#define GNOMA_GDK_WINDOW_ATTR_EVENT_MASK \
    GDK_EXPOSURE_MASK | GDK_STRUCTURE_MASK | \
    GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK | \
    GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | \
    GDK_KEY_PRESS_MASK | GDK_KEY_RELEASE_MASK

#define GNOMA_GDK_WINDOW_ATTR_X 0
#define GNOMA_GDK_WINDOW_ATTR_Y 0
#define GNOMA_GDK_WINDOW_ATTR_WIDTH 500
#define GNOMA_GDK_WINDOW_ATTR_HEIGHT 300
#define GNOMA_GDK_WINDOW_ATTR_WCLASS GDK_INPUT_OUTPUT
#define GNOMA_GDK_WINDOW_ATTR_WINDOW_TYPE GDK_WINDOW_CHILD
#define GNOMA_GDK_WINDOW_ATTR_MASK \
    GDK_WA_X | GDK_WA_Y

namespace gnoma {
namespace gdk {

typedef GdkWindowAttr* window_attr_attached_t;
typedef xos::base::creatort<implement_base> window_attr_creator;
typedef xos::base::attachert<window_attr_attached_t, int, 0, window_attr_creator> window_attr_attacher;
typedef xos::base::attachedt<window_attr_attached_t, int, 0, window_attr_attacher, base> window_attr_attached;
typedef xos::base::createdt<window_attr_attached_t, int, 0, window_attr_attacher, window_attr_attached> window_attr_created;
typedef window_attr_attacher window_attr_implements;
typedef window_attr_created window_attr_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_attrt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_attr_implements, class TExtends = window_attr_extends>
class _EXPORT_CLASS window_attrt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_attrt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      mask_(0) {
        memset(&internal_, 0, sizeof(internal_));
        internal_.event_mask = GNOMA_GDK_WINDOW_ATTR_EVENT_MASK;
        internal_.x = GNOMA_GDK_WINDOW_ATTR_X;
        internal_.y = GNOMA_GDK_WINDOW_ATTR_Y;
        internal_.width = GNOMA_GDK_WINDOW_ATTR_WIDTH;
        internal_.height = GNOMA_GDK_WINDOW_ATTR_HEIGHT;
        internal_.wclass = GNOMA_GDK_WINDOW_ATTR_WCLASS;
        internal_.window_type = GNOMA_GDK_WINDOW_ATTR_WINDOW_TYPE;
        if (!(this->attached_to())) {
            this->attach(&internal_);
            this->set_mask(GNOMA_GDK_WINDOW_ATTR_MASK);
        }
    }
    virtual ~window_attrt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
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
    virtual gint set_mask(gint to) {
        mask_ = to;
        return mask_;
    }
    virtual gint mask() const {
        return mask_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GdkWindowAttr internal_;
    gint mask_;
};
typedef window_attrt<> window_attr;

} // namespace gdk 
} // namespace gnoma 

#endif // _GNOMA_GDK_WINDOW_ATTR_HPP 
