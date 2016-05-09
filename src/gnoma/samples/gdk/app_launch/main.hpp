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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_SAMPLES_GDK_APP_LAUNCH_MAIN_HPP
#define _GNOMA_SAMPLES_GDK_APP_LAUNCH_MAIN_HPP

#include "gnoma/gdk/main.hpp"

namespace gnoma {
namespace samples {
namespace gdk {
namespace app_launch {

typedef gnoma::gdk::main_implements main_implements;
typedef gnoma::gdk::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        int err = 0;
        gint gargc = 0;
        gchar** gargv = 0;

        GNOMA_LOG_MESSAGE_DEBUG("gdk_init_check(&gargc, &gargv)...");
        if ((gdk_init_check(&gargc, &gargv))) {
            GdkDisplay* display = 0;

            GNOMA_LOG_MESSAGE_DEBUG("...gdk_init_check(&gargc, &gargv)");

            GNOMA_LOG_MESSAGE_DEBUG("gdk_display_get_default()...");
            if ((display = gdk_display_get_default())) {
                const gchar* display_name = 0;

                GNOMA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(display) << " = gdk_display_get_default()");

                GNOMA_LOG_MESSAGE_DEBUG("gdk_display_get_name(display = " << pointer_to_string(display) << ")...");
                if ((display_name = gdk_display_get_name(display))) {
                    GNOMA_LOG_MESSAGE_DEBUG("...\"" << display_name << "\" = gdk_display_get_name(display = " << pointer_to_string(display) << ")");

                    GNOMA_LOG_MESSAGE_DEBUG("gdk_display_open(display_name = \"" << display_name << "\")...");
                    if ((display = gdk_display_open(display_name))) {
                        GNOMA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(display) << " = gdk_display_open(display_name = \"" << display_name << "\")");

                        GNOMA_LOG_MESSAGE_DEBUG("...gdk_display_close(display = " << pointer_to_string(display) << ")");
                        gdk_display_close(display);
                    } else {
                        GNOMA_LOG_MESSAGE_DEBUG("...failed 0 = gdk_display_open(display_name = \"" << display_name << "\")");
                    }
                } else {
                    GNOMA_LOG_MESSAGE_DEBUG("...failed 0 = gdk_display_get_name(display = " << pointer_to_string(display) << ")");
                }
            } else {
                GNOMA_LOG_MESSAGE_DEBUG("...failed 0 = gdk_display_get_default()");
            }
        } else {
            GNOMA_LOG_MESSAGE_DEBUG("...failed on gdk_init_check(&gargc, &gargv)");
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace app_launch 
} // namespace gdk 
} // namespace samples 
} // namespace gnoma 

#endif // _GNOMA_SAMPLES_GDK_APP_LAUNCH_MAIN_HPP 
