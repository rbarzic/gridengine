#ifndef __MSG_QMASTER_H
#define __MSG_QMASTER_H
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

#define MSG_SGETEXT_CANTSPOOL_SS                _MESSAGE(33000, _("qmaster is unable to spool "SFN" "SFQ"\n"))
#define MSG_OBJ_JOBS                            _MESSAGE(33001, _("jobs"))
#define MSG_CONFIG_CANTRESOLVEHOSTNAMEX_SSS     _MESSAGE(33002, _("cannot resolve %s name "SFQ": %s"))
#define MSG_CONFIG_CANTRESOLVEHOSTNAMEX_SS      _MESSAGE(33003, _("cannot resolve %s name "SFQ))



/*
** sge_ckptobj.c
*/
#define MSG_OBJ_CKPT                  _MESSAGE(33004, _("checkpointing environment"))
#define MSG_OBJ_CKPTI                 _MESSAGE(33005, _("checkpoint interface"))
#define MSG_OBJ_CKPTENV_SSS           _MESSAGE(33006, _("parameter %s of ckpt environment \"%s\": %s\n"))
#define MSG_SGETEXT_CANTCOUNT_CKPT_S  _MESSAGE(33008, _("can't count checkpoint objects in "SFN"\n") ) 
#define MSG_SGETEXT_NO_CKPT_LIC       _MESSAGE(33009, _("no checkpoint license available\n") )  
#define MSG_SGETEXT_NO_INTERFACE_S    _MESSAGE(33010, _("no valid checkpoint interface "SFN"\n") )   


/*
** sge_follow.c
*/
#define MSG_IGNORE_ORDER_RETRY_I      _MESSAGE(33011, _("ignoring retry of recent order #%d\n"))
#define MSG_UNKNOWN_ERROR_NL          _MESSAGE(33012, _("unknown error\n"))
#define MSG_JOB_NOJOBID               _MESSAGE(33013, _("can't get job id\n"))
#define MSG_JOB_NOTASKID              _MESSAGE(33014, _("can't get task id\n"))
#define MSG_JOB_FINDJOB_U             _MESSAGE(33015, _("unable to find job "U32CFormat"\n"))
#define MSG_JOB_FINDJOBTASK_UU        _MESSAGE(33016, _("unable to find task "U32CFormat" of job "U32CFormat"\n"))

#define MSG_ORD_OLDVERSION_UUU        _MESSAGE(33017, _("scheduler sent order for old version "U32CFormat" of job "U32CFormat"."U32CFormat"\n"))
#define MSG_ORD_TWICE_UU              _MESSAGE(33018, _("scheduler tries to schedule job "U32CFormat"."U32CFormat" twice\n"))
#define MSG_ORD_INITIALTICKETS_U      _MESSAGE(33019, _(" with "U32CFormat" initial tickets"))

#define MSG_OBJ_UNABLE2FINDPE_S       _MESSAGE(33020, _("unable to find pe \"%s\"\n"))
#define MSG_OBJ_NOQNAME               _MESSAGE(33021, _("can't get q_name\n"))

#define MSG_ORD_QVERSION_UUS          _MESSAGE(33022, _("orders queue version ("U32CFormat") is not uptodate ("U32CFormat") for queue \"%s\"\n"))
#define MSG_ORD_USRPRJVERSION_UUS          _MESSAGE(33023, _("orders user/project version ("U32CFormat") is not uptodate ("U32CFormat") for user/project \"%s\"\n"))


#define MSG_JOB_JOBACCESSQ_US         _MESSAGE(33024, _("job "U32CFormat" has no access to queue \"%s\"\n"))
#define MSG_JOB_FREESLOTS_US          _MESSAGE(33025, _("not enough ("U32CFormat") free slots in queue \"%s\"\n"))
#define MSG_JOB_QMARKEDERROR_S        _MESSAGE(33026, _("queue \"%s\" is marked QERROR\n") ) 
#define MSG_JOB_QSUSPCAL_S            _MESSAGE(33027, _("while scheduling queue \"%s\" was suspended on calendar\n"))
#define MSG_JOB_QDISABLECAL_S         _MESSAGE(33028, _("while scheduling queue \"%s\" was disabled on calendar\n"))
#define MSG_JOB_UNABLE2FINDHOST_S     _MESSAGE(33029, _("unable to locate host in exechost list \"%s\"\n"))
#define MSG_JOB_UNABLE2STARTJOB_US    _MESSAGE(33030, _("unable to start job "U32CFormat" before cleanup on host "SFN" has finished\n"))
#define MSG_JOB_HOSTNAMERESOLVE_US    _MESSAGE(33031, _("failed starting job "U32CFormat" - probably hostname resolving problem with \"%s\"\n") ) 
#define MSG_JOB_JOBDELIVER_UU         _MESSAGE(33032, _("failed delivering job "U32CFormat"."U32CFormat))
#define MSG_JOB_UNABLE2FINDJOBORD_U   _MESSAGE(33033, _("unable to find job \""U32CFormat"\" in ticket order\n") )     
#define MSG_JOB_CHANGETICKETS_UU      _MESSAGE(33034, _("scheduler tries to change tickets of a non running job "U32CFormat" task "U32CFormat"\n"))
#define MSG_JOB_CHANGEPTICKETS_UU      _MESSAGE(33035, _("scheduler tries to change pending tickets of a non pending job "U32CFormat" task "U32CFormat"\n"))
#define MSG_JOB_REMOVENOTFINISHED_U   _MESSAGE(33036, _("scheduler tried to remove job "U32CFormat" which is not in state JFINISHED\n"))
#define MSG_JOB_REMOVENONINTERACT_U   _MESSAGE(33037, _("scheduler tried to remove non interactive job "U32CFormat" by use of a ORT_remove_immediate_job order\n"))
#define MSG_JOB_REMOVENONIMMEDIATE_U  _MESSAGE(33038, _("scheduler tried to remove non immediate job "U32CFormat" by use of a ORT_remove_immediate_job order\n"))
#define MSG_JOB_REMOVENOTIDLEIA_U     _MESSAGE(33039, _("scheduler tried to remove interactive job "U32CFormat" but it is not in JIDLE state\n"))
#define MSG_JOB_NOFREERESOURCEIA_U    _MESSAGE(33040, _("no free resource for interactive job "U32CFormat"\n"))
#define MSG_MAIL_CREDITLOWSUBJ_SUS    SFN": Credit low for job " U32CFormat " ("SFN")\n"
#define MSG_JOB_SUSPOTNOTRUN_UU       _MESSAGE(33042, _("got ORT_suspend_on_threshold order for non running task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_UNSUSPOTNOTRUN_UU     _MESSAGE(33043, _("got ORT_unsuspend_on_threshold order for non running task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_UNSUSPOT_UUS          _MESSAGE(33044, _("unsuspending job "U32CFormat"."U32CFormat" according to suspend threshold of queue \"%s\"\n"))
#define MSG_JOB_UNABLE2FINDMQ_SU      _MESSAGE(33045, _("unable to find master queue %s of job "U32CFormat"\n"))
#define MSG_JOB_SUSPTQ_UUS            _MESSAGE(33046, _("suspending job "U32CFormat"."U32CFormat" according to suspend threshold of queue \"%s\"\n"))
#define MSG_JOB_MISSINGJOBTASK_UU     _MESSAGE(33047, _("missing job "U32CFormat"."U32CFormat" appeared in ticket orders list"))
#define MSG_ORD_UNABLE2FINDHOST_S     _MESSAGE(33048, _("unable to lookup host for queue %s in parallel job ticket order"))


/*
** parse_onoff.c
*/
#define MSG_TOKEN_UNRECOGNIZEDSTRING_S                  _MESSAGE(33049, _("unrecognized string \"%s\""))
#define MSG_ANSWER_ERRORINDISABLYEAROFCALENDARXY_SS     _MESSAGE(33050, _("error in disabled_year of calendar \"%s\": %s\n"))
#define MSG_ANSWER_GOTEQUALWITHOUTDAYTIMERANGEORSTATE   _MESSAGE(33051, _("got \"=\" without daytime_range/state"))
#define MSG_ANSWER_FIRSTYESTERDAYINRANGEMUSTBEBEFORESECONDYESTERDAY     _MESSAGE(33052, _("first yearday in range must be before second yearday"))
#define MSG_PARSE_MISSINGPOINTAFTERDAY      _MESSAGE(33053, _("missing \".\" after day\n"))
#define MSG_PARSE_MISSINGPOINTAFTERMONTH    _MESSAGE(33054, _("missing \".\" after month\n"))
#define MSG_PARSE_WOUTSIDEOFRANGEXYZ_SIIS   _MESSAGE(33055, _("\"%s\" outside of range %d-%d of %s"))
#define MSG_PARSE_XISNOTAY_SS               _MESSAGE(33056, _("\"%s\" is not a %s"))
#define MSG_PARSE_MISSINGDASHINDAYTIMERANGE _MESSAGE(33057, _("missing '-' in daytime range"))
#define MSG_PARSE_RANGEBEGISEQUALTOEND      _MESSAGE(33058, _("range begin is equal to end - use 0-24 instead"))
#define MSG_PARSE_DAYTIMESBEYOND24HNOTALLOWED  _MESSAGE(33059, _("daytimes may not be beyond 24:00\n"))
#define MSG_PARSE_HOURSPEC                  _MESSAGE(33060, _("hour specification"))
#define MSG_PARSE_MINUTESPEC                _MESSAGE(33061, _("minute specification"))
#define MSG_PARSE_SECONDSSPEC               _MESSAGE(33062, _("seconds specification"))
#define MSG_PARSE_XISNOTASTATESPECIFIER_S   _MESSAGE(33063, _("\"%s\" is not a state specifier"))
#define MSG_PARSE_UNRECOGNIZEDTOKENATEND    _MESSAGE(33064, _("unrecognized token at end\n"))
#define MSG_PARSE_ERRORINDISABLEDWEEKOFCALENDAR_SS     _MESSAGE(33065, _("error in disabled_week of calendar \"%s\": %s\n"))
#define MSG_PARSE_FOUNDUSELESSWEEKDAYRANGE  _MESSAGE(33066, _("found useless weekday range"))
#define MSG_PARSE_EXPECTEDSTRINGFORWEEKDAY  _MESSAGE(33067, _("expected string for weekday"))
#define MSG_PARSE_XISNOTAWEEKDAY_S          _MESSAGE(33068, _("\"%s\" is not a weekday"))
#define MSG_PARSE_OVERFLOWERRORWHILEPARSING _MESSAGE(33069, _("overflow error while parsing\n"))


/*
** global qmaster messages
*/ 


/* 
** gdi_utility_qmaster.c 
*/
#define MSG_GDI_SIG_DIGIT_SS         _MESSAGE(33070, _("denied: attribute "SFQ" contains invalid value "SFQ"\n"))
#define MSG_GDI_METHOD_VARS_SS       _MESSAGE(33071, _("parameter "SFQ" of queue: %s\n"))
#define MSG_GDI_APATH_S              _MESSAGE(33072, _("denied: path given for "SFQ" must start with an \"/\"\n"))
#define MSG_GDI_VARS_SS              _MESSAGE(33073, _("parameter "SFQ": %s\n"))
#define MSG_GDI_VALUE_S              _MESSAGE(33074, _("denied: attribute "SFQ" contains invalid value (null)\n"))
#define MSG_GDI_TYPE_MEM_SS          _MESSAGE(33075, _("value for attribute %s "SFQ" is not a memory value\n"))
#define MSG_GDI_TYPE_TIME_SS         _MESSAGE(33076, _("value for attribute %s "SFQ" is not a time value\n"))
#define MSG_GDI_MULTIPLE_OCCUR_SSSS  _MESSAGE(33078, _("denied: multiple occurances of %s "SFQ" in %s "SFQ"\n"))
#define MSG_GDI_NO_ATTRIBUTE_SSS     _MESSAGE(33079, _("denied: attribute "SFQ" is not configured for %s "SFQ"\n"))
#define MSG_GDI_KEYSTR_FIRSTCHAR_SC  _MESSAGE(33080, _("%s (\'%c\') not allowed as first character of objectname\n") ) 
#define MSG_GDI_KEYSTR_FIRSTCHAR_S   _MESSAGE(33081, _("%s not allowed as first character of objectname\n") ) 
#define MSG_GDI_KEYSTR_MIDCHAR_SC    _MESSAGE(33082, _("%s (\'%c\') not allowed in objectname\n") ) 
#define MSG_GDI_KEYSTR_MIDCHAR_S     _MESSAGE(33083, _("%s not allowed in objectname\n") ) 
#define MSG_GDI_KEYSTR_KEYWORD_SS     _MESSAGE(33084, _("%s ("SFQ") not allowed as objectname\n") ) 
#define MSG_GDI_KEYSTR_KEYWORD         _MESSAGE(33085, _("Keyword"))
#define MSG_GDI_KEYSTR_DOT             _MESSAGE(33086, _("Dot"))
#define MSG_GDI_KEYSTR_HASH            _MESSAGE(33087, _("Hash"))
#define MSG_GDI_KEYSTR_RETURN          _MESSAGE(33088, _("Return"))
#define MSG_GDI_KEYSTR_TABULATOR       _MESSAGE(33089, _("Tabulator"))
#define MSG_GDI_KEYSTR_CARRIAGERET     _MESSAGE(33090, _("Carriage return"))
#define MSG_GDI_KEYSTR_SPACE           _MESSAGE(33091, _("Space"))
#define MSG_GDI_KEYSTR_SLASH           _MESSAGE(33092, _("Slash"))
#define MSG_GDI_KEYSTR_COLON           _MESSAGE(33093, _("Colon"))
#define MSG_GDI_KEYSTR_QUOTE           _MESSAGE(33094, _("Quote"))
#define MSG_GDI_KEYSTR_DBLQUOTE        _MESSAGE(33095, _("Double quote"))
#define MSG_GDI_KEYSTR_BACKSLASH       _MESSAGE(33096, _("Backslash"))
#define MSG_GDI_KEYSTR_BRACKETS        _MESSAGE(33097, _("Brackets"))
#define MSG_GDI_KEYSTR_BRACES          _MESSAGE(33098, _("Braces"))
#define MSG_GDI_KEYSTR_PARENTHESIS     _MESSAGE(33099, _("Parenthesis"))
#define MSG_GDI_KEYSTR_AT              _MESSAGE(33100, _("AT"))

/*
** ck_to_do_qmaster.c
*/
#define MSG_FILE_OPEN_S              _MESSAGE(33101, _("can't open "SFQ" for appending system state info"))

/*
** sge_c_ack.c
*/
#define MSG_COM_NOQUEUE              _MESSAGE(33102, _("<no queue>"))
#define MSG_COM_UNPACKINT_I          _MESSAGE(33103, _("unpacking integer %d failed\n"))
#define MSG_COM_ACK_S                _MESSAGE(33104, _("ack event from %s\n") )     
#define MSG_COM_ACKEVENTFORUNKOWNJOB_U _MESSAGE(33105, _("ack event for unknown job "U32CFormat"\n"))
#define MSG_COM_ACKEVENTFORUNKNOWNTASKOFJOB_UU _MESSAGE(33106, _("ack event for unknown task " U32CFormat  " of job " U32CFormat " \n"))
#define MSG_COM_UNKNOWN_TAG          _MESSAGE(33107, _("received unknown ack tag "U32CFormat"\n"))

#define MSG_COM_ACK_U                _MESSAGE(33108, _("signalling acknowledged for unknown job " U32CFormat  "\n"))
#define MSG_COM_ACK_US               _MESSAGE(33110, _("ack event for job " U32CFormat  " can't find queue %s\n"))
#define MSG_COM_ACK_QUEUE_U          _MESSAGE(33111, _("ack event for unknown queue " U32CFormat "\n"))
#define MSG_COM_ACK_UNKNOWN          _MESSAGE(33112, _("unknown ack event\n"))
#define MSG_COM_NO_EVCLIENTWITHID_U  _MESSAGE(33113, _("no event client with id "U32CFormat" registered\n"))

/*
** sge_c_gdi.c
*/
#define MSG_GDI_WRONG_GDI_SSISS       _MESSAGE(33114, _("denied: client ("SFN"/"SFN"/%d) uses old GDI version %s while qmaster uses newer version %s\n"))
#define MSG_GDI_WRONG_GDI_SSIUS       _MESSAGE(33115, _("denied: client ("SFN"/"SFN"/%d) uses newer GDI version "U32CFormat" while qmaster uses older version %s\n"))


#define MSG_GDI_NULL_IN_GDI_SSS       _MESSAGE(33116, _("denied: got NULL in %s/%s of gdi request from host \"%s\"\n"))
#define MSG_GDI_OKNL                  _MESSAGE(33117, _("ok\n"))
#define MSG_OBJ_GENQ                  _MESSAGE(33118, _("internal error - can't get generic queue\n"))
#define MSG_OBJ_QLIST                 _MESSAGE(33119, _("queue list"))
#define MSG_MEM_MALLOC                _MESSAGE(33120, _("malloc failure\n"))
#define MSG_SGETEXT_UNKNOWNOP                   _MESSAGE(33121, _("unknown operation\n"))
#define MSG_SGETEXT_FEATURE_NOT_AVAILABLE_FORX_S _MESSAGE(33122, _("feature not available for "SFN" system\n"))
#define MSG_SGETEXT_CANTGET_SS                  _MESSAGE(33123, _(""SFN" can't get "SFN"\n"))
#define MSG_SGETEXT_OPNOIMPFORTARGET            _MESSAGE(33124, _("operation not implemented for target\n"))
#define MSG_SGETEXT_NOADMINHOST_S               _MESSAGE(33125, _("denied: host "SFQ" is no admin host\n"))
#define MSG_SGETEXT_NOSUBMITHOST_S              _MESSAGE(33126, _("denied: host "SFQ" is no submit host\n"))
#define MSG_SGETEXT_NOSUBMITORADMINHOST_S       _MESSAGE(33127, _("denied: host "SFQ" is neither submit nor admin host\n"))
#define MSG_SGETEXT_ALREADYEXISTS_SS            _MESSAGE(33128, _(""SFN" "SFQ" already exists\n"))
#define MSG_SGETEXT_ADDEDTOLIST_SSSS            _MESSAGE(33129, _(""SFN"@"SFN" added "SFQ" to "SFN" list\n"))
#define MSG_SGETEXT_MODIFIEDINLIST_SSSS         _MESSAGE(33130, _(""SFN"@"SFN" modified "SFQ" in "SFN" list\n"))

/*
** sge_calendar_qmaster.c
*/
#define MSG_OBJ_CALENDAR              _MESSAGE(33131, _("calendar"))
#define MSG_EVE_TE4CAL_S              _MESSAGE(33132, _("got timer event for unknown calendar "SFQ"\n"))
#define MSG_SGETEXT_CALENDARSTILLREFERENCEDINQUEUE_SS _MESSAGE(33133, _("denied: calendar "SFQ" is still referenced in queue "SFQ"\n") ) 
#define MSG_SGETEXT_REMOVEDFROMLIST_SSSS        _MESSAGE(33134, _(""SFN"@"SFN" removed "SFQ" from "SFN" list\n"))




/*
** sge_give_jobs.c
*/
#define MSG_COM_NOTENROLLEDONHOST_SSU _MESSAGE(33136, _("target \"%s\" not enrolled on host \"%s\" for delivering job \""U32CFormat"\"\n"))
#define MSG_OBJ_UNABLE2FINDCKPT_S     _MESSAGE(33137, _("can't find checkpointing object \"%s\"\n"))
#define MSG_OBJ_UNABLE2CREATECKPT_SU  _MESSAGE(33138, _("can't create checkpointing object \"%s\" for job " U32CFormat "\n"))
#define MSG_COM_SENDJOBTOHOST_US      _MESSAGE(33141, _("can't send job \"" U32CFormat"\" to host \"%s\""))
#define MSG_COM_RESENDUNKNOWNJOB_UU   _MESSAGE(33142, _("cannot resend unknown job "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_UNKNOWNGDIL4TJ_UU     _MESSAGE(33143, _("transfering job "U32CFormat"."U32CFormat" has an invalid gdi list --- deleting"))
#define MSG_JOB_NOQUEUE4TJ_SUU        _MESSAGE(33144, _("queue \"%s\" in transiting job "U32CFormat"."U32CFormat" doesn't exist. deleting task"))
#define MSG_JOB_NOHOST4TJ_SUU         _MESSAGE(33145, _("execution host \"%s\" for transfering job "U32CFormat"."U32CFormat" doesn't exist. deleting task"))
#define MSG_JOB_NOPE4TJ_SUU           _MESSAGE(33146, _("parallel environment \"%s\" for transfering job "U32CFormat"." U32CFormat" doesn't exist. deleting job"))
#define MSG_JOB_DELIVER2Q_UUS         _MESSAGE(33147, _("failed to deliver job "U32CFormat"."U32CFormat" to queue \"%s\""))
#define MSG_LOG_SENT2EXECD            _MESSAGE(33152, _("sent to execd"))
#define MSG_LOG_EXITED                _MESSAGE(33153, _("job exited"))
#define MSG_LOG_WAIT4SGEDEL           _MESSAGE(33154, _("job waits for schedds deletion"))
#define MSG_LOG_DELSGE                _MESSAGE(33155, _("job deleted by schedd"))
#define MSG_LOG_DELIMMEDIATE          _MESSAGE(33156, _("immediate job deleted by schedd"))
#define MSG_LOG_JATASKEXIT            _MESSAGE(33157, _("ja task exited") )  
#define MSG_JOB_RESCHEDULE_UU         _MESSAGE(33158, _("rescheduling job "U32CFormat"."U32CFormat) ) 
#define MSG_RU_CANCELED_S             _MESSAGE(33159, _("Due to a modification of the reschedule_unknown timeout rescheduling for host "SFN" was canceled."))
#define MSG_RU_TRIGGER_SU             _MESSAGE(33160, _("Due to a modification of the reschedule_unknown timeout rescheduling for host "SFN" will be triggerd in "U32CFormat" seconds."))

/* CR: don't localize mail subject, until we send it in Mime format!
 *     The message definition is not l10n'ed (no _() macro used)!!!        
 */
/* #define MSG_RU_MAILSUB_SS             _MESSAGE(33161, _("Pushed rescheduling of "SFN" "SFN)) */
#define MSG_RU_MAILSUB_SS             "Pushed rescheduling of "SFN" "SFN



#define MSG_RU_MAILBODY_SSSS          _MESSAGE(33162, _("Your "SFN" "SFN" is was running on host "SFN". "SFN" manually/automatic rescheduling for this "SFN"."))
#define MSG_RU_MAILTYPE               _MESSAGE(33163, _("job rescheduling"))
#define MSG_RU_PUSHEDR                _MESSAGE(33164, _("Pushed"))
#define MSG_RU_FORCEDR                _MESSAGE(33165, _("Forced"))
#define MSG_RU_MSGFILEINFO            _MESSAGE(33166, _(SFN" rescheduling of "SFN" "SFN" on host "SFN"\n"))
#define MSG_RU_TYPEJOBARRAY           _MESSAGE(33167, _("job-array task"))
#define MSG_RU_TYPEJOB                _MESSAGE(33168, _("job"))
#define MSG_RU_JR_ERRSTR              _MESSAGE(33169, _("manual/auto rescheduling") )  
#define MSG_RU_NOT_RESTARTABLE_SS     _MESSAGE(33170, _("The "SFN" "SFN" is not restartable\n"))
#define MSG_RU_INTERACTIVEJOB_SSS     _MESSAGE(33171, _(SFN" is a qsh, qlogin, qrsh or a qrlogin "SFN". These types of "SFN" are not restartable\n"))
#define MSG_RU_CKPTNOTVALID_SSS       _MESSAGE(33172, _(SFN" requests ckpt object "SFN". Therefore this "SFN" is not restartable.\n"))
#define MSG_RU_CKPTEXIST_SS           _MESSAGE(33173, _(SFN" requests ckpt object "SFN". This ckpt object does not exist.\n"))
#define MSG_RU_INDELETEDSTATE_SS      _MESSAGE(33174, _("The "SFN" "SFN" is already in deleted state. No rescheduling!\n"))
#define MSG_RU_NORERUNQUEUE_SSS       _MESSAGE(33175, _("The "SFN" "SFN" is running in queue "SFN" were jobs are not rerunable.\n"))

/*
** sge_host_qmaster.c
*/
#define MSG_OBJ_DELGLOBALHOST         _MESSAGE(33176, _("denied: pseudo host \"global\" may not be deleted\n"))
#define MSG_OBJ_LOADREPORTIVAL_SS     _MESSAGE(33177, _("host "SFQ": "SFQ" is not a valid time value for \"load_report_time\" - assuming 120 seconds\n") )    
#define MSG_OBJ_RESCHEDULEUNKN_SS     _MESSAGE(33178, _("host "SFQ": "SFQ" is not a valid time value for \"reschedule_unknown\" - assuming 0 => no auto rescheduling\n"))
#define MSG_OBJ_SHUTDOWNPERMS         _MESSAGE(33179, _("shutting down execd requires manager privileges\n"))
#define MSG_OBJ_NOEXECDONHOST_S       _MESSAGE(33180, _("no execd known on host %s\n"))
#define MSG_OBJ_UNKNOWN               _MESSAGE(33185, _("unknown"))

/* CR: don't localize mail subject, until we send it in Mime format!
 *     The message definition is not l10n'ed (no _() macro used)!!!        
 */
#define MSG_MAIL_JOBKILLEDSUBJ_US     "Job " U32CFormat " ("SFN") Killed"

#define MSG_MAIL_JOBKILLEDBODY_USS    _MESSAGE(33188, _("Job " U32CFormat " ("SFN") was killed due to a kill execd on host %s"))
#define MSG_OBJ_INVALIDHOST_S         _MESSAGE(33189, _("invalid hostname "SFQ"\n"))
#define MSG_OBJ_NOADDHOST_S           _MESSAGE(33190, _("adding host "SFQ" failed\n"))
#define MSG_LOG_REGISTER_SS           _MESSAGE(33191, _("%s on %s registered"))
#define MSG_OBJ_NOSCALING4HOST_SS     _MESSAGE(33192, _("denied: scaling attribute "SFQ" is not configured for host "SFQ"\n") )  
#define MSG_SGETEXT_ISNOEXECHOST_S              _MESSAGE(33193, _(SFQ" is not an execution host\n"))
#define MSG_SGETEXT_NOEXECHOSTS                 _MESSAGE(33194, _("there are no execution hosts to kill\n"))
#define MSG_SGETEXT_CANTCOUNT_HOSTS_S                 _MESSAGE(33195, _("can't count adm./subm. host list in "SFN"\n"))
#define MSG_SGETEXT_CANTDELADMINQMASTER_S       _MESSAGE(33196, _("denied: can't delete master host "SFQ" from admin host list\n") )   
#define MSG_SGETEXT_CANTDELEXECACTIVQ_S         _MESSAGE(33197, _("denied: "SFQ" has an active queue - not deleted\n"))
#define MSG_SGETEXT_TOOFEWSUBMHLIC_II                 _MESSAGE(33198, _("not enough submit host licenses; licensed=%d - requested=%d\n") ) 
#define MSG_CANT_ASSOCIATE_LOAD_SS    _MESSAGE(33199, _("got load report from host "SFQ" - reports load value for host "SFQ"\n"))

/*
** sge_job.c
*/
#define MSG_JOB_SENDKILLTOXFORJOBYZ_SUU _MESSAGE(33200, _("send kill to "SFQ" for job "U32CFormat"."U32CFormat))
#define MSG_JOB_NORESUBPERMS_SSS      _MESSAGE(33201, _("job rejected: %s@%s is not allowed to resubmit jobs of user %s\n"))
#define MSG_JOB_NOPERMS_SS            _MESSAGE(33202, _("job rejected: %s@%s is not allowed to submit jobs\n"))
#define MSG_JOB_NULLNOTALLOWEDT       _MESSAGE(33203, _("job rejected: 0 is an invalid task id\n"))
#define MSG_JOB_MORETASKSTHAN_U       _MESSAGE(33204, _("job rejected: You try to submit a job with more than "U32CFormat" tasks\n"))
#define MSG_JOB_UID2LOW_II            _MESSAGE(33205, _("job rejected: your user id %d is lower than minimum user id %d of cluster configuration\n"))
#define MSG_JOB_GID2LOW_II            _MESSAGE(33206, _("job rejected: your group id %d is lower than minimum group id %d of cluster configuration\n"))
#define MSG_JOB_ALLOWEDJOBSPERUSER    _MESSAGE(33207, _("job rejected: Only "U32CFormat" jobs are allowed per user\n"))
#define MSG_JOB_QNOTREQUESTABLE       _MESSAGE(33208, _("job was rejected because job requests a queue while queues are not configured as requestable\n"))
#define MSG_JOB_QUNKNOWN_S            _MESSAGE(33209, _("job was rejected because job requests unknown queue "SFQ"\n"))
#define MSG_JOB_NOSCRIPT              _MESSAGE(33210, _("job rejected: no script in your request\n"))
#define MSG_JOB_PEUNKNOWN_S           _MESSAGE(33211, _("job rejected: the requested parallel environment "SFQ" does not exist\n"))
#define MSG_JOB_CKPTUNKNOWN_S         _MESSAGE(33212, _("job rejected: the requested checkpointing environment "SFQ" does not exist\n"))
#define MSG_JOB_PERANGEMUSTBEGRZERO   _MESSAGE(33213, _("job rejected: pe range must be greater than zero\n"))
#define MSG_JOB_CKPTMINUSC            _MESSAGE(33214, _("job rejected: checkpointing with \"-c n\" requested\n"))
#define MSG_JOB_NOCKPTREQ             _MESSAGE(33215, _("job rejected: checkpointing without checkpointing environment requested\n"))
#define MSG_JOB_CKPTDENIED            _MESSAGE(33216, _("checkpointing denied\n") )   
#define MSG_JOB_NOTINANYQ_S           _MESSAGE(33217, _("warning: %s your job is not allowed to run in any queue\n"))
#define MSG_JOB_PRJUNKNOWN_S          _MESSAGE(33218, _("job rejected: the requested project "SFQ" does not exist\n"))
#define MSG_JOB_USRUNKNOWN_S          _MESSAGE(33219, _("job rejected: the user "SFQ" does not exist\n"))
#define MSG_JOB_PRJNOSUBMITPERMS_S    _MESSAGE(33221, _("job rejected: project "SFQ" is not allowed to submit jobs\n"))
#define MSG_JOB_PRJREQUIRED           _MESSAGE(33222, _("job rejected: no project was supplied and only certain projects are allowed to submit jobs\n"))
#define MSG_JOB_NODEADLINEUSER_S      _MESSAGE(33223, _("job rejected: the user "SFQ" is no deadline initiation user\n"))
#define MSG_JOB_NOJOBNAME_U           _MESSAGE(33225, _("job "U32CFormat" was rejected cause there is no job_name in the request\n"))
#define MSG_JOB_NOWRITE_US            _MESSAGE(33226, _("job "U32CFormat" was rejected cause it can't be written: %s\n"))
#define MSG_JOB_NOWRITE_U             _MESSAGE(33227, _("job "U32CFormat" was rejected cause it couldn't be written\n"))
#define MSG_JOB_SUBMITJOB_USS         _MESSAGE(33233, _("your job "U32CFormat" (\""SFN SFN"\") has been submitted\n"))
#define MSG_JOB_SUBMITJOBARRAY_UUUUSS _MESSAGE(33234, _("your job-array "U32CFormat"."U32CFormat"-"U32CFormat":"U32CFormat" (\""SFN SFN"\") has been submitted\n"))
#define MSG_LOG_NEWJOB                _MESSAGE(33235, _("new job"))
#define MSG_JOB_DELETEJOB             _MESSAGE(33237, _("delete job"))
#define MSG_JOB_JOB                   _MESSAGE(33238, _("Job"))
#define MSG_JOB_FORCEDDELETEPERMS_S   _MESSAGE(33239, _(SFQ" - forcing a job deletion requires manager privileges\n"))
#define MSG_JOB_DELETEPERMS_SU        _MESSAGE(33240, _("%s - you do not have the necessary privileges to delete the job \"" U32CFormat "\"\n"))
#define MSG_JOB_DELETETASK_SUU        _MESSAGE(33241, _("%s has deleted job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_DELETEJOB_SU          _MESSAGE(33242, _("%s has deleted job "U32CFormat"\n"))
#define MSG_JOB_DISCONTINUEDTRANS_SU  _MESSAGE(33243, _("Discontinued delete transaction of user "SFQ" after job "U32CFormat"\n"))
#define MSG_JOB_UNABLE2FINDQOFJOB_S   _MESSAGE(33244, _("can't locate the queue "SFQ" associated with this job\n"))

/* CR: don't localize mail subject, until we send it in Mime format!
 *     The message definition is not l10n'ed (no _() macro used)!!!        
 */
#define MSG_MAIL_TASKKILLEDSUBJ_UUS   "Job-array task "U32CFormat"."U32CFormat" ("SFN") Killed"


#define MSG_MAIL_TASKKILLEDBODY_UUSSS _MESSAGE(33245, _("Job-array task "U32CFormat"."U32CFormat" ("SFN") was killed by %s@%s"))
#define MSG_MAIL_JOBKILLEDBODY_USSS   _MESSAGE(33246, _("Job " U32CFormat " ("SFN")  was killed by %s@%s"))
#define MSG_MAIL_BECAUSE              _MESSAGE(33247, _("\nbecause "))
#define MSG_JOB_FORCEDDELTASK_SUU     _MESSAGE(33248, _("warning: %s forced the deletion of job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_FORCEDDELJOB_SU       _MESSAGE(33249, _("warning: %s forced the deletion of job "U32CFormat"\n"))
#define MSG_COM_NOSYNCEXECD_SU        _MESSAGE(33250, _("%s unable to sync state with remote execd for the deletion of job \"" U32CFormat "\"\n"))
#define MSG_JOB_REGDELTASK_SUU        _MESSAGE(33251, _("%s has registered the job-array task "U32CFormat"."U32CFormat" for deletion\n"))
#define MSG_JOB_REGDELJOB_SU          _MESSAGE(33252, _("%s has registered the job "U32CFormat" for deletion\n"))
#define MSG_JOB_CHANGEATTR            _MESSAGE(33253, _("change job attributes"))
#define MSG_JOB_NOALTERNOWRITE_U      _MESSAGE(33254, _("alternation of job "U32CFormat" was rejected cause it couldn't be written\n"))
#define MSG_JOB_CHANGESHAREFUNC       _MESSAGE(33255, _("change share of job functional tickets"))
#define MSG_JOB_SETSHAREFUNC_SSUUU    _MESSAGE(33256, _("%s@%s sets job functional ticket share of job "U32CFormat"."U32CFormat" to "U32CFormat"\n"))
#define MSG_JOB_RMHOLDMNG             _MESSAGE(33257, _("remove manager hold"))
#define MSG_JOB_SETHOLDMNG            _MESSAGE(33258, _("set manager hold"))
#define MSG_JOB_RMHOLDOP              _MESSAGE(33259, _("remove operator hold"))
#define MSG_JOB_SETHOLDOP             _MESSAGE(33260, _("set operator hold"))
#define MSG_JOB_RMHOLDUSER            _MESSAGE(33261, _("remove user hold"))
#define MSG_JOB_SETHOLDUSER           _MESSAGE(33262, _("set user hold"))
#define MSG_JOB_HOLD                  _MESSAGE(33263, _("hold"))
#define MSG_JOB_NOJOBARRAY_U          _MESSAGE(33264, _(U32CFormat " is no job array\n"))
#define MSG_JOB_CHANGEOVERRIDETICKS   _MESSAGE(33265, _("change amount of override tickets"))
#define MSG_JOB_SETOVERRIDETICKS_SSUU _MESSAGE(33266, _("%s@%s sets override tickets of job "U32CFormat" to "U32CFormat"\n"))
#define MSG_JOB_PRIOINC               _MESSAGE(33267, _("increase job priority"))
#define MSG_JOB_PRIOSET_SSUI          _MESSAGE(33268, _("%s@%s sets scheduling priority of job "U32CFormat" to %d\n"))
#define MSG_JOB_ACCOUNT               _MESSAGE(33269, _("account"))
#define MSG_JOB_WD                    _MESSAGE(33270, _("working directory"))
#define MSG_JOB_STARTTIME             _MESSAGE(33271, _("start time"))
#define MSG_JOB_STDERRPATHLIST        _MESSAGE(33272, _("stderr path list"))
#define MSG_JOB_STDOUTPATHLIST        _MESSAGE(33273, _("stdout path list"))
#define MSG_JOB_HOLDLISTMOD_USS       _MESSAGE(33274, _("modified job id hold list of job "U32CFormat"\n   blocking jobs: "SFN"\n   exited jobs:   "SFN"\n"))
#define MSG_JOB_MERGEOUTPUT           _MESSAGE(33275, _("output merge behaviour"))
#define MSG_JOB_HARDRESOURCELIST      _MESSAGE(33276, _("hard resource list"))
#define MSG_JOB_SOFTRESOURCELIST      _MESSAGE(33277, _("soft resource list"))
#define MSG_JOB_MAILOPTIONS           _MESSAGE(33278, _("mail options"))
#define MSG_JOB_MAILLIST              _MESSAGE(33279, _("mail list"))
#define MSG_JOB_JOBNAME               _MESSAGE(33280, _("job name"))
#define MSG_JOB_NOTIFYBEHAVIOR        _MESSAGE(33281, _("notify behaviour"))
#define MSG_JOB_SLOTRANGE             _MESSAGE(33282, _("slot range"))
#define MSG_JOB_QNOTREQUESTABLE2      _MESSAGE(33283, _("denied: queues are not configured to be requestable\n"))
#define MSG_JOB_HARDQLIST             _MESSAGE(33284, _("hard queue list"))
#define MSG_JOB_SOFTQLIST             _MESSAGE(33285, _("soft queue list"))
#define MSG_JOB_MASTERHARDQLIST       _MESSAGE(33286, _("master hard queue list"))
#define MSG_JOB_RESTARTBEHAVIOR       _MESSAGE(33287, _("restart behaviour"))
#define MSG_JOB_SHELLLIST             _MESSAGE(33288, _("shell list"))
#define MSG_JOB_ENVLIST               _MESSAGE(33289, _("environment"))
#define MSG_JOB_QSARGS                _MESSAGE(33290, _("qs args"))
#define MSG_JOB_SCRIPTARGS            _MESSAGE(33291, _("script arguments"))
#define MSG_JOB_CONTEXT               _MESSAGE(33292, _("context"))
#define MSG_JOB_NODIRECTSLOTS         _MESSAGE(33293, _("denied: use parallel environments instead of requesting slots explicitly\n"))
#define MSG_JOB_NOSEQNRREAD_SS        _MESSAGE(33294, _("can't read job sequence number in file "SFQ": %s"))
#define MSG_JOB_NOSEQFILEOPEN_SS      _MESSAGE(33295, _("can't open sequence number file "SFQ": for reading: %s -- guessing next job number"))
#define MSG_JOB_NOSEQFILECREATE_SS    _MESSAGE(33296, _("can't create job sequence number file "SFQ": %s - delaying until next job"))
#define MSG_JOB_NOSUITABLEQ_S         _MESSAGE(33297, _("%s: no suitable queues\n"))
#define MSG_JOB_VERIFYERROR           _MESSAGE(33298, _("error"))
#define MSG_JOB_VERIFYWARN            _MESSAGE(33299, _("warning"))
#define MSG_JOB_VERIFYVERIFY          _MESSAGE(33300, _("verification"))
#define MSG_JOB_VERIFYFOUNDQ          _MESSAGE(33301, _("verification: found suitable queue(s)\n"))
#define MSG_JOB_VERIFYFOUNDSLOTS_I    _MESSAGE(33302, _("verification: found possible assignment with %d slots\n"))
#define MSG_OBJ_PE                    _MESSAGE(33303, _("parallel environment"))

#define MSG_JOB_MOD_SOFTREQCONSUMABLE_S  _MESSAGE(33305, _("denied: soft requests on consumables like "SFQ" are not supported\n"))
#define MSG_JOB_MOD_MISSINGRUNNINGJOBCONSUMABLE_S     _MESSAGE(33306, _("denied: former resource request on consumable "SFQ" of running job lacks in new resource request\n"))
#define MSG_JOB_MOD_ADDEDRUNNINGJOBCONSUMABLE_S       _MESSAGE(33307, _("denied: resource request on consumable "SFQ" of running job was not contained former resource request\n"))
#define MSG_JOB_MOD_CHANGEDRUNNINGJOBCONSUMABLE_S     _MESSAGE(33308, _("denied: can't change consumable resource request "SFQ" of running job\n"))

#define MSG_JOB_MOD_GOTOWNJOBIDINHOLDJIDOPTION_U      _MESSAGE(33309, _("denied: job \""U32CFormat"\" may not be it's own jobnet predecessor\n"))
#define MSG_JOB_MOD_GOTOWNJOBIDINHOLDJIDOPTION_S      _MESSAGE(33310, _("denied: job "SFQ" may not be it's own jobnet predecessor\n"))
#define MSG_JOB_MOD_JOBNETPREDECESSAMBIGUOUS_SUU      _MESSAGE(33311, _("denied: non-ambiguous jobnet predecessor "SFQ" (found jobs "U32CFormat" and "U32CFormat")\n"))
#define MSG_JOB_MOD_NOJOBNAME_SS                      _MESSAGE(33312, _("denied: "SFQ" is not a valid job name for %s\n"))
#define MSG_JOB_MOD_JOBNAMEVIOLATESJOBNET_SSUU        _MESSAGE(33313, _("denied: using job name "SFQ" for %s violates reference unambiguousness in jobnet from job "U32CFormat" to "U32CFormat"\n"))
#define MSG_JOB_MOD_CHGJOBNAMEDESTROYSREF_UU          _MESSAGE(33314, _("denied: changing job name of job "U32CFormat" destroys jobnet predecessor reference from job "U32CFormat"\n"))
#define MSG_SGETEXT_NEEDONEELEMENT_SS                 _MESSAGE(33315, _("denied: request format error: need at least one element in sublist "SFQ" in "SFN"()\n"))
#define MSG_SGETEXT_CANT_MOD_RUNNING_JOBS_U           _MESSAGE(33316, _("job "U32CFormat" can't modify running jobs\n") ) 
#define MSG_SGETEXT_MUST_BE_OPR_TO_SS                 _MESSAGE(33317, _("denied: "SFQ" must be operator to "SFN"\n"))
#define MSG_SGETEXT_MOD_JOBS_SU                       _MESSAGE(33318, _("modified "SFN" of job "U32CFormat"\n") )     
#define MSG_SGETEXT_DOESNOTEXIST_SU                   _MESSAGE(33319, _(""SFN" \"" U32CFormat "\" does not exist\n"))
#define MSG_SGETEXT_DOESNOTEXISTTASK_UU               _MESSAGE(33320, _("job \"" U32CFormat "\" task \"" U32CFormat "\" does not exist\n"))
#define MSG_SGETEXT_DOESNOTEXISTTASKRANGE_UUUU        _MESSAGE(33321, _("job \"" U32CFormat "\" task id range \"" U32CFormat "-" U32CFormat ":" U32CFormat "\" comprises no tasks\n"))
#define MSG_SGETEXT_NO_PROJECT                        _MESSAGE(33322, _("job rejected: no project assigned to job\n") )     
#define MSG_SGETEXT_MOD_JATASK_SUU                    _MESSAGE(33323, _("modified "SFN" of job-array task "U32CFormat"."U32CFormat"\n") )  
#define MSG_SGETEXT_MUST_BE_MGR_TO_SS                 _MESSAGE(33324, _("denied: "SFQ" must be manager to "SFN"\n"))
#define MSG_SGETEXT_MUST_BE_JOB_OWN_TO_SUS            _MESSAGE(33325, _("denied: "SFQ" must be at least owner of job "U32CFormat" to "SFN"\n"))
#define MSG_SGETEXT_NOJOBSDELETED                     _MESSAGE(33326, _("No jobs deleted\n"))
#define MSG_SGETEXT_NOJOBSMODIFIED                    _MESSAGE(33327, _("No jobs modified\n"))
#define MSG_SGETEXT_THEREARENOJOBS                    _MESSAGE(33328, _("There are no jobs registered\n"))
#define MSG_SGETEXT_THEREARENOJOBSFORUSERS_S          _MESSAGE(33329, _("There are no jobs registered for following users: "SFN"\n"))
#define MSG_SGETEXT_SPECIFYUSERORJID                  _MESSAGE(33330, _("You have to specify a username or job ids\n"))
#define MSG_SGETEXT_SPECIFYONEORALLUSER               _MESSAGE(33331, _("The switch for \"all users\" and a specified \"user list\" are not allowed together\n"))
#define MSG_SGETEXT_NO_ACCESS2PRJ4USER_SS             _MESSAGE(33332, _("job rejected: no access to project "SFQ" for user "SFQ"\n") ) 
#define MSG_SGETEXT_NOTALLOWEDTOSPECUSERANDJID        _MESSAGE(33333, _("it is not allowed to select users and job ids together\n"))
#define MSG_SGETEXT_MODIFIEDINLIST_SSUS               _MESSAGE(33334, _(""SFN"@"SFN" modified \"" U32CFormat "\" in "SFN" list\n"))



/*
** sge_m_event.c
*/
#define MSG_EVE_REINITSCHEDD_I        _MESSAGE(33341, _("%d. reinitialization of \"schedd\""))
#define MSG_EVE_UNKNOWNEVCLIENT_U     _MESSAGE(33342, _("no event client known with id "U32CFormat"\n"))
#define MSG_EVE_TOTALUPDATE           _MESSAGE(33343, _("scheduler needs total update"))
#define MSG_EVE_REG_SU                _MESSAGE(33344, _(SFQ" registers as event client with id "U32CFormat"\n"))
#define MSG_EVE_UNREG_SU              _MESSAGE(33345, _("event client "SFQ" with id "U32CFormat" deregistered"))
#define MSG_EVE_EVENTCLIENT           _MESSAGE(33346, _("event client"))

#define MSG_EVE_ILLEGALEVENTCLIENTID_S _MESSAGE(33347, _("illegal event client id "SFQ"\n"))
#define MSG_EVE_ILLEGALIDREGISTERED_U _MESSAGE(33348, _("illegal event client id "U32CFormat" for registration\n"))

#define MSG_EVE_INVALIDSUBSCRIPTION   _MESSAGE(33349, _("invalid subscription information\n"))
#define MSG_EVE_INVALIDINTERVAL_U     _MESSAGE(33350, _("invalid event interval "U32CFormat"\n"))

#define MSG_COM_ACKTIMEOUT4EV_ISIS    _MESSAGE(33351, _("acknowledge timeout after %d seconds for event client (%s:%d) on host \"%s\""))
#define MSG_COM_NOSHUTDOWNPERMS       _MESSAGE(33352, _("shutdown requires manager privileges\n"))
#define MSG_COM_NOSCHEDDREGMASTER     _MESSAGE(33353, _("no scheduler registered at qmaster\n"))
#define MSG_COM_NOSCHEDMONPERMS       _MESSAGE(33354, _("starting scheduler monitoring requires manager privileges\n"))
#define MSG_COM_SCHEDMON_SS           _MESSAGE(33355, _("%s@%s triggers scheduler monitoring\n"))
/*
** sge_manop.c
*/
#define MSG_OBJ_MANAGER               _MESSAGE(33356, _("manager"))
#define MSG_OBJ_OPERATOR              _MESSAGE(33357, _("operator"))
#define MSG_SGETEXT_MAY_NOT_REMOVE_USER_FROM_LIST_SS  _MESSAGE(33358, _("may not remove user "SFQ" from "SFN" list\n"))

/*
** sge_pe_qmaster.c
*/
#define MSG_OBJ_USERLIST              _MESSAGE(33360, _("user list"))
#define MSG_OBJ_XUSERLIST             _MESSAGE(33361, _("xuser list"))
#define MSG_PE_ALLOCRULE_SS           _MESSAGE(33362, _("parameter allocation_rule of pe "SFQ": %s\n"))
#define MSG_PE_USEDSLOTSTOOBIG_S      _MESSAGE(33366, _("PE_used_slots of pe %s is greater than PE_slots!\n") )  
#define MSG_PE_STARTPROCARGS_SS       _MESSAGE(33367, _("parameter start_proc_args of pe "SFQ": %s\n"))
#define MSG_PE_STOPPROCARGS_SS        _MESSAGE(33368, _("parameter stop_proc_args of pe "SFQ": %s\n"))

/*
** sge_ckpt_qmaster.c
*/ 
#define MSG_CKPT_INVALIDWHENATTRIBUTE_S _MESSAGE(33369, _("Invalid \"when\" attribute for ckpt "SFQ"\n"))
#define MSG_CKPT_XISNOTASIGNALSTRING_S  _MESSAGE(33370, _("\"%s\" is not a signal string (like HUP, INT, " "WINCH, ..)\n"))

/*
** sge_qmod_qmaster.c
*/
#define MSG_QUEUE_INVALIDQ_S          _MESSAGE(33371, _("invalid queue "SFQ"\n"))
#define MSG_QUEUE_INVALIDQORJOB_S     _MESSAGE(33372, _("invalid queue or job "SFQ"\n"))
#define MSG_QUEUE_NOCHANGEQPERMS_SS   _MESSAGE(33373, _("%s - you have no permission to modify queue "SFQ"\n"))
#define MSG_LOG_UNKNOWNQMODCMD_U      _MESSAGE(33374, _("unknown command type\n" U32CFormat))
#define MSG_JOB_NOMODJOBPERMS_SU      _MESSAGE(33375, _("%s - you have no permission to modify job \"" U32CFormat "\"\n"))
#define MSG_JOB_CLEARERRORTASK_SSUU   _MESSAGE(33376, _("%s@%s cleared error state of job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_CLEARERRORJOB_SSU     _MESSAGE(33377, _("%s@%s cleared error state of job "U32CFormat"\n"))
#define MSG_JOB_NOERRORSTATETASK_UU   _MESSAGE(33378, _("Job-array task "U32CFormat"."U32CFormat" is not in error state\n"))
#define MSG_JOB_NOERRORSTATEJOB_UU    _MESSAGE(33379, _("Job "U32CFormat" is not in error state\n"))
#define MSG_QUEUE_NOCLEARERRORPERMS_SS   _MESSAGE(33380, _("%s - you have no permission to clear error state of queue "SFQ"\n") )   
#define MSG_QUEUE_NOERRORSTATEQ_SS    _MESSAGE(33381, _("%s - queue "SFQ" is not in error state\n"))
#define MSG_QUEUE_NOTMODIFIEDSPOOL_S  _MESSAGE(33382, _("Queue state of "SFQ" not modified: impossible to write spoolfile\n"))
#define MSG_QUEUE_CLEARERRORSTATE_SSS _MESSAGE(33383, _("The error state of queue "SFQ" has been cleared by %s@%s\n"))
#define MSG_QUEUE_NOENABLEQPERMS_SS   _MESSAGE(33384, _("%s - you have no permission to enable queue "SFQ"\n"))
#define MSG_QUEUE_ALREADYENABLED_SS   _MESSAGE(33385, _("%s - queue "SFQ" is already enabled\n"))
#define MSG_QUEUE_ENABLEQ_SSS         _MESSAGE(33386, _("Queue "SFQ" has been enabled by %s@%s\n"))
#define MSG_QUEUE_NODISABLEQPERMS_SS  _MESSAGE(33387, _("%s - you have no permission to disable queue "SFQ"\n"))
#define MSG_QUEUE_NORESCHEDULEQPERMS_SS  _MESSAGE(33388, _("%s - you have no permission to reschedule jobs of queue "SFQ"\n"))
#define MSG_QUEUE_ALREADYDISABLED_SS  _MESSAGE(33389, _("%s - queue "SFQ" is already disabled\n"))
#define MSG_QUEUE_DISABLEQ_SSS        _MESSAGE(33390, _("Queue "SFQ" has been disabled by %s@%s\n"))
#define MSG_QUEUE_NOFORCESUSPENDQ_SS  _MESSAGE(33392, _("%s - can't force suspension of queue "SFQ"\n"))
#define MSG_QUEUE_FORCESUSPENDQ_SS    _MESSAGE(33393, _("%s - forced suspension of queue "SFQ"\n"))
#define MSG_QUEUE_ALREADYSUSPENDED_SS _MESSAGE(33394, _("%s - queue "SFQ" is already suspended\n"))
#define MSG_QUEUE_NOSUSPENDQ_SS       _MESSAGE(33395, _("%s - can't suspend queue "SFQ"\n"))
#define MSG_QUEUE_SUSPENDQ_SSS        _MESSAGE(33396, _("Queue "SFQ" was suspended by %s@%s\n"))
#define MSG_QUEUE_NOFORCEENABLEQ_SS   _MESSAGE(33397, _("%s - can't force enabling of queue "SFQ"\n"))
#define MSG_QUEUE_FORCEENABLEQ_SSS     _MESSAGE(33398, _("%s@%s - forced enabling of queue "SFQ"\n"))
#define MSG_QUEUE_NOUNSUSP4SOS_SS     _MESSAGE(33399, _("%s - can't unsuspend queue "SFQ" - queue is suspended because of suspend on subordinate\n"))
#define MSG_QUEUE_NOUNSUSP4SOC_SS     _MESSAGE(33400, _("%s - can't unsuspend queue "SFQ" - queue is suspended on calendar\n"))
#define MSG_QUEUE_ALREADYUNSUSP_SS    _MESSAGE(33401, _("%s - queue "SFQ" is already unsuspended\n"))
#define MSG_QUEUE_NOUNSUSPQ_SS        _MESSAGE(33402, _("%s - can't unsuspend queue "SFQ"\n"))
#define MSG_QUEUE_UNSUSPENDQ_SSS      _MESSAGE(33403, _("%s@%s unsuspended queue "SFQ"\n"))
#define MSG_QUEUE_NOCLEANQPERMS       _MESSAGE(33404, _("cleaning a queue requires manager privileges\n"))
#define MSG_QUEUE_CLEANQ_SSS          _MESSAGE(33405, _("%s@%s cleaned queue "SFQ"\n"))
#define MSG_JOB_NOFORCESUSPENDTASK_SUU     _MESSAGE(33406, _("%s - can't force suspension job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_NOFORCESUSPENDJOB_SU       _MESSAGE(33407, _("%s - can't force suspension job "U32CFormat"\n"))
#define MSG_JOB_FORCESUSPENDTASK_SUU  _MESSAGE(33408, _("%s - forced suspension of job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_FORCESUSPENDJOB_SU    _MESSAGE(33409, _("%s - forced suspension of job "U32CFormat"\n"))
#define MSG_JOB_ALREADYSUSPENDED_SUU  _MESSAGE(33410, _("%s - job-array task "U32CFormat"."U32CFormat" is already suspended\n"))
#define MSG_JOB_ALREADYSUSPENDED_SU   _MESSAGE(33411, _("%s - job "U32CFormat" is already suspended\n"))
#define MSG_JOB_ALREADYUNSUSPENDED_SUU  _MESSAGE(33412, _("%s - job-array task "U32CFormat"."U32CFormat" is already unsuspended\n"))
#define MSG_JOB_ALREADYUNSUSPENDED_SU _MESSAGE(33413, _("%s - job "U32CFormat" is already unsuspended\n"))
#define MSG_JOB_NOSUSPENDTASK_SUU     _MESSAGE(33414, _("%s - can't suspend job-array task "U32CFormat"."U32CFormat" \n"))
#define MSG_JOB_NOSUSPENDJOB_SU       _MESSAGE(33415, _("%s - can't suspend job "U32CFormat" \n"))
#define MSG_JOB_NOUNSUSPENDTASK_SUU   _MESSAGE(33416, _("%s - can't unsuspend job-array task "U32CFormat"."U32CFormat" \n"))
#define MSG_JOB_NOUNSUSPENDJOB_SU     _MESSAGE(33417, _("%s - can't unsuspend job "U32CFormat" \n"))
#define MSG_JOB_SUSPENDTASK_SUU       _MESSAGE(33418, _("%s - suspended job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_SUSPENDJOB_SU         _MESSAGE(33419, _("%s - suspended job " U32CFormat "\n"))
#define MSG_JOB_UNSUSPENDTASK_SUU     _MESSAGE(33421, _("%s - unsuspended job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_UNSUSPENDJOB_SU       _MESSAGE(33422, _("%s - unsuspended job " U32CFormat "\n"))
#define MSG_JOB_RMADMSUSPENDTASK_SSUU _MESSAGE(33423, _("%s@%s removed administrator suspension of job-array task "U32CFormat"."U32CFormat" (suspend threshold is still active)\n"))
#define MSG_JOB_RMADMSUSPENDJOB_SSU   _MESSAGE(33424, _("%s@%s removed administrator suspension of job "U32CFormat" (suspend threshold is still active)\n"))
#define MSG_JOB_NOADMSUSPENDTASK_SUU  _MESSAGE(33425, _("%s - job-array task "U32CFormat"."U32CFormat" is not suspended by administrator - modify suspend threshold list of queue to remove suspend state\n"))
#define MSG_JOB_NOADMSUSPENDJOB_SU    _MESSAGE(33426, _("%s - job "U32CFormat" is not suspended by administrator - modify suspend threshold list of queue to remove suspend state\n"))
#define MSG_JOB_NOFORCEENABLETASK_SUU _MESSAGE(33427, _("%s - can't force enabling of job-array task "U32CFormat"."U32CFormat "\"\n"))
#define MSG_JOB_NOFORCEENABLEJOB_SU   _MESSAGE(33428, _("%s - can't force enabling of job "U32CFormat"\n"))
#define MSG_JOB_FORCEENABLETASK_SUU   _MESSAGE(33429, _("%s - forced enabling of job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_FORCEENABLEJOB_SU     _MESSAGE(33430, _("%s - forced enabling of job "U32CFormat"\n"))
#define MSG_JOB_FORCEUNSUSPTASK_SSUU  _MESSAGE(33431, _("%s@%s forced unsuspension of job-array task "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_FORCEUNSUSPJOB_SSU    _MESSAGE(33432, _("%s@%s forced unsuspension of job "U32CFormat"\n"))
#define MSG_EVE_RESENTSIGNALTASK_UU   _MESSAGE(33433, _("got resend signal timer event for unknown array task "U32CFormat"."U32CFormat"\n") ) 
#define MSG_EVE_RESENTSIGNALQ_S       _MESSAGE(33434, _("got resend signal timer event for unknown queue %s\n"))
#define MSG_COM_NOUPDATEQSTATE_IS     _MESSAGE(33435, _("can't update remote queue state (%d) on queue "SFQ))
#define MSG_QUEUE_ENABLEQCAL_S        _MESSAGE(33436, _("enable queue "SFQ" on calendar\n"))
#define MSG_QUEUE_SOSNOUNSUSPCAL_S    _MESSAGE(33437, _("suspension on subordinate prevents unsuspension according to calendar for queue "SFQ"\n"))
#define MSG_QUEUE_AMDSNOUNSUSPCAL_S   _MESSAGE(33438, _("administrator suspension prevents unsuspension according to calendar for queue "SFQ"\n"))
#define MSG_QUEUE_SUSPENDQCAL_S       _MESSAGE(33439, _("suspend queue "SFQ" on calendar\n"))
#define MSG_QUEUE_DISABLEQCAL_S       _MESSAGE(33440, _("disable queue "SFQ" on calendar\n"))
#define MSG_QUEUE_UNSUSPENDQCAL_S     _MESSAGE(33441, _("unsuspend queue "SFQ" on calendar\n"))
#define MSG_QUEUE_NOSUSP4SOS_S        _MESSAGE(33442, _("no need to suspend queue "SFQ" it's already suspended on subordinate\n"))
#define MSG_QUEUE_NOSUSP4ADMS_S       _MESSAGE(33443, _("no need to suspend queue "SFQ" it's already suspended by administrator\n"))
#define MSG_QUEUE_ADDENABLED_S        _MESSAGE(33444, _("adding queue "SFQ" it gets enabled according to initial_state\n"))
#define MSG_QUEUE_ADDDISABLED_S       _MESSAGE(33445, _("adding queue "SFQ" it gets disabled according to initial_state\n"))
#define MSG_QUEUE_EXECDRESTARTENABLEQ_SS    _MESSAGE(33446, _("execd restart at "SFQ" enables queue "SFQ" according to initial_state\n"))
#define MSG_QUEUE_EXECDRESTARTDISABLEQ_SS   _MESSAGE(33447, _("execd restart at "SFQ" disables queue "SFQ" according to initial_state\n"))
/*
** sge_queue_qmaster.c
*/
#define MSG_QUEUE_PRIORITYRANGE                 _MESSAGE(33448, _("priority not in range -20 to +20\n"))
#define MSG_QUEUE_CANTLOCATEQUEUEX_S            _MESSAGE(33449, _("can't locate queue %s\n"))
#define MSG_QUEUE_DELQUEUETEMPLATE              _MESSAGE(33450, _("deleting queue \"template\""))
#define MSG_QUEUE_NULLPTRPASSEDTOSGE_DEL_QUEUE  _MESSAGE(33451, _("NULL ptr passed to sge_del_queue()\n"))
#define MSG_CALENDAR_CALENDARXREFERENCEDINQUEUEYNOTEXISTS_SS _MESSAGE(33452, _("calendar "SFQ" referenced in queue "SFQ" does not exist\n"))
#define MSG_QUEUE_NULLPTR             _MESSAGE(33453, _("NULL ptr passed to sge_add_queue()\n"))
#define MSG_OBJ_QUEUE                 _MESSAGE(33454, _("queue"))
#define MSG_UNABLETODELQUEUEXREFERENCEDINCHKPTY_SS _MESSAGE(33455, _("unable to delete queue "SFQ", referenced in checkpoint definition "SFQ"\n"))
#define MSG_UNABLETODELQUEUEXREFERENCEDINPEY_SS _MESSAGE(33456, _("unable to delete queue "SFQ", referenced in parallel environment definition "SFQ"\n"))
#define MSG_SGETEXT_NOTPOSSIBLETOMODHOSTNAME          _MESSAGE(33457, _("it is not possible to modify the hostname attribute\n"))
#define MSG_SGETEXT_OPNOTALLOWED_S              _MESSAGE(33459, _("operation not allowed: "SFN"\n"))
#define MSG_NOTALLOWEDTODELSUBORDINATE_SS              _MESSAGE(33460, _("deleting queue "SFQ" is not allowed because it is subordinate queue of "SFQ"\n"))
#define MSG_SGETEXT_ACTIVEUNITS_SSIS            _MESSAGE(33461, _(""SFN" "SFQ" has %d active "SFN"\n"))
#define MSG_SGETEXT_COMPLEXNOTUSERDEFINED_SSS         _MESSAGE(33462, _("denied: complex "SFQ" referenced in "SFN" "SFQ" is not a user complex\n") )  
#define MSG_SGETEXT_UNKNOWNQUEUE_SSSS                 _MESSAGE(33463, _("denied: queue "SFQ" referenced in "SFN" of "SFN" "SFQ" does not exist\n"))
#define MSG_SGETEXT_QUEUEALLANDQUEUEARENOT_SSSS        _MESSAGE(33464, _("queuenames and keyword "SFQ" are not allowed in "SFQ" of "SFQ" "SFQ"\n"))
#define MSG_SGETEXT_UNKNOWNCOMPLEX_SSS                _MESSAGE(33466, _("denied: complex "SFQ" referenced in "SFN" "SFQ" does not exist\n") )  
#define MSG_AT_LEASTONEQTYPE                          _MESSAGE(33467, _("At least one queue type must be selected\n"))

/*
** qmaster.c
*/
#define MSG_SGETEXT_KILL_SSS                    _MESSAGE(33468, _(""SFN"@"SFN" kills "SFN"\n"))
#define MSG_SETTING_PRIORITY_TAGS_S             _MESSAGE(33469, _("setting SGE_PRIORITY_TAGS to %s\n"))
#define MSG_TOO_MANY_PRIORITY_TAGS_S            _MESSAGE(33470, _("SGE_PRIORITY_TAGS %s contains too many tags (max 9)\n"))


/*
** sge_sharetree_qmaster.c
*/
#define MSG_STREE_ADDSTREE_SSII       _MESSAGE(33471, _("%s@%s has added sharetree with %d nodes and %d leafs\n"))
#define MSG_STREE_MODSTREE_SSII       _MESSAGE(33472, _("%s@%s has modified sharetree with %d nodes and %d leafs\n"))
#define MSG_STREE_PRJINPTJSUBTREE_SS  _MESSAGE(33473, _("found project "SFQ" in project "SFQ" sub-tree of share tree\n"))
#define MSG_STREE_PRJTWICE_S          _MESSAGE(33474, _("found project "SFQ" twice in share tree\n"))
#define MSG_STREE_USERNONLEAF_S       _MESSAGE(33475, _("found user "SFQ" in share tree as a non-leaf node\n"))
#define MSG_STREE_USERTWICEINPRJSUBTREE_SS _MESSAGE(33476, _("found user "SFQ" twice in project "SFQ" sub-tree of share tree\n"))
#define MSG_STREE_USERTNOACCESS2PRJ_SS   _MESSAGE(33477, _("found user "SFQ" with no access to project "SFQ" sub-tree of share tree\n"))
#define MSG_STREE_USERPRJTWICE_SS     _MESSAGE(33478, _("found %s "SFQ" twice in share tree\n"))
#define MSG_STREE_QMASTERSORCETREE_SS _MESSAGE(33479, _("tree of qmaster has %snode while source tree has %snode\n"))
#define MSG_STREE_NOPLUSSPACE         _MESSAGE(33480, _("no "))
#define MSG_STREE_VERSIONMISMATCH_II  _MESSAGE(33481, _("trees have different versions: qmaster=%d src=%d\n") ) 
#define MSG_STREE_MISSINGNODE_S       _MESSAGE(33482, _("missing node "SFQ" in dst trees\n"))
#define MSG_SGETEXT_DOESNOTEXIST_S              _MESSAGE(33483, _(""SFN" does not exist\n"))
#define MSG_SGETEXT_REMOVEDLIST_SSS         _MESSAGE(33484, _(""SFN"@"SFN" removed "SFN" list\n"))
#define MSG_SGETEXT_FOUND_UP_TWICE_SS                 _MESSAGE(33485, _("denied: found node "SFQ" twice under node "SFQ"\n") )     
#define MSG_SGETEXT_UNKNOWN_SHARE_TREE_REF_TO_SS      _MESSAGE(33486, _("denied: share tree contains reference to unknown "SFN" "SFQ"\n") )  


/*
** sge_userprj_qmaster.c
*/
#define MSG_USERPRJ_PRJXSTILLREFERENCEDINENTRYX_SS _MESSAGE(33487, _("project "SFQ" is still referenced by user "SFQ"\n"))
#define MSG_UP_NOADDDEFAULT_S          _MESSAGE(33488, _("denied: not allowed add a %s with name \"default\"\n") ) 
#define MSG_UP_ALREADYEXISTS_SS        _MESSAGE(33489, _("denied: shared namespace between project and user: there is already a " SFN " which is named " SFQ "\n"))
#define MSG_UM_CLUSTERUSERXNOTGUILTY_S _MESSAGE(33490, _("cluster user name '%s' is not valid\n"))
#define MSG_HGRP_GROUPXNOTGUILTY_S     _MESSAGE(33491, _("host group name '%s' is not valid\n"))
#define MSG_HGRP_CANTADDMEMBERXTOGROUPY_SS      _MESSAGE(33492, _("can't add member '%s' to host group '%s'\n"))
#define MSG_UM_MAPLISTFORXEXISTS_S     _MESSAGE(33495, _("mapping list for '%s' allready exist\n"))
#define MSG_HGRP_MEMBERLISTFORXEXISTS_S _MESSAGE(33496, _("member list for '%s' allready exist\n"))
#define MSG_UM_NOMAPLISTFORXFOUND_S    _MESSAGE(33497, _("no mapping list for '%s' found\n"))
#define MSG_UM_EXIMINEMAPFORX_S        _MESSAGE(33500, _("examine mapping for cluster user '%s'\n"))
#define MSG_UM_ERRORADDMAPENTRYXFORY_SS _MESSAGE(33503, _("error adding mapping entry '%s' for cluster user '%s'"))
#define MSG_UM_ERRORWRITESPOOLFORUSER_S _MESSAGE(33504, _("error writing spoolfile for cluster user '%s'"))
#define MSG_HGRP_ERRORWRITESPOOLFORGROUP_S  _MESSAGE(33505, _("error writing spoolfile for host group '%s'"))
#define MSG_OBJ_PRJ                    _MESSAGE(33506, _("project"))
#define MSG_OBJ_PRJS                  _MESSAGE(33507, _("projects"))
#define MSG_OBJ_XPRJS                 _MESSAGE(33508, _("xprojects"))
#define MSG_OBJ_EH                    _MESSAGE(33509, _("exechost"))
#define MSG_OBJ_CONF                  _MESSAGE(33510, _("configuration"))
#define MSG_OBJ_GLOBAL                _MESSAGE(33511, _("global"))
#define MSG_FILE_RM_S                 _MESSAGE(33512, _("cant remove %s from disk"))
#define MSG_SGETEXT_PROJECTSTILLREFERENCED_SSSS       _MESSAGE(33516, _("denied: project "SFQ" is still referenced in "SFN" of "SFN" "SFQ"\n") )   
#define MSG_SGETEXT_UNKNOWNPROJECT_SSSS               _MESSAGE(33517, _("denied: project "SFQ" referenced in "SFN" of "SFN" "SFQ" does not exist\n") )  


/*
** sge_userset_qmaster.c
*/
#define MSG_US_INVALIDUSERNAME        _MESSAGE(33518, _("userset contains invalid (null) user name"))
#define MSG_SGETEXT_NO_DEPARTMENT4USER_SS             _MESSAGE(33519, _("denied: no matching department for user "SFQ" or group "SFQ"\n") )  
#define MSG_SGETEXT_UNKNOWNUSERSET_SSSS               _MESSAGE(33520, _("denied: userset "SFQ" referenced in "SFN" of "SFN" "SFQ" does not exist\n") ) 
#define MSG_SGETEXT_USERSETSTILLREFERENCED_SSSS       _MESSAGE(33521, _("denied: userset "SFQ" is still referenced in "SFN" of "SFN" "SFQ"\n") ) 


/*
** complex_qmaster.c
*/
#define MSG_CPLX_ATTRIBISNULL_SS      _MESSAGE(33522, _("attribute name "SFQ" in complex "SFQ" contains invalid (null) values\n"))
#define MSG_CPLX_ATTRIBALREADY_SS     _MESSAGE(33523, _("attribute name "SFQ" is already in use in complex "SFQ"\n"))
#define MSG_CPLX_SHORTCUTALREADY_SS   _MESSAGE(33524, _("shortcut name "SFQ" is already in use in complex "SFQ"\n"))
#define MSG_CPLX_ATTRIBNOCONSUM_S     _MESSAGE(33525, _("denied: attribute "SFQ" is a string type and thus may not be consumable\n"))
#define MSG_CPLX_ATTRIBNOCONSUMEH_SS  _MESSAGE(33526, _("denied: attribute "SFQ" in 'complex_list' of exec host "SFQ" has a string value and thus it may not be consumable\n"))
#define MSG_CPLX_ATTRIBNOCONSUMQ_SS   _MESSAGE(33527, _("denied: attribute "SFQ" in 'complex_list' of queue "SFQ" has a string value and thus it may not be consumable\n"))
#define MSG_FILE_NOOPENDIR_S          _MESSAGE(33528, _("can't open directory "SFQ))
#define MSG_FILE_NOWRITEHIST_S        _MESSAGE(33529, _("can't write history for complex "SFQ))
#define MSG_NONAME                    _MESSAGE(33530, _("<noname>"))
#define MSG_OBJ_CPLX                  _MESSAGE(33531, _("complex"))
#define MSG_ATTRSTILLREFINQUEUE_SS    _MESSAGE(33532, _("attribute "SFQ" still referenced in queue "SFQ" - complex not modified"))
#define MSG_ATTRSTILLREFINHOST_SS     _MESSAGE(33533, _("attribute "SFQ" still referenced in host "SFQ" - complex not modified"))
#define MSG_ATTRSTILLREFINSCHED_S     _MESSAGE(33534, _("attribute "SFQ" still referenced in scheduler configuration - complex not modified"))
#define MSG_SGETEXT_CANTDELCMPLX_S              _MESSAGE(33535, _("can't delete complex "SFQ" from list\n"))
#define MSG_SGETEXT_CANTDELCMPLXDISK_S          _MESSAGE(33536, _("can't delete complex "SFQ" from disk\n"))


/*
** configuration_qmaster.c
*/
#define MSG_SGETEXT_CANT_DEL_CONFIG_S           _MESSAGE(33538, _("can't delete configuration "SFQ" from list\n"))
#define MSG_CONF_DELLOCCONFFORXWITHEXECDSPOOLDENIED_S  _MESSAGE(33539, _("Deleting local configuration for "SFQ" with a local execd_spool_dir setting only supported in a shut-down cluster.\n"))
#define MSG_SGETEXT_CANT_DEL_CONFIG_DISK_SS     _MESSAGE(33540, _("can't delete configuration "SFQ" from disk: %s\n"))
#define MSG_CONF_CANTSELECTCONFIGURATIONFORHOST_SI _MESSAGE(33542, _("can't select configuration for host "SFQ": %d"))
#define MSG_CONF_CANTMERGECONFIGURATIONFORHOST_SI _MESSAGE(33543, _("can't merge configuration for host "SFQ": %d"))
#define MSG_CONF_CHANGEPARAMETERXONLYSUPONSHUTDOWN_S _MESSAGE(33544, _("Changing parameter "SFQ" only supported in a shut-down cluster.\n"))
#define MSG_CONF_NAMEISNULLINCONFIGURATIONLISTOFX_S _MESSAGE(33545, _("name == NULL in configuration list of "SFQ"\n"))
#define MSG_CONF_VALUEISNULLFORATTRXINCONFIGURATIONLISTOFY_SS _MESSAGE(33546, _("value == NULL for attribute "SFQ" in configuration list of "SFQ"\n"))
#define MSG_CONF_GOTINVALIDVALUEXFORLOGLEVEL_S _MESSAGE(33547, _("denied: got invalid value "SFQ" for loglevel\n"))
#define MSG_CONF_GOTINVALIDVALUEXFORSHELLSTARTMODE_S _MESSAGE(33548, _("denied: got invalid value "SFQ" for shell_start_mode\n"))
#define MSG_CONF_GOTINVALIDVALUEXASADMINUSER_S _MESSAGE(33549, _("denied: got invalid value "SFQ" as admin_user\n"))
#define MSG_CONF_PARAMETERXINCONFIGURATION_SS _MESSAGE(33550, _("denied: parameter "SFQ" in configuration: "SFQ"\n"))
#define MSG_CONF_THEPATHGIVENFORXMUSTSTARTWITHANY_S _MESSAGE(33551, _("denied: the path given for "SFQ" must start with an \"/\"\n"))
#define MSG_CONF_INFNOTALLOWEDFORATTRXINCONFLISTOFY_SS _MESSAGE(33552, _("infinity not allowed for attribute "SFQ" in configuration list of "SFQ"\n"))
#define MSG_CONF_FORMATERRORFORXINYCONFIG_SS _MESSAGE(33553, _("format error for "SFQ" in "SFQ" configuration\n"))


/*
** job_exit.c
*/
#define MSG_OBJ_UNKNOWNQ              _MESSAGE(33554, _("<unknown queue>"))
#define MSG_OBJ_UNKNOWNHOST           _MESSAGE(33555, _("<unknown host>"))
#define MSG_JOB_WRITEJFINISH_S        _MESSAGE(33556, _("writing job finish information: can't locate queue \"%s\"\n"))
#define MSG_JOB_JFINISH_UUS           _MESSAGE(33557, _("job "U32CFormat"."U32CFormat" finished on host %s"))
#define MSG_JOB_FAILEDONHOST_UUSSSS   _MESSAGE(33558, _("job "U32CFormat"."U32CFormat" failed on host "SFN" "SFN" "SFN" because: %-.512s"))
#define MSG_GENERAL                   _MESSAGE(33559, _("general "))
#define MSG_JOB_JEXITNOTRUN_UU        _MESSAGE(33560, _("received JOB_EXIT for job "U32CFormat"."U32CFormat" which ist NOT running\n"))
#define MSG_LOG_JREMOVED              _MESSAGE(33561, _("job removed "))
#define MSG_LOG_JERRORSET             _MESSAGE(33562, _("job set in error state "))
#define MSG_LOG_JNOSTARTRESCHEDULE    _MESSAGE(33563, _("job never ran -> schedule it again"))
#define MSG_LOG_JRERUNRESCHEDULE      _MESSAGE(33564, _("job rerun/checkpoint specified -> schedule it again"))
#define MSG_LOG_JCKPTRESCHEDULE       _MESSAGE(33565, _("job was checkpointed -> schedule it again"))
#define MSG_LOG_JNORESRESCHEDULE      _MESSAGE(33566, _("job didn't get resources -> schedule it again"))
#define MSG_LOG_QERRORBYJOB_SU        _MESSAGE(33567, _("queue %s marked QERROR as result of job "U32CFormat"'s failure\n") ) 
#define MSG_LOG_QERRORBYJOBHOST_SUS   _MESSAGE(33568, _("queue %s marked QERROR as result of job "U32CFormat"'s failure at host %s\n"))
#define MSG_FILE_WRITE_S              _MESSAGE(33569, _("writing to %s\n"))
#define MSG_FILE_WRITEACCT            _MESSAGE(33570, _("can't write to acct_file\n"))


/*
** job_report_qmaster.c
*/
#define MSG_JOB_REPORTEXITQ_SUUSSSSS   _MESSAGE(33571, _("execd %s reports exiting job ("U32CFormat"."U32CFormat"/%s in queue "SFQ" that was supposed to be in queue "SFQ" at "SFQ" (state = %s)"))
#define MSG_JOB_REPORTRUNQ_SUUSSU      _MESSAGE(33572, _("execd %s reports running state for job ("U32CFormat"."U32CFormat"/%s) in queue "SFQ" while job is in state "U32CFormat" "))
#define MSG_JOB_REPORTRUNFALSE_SUUSS   _MESSAGE(33573, _("execd@%s reports running job ("U32CFormat"."U32CFormat"/%s) in queue "SFQ" that was not supposed to be there - killing"))
#define MSG_JOB_REPORTEXITJ_UUU        _MESSAGE(33574, _("JEXITING report for job "U32CFormat"."U32CFormat": which is in status "U32CFormat"\n"))
#define MSG_JOB_FILESIZEEXCEED_SSUU    _MESSAGE(33575, _("file size resource limit exceeded by task %s at %s of job "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_CPULIMEXCEED_SSUU      _MESSAGE(33576, _("cpu time resource limit exceeded by task %s at %s of job "U32CFormat"."U32CFormat"\n"))
#define MSG_JOB_DIEDTHROUGHSIG_SSUUS   _MESSAGE(33577, _("task %s at %s of job "U32CFormat"."U32CFormat" died through signal %s\n"))
#define MSG_JOB_TASKFAILED_SSUUU       _MESSAGE(33578, _("task %s at %s of job "U32CFormat"."U32CFormat" failed "U32CFormat"\n"))
#define MSG_JOB_TASKFINISHED_SSUU      _MESSAGE(33579, _("task %s at %s of job "U32CFormat"."U32CFormat" finished\n"))
#define MSG_JOB_JOBTASKFAILED_SU       _MESSAGE(33580, _("task %s of job "U32CFormat" failed - killing job\n"))
#define MSG_OBJ_NOTRUNNING             _MESSAGE(33581, _("<not running>"))
#define MSG_EXECD_UNKNOWNJ_SUUSUS      _MESSAGE(33582, _("execd %s reports unknown job ("U32CFormat"."U32CFormat"/%s) with unknown state "U32CFormat" in queue "SFQ))


/*
** qmaster.c
*/
#define MSG_STARTUP_PROGRAMCALLEDWITHINVALIDNAME_S        _MESSAGE(33583, _("program called with invalid name: '%s'\n"))
#define MSG_STARTUP_PROGRAMDOESNOTMATCHPRODUCTMODE_S      _MESSAGE(33584, _("program name '%s' does not match product mode"))
#define MSG_COMMD_CANTENROLLTOCOMMD_S              _MESSAGE(33585, _("can't enroll to commd: %s"))
#define MSG_COMMD_FOUNDRUNNINGCOMMDONLOCALHOST              _MESSAGE(33586, _("found running commd on local host"))
#define MSG_STARTUP_BEGINWITHSTARTUP              _MESSAGE(33587, _("begin with start up"))
#define MSG_STARTUP_SETUPFAILED              _MESSAGE(33588, _("setup failed"))
#define MSG_QIDL_CANTINITIALIZEQIDL              _MESSAGE(33589, _("cannot initialze qidl"))
#define MSG_QIDL_CANTSPAWNTHREADFORCORBASERVER              _MESSAGE(33590, _("cannot spawn thread for corba server"))
#define MSG_GDI_FAILEDINSGEUNPACKGDIREQUEST_SSI           _MESSAGE(33591, _("Failed in sge_unpack_gdi_request (%s/%s/%d)\n"))
#define MSG_CULL_FAILEDINCULLUNPACKLISTREPORT              _MESSAGE(33592, _("Failed in cull_unpack_list report\n"))
#define MSG_SHUTDOWN_SHUTTINGDOWNQMASTERREQUIRESMANAGERPRIVILEGES              _MESSAGE(33593, _("shutting down qmaster requires manager privileges\n"))
#define MSG_GOTSTATUSREPORTOFUNKNOWNCOMMPROC_S    _MESSAGE(33594, _("got load report of unknown commproc "SFQ"\n"))
#define MSG_GOTSTATUSREPORTOFUNKNOWNEXECHOST_S    _MESSAGE(33595, _("got load report of unknown exec host "SFQ"\n"))
#define MSG_CONF_CANTNOTIFYEXECHOSTXOFNEWCONF_S    _MESSAGE(33596, _("can't notify exec host "SFQ" of new conf\n"))
#define MSG_LICENCE_ERRORXUPDATINGLICENSEDATA_I    _MESSAGE(33597, _("error %d updating license data\n"))
#define MSG_HEARTBEAT_FAILEDTOINCREMENTHEARBEATFILEXINSPOOLDIR_S    _MESSAGE(33598, _("failed to increment heartbeat file "SFQ" in spool directory"))
#define MSG_GDI_FAILEDTOEXTRACTAUTHINFO    _MESSAGE(33599, _("failed to extract authentication information"))

/*
** qmaster_to_execd.c
*/
#define MSG_NOXKNOWNONHOSTYTOSENDCONFNOTIFICATION_SS  _MESSAGE(33600, _("no %s known on host %s to send conf notification\n"))

/*
** read_write_manop.c
*/
#define MSG_FILE_ERROROPENINGX_S    _MESSAGE(33601, _("error opening %s\n"))

/*
** setup_qmaster.c
*/
#define MSG_SETUP_QUEUE_S                          _MESSAGE(33602, _("\tQueue "SFQ".\n"))
#define MSG_SETUP_USERSET_S                        _MESSAGE(33603, _("\tUserset "SFQ".\n"))
#define MSG_SETUP_USER_S                           _MESSAGE(33604, _("\tUser "SFQ".\n"))
#define MSG_SETUP_PROJECT_S                        _MESSAGE(33605, _("\tProject "SFQ".\n"))
#define MSG_SETUP_MAPPINGETRIES_S                  _MESSAGE(33606, _("\tMapping entries for "SFQ".\n"))
#define MSG_SETUP_HOSTGROUPENTRIES_S               _MESSAGE(33607, _("\tHost group entries for group "SFQ".\n"))
#define MSG_SETUP_PE_S                             _MESSAGE(33608, _("\tPE "SFQ".\n"))
#define MSG_SETUP_CALENDAR_S                       _MESSAGE(33609, _("\tCalendar "SFQ".\n"))
#define MSG_SETUP_COMPLEX_S                        _MESSAGE(33610, _("\tComplex "SFQ".\n"))
#define MSG_SETUP_CKPT_S                           _MESSAGE(33611, _("\tCKPT "SFQ".\n"))
#define MSG_SETUP_SETUPMAYBECALLEDONLYATSTARTUP    _MESSAGE(33612, _("setup may be called only at startup"))
#define MSG_CONFIG_FOUNDNOLOCALCONFIGFORQMASTERHOST_S    _MESSAGE(33613, _("found no local configuration for qmaster host "SFQ))
#define MSG_CONFIG_ERRORXSELECTINGCONFIGY_IS    _MESSAGE(33614, _("Error %d selecting configuration "SFQ"\n"))
#define MSG_CONFIG_ERRORXMERGINGCONFIGURATIONY_IS    _MESSAGE(33615, _("Error %d merging configuration "SFQ"\n"))
#define MSG_CONFIG_ADDINGHOSTTEMPLATETOEXECHOSTLIST    _MESSAGE(33616, _("adding host template to exechost_list\n"))
#define MSG_CONFIG_ADDINGHOSTGLOBALTOEXECHOSTLIST    _MESSAGE(33617, _("adding host global to exechost_list\n"))
#define MSG_CONFIG_CANTWRITEMANAGERLIST       _MESSAGE(33618, _("can't write manager list\n"))
#define MSG_CONFIG_CANTWRITEOPERATORLIST      _MESSAGE(33619, _("can't write operator list\n"))
#define MSG_CONFIG_READINGINUSERSETS       _MESSAGE(33620, _("Reading in usersets:\n"))
#define MSG_CONFIG_READINGFILE_SS       _MESSAGE(33621, _("reading file %s/%s\n"))
#define MSG_CONFIG_READINGINQUEUES       _MESSAGE(33622, _("Reading in queues:\n"))
#define MSG_CONFIG_QUEUEXUPDATED_S       _MESSAGE(33623, _("Queue %s updated\n"))
#define MSG_CONFIG_OBSOLETEQUEUETEMPLATEFILEDELETED       _MESSAGE(33624, _("obsolete queue template file deleted\n"))
#define MSG_CONFIG_FOUNDQUEUETEMPLATEBUTNOTINFILETEMPLATEIGNORINGIT       _MESSAGE(33625, _("found queue 'template', but not in file 'template'; ignoring it!\n"))
#define MSG_CONFIG_CANTRECREATEQEUEUEXFROMDISKBECAUSEOFUNKNOWNHOSTY_SS       _MESSAGE(33626, _("cannot recreate queue %s from disk because of unknown host %s\n"))
#define MSG_CONFIG_CANTWRITEHISTORYFORQUEUEX_S       _MESSAGE(33627, _("can't write history for queue "SFQ"\n"))
#define MSG_CONFIG_READINGINSCHEDULERCONFIG       _MESSAGE(33628, _("Reading in scheduler configuration\n"))
#define MSG_CONFIG_READINGINUSERS       _MESSAGE(33629, _("Reading in users:\n"))
#define MSG_CONFIG_READINGINPROJECTS       _MESSAGE(33630, _("Reading in projects:\n"))
#define MSG_CONFIG_CANTLOADSHARETREEXSTARTINGUPWITHEMPTYSHARETREE_S       _MESSAGE(33631, _("cant load sharetree (%s), starting up with empty sharetree"))
#define MSG_CONFIG_READINGINEXECUTIONHOSTS       _MESSAGE(33632, _("Reading in execution hosts.\n"))
#define MSG_CONFIG_CANTWRITEHISTORYFORHOSTX_S       _MESSAGE(33634, _("cannot write history for host "SFQ"\n"))
#define MSG_CONFIG_READINGINADMINHOSTS       _MESSAGE(33635, _("Reading in administrative hosts.\n"))
#define MSG_CONFIG_READINGINSUBMITHOSTS       _MESSAGE(33636, _("Reading in submit hosts.\n"))
#define MSG_CONFIG_READINGINGPARALLELENV       _MESSAGE(33637, _("Reading in parallel environments:\n"))
#define MSG_CONFIG_READINGUSERMAPPINGENTRY _MESSAGE(33638, _("Reading in user mapping entries:\n"))
#define MSG_CONFIG_READINGHOSTGROUPENTRYS  _MESSAGE(33639, _("Reading in host group entries:\n"))
#define MSG_CONFIG_READINGINCALENDARS       _MESSAGE(33640, _("Reading in calendars:\n"))
#define MSG_CONFIG_READINGINCOMPLEXES       _MESSAGE(33641, _("Reading in complexes:\n"))
#define MSG_CONFIG_FAILEDPARSINGYEARENTRYINCALENDAR_SS       _MESSAGE(33642, _("failed parsing year entry in calendar "SFQ": %s\n"))
#define MSG_CONFIG_READINGINCKPTINTERFACEDEFINITIONS       _MESSAGE(33644, _("Reading in ckpt interface definitions:\n"))
#define MSG_CONFIG_CANTFINDQUEUEXREFERENCEDINJOBY_SU       _MESSAGE(33645, _("can't find queue "SFQ" referenced in job "U32CFormat))
#define MSG_CONFIG_FAILEDREMOVINGSCRIPT_SS       _MESSAGE(33648, _("failed removing script of bad jobfile (reason: %s): please delete "SFQ" manually\n"))
#define MSG_CONFIG_REMOVEDSCRIPTOFBADJOBFILEX_S       _MESSAGE(33649, _("removed script of bad jobfile "SFQ"\n"))
#define MSG_CONFIG_READINGINX_S       _MESSAGE(33650, _("Reading in %s.\n"))
#define MSG_CONFIG_CANTFINDSCRIPTFILE_U       _MESSAGE(33651, _("can't find script file for job " U32CFormat " - deleting\n"))
#define MSG_CONFIG_JOBFILEXHASWRONGFILENAMEDELETING_U       _MESSAGE(33652, _("job file \""U32CFormat"\" has wrong file name - deleting\n"))
#define MSG_CONFIG_NODIRECTORY_S                              _MESSAGE(33653, _(SFQ" is no directory - skipping the entry\n"))


/*
** subordinate_qmaster.c
*/
#define MSG_JOB_SOSUSINGGDILFORJOBXCANTFINDREFERENCEQUEUEY_US       _MESSAGE(33654, _("sos_using_gdil for job "U32CFormat": can't find referenced queue "SFQ))
#define MSG_JOB_USOSUSINGGDILFORJOBXCANTFINDREFERENCEQUEUEY_US       _MESSAGE(33655, _("usos_using_gdil for job "U32CFormat": can't find referenced queue "SFQ))
#define MSG_SGETEXT_SUBITSELF_S                 _MESSAGE(33656, _("queue "SFQ" can't get subordinated by itself\n"))
#define MSG_SGETEXT_UNKNOWNSUB_SS               _MESSAGE(33657, _("subordinated queue "SFQ" referenced in queue "SFQ" does not exist\n"))
#define MSG_SGETEXT_SUBTHRESHOLD_EXCEEDS_SLOTS_SUSU   _MESSAGE(33658, _("queue "SFQ": threshold of "U32CFormat" for subordinated " "queue "SFQ" exceeds job slots of "U32CFormat"\n"))
#define MSG_SGETEXT_SUBHOSTDIFF_SSS                   _MESSAGE(33659, _("queue "SFQ": subordinated queue "SFQ" resides on other host "SFQ"\n"))


/*
** time_event.c
*/
#define MSG_SYSTEM_SYSTEMHASBEENMODIFIEDXSECONDS_I       _MESSAGE(33660, _("system time has been modified (%d seconds)\n"))
#define MSG_SYSTEM_RECEIVEDUNKNOWNEVENT       _MESSAGE(33661, _("received unkown event\n"))


/* sge_user_mapping.c */
#define MSG_UMAP_ADDEDENTRY_S                      _MESSAGE(33662, _("added mapping entry '%s'\n"))
#define MSG_UMAP_EXAMINEMAPENTRY_S                 _MESSAGE(33663, _("examine mapping entry '%s'\n"))
#define MSG_UMAP_EXAMINEHOSTLISTFORMAPNAME_S       _MESSAGE(33664, _("examine hostlist for user mapping name '%s'\n"))
#define MSG_UMAP_CANTADDHOSTX_S                    _MESSAGE(33665, _("can't add host or group '%s'\n"))
#define MSG_UMAP_XADDED_S                          _MESSAGE(33666, _("host or group '%s' added\n"))
#define MSG_UMAP_REMOVEDMAPENTRYXFORCLUSERUSERY_SS      _MESSAGE(33667, _("removed mapping entry '%s' for cluster user '%s'\n"))
#define MSG_UMAP_REMOVEDXFROMMAPENTRYYFORCLUSERUSERZ_SSS      _MESSAGE(33668, _("removed '%s' from mapping entry '%s' for cluster user '%s'\n"))
#define MSG_UMAP_HOSTNAMEXNOTRESOLVEDY_SS          _MESSAGE(33669, _("hostname '%s' not resolved: %s\n"))
#define MSG_QMASTER_XNOVALIDSSM_S                  _MESSAGE(33670, _(SFQ" is not a valid shell_start_mode\n"))
#define MSG_QMASTER_XNOVALIDIS_S                   _MESSAGE(33671, _(SFQ" is not a valid initial_state\n"))
#define MSG_QMASTER_AUTODEFDEPARTMENT              _MESSAGE(33672, _("all users are assigned to the \"defaultdepartment\" automatically\n"))
#define MSG_QMASTER_DEPTFORDEFDEPARTMENT           _MESSAGE(33673, _("the \"defaultdepartment\" has to be of type \"DEPT\"\n"))
#define MSG_QMASTER_ACLNOSHARE                     _MESSAGE(33674, _("not allowed to set \"fshare\" for ACL lists\n"))
#define MSG_QMASTER_ACLNOTICKET                    _MESSAGE(33675, _("not allowed to set \"oticket\" for ACL lists\n"))

/*--*/
#define MSG_COM_NONOTIFICATION_SNE_S                 _MESSAGE(33680, _("failed sending shutdown notification to exec host %s\n"))
#define MSG_COM_NONOTIFICATION_SKE_S                 _MESSAGE(33681, _("failed sending shutdown and kill notification to exec host %s\n"))
#define MSG_COM_NONOTIFICATION_SNU_S                 _MESSAGE(33682, _("failed sending shutdown notification to unknown exec host %s\n"))
#define MSG_COM_NONOTIFICATION_SKU_S                 _MESSAGE(33683, _("failed sending shutdown and kill notification to unknown exec host %s\n"))
#define MSG_COM_NOTIFICATION_SNE_S                   _MESSAGE(33684, _("sent shutdown notification to exec host %s\n"))
#define MSG_COM_NOTIFICATION_SKE_S                   _MESSAGE(33685, _("sent shutdown and kill notification to exec host %s\n"))
#define MSG_COM_NOTIFICATION_SNU_S                   _MESSAGE(33686, _("sent shutdown notification to unknown exec host %s\n"))
#define MSG_COM_NOTIFICATION_SKU_S                   _MESSAGE(33687, _("sent shutdown and kill notification to unknown exec host %s\n"))
#define MSG_SGETEXT_CANT_DELETE_USER_IN_SHARE_TREE_S _MESSAGE(33688, _("denied: may not remove user "SFQ" still referenced in sharetree\n"))
#define MSG_SGETEXT_CANT_DELETE_PRJ_IN_SHARE_TREE_S  _MESSAGE(33689, _("denied: may not remove project "SFQ" still referenced in sharetree\n")) 
#define MSG_SGETEXT_COMPLEXSTILLREFERENCED_INQ_SS    _MESSAGE(33690, _("denied: complex "SFQ" is still referenced in complex_list of queue "SFQ"\n"))
#define MSG_SGETEXT_COMPLEXSTILLREFERENCED_INH_SS    _MESSAGE(33691, _("denied: complex "SFQ" is still referenced in complex_list of exechost "SFQ"\n"))
#define MSG_SGETEXT_MANAGER_ALREADYEXISTS_S          _MESSAGE(33692, _("manager "SFQ" already exists\n"))
#define MSG_SGETEXT_OPERATOR_ALREADYEXISTS_S         _MESSAGE(33693, _("operator "SFQ" already exists\n"))
#define MSG_SGETEXT_MANAGER_ADDEDTOLIST_SSS          _MESSAGE(33694, _(""SFN"@"SFN" added "SFQ" to manager list\n"))
#define MSG_SGETEXT_OPERATOR_ADDEDTOLIST_SSS         _MESSAGE(33695, _(""SFN"@"SFN" added "SFQ" to operator list\n"))
#define MSG_SGETEXT_CONFIG_ADDEDTOLIST_SSS           _MESSAGE(33696, _(""SFN"@"SFN" added "SFQ" to configuration list\n"))
#define MSG_SGETEXT_CONFIG_MODIFIEDINLIST_SSS        _MESSAGE(33697, _(""SFN"@"SFN" modified "SFQ" in configuration list\n"))
#define MSG_SGETEXT_SCHEDULER_MODIFIEDINLIST_SS      _MESSAGE(33698, _(""SFN"@"SFN" modified scheduler configuration\n"))
#define MSG_CKPTREFINJOB_SU                          _MESSAGE(33699, _("Checkpointing object "SFQ" is still referenced in job " U32CFormat".\n"))
#define MSG_PEREFINJOB_SU                            _MESSAGE(33700, _("Pe "SFQ" is still referenced in job "U32CFormat".\n"))

/* 
 * qmaster/sge_job.c
 */
#define MSG_QMASTER_TIGHTLYINTEGRATEDARRAYJOB   _MESSAGE(33701, _("Cannot submit tightly integrated parallel array job. Please use loose integration or non array jobs.\n"))

#endif /* __MSG_QMASTER_H */
