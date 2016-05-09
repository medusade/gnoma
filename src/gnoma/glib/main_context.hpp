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
///   File: main_context.hpp
///
/// Author: $author$
///   Date: 5/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GLIB_MAIN_CONTEXT_HPP
#define _GNOMA_GLIB_MAIN_CONTEXT_HPP

#include "gnoma/glib/glib.hpp"

namespace gnoma {
namespace glib {

typedef GMainContext* main_context_attached_t;
typedef xos::base::creatort<implement_base> main_context_creator;
typedef xos::base::attachert<main_context_attached_t, int, 0, main_context_creator> main_context_attacher;
typedef xos::base::attachedt<main_context_attached_t, int, 0, main_context_attacher, base> main_context_attached;
typedef xos::base::createdt<main_context_attached_t, int, 0, main_context_attacher, main_context_attached> main_context_created;
typedef main_context_attacher main_context_implements;
typedef main_context_created main_context_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_contextt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_context_implements, class TExtends = main_context_extends>
class _EXPORT_CLASS main_contextt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_contextt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~main_contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        attached_t detached = 0;
        if ((detached = create_attached())) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached())) {
                this->attach(detached);
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("g_main_context_new()...");
        if ((detached = g_main_context_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = g_main_context_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = g_main_context_new()");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        bool success = false;
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("g_main_context_unref(detached = " << gpointer_to_string(detached) << ")...");
            g_main_context_unref(detached);
            GNOMA_LOG_MESSAGE_DEBUG("...g_main_context_unref(detached = " << gpointer_to_string(detached) << ")");
            success = true;
        }
        return success;
    }
    virtual operator attached_t () const {
        return this->attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_contextt<> main_context;

} // namespace glib 
} // namespace gnoma 

#endif // _GNOMA_GLIB_MAIN_CONTEXT_HPP 
        

