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
///   File: app_launch_context.hpp
///
/// Author: $author$
///   Date: 5/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GDK_APP_LAUNCH_CONTEXT_HPP
#define _GNOMA_GDK_APP_LAUNCH_CONTEXT_HPP

#include "gnoma/gdk/gdk.hpp"

namespace gnoma {
namespace gdk {

typedef GdkAppLaunchContext* app_launch_context_attached_t;
typedef xos::base::creatort<implement_base> app_launch_context_creator;
typedef xos::base::attachert<app_launch_context_attached_t, int, 0, app_launch_context_creator> app_launch_context_attacher;
typedef xos::base::attachedt<app_launch_context_attached_t, int, 0, app_launch_context_attacher, base> app_launch_context_attached;
typedef xos::base::createdt<app_launch_context_attached_t, int, 0, app_launch_context_attacher, app_launch_context_attached> app_launch_context_created;
typedef app_launch_context_attacher app_launch_context_implements;
typedef app_launch_context_created app_launch_context_extends;
///////////////////////////////////////////////////////////////////////
///  Class: app_launch_contextt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = app_launch_context_implements,
 class TExtends = app_launch_context_extends>
class _EXPORT_CLASS app_launch_contextt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    app_launch_contextt
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~app_launch_contextt() {
        if (!(this->destroyed())) {
            const creator_exception e = failed_to_destroy;
            GNOMA_LOG_ERROR("...failed this->destroyed() throw(creator_exception e = failed_to_destroy = " << failed_to_destroy << ")...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gdk_app_launch_context_new()...");
        if ((detached = gdk_app_launch_context_new())) {
            GNOMA_LOG_MESSAGE_DEBUG("..." << gpointer_to_string(detached) << " = gdk_app_launch_context_new()");
        } else {
            GNOMA_LOG_ERROR("...failed 0 = gdk_app_launch_context_new()");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            GNOMA_LOG_MESSAGE_DEBUG("g_object_unref(detached = " << gpointer_to_string(detached) << ")...");
            g_object_unref(detached);
            return true;
        } else {
            GNOMA_LOG_ERROR("...detached = 0");
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef app_launch_contextt<> app_launch_context;

} // namespace gdk 
} // namespace gnoma 

#endif // _GNOMA_GDK_APP_LAUNCH_CONTEXT_HPP 
