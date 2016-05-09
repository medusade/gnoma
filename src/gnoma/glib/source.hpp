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
///   File: source.hpp
///
/// Author: $author$
///   Date: 5/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GLIB_SOURCE_HPP
#define _GNOMA_GLIB_SOURCE_HPP

#include "gnoma/glib/source_signals.hpp"
#include "gnoma/glib/glib.hpp"

namespace gnoma {
namespace glib {

typedef GSource* source_attached_t;
typedef xos::base::creatort<implement_base> source_creator;
typedef xos::base::attachert<source_attached_t, int, 0, source_creator> source_attacher;
typedef xos::base::attachedt<source_attached_t, int, 0, source_attacher, base> source_attached;
typedef xos::base::createdt<source_attached_t, int, 0, source_attacher, source_attached> source_created;
typedef source_signals source_signals_implements;
typedef source_attacher source_implements;
typedef source_created source_extends;
///////////////////////////////////////////////////////////////////////
///  Class: sourcet
///////////////////////////////////////////////////////////////////////
template
<class TSignalsImplements = source_signals_implements,
 class TImplements = source_implements, class TExtends = source_extends>
class _EXPORT_CLASS sourcet
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    typedef TSignalsImplements source_signals_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sourcet
    (source_signals_t* source_signals_forward_to = 0,
     attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      source_signals_forward_to_(source_signals_forward_to) {
    }
    virtual ~sourcet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool destroy_detached(attached_t detached) const {
        bool success = false;
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("g_source_unref(detached = " << gpointer_to_string(detached) << ")...");
            g_source_unref(detached);
            GNOMA_LOG_MESSAGE_DEBUG("...g_source_unref(detached = " << gpointer_to_string(detached) << ")");
            success = true;
        }
        return success;
    }
    virtual operator attached_t () const {
        return this->attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_callback() {
        if ((set_callback
             (this->source_signal_source_func_callback,
              ((gpointer)((source_signals_t*)this)),
              this->source_signal_destroy_notify_callback))) {
            return true;
        }
        return false;
    }
    virtual bool set_callback
    (GSourceFunc func, gpointer data, GDestroyNotify notify) {
        if ((func)) {
            attached_t detached = 0;
            if ((detached = this->attached_to())) {
                GNOMA_LOG_MESSAGE_DEBUG("...g_source_set_callback(detached = " << gpointer_to_string(detached) << ", func = " << gnoma_pointer_to_string(func) << ", data = " << gpointer_to_string(data) << ", notify = " << gnoma_pointer_to_string(notify) << ")");
                g_source_set_callback(detached, func, data, notify);
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::attach;
    virtual guint attach(GMainContext* context) {
        if ((context)) {
            attached_t detached = 0;
            if ((detached = this->attached_to())) {
                guint id = 0;
                GNOMA_LOG_MESSAGE_DEBUG("g_source_attach(detached = " << gpointer_to_string(detached) << ", context = " << gpointer_to_string(context) << ")...");
                if ((id = g_source_attach(detached, context))) {
                    GNOMA_LOG_MESSAGE_DEBUG("..." << id << " = g_source_attach(detached = " << gpointer_to_string(detached) << ", context = " << gpointer_to_string(context) << ")");
                    return id;
                } else {
                    GNOMA_LOG_MESSAGE_DEBUG("...failed 0 on g_source_attach(detached = " << gpointer_to_string(detached) << ", context = " << gpointer_to_string(context) << ")");
                }
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual source_signals_t* forward_source_signals_to(source_signals_t* to) {
        source_signals_forward_to_ = to;
        return source_signals_forward_to_;
    }
    virtual source_signals_t* source_signals_forward_to() const {
        return source_signals_forward_to_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    source_signals_t* source_signals_forward_to_;
};
typedef sourcet<> source;

typedef glib::source_implements timeout_source_implements;
typedef glib::source timeout_source_extends;
///////////////////////////////////////////////////////////////////////
///  Class: timeout_sourcet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = timeout_source_implements,
 class TExtends = timeout_source_extends>
class _EXPORT_CLASS timeout_sourcet
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::source_signals_t source_signals_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    timeout_sourcet
    (source_signals_t* source_signals_forward_to = 0,
     attached_t detached = 0, bool is_created = false)
    : Extends(source_signals_forward_to, detached, is_created) {
    }
    virtual ~timeout_sourcet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(guint interval) {
        attached_t detached = 0;
        if ((detached = create_attached(interval))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual attached_t create_attached(guint interval) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(interval))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached(guint interval) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("g_timeout_source_new(interval = " << interval << ")...");
        if ((detached = g_timeout_source_new(interval))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = g_timeout_source_new(interval = " << interval << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = g_timeout_source_new(interval = " << interval << ")");
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef timeout_sourcet<> timeout_source;

} // namespace glib
} // namespace gnoma 

#endif // _GNOMA_GLIB_SOURCE_HPP 
