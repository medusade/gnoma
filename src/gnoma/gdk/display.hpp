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
///   File: display.hpp
///
/// Author: $author$
///   Date: 5/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_DISPLAY_HPP
#define _GNOMA_GDK_DISPLAY_HPP

#include "gnoma/gdk/gdk.hpp"
#include "gnoma/base/base.hpp"

namespace gnoma {
namespace gdk {

typedef GdkDisplay* display_attached_t;
typedef xos::base::openert<implement_base> display_opener;
typedef xos::base::attachert<display_attached_t, int, 0, display_opener> display_attacher;
typedef xos::base::attachedt<display_attached_t, int, 0, display_attacher, base> display_attached;
typedef xos::base::openedt<display_attached_t, int, 0, display_attacher, display_attached> display_opened;
typedef display_attacher display_implements;
typedef display_opened display_extends;
///////////////////////////////////////////////////////////////////////
///  Class: displayt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = display_implements, class TExtends = display_extends>
class _EXPORT_CLASS displayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    displayt
    (attached_t detached = 0, bool is_open = false)
    : Extends(detached, is_open) {
    }
    virtual ~displayt() {
        if (!(this->closed())) {
            opener_exception e = failed_to_close;
            GNOMA_LOG_ERROR("...failed on this->closed() throw(opener_exception e = failed_to_close)...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::open;
    virtual bool open(const gchar* display_name) {
        attached_t detached = 0;
        if ((detached = open_attached(display_name))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    using Extends::open_attached;
    virtual attached_t open_attached(const gchar* display_name) {
        attached_t detached = 0;
        if ((detached = open_detached(display_name))) {
            this->attach(detached);
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t open_detached() const {
        attached_t detached = 0;
        const gchar* display_name = 0;
        if ((display_name = get_default_name())) {
            detached = open_detached(display_name);
        }
        return detached;
    }
    virtual attached_t open_detached(const gchar* display_name) const {
        attached_t detached = 0;
        if ((display_name)) {
            GNOMA_LOG_MESSAGE_DEBUG("gdk_display_open(display_name = \"" << display_name << "\")...");
            if ((detached = gdk_display_open(display_name))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(detached) << " = gdk_display_open(display_name = \"" << display_name << "\")");
            } else {
                GNOMA_LOG_ERROR("...failed 0 = gdk_display_open(display_name = \"" << display_name << "\")");
            }
        }
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_display_close(detached = " << pointer_to_string(detached) << ")");
            gdk_display_close(detached);
            return true;
        } else {
            GNOMA_LOG_ERROR("...detached = 0");
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GdkWindow* get_default_group() const {
        attached_t detached = 0;
        GdkWindow* default_group = 0;
        if ((detached = this->attached_to())) {
            default_group = get_default_group(detached);
        }
        return default_group;
    }
    virtual GdkWindow* get_default_group(attached_t detached) const {
        GdkWindow* default_group = 0;
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_display_get_default_group(detached = " << gpointer_to_string(detached) << ")");
            if ((default_group = gdk_display_get_default_group(detached))) {
                GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(default_group) << " = gdk_display_get_default_group(detached = " << gpointer_to_string(detached) << ")");
            } else {
                GNOMA_LOG_ERROR("...failed 0 = gdk_display_get_default_group(detached = " << gpointer_to_string(detached) << ")");
            }
        }
        return default_group;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const gchar* get_name() const {
        attached_t detached = 0;
        const gchar* name = 0;
        if ((detached = this->attached_to())) {
            name = get_name(detached);
        }
        return name;
    }
    virtual const gchar* get_name(attached_t detached) const {
        const gchar* name = 0;
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...gdk_display_get_name(detached = " << gpointer_to_string(detached) << ")");
            if ((name = gdk_display_get_name(detached))) {
                GNOMA_LOG_MESSAGE_DEBUG("...\"" << name << "\" = gdk_display_get_name(detached = " << gpointer_to_string(detached) << ")");
            } else {
                GNOMA_LOG_ERROR("...failed 0 = gdk_display_get_name(detached = " << gpointer_to_string(detached) << ")");
            }
        }
        return name;
    }
    virtual const gchar* get_default_name() const {
        attached_t detached = 0;
        const gchar* name = 0;
        if ((detached = get_default())) {
            name = get_name(detached);
        }
        return name;
    }
    virtual attached_t get_default() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_display_get_default()...");
        if ((detached = gdk_display_get_default())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_display_get_default()");
        } else {
            GNOMA_LOG_ERROR("failed 0 = gdk_display_get_default()...");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef displayt<> display;

} // namespace gdk 
} // namespace gnoma 

#endif // _GNOMA_GDK_DISPLAY_HPP 
