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

#include "sgermon.h"
#include "sge_string.h"
#include "sge_log.h"
#include "cull_list.h"
#include "symbols.h"
#include "sge.h"

#include "sge_attr.h"
#include "sge_cqueue.h"
#include "sge_qinstance.h"

#include "msg_common.h"
#include "msg_sgeobjlib.h"

#define QINSTANCE_LAYER BASIS_LAYER

lListElem * 
qinstance_create(const lListElem *cqueue, lList **answer_list,
                 const char *hostname, bool *is_ambiguous) 
{
   lListElem *ret = NULL;
   int index;

   DENTER(QINSTANCE_LAYER, "qinstance_create");
   
   ret = lCreateElem(QI_Type);
   lSetHost(ret, QI_hostname, hostname);
   lSetString(ret, QI_name, lGetString(cqueue, CQ_name));

   index = 0;
   while (cqueue_attribute_array[index].cqueue_attr != NoName) {
      bool tmp_is_ambiguous = false;
      bool tmp_has_changed = false;

      qinstance_modify(ret, answer_list, cqueue, 
                       cqueue_attribute_array[index].qinstance_attr,
                       cqueue_attribute_array[index].cqueue_attr, 
                       cqueue_attribute_array[index].href_attr,
                       cqueue_attribute_array[index].value_attr,
                       cqueue_attribute_array[index].primary_key_attr,
                       &tmp_is_ambiguous, &tmp_has_changed);
      if (tmp_is_ambiguous) {
         /* EB: TODO: move to msg file */ 
         WARNING(("Attribute "SFQ" has ambiguous value for host "SFQ"\n",
                  cqueue_attribute_array[index].name, hostname));
         *is_ambiguous = tmp_is_ambiguous;
      }
      index++;
   }

   DEXIT;
   return ret;
}

bool
qinstance_modify(lListElem *this_elem, lList **answer_list,
                 const lListElem *cqueue, 
                 int attribute_name, 
                 int cqueue_attibute_name,
                 int sub_host_name, int sub_value_name,
                 int subsub_key, bool *is_ambiguous, bool *has_changed)
{
#define QINSTANCE_MODIFY_DEBUG
   bool ret = true;
  
#ifdef QINSTANCE_MODIFY_DEBUG 
   DENTER(TOP_LAYER, "qinstance_modify");
#else
   DENTER(QINSTANCE_LAYER, "qinstance_modify");
#endif

   if (this_elem != NULL && cqueue != NULL && 
       attribute_name != NoName && cqueue_attibute_name != NoName) {
      const char *hostname = lGetHost(this_elem, QI_hostname);
      const lList *attr_list = lGetList(cqueue, cqueue_attibute_name);
      const lDescr *descr = lGetElemDescr(this_elem);
      int pos = lGetPosInDescr(descr, attribute_name);
      int type = lGetPosType(descr, pos);
      bool value_found = true;
      lList *list_value = NULL;

      switch (cqueue_attibute_name) {
         case CQ_qtype:
            {
               u_long32 old_value = lGetUlong(this_elem, attribute_name);
               u_long32 new_value;

               qtlist_attr_list_find_value(attr_list, answer_list, 
                                           hostname, &new_value,
                                           is_ambiguous);
               if (old_value != new_value) {
#ifdef QINSTANCE_MODIFY_DEBUG
                  DPRINTF(("Changed "SFQ" from "u32" to "u32"\n",
                           lNm2Str(attribute_name), old_value, new_value));
#endif
                  lSetUlong(this_elem, attribute_name, new_value);
                  *has_changed = true;
               }
            }
            break;
         case CQ_s_fsize:
         case CQ_h_fsize:
         case CQ_s_data:
         case CQ_h_data:
         case CQ_s_stack:
         case CQ_h_stack:
         case CQ_s_core:
         case CQ_h_core:
         case CQ_s_rss:
         case CQ_h_rss:
         case CQ_s_vmem:
         case CQ_h_vmem:
            {
               const char *old_value = lGetString(this_elem, attribute_name);
               const char *new_value;

               mem_attr_list_find_value(attr_list, answer_list, 
                                        hostname, &new_value, is_ambiguous);
               if (old_value == NULL || new_value == NULL ||
                   strcmp(old_value, new_value)) {
#ifdef QINSTANCE_MODIFY_DEBUG
                  DPRINTF(("Changed "SFQ" from "SFQ" to "SFQ"\n",
                           lNm2Str(attribute_name),
                           old_value ? old_value : "<null>",
                           new_value ? new_value : "<null>")); 
#endif
                  lSetString(this_elem, attribute_name, new_value);
                  *has_changed = true;
               }
            }
            break;
         case CQ_s_rt:
         case CQ_h_rt:
         case CQ_s_cpu:
         case CQ_h_cpu:
            {
               const char *old_value = lGetString(this_elem, attribute_name);
               const char *new_value;

               time_attr_list_find_value(attr_list, answer_list, 
                                         hostname, &new_value, is_ambiguous);
               if (old_value == NULL || new_value == NULL ||
                   strcmp(old_value, new_value)) {
#ifdef QINSTANCE_MODIFY_DEBUG
                  DPRINTF(("Changed "SFQ" from "SFQ" to "SFQ"\n",
                           lNm2Str(attribute_name),
                           old_value ? old_value : "<null>",
                           new_value ? new_value : "<null>")); 
#endif
                  lSetString(this_elem, attribute_name, new_value);
                  *has_changed = true;
               }
            }
            break;
         case CQ_suspend_interval:
         case CQ_min_cpu_interval:
         case CQ_notify:
            {
               const char *old_value = lGetString(this_elem, attribute_name);
               const char *new_value;

               inter_attr_list_find_value(attr_list, answer_list, 
                                          hostname, &new_value, is_ambiguous);
               if (old_value == NULL || new_value == NULL ||
                   strcmp(old_value, new_value)) {
#ifdef QINSTANCE_MODIFY_DEBUG
                  DPRINTF(("Changed "SFQ" from "SFQ" to "SFQ"\n",
                           lNm2Str(attribute_name),
                           old_value ? old_value : "<null>",
                           new_value ? new_value : "<null>"));
#endif
                  lSetString(this_elem, attribute_name, new_value);
                  *has_changed = true;
               }
            }
            break;
         case CQ_ckpt_list:
         case CQ_pe_list:
            strlist_attr_list_find_value(attr_list, answer_list,
                                         hostname, &list_value, is_ambiguous);
            /* EB: TODO: handle only if sublist changed */
            lSetList(this_elem, attribute_name, lCopyList("", list_value));
            *has_changed = true;
            break;
         case CQ_owner_list:
         case CQ_acl:
         case CQ_xacl:
            usrlist_attr_list_find_value(attr_list, answer_list,
                                         hostname, &list_value, is_ambiguous);
            /* EB: TODO: handle only if sublist changed */
            lSetList(this_elem, attribute_name, lCopyList("", list_value));
            *has_changed = true;
            break;
         case CQ_projects:
         case CQ_xprojects:
            prjlist_attr_list_find_value(attr_list, answer_list,
                                         hostname, &list_value, is_ambiguous);
            /* EB: TODO: handle only if sublist changed */
            lSetList(this_elem, attribute_name, lCopyList("", list_value));
            *has_changed = true;
            break;
         case CQ_consumable_config_list:
         case CQ_load_thresholds:
         case CQ_suspend_thresholds:
            celist_attr_list_find_value(attr_list, answer_list,
                                         hostname, &list_value, is_ambiguous);
            /* EB: TODO: handle only if sublist changed */
            lSetList(this_elem, attribute_name, lCopyList("", list_value));
            *has_changed = true;
            break;
         case CQ_subordinate_list:
            solist_attr_list_find_value(attr_list, answer_list,
                                        hostname, &list_value, is_ambiguous);
            /* EB: TODO: handle only if sublist changed */
            lSetList(this_elem, attribute_name, lCopyList("", list_value));
            *has_changed = true;
            break;
         default:
            value_found = false;
            break;
      }

      if (!value_found) {
         switch (type) {
            case lStringT:
               {
                  const char *old_value = lGetString(this_elem, attribute_name);
                  const char *new_value;

                  str_attr_list_find_value(attr_list, answer_list,
                                           hostname, &new_value, is_ambiguous);
                  if (old_value == NULL || new_value == NULL ||
                      strcmp(old_value, new_value)) {
#ifdef QINSTANCE_MODIFY_DEBUG
                     DPRINTF(("Changed "SFQ" from "SFQ" to "SFQ"\n",
                              lNm2Str(attribute_name),
                              old_value ? old_value : "<null>",
                              new_value ? new_value : "<null>"));
#endif
                     lSetString(this_elem, attribute_name, new_value);
                     *has_changed = true;
                  }
               }
               break;
            case lUlongT:
               {
                  u_long32 old_value = lGetUlong(this_elem, attribute_name);
                  u_long32 new_value;

                  ulng_attr_list_find_value(attr_list, answer_list, hostname, 
                                            &new_value, is_ambiguous);
                  if (old_value != new_value) {
#ifdef QINSTANCE_MODIFY_DEBUG
                     DPRINTF(("Changed "SFQ" from "u32" to "u32"\n",
                              lNm2Str(attribute_name),
                              old_value, new_value));
#endif
                     lSetUlong(this_elem, attribute_name, new_value);
                     *has_changed = true;
                  }
               }
               break;
            case lBoolT:
               {
                  bool old_value = lGetBool(this_elem, attribute_name);
                  bool new_value;

                  bool_attr_list_find_value(attr_list, answer_list,
                                            hostname, &new_value, is_ambiguous);
                  if (old_value != new_value) {
#ifdef QINSTANCE_MODIFY_DEBUG
                     DPRINTF(("Changed "SFQ" from "SFQ" to "SFQ"\n",
                              old_value ? "true" : "false",
                              new_value ? "true" : "false"));
#endif
                     lSetBool(this_elem, attribute_name, new_value);
                     *has_changed = true;
                  }
               }
               break;
            default:
               DPRINTF(("unhandled attribute\n"));
               break;
         }
      }
   }
   DEXIT;
   return ret;
}


