#!/vol2/TCL_TK/glinux/bin/tclsh
# expect script 
#___INFO__MARK_BEGIN__
##########################################################################
#
#  The Contents of this file are made available subject to the terms of
#  the Sun Industry Standards Source License Version 1.2
#
#  Sun Microsystems Inc., March, 2001
#
#
#  Sun Industry Standards Source License Version 1.2
#  =================================================
#  The contents of this file are subject to the Sun Industry Standards
#  Source License Version 1.2 (the "License"); You may not use this file
#  except in compliance with the License. You may obtain a copy of the
#  License at http://gridengine.sunsource.net/Gridengine_SISSL_license.html
#
#  Software provided under this License is provided on an "AS IS" basis,
#  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
#  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
#  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
#  See the License for the specific provisions governing your rights and
#  obligations concerning the Software.
#
#  The Initial Developer of the Original Code is: Sun Microsystems, Inc.
#
#  Copyright: 2001 by Sun Microsystems, Inc.
#
#  All Rights Reserved.
#
##########################################################################
#___INFO__MARK_END__

global module_name
global rlogin_spawn_session_buffer
set module_name "remote_procedures.tcl"
global rlogin_max_open_connections
set rlogin_max_open_connections 20

set descriptors [exec "/bin/sh" "-c" "ulimit -n"]
puts "    *********************************************"
puts "    * CONNECTION SETUP (remote_procedures.tcl)"
puts "    *********************************************"
puts "    * descriptors = $descriptors"
set rlogin_max_open_connections [expr ($descriptors - 9) / 3]
puts "    * rlogin_max_open_connections = $rlogin_max_open_connections"
puts "    *********************************************"

# procedures
#                                                             max. column:     |
#****** remote_procedures/test() ******
# 
#  NAME
#     test -- ??? 
#
#  SYNOPSIS
#     test { m p } 
#
#  FUNCTION
#     ??? 
#
#  INPUTS
#     m - ??? 
#     p - ??? 
#
#  RESULT
#     ??? 
#
#  EXAMPLE
#     ??? 
#
#  NOTES
#     ??? 
#
#  BUGS
#     ??? 
#
#  SEE ALSO
#     ???/???
#*******************************
proc test {m p} {
   puts "test $m $p"
}


#                                                             max. column:     |
#****** remote_procedures/start_remote_tcl_prog() ******
# 
#  NAME
#     start_remote_tcl_prog -- ??? 
#
#  SYNOPSIS
#     start_remote_tcl_prog { host user tcl_file tcl_procedure tcl_procargs } 
#
#  FUNCTION
#     ??? 
#
#  INPUTS
#     host          - ??? 
#     user          - ??? 
#     tcl_file      - ??? 
#     tcl_procedure - ??? 
#     tcl_procargs  - ??? 
#
#  RESULT
#     ??? 
#
#  EXAMPLE
#     ??? 
#
#  NOTES
#     ??? 
#
#  BUGS
#     ??? 
#
#  SEE ALSO
#     ???/???
#*******************************
proc start_remote_tcl_prog { host user tcl_file tcl_procedure tcl_procargs} {
  
   global CHECK_TESTSUITE_ROOT CHECK_SCRIPT_FILE_DIR CHECK_TCL_SCRIPTFILE_DIR CHECK_DEFAULTS_FILE
   global CHECK_OUTPUT CHECK_DEBUG_LEVEL
 
   set tcl_bin [ get_binary_path $host "expect"]
   set tcl_prog "$CHECK_TESTSUITE_ROOT/$CHECK_SCRIPT_FILE_DIR/remote_tcl_command.sh"
   set tcl_testhome "$CHECK_TESTSUITE_ROOT"
   set tcl_defaults  "$CHECK_DEFAULTS_FILE"
   
   set debug_arg ""
   if { $CHECK_DEBUG_LEVEL != 0 } {
      set debug_arg "debug"
   }
   set remote_args "$tcl_bin $CHECK_TESTSUITE_ROOT/$CHECK_TCL_SCRIPTFILE_DIR/$tcl_file $tcl_testhome $tcl_procedure \"$tcl_procargs\" $tcl_defaults $debug_arg"

   set result ""
   debug_puts "prog: $tcl_prog"
   debug_puts "remote_args: $remote_args"
   set result [ start_remote_prog "$host" "$user" "$tcl_prog" "$remote_args" prg_exit_state 300 ]
   if { [string first "Error in procedure" $result] >= 0 } {
      add_proc_error "start_remote_tcl_prog" -2 "error in $tcl_file, proc $tcl_procedure $tcl_procargs"
   }
   return $result
}




#                                                             max. column:     |
#
#****** remote_procedures/start_remote_prog() ******
#  NAME
#     start_remote_prog() -- ??? 
#
#  SYNOPSIS
#     start_remote_prog { hostname user exec_command exec_arguments 
#     {exit_var prg_exit_state} {mytimeout 60} {background 0} {envlist ""}} 
#
#  FUNCTION
#     ??? 
#
#  INPUTS
#     hostname                  - ??? 
#     user                      - ??? 
#     exec_command              - ??? 
#     exec_arguments            - ??? 
#     {exit_var prg_exit_state} - ??? 
#     {mytimeout 60}            - ??? 
#     {background 0}            - if not 0 -> start remote prog in background
#     {envlist}                 - array with environment settings to export
#
#  RESULT
#     program output
#
#  EXAMPLE
#     set envlist(COLUMNS) 500
#     start_remote_prog "ahost" "auser" "ls" "-la" "prg_exit_state" "60" "0" "envlist"
#
#  NOTES
#     ??? 
#
#  BUGS
#     ??? 
#
#  SEE ALSO
#     ???/???
#*******************************
#
proc start_remote_prog { hostname user exec_command exec_arguments {exit_var prg_exit_state} {mytimeout 60} {background 0} {envlist ""} } {
   global CHECK_OUTPUT CHECK_MAIN_RESULTS_DIR CHECK_DEBUG_LEVEL 
   global open_spawn_buffer 
   upvar $exit_var back_exit_state
   upvar $envlist users_env
   
   set back_exit_state -1

   if { [ llength $exec_command ] != 1 } {
      puts "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ="
      puts "  WARNING     WARNING   WARNING  WARNING"
      puts "  procedure start_remote_prog: \"$exec_command\""
      puts "  is not a command name; it has additional arguments" 
      puts "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ="
     if { $CHECK_DEBUG_LEVEL == 2 } {
         wait_for_enter 
     }
   }

#   puts [array names users_env]
   set id [open_remote_spawn_process "$hostname" "$user" "$exec_command" "$exec_arguments" $background users_env]
   if { [string compare $id ""] == 0 } {
      add_proc_error "start_remote_prog" -1 "got no spawn id"
      return ""
   }
   set myspawn_id [ lindex $id 1 ]


   debug_puts "my SPAWN ID is: $myspawn_id"
   set output ""
   set exit_status ""
   set do_stop 0
   log_user 0
   if { $CHECK_DEBUG_LEVEL != 0 } {
      log_user 1
   }
   set timeout $mytimeout
   set real_end_found 0
   set real_start_found 0
   set nr_of_lines 0
   
 
   debug_puts "real buffer size is: [match_max -i $myspawn_id]"
 
   debug_puts "expecting on id: $myspawn_id"
   while { $do_stop == 0 } {
      expect {
        -i $myspawn_id full_buffer {
           add_proc_error "start_remote_prog" "-1" "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
           set do_stop 1 
        }
        -i $myspawn_id "\n" {
           set buffer $expect_out(buffer)
           if { $real_start_found == 1 } {
              append output $buffer
              incr nr_of_lines 1
#              puts $CHECK_OUTPUT "output has now $nr_of_lines lines."
              if { $background == 1 } { 
                 set do_stop 1
              }
           }
           
#           set help_buffer [split $buffer "\r" ]
#           set help_buffer [join $help_buffer "/r"] 
#           set help_buffer [split $help_buffer "\n" ]
#           set help_buffer [join $help_buffer "/n"] 

#           set help_buffer [string replace $help_buffer end end ]
#           set help_buffer "$help_buffer\\r\\n"
           if { $CHECK_DEBUG_LEVEL != 0 } {
              puts $CHECK_OUTPUT ""
           }
#           puts $CHECK_OUTPUT "--> string is \"${help_buffer}\""

           if { [ string first "_start_mark_:" $buffer ] >= 0 } {
               if { [ string first "?" $buffer ] < 0 } {
                  set real_start_found 1
                  set output "_start_mark_\n"
                  debug_puts "found programm output start"
               }
           }           
           if { [ string first "_exit_status_:" $buffer ] >= 0 } {
               if { [ string first "?" $buffer ] < 0 } {
                  set do_stop 1
                  set exit_status $buffer 
                  set real_end_found 1
                  debug_puts "found programm output end"
               }
           }

           if { [ string first "connection closed" $buffer ] == 0 } {
               set do_stop 1
               puts $CHECK_OUTPUT "found connection closed message, as programm output end"
           }
        }

        -i $myspawn_id timeout { 
           set do_stop 1 
           add_proc_error "start_remote_prog" "-1" "timeout error:\n$expect_out(0,string)"
        }

        -i $myspawn_id eof { 
           set do_stop 1 
        }

        -i $myspawn_id default {
           set do_stop 1 
           add_proc_error "start_remote_prog" "-1" "unexpected error - default expect case is stop"
        }
      }
      flush $CHECK_OUTPUT
   }
   flush $CHECK_OUTPUT 
   close_spawn_process $id


   log_user 1
   # parse output: cut leading sequence 
   set help_str [ split $output "\n" ]
   set index 0
   set found_end 0
   foreach elem $help_str {
      if { [string first "_start_mark_" $elem ] >= 0 } {
         set found_end $index
      }
      incr index 1
   }
   set output [lreplace $help_str 0 $found_end ]
 
   # parse output: search exit status
   if {$real_end_found == 1} {
      set index 0 
      set found_end 0
      foreach elem $output {
        if { [string first "_exit_status_:" $elem ] >= 0 } {
           set exit_status $elem
           set found_end $index
        }
        incr index 1
      }
      set output [lreplace $output $found_end $index ]
   }
   
   set output [ join $output "\n"]
   if {$real_end_found == 1} {
      # get exit status from exit status line

      set first_index [string first "(" $exit_status ]
      set first_index [ expr ( $first_index + 1 ) ]
      set last_index [string first ")" $exit_status ]
      set last_index [ expr ( $last_index - 1 ) ]
      set exit_status [string range $exit_status $first_index $last_index]
   } else {
      set exit_status -1
   }
   debug_puts "E X I T   S T A T E   of remote prog: $exit_status"
   if { $exit_status != 0 } {
      puts $CHECK_OUTPUT "--> exit_state is \"$exit_status\""
   }
    
   if { $CHECK_DEBUG_LEVEL == 2 } {
      wait_for_enter
   }

   set back_exit_state $exit_status
   return $output
}

#                                                             max. column:     |
#****** remote_procedures/open_remote_spawn_process() ******
# 
#  NAME
#     open_remote_spawn_process -- ??? 
#
#  SYNOPSIS
#     open_remote_spawn_process { hostname user exec_command exec_arguments { background 0 } } 
#
#  FUNCTION
#     ??? 
#
#  INPUTS
#     hostname         - ??? 
#     user             - ??? 
#     exec_command     - ??? 
#     exec_arguments   - ??? 
#     { background 0 } - if not 0 -> start command with "&" in background 
#                        if 2 -> wait 30 seconds after starting background process
#
#  RESULT
#     ??? 
#
#  EXAMPLE
#     set id [open_remote_spawn_process "boromir" "testuser" "ls" "-la"]
#     set do_stop 0
#     set output ""
#     set sp_id [lindex $id 1]
#     while { $do_stop == 0 } {
#        expect {
#           -i $sp_id full_buffer {     ;# input buffer default size is 2000 byte 
#              set do_stop 1
#              puts "error - buffer overflow" 
#           } 
#           -i $sp_id timeout { set do_stop 1 }
#           -i $sp_id eof { set do_stop 1 }
#           -i $sp_id "*\r" {
#              set output "$output$expect_out(0,string)"
#           }
#        }
#     }  
#     close_spawn_process $id
#     puts $CHECK_OUTPUT ">>> output start <<<"
#     puts $CHECK_OUTPUT $output
#     puts $CHECK_OUTPUT ">>> output end <<<"
#
#  NOTES
#     ??? 
#
#  BUGS
#     ??? 
#
#  SEE ALSO
#     ???/???
#*******************************
proc open_remote_spawn_process { hostname user exec_command exec_arguments { background 0 } {envlist ""} } {

  global open_spawn_buffer CHECK_OUTPUT CHECK_USER CHECK_TESTSUITE_ROOT CHECK_SCRIPT_FILE_DIR
  global CHECK_MAIN_RESULTS_DIR CHECK_EXPECT_MATCH_MAX_BUFFER

  upvar $envlist users_env


  uplevel 1 { set remote_spawn_nr_of_shells 0 }

  uplevel 1 { global open_spawn_buffer }
  uplevel 1 { global CHECK_USER }
  uplevel 1 { global CHECK_TESTSUITE_ROOT }
  uplevel 1 { global CHECK_SCRIPT_FILE_DIR }
  uplevel 1 { global CHECK_MAIN_RESULTS_DIR }
  uplevel 1 { global CHECK_DEBUG_LEVEL }
  uplevel 1 { global CHECK_EXPECT_MATCH_MAX_BUFFER }
  uplevel 1 { global CHECK_OUTPUT }


  debug_puts "open_remote_spawn_process on host \"$hostname\""
  debug_puts "user:           $user"
  debug_puts "exec_command:   $exec_command"
  debug_puts "exec_arguments: $exec_arguments"

  if { [string compare $user $CHECK_USER] != 0 } {
      if {[have_root_passwd] == -1} {
         add_proc_error "open_remote_spawn_process" -2 "root access required"
         return "" 
      }
  }
  set type [ file tail $exec_command ]
  if { [ file isdirectory $CHECK_MAIN_RESULTS_DIR ] != 1 } {
     set script_name "/tmp/temp_${hostname}_${type}_[timestamp].sh"
  } else {
     set script_name "$CHECK_MAIN_RESULTS_DIR/temp_${hostname}_${type}_[timestamp].sh"
  }
  create_shell_script "$script_name" "$exec_command" "$exec_arguments" users_env
 
  set open_spawn_buffer $script_name
  uplevel 1 { set open_remote_spawn__script_name $open_spawn_buffer }
 
  set open_spawn_buffer $hostname
  uplevel 1 { set open_remote_spawn__hostname $open_spawn_buffer }
  
  set open_spawn_buffer $user
  uplevel 1 { set open_remote_spawn__user $open_spawn_buffer }

  set open_spawn_buffer $CHECK_USER
  uplevel 1 { set open_remote_spawn__check_user $open_spawn_buffer }

  set open_spawn_buffer $exec_command
  uplevel 1 { set open_remote_spawn__prog "$open_spawn_buffer" }
   
  set open_spawn_buffer $exec_arguments
  uplevel 1 { set open_remote_spawn__args "$open_spawn_buffer" }

  

  uplevel 1 { 
     log_user 0
     if { $CHECK_DEBUG_LEVEL != 0 } {
        log_user 1
     }
  }

  uplevel 1 { set timeout 120 }
  get_open_spawn_rlogin_session $hostname $user con_data
  if { $con_data(pid) != 0 } {
     debug_puts "Using open rlogin connection to host \"$hostname\",user \"$user\"" 
     set nr_of_shells $con_data(nr_shells)
     set back  $con_data(pid) 
     lappend back $con_data(spawn_id)
     set open_spawn_buffer $con_data(spawn_id)
     uplevel 1 { 
        set open_remote_spawn__id "$open_spawn_buffer" 
     }
  } else { 
     uplevel 1 { puts $CHECK_OUTPUT "opening connection to host $open_remote_spawn__hostname" }
     if { [have_ssh_access] == 0 } {
        set pid [ uplevel 1 { spawn "rlogin" "$open_remote_spawn__hostname" } ] 
        uplevel 1 { incr remote_spawn_nr_of_shells 1 }
      } else {
        set pid [ uplevel 1 { spawn "ssh" "-l" "root" "$open_remote_spawn__hostname" } ]
        uplevel 1 { incr remote_spawn_nr_of_shells 1 }
      }
      set sp_id [uplevel 1 { set spawn_id }]
      set back $pid      ;# return value (pid and spawn_id)
      lappend back $sp_id
      set open_spawn_buffer $sp_id
      uplevel 1 { set open_remote_spawn__id "$open_spawn_buffer" }

      if {$pid == 0 } {
        add_proc_error "open_remote_spawn_process" -2 "could not spawn! (ret_pid = $pid)" 
      }
      match_max -i $sp_id $CHECK_EXPECT_MATCH_MAX_BUFFER
      debug_puts "open_remote_spawn_process -> buffer size is: [match_max]"
       # wait for shell to start
      catch {
          uplevel 1 {
             log_user 0
             if { $CHECK_DEBUG_LEVEL != 0 } {
                log_user 1
             }
             set my_tries 30
             while { 1 } {
                set timeout 1
                expect {
                   -i $spawn_id full_buffer {
                      add_proc_error "open_remote_spawn_process" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
                      break
                   }
                   -i $spawn_id "*" {
                       debug_puts "startup ..."
                       break;
                   }
                   -i $spawn_id default {
                       if { $my_tries > 0 } {
                           incr my_tries -1
                           puts -nonewline $CHECK_OUTPUT "."
                           flush $CHECK_OUTPUT
                           continue
                       } else { 
                          add_proc_error "open_remote_spawn_process" -1 "startup timeout" 
                          break
                       }
                   }
                }
             }
   
             set mytries 60
             debug_puts "waiting for shell response ..."
             set timeout 1
             set ok 0
             # send -i $spawn_id "\necho \"__ my id is ->\`id\`<-\"\n\n"  (caused problems on some arch's)
             while { $ok != 1 } {
                expect {
                   -i $spawn_id full_buffer {
                      add_proc_error "open_remote_spawn_process" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
                      set ok 1
                   }
                   -i $spawn_id timeout {
                      puts -nonewline $CHECK_OUTPUT "              \r$mytries\r"
                      
                      flush $CHECK_OUTPUT
                      send -i $spawn_id -- "\necho \"__ my id is ->\`id\`<-\"\n\n"
                      set timeout 3
                      incr mytries -1 ; 
                      if  { $mytries < 0 } { 
                          set ok 1
                          add_proc_error "open_remote_spawn_process" -2 "shell doesn't start or runs not as user $open_remote_spawn__check_user on host $open_remote_spawn__hostname" 
                      }
                   }
                   -i $spawn_id -- "__ my id is ->*${open_remote_spawn__check_user}*<-" { 
                       debug_puts "shell response! - fine" 
                       set ok 1
                       send -i $spawn_id "\n"
                       debug_puts "sending new line"
                   }
                   -i $spawn_id -- "__ my id is ->*root*<-" { 
                       debug_puts "shell response! - fine" 
                       set ok 1
                       send -i $spawn_id "\n"
                       debug_puts "sending new line"
                   }
   
                }
             }
             set timeout 60
             log_user 1
         }
      }
      catch {
         uplevel 1 {
            set open_remote_spawn__stop 0
            log_user 0
            if { $CHECK_DEBUG_LEVEL != 0 } {
              log_user 1
            }
            set timeout 60 
            while { $open_remote_spawn__stop == 0 } {
               expect {
                  -i $spawn_id full_buffer {
                     set open_remote_spawn__stop -1
                     add_proc_error "open_remote_spawn_process" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
                  }
                  -i $spawn_id timeout {
                     set open_remote_spawn__stop -1
                     add_proc_error "open_remote_spawn_process" -2 "rlogin timeout"
                  } 
                  -i $spawn_id -- "ermission denied" {
                        set open_remote_spawn__stop -1
                        add_proc_error "open_remote_spawn_process" -2 "permission denied"
                  }
                  -i $spawn_id -- "\n" {
                        debug_puts "login sequence for user $CHECK_USER ..."
                        if { ([string compare $open_remote_spawn__user $CHECK_USER ] != 0) && 
                             ([have_ssh_access] == 0) } {
                              if { [string compare $open_remote_spawn__user "root" ] != 0 } {
                                 debug_puts "switch to root become $open_remote_spawn__user"
                                 send -i $spawn_id "su root -c 'su - $open_remote_spawn__user'\n" 
                                 incr remote_spawn_nr_of_shells 1   ;# this shell ist closed with 1 exit call!!!
                              } else {
                                 debug_puts "switch to root"
                                 send -i $spawn_id "su root\n"
                                 incr remote_spawn_nr_of_shells 1 
                              }
                        }
                        if { ([string compare $open_remote_spawn__user $CHECK_USER ] == 0) && 
                             ([have_ssh_access] == 0) } {
                             send -i $spawn_id "\n"
                             debug_puts "sending new line"
                        }
                        
                        if { [have_ssh_access] != 0 } {
                             send -i $spawn_id "su - $open_remote_spawn__user\n"
                             incr remote_spawn_nr_of_shells 1 
                             debug_puts "switching to user $open_remote_spawn__user (with env)"
                        } 
                        set open_remote_spawn__stop 1
                  }
                  -i $spawn_id eof {
                     set open_remote_spawn__stop -1
                     add_proc_error "open_remote_spawn_process" -2 "unexpected eof on rlogin command"
                  }
               }
            }
            log_user 1
         }
      }
   
   
      catch {
         if { ([string compare $user $CHECK_USER ] != 0) && ([have_ssh_access] == 0) } {
            uplevel 1 { 
               log_user 0
               if { $CHECK_DEBUG_LEVEL != 0 } {
                 log_user 1
               }
               expect {
                  -i $spawn_id full_buffer {
                     add_proc_error "open_remote_spawn_process" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
                  }
                  -i $spawn_id timeout {
                     add_proc_error "open_remote_spawn_process" -2 "timeout waiting for password question"
                  }  
                  -i $spawn_id -- "ermission denied" {
                     add_proc_error "open_remote_spawn_process" -2 "permission denied error"
                  }
                  -i $spawn_id -- "assword:" {
                     log_user 0
                     sleep 4 
                     set send_slow "1 .1"
                     send -i $spawn_id -s "[get_root_passwd]\n"
                     debug_puts "root password sent" 
                     if { $CHECK_DEBUG_LEVEL != 0 } {
                        log_user 1
                     }
                  }
                  -i $spawn_id eof {
                     add_proc_error "open_remote_spawn_process" -2 "unexpected eof on rlogin command"
                  }
               }
               log_user 1
            }
         }
      }
      set nr_of_shells [ uplevel 1 { set remote_spawn_nr_of_shells  } ]
      add_open_spawn_rlogin_session $hostname $user $sp_id $pid $nr_of_shells

   }
   uplevel 1 { 
      log_user 0
      if { $CHECK_DEBUG_LEVEL != 0 } {
        log_user 1
      }
      set timeout 1
      send -i $open_remote_spawn__id "ls -la $open_remote_spawn__script_name ; echo \">>\"\$?\"<<\"\n"
      set open_remote_spawn__tries 70
      while { $open_remote_spawn__tries > 0 } {
         expect {
            -i $open_remote_spawn__id full_buffer {
               add_proc_error "open_remote_spawn_process" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
               break
            }
            -i $open_remote_spawn__id timeout {
                send -i $open_remote_spawn__id "ls -la $open_remote_spawn__script_name ; echo \">>\"\$?\"<<\"\n"
                incr open_remote_spawn__tries -1
            }  
            -i $open_remote_spawn__id ">>0<<" {
               debug_puts "file $open_remote_spawn__script_name exists"
               break
            }
            -i $open_remote_spawn__id eof {
               add_proc_error "open_remote_spawn_process" -2 "unexpected eof"
               break
            }
         }
      }
      if { $open_remote_spawn__tries <= 0 } {
          add_proc_error "open_remote_spawn_process" -1 "timeout waiting for ls command"
      }
      log_user 1
   }

   puts $CHECK_OUTPUT "starting command \"$exec_command\" as user \"$user\" on host \"$hostname\" now ..."

   if { $background != 0 } {
      uplevel 1 { append open_remote_spawn__script_name " &" }
   }
   
      


   uplevel 1 { 
      log_user 0
      if { $CHECK_DEBUG_LEVEL != 0 } {
         log_user 1
      }
      debug_puts "starting \"$open_remote_spawn__script_name\""
   }
#   if {$con_data(pid) == 0 }  {
#      uplevel 1 { 
#         send -i $open_remote_spawn__id "unset correct\n"
#         wait_for_enter
#      }
#   }
   uplevel 1 { 
      send -i $open_remote_spawn__id "unset correct\n"
      send -i $open_remote_spawn__id "$open_remote_spawn__script_name\n"
      log_user 1
   }

   if { $background == 2 } {
    
      set back_time 15 ;# let background process time to do his initialization
      while { $back_time > 0 } {
         puts -nonewline $CHECK_OUTPUT "."
         flush $CHECK_OUTPUT
         sleep 1
         incr back_time -1
      }
      puts $CHECK_OUTPUT "hope background process is initalized now!"
   }


   delete_file_at_startup $script_name

   debug_puts "number of open shells: $nr_of_shells"
   lappend back $nr_of_shells

   return $back
}

#                                                             max. column:     |
#****** remote_procedures/open_root_spawn_process() ******
# 
#  NAME
#     open_root_spawn_process -- starrrt process as root with spawn command
#
#  SYNOPSIS
#     open_root_spawn_process { args } 
#
#  FUNCTION
#     Starts process given in "args" as user "root" and returns its spawn id
#     and pid in a list. The root password is sent when the su command is 
#     asking for the root password.
#     The first list element is the pid and the second is the spawn id. The 
#     return value is used in close_spawn_process to close the connection to
#     this process.
#
#  INPUTS
#     args - full argument list of the process to start
#
#  RESULT
#     tcl list with id and pid of the process
#
#     - first element is the pid
#     - second element is the spawn id
#
#  EXAMPLE
#     set id [ 
#       open_spawn_process "id"
#     ]
#     set timeout 60
#     expect {
#       timeout { puts "timeout" }  
#       "root" { puts "we have root access" }
#     }
#     puts "pid: [ lindex $id 0]"
#     puts "spawn id: [ lindex $id 1]"
#     close_spawn_process $id
#     
#  SEE ALSO
#     remote_procedures/open_spawn_process
#     remote_procedures/open_root_spawn_process
#     remote_procedures/close_spawn_process
#     remote_procedures/run_command_as_user
#     remote_procedures/start_remote_tcl_prog
#     remote_procedures/start_remote_prog
#*******************************
# proc open_root_spawn_process {args} {
# 
#    global CHECK_OUTPUT open_spawn_buffer CHECK_HOST env CHECK_PRODUCT_ROOT CHECK_TESTSUITE_ROOT
#    global CHECK_COMMD_PORT CHECK_OUTPUT CHECK_SCRIPT_FILE_DIR
#    uplevel 1 { global CHECK_EXPECT_MATCH_MAX_BUFFER  } 
#    uplevel 1 { global CHECK_OUTPUT }
#    uplevel 1 { global CHECK_DEBUG_LEVEL }
# 
#    set arguments ""
#    set arg_nr 0 
#    foreach elem $args {
# 
#       incr arg_nr 1
# 
#       if { $arg_nr == 1 } {
#         set programm "$elem" 
#       }  
#       if { $arg_nr == 2 } {
#         set arguments "$elem"
#       }
#       if { $arg_nr > 2  } {
#         set arguments "$arguments $elem"
#       }
#    }
#    debug_puts "open_root_spawn_process"
#    debug_puts "programm:  \"$programm\""
#    debug_puts "arguments: \"$arguments\""
# 
#    if { [have_root_passwd] == -1 } {
#       set_error -2 "root access required"
#       return "" 
#    }
#    if { $arg_nr == 1 } {
#       set open_spawn_buffer "$programm"
#    } else {
#       set open_spawn_buffer "$programm $arguments"
#    }
#    debug_puts "open_spawn_buffer: $open_spawn_buffer"
# 
#    uplevel 1 { set open_root_spawn_arguments "$open_spawn_buffer" }
#    if { [have_ssh_access] == 0 } {
#      set pid [ uplevel 1 { spawn "su" "root" "-c" "$open_root_spawn_arguments" } ]
#    } else {
#      set pid [ uplevel 1 { spawn "ssh" "-l" "root" "$CHECK_HOST" "$CHECK_TESTSUITE_ROOT/$CHECK_SCRIPT_FILE_DIR/ssh_progstarter.csh \"[get_current_working_dir]\" \"$CHECK_PRODUCT_ROOT\" \"$CHECK_COMMD_PORT\" $open_root_spawn_arguments" } ]
#    }
#    set sp_id [uplevel 1 { set spawn_id }]
# 
#    set back $pid
#    lappend back $sp_id
#    uplevel 1 {
#       match_max -i $spawn_id $CHECK_EXPECT_MATCH_MAX_BUFFER
#       debug_puts "open_root_spawn_process -> buffer size is: [match_max]"
#    }
#    debug_puts "open_root_spawn_process:  arguments: $args"
# 
#    flush $CHECK_OUTPUT
# 
#    if {$pid == 0 } {
#      add_proc_error "open_root_spawn_process" -1 "could not spawn! (ret_pid = $pid)" 
#    }
# 
#    if { [have_ssh_access] == 0 } {
#       uplevel 1 { set timeout 60 }
#       uplevel 1 { expect -i $spawn_id "assword:" }
# 
#       sleep 5  ;# for some architectures it is neccessary to 
#                ;# login in "human keystrock" speed
#       uplevel 1 { 
#         log_user 0
#         sleep 2
#         send "[get_root_passwd]\r" }
#         debug_puts "root password sent" 
#         if { $CHECK_DEBUG_LEVEL != 0 } {
#            log_user 1
#         }
# 
#    }
# 
#    return $back
# }


#                                                             max. column:     |
#****** remote_procedures/open_spawn_process() ******
# 
#  NAME
#     open_spawn_process -- start process with the expect "spawn" command
#
#  SYNOPSIS
#     open_spawn_process { args } 
#
#  FUNCTION
#     Starts process given in "args" and returns its spawn id and pid in a list. 
#     The first list element is the pid and the second is the spawn id. The return 
#     value is used in close_spawn_process to close the connection to this 
#     process.
#
#  INPUTS
#     args - full argument list of the process to start
#
#  RESULT
#     tcl list with id and pid of the process
#
#     - first element is the pid
#     - second element is the spawn id
#
#  EXAMPLE
#     set id [ 
#       open_spawn_process "$CHECK_PRODUCT_ROOT/bin/$CHECK_ARCH/qconf" "-dq" "$q_name"
#     ]
#     expect {
#       ...
#     }
#     puts "pid: [ lindex $id 0]"
#     puts "spawn id: [ lindex $id 1]"
#     close_spawn_process $id
#
#
#  NOTES
#     always close an opened spawn id with the procedure close_spawn_process
#
#  SEE ALSO
#     remote_procedures/open_spawn_process
#     remote_procedures/open_root_spawn_process
#     remote_procedures/close_spawn_process
#     remote_procedures/run_command_as_user
#     remote_procedures/start_remote_tcl_prog
#     remote_procedures/start_remote_prog
#     
#*******************************
proc open_spawn_process {args} {

   global CHECK_OUTPUT open_spawn_buffer env 
   uplevel 1 { global open_spawn_buffer }
   uplevel 1 { global CHECK_EXPECT_MATCH_MAX_BUFFER }
   uplevel 1 { global CHECK_OUTPUT }

   set arguments ""
   set my_arg_no 0

   foreach elem $args {
      incr my_arg_no 1
      if {$my_arg_no == 1} {
        set arguments "$elem"
      } else {
        set arguments "$arguments $elem"
      }
   }
   debug_puts $arguments
   set open_spawn_buffer $arguments
   uplevel 1 { set open_spawn_arguments $open_spawn_buffer } 

   debug_puts "starting spawn process ..."
   flush $CHECK_OUTPUT

   set pid   [ uplevel 1 { eval spawn $open_spawn_arguments } ]
   set sp_id [ uplevel 1 { set spawn_id } ]
   set back $pid
   lappend back $sp_id
   debug_puts "open_spawn_process:  arguments: $args"
   uplevel 1 {
      match_max -i $spawn_id $CHECK_EXPECT_MATCH_MAX_BUFFER
      debug_puts "open_spawn_process -> buffer size is: [match_max]"
   }

   flush $CHECK_OUTPUT

   if {$pid == 0 } {
     add_proc_error "open_spawn_process" -1 "could not spawn! (ret_pid = $pid)" 
   }
   return $back
}


#****** remote_procedures/add_open_spawn_rlogin_session() **********************
#  NAME
#     add_open_spawn_rlogin_session() -- add spawn id to open connection list
#
#  SYNOPSIS
#     add_open_spawn_rlogin_session { hostname user spawn_id pid } 
#
#  FUNCTION
#     This procedure will add the given spawn id to the rlogin spawn open 
#     connection buffer. This buffer contains all open rlogin spawn process
#     ids. 
#
#  INPUTS
#     hostname - hostname of rlogin connection
#     user     - user who logged in
#     spawn_id - spawn process id
#     pid      - process id of rlogin session
#
#  RESULT
#     no return value
#
#  SEE ALSO
#     remote_procedures/add_open_spawn_rlogin_session
#     remote_procedures/get_open_spawn_rlogin_session
#     remote_procedures/get_spawn_id_rlogin_session
#     remote_procedures/check_rlogin_session
#*******************************************************************************
proc add_open_spawn_rlogin_session { hostname user spawn_id spawn_pid nr_of_shells} {
   global CHECK_OUTPUT rlogin_spawn_session_buffer
   global do_close_rlogin rlogin_max_open_connections 
   

   if { $do_close_rlogin != 0 } {
      debug_puts "close_rlogin argument set, closing rlogin connections after use"
      return  
   }

   set entries [array names rlogin_spawn_session_buffer]

   if { [llength $entries] >= $rlogin_max_open_connections } {
      debug_puts "number of open connections > rlogin_max_open_connections = $rlogin_max_open_connections"
      puts $CHECK_OUTPUT "removing oldest not used rlogin session (rlogin_max_open_connections overflow)"
      set now [timestamp]
      set remove_sp_id ""
      set remove_pid   "" 
      set closes       ""
      foreach sp_id $entries {
         set data [split $rlogin_spawn_session_buffer($sp_id) ";"]
         set time [ lindex $data 3 ]  
         set pid  [ lindex $data 1 ]
         if { $now > $time } {
            set now $time
            set remove_pid $pid
            set remove_sp_id $sp_id
            set closes [ lindex $data 4 ]

         } 
         debug_puts $time,$sp_id,$pid,$closes
      }
      debug_puts "longest not used element: $remove_sp_id, $remove_pid" 

      set cl_id $remove_pid
      lappend cl_id $remove_sp_id
      lappend cl_id $closes       ;# nr of open shells
      unset rlogin_spawn_session_buffer($remove_sp_id)
      close_spawn_process $cl_id 0 2
   }

   debug_puts "Adding spawn_id=$spawn_id, rlogin pid=$spawn_pid to"
   debug_puts "host=$hostname, user=$user into open rlogin session buffer"

   set con_data "$hostname;$spawn_pid;$user;[timestamp];$nr_of_shells"
   set rlogin_spawn_session_buffer($spawn_id) $con_data 
}

#****** remote_procedures/get_open_spawn_rlogin_session() **********************
#  NAME
#     get_open_spawn_rlogin_session() -- get rlogin connection data
#
#  SYNOPSIS
#     get_open_spawn_rlogin_session { hostname user back_var } 
#
#  FUNCTION
#     This procedure returns the corresponding spawn_id for hostname and user
#     name.
#
#  INPUTS
#     hostname - hostname of rlogin connection 
#     user     - user who logged in 
#     back_var - name of array to store data in
#                (the array has following names:
#                 back_var(spawn_id) 
#                 back_var(pid)     
#                 back_var(hostname) 
#                 back_var(user))
#
#  RESULT
#     1 on success, 0 if no connection is available
#
#  EXAMPLE
#     get_open_spawn_rlogin_session $hostname $user con_data
#     if { $con_data(pid) != 0 } {
#     }
#
#  NOTES
#     The back_var array is set to "0" if no connection is available 
#
#  SEE ALSO
#     remote_procedures/add_open_spawn_rlogin_session
#     remote_procedures/get_open_spawn_rlogin_session
#     remote_procedures/get_spawn_id_rlogin_session
#     remote_procedures/check_rlogin_session
#*******************************************************************************
proc get_open_spawn_rlogin_session { hostname user back_var } {
   global CHECK_OUTPUT rlogin_spawn_session_buffer
   global do_close_rlogin

   upvar $back_var back 

   set back(spawn_id)  0
   set back(pid)       0
   set back(hostname)  0
   set back(user)      0
   set back(ltime)     0
   set back(nr_shells) 0
   

   if { $do_close_rlogin != 0 } {
      return 0 
   }


   debug_puts "Cecking whether $hostname has an open rlogin session"
   set entries [array names rlogin_spawn_session_buffer]
   debug_puts "open rlogin connections: [llength $entries]"
   

   foreach elem $entries {
      set con_data $rlogin_spawn_session_buffer($elem)
      if { [string first $hostname $con_data] >= 0 } {
         if { [string first $user $con_data] >= 0 } {
            set data_list [split $con_data ";"]
            set back(spawn_id)  $elem
            set back(pid)       [lindex $data_list 1]
            set back(user)      [lindex $data_list 2]
            set back(hostname)  $hostname
            set back(ltime)     [lindex $data_list 3]
            set back(nr_shells) [lindex $data_list 4]
            debug_puts "spawn_id  : $back(spawn_id)"
            debug_puts "pid       : $back(pid)"
            debug_puts "hostname  : $back(hostname)"
            debug_puts "user:     : $back(user)"
            debug_puts "ltime:    : $back(ltime)"
            debug_puts "nr_shells : $back(nr_shells)"
            if { [check_rlogin_session $back(spawn_id) $back(pid) $back(hostname) $back(user) $back(nr_shells) ] != 1 } {
               set back(spawn_id) "0"
               set back(pid)      "0"
               set back(hostname) "0"
               set back(user)     "0"
               set back(ltime)     0
               set back(nr_shells) 0
               return 0 
            } else {
               unset rlogin_spawn_session_buffer($elem)
               debug_puts "old rlogin connection data: $con_data" 
               set con_data "$back(hostname);$back(pid);$back(user);[timestamp];$back(nr_shells)"
               debug_puts "new rlogin connection data: $con_data"
               set rlogin_spawn_session_buffer($elem) $con_data 
               return 1
            }
         }
      }
   }
   debug_puts "get_open_spawn_rlogin_session - session $user,$hostname not found"
   return 0
}

#****** remote_procedures/get_spawn_id_rlogin_session() ************************
#  NAME
#     get_spawn_id_rlogin_session() -- get rlogin connection data
#
#  SYNOPSIS
#     get_spawn_id_rlogin_session { id back_var } 
#
#  FUNCTION
#     This procedure returns the corresponding data for a rlogin spawn id
#
#  INPUTS
#     id       - spawn id of connection
#     back_var - name of array to store data in
#                (the array has following names:
#                 back_var(spawn_id) 
#                 back_var(pid)     
#                 back_var(hostname) 
#                 back_var(user))
#
#
#  RESULT
#     1 on success, 0 if no connection is available
#
#  EXAMPLE
#     get_spawn_id_rlogin_session $sp_id con_data
#       if { $con_data(pid) != 0 } { ...}
#
#  NOTES
#     The back_var array is set to "0" if no connection is available 
#
#  SEE ALSO
#     remote_procedures/add_open_spawn_rlogin_session
#     remote_procedures/get_open_spawn_rlogin_session
#     remote_procedures/get_spawn_id_rlogin_session
#     remote_procedures/check_rlogin_session
#*******************************************************************************
proc get_spawn_id_rlogin_session { id back_var {no_check 0}} {
   global CHECK_OUTPUT rlogin_spawn_session_buffer
   global do_close_rlogin

   upvar $back_var back 

   set back(spawn_id) "0"
   set back(pid)      "0"
   set back(hostname) "0"
   set back(user)     "0"
   set back(ltime)     0
   set back(nr_shells) 0

   if { $do_close_rlogin != 0 } {
      return 0 
   }


   if { [info exists rlogin_spawn_session_buffer($id) ] != 0 } {
      set con_data $rlogin_spawn_session_buffer($id)
      set data_list [split $con_data ";"]
      set back(spawn_id) $id
      set back(pid)      [lindex $data_list 1]
      set back(hostname) [lindex $data_list 0]
      set back(user)     [lindex $data_list 2]
      set back(ltime)     [lindex $data_list 3]
      set back(nr_shells) [lindex $data_list 4]
      
      debug_puts "spawn_id  : $back(spawn_id)"
      debug_puts "pid       : $back(pid)"
      debug_puts "hostname  : $back(hostname)"
      debug_puts "user:     : $back(user)"
      debug_puts "ltime:    : $back(ltime)"
      debug_puts "nr_shells : $back(nr_shells)"

      if { $no_check == 1 } {
         return 1 
      }
      if { [check_rlogin_session $back(spawn_id) $back(pid) $back(hostname) $back(user) $back(nr_shells)] != 1 } {
         set back(spawn_id) "0"
         set back(pid)      "0"
         set back(hostname) "0"
         set back(user)     "0"
         set back(ltime)     0
         set back(nr_shells) 0

         return 0 
      } else {
         return 1
      }
   }
   return 0
}

#****** remote_procedures/close_open_rlogin_sessions() *************************
#  NAME
#     close_open_rlogin_sessions() -- close all open rlogin sessions
#
#  SYNOPSIS
#     close_open_rlogin_sessions { } 
#
#  FUNCTION
#     This procedure closes all open rlogin expect sessions.
#
#*******************************************************************************
proc close_open_rlogin_sessions {} {
   global CHECK_OUTPUT rlogin_spawn_session_buffer
   global do_close_rlogin

   if { $do_close_rlogin != 0 } {
      puts $CHECK_OUTPUT "close_open_rlogin_sessions - open rlogin session mode not activated!"
      return 0 
   }
   set sessions [array names rlogin_spawn_session_buffer]
   set help_buf ""
   foreach session $sessions {
      lappend help_buf "$session;$rlogin_spawn_session_buffer($session)"
   }
   foreach session $help_buf {
      set data_list [split $session ";"]
      set back(spawn_id)  [lindex $data_list 0]
      set back(pid)       [lindex $data_list 2]
      set back(hostname)  [lindex $data_list 1]
      set back(user)      [lindex $data_list 3]
      set back(ltime)     [lindex $data_list 4]
      set back(nr_shells) [lindex $data_list 5]

      unset rlogin_spawn_session_buffer($back(spawn_id))
      set id $back(pid)
      lappend id $back(spawn_id)
      lappend id $back(nr_shells)
      puts $CHECK_OUTPUT "close_open_rlogin_sessions - closing $id"
      close_spawn_process $id 0 2
   }
}

#****** remote_procedures/check_rlogin_session() *******************************
#  NAME
#     check_rlogin_session() -- check if rlogin session is alive
#
#  SYNOPSIS
#     check_rlogin_session { spawn_id pid hostname user } 
#
#  FUNCTION
#     This procedure checks if the given rlogin spawn session is alive. If not
#     it will close the session.
#
#  INPUTS
#     spawn_id - spawn process id
#     pid      - process id of rlogin session
#     hostname - hostname of rlogin connection 
#     user     - user who logged in 
#
#  RESULT
#     1 on success, 0 if no connection is available
#
#  SEE ALSO
#     remote_procedures/add_open_spawn_rlogin_session
#     remote_procedures/get_open_spawn_rlogin_session
#     remote_procedures/get_spawn_id_rlogin_session
#     remote_procedures/check_rlogin_session
#*******************************************************************************
proc check_rlogin_session { spawn_id pid hostname user nr_of_shells} {
   global CHECK_OUTPUT rlogin_spawn_session_buffer


   if { [info exists rlogin_spawn_session_buffer($spawn_id) ] != 0 } {
      set timeout 1
      set ok 0
      set mytries  5
      debug_puts "check_rlogin_session -> waiting for shell response ..."
      
      send -i $spawn_id -- "\necho \"__ my id is ->\`id\`<-\"\n\n"
      while { $ok == 0 } {
         expect {
            -i $spawn_id full_buffer {
               add_proc_error "check_rlogin_session" -1 "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
               set ok 2
            }
            -i $spawn_id -- "__ my id is ->*${user}*<-" { 
                debug_puts "shell response! - fine" 
                set ok 1
                send -i $spawn_id "\n"
                debug_puts "sending new line"
            }
            -i $spawn_id default {
               flush $CHECK_OUTPUT
               send -i $spawn_id -- "\necho \"__ my id is ->\`id\`<-\"\n\n"
               set timeout 3
               puts $CHECK_OUTPUT "timeout counter: $mytries ..."

               incr mytries -1 ; 
               if  { $mytries < 0 } { 
                   set ok 2
               }
            }
         }
      }
      if { $ok == 1 } {
         return 1 ;# ok
      } else {
         # restart connection
         puts $CHECK_OUTPUT "timeout"
         unset rlogin_spawn_session_buffer($spawn_id)
         set id $pid
         lappend id $spawn_id
         lappend id $nr_of_shells
         puts $CHECK_OUTPUT "closing spawn id $spawn_id with pid $pid to enable new rlogin session ..."
         close_spawn_process $id 0 3
         puts $CHECK_OUTPUT "closing done."
      }       
   }
   return 0 ;# error
}
#                                                             max. column:     |
#****** remote_procedures/close_spawn_process() ******
# 
#  NAME
#     close_spawn_process -- close open spawn process id 
#
#  SYNOPSIS
#     close_spawn_process { id { check_exit_state 0 } } 
#
#  FUNCTION
#     This procedure will close the process associated with the spawn id
#     returned from the procedures open_spawn_process or open_root_spawn_process.
#
#  INPUTS
#     id - spawn process id (returned from open_spawn_process or 
#          open_root_spawn_process)
#     { check_exit_state 0 } - if 0: check exit state
#
#  RESULT
#     exit state of the "spawned" process
#
#  EXAMPLE
#     see open_root_spawn_process or open_spawn_process 
#
#  NOTES
#     After a process is "spawned" with the  open_spawn_process procedure it 
#     must be closed with the close_spawn_process procedure. id is the return 
#     value of open_spawn_process or open_root_spawn_process.
#     If a open spawn process id is not closed, it will not free the file
#     descriptor for that id. If all file descriptors are used, no new spawn
#     process can be forked!
#
#  SEE ALSO
#     remote_procedures/open_spawn_process
#     remote_procedures/open_root_spawn_process
#     remote_procedures/close_spawn_process
#     remote_procedures/run_command_as_user
#     remote_procedures/start_remote_tcl_prog
#     remote_procedures/start_remote_prog
#*******************************
proc close_spawn_process { id { check_exit_state 0 } {my_uplevel 1}} {

   global CHECK_OUTPUT open_spawn_buffer CHECK_DEBUG_LEVEL
  
#   catch { upvar $my_uplevel remote_spawn_nr_of_shells nr_of_shells }

   set sp_id  [lindex $id 1]
   set sp_pid [lindex $id 0]
   get_spawn_id_rlogin_session $sp_id con_data 1
   if { $con_data(pid) != 0 } {
      debug_puts "sending CTRL + C to spawn id $sp_id ..."
      send -i $sp_id "\003" ;# send CTRL+C to stop evtl. running processes in that shell
      debug_puts "Will not close spawn id \"$sp_id\", this is rlogin connection to"
      debug_puts "host \"$con_data(hostname)\", user \"$con_data(user)\""
      return -1   
   }

   log_user 0  
   if { $CHECK_DEBUG_LEVEL != 0 } {
      log_user 1
   }
   if { [llength $id ] > 2  } { 
       set nr_of_shells [lindex $id 2]
       set timeout 0
       set do_stop 0
       set send_slow "1 .05"
       debug_puts "nr of open shells: $nr_of_shells"
       debug_puts "-->sending $nr_of_shells exit(s) to shell on id $sp_id"
       for {set i 0} {$i < $nr_of_shells } {incr i 1} {
          send -s -i $sp_id "exit\n"
          set timeout 15
          expect { 
              -i $sp_id full_buffer {
                 add_proc_error "close_spawn_process" "-1" "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
              }
              -i $sp_id "*" {
                 debug_puts "shell exit"
              }
              -i $sp_id default {
                 puts $CHECK_OUTPUT "timeout or eof while waiting for shell exit"
              }
          }
       }
       set timeout 10
       set my_tries 6
       while { $do_stop != 1 } {
          expect {
             -i $sp_id full_buffer {
                add_proc_error "close_spawn_process" "-1" "buffer overflow please increment CHECK_EXPECT_MATCH_MAX_BUFFER value"
                set do_stop 1 
             }
             -i $sp_id eof { 
                set do_stop 1 
                debug_puts "got end of file - ok"
             }
             -i $sp_id default {
                puts $CHECK_OUTPUT "timeout"
                if { $my_tries > 0 } {
                   send -s -i $sp_id "exit\n"
                } else {
                   add_proc_error "close_spawn_process" "-1" "error closing shell"
                   set do_stop 1
                }
                incr my_tries -1
             }
          }
          debug_puts "waiting for end of file"
       }
   } 

   set open_spawn_buffer $sp_id
   catch { uplevel $my_uplevel { close -i $open_spawn_buffer
            debug_puts "closed buffer: $open_spawn_buffer" } }

   flush $open_spawn_buffer
   log_user 1
   set wait_return "" 
   catch { set wait_return [ uplevel $my_uplevel { wait -i $open_spawn_buffer } ] }

   debug_puts "closed buffer: $open_spawn_buffer"
   if { ([ string compare $open_spawn_buffer [lindex $wait_return 1] ] != 0) && ($check_exit_state == 0)} {
      add_proc_error "close_spawn_process" "-1" "wrong spawn id closed: expected $open_spawn_buffer, got [lindex $wait_return 1]"
   }
   

   debug_puts "wait pid        : [lindex $wait_return 0]"
   debug_puts "wait spawn id   : [lindex $wait_return 1]"

   if { [lindex $wait_return 2] == 0 } {
      if { ([lindex $wait_return 3] != 0) && ($check_exit_state == 0) } {
         add_proc_error "close_spawn_process" -1 "wait exit status: [lindex $wait_return 3]"
      }
   } else {
         puts $CHECK_OUTPUT "*** operating system error: [lindex $wait_return 3]"
         puts $CHECK_OUTPUT "spawn id: [lindex $wait_return 1]"
         puts $CHECK_OUTPUT "wait pid: [lindex $wait_return 0]"
         if { ($check_exit_state == 0) } {
            add_proc_error "close_spawn_process" -1 "operating system error: [lindex $wait_return 3]"
         }
   }
   flush $CHECK_OUTPUT
   return [lindex $wait_return 3] ;# return exit state
}


# user is a system user name
# command is a binary in $CHECK_PRODUCT_ROOT/bin/$CHECK_ARCH or a absolute path
# args are the command options of command
# counter: how often sould the command be called
# returns each line of output in a list
#                                                             max. column:     |
#****** remote_procedures/run_command_as_user() ******
# 
#  NAME
#     run_command_as_user -- start proccess under a specific user account
#
#  SYNOPSIS
#     run_command_as_user { hostname user command args counter } 
#
#  FUNCTION
#     This procedure is using start_remote_prog to start a binary or a skript 
#     file under a specific user account.
#
#  INPUTS
#     hostname - host where the command should be started
#     user     - system user name who should start the command
#     command  - command name (if no full path is given, the product
#                root path will be used)
#     args     - command arguments
#     counter  - run the command $counter times
#
#  RESULT
#     the command output 
#
#  EXAMPLE
#     set jobargs "/home/me/testjob.sh"
#     set result [ run_command_as_user "expo1" "user1" "qsub" "$jobargs" 5]
#     puts $result
#
#  NOTES
#     This procedure starts the script file remote_submit.sh in the scripts 
#     directory of the testsuite. This script is sourcing the 
#     default/common/settings.sh file of the cluster. If the command parameter
#     has no full path entry it will add the $CHECK_PRODUCT_ROOT path in 
#     front of the command. 
#
#  SEE ALSO
#     remote_procedures/open_spawn_process
#     remote_procedures/open_root_spawn_process
#     remote_procedures/close_spawn_process
#     remote_procedures/run_command_as_user
#     remote_procedures/start_remote_tcl_prog
#     remote_procedures/start_remote_prog
#*******************************
proc run_command_as_user { hostname user command args counter } {

   global CHECK_TESTSUITE_ROOT CHECK_PRODUCT_ROOT CHECK_ARCH CHECK_OUTPUT open_spawn_buffer 
   global CHECK_HOST CHECK_COMMD_PORT CHECK_SCRIPT_FILE_DIR
 
   # perform su to user and submit jobs as user $user
   set program  "$CHECK_TESTSUITE_ROOT/$CHECK_SCRIPT_FILE_DIR/remote_submit.sh"           ;# script to call in su root -c option
   set par1     "$CHECK_PRODUCT_ROOT"    ;# settings script
   if { [string first "\/" $command ] >= 0 } {
      set par2  "$command $args"
   } else {
      set par2  "$CHECK_PRODUCT_ROOT/bin/$CHECK_ARCH/$command $args"  ;# job to start
   }
   set par3     "$counter"  ;# number of qsub calls

   puts $CHECK_OUTPUT "running: $par2"
   set output [ start_remote_prog "$hostname" "$user" "$program" "\"$par1\" \"$par2\" \"$par3\"" "prg_exit_state" "120" ]
   return $output
}




# main
if { [info exists argc ] != 0 } {
   set TS_ROOT ""
   set procedure ""
   for { set i 0 } { $i < $argc } { incr i } {
      if {$i == 0} { set TS_ROOT [lindex $argv $i] }
      if {$i == 1} { set procedure [lindex $argv $i] }
   }
   if { $argc == 0 } {
      puts "usage:\n$module_name <CHECK_TESTSUITE_ROOT> <proc> no_main <testsuite params>"
      puts "options:"
      puts "CHECK_TESTSUITE_ROOT -  path to TESTSUITE directory"
      puts "proc                 -  procedure from this file with parameters"
      puts "no_main              -  used to source testsuite file (check.exp)"
      puts "testsuite params     -  any testsuite command option (from file check.exp)"
      puts "                        testsuite params: file <path>/defaults.sav is needed"
   } else {
      source "$TS_ROOT/check.exp"
      puts $CHECK_OUTPUT "master host is $CHECK_CORE_MASTER"
      puts $CHECK_OUTPUT "calling \"$procedure\" ..."
      set result [ eval $procedure ]
      puts $result 
      flush $CHECK_OUTPUT
   }
}

