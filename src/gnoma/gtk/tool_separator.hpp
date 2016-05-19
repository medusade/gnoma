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
///   File: tool_separator.hpp
///
/// Author: $author$
///   Date: 5/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_TOOL_SEPARATOR_HPP
#define _GNOMA_GTK_TOOL_SEPARATOR_HPP

#include "gnoma/gtk/widget.hpp"

namespace gnoma {
namespace gtk {

typedef widget_implements tool_separator_implements;
typedef widget tool_separator_extends;
///////////////////////////////////////////////////////////////////////
///  Class: tool_separatort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = tool_separator_implements, class TExtends = tool_separator_extends>
class _EXPORT_CLASS tool_separatort
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tool_separatort
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~tool_separatort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((detached = create_detached())) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_separator_tool_item_new()...");
        if ((detached = GTK_WIDGET(gtk_separator_tool_item_new()))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gtk_separator_tool_item_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gtk_separator_tool_item_new()");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef tool_separatort<> tool_separator;

} // namespace gtk
} // namespace gnoma

#endif // _GNOMA_GTK_TOOL_SEPARATOR_HPP


