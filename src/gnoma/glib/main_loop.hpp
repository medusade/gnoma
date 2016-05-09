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
///   File: main_loop.hpp
///
/// Author: $author$
///   Date: 5/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GLIB_MAIN_LOOP_HPP
#define _GNOMA_GLIB_MAIN_LOOP_HPP

#include "gnoma/glib/glib.hpp"

namespace gnoma {
namespace glib {

typedef GMainLoop* main_loop_attached_t;
typedef xos::base::creatort<implement_base> main_loop_creator;
typedef xos::base::attachert<main_loop_attached_t, int, 0, main_loop_creator> main_loop_attacher;
typedef xos::base::attachedt<main_loop_attached_t, int, 0, main_loop_attacher, base> main_loop_attached;
typedef xos::base::createdt<main_loop_attached_t, int, 0, main_loop_attacher, main_loop_attached> main_loop_created;
typedef main_loop_attacher main_loop_implements;
typedef main_loop_created main_loop_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_loopt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_loop_implements, class TExtends= main_loop_extends>
class _EXPORT_CLASS main_loopt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_loopt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~main_loopt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (GMainContext *context, gboolean is_running = FALSE) {
        attached_t detached = 0;
        if ((detached = create_attached(context, is_running))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual attached_t create_attached
    (GMainContext *context, gboolean is_running = FALSE) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(context, is_running))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached
    (GMainContext *context, gboolean is_running = FALSE) const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("g_main_loop_new(context = " << gpointer_to_string(context) << ", is_running = " << gboolean_to_string(is_running) << ")...");
        if ((detached = g_main_loop_new(context, is_running))) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = g_main_loop_new(context = " << gpointer_to_string(context) << ", is_running = " << gboolean_to_string(is_running) << ")");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = g_main_loop_new(context = " << gpointer_to_string(context) << ", is_running = " << gboolean_to_string(is_running) << ")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        bool success = false;
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("g_main_loop_unref(detached = " << gpointer_to_string(detached) << ")...");
            g_main_loop_unref(detached);
            GNOMA_LOG_MESSAGE_DEBUG("...g_main_loop_unref(detached = " << gpointer_to_string(detached) << ")");
            success = true;
        }
        return success;
    }
    virtual operator attached_t () const {
        return this->attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool run() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("g_main_loop_run(detached = " << gpointer_to_string(detached) << ")...");
            g_main_loop_run(detached);
            GNOMA_LOG_MESSAGE_DEBUG("...g_main_loop_run(detached = " << gpointer_to_string(detached) << ")");
            return true;
        }
        return false;
    }
    virtual bool quit() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            GNOMA_LOG_MESSAGE_DEBUG("...g_main_loop_quit(detached = " << gpointer_to_string(detached) << ")");
            g_main_loop_quit(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_loopt<> main_loop;

} // namespace glib 
} // namespace gnoma 

#endif // _GNOMA_GLIB_MAIN_LOOP_HPP 
