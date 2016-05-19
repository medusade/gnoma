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
///   File: panels.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_APP_GTK_GNUTEXT_PANELS_HPP
#define _GNOMA_APP_GTK_GNUTEXT_PANELS_HPP

#include "gnoma/gtk/box.hpp"

namespace gnoma {
namespace app {
namespace gtk {
namespace gnutext {

typedef gnoma::gtk::horizontal::box_implements panels_implements;
typedef gnoma::gtk::horizontal::box panels_extends;
///////////////////////////////////////////////////////////////////////
///  Class: panelst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = panels_implements, class TExtends = panels_extends>
class _EXPORT_CLASS panelst
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    panelst
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~panelst() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef panelst<> panels;

} // namespace gnutext
} // namespace gtk
} // namespace app
} // namespace gnoma

#endif // _GNOMA_APP_GTK_GNUTEXT_PANELS_HPP


