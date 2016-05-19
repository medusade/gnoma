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
///   File: separator.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_SEPARATOR_HPP
#define _GNOMA_GTK_SEPARATOR_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements separator_implements;
typedef widget separator_extends;
///////////////////////////////////////////////////////////////////////
///  Class: separatort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = separator_implements, class TExtends = separator_extends>
class _EXPORT_CLASS separatort
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    separatort
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~separatort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_attached;
    virtual attached_t create_attached(GtkOrientation orientation) {
        attached_t detached = 0;
        if ((detached = create_detached(orientation))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached(GtkOrientation orientation) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_separator_new(orientation = " << orientation << ")...");
        if ((detached = gtk_separator_new(orientation))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_separator_new(orientation = " << orientation << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_separator_new(orientation = " << orientation << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef separatort<> separator;

namespace horizontal {
typedef gtk::separator_implements separator_implements;
typedef gtk::separator separator_extends;
///////////////////////////////////////////////////////////////////////
///  Class: separatort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = separator_implements, class TExtends = separator_extends>
class _EXPORT_CLASS separatort
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    separatort
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~separatort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        detached = this->create_detached(GTK_ORIENTATION_HORIZONTAL);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef separatort<> separator;
} // namespace horizontal

namespace vertical {
typedef gtk::separator_implements separator_implements;
typedef gtk::separator separator_extends;
///////////////////////////////////////////////////////////////////////
///  Class: separatort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = separator_implements, class TExtends = separator_extends>
class _EXPORT_CLASS separatort
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    separatort
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~separatort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::create_detached;
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        detached = this->create_detached(GTK_ORIENTATION_VERTICAL);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef separatort<> separator;
} // namespace vertical

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_SEPARATOR_HPP
