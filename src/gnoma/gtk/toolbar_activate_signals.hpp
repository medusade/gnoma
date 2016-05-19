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
///   File: toolbar_activate_signals.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOLBAR_ACTIVATE_SIGNALS_HPP
#define _GNOMA_GTK_TOOLBAR_ACTIVATE_SIGNALS_HPP

#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

///////////////////////////////////////////////////////////////////////
/// Struct: toolbar_activate_signalst
///////////////////////////////////////////////////////////////////////
template <class TSignals>
struct toolbar_activate_signalst {
    gint id;
    TSignals* to;
    GtkToolItem* toolitem;
    GtkToolbar* toolbar;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    toolbar_activate_signalst
    (gint _id, TSignals* _to,
     GtkToolItem* _toolitem, GtkToolbar* _toolbar)
    : id(_id), to(_to),
      toolitem(_toolitem), toolbar(_toolbar) {
    }
    toolbar_activate_signalst(const toolbar_activate_signalst& copy)
    : id(copy._id), to(copy.to),
      toolitem(copy.toolitem), toolbar(copy.toolbar) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOLBAR_ACTIVATE_SIGNALS_HPP
        

