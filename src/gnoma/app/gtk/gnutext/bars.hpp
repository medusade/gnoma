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
///   File: bars.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_APP_GTK_GNUTEXT_BARS_HPP
#define _GNOMA_APP_GTK_GNUTEXT_BARS_HPP

#include "gnoma/gtk/box.hpp"

namespace gnoma {
namespace app {
namespace gtk {
namespace gnutext {

typedef gnoma::gtk::vertical::box_implements bars_implements;
typedef gnoma::gtk::vertical::box bars_extends;
///////////////////////////////////////////////////////////////////////
///  Class: barst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = bars_implements, class TExtends = bars_extends>
class _EXPORT_CLASS barst
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    barst
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~barst() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef barst<> bars;

} // namespace gnutext
} // namespace gtk
} // namespace app
} // namespace gnoma

#endif // _GNOMA_APP_GTK_GNUTEXT_BARS_HPP
