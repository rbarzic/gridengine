#ifndef __MSG_QCONF_H
#define __MSG_QCONF_H
/*___INFO__MARK_BEGIN__*/
/*************************************************************************
 * 
 *  The Contents of this file are made available subject to the terms of
 *  the Sun Industry Standards Source License Version 1.2
 * 
 *  Sun Microsystems Inc., March, 2001
 * 
 * 
 *  Sun Industry Standards Source License Version 1.2
 *  =================================================
 *  The contents of this file are subject to the Sun Industry Standards
 *  Source License Version 1.2 (the "License"); You may not use this file
 *  except in compliance with the License. You may obtain a copy of the
 *  License at http://gridengine.sunsource.net/Gridengine_SISSL_license.html
 * 
 *  Software provided under this License is provided on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
 *  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
 *  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
 *  See the License for the specific provisions governing your rights and
 *  obligations concerning the Software.
 * 
 *   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
 * 
 *   Copyright: 2001 by Sun Microsystems, Inc.
 * 
 *   All Rights Reserved.
 * 
 ************************************************************************/
/*___INFO__MARK_END__*/

#include "basis_types.h"

#define MSG_GDI_USERINACL_SS          _MESSAGE(5000, _(SFQ" is already in access list "SFQ"\n"))
#define MSG_GDI_CANTADDTOACL_SS       _MESSAGE(5001, _("can't add "SFQ" to access list "SFQ"\n"))
#define MSG_GDI_ADDTOACL_SS           _MESSAGE(5002, _("added "SFQ" to access list "SFQ"\n"))
#define MSG_GDI_ACLDOESNOTEXIST_S     _MESSAGE(5003, _("access list "SFQ" doesn't exist\n"))
#define MSG_GDI_USERNOTINACL_SS       _MESSAGE(5004, _("user "SFQ" is not in access list "SFQ"\n"))
#define MSG_GDI_CANTDELFROMACL_SS     _MESSAGE(5005, _("can't delete user "SFQ" from access list "SFQ"\n"))
#define MSG_GDI_DELFROMACL_SS         _MESSAGE(5006, _("deleted user "SFQ" from access list "SFQ"\n"))
#define MSG_HOST_NEEDAHOSTNAMEORALL   _MESSAGE(5007, _("Need a hostname or the keyword \"all\"\n"))

#define MSG_PARSE_NOOPTIONARGPROVIDEDTOX_S  _MESSAGE(5008, _("no option argument provided to "SFQ""))

#define MSG_CUSER_DOESNOTEXIST_S      _MESSAGE(5012, _("User mapping entry "SFQ" does not exist\n"))
#define MSG_CUSER_FILENOTCORRECT_S    _MESSAGE(5013, _("User mapping file "SFQ" is not correct\n"))

#endif /* __MSG_QCONF_H */

