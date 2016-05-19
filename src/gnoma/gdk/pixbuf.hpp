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
///   File: pixbuf.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_PIXBUF_HPP
#define _GNOMA_GDK_PIXBUF_HPP

#include "gnoma/gdk/gdk.hpp"

namespace gnoma {
namespace gdk {

typedef GdkPixbuf* pixbuf_attached_t;
typedef xos::base::creatort<implement_base> pixbuf_creator;
typedef xos::base::attachert<pixbuf_attached_t, int, 0, pixbuf_creator> pixbuf_attacher;
typedef xos::base::attachedt<pixbuf_attached_t, int, 0, pixbuf_attacher, base> pixbuf_attached;
typedef xos::base::createdt<pixbuf_attached_t, int, 0, pixbuf_attacher, pixbuf_attached> pixbuf_created;
typedef pixbuf_attacher pixbuf_implements;
typedef pixbuf_created pixbuf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: pixbuft
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pixbuf_implements, class TExtends = pixbuf_extends>
class _EXPORT_CLASS pixbuft
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixbuft
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~pixbuft() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_from_file_at_size_attached
    (const char* filename, int width, int height) {
        attached_t detached = 0;
        if ((detached = create_from_file_at_size_detached(filename, width, height))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_from_file_at_size_detached
    (const char* filename, int width, int height) const {
        attached_t detached = 0;
        GError* error = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_pixbuf_new_from_file_at_size(filename = " << chars_to_string(filename) << ", width = " << width << ", height = " << height << ", &error = " << pointer_to_string(&error) << ")...");
        if ((detached = gdk_pixbuf_new_from_file_at_size(filename, width, height, &error))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_pixbuf_new_from_file_at_size(filename = " << chars_to_string(filename) << ", width = " << width << ", height = " << height << ", &error = " << pointer_to_string(&error) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gdk_pixbuf_new_from_file_at_size(filename = " << chars_to_string(filename) << ", width = " << width << ", height = " << height << ", &error = " << pointer_to_string(&error) << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_from_file_attached(const char* filename) {
        attached_t detached = 0;
        if ((detached = create_from_file_detached(filename))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_from_file_detached(const char* filename) const {
        attached_t detached = 0;
        GError* error = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_pixbuf_new_from_file(filename = " << chars_to_string(filename) << ", &error = " << pointer_to_string(&error) << ")...");
        if ((detached = gdk_pixbuf_new_from_file(filename, &error))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_pixbuf_new_from_file(filename = " << chars_to_string(filename) << ", &error = " << pointer_to_string(&error) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gdk_pixbuf_new_from_file(filename = " << chars_to_string(filename) << ", &error = " << pointer_to_string(&error) << ")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("...g_object_unref(" << gpointer_to_string(detached) << ")");
            g_object_unref(detached);
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
};
typedef pixbuft<> pixbuf;

} // namespace gdk
} // namespace gnoma

#endif // _GNOMA_GDK_PIXBUF_HPP
