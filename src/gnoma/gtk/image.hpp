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
///   File: image.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_IMAGE_HPP
#define _GNOMA_GTK_IMAGE_HPP

#include "gnoma/gtk/widget.hpp"
#include "gnoma/gdk/pixbuf.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements image_implements;
typedef widget image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: imaget
///////////////////////////////////////////////////////////////////////
template
<class TImplements = image_implements, class TExtends = image_extends>
class _EXPORT_CLASS imaget
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    imaget
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~imaget() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_from_pixbuf_attached(GdkPixbuf* pixbuf) {
        attached_t detached = 0;
        if ((detached = create_from_pixbuf_detached(pixbuf))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_from_pixbuf_detached(GdkPixbuf* pixbuf) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_image_new_from_pixbuf(pixbuf = " << gpointer_to_string(pixbuf) << ")...");
        if ((detached = gtk_image_new_from_pixbuf(pixbuf))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_image_new_from_pixbuf(pixbuf = " << gpointer_to_string(pixbuf) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_image_new_from_pixbuf(pixbuf = " << gpointer_to_string(pixbuf) << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef imaget<> image;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_IMAGE_HPP


