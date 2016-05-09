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
///   File: source_signals.hpp
///
/// Author: $author$
///   Date: 5/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GLIB_SOURCE_SIGNALS_HPP
#define _GNOMA_GLIB_SOURCE_SIGNALS_HPP

#include "gnoma/glib/glib.hpp"

namespace gnoma {
namespace glib {

///////////////////////////////////////////////////////////////////////
///  Class: source_signalst
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS source_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gboolean on_source_signal_source_func(gpointer data) {
        source_signalst* to = this->source_signals_forward_to();
        GNOMA_LOG_MESSAGE_DEBUG("...on_source_signal_source_func(data = " << gpointer_to_string(data) << ")");
        if ((to)) {
            return to->on_source_signal_source_func(data);
        }
        return FALSE;
    }
    static gboolean source_signal_source_func_callback(gpointer data) {
        source_signalst* to = ((source_signalst*)data);
        GNOMA_LOG_MESSAGE_DEBUG("...source_signal_source_func_callback(data = " << gpointer_to_string(data) << ")");
        if ((to)) {
            return to->on_source_signal_source_func(data);
        }
        return FALSE;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_source_signal_destroy_notify(gpointer data) {
        source_signalst* to = this->source_signals_forward_to();
        GNOMA_LOG_MESSAGE_DEBUG("...on_source_signal_destroy_notify(data = " << gpointer_to_string(data) << ")");
        if ((to)) {
            return to->on_source_signal_destroy_notify(data);
        }
    }
    static void source_signal_destroy_notify_callback(gpointer data) {
        source_signalst* to = ((source_signalst*)data);
        GNOMA_LOG_MESSAGE_DEBUG("...source_signal_destroy_notify_callback(data = " << gpointer_to_string(data) << ")");
        if ((to)) {
            return to->on_source_signal_destroy_notify(data);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual source_signalst* forward_source_signals_to(source_signalst* to) {
        return 0;
    }
    virtual source_signalst* source_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef source_signalst<> source_signals;

} // namespace glib
} // namespace gnoma 

#endif // _GNOMA_GLIB_SOURCE_SIGNALS_HPP 
