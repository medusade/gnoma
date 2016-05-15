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
///   File: application_main.hpp
///
/// Author: $author$
///   Date: 5/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GTK_APPLICATION_MAIN_HPP
#define _GNOMA_GTK_APPLICATION_MAIN_HPP

#include "gnoma/gtk/main.hpp"
#include "gnoma/gtk/application.hpp"

#define GNOMA_GUI_GTK_APPLICATION_FLAGS G_APPLICATION_FLAGS_NONE
#define GNOMA_GUI_GTK_APPLICATION_ID "gnoma.gtk.application"

namespace gnoma {
namespace gtk {

typedef gnoma::gtk::main_implements application_main_implements;
typedef gnoma::gtk::main application_main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: application_maint
///////////////////////////////////////////////////////////////////////
template
<class TSignalsImplements = application_signals,
 class TImplements = application_main_implements,
 class TExtends = application_main_extends>

class _EXPORT_CLASS application_maint
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TSignalsImplements application_signals_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    application_maint()
    : application_id_(GNOMA_GUI_GTK_APPLICATION_ID),
      application_flags_(GNOMA_GUI_GTK_APPLICATION_FLAGS),
      application_detached_(0),
      application_(this) {
    }
    virtual ~application_maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int gtk_main(int argc, char** argv, char** env) {
        int err = 0;
        int application_argc = 0;
        char** application_argv = 0;
        GtkApplication*& application = application_detached_;

        if ((application)) {
            GNOMA_LOG_MESSAGE_DEBUG("gtk_application_run()...");
            if ((err = g_application_run
                 (G_APPLICATION(application), application_argc, application_argv))) {
                GNOMA_LOG_ERROR("failed " << err << " on g_application_run()");
            } else {
                GNOMA_LOG_MESSAGE_DEBUG("...gtk_application_run()");
            }
        }
        return err;
    }
    virtual int before_gtk_main(int argc, char** argv, char** env) {
        int err = 0;
        const gchar* application_id = application_id_.chars();
        GApplicationFlags application_flags =  application_flags_;
        GtkApplication*& application = application_detached_;

        if (!(err = before_create_application
             (application_id, application_flags, argc,argv,env))) {

            if ((application = create_application
                 (application_id, application_flags, argc,argv,env))) {
                int err2 = 0;

                if (!(err = after_create_application
                     (application, application_id, application_flags, argc,argv,env))) {

                    if ((connect_signal_activate(application))) {
                        return err;
                    } else {
                        GNOMA_LOG_ERROR("failed on connect_signal_activate()");
                    }
                } else {
                    GNOMA_LOG_ERROR("failed on after_create_application()");
                }
                if ((err2 = destroy_application
                    (application, application_id, application_flags, argc,argv,env))) {
                    GNOMA_LOG_ERROR("failed on destroy_application()");
                    if (!(err)) err = err2;
                }
            } else {
                GNOMA_LOG_ERROR("failed on create_application()");
            }
        } else {
            GNOMA_LOG_ERROR("failed on before_create_application()");
        }
        return err;
    }
    virtual int after_gtk_main(int argc, char** argv, char** env) {
        int err = 0, err2 = 0;
        const gchar* application_id = application_id_.chars();
        GApplicationFlags application_flags =  application_flags_;
        GtkApplication*& application = application_detached_;

        if (!(disconnect_signal_activate(application))) {
            GNOMA_LOG_ERROR("failed on disconnect_signal_activate()");
            if (!(err)) err = 1;
        }
        if ((err2 = destroy_application
            (application, application_id, application_flags, argc,argv,env))) {
            GNOMA_LOG_ERROR("failed on destroy_application()");
            if (!(err)) err = err2;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkApplication* create_application
    (const gchar* application_id, GApplicationFlags application_flags,
     int argc, char** argv, char** env) {
        GtkApplication* application = 0;
        application = application_.create_attached(application_id, application_flags);
        return application;
    }
    virtual int destroy_application
    (GtkApplication* application,
     const gchar* application_id, GApplicationFlags application_flags,
     int argc, char** argv, char** env) {
        if ((application) && (application == (application_.attached_to()))) {
            if ((application_.destroy())) {
                return 0;
            }
        }
        return 1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_create_application
    (const gchar* application_id, GApplicationFlags application_flags,
     int argc, char** argv, char** env) {
        return 0;
    }
    virtual int after_create_application
    (GtkApplication* application,
     const gchar* application_id, GApplicationFlags application_flags,
     int argc, char** argv, char** env) {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_activate(GtkApplication* detached) {
        if ((detached) && (detached == (application_.attached_to()))) {
            if ((application_.connect_signal_activate())) {
                return true;
            }
        }
        return false;
    }
    virtual bool disconnect_signal_activate(GtkApplication* detached) {
        if ((detached) && (detached == (application_.attached_to()))) {
            if ((application_.disconnect_signal_activate())) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkApplication* set_application(GtkApplication* to) {
        application_detached_ = to;
        return application_detached_;
    }
    virtual GtkApplication* application() const {
        return application_detached_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    gstring application_id_;
    GApplicationFlags application_flags_;
    GtkApplication* application_detached_;
    gtk::application application_;
};
typedef application_maint<> application_main;

} // namespace gtk 
} // namespace gnoma 

#endif // _GNOMA_GTK_APPLICATION_MAIN_HPP 
