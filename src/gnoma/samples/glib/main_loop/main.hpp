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
///   Date: 5/7/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_SAMPLES_GLIB_MAIN_LOOP_MAIN_HPP
#define _GNOMA_SAMPLES_GLIB_MAIN_LOOP_MAIN_HPP

#include "gnoma/glib/main_loop.hpp"
#include "gnoma/glib/main_context.hpp"
#include "gnoma/glib/source.hpp"
#include "gnoma/glib/main.hpp"

namespace gnoma {
namespace samples {
namespace glib {
namespace main_loop {

typedef gnoma::glib::main_implements main_implements;
typedef gnoma::glib::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public gnoma::glib::source_signals,
  virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): loop_(0) {
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gboolean on_source_signal_source_func(gpointer data) {
        g_main_loop_quit(loop_);
        return FALSE;
    }
    virtual void on_source_signal_destroy_notify(gpointer data) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        int err = 0;
        guint interval = 1000;
        GSource *source_detached = 0;
        gnoma::glib::timeout_source source(this);

        if ((source_detached = source.create_attached(interval))) {
            GMainContext *context_detached = 0;
            gnoma::glib::main_context context;

            if ((context_detached = context.create_attached())) {
                guint source_id = 0;

                if ((source_id = g_source_attach(source_detached, context_detached))) {

                    if ((loop_ = gnoma::glib::main_loop().create_detached(context_detached))) {
                        context_detached = 0;

                        source.set_callback();
                        g_main_loop_run(loop_);

                        if ((loop_)) {
                            gnoma::glib::main_loop().destroy_detached(loop_);
                        }
                    }
                }
                if ((context_detached)) {
                    context.destroy();
                }
            }
            if ((source_detached)) {
                source.destroy();
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    GMainLoop *loop_;
};

} // namespace main_loop 
} // namespace glib 
} // namespace samples 
} // namespace gnoma 

#endif // _GNOMA_SAMPLES_GLIB_MAIN_LOOP_MAIN_HPP 
