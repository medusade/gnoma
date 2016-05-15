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
///   Date: 5/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_MAIN_HPP
#define _GNOMA_GTK_MAIN_HPP

#include "gnoma/console/main.hpp"
#include "gnoma/gtk/gtk.hpp"

namespace gnoma {
namespace gtk {

typedef console::main_implements main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        int err = 0;
        if (!(err = before_gtk_main(argc, argv, env))) {
            int err2 = 0;
            err = gtk_main(argc, argv, env);
            if ((err = after_gtk_main(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int before_run(int argc, char** argv, char** env) {
        int err = 0;
        gint gargc = 0;
        gchar** gargv = 0;

        GNOMA_LOG_MESSAGE_DEBUG("gtk_init_check(&gargc, &gargv)...");
        if ((gtk_init_check(&gargc, &gargv))) {
            GNOMA_LOG_MESSAGE_DEBUG("...gtk_init_check(&gargc, &gargv)");
        } else {
            GNOMA_LOG_ERROR("...failed on gtk_init_check(&gargc, &gargv)");
            err = 1;
        }
        return err;
    }
    virtual int after_run(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int gtk_main(int argc, char** argv, char** env) {
        int err = 0;
        GNOMA_LOG_MESSAGE_DEBUG("gtk_main()...");
        ::gtk_main();
        GNOMA_LOG_MESSAGE_DEBUG("...gtk_main()");
        return err;
    }
    virtual int before_gtk_main(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_gtk_main(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace gtk 
} // namespace gnoma 

#endif // _GNOMA_GTK_MAIN_HPP 
