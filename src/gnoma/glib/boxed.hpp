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
///   File: boxed.hpp
///
/// Author: $author$
///   Date: 5/7/2016
///////////////////////////////////////////////////////////////////////
#ifndef _GNOMA_GLIB_BOXED_HPP
#define _GNOMA_GLIB_BOXED_HPP

#include "gnoma/glib/glib.hpp"

namespace gnoma {
namespace glib {

///////////////////////////////////////////////////////////////////////
///  Class: boxed_implementst
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS boxed_implementst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef boxed_implementst<> boxed_implements;
typedef base boxed_extends;
///////////////////////////////////////////////////////////////////////
///  Class: boxedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = boxed_implements, class TExtends = boxed_extends>

class _EXPORT_CLASS boxedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    boxedt() {
    }
    virtual ~boxedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef boxedt<> boxed;

} // namespace glib
} // namespace gnoma 

#endif // _GNOMA_GLIB_BOXED_HPP 
