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

#include "gnoma/gdk/app_launch_context.hpp"
#include "gnoma/gdk/window.hpp"
#include "gnoma/gdk/window_attr.hpp"
#include "gnoma/gdk/display.hpp"
#include "gnoma/gdk/screen.hpp"
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
            GdkDisplay* display_detached = 0;
            gnoma::gdk::display display;

            if ((display_detached = display.open_attached())) {
                GdkScreen* screen_detached = 0;
                gnoma::gdk::screen screen;

                if ((screen_detached = screen.create_attached(display_detached))) {
                    GdkAppLaunchContext* context_detached = 0;
                    gnoma::gdk::app_launch_context context;

                    if ((context_detached = context.create_attached())) {
                        GdkWindow* window_detached = 0;

                        if ((window_detached = screen.get_root_window())) {
                            gnoma::gdk::window_attr window_attr;
                            gnoma::gdk::window window;

                            if ((window_detached = window.create_attached
                                 (window_detached, window_attr, window_attr.mask()))) {
                                GdkEvent* event = 0;

                                window.show();
                                do {
                                    //GNOMA_LOG_MESSAGE_DEBUG("gdk_event_get()...");
                                    if ((event = gdk_event_get())) {
                                        GNOMA_LOG_MESSAGE_DEBUG("...gdk_event_get()");
                                        gdk_event_free(event);
                                    } else {
                                        //GNOMA_LOG_MESSAGE_DEBUG("...failed on gdk_event_get()");
                                    }
                                } while (true);
                                sleep(5);
                                window.hide();
                                window.destroy();
                            }
                        }
                    }
                }
                display.close();
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
